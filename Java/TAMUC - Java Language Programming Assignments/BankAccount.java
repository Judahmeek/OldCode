
package bank_demo;

public class BankAccount {
    
    private int acctNumber;
    private double balance;
    
    public BankAccount(int acctNumber, double initBalance) {
        this.acctNumber = acctNumber;
        this.balance = initBalance;
    }
    
    public void withdraw(double amt) {
        balance -= amt;
    }
    
    public void deposit(double amt) {
        balance += amt;
    }
    
    public double getBalance() {
        return balance;
    }
    
    public int getAcctNumber() {
        return acctNumber;
    }
    
    @Override public String toString() {
        String output = "Generic Account " + acctNumber + ", Balance = "
                + balance;
        return output;
    }
    
}
