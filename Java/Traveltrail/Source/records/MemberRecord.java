/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail.records;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import traveltrail.bases.MemberBase;
import traveltrail.interfaces.Extractable;

/**
 * Creates a record of a member and keeps track of it in the database
 * 
 * @author Judah Meek
 */
public final class MemberRecord extends EntityRecord {
    
    private MemberBase base;
    
    /**
     * Default Constructor
     */
    public MemberRecord() {
    }
    
    /**
     * 
     * @param name
     * @param age
     * @param gender
     * @param position
     * @param occupation
     * @param personality
     * @param skills
     * @param race
     * @param mass
     */
    private MemberRecord(EntityRecord entityRecord, MemberBase base) {
        super(entityRecord);
        setMemberBase(base);
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
        return new MemberRecord((EntityRecord) super.extractRow(resultSet, startingIndex),
                                (MemberBase) base.extractRow(resultSet, startingIndex));
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

    public void setMemberBase(MemberBase base) {
        this.base = base;
    }
    
    public MemberBase getMemberBase() {
        return new MemberBase(base);
    }
}