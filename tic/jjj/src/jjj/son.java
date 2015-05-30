package jjj;

public class son extends father {
	void abc(){
		System.out.println("def");
	}
	void def(){
		System.out.println("ghi");
	}
	public static void main(String[] args) {
		father afather = new son();
		afather.def();
	}
}
