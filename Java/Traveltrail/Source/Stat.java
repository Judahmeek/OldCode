/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail;

import traveltrail.records.StatRecord;

/**
 *
 * @author Wap
 */
public class Stat {
    private String name;
    private int value;
    private int max;
    private int min;

    private Stat(String name, int value, int max, int min) {
        setName(name);
        setValue(value);
        setMax(max);
        setMin(min);
    }

    public Stat(Stat stat) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    public Stat(StatRecord stat) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
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
    private void setName(String name) {
        this.name = name;
    }

    /**
     *
     * @return
     */
    public int getValue() {
        return value;
    }

    /**
     *
     * @param value
     */
    private void setValue(int value) {
        this.value = value;
    }
    
    public void increaseValue(int value) {
        this.value += value;
        if(this.value > max) {
            this.value = max;
        }
    }
    
    public void decreaseValue(int value) {
        this.value = value;
        if(this.value < min) {
            this.value = min;
        }
    }

    public int getMax() {
        return max;
    }

    private void setMax(int max) {
        this.max = max;
    }

    public int getMin() {
        return min;
    }

    private void setMin(int min) {
        this.min = min;
    }
}
