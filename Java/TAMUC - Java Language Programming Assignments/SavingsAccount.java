package bank_demo;


public class SavingsAccount extends BankAccount {
    
    private static double intRate = .05;
    
    public SavingsAccount(int acctNumber, double initBalance) {
        super(acctNumber, initBalance);
    }
    
    public void addInterest() {
        double interest = this.getBalance() * intRate / 12;
        this.deposit(interest);
    }
    
    @Override public String toString() {
        String output = "Savings Account " + this.getAcctNumber() 
                + ", Balance = " + this.getBalance();
        return output;
    }
    
}
