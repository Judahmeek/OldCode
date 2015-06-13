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
public final class ItemBase implements Extractable, Preparable{
    /**
     *
     */
    private int id;

    /**
     *
     */
    private int quantity;
    
    /**
     * 
     */
    private String owner;
    
    /**
     * Default Constructor
     */
    public ItemBase(){
    }
    
    public ItemBase(ItemBase other){
        setID(other.getID());
        setQuantity(other.getQuantity());
        setOwner(other.getOwner());
    }
    
    /**
     *
     * @param id
     * @param quantity
     * @param owner
     */
    public ItemBase(int id, int quantity, String owner){
        setID(id);
        setQuantity(quantity);
        setOwner(owner);
    }
    
    @Override
    public Extractable extractRow(ResultSet resultSet, Integer startingIndex) throws SQLException{
        int index = startingIndex;
        startingIndex += 3;
        return new ItemBase(resultSet.getInt(index),
                            resultSet.getInt(++index),
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
        startingIndex += 3;
        preparedStatement.setInt(index, getID());
        preparedStatement.setInt(++index, getQuantity());
        preparedStatement.setString(++index, getOwner());
    }

    /**
     *
     * @return
     */
    public int getID() {
        return id;
    }

    /**
     *
     * @param id
     */
    public void setID(int id) {
        this.id = id;
    }

    /**
     *
     * @return
     */
    public int getQuantity() {
        return quantity;
    }

    /**
     *
     * @param quantity
     */
    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    /**
     *
     * @return
     */
    public String getOwner() {
        return owner;
    }

    /**
     *
     * @param owner
     */
    public void setOwner(String owner) {
        this.owner = owner;
    }
}
