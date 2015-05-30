package jjj;

public class Test{
	public static void main(String args[]){
		TestThread t1 = new TestThread();
		TestThread2 t2 = new TestThread2();
		t1.start();
		t2.start();
		Thread t3 = new Thread(new TestThread3());
	}
}