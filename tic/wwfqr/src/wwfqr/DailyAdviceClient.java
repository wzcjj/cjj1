package wwfqr;
import java.io.*;
import java.net.*;

public class DailyAdviceClient {
	public void go(){
		try {
			Socket s = new Socket("xiaoheiwu.cn.com",1227);
			InputStreamReader streamReader =new InputStreamReader(s.getInputStream());
			BufferedReader reader = new BufferedReader(streamReader);
			String advice = reader.readLine();
			System.out.println(advice);
			BufferedWriter writer = new BufferedWriter();
			writer.println("ncjj");
			reader.close();
			s.close();
		} catch (UnknownHostException e) {
			// TODO �Զ����ɵ� catch ��
			e.printStackTrace();
		} catch (IOException e) {
			// TODO �Զ����ɵ� catch ��
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		DailyAdviceClient client = new DailyAdviceClient();
		client.go();
	}

}
