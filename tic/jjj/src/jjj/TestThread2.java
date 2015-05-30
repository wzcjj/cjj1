package jjj;

public class TestThread2 extends Thread{
	public void run(){
		for(int i=1;i<=5;i++){
			try {
				Thread.sleep(10);
			} catch (InterruptedException e) {
				// TODO 自动生成的 catch 块
				e.printStackTrace();
			}
			System.out.println("2");
		}
	}
}
