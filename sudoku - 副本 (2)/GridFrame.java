package sudoku;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;

import javax.swing.*;

class GridFrame extends JFrame {
          JPanel sudokus=new JPanel(new GridLayout(3,3,3,3));//定义面板，并设置为网格布局，3行3列，组件水平、垂直间距均为3
          JPanel number=new JPanel(new GridLayout(9,1,3,3));
          JPanel sudoku[][];
          JPanel buttons=new JPanel(new GridLayout(3,1,3,3));
          JLabel t=new JLabel("1",JLabel.CENTER);        //定义文本框
          JLabel copyright=new JLabel("All Copyright Reserved 2014 cjj,xy",JLabel.CENTER);
          Sudoku btn[][];                             //声明按钮数组
          Number button[];

          //定义字符串数组，为按钮的显示文本赋值

         //注意字符元素的顺序与循环添加按钮保持一致


     public GridFrame(String s){
        super(s);  //为窗体名称赋值
        sudoku=new JPanel[4][4];
        for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)sudoku[i][j]=new JPanel(new GridLayout(3,3,3,3));
        this.setBackground(java.awt.Color.blue);
        setLayout(new BorderLayout());     //定义窗体布局为边界布局
        btn=new Sudoku[10][10];     //创建按钮数组            
        for(int i=1;i<=9;i++)for(int j=1;j<=9;j++){//循环定义按钮，并添加到面板中
               btn[i][j]=new Sudoku();
               sudoku[(i-1)/3+1][(j-1)/3+1].add(btn[i][j]);
         }
        for(int i=1;i<=3;i++)for(int j=1;j<=3;j++)sudokus.add(sudoku[i][j]);
        sudokus.setBackground(java.awt.Color.black);
        button=new Number[10];		//创建按钮数组        
        for(int i=1;i<=9;i++){//循环定义按钮，并添加到面板中
        	button[i]=new Number(i);
        	number.add(button[i]);
        }
        	Start start=new Start();//创建按钮
        	buttons.add(start);
        	start.pushed();//先生成一次
        	Answer answer = new Answer();//创建按钮
        	buttons.add(answer);
        	buttons.add(copyright,BorderLayout.SOUTH);
        	getContentPane().add(t,BorderLayout.NORTH);   //放到上方
            getContentPane().add(sudokus,BorderLayout.CENTER);   //放到中间
            getContentPane().add(number,BorderLayout.EAST);//放到右方
            getContentPane().add(buttons,BorderLayout.SOUTH);//放到下方
            setVisible(true);
            setSize(500,550);//设置大小
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//点X时结束进程
            setLocationRelativeTo(null);               //让窗体居中显示
        }

      public static void main(String[] args){

         GridFrame gl=new GridFrame("数独");//标题

         }
      public class Number extends JButton implements ActionListener {
    		int value;//对应的数字
    		Number(int i){
    			value=i;
    			this.setText(""+i);//显示数字
            	this.addActionListener(this);//监听器
    		}
    		
    		public void pushed(){
    			t.setText(""+value);//更换label中的数字
    		}

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO 自动生成的方法存根
				pushed();
			}
    	}
      public class Sudoku extends JButton implements ActionListener {
  		int value,canchange;//值、是否能改
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
  			int n=Integer.parseInt(t.getText());//读取label中的数字
  			if(n!=value)value=n;//改变value的值
  			else value=0;
  			for(int i=1;i<=9;i++)for(int j=1;j<=9;j++)if(btn[i][j].canchange==1&&btn[i][j].value!=0){
  				if(check(i,j))btn[i][j].setForeground(Color.BLUE);
  				else btn[i][j].setForeground(Color.RED);
  			}
  			if(value>0)this.setText(""+value);//显示value
  			else this.setText("");
  		}

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO 自动生成的方法存根
				if(canchange==1)pushed();
			}
  	}
      public class Start extends JButton implements ActionListener {
    	  Start(){
    		  this.setText("重新生成数独");
            	this.addActionListener(this);
    	  }
    	  public void solve(){
    		  OneThread t=new OneThread();
    		  t.start();
    		  try {
				t.join();
			} catch (InterruptedException e) {
				// TODO 自动生成的 catch 块
				e.printStackTrace();
			}
    	  }
    	  public void change(){
    		  FileInputStream fis = null;
    		  try {
    				fis = new FileInputStream("sudokuin.tsv");//读入文件
    			} catch (FileNotFoundException e1) {
    				// TODO 自动生成的 catch 块
    				e1.printStackTrace();
    			}
    			for(int i=1;i<=9;i++){//将生成的数独导入
    				for(int j=1;j<=9;j++){
    					try {
    						int n=fis.read();
    						while(n==9||n==10||n==13)n=fis.read();//过滤不是数字的内容
    						btn[i][j].value=n-'0';
    						fis.read();
    					} catch (IOException e1) {
    						// TODO 自动生成的 catch 块
    						e1.printStackTrace();
    					}
    					if(btn[i][j].value!=0)
    						{
    							btn[i][j].canchange=0;//初始化格子
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
					// TODO 自动生成的 catch 块
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
    	  				Runtime.getRuntime().exec("createfinal");//调用生成数独程序
    	  			} catch (IOException e) {
    	  				// TODO 自动生成的 catch 块
    	  				e.printStackTrace();
    	  			}
    		  }
    	  }
		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO 自动生成的方法存根
			pushed();
		}
    	  public class Level extends JFrame{
    		  public Level(){
    			  super("选择难度");
    			  Levels easy=new Levels("easy");
    			  Levels normal=new Levels("normal");
    			  Levels hard=new Levels("hard");
    			  JPanel hardlevels=new JPanel(new GridLayout(3,1,3,3));
    			  hardlevels.add(easy);
    			  hardlevels.add(normal);
    			  hardlevels.add(hard);
    	            getContentPane().add(hardlevels,BorderLayout.CENTER);
    	            setVisible(true);
    	            setSize(300,200);//设置大小
    	            setLocationRelativeTo(null);               //让窗体居中显示
    		  }
    		  public class Levels extends JButton implements ActionListener{
    			  String level;
    			  public Levels(String s){
    				  super(s);
    				  level=s;
    			  }
				@Override
				public void actionPerformed(ActionEvent arg0) {
					// TODO 自动生成的方法存根
					FileOutputStream fis = null;
					try {
						fis = new FileOutputStream("hardlevel.in");//从文件读入答案
					} catch (FileNotFoundException e1) {
						// TODO 自动生成的 catch 块
						e1.printStackTrace();
					}
					try {
						fis.write(level.getBytes());
					} catch (IOException e) {
						// TODO 自动生成的 catch 块
						e.printStackTrace();
					}
					try {
						fis.close();
					} catch (IOException e) {
						// TODO 自动生成的 catch 块
						e.printStackTrace();
					}
					this.setVisible(false);
				}
    			  
    		  }
    	  }
      }
      public class Answer extends JButton implements ActionListener {
    	  Answer(){
    		  this.setText("显示答案");
            	this.addActionListener(this);
    	  }
    	public void solve(){
    		OneThread t=new OneThread();
  		  t.start();
  		  try {
				t.join();
			} catch (InterruptedException e) {
				// TODO 自动生成的 catch 块
				e.printStackTrace();
			}
    	}
    	public class OneThread extends Thread{
  		  public void run(){
  			  try {
  	  				Runtime.getRuntime().exec("sudoku");//调用生成数独程序
  	  			} catch (IOException e) {
  	  				// TODO 自动生成的 catch 块
  	  				e.printStackTrace();
  	  			}
  		  }
  	  }
    	public void change(){
			FileInputStream fis = null;
			try {
				fis = new FileInputStream("sudokuout.tsv");//从文件读入答案
			} catch (FileNotFoundException e1) {
				// TODO 自动生成的 catch 块
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
						// TODO 自动生成的 catch 块
						e1.printStackTrace();
					}
					if(btn[i][j].canchange==1)btn[i][j].setForeground(Color.BLUE);
					btn[i][j].setText(""+btn[i][j].value);
				}
			}
    		try {
				fis.close();
			} catch (IOException e) {
				// TODO 自动生成的 catch 块
				e.printStackTrace();
			}
    	}
		public void actionPerformed(ActionEvent e) {
			// TODO 自动生成的方法存根
			solve();
			change();
		}
    	  
      }
} 

 