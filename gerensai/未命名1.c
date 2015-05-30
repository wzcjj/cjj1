#include <stdio.h>

struct stutype{
	int number;
	char name[10];
	int score[5];
};
typedef struct stutype stud;


int main(){

	stud stu[10];
	int n=0;
	int i;

	FILE * infile1;
	FILE * infile2;
	FILE * outfile;

	infile1=fopen("test1.txt","r");
	outfile=fopen("test.txt","w");

	if(infile1!=NULL){
		while(fscanf(infile1,"%d %s %d %d %d %d %d",&stu[n].number,stu[n].name,&stu[n].score[0],&stu[n].score[1],&stu[n].score[2],&stu[n].score[3],&stu[n].score[4])!=EOF){
			n++;
		}
	}
	fclose(infile1);

	infile2=fopen("test2.txt","r");
	if(infile2!=NULL){
		while(fscanf(infile2,"%d %s %d %d %d %d %d",&stu[n].number,stu[n].name,&stu[n].score[0],&stu[n].score[1],&stu[n].score[2],&stu[n].score[3],&stu[n].score[4])!=EOF){
			n++;
	printf("%d %s %d %d %d %d %d\n",stu[n].number,stu[n].name,stu[n].score[0],stu[n].score[1],stu[n].score[2],stu[n].score[3],stu[n].score[4]);
		}
	}
	fclose(infile2);
	if(outfile!=NULL){
		for(i=0;i<n;i++) fprintf(outfile,"%d %s %d %d %d %d %d\n",stu[i].number,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4]);
	}
	return 0;
}
