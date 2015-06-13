package function;

import java.util.ArrayList;
import java.util.Scanner;

public class cartesianFuncCalc {
    
    public cartesianFuncCalc(String function, ArrayList<terms> Terms, ArrayList<Character> signs){
        double currentExp=0;
        double currentCoeff=1;
        int emptyCount = 0;
        double temp;
        String tempFunc = "";
        String tempFunc2 = "";
        Terms.clear();
        signs.clear();
        signs.add('+');
        parenthesis x = new parenthesis();
        Terms.add(new terms(currentCoeff, currentExp));
        for (int i=0; i < function.length(); i++){
             getDouble g = new getDouble();
            switch (function.charAt(i)){
                case '0':
                    currentCoeff = g.getDouble(function, i);
                    i+=g.getCount()-1;
                    Terms.get(Terms.size()-1).setCoef(currentCoeff);
                break;
                case '1':
                    currentCoeff = g.getDouble(function, i);
                    i+=g.getCount()-1;
                    Terms.get(Terms.size()-1).setCoef(currentCoeff);
                break;
                case '2':
                    currentCoeff = g.getDouble(function, i);
                    i+=g.getCount()-1;
                    Terms.get(Terms.size()-1).setCoef(currentCoeff);
                break;
                case '3':
                    currentCoeff = g.getDouble(function, i);
                    i+=g.getCount()-1;
                    Terms.get(Terms.size()-1).setCoef(currentCoeff);
                break;
                case '4':
                    currentCoeff = g.getDouble(function, i);
                    i+=g.getCount()-1;
                    Terms.get(Terms.size()-1).setCoef(currentCoeff);
                break;
                case '5':
                    currentCoeff = g.getDouble(function, i);
                    i+=g.getCount()-1;
                    Terms.get(Terms.size()-1).setCoef(currentCoeff);
                break;
                case '6':
                    currentCoeff = g.getDouble(function, i);
                    i+=g.getCount()-1;
                    Terms.get(Terms.size()-1).setCoef(currentCoeff);
                break;
                case '7':
                    currentCoeff = g.getDouble(function, i);
                    i+=g.getCount()-1;
                    Terms.get(Terms.size()-1).setCoef(currentCoeff);
                break;
                case '8':
                    currentCoeff = g.getDouble(function, i);
                    i+=g.getCount()-1;
                    Terms.get(Terms.size()-1).setCoef(currentCoeff);
                break;
                case '9':
                    currentCoeff = g.getDouble(function, i);
                    i+=g.getCount()-1;
                    Terms.get(Terms.size()-1).setCoef(currentCoeff);
                break;
                case '(':
                    int flag = 1;
                    functionCalc h = new functionCalc("1", "cartesian", -100000, 100000);
                    
                    functionCalc one = new functionCalc("1", "cartesian", -100000, 100000);
                        tempFunc = "";
                        i++;
                        tempFunc = x.parenthesis(function, i);
                            i+=x.getCount();
                            System.out.println(function.charAt(i) + "check");
                            //System.out.println(function.charAt(i));
                            functionCalc f = new functionCalc(tempFunc, "cartesian", -100000, 100000);
                    
                   // System.out.println(tempFunc);
                            i++;
                    if(i < function.length()){
                    if (function.charAt(i) == '^')
                    {
                        i++;
                        
                        if(function.charAt(i) == '('){
                            i++;
                            //flag = 1;
                            tempFunc2 = x.parenthesis(function, i);
                            i+=x.getCount();
                            h = new functionCalc(tempFunc2, "cartesian", -100000, 100000);
                            System.out.println(tempFunc2);
                            System.out.println(function.charAt(i));
                            Terms.remove(Terms.size()-1);
                            Terms.add(new terms(h, one, f, one, 1));
                            
                        }
                        else
                        {
                            double t = g.getDouble(function, i);
                            h = new functionCalc((""+t), "cartesian", -100000, 100000);
                            i +=g.getCount();
                            Terms.remove(Terms.size()-1);
                            Terms.add(new terms(h, one, f, one, 1));
                        }
                    }
                    
                    else{
                        h = new functionCalc("1", "cartesian", -100000, 100000);
                        Terms.remove(Terms.size()-1);
                        Terms.add(new terms(h, one, f, one, 1));
                    }
                    }
                    else {
                        System.out.println("Made it here");
                        Terms.remove(Terms.size()-1);
                        Terms.add(new terms(one, one, f, one, 1));
                    }
                    //currentCoeff = Terms.get(Terms.size()-1).getCoef();
                    
                    
                    
                break;
                case '+':
                    signs.add('+');
                break;
                case '-':
                    if (Terms.isEmpty())
                    {
                        signs.remove(0);
                        signs.add('-');
                    }
                    signs.add('-');
                break;
                case '*':
                    
                break;
                case '/':
                    i++;
                    emptyCount++;
                    i++;
                    functionCalc m = new functionCalc("1", "cartesian", -100000, 100000);
                    
                    functionCalc exp;
                    functionCalc den;                 
                    //Terms.remove(Terms.size()-1);
                    flag = 1;
                    tempFunc="";
                    tempFunc2="";
                    if (function.charAt(i) == '(')
                    {
                        i++;
                        tempFunc=x.parenthesis(function, i);
                       System.out.println(tempFunc);
                        i+=x.getCount(); // sitting on 1-digit after close parenthesis
                        //i++;
                        den = new functionCalc(tempFunc, "cartesian", -100000, 100000);
                     }
                     else 
                     {
                        double temp2 = g.getDouble(function, i);
                        i+=g.getCount();
                        den = new functionCalc(("" + temp2), "cartesian", -100000, 100000);
                     }
                    i++;
                    if (i < function.length())
                    {
                    switch (function.charAt(i))
                    {
                        case ' ':
                            switch (Terms.get(Terms.size()-1).getType())
                            {
				case "polynomial":
					String polynomial = (Terms.get(Terms.size()-1).getCoef() + "x^" + Terms.get(Terms.size()-1).getExp());
					functionCalc temporary = new functionCalc(polynomial, "cartesian", -100000, 100000);
					Terms.remove(Terms.size()-1);
					Terms.add(new terms(m, temporary, m, den, 1));
				break;
				case "exponential":
					Terms.get(Terms.size()-1).setDenominator(den, m);
				break;
                            }
                        break;
                        case '^':
                            i++;
                            getDouble v = new getDouble();
                            //i+=v.getCount();
                            if (function.charAt(i)=='(')
                            {
                                
				tempFunc2 = x.parenthesis(function, i);
				i+=x.getCount();
				exp = new functionCalc(tempFunc2, "cartesian", -100000, 100000);
                            }				
                            else 
                            {
				tempFunc2 = ("" + v.getDouble(function, i));
                                System.out.println("Yes it made it here and the exponent is " + tempFunc2);
				i+=v.getCount();
				exp = new functionCalc(tempFunc2, "cartesian", -100000, 100000);
                                System.out.println("Here" + exp.getF_of_X(1, i));
                            }
                            
                            switch (Terms.get(Terms.size()-1).getType())
                            {
				case "polynomial":
					String polynomial = ("(" + Terms.get(Terms.size()-1).getCoef() + "x^" + Terms.get(Terms.size()-1).getExp() + ")");
					functionCalc temporary = new functionCalc(polynomial, "cartesian", -100000, 100000);
					Terms.remove(Terms.size()-1);
					Terms.add(new terms(m, temporary, exp, den, 1));
				break;
				case "exponential":
					Terms.get(Terms.size()-1).setDenominator(den, exp);
				break;
                            }
                        break;
                    }
                    }
                    else
                    {
                        switch (Terms.get(Terms.size()-1).getType())
                            {
				case "polynomial":
					String polynomial = ("(" + Terms.get(Terms.size()-1).getCoef() + "x^" + Terms.get(Terms.size()-1).getExp() + ")");
					functionCalc temporary = new functionCalc(polynomial, "cartesian", -100000, 100000);
					Terms.remove(Terms.size()-1);
					Terms.add(new terms(m, temporary, m, den, 1));
				break;
				case "exponential":
					Terms.get(Terms.size()-1).setDenominator(den, m);
				break;
                            }
                    }
                break;
                case '^':
                    i++;
                    
                    if (function.charAt(i)== '('){
                        
                        tempFunc = "";
                        i++;
                        tempFunc = ("" + x.parenthesis(function, i));
                    
                    functionCalc j = new functionCalc(tempFunc, "cartesian", -100000, 100000);
                    
                   
                    }
                    else
                        tempFunc = ("" + g.getDouble(function, i));
                        switch (Terms.get(Terms.size()-1).getType()){
                            case "polynomial":
                                Terms.get(Terms.size()-1).setExponent(g.getDouble(function, i));
                            break;
                            case "exponential":
                                currentCoeff = Terms.get(Terms.size()-1).getCoef();
                                Terms.remove(Terms.size()-1);
                                functionCalc One = new functionCalc("1", "cartesian", -100000, 100000);
                                functionCalc t = new functionCalc(("" + currentCoeff), "cartesian", -100000, 100000);
                                functionCalc s = new functionCalc("tempFunc", "cartesian", -100000, 100000);
                                Terms.add(new terms(s, t, One, One, 1));
                            break;
                        }
                        
                break;
                case ' ':
                    emptyCount++;
                    System.out.println("" + function.charAt(i+1) + " " + emptyCount);
                    if (emptyCount%2 == 1)
                    Terms.add(new terms(1, 0));
                break;
                case 'x':
                    currentExp=1;
                    if (Terms.isEmpty())
                        signs.add('+');
                    Terms.get(Terms.size()-1).setExponent(currentExp);
                break;
                
            }
        }
    } 
        
    
    public functionCalc getYEqualOne(){
        return (new functionCalc("1", "cartesian", -100000, 100000));
    }
    public double F_of_X(double X, ArrayList<terms> Terms, ArrayList<Character> signs){
        double Y=0;
        int signcount=0;
        int i=0;
        //for (char x: signs){
          //  System.out.println("" + x);}
        //for (char x: F.getDerivSigns()){
            //System.out.println("" + x);
       
        for (terms x: Terms){
                switch (x.getType()){
                    case "polynomial":
                        //System.out.println("" + x.getCoef() + "(" + X + ")^" + x.getExp());
                        switch (signs.get(Terms.indexOf(x))){
                            case '+':
                                Y += x.getCoef()*Math.pow(X, x.getExp());
                            break;
                            case '-':
                                Y -= x.getCoef()*Math.pow(X, x.getExp());
                            break;
                            
                        }
                    break;
                    case "rational":
                        Y=1;
                        for (functionCalc y: x.getNumerator()){
                           Y*=y.getF_of_X(X, 0);
                        }
                        for (functionCalc y: x.getDenominator()){
                           Y/=y.getF_of_X(X, 0);
                        }
                    break;
                    case "exponential":
                        Y=1;
                        for (functionCalc y: x.getNumerator()){
                            //System.out.println("" + y.getFunction() + "^" + x.getNumExp().get(x.getNumerator().indexOf(y)).getFunction());
                            //System.out.println("" + Math.pow(y.getF_of_X(X, 0), x.getNumExp().get(x.getNumerator().indexOf(y)).getF_of_X(X, 0)));
                            Y*=Math.pow(y.getF_of_X(X, 0), x.getNumExp().get(x.getNumerator().indexOf(y)).getF_of_X(X, 0));
                            
                        }
                        
                        for (functionCalc y: x.getDenominator()){
                            //System.out.println("" + y.getFunction() + "^" + x.getDenExp().get(x.getDenominator().indexOf(y)).getFunction());
                            //System.out.println("" + Math.pow(y.getF_of_X(X, 0), x.getDenExp().get(x.getDenominator().indexOf(y)).getF_of_X(X, 0)));
                            Y/=Math.pow(y.getF_of_X(X, 0), x.getDenExp().get(x.getDenominator().indexOf(y)).getF_of_X(X, 0));
                  
                        }
                    break;
                    case "logarithmic":
                        Y=1;
                        for (functionCalc y: x.getNumerator()){
                            //System.out.println("" + y.getFunction() + "^" + x.getNumExp().get(x.getNumerator().indexOf(y)).getFunction());
                            //System.out.println("" + Math.pow(y.getF_of_X(X, 0), x.getNumExp().get(x.getNumerator().indexOf(y)).getF_of_X(X, 0)));
                            Y*=Math.pow(y.getF_of_X(X, 0), x.getNumExp().get(x.getNumerator().indexOf(y)).getF_of_X(X, 0));
                            
                        }
                        
                        for (functionCalc y: x.getDenominator()){
                            //System.out.println("" + y.getFunction() + "^" + x.getDenExp().get(x.getDenominator().indexOf(y)).getFunction());
                            //System.out.println("" + Math.pow(y.getF_of_X(X, 0), x.getDenExp().get(x.getDenominator().indexOf(y)).getF_of_X(X, 0)));
                            Y/=Math.pow(y.getF_of_X(X, 0), x.getDenExp().get(x.getDenominator().indexOf(y)).getF_of_X(X, 0));
                  
                        }
                        Y*=Math.log(x.getInnerFunc().getF_of_X(X, 0));
                        Y/=Math.log(x.getBase());
                    break;
                }
        }
        
        return Y;
    
    }
    }   
    
       