package 进击的客户端;

import java.util.Scanner;

import javax.swing.*;

public class ReaderWork implements Runnable{

	Scanner reader;
	JTextArea area;
	
	ReaderWork(Scanner reader,JTextArea area){
		super();
		this.reader=reader;
		this.area=area;
	}
	
	public void run() {
		String s;
		while((s = reader.nextLine()) != null){
			if(!s.equals("密码错误"))System.out.println(s);
			area.append("Server:"+s+'\n');
			area.setCaretPosition(area.getText().length());
		}
	}

}
