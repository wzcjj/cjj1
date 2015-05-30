package jjj;

public abstract class Student {
	private String name;
	private int score;
	public Student(String s,int sc){
		name=s;
		score=sc;
	}
	String getName(){
		return name;
	}
	int getScore(){
		return score;
	}
}
