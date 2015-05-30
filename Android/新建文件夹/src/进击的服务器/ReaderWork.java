package 进击的服务器;

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
			area.append("Customer:"+s+'\n');
			area.setCaretPosition(area.getText().length());
		}
	}

}
