package wwfqr;
import java.io.*;
import java.net.*;

public class DailyAdviceServer {
	
	String[] adviceList = {"a","b","c","d","e"};
	
	private String getAdvice(){
		int random = (int) (Math.random() * adviceList.length);
		return adviceList[random];
	}
	
	public void go(){
		try {
			ServerSocket serverSock = new ServerSocket(4242);
			while(true){
				Socket sock = serverSock.accept();
				PrintWriter writer = new PrintWriter(sock.getOutputStream());
				String advice = getAdvice();
				writer.println(advice);
				writer.close();
				System.out.println(advice);
			}
		} catch (IOException e) {
			// TODO �Զ����ɵ� catch ��
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		DailyAdviceServer server = new DailyAdviceServer();
		server.go();
	}

}
