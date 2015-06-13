

package function;


public class parenthesis {
    private int count;
    public String parenthesis(String function, int index){
        int flag=1;
        count = index;
        String temp = "";
	do{
            if (function.charAt(index) == '('){
                flag++;
            }
            if (function.charAt(index) == ')'){
                flag--;
            }
            if (flag != 0)
            {
                temp+=function.charAt(index++);
            }
            }while(flag != 0);
        count = (index - count);
        return temp;
    }
    public int getCount(){
        return count;
    }
}
