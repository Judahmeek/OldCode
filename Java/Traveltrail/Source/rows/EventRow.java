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
public final class EventRow implements Extractable{
    private int id;
    private int location;
    private String type;
    private boolean unique;
    private int priority;
    private String category;
    private int baseProbability;
    private String probabilityConditions;
    private String scenario;
    private String input;
    private String effects;

    /**
     *
     */
    public EventRow() {
        setId(-1);
        setLocation(-1);
        setType(null);
        setUnique(true);
        setPriority(-1);
        setCategory(null);
        setBaseProbability(-1);
        setProbabilityConditions(null);
        setScenario(null);
        setInput(null);
        setEffects(null);
    }
    
    /**
     *
     * @param id
     * @param location
     * @param type
     * @param unique
     * @param priority
     * @param category
     * @param baseProbability
     * @param probabilityConditions
     * @param scenario
     * @param input
     * @param effects
     */
    public EventRow(int id, int location, String type, boolean unique, int priority, String category, int baseProbability, String probabilityConditions, String scenario, String input, String effects) {
        setId(id);
        setLocation(location);
        setType(type);
        setUnique(unique);
        setPriority(priority);
        setCategory(category);
        setBaseProbability(baseProbability);
        setProbabilityConditions(probabilityConditions);
        setScenario(scenario);
        setInput(input);
        setEffects(effects);
    }
    
    @Override
    public Extractable extractRow(ResultSet resultSet) throws SQLException {
        return new EventRow(resultSet.getInt(1), resultSet.getInt(2), resultSet.getString(3), resultSet.getBoolean(4), resultSet.getInt(5), resultSet.getString(6), resultSet.getInt(7), resultSet.getString(8), resultSet.getString(9), resultSet.getString(10), resultSet.getString(11));
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
    public int getLocation() {
        return location;
    }

    /**
     *
     * @param location
     */
    public void setLocation(int location) {
        this.location = location;
    }

    /**
     *
     * @return
     */
    public String getType() {
        return type;
    }

    /**
     *
     * @param type
     */
    public void setType(String type) {
        this.type = type;
    }

    /**
     *
     * @return
     */
    public boolean isUnique() {
        return unique;
    }

    /**
     *
     * @param unique
     */
    public void setUnique(boolean unique) {
        this.unique = unique;
    }

    /**
     *
     * @return
     */
    public int getPriority() {
        return priority;
    }

    /**
     *
     * @param priority
     */
    public void setPriority(int priority) {
        this.priority = priority;
    }

    /**
     *
     * @return
     */
    public String getCategory() {
        return category;
    }

    /**
     *
     * @param category
     */
    public void setCategory(String category) {
        this.category = category;
    }

    /**
     *
     * @return
     */
    public int getBaseProbability() {
        return baseProbability;
    }

    /**
     *
     * @param baseProbability
     */
    public void setBaseProbability(int baseProbability) {
        this.baseProbability = baseProbability;
    }

    /**
     *
     * @return
     */
    public String getProbabilityConditions() {
        return probabilityConditions;
    }

    /**
     *
     * @param probabilityConditions
     */
    public void setProbabilityConditions(String probabilityConditions) {
        this.probabilityConditions = probabilityConditions;
    }

    /**
     *
     * @return
     */
    public String getScenario() {
        return scenario;
    }

    /**
     *
     * @param scenario
     */
    public void setScenario(String scenario) {
        this.scenario = scenario;
    }

    /**
     *
     * @return
     */
    public String getInput() {
        return input;
    }

    /**
     *
     * @param input
     */
    public void setInput(String input) {
        this.input = input;
    }

    /**
     *
     * @return
     */
    public String getEffects() {
        return effects;
    }

    /**
     *
     * @param effects
     */
    public void setEffects(String effects) {
        this.effects = effects;
    }
}
