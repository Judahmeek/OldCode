
package flyable_demo;


public interface Flyable {

    void takeoff();
    void changeAltitude(int altitude);
    String identifyType();
    void yieldWayTo(Flyable f);
    
}
