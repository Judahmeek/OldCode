package traveltrail;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Arrays;
import traveltrail.records.EntityRecord;
import traveltrail.records.SaveRecord;
import traveltrail.rows.Extractable;

/**
 * DatabaseManager controls the entire database, including insertion and
 * removal of rows, and connection to the database.
 * 
 * @author Judah Meek
 */
public class DatabaseManager {

    private Connection connection = null;
    private Statement statement = null;
    private PreparedStatement preparedStatement = null;
    private ResultSet resultSet = null;
    private String request = null;
    
    /**
     * @param results  ArrayList<String> to store results in
     */
    public void showTables(ArrayList<String> results){
        try {
            results.clear();
            request = "show tables;";
            useStatement();
            while(resultSet.next()) {
                results.add(resultSet.getString(1));
            }
        } catch (SQLException ex) {
            printSQLException(ex);
        }
    }
    
    /**
     * @param database  Name of the target database
     * @param table  Name of target table within database
     * @param results  ArrayList to store results in
     * @param template Template class tells pullTable function which extractRow to use
     */
    public void pullTable(String database, String table, ArrayList<Extractable> results, Extractable template){
        try {
            results.clear();
            request = "select * from" + database + "." + table + ";";
            useStatement();
            while(resultSet.next()) {
                results.add(template.extractRow(resultSet));
            }
        } catch (SQLException ex) {
            printSQLException(ex);
        }
    }
    
    /**
     * @param saveId  saveID of the records to be pulled
     * @param database  name of the database being used
     * @param table  name of table to be queried
     * @param results  ArrayList to store results in
     * @param template Template class tells pullTable function which extractRow to use
     */
    public void pullRecords(int saveId, String database, String table, ArrayList<Extractable> results, Extractable template){
        try {
            results.clear();
            request = "select * from" + database + "." + table + " where saveId = " + saveId + ";";
            useStatement();
            while(resultSet.next()) {
                results.add(template.extractRow(resultSet));
            }
        } catch (SQLException ex) {
            printSQLException(ex);
        }
    }
    
    /**
     * @param id  id of location row
     * @param database  name of the database being used
     * @return resultSet of all locations
     */
    public Location getLocation(int id, String database){
        request = "select * from" + database + ".locations where id = " + id + ";";
        useStatement();
        return new Location(resultSet);
    }
    
    /**
     *
     * @param user
     * @param password
     * @return
     */
    public boolean getConnection(String user, String password) {
        try {
            // This will load the MySQL driver
            Class.forName("com.mysql.jdbc.Driver");
            
            // Setup the connection with the DB
            connection = DriverManager
                    .getConnection("jdbc:mysql://localhost/", user, password);
            return true;
        } catch (ClassNotFoundException e) {
            printException(e);
            return false;
        } catch (SQLException e) {
            printSQLException(e);
            return false;
        }
    }
    
    /**
     *
     */
    public void useStatement() {
        try {
            statement = connection.createStatement();
            
            resultSet = statement
                    .executeQuery(request);
            
        } catch (SQLException e) {
            printSQLException(e);
        }
    }
    
    /**
     * @param args  list of SaveRecord, used for saving progress in the game
     */
    public void saveRecords(ArrayList<SaveRecord> args) {
        try {
            preparedStatement = connection
                    .prepareStatement(request);
            for (SaveRecord record : args) {
                record.formatPreparedStatement(preparedStatement);
                preparedStatement.executeUpdate();
            }
        } catch (SQLException e) {
            printSQLException(e);
        }
    }
    
    public void saveRecords(ArrayList<EntityRecord> entities, ArrayList<Stat> stats){
        try {
            preparedStatement = connection
                    .prepareStatement(request);
            for (EntityRecord record : entities) {
                stats.addAll(Arrays.asList(record.getStats()));
                record.formatPreparedStatement(preparedStatement);
                preparedStatement.executeUpdate();
            }
        } catch (SQLException e) {
            printSQLException(e);
        }
    }

    /**
     *
     */
    public void close() {
        try {
            if (resultSet != null) {
                resultSet.close();
            }

            if (statement != null) {
                statement.close();
            }

            if (connection != null) {
                connection.close();
            }
        } catch (SQLException e) {
            printSQLException(e);
        }
    }

    /**
     * @param ex   exception error
     */
    public static void printException(Exception ex) {
        System.err.println("Message: " + ex.getMessage());

        Throwable t = ex.getCause();
        while(t != null) {
            System.out.println("Cause: " + t);
            t = t.getCause();
        }
    }
    
    /**
     * @param ex    exception error from SQL handler
     */
    public static void printSQLException(SQLException ex) {

        for (Throwable e : ex) {
            if (e instanceof SQLException) {
                e.printStackTrace(System.err);
                System.err.println("SQLState: " +
                    ((SQLException)e).getSQLState());

                System.err.println("Error Code: " +
                    ((SQLException)e).getErrorCode());

                System.err.println("Message: " + e.getMessage());

                Throwable t = ex.getCause();
                while(t != null) {
                    System.out.println("Cause: " + t);
                    t = t.getCause();
                }
            }
        }
    }
}
