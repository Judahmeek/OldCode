
package flyable_demo;


public class Airplane implements Flyable {
    
    private String tailNumber;
    private int altitude;
    
    public Airplane(String tn) {
        tailNumber = tn;
    }
    
    @Override public void takeoff() {
        System.out.println("Airplane " + tailNumber + " is taking off");
    }
    
    @Override public void changeAltitude(int altitude) {
        this.altitude = altitude;
        System.out.println("Airplane " + tailNumber + " is at "
                + altitude + " feet");
    }
    
    @Override public String identifyType() {
        return "Airplane";
    }
    
    @Override public void yieldWayTo(Flyable f) {
        System.out.println("Aircraft " + tailNumber + " yielding the way to the " 
                + f.identifyType());
    }
    
    public void stallRecover() {
        System.out.println("Aircraft " + tailNumber + " is recovering " +
                "from a stall.");
    }
    
    
    
}
