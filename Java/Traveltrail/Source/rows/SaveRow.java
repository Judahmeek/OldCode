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
public final class SaveRow implements Extractable{
    private int id;
    private String trail;
    private String name;
    private String timeStamp;
    
    @Override
    public Extractable extractRow(ResultSet resultSet) throws SQLException {
        return new SaveRow(resultSet.getInt(1), resultSet.getString(2), resultSet.getString(3), resultSet.getString(4));
    }
    
    /**
     *
     */
    public SaveRow(){
        setId(-1);
        setTrail(null);
        setName(null);
        setTimeStamp(null);
    }
    
    /**
     *
     * @param save_id
     * @param trail
     * @param name
     * @param time
     */
    public SaveRow(int save_id, String trail, String name, String time){
        id = save_id;
        this.trail = trail;
        this.name = name;
        timeStamp = time;
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
    public String getTrail() {
        return trail;
    }

    /**
     *
     * @param trail
     */
    public void setTrail(String trail) {
        this.trail = trail;
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
    public String getTimeStamp() {
        return timeStamp;
    }

    /**
     *
     * @param timeStamp
     */
    public void setTimeStamp(String timeStamp) {
        this.timeStamp = timeStamp;
    }
    
    /**
     *
     * @return
     */
    @Override
    public String toString(){
        return "ID: " + getId() + " Name: " + getName() + " Trail: " + getTrail() + " Time: " + getTimeStamp();
        
    }

}
