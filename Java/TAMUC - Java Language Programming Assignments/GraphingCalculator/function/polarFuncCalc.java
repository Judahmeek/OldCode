

package function;

import java.util.ArrayList;
import java.util.Scanner;


public class polarFuncCalc {
    polarFuncCalc(String function, ArrayList<terms> Terms, ArrayList<String> signs){
        double exponent=0;
        double currentCoeff=0;
        int index=0;
        Scanner f=new Scanner(function);
        Terms.clear();
        signs.clear();
       while (f.hasNext()){
          String temp = f.next();
          if (temp.charAt(0) == '+'){
              signs.add("+");
          }
          else if (temp.charAt(0) == '-'){
              signs.add("-");
          }
          else{
              if(temp.charAt(0) == 't'){
                  currentCoeff = 1;
                  }
              else
                  //trig function switch in here
                  currentCoeff=(new getDouble()).getDouble(temp, 0);
                    for(int i = 0; i < temp.length(); i++){
                        if (temp.charAt(i)=='t'){
                            index = i;
                            break;
                        }
                        else
                            index = temp.length();
                    }
               if (index < (temp.length()-1))
              exponent = (new getDouble()).getDouble(temp, index+1);
          else if (index==temp.length())
              exponent = 0;
          else
              exponent = 1;
          Terms.add(new terms(currentCoeff, exponent));
          
          }
      }
    }
}
