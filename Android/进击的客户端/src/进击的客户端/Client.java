package 进击的客户端;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class Client {
	private TheFrame theFreame;
	
	private void go(){
		try {
			Socket sock = new Socket("xiaoheiwu.cn.com", 1228);
			OutputStream out = sock.getOutputStream();
			BufferedWriter bwriter = new BufferedWriter(new OutputStreamWriter(out, "UTF-8"));
			PrintWriter writer = new PrintWriter(bwriter);
			InputStream in = sock.getInputStream();
			BufferedReader breader = new BufferedReader(new InputStreamReader(in, "UTF-8"));
			Scanner reader = new Scanner(breader);
			theFreame = new TheFrame("进击的客户端",writer,reader);
		} catch (Exception e) {
			System.out.println("连接服务器失败");
		}
	}

	public static void main(String[] args) {
		Client client = new Client();
		client.go();
	}

}
