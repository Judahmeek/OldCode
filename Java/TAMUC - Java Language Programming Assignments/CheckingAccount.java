package bank_demo;

public class CheckingAccount extends BankAccount {
    
    private int transCounter;
    private static int maxFreeTrans = 3;
    private static double transFee = 1.0;
    
    public CheckingAccount(int acctNumber, double initBalance) {
        super(acctNumber,initBalance);
        this.transCounter = 0;
    }
    
    @Override public void withdraw(double amt) {
        transCounter++;
        super.withdraw(amt);
    }
    
    @Override public void deposit(double amt) {
        transCounter++;
        super.deposit(amt);
    }
    
    @Override public String toString() {
        String output = "Checking Account " + this.getAcctNumber() 
                + ", Balance = " + this.getBalance();
        return output;
    }
    
    public void deductFees() {
        if (transCounter > maxFreeTrans) {
            super.withdraw((transCounter-maxFreeTrans)*transFee);
        }
        transCounter = 0;
    }
    
    
}
