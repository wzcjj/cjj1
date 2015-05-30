import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;


public class TestClient
{
	
	public static void main(String[] args)
	{
		try
		{
			Socket sock = new Socket("127.0.0.1", 1234);
			OutputStream out = sock.getOutputStream();
			BufferedWriter bwriter = new BufferedWriter(new OutputStreamWriter(out, "UTF-8"));
			PrintWriter writer = new PrintWriter(bwriter);
			InputStream in = sock.getInputStream();
			BufferedReader breader = new BufferedReader(new InputStreamReader(in, "UTF-8"));
			Scanner reader = new Scanner(breader);
			//for(int i=1;;i++){
				writer.println("ncjj");
				writer.flush();
				writer.println("ccjj");
				writer.flush();
				Thread.sleep(1000);
				reader.close();
				writer.close();
				sock.close();
			//}
			//for (int i = 0; i < 10; i ++)
			//{
			//	String read = reader.nextLine();
			//	System.out.println(read);
			//}
		} catch (Exception e)
		{
			System.out.println("连接已断开！");
		}
	}
	
}
