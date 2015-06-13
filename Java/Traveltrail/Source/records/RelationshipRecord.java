/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail.records;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import traveltrail.Relationship;
import traveltrail.interfaces.Extractable;

/**
 *
 * @author Wap
 */
public final class RelationshipRecord extends SaveRecord {
    private int subject;
    private Relationship relationship;
    
    /**
     * Default Constructor
     */
    public RelationshipRecord() {
    }
    
    /**
     * 
     * @param subject entityID
     * @param relationship
     * @param target entityID
     */
    private RelationshipRecord(int saveID, int subject, String relationship, int target) {
        super(saveID);
        setSubject(subject);
        setRelationship(relationship, target);
    }
    
    /**
     * 
     * @param resultSet
     * @return
     * @throws SQLException 
     */
    @Override
    public Extractable extractRow(ResultSet resultSet) throws SQLException {
        return new RelationshipRecord(resultSet.getInt(1), resultSet.getInt(2), resultSet.getString(3), resultSet.getInt(4));
    }
    
    /**
     * 
     * @param preparedStatement
     * @throws SQLException 
     */    
    @Override
    public void formatPreparedStatement(PreparedStatement preparedStatement) throws SQLException {
        preparedStatement.setInt(1, getSaveID());
        preparedStatement.setInt(2, getSubject());
        preparedStatement.setString(3, getRelationship().getRelationship());
        preparedStatement.setInt(4, getRelationship().getTarget());
    }

    /**
     *
     * @return
     */
    public int getSubject() {
        return subject;
    }

    /**
     *
     * @param subject
     */
    public void setSubject(int subject) {
        this.subject = subject;
    }

    /**
     *
     * @return
     */
    public Relationship getRelationship() {
        return relationship;
    }

    /**
     *
     * @param relationship
     * @param target
     */
    public void setRelationship(String relationship, int target) {
        this.relationship = new Relationship(relationship, target);
    }
}
