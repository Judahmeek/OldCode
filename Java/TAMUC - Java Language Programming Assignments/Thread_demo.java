
package thread_demo;


public class Thread_demo {

    public static final int N = 100;
    public static final int Nthread = 10;
    
    
    public static void main(String[] args) throws InterruptedException {
        
        class TotalObject {
            public int total;
            public TotalObject() {
                total = 0;
            }
        }
        
        final TotalObject total_obj = new TotalObject();
        
        class MyRunnable implements Runnable {
            public void run() {
                try {
                    for (int k = 0; k < N; k++) {
                        //synchronized(total_obj) {
                            total_obj.total = total_obj.total + 1;
                            Thread.sleep(1);
                        //}
                    }
                }
                catch (InterruptedException e) {
                }
            }
        }
        
        Runnable[] runnables = new Runnable[Nthread];
        Thread[] threads = new Thread[Nthread];
        
        for (int k = 0; k < Nthread; k++) {
            runnables[k] = new MyRunnable();
            threads[k] = new Thread(runnables[k]);
        }
        
        for (int k = 0; k < Nthread; k++) {
            threads[k].start();
        }
        
        
        Thread.sleep(2000);
        
        System.out.println("Total is " + total_obj.total);
        
        
    }
}
