/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail.records;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import traveltrail.bases.VehicleBase;
import traveltrail.interfaces.Extractable;

/**
 * Creates a record for an in-game vehicle that can be inserted into a database.
 *
 * @author Judah Meek
 */
public final class VehicleRecord extends EntityRecord {
    
    private VehicleBase base;
        
    /**
     * Default Constructor
     */
    public VehicleRecord(){
    }
    
    /**
     *
     * @param entityRecord
     * @param base
     */
    public VehicleRecord(EntityRecord entityRecord, VehicleBase base){
        super(entityRecord);
        setBase(base);
    }
    
    @Override
    public Extractable extractRow(ResultSet resultSet, Integer startingIndex) throws SQLException{
        return new VehicleRecord((EntityRecord) super.extractRow(resultSet, startingIndex),
                                (VehicleBase) base.extractRow(resultSet, startingIndex));
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

    /**
     *
     * @return
     */
    public VehicleBase getBase() {
        return new VehicleBase(base);
    }

    /**
     *
     * @param base
     */
    public void setBase(VehicleBase base) {
        this.base = base;
    }
}
