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
public final class StartRow implements Extractable{
    private int minCustomPCs;
    private int maxCustomPCs;
    
    @Override
    public Extractable extractRow(ResultSet resultSet) throws SQLException {
        return new StartRow(resultSet.getInt(1), resultSet.getInt(2));
    }
    
    /**
     *
     */
    public StartRow(){
        setMinPCs(-1);
        setMaxPCs(-1);
    }
    
    /**
     *
     * @param minPCs
     * @param maxPCs
     */
    public StartRow(int minPCs, int maxPCs){
        setMinPCs(minPCs);
        setMaxPCs(maxPCs);
    }
    
    /**
     *
     * @return
     */
    public int getMinPCs(){
        return minCustomPCs;
    }
    
    /**
     *
     * @return
     */
    public int getMaxPCs(){
        return maxCustomPCs;
    }
    
    /**
     *
     * @param value
     */
    public void setMinPCs(int value){
        minCustomPCs = value;
    }
    
    /**
     *
     * @param value
     */
    public void setMaxPCs(int value){
        maxCustomPCs = value;
    }
}
