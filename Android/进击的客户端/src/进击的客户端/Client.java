package �����Ŀͻ���;

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
			theFreame = new TheFrame("�����Ŀͻ���",writer,reader);
		} catch (Exception e) {
			System.out.println("���ӷ�����ʧ��");
		}
	}

	public static void main(String[] args) {
		Client client = new Client();
		client.go();
	}

}
