/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package fraction_example;

/**
 *
 * @author MalehRay
 */
public class Fraction {

    private int num;
    private int den;
    
    // Constructor
    public Fraction(int num, int den) {
        this.num = num;
        this.den = den;
    }
    
    // Accessor: Gets numerator
    public int getNum() {
        return this.num;
    }
    
    // Accessor: Gets denominator
    public int getDen() {
        return this.den;
    }
    
    // Mutator: set the numerator
    public void setNum(int num) {
        this.num = num;
    }
    
    // Mutator: set the denominator
    public void setDen(int den) {
        this.den = den;
    }
    
    // Write fraction as a string
    @Override public String toString() {
        return this.num + "/" + this.den;
    }
    
    // Add two fractions
    public Fraction add(Fraction b) {
        int common_denom = this.den*b.den;
        int final_num = this.num*b.den + this.den*b.num;
        return (new Fraction(final_num,common_denom)).reduce();
    }
    
    // Add two fractions
    public static Fraction add(Fraction a, Fraction b) {
        int common_denom = a.den*b.den;
        int final_num = a.num*b.den + a.den*b.num;
        return (new Fraction(final_num,common_denom)).reduce();
    }
    
    // Reduce fraction
    public Fraction reduce() {
        int gcd_value = gcd(this.num,this.den);
        return new Fraction(this.num/gcd_value,
                            this.den/gcd_value);        
    }
    
    // GCD Function
    public static int gcd(int a, int b) {
        if (a == 0) {
            return b;
        }
        else if (b == 0) {
            return a;
        }
        else if (a > b) {
            return gcd(b,a%b);
        }
        else {
            return gcd(a,b%a);
        }
    }
    
    
}
