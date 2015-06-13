

package function;

import java.util.ArrayList;


public class terms {
    private double coefficient;//coefficient for all expressions
    private double exponent;//exponent if exponent is a constant
    private String type;//type of function
    private String trigType;//identifies which trig expression is used
    private double Base;//base for exponential and logarithmic functions
    private functionCalc Exponent;//exponent for exponential functions
    private functionCalc innerFunction; //for radical expression
    private functionCalc trigFunc; //for trigonometric expressions
    private ArrayList<functionCalc> numerator = new ArrayList<>();//numerator for rational expressions
    private ArrayList<functionCalc> denominator = new ArrayList<>();//denominator for rational expressions
    private ArrayList<functionCalc> numExponent = new ArrayList<>();
    private ArrayList<functionCalc> denExponent = new ArrayList<>();
    private functionCalc Function;
    
    public terms(double coef, double exp){
        coefficient = coef;
        exponent = exp;
        type = "polynomial";
    }
        public terms(functionCalc expNum, functionCalc expDen, functionCalc innerTermNumerator, functionCalc innerTermDenominator, double coef){
        coefficient = coef;
        numerator.add(innerTermNumerator);
        denominator.add(innerTermDenominator);
        numExponent.add(expNum);
        denExponent.add(expDen);
        Exponent = expNum;
        type="exponential";
        
    }
    public terms(double coef, functionCalc numer, functionCalc denom){
        coefficient= coef;
        numerator.add(numer);
        denominator.add(denom);
        type="rational";
        
    }
    //public terms(functionCalc innerFunc, double exp){
        
        //innerFunction = innerFunc;
        //type="radical";
        
    //}
    public terms(functionCalc innerFunc, double base){
        
        innerFunction = innerFunc;
        Base = base;
        type="logarithmic";
        
    }
    public terms(double coef, String tFunc, functionCalc innerFunc){
        coefficient = coef;
        trigType=tFunc;
        trigFunc=innerFunc;
        type="trigonometric";
        
    }
    public void setCoef(double coef){
        coefficient = coef;
    }
    public double getCoef(){
        return coefficient;
    }
    public void setExponent(double exp){
        exponent = exp;
    }
    
   
    public double getExp(){
        return exponent;
        
        }
    public functionCalc getExponent(){
        return Exponent;
        }
    public functionCalc getInnerFunc(){
        return innerFunction;
    }
    public void setNumerator(functionCalc numer, functionCalc exp){
        numerator.add(numer);
        numExponent.add(exp);
    }
    public void addExpTerms(terms Term){
        functionCalc One = new functionCalc("1","cartesian", -100000, 100000);
        switch (Term.type){
            case "polynomial":
            numerator.add(new functionCalc(("" + Term.coefficient + "x^" + Term.exponent),"cartesian", -100000, 100000));
            numExponent.add(One);
            break;
            case "exponential":
        for (functionCalc t: Term.getNumerator()){
            numerator.add(t);
            numExponent.add(Term.getNumExp().get(Term.getNumerator().indexOf(t)));
        }
        for (functionCalc t: Term.getDenominator()){
            denominator.add(t);
            denExponent.add(Term.getNumExp().get(Term.getNumerator().indexOf(t)));
        }
            break;
    }
    }
    public void setDenominator(functionCalc denom, functionCalc exp){
        denominator.add(denom);
        denExponent.add(exp);
    }
    public ArrayList<functionCalc> getNumerator(){
        return numerator;
        }
    public ArrayList<functionCalc> getDenominator(){
        return denominator;
        }
    public ArrayList<functionCalc> getNumExp(){
        return numExponent;
    }
    public ArrayList<functionCalc> getDenExp(){
        return denExponent;
    }
    public String getType(){
        return type;
    }
    public double getBase(){
        return Base;
    }
    public functionCalc getInnerFunction(){
        
        return innerFunction;
    }
    }

