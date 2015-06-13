

package function;


public class getDouble {
    private int count=0;
    //private double a;
    public double getDouble(String s, int i){
        double a=0;
        int decFlag=0;
        int n=0;
        count = 0;
        do{
            switch (s.charAt(i)){
               case '0':
                   if (decFlag ==0)
                   {a=(a*10)+0;
                   count++;}
                   else
                   {a+=(0*Math.pow(10, n--));
                   count++;}
               break;
               case '1':
                   if (decFlag ==0)
                   {a=(a*10)+1;
                   count++;
                   }
                   else
                   {a+=(1*Math.pow(10, n--));
                   count++;
                   }
               break;
               case '2':
                   if (decFlag ==0)
                   {a=(a*10)+2;
                   count++;
                   }
                   else
                   {a+=(2*Math.pow(10, n--));
                   count++;
                   }
               break;
               case '3':
                   if (decFlag ==0)
                   {a=(a*10)+3;
                   count++;
                   }
                   else
                   {a+=(3*Math.pow(10, n--));
                   count++;
                   }
               break;
               case '4':
                   if (decFlag ==0)
                   {a=(a*10)+4;
                   count++;
                   }
                   else
                   a+=(4*Math.pow(10, n--));
               break;
               case '5':
                   if (decFlag ==0)
                   {a=(a*10)+5;
                   count++;
                   }
                   else
                   {a+=(5*Math.pow(10, n--));
                   count++;
                   }
               break;
               case '6':
                   if (decFlag ==0)
                   {a=(a*10)+6;
                   count++;
                   }
                   else
                   {a+=(6*Math.pow(10, n--));
                   count++;
                   }
               break;
               case '7':
                   if (decFlag ==0)
                   {a=(a*10)+7;
                   count++;
                   }
                   else
                   {a+=(7*Math.pow(10, n--));
                   count++;
                   }
               break;
               case '8':
                   if (decFlag == 0)
                   {a=(a*10)+8;
                   count++;
                   }
                   else
                   {a+=(8*Math.pow(10, n--));
                   count++;
                   }
               break;
               case '9':
                   if (decFlag == 0)
                   {a=(a*10)+9;
                   count++;
                   }
                   else
                   {a+=(9*Math.pow(10, n--));
                   count++;
                   }
               break;
               case '.':
               {decFlag=1;
                   n=-1;
               count++;
               }
               break;
            }
            i++;
            if(i==s.length())
                break;
        }while(s.charAt(i)=='0' || s.charAt(i)=='1' || s.charAt(i)=='2' || s.charAt(i)=='3' || s.charAt(i)=='4' || s.charAt(i)=='5' || s.charAt(i)=='6' || s.charAt(i)=='7' || s.charAt(i)=='8' || s.charAt(i)=='9' || s.charAt(i)=='.');
        if (i==1 && a==0 && s.charAt(0)!=0)
            a=1;
        return a;
    }
    public int getCount(){
        return count;
    }
    
}
