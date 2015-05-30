package sudoku;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.Timer;
import java.util.TimerTask;
import javax.swing.*;

class GridFrame extends JFrame {
          JPanel sudokus=new JPanel(new GridLayout(3,3,3,3));//������壬������Ϊ���񲼾֣�3��3�У����ˮƽ����ֱ����Ϊ3
          JPanel number=new JPanel(new GridLayout(9,1,3,3));
          JPanel sudoku[][];
          JPanel buttons=new JPanel(new GridLayout(3,1,3,3));
          JPanel level=new JPanel(new GridLayout(1,3,3,3));
          JPanel ups=new JPanel(new GridLayout(1,3,3,3));
          JPanel upleft=new JPanel(new GridLayout(1,2,3,3));
          JPanel upright=new JPanel(new GridLayout(1,2,3,3));
          JLabel t=new JLabel("1",JLabel.CENTER);        //�����ı���
          JLabel copyright=new JLabel("All Copyright Reserved 2014 cjj,xy",JLabel.CENTER);
          JLabel stime=new JLabel("Time:",JLabel.RIGHT);
          JLabel time=new JLabel("0",JLabel.LEFT);
          JLabel sblank=new JLabel("Blanks:",JLabel.RIGHT);
          JLabel blank=new JLabel("",JLabel.LEFT);
          Sudoku btn[][];                             //������ť����
          Number button[];
          static int tim=0,bla;
          TimeTask tTask=new TimeTask();

          //�����ַ������飬Ϊ��ť����ʾ�ı���ֵ

         //ע���ַ�Ԫ�ص�˳����ѭ����Ӱ�ť����һ��

          public class TimeTask {   
  	         Timer timer = new Timer();
        	    
        	    public void timeVoid(){
        	        TimerTask tt=new TimerTask() { 
        	            @Override
        	            public void run() {
        	            	GridFrame.tim++;
        	            	time.setText(""+tim);
        	            }
        	        };
        	        timer.schedule(tt, 1000,1000);
        	    }
        	}
          public void setblanks(){
        	  int b=0;
        	  for(int i=1;i<=9;i++)for(int j=1;j<=9;j++)if(btn[i][j].value==0||btn[i][j].getForeground()==Color.green)b++;
        	  bla=b;
          	  blank.setText(""+bla);
          }

     public GridFrame(String s){
        super(s);  //Ϊ�������Ƹ�ֵ
        tTask.timeVoid();
        Font font= new Font("����",1,25);
        t.setFont(font);
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
        	Start easy=new Start("easy");//������ť
        	Start normal=new Start("normal");//������ť
        	Start hard=new Start("hard");//������ť
        	level.add(easy);
        	level.add(normal);
        	level.add(hard);
        	buttons.add(level);
        	normal.pushed();//������һ��
        	Answer answer = new Answer();//������ť
        	buttons.add(answer);
        	buttons.add(copyright,BorderLayout.SOUTH);
        	upleft.add(stime);
        	upleft.add(time);
        	upright.add(sblank);
        	upright.add(blank);
        	ups.add(upleft);
        	ups.add(t);
        	ups.add(upright);
        	getContentPane().add(ups,BorderLayout.NORTH);   //�ŵ��Ϸ�
            getContentPane().add(sudokus,BorderLayout.CENTER);   //�ŵ��м�
            getContentPane().add(number,BorderLayout.EAST);//�ŵ��ҷ�
            getContentPane().add(buttons,BorderLayout.SOUTH);//�ŵ��·�
            setVisible(true);
            setSize(500,570);//���ô�С
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
      public class Sudoku extends JButton implements ActionListener,MouseListener{
  		int value,canchange;//ֵ���Ƿ��ܸ�
  		Sudoku(){
  			value=0;
  			canchange=1;
  			this.setText("");//��ʼΪ��
  			this.addMouseListener(this);
          	this.addActionListener(this);
  		}
  		public boolean check(int x,int y){//�ж��Ƿ����
  			for(int i=1;i<=9;i++)if(x!=i&&btn[i][y].value==btn[x][y].value||y!=i&&btn[x][i].value==btn[x][y].value)return false;
  			for(int i=(x-1)/3*3+1;i<=(x-1)/3*3+3;i++)for(int j=(y-1)/3*3+1;j<=(y-1)/3*3+3;j++)if(i!=x&&j!=y){
  				if(btn[i][j].value==btn[x][y].value)return false;
  			}
  			return true;
  		}
  		public void pushed(){
  			int n=Integer.parseInt(t.getText());//��ȡlabel�е�����
  			if(n!=value||this.getForeground()==Color.green)value=n;//�ı�value��ֵ
  			else value=0;
  			this.setForeground(Color.BLUE);
  			for(int i=1;i<=9;i++)for(int j=1;j<=9;j++)if(btn[i][j].canchange==1&&btn[i][j].value!=0){//�ı���ɫ
  				if(check(i,j)){
  					if(btn[i][j].getForeground()!=Color.green)btn[i][j].setForeground(Color.BLUE);
  				}
  				else btn[i][j].setForeground(Color.RED);
  			}
  			if(value>0)this.setText(""+value);//��ʾvalue
  			else this.setText("");
  			setblanks();
  		}

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO �Զ����ɵķ������
				if(canchange==1)pushed();
			}
			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO �Զ����ɵķ������
				int n=Integer.parseInt(t.getText());//��ȡlabel�е�����
				if (e.getButton() == MouseEvent.BUTTON3)if(canchange==1){//�Ҽ��������Ϊ��ɫ
					if(this.getForeground()==Color.green&&this.getText()!=""&&Integer.parseInt(this.getText())==n){
						this.setText("");
						value=0;
					}
					else{
						value=n;
						this.setText(""+n);
						this.setForeground(Color.green);
					}
		  			for(int i=1;i<=9;i++)for(int j=1;j<=9;j++)if(btn[i][j].canchange==1&&btn[i][j].value!=0){//�ж��Ƿ����
		  				if(check(i,j)){
		  					if(!(btn[i][j].getForeground()==Color.green))btn[i][j].setForeground(Color.BLUE);
		  				}
		  				else btn[i][j].setForeground(Color.RED);
		  			}
				}
	  			setblanks();
			}
			@Override
			public void mouseEntered(MouseEvent e) {
				// TODO �Զ����ɵķ������
				
			}
			@Override
			public void mouseExited(MouseEvent e) {
				// TODO �Զ����ɵķ������
				
			}
			@Override
			public void mousePressed(MouseEvent e) {
				// TODO �Զ����ɵķ������
				
			}
			@Override
			public void mouseReleased(MouseEvent e) {
				// TODO �Զ����ɵķ������
				
			}
  	}
      public class Start extends JButton implements ActionListener {
    	  String value;
    	  Start(String s){
    		  this.setText(s);
    		  value=s;
            	this.addActionListener(this);
    	  }
    	  void pushed(){
    		  FileInputStream fis = null;
    		  FileOutputStream fou =null;
    		  try {
				fou=new FileOutputStream("hardlevel.in");
				try {
					fou.write(value.getBytes());//�����Ѷ�ֵ
				} catch (IOException e) {
					// TODO �Զ����ɵ� catch ��
					e.printStackTrace();
				}
			} catch (FileNotFoundException e2) {
				// TODO �Զ����ɵ� catch ��
				e2.printStackTrace();
			}
    		  try {
				try {
					Runtime.getRuntime().exec("create3test32").waitFor();//����������������
				} catch (InterruptedException e) {
					// TODO �Զ����ɵ� catch ��
					e.printStackTrace();
				}
			} catch (IOException e) {
				// TODO �Զ����ɵ� catch ��
				e.printStackTrace();
			}
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
        	setblanks();
    	  }
		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO �Զ����ɵķ������
			pushed();
			tim=0;
        	time.setText(""+tim);
		}
    	  
      }
      public class Answer extends JButton implements ActionListener {
    	  Answer(){
    		  this.setText("��ʾ��");
            	this.addActionListener(this);
    	  }
    	public void solve(){
			try {
				try {
					Runtime.getRuntime().exec("sudoku").waitFor();//���ý���������
				} catch (InterruptedException e) {
					// TODO �Զ����ɵ� catch ��
					e.printStackTrace();
				}
			} catch (IOException e2) {
				// TODO �Զ����ɵ� catch ��
				e2.printStackTrace();
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
    		
    	}
		public void actionPerformed(ActionEvent e) {
			// TODO �Զ����ɵķ������
			solve();
			change();
			setblanks();
		}
    	  
      }
} 

 