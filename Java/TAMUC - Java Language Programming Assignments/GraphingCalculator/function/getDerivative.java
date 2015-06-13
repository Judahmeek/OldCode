

package function;

//import java.util.ArrayList;

import java.util.ArrayList;



public class getDerivative extends functionCalc{
   // private ArrayList<terms> derivTerms = new ArrayList<>();
    //private ArrayList<Character> derivSigns = new ArrayList<>();
    //private ArrayList<Character> signs = new ArrayList<>();
    public getDerivative(){
        
    }
    public terms getPolynomialDerivative(terms T){
        return new terms((T.getCoef()*T.getExp()), T.getExp()-1);
    }
    public terms getLogarithmicDerivative(terms T){
        getDerivative(T.getInnerFunction());
        functionCalc One = new functionCalc("1", "cartesian", -100000, 100000);
        functionCalc x = new functionCalc(T.getInnerFunction().getDerivTerms(), T.getInnerFunction().getDerivSigns());
        return new terms(One, One, T.getInnerFunction(), x, 1);
    }
    public functionCalc getExponentialDerivative(functionCalc base, functionCalc exponent){
        functionCalc One = new functionCalc("1", "cartesian", -100000, 100000);
        functionCalc Terms = new functionCalc("0", "cartesian", -100000, 100000);
        getDerivative(base);
        getDerivative(exponent);
        functionCalc x = new functionCalc(base.getDerivTerms(), base.getDerivSigns());
        functionCalc y = new functionCalc(exponent.getDerivTerms(), exponent.getDerivSigns());
        terms temp = new terms(One, One, x, base, 1);
        temp.setNumerator(exponent, One);
        terms temp2 = new terms(One, One, y, One, 1);
        temp2.setNumerator(new functionCalc((new terms(base, Math.E)), '+'), One);
        Terms.getTerms().add(temp);
        Terms.getSigns().add('+');
        Terms.getTerms().add(temp2);
        Terms.getSigns().add('+');
        return Terms;
        
    }
    
    public void getDerivative(functionCalc F){
        functionCalc One = new functionCalc("1", "cartesian", -100000, 100000);
        F.getDerivTerms().clear();
        F.getDerivSigns().clear();
        for(terms T: F.getTerms()){//cycle through each term in the function just one
                
            switch (T.getType()){ 
                case "polynomial":
                    
                    F.getDerivTerms().add(getPolynomialDerivative(T));
                    F.getDerivSigns().add('+');                    
                    //terms temp = F.getDerivTerms().get(F.getDerivTerms().size()-1);
                    
                break;    
                case "exponential":// jumps to here
                    for (functionCalc F_I: T.getNumerator()){
                        getDerivative(F_I);
                        getDerivative(T.getNumExp().get(T.getNumerator().indexOf(F_I)));
                        functionCalc F_IPrime = new functionCalc(F_I.getDerivTerms(), F_I.getDerivSigns());
                        functionCalc F_IExpPrime = new functionCalc(F_I.getDerivTerms(), F_I.getDerivSigns());
                        terms temp1 = new terms(One, One, F_IPrime, F_I, 1);
                        temp1.getNumerator().add(T.getNumExp().get(T.getNumerator().indexOf(F_I)));
                        terms temp3 = new terms(F_I, Math.E);
                        terms temp2 = new terms(One, One, F_IExpPrime, One , 1);
                        temp2.getNumerator().add(new functionCalc(temp3, '+'));                        
                        //F.getDerivTerms().add(temp1); //causing index out of bounds exception in get DF_of_X
                        F.getDerivSigns().add('+');
                        //F.getDerivTerms().add(temp1);
                        //F.getDerivSigns().add('+');
                    }
                    for (functionCalc F_I: T.getDenominator()){
                        getDerivative(F_I);
                        getDerivative(T.getDenExp().get(T.getDenominator().indexOf(F_I)));
                        functionCalc F_IPrime = new functionCalc(F_I.getDerivTerms(), F_I.getDerivSigns());
                        functionCalc F_IExpPrime = new functionCalc(F_I.getDerivTerms(), F_I.getDerivSigns());
                        terms temp1 = new terms(One, One, F_IPrime, F_I, 1);
                        temp1.getNumerator().add(T.getDenExp().get(T.getDenominator().indexOf(F_I)));
                        terms temp3 = new terms(F_I, Math.E);
                        terms temp2 = new terms(One, One, F_IExpPrime, One , 1);
                        temp2.getNumerator().add(new functionCalc(temp3, '+'));
                        ArrayList<terms> Temp = new ArrayList<>();
                        Temp.add(temp1);
                        Temp.add(temp2);
                        ArrayList<Character> signs = new ArrayList<>();
                        signs.add('+');
                        signs.add('+');
                    }
                break;    
                case "logarithmic":
                    F.getDerivTerms().add(getLogarithmicDerivative(T));
                    F.getDerivSigns().add('+');                    
                    terms temp2 = F.getDerivTerms().get(F.getDerivTerms().size()-1);
                break;
            }
        }
    }    
}                           
        

