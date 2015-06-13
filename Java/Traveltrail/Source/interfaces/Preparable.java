/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail.interfaces;

import java.sql.PreparedStatement;
import java.sql.SQLException;

/**
 *
 * @author Anomaly
 */
public interface Preparable {
    /**
     *
     * @param preparedStatement holds an SQL prepared statement
     * @param startingIndex
     * @throws SQLException
     */
    public void formatPreparedStatement (PreparedStatement preparedStatement, Integer startingIndex) throws SQLException;
}
