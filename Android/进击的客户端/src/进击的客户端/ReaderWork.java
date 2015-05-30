package �����Ŀͻ���;

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
			if(!s.equals("�������"))System.out.println(s);
			area.append("Server:"+s+'\n');
			area.setCaretPosition(area.getText().length());
		}
	}

}
