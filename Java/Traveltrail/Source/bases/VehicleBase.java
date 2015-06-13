/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail.bases;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import traveltrail.interfaces.Extractable;
import traveltrail.interfaces.Preparable;

/**
 *
 * @author Anomaly
 */
public final class VehicleBase implements Extractable, Preparable {
    private String name;
    private String model;
        
    /**
     * Default Constructor
     */
    public VehicleBase(){
    }
    
    public VehicleBase(VehicleBase other) {
        setName(other.getName());
        setModel(other.getModel());
    }
    
    /**
     *
     * @param name
     * @param model
     */
    public VehicleBase(String name, String model){
        setName(name);
        setModel(model);
    }
    
    @Override
    public Extractable extractRow(ResultSet resultSet, Integer startingIndex) throws SQLException{
        int index = startingIndex;
        startingIndex += 2;
        return new VehicleBase(resultSet.getString(index),
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
        preparedStatement.setString(index, getName());
        preparedStatement.setString(++index, getModel());
    }

    /**
     *
     * @return
     */
    public String getName() {
        return name;
    }

    /**
     *
     * @param name
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     *
     * @return
     */
    public String getModel() {
        return model;
    }

    /**
     *
     * @param model
     */
    public void setModel(String model) {
        this.model = model;
    }
    
}
