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
public final class SkillRow implements Extractable{
    private int id;
    private String name;
    private String race;
    private int min;
    private int max;
    private int avg;

    private SkillRow() {
        setId(-1);
        setName(null);
        setRace(null);
        setMin(-1);
        setMax(-1);
        setAvg(-1);
    }
    
    private SkillRow(int id, String name, String race, int min, int max, int avg) {
        setId(id);
        setName(name);
        setRace(race);
        setMin(min);
        setMax(max);
        setAvg(avg);
    }
    
    @Override
    public Extractable extractRow(ResultSet resultSet) throws SQLException {
        return new SkillRow(resultSet.getInt(1), resultSet.getString(2), resultSet.getString(3), resultSet.getInt(4), resultSet.getInt(5), resultSet.getInt(6));
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
    public String getRace() {
        return race;
    }

    /**
     *
     * @param race
     */
    public void setRace(String race) {
        this.race = race;
    }

    /**
     *
     * @return
     */
    public int getMin() {
        return min;
    }

    /**
     *
     * @param min
     */
    public void setMin(int min) {
        this.min = min;
    }

    /**
     *
     * @return
     */
    public int getMax() {
        return max;
    }

    /**
     *
     * @param max
     */
    public void setMax(int max) {
        this.max = max;
    }

    /**
     *
     * @return
     */
    public int getAvg() {
        return avg;
    }

    /**
     *
     * @param avg
     */
    public void setAvg(int avg) {
        this.avg = avg;
    }
}
