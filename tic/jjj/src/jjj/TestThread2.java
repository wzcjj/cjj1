package jjj;

public class TestThread2 extends Thread{
	public void run(){
		for(int i=1;i<=5;i++){
			try {
				Thread.sleep(10);
			} catch (InterruptedException e) {
				// TODO �Զ����ɵ� catch ��
				e.printStackTrace();
			}
			System.out.println("2");
		}
	}
}
