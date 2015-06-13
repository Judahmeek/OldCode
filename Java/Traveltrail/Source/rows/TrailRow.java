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
public final class TrailRow implements Extractable{
    private int id;
    private String name;
    private String description;
    
    @Override
    public Extractable extractRow(ResultSet resultSet) throws SQLException {
        return new TrailRow(resultSet.getInt(1), resultSet.getString(2), resultSet.getString(3));
    }
    
    /**
     *
     */
    public TrailRow(){
        setId(-1);
        setName(null);
        setDescription(null);
    }
    
    /**
     *
     * @param trail_id
     * @param trail_name
     * @param trail_desc
     */
    public TrailRow(int trail_id, String trail_name, String trail_desc){
        setId(trail_id);
        setName(trail_name);
        setDescription(trail_desc);
        
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
    public String getDescription() {
        return description;
    }

    /**
     *
     * @param description
     */
    public void setDescription(String description) {
        this.description = description;
    }
    
    @Override
    public String toString(){
        return getName() + "\t" + getDescription();
    }
}
