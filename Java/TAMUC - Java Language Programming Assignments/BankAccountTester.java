
package bank_demo;

public class BankAccountTester {

    public static void main(String[] args) {
        
        BankAccount acct = new SavingsAccount(101,1000);
        System.out.println(acct);
        acct.withdraw(100);
        System.out.println(acct);
        acct.deposit(200);
        System.out.println(acct);
        acct.withdraw(300);
        System.out.println(acct);
        acct.deposit(400);
        System.out.println(acct);
        ((SavingsAccount) acct).addInterest();
        System.out.println(acct);
        
        
    }
}
