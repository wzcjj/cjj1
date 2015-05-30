package sudoku;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;

import javax.swing.*;

class GridFrame extends JFrame {
          JPanel sudokus=new JPanel(new GridLayout(3,3,3,3));//������壬������Ϊ���񲼾֣�3��3�У����ˮƽ����ֱ����Ϊ3
          JPanel number=new JPanel(new GridLayout(9,1,3,3));
          JPanel sudoku[][];
          JPanel buttons=new JPanel(new GridLayout(3,1,3,3));
          JLabel t=new JLabel("1",JLabel.CENTER);        //�����ı���
          JLabel copyright=new JLabel("All Copyright Reserved 2014 cjj,xy",JLabel.CENTER);
          Sudoku btn[][];                             //������ť����
          Number button[];

          //�����ַ������飬Ϊ��ť����ʾ�ı���ֵ

         //ע���ַ�Ԫ�ص�˳����ѭ����Ӱ�ť����һ��


     public GridFrame(String s){
        super(s);  //Ϊ�������Ƹ�ֵ
        sudoku=new JPanel[4][4];
        for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)sudoku[i][j]=new JPanel(new GridLayout(3,3,3,3));
        this.setBackground(java.awt.Color.blue);
        setLayout(new BorderLayout());     //���崰�岼��Ϊ�߽粼��
        btn=new Sudoku[10][10];     //������ť����            
        for(int i=1;i<=9;i++)for(int j=1;j<=9;j++){//ѭ�����尴ť������ӵ������
               btn[i][j]=new Sudoku();
               sudoku[(i-1)/3+1][(j-1)/3+1].add(btn[i][j]);
         }
        for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)sudokus.add(sudoku[i][j]);
        sudokus.setBackground(java.awt.Color.black);
        button=new Number[10];		//������ť����        
        for(int i=1;i<=9;i++){//ѭ�����尴ť������ӵ������
        	button[i]=new Number(i);
        	number.add(button[i]);
        }
        	Start start=new Start();//������ť
        	buttons.add(start);
        	start.pushed();//������һ��
        	Answer answer = new Answer();//������ť
        	buttons.add(answer);
        	buttons.add(copyright,BorderLayout.SOUTH);
        	getContentPane().add(t,BorderLayout.NORTH);   //�ŵ��Ϸ�
            getContentPane().add(sudokus,BorderLayout.CENTER);   //�ŵ��м�
            getContentPane().add(number,BorderLayout.EAST);//�ŵ��ҷ�
            getContentPane().add(buttons,BorderLayout.SOUTH);//�ŵ��·�
            setVisible(true);
            setSize(500,550);//���ô�С
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//��Xʱ��������
            setLocationRelativeTo(null);               //�ô��������ʾ
        }

      public static void main(String[] args){

         GridFrame gl=new GridFrame("����");//����

         }
      public class Number extends JButton implements ActionListener {
    		int value;//��Ӧ������
    		Number(int i){
    			value=i;
    			this.setText(""+i);//��ʾ����
            	this.addActionListener(this);//������
    		}
    		
    		public void pushed(){
    			t.setText(""+value);//����label�е�����
    		}

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO �Զ����ɵķ������
				pushed();
			}
    	}
      public class Sudoku extends JButton implements ActionListener {
  		int value,canchange;//ֵ���Ƿ��ܸ�
  		Sudoku(){
  			value=0;
  			canchange=1;
  			this.setText("");
          	this.addActionListener(this);
  		}
  		public boolean check(int x,int y){
  			for(int i=1;i<=9;i++)if(x!=i&&btn[i][y].value==btn[x][y].value||y!=i&&btn[x][i].value==btn[x][y].value)return false;
  			for(int i=(x-1)/3*3+1;i<=(x-1)/3*3+3;i++)for(int j=(y-1)/3*3+1;j<=(y-1)/3*3+3;j++)if(i!=x&&j!=y){
  				if(btn[i][j].value==btn[x][y].value)return false;
  			}
  			return true;
  		}
  		public void pushed(){
  			int n=Integer.parseInt(t.getText());//��ȡlabel�е�����
  			if(n!=value)value=n;//�ı�value��ֵ
  			else value=0;
  			for(int i=1;i<=9;i++)for(int j=1;j<=9;j++)if(btn[i][j].canchange==1&&btn[i][j].value!=0){
  				if(check(i,j))btn[i][j].setForeground(Color.BLUE);
  				else btn[i][j].setForeground(Color.RED);
  			}
  			if(value>0)this.setText(""+value);//��ʾvalue
  			else this.setText("");
  		}

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO �Զ����ɵķ������
				if(canchange==1)pushed();
			}
  	}
      public class Start extends JButton implements ActionListener {
    	  Start(){
    		  this.setText("������������");
            	this.addActionListener(this);
    	  }
    	  public void solve(){
    		  OneThread t=new OneThread();
    		  t.start();
    		  try {
				t.join();
			} catch (InterruptedException e) {
				// TODO �Զ����ɵ� catch ��
				e.printStackTrace();
			}
    	  }
    	  public void change(){
    		  FileInputStream fis = null;
    		  try {
    				fis = new FileInputStream("sudokuin.tsv");//�����ļ�
    			} catch (FileNotFoundException e1) {
    				// TODO �Զ����ɵ� catch ��
    				e1.printStackTrace();
    			}
    			for(int i=1;i<=9;i++){//�����ɵ���������
    				for(int j=1;j<=9;j++){
    					try {
    						int n=fis.read();
    						while(n==9||n==10||n==13)n=fis.read();//���˲������ֵ�����
    						btn[i][j].value=n-'0';
    						fis.read();
    					} catch (IOException e1) {
    						// TODO �Զ����ɵ� catch ��
    						e1.printStackTrace();
    					}
    					if(btn[i][j].value!=0)
    						{
    							btn[i][j].canchange=0;//��ʼ������
    							btn[i][j].setForeground(Color.BLACK);
    						}
    					else btn[i][j].canchange=1;
    					if(btn[i][j].value!=0)btn[i][j].setText(""+btn[i][j].value);
    					else btn[i][j].setText("");
    				}
    			}
    			try {
					fis.close();
				} catch (IOException e) {
					// TODO �Զ����ɵ� catch ��
					e.printStackTrace();
				}
    	  }
    	  public void chooselevel(){
    		  
    	  }
    	  void pushed(){
    		  solve();
              change();
    	  }
    	  public class OneThread extends Thread{
    		  public void run(){
    			  try {
    	    		  Level l=new Level();
    	    		  l.setVisible(false);
    	  				Runtime.getRuntime().exec("createfinal");//����������������
    	  			} catch (IOException e) {
    	  				// TODO �Զ����ɵ� catch ��
    	  				e.printStackTrace();
    	  			}
    		  }
    	  }
		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO �Զ����ɵķ������
			pushed();
		}
    	  public class Level extends JFrame{
    		  public Level(){
    			  super("ѡ���Ѷ�");
    			  Levels easy=new Levels("easy");
    			  Levels normal=new Levels("normal");
    			  Levels hard=new Levels("hard");
    			  JPanel hardlevels=new JPanel(new GridLayout(3,1,3,3));
    			  hardlevels.add(easy);
    			  hardlevels.add(normal);
    			  hardlevels.add(hard);
    	            getContentPane().add(hardlevels,BorderLayout.CENTER);
    	            setVisible(true);
    	            setSize(300,200);//���ô�С
    	            setLocationRelativeTo(null);               //�ô��������ʾ
    		  }
    		  public class Levels extends JButton implements ActionListener{
    			  String level;
    			  public Levels(String s){
    				  super(s);
    				  level=s;
    			  }
				@Override
				public void actionPerformed(ActionEvent arg0) {
					// TODO �Զ����ɵķ������
					FileOutputStream fis = null;
					try {
						fis = new FileOutputStream("hardlevel.in");//���ļ������
					} catch (FileNotFoundException e1) {
						// TODO �Զ����ɵ� catch ��
						e1.printStackTrace();
					}
					try {
						fis.write(level.getBytes());
					} catch (IOException e) {
						// TODO �Զ����ɵ� catch ��
						e.printStackTrace();
					}
					try {
						fis.close();
					} catch (IOException e) {
						// TODO �Զ����ɵ� catch ��
						e.printStackTrace();
					}
					this.setVisible(false);
				}
    			  
    		  }
    	  }
      }
      public class Answer extends JButton implements ActionListener {
    	  Answer(){
    		  this.setText("��ʾ��");
            	this.addActionListener(this);
    	  }
    	public void solve(){
    		OneThread t=new OneThread();
  		  t.start();
  		  try {
				t.join();
			} catch (InterruptedException e) {
				// TODO �Զ����ɵ� catch ��
				e.printStackTrace();
			}
    	}
    	public class OneThread extends Thread{
  		  public void run(){
  			  try {
  	  				Runtime.getRuntime().exec("sudoku");//����������������
  	  			} catch (IOException e) {
  	  				// TODO �Զ����ɵ� catch ��
  	  				e.printStackTrace();
  	  			}
  		  }
  	  }
    	public void change(){
			FileInputStream fis = null;
			try {
				fis = new FileInputStream("sudokuout.tsv");//���ļ������
			} catch (FileNotFoundException e1) {
				// TODO �Զ����ɵ� catch ��
				e1.printStackTrace();
			}
			for(int i=1;i<=9;i++){
				for(int j=1;j<=9;j++){
					try {
						int n=fis.read();
						while(n==9||n==10||n==13)n=fis.read();
						btn[i][j].value=n-'0';
						fis.read();
					} catch (IOException e1) {
						// TODO �Զ����ɵ� catch ��
						e1.printStackTrace();
					}
					if(btn[i][j].canchange==1)btn[i][j].setForeground(Color.BLUE);
					btn[i][j].setText(""+btn[i][j].value);
				}
			}
    		try {
				fis.close();
			} catch (IOException e) {
				// TODO �Զ����ɵ� catch ��
				e.printStackTrace();
			}
    	}
		public void actionPerformed(ActionEvent e) {
			// TODO �Զ����ɵķ������
			solve();
			change();
		}
    	  
      }
} 

 