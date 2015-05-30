#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int i,j,m,n;
    string s;
    while(1)
    {
        cin>>s;
        if(s[0]=='0'&&s[2]=='0'&&s[3]=='0')break;
        if(s[0]=='0'&&s[2]=='5'&&s[3]=='0')
        {
            cout<<"1 card(s)"<<endl;
            continue;
        }
        float t=s[0]-'0'+(s[2]-'0')*0.1+(s[3]-'0')*0.01;
        float t1=0;
        for(i=1;;i++)
        {
            t1+=1.0/(i+1);
            if(t1>t)
            {
                cout<<i<<" card(s)"<<endl;
                break;
            }
        }
    }
    return 0;
}
