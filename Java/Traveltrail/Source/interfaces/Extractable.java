/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail.interfaces;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 *
 * @author Wap
 */
public interface Extractable {
    
    /**
     *
     * @param resultSet
     * @param startingIndex
     * @return
     * @throws SQLException
     */
    public Extractable extractRow(ResultSet resultSet, Integer startingIndex) throws SQLException;
    
    
}
