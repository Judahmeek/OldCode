/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 *
 * @author Wap
 */
public class Location {

    /**
     *
     */
    public int id;

    /**
     *
     */
    public String links;

    /**
     *
     */
    public String name;

    /**
     *
     */
    public String buildings;

    /**
     *
     */
    public String people;
    
    /**
     *
     * @param resultSet
     */
    public Location(ResultSet resultSet){
        try {
            id = resultSet.getInt(1);
            name = resultSet.getString(2);
            links = resultSet.getString(3);
            buildings = resultSet.getString(4);
            people = resultSet.getString(5);
        } catch (SQLException ex) {
            DatabaseManager.printSQLException(ex);
        }
    }
}
