import java.io.*;
import java.net.*;
import java.util.Scanner;

class Client implements Runnable
{
	private Socket sock = null;
	public Client(Socket sock)
	{
		this.sock = sock;
	}
	
	public void run()
	{
		OutputStream out;
		try
		{
			out = sock.getOutputStream();
			BufferedWriter bwriter = new BufferedWriter(new OutputStreamWriter(out, "UTF-8"));
			PrintWriter writer = new PrintWriter(bwriter);
			InputStream in = sock.getInputStream();
			BufferedReader breader = new BufferedReader(new InputStreamReader(in, "UTF-8"));
			Scanner reader = new Scanner(breader);
			for (int i = 0; i < 10; i ++)
			{
				writer.println("Ð¤Èð");
				writer.flush();
				try
				{
					Thread.sleep(1000);
				} catch (InterruptedException e){}
			}
			String read = reader.nextLine();
			System.out.println(read);
		} catch (IOException e)
		{
			e.printStackTrace();
		}
		
	}
}

public class Test
{
	
	public static void main(String[] args)
	{
		ServerSocket s = null;
		try
		{
			s = new ServerSocket(1234);
			while (true)
			{
				Socket sock	= s.accept();
				new Thread(new Client(sock)).start();
			}
		} catch (IOException e)
		{
			if (s != null)
				try
				{
					s.close();
				} catch (Exception e1){}
			System.out.println("Æô¶¯·þÎñÆ÷Ê§°Ü£¡");
		}
	}
	
}
