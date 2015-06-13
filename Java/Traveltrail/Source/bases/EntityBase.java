/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail.bases;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import traveltrail.interfaces.Extractable;
import traveltrail.interfaces.Preparable;

/**
 *
 * @author Anomaly
 */
public class EntityBase implements Extractable, Preparable {
    
    private int entityID;
    
    private ArrayList<String> statuses;
    
    public EntityBase(){
    }
    
    public EntityBase(EntityBase other){
        setEntityID(other.getEntityID());
        setStatuses(other.getStatuses());
    }
    
    public EntityBase(int entityID, String statuses){
        setEntityID(entityID);
        setStatuses(statuses);
    }
    
    public EntityBase(int entityID, String[] statuses){
        setEntityID(entityID);
        setStatuses(statuses);
    }
    
        @Override
    public Extractable extractRow(ResultSet resultSet, Integer startingIndex) throws SQLException{
        int index = startingIndex;
        startingIndex += 2;
        return new EntityBase(resultSet.getInt(index),
                              resultSet.getString(++index));
    }
    
    /**
     * 
     * @param preparedStatement
     * @throws SQLException 
     */    
    @Override
    public void formatPreparedStatement(PreparedStatement preparedStatement, Integer startingIndex) throws SQLException {
        int index = startingIndex;
        startingIndex += 2;
        preparedStatement.setInt(index, getEntityID());
        preparedStatement.setString(++index, getStatusString());
    }
    
    public int getEntityID(){
        return entityID;
    }

    private void setEntityID(int eID){
        this.entityID = eID;
    }
    
    public String getStatusString(){
        String result = statuses.toString();
        return result.substring(1, (result.length() - 1));
    }

    public String[] getStatuses(){
        return (String[]) statuses.toArray();
    }

    private void setStatuses(String statuses){
        this.statuses.addAll(Arrays.asList(statuses.split(", ")));
    }
    
    private void setStatuses(String[] statuses){
        this.statuses.addAll(Arrays.asList(statuses));
    }
    
    public void addStatus(String status){
        statuses.add(status);
    }
    
    public void removeStatus(String status){
        statuses.remove(status);
    }
    
}
