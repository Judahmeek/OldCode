/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail.records;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import traveltrail.interfaces.Extractable;
import traveltrail.interfaces.Preparable;

/**
 * Saves the records into the table.
 *
 * @author Judah Meek
 */
public class SaveRecord implements Extractable, Preparable {

    /**
     *
     */
    private int saveID;
    
    public SaveRecord(){
    }
    
    public SaveRecord(int saveID){
        setSaveID(saveID);
    }
    
    /**
     * Copy Constructor
     * @param other target SaveRecord to be copied
    */
    public SaveRecord(SaveRecord other){
        saveID = other.getSaveID();
    }
    
    /**
     * 
     * @param resultSet
     * @return
     * @throws SQLException 
     */
    @Override
    public Extractable extractRow(ResultSet resultSet, Integer startingIndex) throws SQLException {
        return new SaveRecord(resultSet.getInt(startingIndex++));
    }
    
    
    @Override
    public void formatPreparedStatement(PreparedStatement preparedStatement, Integer startingIndex) throws SQLException {
        preparedStatement.setInt(startingIndex++, getSaveID());
    }

    /**
     *
     * @return
     */
    public final int getSaveID() {
        return saveID;
    }

    /**
     *
     * @param saveID
     */
    public void setSaveID(int saveID) {
        this.saveID = saveID;
    }
}