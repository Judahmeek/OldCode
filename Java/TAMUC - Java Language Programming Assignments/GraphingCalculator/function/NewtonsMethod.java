

package function;


public class NewtonsMethod {
    public double NewtonsMethod(functionCalc function, double X, double limit){
        double xK = X;
        double xKminusOne;
        if (function.getDerivTerms().isEmpty()){
            getDerivative g = new getDerivative();
            g.getDerivative(function);
        }
        do{
        xKminusOne = xK;
        xK -= ((function.getF_of_X(xK, 0))/((function.getDF_of_X(xK, 0))));
        }while(Math.abs(xK - xKminusOne) >= limit);
        return xK;
    }
}
