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
public final class StartingLocationRow implements Extractable{
    private int id;
    private String name;
    private String description;
    
    public StartingLocationRow(){
        setID(-1);
        setName(null);
        setDescription(null);
    }
    
    public StartingLocationRow(int id, String name, String description){
        setID(id);
        setName(name);
        setDescription(description);
    }
    
    @Override
    public Extractable extractRow(ResultSet resultSet) throws SQLException {
        return new StartingLocationRow(resultSet.getInt(1), resultSet.getString(2), resultSet.getString(3));
    }

    public int getID() {
        return id;
    }

    public void setID(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }
    
    @Override
    public String toString(){
        return getName() + "\t" + getDescription();
    }
}
