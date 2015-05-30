package 进击的服务器;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.PrintWriter;
import java.net.Socket;

import javax.swing.*;

public class Send extends JButton implements ActionListener{
	PrintWriter writer;
	JTextField field;
	JTextArea area;
	Send(String s,PrintWriter writer,JTextArea area){
		super(s);
		this.writer=writer;
		this.area=area;
		this.addActionListener(this);
	}
	public void pushed(){
		String s = field.getText();
		area.append("Us:"+s+'\n');
		field.setText("");
		writer.println(s);
		writer.flush();
	}

	public void actionPerformed(ActionEvent arg0) {
		pushed();
	}
}
