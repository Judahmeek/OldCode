/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail;

import java.util.ArrayList;
import traveltrail.records.StatRecord;
import traveltrail.rows.Extractable;
import traveltrail.rows.LocationRow;
import traveltrail.rows.SaveRow;
import traveltrail.rows.TrailRow;

/**
 * This program contains the framework for a game, the details of which it loads from a database.
 * Features of this framework include game save/loading and a dynamic event system.
 * 
 * @author Judah Meek
 */
public class TravelTrail {
    
    static boolean active = true;
    static boolean sameCredentials = true;
    
    /**
     * @param args arguments from the command line
     */
    public static void main(String[] args) {
        
        /*
         * Initializing manager objects
         */
        DatabaseManager databaseManager = new DatabaseManager();
        IOManager ioManager = new IOManager();
        
        while(active){
            /*
             * This code section prompts the user for database connection details.
             */
            ArrayList<String> credentials = new ArrayList<>();
            ioManager.requestDBCredentails(credentials);
            while(!databaseManager.getConnection(credentials.get(0), credentials.get(1))){
                ioManager.displayString("Database connection failed.");
                ioManager.requestDBCredentails(credentials);
            }
            /*
             * This code section extracts the list of trails from the database
             * and inserts them into an arraylist.
             */
            ArrayList<Extractable> trails = new ArrayList<>();
            TrailRow trailRow = new TrailRow();
            databaseManager.pullTable("traveltrail", "trail", trails, trailRow);

            /*
             * This code section extracts a list of all tables within the database and
             * then compares it to list of supposedly available trails. It then removes
             * any trails for which there is no table.
             */
            ArrayList<String> tables = new ArrayList<>();
            databaseManager.showTables(tables);
            for(int counter = 0; counter < trails.size();){
                trailRow = (TrailRow) trails.get(counter);
                    if(!tables.contains(trailRow.getName())){
                        trails.remove(counter);
                    }
                    else {
                        ++counter;
                }
            }
            
            while(sameCredentials){
                /*
                 * This code section asks the user if the user wants to load a save file and then calls
                 * one of two functions depending on the result.
                 */
                boolean userWantSave = ioManager.wantSave();

                if (userWantSave){
                    ArrayList<Extractable> extractedData = new ArrayList<>();
                    SaveRow saveRow = new SaveRow();
                    databaseManager.pullTable("traveltrail", "saveFiles", extractedData, saveRow);

                    /* This code section removes any extracted save files that are based off of unavailable trails.
                    */
                    for(int counter = 0; counter < extractedData.size();){
                        saveRow = (SaveRow) extractedData.get(counter);
                        if(!tables.contains(saveRow.getTrail())){
                            extractedData.remove(counter);
                        }
                        else {
                            ++counter;
                        }
                    }

                    /* This code section checks if there are any available save files and informs the user if there are not.
                    */
                    if(extractedData.isEmpty()){
                        ioManager.displayString("No save files are available.");
                    } else {

                        /* This code section extracts the selected save file and then instantiates the Party and EventManager
                        */
                        int save = ioManager.selectSave(extractedData);
                        saveRow = (SaveRow) extractedData.get(save);
                        StatRecord statRecord = new StatRecord();
                        databaseManager.pullRecords(saveRow.getId(), saveRow.getTrail(), "stats", extractedData, statRecord);
                        
                        ArrayList<Extractable> locations = new ArrayList<>();
                        LocationRow locationRow = new LocationRow();
                        databaseManager.pullTable(saveRow.getTrail(), "locations", locations, locationRow);
                        Party party = new Party(saveRow.getId(), saveRow.getTrail(), ioManager, databaseManager, (ArrayList<StatRecord>)(ArrayList<?>) extractedData);
                    }
                }
                else{
                    /* This code section prompts the user to choose which trail to initialize.
                    */
                    int trail = ioManager.selectTrail(trails);
                    trailRow = (TrailRow) trails.get(trail);
                    Party party = new Party(trailRow.getName(), ioManager, databaseManager);
                }
            }
        }
    }
}