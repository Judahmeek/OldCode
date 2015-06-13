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
 *
 * @author Wap
 */
public final class StatRecord extends SaveRecord {
    private int entityID;
    private String name;
    private int value;
        
    /**
     * Default Constructor
     */
    public StatRecord(){
    }
    
    /**
     *
     * @param saveID
     * @param entityID
     * @param name
     * @param value
     */
    public StatRecord(int saveID, int entityID, String name, int value){
        super(saveID);
        setEntityID(entityID);
        setName(name);
        setValue(value);
    }
    
    @Override
    public Extractable extractRow(ResultSet resultSet) throws SQLException{
        return new StatRecord(resultSet.getInt(1), resultSet.getInt(2), resultSet.getString(3), resultSet.getInt(4));
    }

    @Override
    public void formatPreparedStatement(PreparedStatement preparedStatement) throws SQLException {
        preparedStatement.setInt(1, getSaveID());
        preparedStatement.setInt(1, getEntityID());
        preparedStatement.setString(2, getName());
        preparedStatement.setInt(3, getValue());
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
    public int getValue() {
        return value;
    }

    /**
     *
     * @param value
     */
    public void setValue(int value) {
        this.value = value;
    }

    public int getEntityID() {
        return entityID;
    }

    public void setEntityID(int entityID) {
        this.entityID = entityID;
    }
}
