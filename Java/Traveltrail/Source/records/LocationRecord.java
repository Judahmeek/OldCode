/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail.records;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import traveltrail.rows.Extractable;

/**
 * Creates a record of a party of members and keeps track of it in the database
 *
 * @author Judah Meek
 */
public final class LocationRecord extends EntityRecord {

    /**
     *
     */
    private int location;
    
    /**
     * Default Constructor
     */
    public LocationRecord(){
    }
    
    /**
     *
     * @param saveID
     * @param entityID
     * @param location
     * @param status
     */
    public LocationRecord(int saveID, int entityID, String status, int location){
        super(saveID, entityID, status);
        setLocation(location);
    }
    
    @Override
    public Extractable extractRow(ResultSet resultSet) throws SQLException{
        return new LocationRecord(resultSet.getInt(1), resultSet.getInt(2), resultSet.getString(3), resultSet.getInt(4));
    }
    
    /**
     * 
     * @param preparedStatement
     * @throws SQLException 
     */    
    @Override
    public void formatPreparedStatement(PreparedStatement preparedStatement) throws SQLException {
        preparedStatement.setInt(1, getSaveID());
        preparedStatement.setInt(2, getEntityID());
        preparedStatement.setString(3, getStatusString());
        preparedStatement.setInt(4, getLocation());
    }

    public int getLocation() {
        return location;
    }

    public void setLocation(int location) {
        this.location = location;
    }
}