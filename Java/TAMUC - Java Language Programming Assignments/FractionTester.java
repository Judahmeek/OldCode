/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package fraction_example;

/**
 *
 * @author MalehRay
 */
public class FractionTester {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Fraction x = new Fraction(1,2);
        Fraction y = new Fraction(1,3);
        System.out.println("My fraction: " + x);
        System.out.println("Reduced = " + x.reduce());
        System.out.println(x + "+" + y + "=" + x.add(y));
        
    }
}
