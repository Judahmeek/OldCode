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
public final class ItemRow implements Extractable{
    private int id;
    private String name;
    private int avgPrice;
    private int mass;
    
    @Override
    public Extractable extractRow(ResultSet resultSet) throws SQLException {
        return new ItemRow(resultSet.getInt(1), resultSet.getString(2), resultSet.getInt(3), resultSet.getInt(4));
    }
    
    /**
     *
     */
    public ItemRow(){
        setId(-1);
        setName(null);
        setAvgPrice(-1);
        setMass(-1);
    }
    
    /**
     *
     * @param id
     * @param name
     * @param avgPrice
     * @param mass
     */
    public ItemRow(int id, String name, int avgPrice, int mass){
        setId(id);
        setName(name);
        setAvgPrice(avgPrice);
        setMass(mass);
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
    public int getAvgPrice() {
        return avgPrice;
    }

    /**
     *
     * @param avgPrice
     */
    public void setAvgPrice(int avgPrice) {
        this.avgPrice = avgPrice;
    }

    /**
     *
     * @return
     */
    public int getMass() {
        return mass;
    }

    /**
     *
     * @param mass
     */
    public void setMass(int mass) {
        this.mass = mass;
    }
}