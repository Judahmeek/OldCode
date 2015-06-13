/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail.records;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import traveltrail.bases.EntityBase;
import traveltrail.interfaces.Extractable;

/**
 * Saves the records into the table.
 *
 * @author Judah Meek
 */
public class EntityRecord extends SaveRecord{
    
    private EntityBase base;
    
    EntityRecord() {
    }
    
    EntityRecord(EntityRecord other){
        super.setSaveID(other.getSaveID());
        setEntityBase(other.getEntityBase());
    }
    
    public EntityRecord(SaveRecord saveRecord, EntityBase base){
        super(saveRecord);
        setEntityBase(base);
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
        return new EntityRecord((SaveRecord) super.extractRow(resultSet, startingIndex),
                                (EntityBase) base.extractRow(resultSet, startingIndex));
    }
    
    
    @Override
    public void formatPreparedStatement(PreparedStatement preparedStatement, Integer startingIndex) throws SQLException {
        super.formatPreparedStatement(preparedStatement, startingIndex);
        base.formatPreparedStatement(preparedStatement, startingIndex);
    }
    
    private void setEntityBase(EntityBase Base){
        this.base = new EntityBase(Base);
    }
    
    public EntityBase getEntityBase(){
        return new EntityBase(base);
    }
}