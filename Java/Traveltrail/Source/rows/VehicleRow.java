/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail.rows;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Placeholder for database information required by this program to create vehicle
 * instances as designed by trail designers.
 *
 * @author Wap
 */
public final class VehicleRow implements Extractable{
    private int model;
    private int avgPrice;
    
    @Override
    public Extractable extractRow(ResultSet resultSet) throws SQLException {
        return new VehicleRow(resultSet.getInt(1), resultSet.getInt(2));
    }
    
    /**
     *
     */
    public VehicleRow(){
        setModel(-1);
        setAvgPrice(-1);
    }
    
    /**
     *
     * @param model
     * @param price
     */
    public VehicleRow(int model, int price){
        setModel(model);
        setAvgPrice(price);
    }

    /**
     *
     * @return
     */
    public int getModel() {
        return model;
    }

    /**
     *
     * @param model
     */
    public void setModel(int model) {
        this.model = model;
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
}
