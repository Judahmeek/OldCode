/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail.rows;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 *
 * @author Wap
 */
public final class RaceRow implements Extractable{
    private int id;
    private String name;
    private boolean playable;
    private String[] genders;
    private String[] personalities;
    private String[] relationships;
    private int minAge;
    private int maxAge;
    private int minHeight;
    private int maxHeight;
    private int minMass;
    private int maxMass;

    /**
     *
     */
    public RaceRow() {
        setId(-1);
        setName(null);
        setPlayable(false);
        setGenders(null);
        setPersonalities(null);
        setRelationships(null);
        setMinAge(-1);
        setMaxAge(-1);
        setMinHeight(-1);
        setMaxHeight(-1);
        setMinMass(-1);
        setMaxMass(-1);
    }
    
    /**
     *
     * @param id
     * @param name
     * @param playable
     * @param genders
     * @param personalities
     * @param relationships
     * @param minAge
     * @param maxAge
     * @param minHeight
     * @param maxHeight
     * @param minMass
     * @param maxMass
     */
    public RaceRow(int id, String name, boolean playable, String genders, String personalities, String relationships, int minAge, int maxAge, int minHeight, int maxHeight, int minMass, int maxMass) {
        setId(id);
        setName(name);
        setPlayable(playable);
        setGenders(genders);
        setPersonalities(personalities);
        setRelationships(relationships);
        setMinAge(minAge);
        setMaxAge(maxAge);
        setMinHeight(minHeight);
        setMaxHeight(maxHeight);
        setMinMass(minMass);
        setMaxMass(maxMass);
    }
    
    @Override
    public Extractable extractRow(ResultSet resultSet) throws SQLException {
        return new RaceRow(resultSet.getInt(1), resultSet.getString(2), resultSet.getBoolean(3), resultSet.getString(4), resultSet.getString(5), resultSet.getString(6), resultSet.getInt(7), resultSet.getInt(8), resultSet.getInt(9), resultSet.getInt(10), resultSet.getInt(11), resultSet.getInt(12));
    }

    /**
     *
     * @return
     */
    public int getId() {
        return id;
    }

    /**
     *
     * @param id
     */
    public void setId(int id) {
        this.id = id;
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
    public boolean isPlayable() {
        return playable;
    }

    /**
     *
     * @param playable
     */
    public void setPlayable(boolean playable) {
        this.playable = playable;
    }
    
    /**
     *
     * @return
     */
    public String[] getGenders() {
        return genders;
    }

    /**
     *
     * @param genders
     */
    public void setGenders(String genders) {
        this.genders = genders.split(";");
    }

    /**
     *
     * @return
     */
    public String[] getPersonalities() {
        return personalities;
    }

    /**
     *
     * @param personalities
     */
    public void setPersonalities(String personalities) {
        this.personalities = personalities.split(";");
    }

    /**
     *
     * @return
     */
    public String[] getRelationships() {
        return relationships;
    }

    /**
     *
     * @param relationships
     */
    public void setRelationships(String relationships) {
        this.relationships = relationships.split(";");
    }

    /**
     *
     * @return
     */
    public int getMinAge() {
        return minAge;
    }

    /**
     *
     * @param minAge
     */
    public void setMinAge(int minAge) {
        this.minAge = minAge;
    }

    /**
     *
     * @return
     */
    public int getMaxAge() {
        return maxAge;
    }

    /**
     *
     * @param maxAge
     */
    public void setMaxAge(int maxAge) {
        this.maxAge = maxAge;
    }

    /**
     *
     * @return
     */
    public int getMinHeight() {
        return minHeight;
    }

    /**
     *
     * @param minHeight
     */
    public void setMinHeight(int minHeight) {
        this.minHeight = minHeight;
    }

    /**
     *
     * @return
     */
    public int getMaxHeight() {
        return maxHeight;
    }

    /**
     *
     * @param maxHeight
     */
    public void setMaxHeight(int maxHeight) {
        this.maxHeight = maxHeight;
    }

    /**
     *
     * @return
     */
    public int getMinMass() {
        return minMass;
    }

    /**
     *
     * @param minMass
     */
    public void setMinMass(int minMass) {
        this.minMass = minMass;
    }

    /**
     *
     * @return
     */
    public int getMaxMass() {
        return maxMass;
    }

    /**
     *
     * @param maxMass
     */
    public void setMaxMass(int maxMass) {
        this.maxMass = maxMass;
    }
}
