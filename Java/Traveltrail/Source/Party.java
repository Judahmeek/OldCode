/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail;

import java.util.ArrayList;
import java.util.HashMap;
import traveltrail.records.ItemRecord;
import traveltrail.records.LocationRecord;
import traveltrail.records.MemberRecord;
import traveltrail.records.RelationshipRecord;
import traveltrail.records.StatRecord;
import traveltrail.records.VehicleRecord;
import traveltrail.rows.Extractable;
import traveltrail.rows.LocationRow;
import traveltrail.rows.StartRow;
import traveltrail.rows.StartingLocationRow;

/**
 *
 * @author Wap
 */
public final class Party {
    
    private Location location;
    
    private ArrayList<Member> members;
    private ArrayList<String> statuses;
    private ArrayList<Item> items;
    private ArrayList<Vehicle> vehicles;
    
    /**
     *
     * @param trail
     * @param ioManager
     * @param databaseManager
     */
    public Party(String trail, IOManager ioManager, DatabaseManager databaseManager){
        
        ArrayList<Extractable> extractedData = new ArrayList<>();
        StartRow startRow = new StartRow();
        
        databaseManager.pullTable(trail, "start", extractedData, startRow);
        startRow = (StartRow) extractedData.get(0);
        
        int num = ioManager.selectNumPC(startRow.getMinPCs(), startRow.getMaxPCs());
        
        for(int counter = num; counter > 0; --counter) {
            members.add(new Member());
        }
        
        StartingLocationRow startingLocationRow = new StartingLocationRow();
        databaseManager.pullTable(trail, "startinglocations", extractedData, startingLocationRow);
        startingLocationRow = (StartingLocationRow) ioManager.selectStartingLocationRow(extractedData);
        
        addStatus("new");
        setLocation(databaseManager.getLocation(startingLocationRow.getID(), trail));
    }

    Party(int saveID, String trail, IOManager ioManager, DatabaseManager databaseManager, ArrayList<StatRecord> statRecords) {
        
        ArrayList<Extractable> extractedRecords = new ArrayList<>();
        
        MemberRecord memberRecord = new MemberRecord();
        databaseManager.pullRecords(saveID, trail, "members", extractedRecords, memberRecord);
        for(Extractable record: extractedRecords) {
            members.add(new Member((MemberRecord) record));
        }
        
        VehicleRecord vehicleRecord = new VehicleRecord();
        databaseManager.pullRecords(saveID, trail, "vehicles", extractedRecords, vehicleRecord);
        for(Extractable record: extractedRecords) {
            vehicles.add(new Vehicle((VehicleRecord) record));
        }
        
        ItemRecord itemRecord = new ItemRecord();
        databaseManager.pullRecords(saveID, trail, "items", extractedRecords, itemRecord);
        for(Extractable record: extractedRecords) {
            items.add(new Item((ItemRecord) record));
        }
        
        RelationshipRecord relationshipRecord = new RelationshipRecord();
        databaseManager.pullRecords(saveID, trail, "relationships", extractedRecords, relationshipRecord);
        HashMap<Integer, ArrayList<Relationship>> relationshipMap = new HashMap<>();
        for(Extractable record : extractedRecords) {
            relationshipRecord = (RelationshipRecord) record;
            ArrayList<Relationship> relationships = relationshipMap.get(relationshipRecord.getSubject());
            if (relationships == null) {
                relationships = new ArrayList<>();
            }
            relationships.add(relationshipRecord.getRelationship());
        }
        for(Integer entityID : relationshipMap.keySet()) {
            for(Member member : members) {
                if(member.getEntityID().equals entityID) {
                    
                }
            }
        }
        
        LocationRecord locationRecord = new LocationRecord();
        databaseManager.pullRecords(saveID, trail, "location", extractedRecords, locationRecord);
        setLocation(databaseManager.getLocation(((LocationRow) extractedRecords.get(0)).getID(), trail));
        
    }

    public Location getLocation() {
        return location;
    }

    public void setLocation(Location location) {
        this.location = location;
    }

    public int getFunds() {
        return funds;
    }

    public void setFunds(int funds) {
        this.funds = funds;
    }

    public Member[] getMembers() {
        return (Member[]) members.toArray();
    }

    public void setMembers(ArrayList<Member> members) {
        this.members.addAll(members);
    }
    
    public void addMember(Member member) {
        members.add(member);
    }
    
    public void removeMember(Member member){
        if(members.contains(member)) {
            members.remove(member);
        }
    }

    public String[] getStatuses() {
        return (String[]) statuses.toArray();
    }

    public void addStatus(String status) {
        statuses.add(status);
    }
    
    public void removeStatus(String status){
        if(statuses.contains(status)) {
            statuses.remove(status);
        }
    }

    public Item[] getItems() {
        return (Item[]) items.toArray();
    }

    public void setItems(ArrayList<Item> items) {
        this.items.addAll(items);
    }
    
    public void addItem(Item item) {
        items.add(item);
    }
    
    public void removeItem(Item item) {
        if (items.contains(item)) {
            items.remove(item);
        }
    }

    public Vehicle[] getVehicles() {
        return (Vehicle[]) vehicles.toArray();
    }

    public void setVehicles(ArrayList<Vehicle> vehicles) {
        this.vehicles.addAll(vehicles);
    }
    
    public void addVehicle(Vehicle vehicle) {
        vehicles.add(vehicle);
    }
    
    public void removeVehicle(Vehicle vehicle) {
        if (vehicles.contains(vehicle)) {
            vehicles.remove(vehicle);
        }
    }
}
