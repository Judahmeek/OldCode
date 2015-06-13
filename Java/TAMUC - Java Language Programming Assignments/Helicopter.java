
package flyable_demo;

public class Helicopter implements Flyable {
    
    private String tailNumber;
    private int altitude;
    
    public Helicopter(String tn) {
        tailNumber = tn;
    }
    
     @Override public void takeoff() {
        System.out.println("Helicopter " + tailNumber + " is taking off");
    }
    
    @Override public void changeAltitude(int altitude) {
        this.altitude = altitude;
        System.out.println("Helicopter " + tailNumber + " is at "
                + altitude + " feet");
    }
    
    @Override public String identifyType() {
        return "Helicopter";
    }
    
    @Override public void yieldWayTo(Flyable f) {
        System.out.println("Helicopter " + tailNumber + " yielding the way to the " 
                + f.identifyType());
    }
    
}
