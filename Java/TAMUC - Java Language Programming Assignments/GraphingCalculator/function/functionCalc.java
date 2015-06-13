

package function;

import java.util.ArrayList;
//import java.util.Scanner;

public class functionCalc {
    private String function;
    //private String domain;
    private String fSystem;        
    private double xMin;
    private double xMax;
    //private double x=0;
    private ArrayList<terms> Terms = new ArrayList<>();
    private ArrayList<terms> derivativeTerms = new ArrayList<>();
    private ArrayList<Character> signs = new ArrayList<>();
    private ArrayList<Character> derivativeSigns = new ArrayList<>();
    private ArrayList<cartesianFuncCalc> y1 = new ArrayList<>();//ArrayList for multiple functions
    //private ArrayList<polarFuncCalc> y2 = new ArrayList<>();
    
    public functionCalc(){
        
    }
    public functionCalc(String func, String system, double xMinimum, double xMaximum){
        function = func;
        fSystem = system;
        xMin = xMinimum;
        xMax = xMaximum;
        switch (fSystem){
            case("cartesian"):
                cartesianFuncCalc temp1 = new cartesianFuncCalc(function, Terms, signs);
                y1.add(temp1);
            break;
            case("polar"):
                //polarFuncCalc temp2 = new polarFuncCalc(function, Terms, signs);
                //y2.add(temp2);
            break;
        }
    }
    public functionCalc(ArrayList<terms> T, ArrayList<Character> S){
        Terms = T;
        signs = S;
        fSystem = "cartesian";
    }
    public functionCalc(terms T, char S){
        Terms.add(T);
        signs.add(S);
        fSystem = "cartesian";
    }
    public double getF_of_X(double X, int index){
        double temp=0;
        switch (fSystem){
            case("cartesian"):
                temp = y1.get(index).F_of_X(X, Terms, signs);
            break;
        }
       return temp;
    }
    public double getDF_of_X(double X, int index){
        double temp=0;
        switch (fSystem){
            case("cartesian"):
                temp = y1.get(index).F_of_X(X, derivativeTerms, derivativeSigns);
            break;
        }
       return temp;
    }
    public ArrayList<terms> getTerms(){
        return Terms;
    }
    public ArrayList<terms> getDerivTerms(){
        return derivativeTerms;
    }
    public ArrayList<Character> getSigns(){
        return signs;
    }
    public ArrayList<Character> getDerivSigns(){
        return derivativeSigns;
    }
    public void setTerms(ArrayList<terms> Term, ArrayList<Character> Signs){
        Terms = Term;
        signs = Signs;
    }
    
    public String getFunction(){
        return function;
    }
    public String getFSystem(){
        return fSystem;
    }
    public void setFSystem(String FSystem){
        fSystem = FSystem;
    }
}
