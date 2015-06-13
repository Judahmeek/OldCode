/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package stock_data;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.net.URLConnection;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author malehray
 */
public class Stock_data {


    public static void main(String[] args) throws IOException {
        
       String symb = "AAPL";
        
       int from_month = 1;
       int from_day = 1;
       int from_year = 2013;
       
       int to_month = 4;
       int to_day = 21;
       int to_year = 2014;
       
       String url_string = "http://ichart.yahoo.com/table.csv?s=" +
               symb + "&a=" + (from_month-1) + "&b=" + from_day +
               "&c=" + from_year + "&d=" + (to_month-1) +
               "&e=" + to_day + "&f=" + to_year + "&g=d&ignore=.csv";
       
       System.out.println(url_string);
       
       URL url = new URL(url_string);
       URLConnection connection = url.openConnection();
       InputStream istream = connection.getInputStream();
       Scanner in = new Scanner(istream);
       
       ArrayList<Double> stock_price = new ArrayList<Double>(0);
       
       if (in.hasNextLine()) {
           in.nextLine();
       }
       
       while (in.hasNextLine()) {
  
           String line = in.nextLine();
           Scanner inline = new Scanner(line);
           inline.useDelimiter(",");
           inline.next();
           inline.next();
           inline.next();
           inline.next();
           
           stock_price.add(Double.parseDouble(inline.next()));
  
       }

       for (Double x : stock_price) {
           System.out.println(x);
       }
       
               
        
    }
}
