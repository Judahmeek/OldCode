

package function;


public class graphFunction {

   
    public static void main(String[] args) {
       functionCalc f = new functionCalc("4x^2 + 2x", "cartesian", -100000, 100000);
             //System.out.println(f.getTerms().get(0).getType() + " " + f.getFunction());
       
       getDerivative h = new getDerivative();
       h.getDerivative(f);
       //functionCalc g = new functionCalc("r=5sin(t)", "polar", (-2*Math.PI), (2*Math.PI));
       
       for(double i=-5; i < 6; i++)
       {
           System.out.println("" + f.getF_of_X(i, 0));
          System.out.println("" + f.getDF_of_X(i, 0));
           
       }
       
    }
    
}
