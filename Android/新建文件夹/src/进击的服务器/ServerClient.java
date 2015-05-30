package 进击的服务器;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class ServerClient implements Runnable{

	private TheFrame theFreame;
	private Socket sock = null;
	
	public ServerClient(Socket sock)
	{
		this.sock = sock;
	}
	
	public void run() {
		try {
			OutputStream out = sock.getOutputStream();
			BufferedWriter bwriter = new BufferedWriter(new OutputStreamWriter(out, "UTF-8"));
			PrintWriter writer = new PrintWriter(bwriter);
			InputStream in = sock.getInputStream();
			BufferedReader breader = new BufferedReader(new InputStreamReader(in, "UTF-8"));
			Scanner reader = new Scanner(breader);
			theFreame = new TheFrame("进击的服务器",writer,reader);
		} catch (Exception e) {
			System.out.println("连接服务器失败");
		}
	}

}
