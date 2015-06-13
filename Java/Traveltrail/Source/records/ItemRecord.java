/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail.records;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import traveltrail.bases.ItemBase;
import traveltrail.interfaces.Extractable;

/**
 * Stores and retrieves item records in the database
 * 
 * @author Wap
 */
public final class ItemRecord extends EntityRecord {

    /**
     *
     */
    private ItemBase base;
    
    /**
     * Default Constructor
     */
    public ItemRecord(){
    }
    
    /**
     *
     * @param saveID
     * @param entityID
     * @param status
     * @param id
     * @param quantity
     * @param owner
     */
    public ItemRecord(EntityRecord entityRecord, ItemBase base){
        super(entityRecord);
        setItemBase(base);
    }
    
    /**
     * 
     * @param resultSet
     * @param startingIndex
     * @return
     * @throws SQLException 
     */
    @Override
    public Extractable extractRow(ResultSet resultSet, Integer startingIndex) throws SQLException {
        return new ItemRecord((EntityRecord) super.extractRow(resultSet, startingIndex),
                                (ItemBase) base.extractRow(resultSet, startingIndex));
    }
    
    /**
     * 
     * @param preparedStatement
     * @param startingIndex
     * @throws SQLException 
     */    
    @Override
    public void formatPreparedStatement(PreparedStatement preparedStatement, Integer startingIndex) throws SQLException {
        super.formatPreparedStatement(preparedStatement, startingIndex);
        base.formatPreparedStatement(preparedStatement, startingIndex);
    }

    public void setItemBase(ItemBase base) {
        this.base = base;
    }
    
    public ItemBase getItemBase() {
        return new ItemBase(base);
    }
}
