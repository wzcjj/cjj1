import java.util.ArrayList;


class Testi
{
	public int i;
}

class Thread1 implements Runnable
	{
		ArrayList<Integer> list;
		public Thread1(ArrayList<Integer> list)
		{
			this.list = list;
		}
		@Override
		public void run()
		{
			while (true)
			{
				synchronized (list)
				{
					if (list.size() == 0)
						break;
					int i = list.get(0);
					System.out.println("Thread1 " + i);
					list.remove(0);
				}
			}
		}
		
	}

	class Thread3 implements Runnable
	{
		ArrayList<Integer> list;
		public Thread3(ArrayList<Integer> list)
		{
			this.list = list;
		}
		@Override
		public void run()
		{
			while (true)
			{
				synchronized (list)
				{
					if (list.size() == 0)
						break;
					int i = list.get(0);
					System.out.println("Thread2 " + i);
					list.remove(0);
				}
			}
		}
		
	}
	
public class Test
{
	
	
	public static void main(String args[])
	{
		ArrayList<Integer> list = new ArrayList<Integer>();
		for (int i = 0; i < 500; i ++)
		{
			list.add(i);
		}
		Thread t1 = new Thread(new Thread1(list));
		Thread t3 = new Thread(new Thread3(list));
		t1.start();
		t3.start();
	}
}
