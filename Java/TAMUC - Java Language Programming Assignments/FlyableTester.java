
package flyable_demo;

public class FlyableTester {

    public static void main(String[] args) {
        
        Flyable a = new Airplane("N3456");
        Flyable b = new Helicopter("N7890");
        
        a.takeoff();
        b.takeoff();
        
        a.changeAltitude(5000);
        b.changeAltitude(4500);
        
        a.yieldWayTo(b);
        
        ((Airplane) a).stallRecover();
        
    }
}
