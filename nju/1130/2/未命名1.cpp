#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;
map< string,string > a;
map< char , string > b;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    string s;
    a["11000"]="0";
    a["00011"]="1";
    a["00101"]="2";
    a["00110"]="3";
    a["01001"]="4";
    a["01010"]="5";
    a["01100"]="6";
    a["10001"]="7";
    a["10010"]="8";
    a["10100"]="9";
    b['0']="11000";
    b['1']="00011";
    b['2']="00101";
    b['3']="00110";
    b['4']="01001";
    b['5']="01010";
    b['6']="01100";
    b['7']="10001";
    b['8']="10010";
    b['9']="10100";
    while( getline(cin,s) ){
        if(s.size()>20){
            string s1="";
            if(a.count(s.substr(0,5))==1)s1+=a[s.substr(0,5)];
            else{
                cout<<"error"<<endl;
                continue;
            }
            if(a.count(s.substr(6,5))==1)s1+=a[s.substr(6,5)];
            else{
                cout<<"error"<<endl;
                continue;
            }
            if(a.count(s.substr(12,5))==1)s1+=a[s.substr(12,5)];
            else{
                cout<<"error"<<endl;
                continue;
            }
            if(a.count(s.substr(18,5))==1)s1+=a[s.substr(18,5)];
            else{
                cout<<"error"<<endl;
                continue;
            }
            if(a.count(s.substr(24,5))==1)s1+=a[s.substr(24,5)];
            else{
                cout<<"error"<<endl;
                continue;
            }
            cout<<s1<<endl;
        }
        else{
            string s1="";
            for(int i=0;i<5;i++)s1+=b[s[i]]+" ";
            s1=s1.substr(0,s1.size()-1);
            cout<<s1<<endl;
        }
    }
    return 0;
}
             
