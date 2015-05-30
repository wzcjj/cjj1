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
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		} catch (IOException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		DailyAdviceClient client = new DailyAdviceClient();
		client.go();
	}

}
