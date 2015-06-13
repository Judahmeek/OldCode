/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail;

/**
 *
 * @author Anomaly
 */
public final class Relationship {
    private String relationship;
    private int target;

    public Relationship(String relationship, int target) {
        setRelationship(relationship);
        setTarget(target);
    }

    public String getRelationship() {
        return relationship;
    }

    public void setRelationship(String relationship) {
        this.relationship = relationship;
    }

    public int getTarget() {
        return target;
    }

    public void setTarget(int target) {
        this.target = target;
    }
}
