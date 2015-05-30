package �����ķ�����;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

import javax.swing.*;

public class TheFrame extends JFrame{
	
	JTextArea area = new JTextArea(10,20);
	Send send;
	TheField field;
	JPanel panel = new JPanel(new GridLayout(1,2,3,3));
	
	TheFrame(String s,PrintWriter writer,Scanner reader){
		super(s);
		area.setLineWrap(true);        //�����Զ����й��� 
		area.setWrapStyleWord(true);            // ������в����ֹ���
		area.setEditable(false);
		send = new Send("send",writer,area);
		field = new TheField(20,send);
		send.field=field;
		Thread readerThread = new Thread(new ReaderWork(reader,area));
		readerThread.start();
		panel.add(field);
		//panel.add(send);
        getContentPane().add(new JScrollPane(area),BorderLayout.CENTER); 
        getContentPane().add(panel,BorderLayout.SOUTH); 
        setVisible(true);
        setSize(500,550);//���ô�С
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//��Xʱ��������
        setLocationRelativeTo(null);               //�ô��������ʾ
	}
}
