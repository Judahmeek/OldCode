package traveltrail;

import java.util.ArrayList;
import java.util.Scanner;
import traveltrail.interfaces.Extractable;

/**
 * Controls all input and output to the game
 * 
 * @author Judah Meek
 */
public class IOManager {
    private final Scanner scanner;
    
    IOManager(){
        scanner = new Scanner(System.in);
    }
    
    /**
     * @param output    message to be displayed for user
     */
    public void displayString(String output){
        System.out.println(output);
    }
    
    /**
     *
     * @param credentials
     */
    public void requestDBCredentails(ArrayList<String> credentials){
        credentials.clear();
        credentials.add(requestString("What user account do you want this program to use to access mysql: "));
        credentials.add(requestString("What is the password for the user account: "));
    }
    
    /**
     * @param menu  menu to be displayed to the user
     */
    public void displayMenu(ArrayList<Extractable> menu){
        int counter = 0;
        for(Extractable row: menu) {
            ++counter;
            System.out.println(counter + ".)\t" + row);
        }
        System.out.println();
    }
    
    /**
     * @param menu  menu to be displayed to the user
     */
    public void displayMenu(String[] menu){
        int counter = 0;
        for(String row: menu) {
            ++counter;
            System.out.println(counter + ".)\t" + row);
        }
        System.out.println();
    }
    
    /**
     * @param request  obtain input from the user
     * @return input  input from user
     */
    private String requestString(String request){
        System.out.print(request);
        String input = scanner.nextLine();
        return input;
    }
    
    /**
     * @param request  obtain integer input from the user
     * @return input  input from user
     */
    private int requestInteger(String request){
        System.out.print("\n" + request);
        while (!scanner.hasNextInt()) {
            scanner.next();
        }
        int input = scanner.nextInt();
        return input;
    }
    
    private boolean requestBoolean(String request, char True, char False){
        System.out.print(request);
        String character = scanner.next();
        while (character.charAt(0) != True || False != character.charAt(0)){
            System.out.println("Invalid input. Please try again.");
            character = scanner.next();
        }
        return character.charAt(0) == True;
    }

    /**
     *
     * @return
     */
    public boolean wantSave() {
        return requestBoolean("Do you want to load a save file? ", 'y', 'n');
    }

    /**
     *
     * @param extractedData
     * @return
     */
    public int selectSave(ArrayList<Extractable> extractedData) {
        displayString("Available Save Files:");
        displayMenu(extractedData);
        int input = requestInteger("Please input the number of the desired save file: ");
        int upperRange = extractedData.size();
        while((input < 1) || (input > upperRange)){
            input = requestInteger("Invalid input. Please try again: ");
        }
        return input;
    }

    /**
     *
     * @param trails
     * @return
     */
    public int selectTrail(ArrayList<Extractable> trails) {
        displayString("Here is a list of the trails available:\n");
        displayMenu(trails);
        int input = requestInteger("Please input the number of the trail you wish to travel: ");
        int upperRange = trails.size();
        while((input < 1) || (input > upperRange)){
            input = requestInteger("Invalid input. Please try again: ");
        }
        return input;
    }

    /**
     *
     * @param minPCs
     * @param maxPCs
     * @return
     */
    public int selectNumPC(int minPCs, int maxPCs) {
        displayString("Number of starting party members can be between " + minPCs + " and " + maxPCs + ".");
        int input = requestInteger("How many party members do you want in your starting party: ");
        while((input < minPCs) || (input > maxPCs)){
            input = requestInteger("Invalid input. Please try again: ");
        }
        return input;
    }

    Extractable selectStartingLocationRow(ArrayList<Extractable> startingLocations) {
        System.out.print("#\tName\tDescription");
        displayMenu(startingLocations);
        int size = startingLocations.size();
        int input = requestInteger("Please pick your starting location: ");
        while((input < 1) || (input > size)){
            input = requestInteger("Invalid input. Please try again: ");
        }
        return startingLocations.get(input);
    }
}
