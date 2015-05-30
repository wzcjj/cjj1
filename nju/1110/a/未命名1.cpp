#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s[10];
    int i;
    for(i=1;i<=7;i++)cin>>s[i];
    cout<<"Dear Instructor "<<s[1]<<",\nI am sorry that I am unable to turn in my homework at this time. First, I ate a rotten "<<s[3]<<", which made me turn "<<s[6]<<" and extremely ill. I came down with a fever of "<<s[4]<<". Next, my "<<s[5]<<" pet "<<s[7]<<" must have smelled the remains of the "<<s[3]<<" on my homework, because he ate it. I am currently rewriting my homework and hope you will accept it late.\nSincerely,\n"<<s[2]<<endl;
    system("pause"); 
    return 0;
}
