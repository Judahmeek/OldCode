/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail;

import java.util.ArrayList;
import java.util.Arrays;
import traveltrail.records.StatRecord;

/**
 *
 * @author Anomaly
 */
public class Entity extends EntityBase {
    
    private ArrayList<Stat> stats;
    
    public Entity() {
    }
    
    public Entity(int entityID, String statuses, ArrayList<StatRecord> stats){
        super(entityID, statuses);
        setStats(stats);
    }

    public Stat[] getStats() {
        return (Stat[]) stats.toArray();
    }
    
    private void setStats(ArrayList<StatRecord> stats){
        for (StatRecord stat:stats){
            this.stats.add(new Stat(stat));
        }
    }

    public void addStat(Stat stat) {
        stats.add(stat);
    }
}
