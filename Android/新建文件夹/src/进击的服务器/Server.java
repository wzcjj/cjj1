package 进击的服务器;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Server {
	private TheFrame theFreame;

	public static void main(String[] args)
	{
		ServerSocket s = null;
		try
		{
			s = new ServerSocket(1227);
			while (true)
			{
				Socket sock	= s.accept();
				new Thread(new ServerClient(sock)).start();
			}
		} catch (IOException e)
		{
			if (s != null)
				try
				{
					s.close();
				} catch (Exception e1){}
			System.out.println("启动服务器失败！");
		}
	}

}
