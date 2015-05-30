#include <iostream> 
#include <string> 
 
#include <stdio.h>  
using namespace std;
 
class code
{
public:
    void input();
    void decide();
    void outputzip();
    void outputbar();
    bool trans(string q);
    bool count(char m[5][5]);
    bool inter(string str);
    char b[10000];
 
 
private:
     
    string a;
    char p[5][5];
    int outp[5];
};
int main()
{
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
    code ans;
    while(gets(ans.b))
    {
        ans.input();
        ans.decide();
    }
    return 0;
}
void code::input()
{
     
     
    a=b;
}
void code::decide()
{
    if (trans(a))
    {
        outputbar();
    }
    else
    {
        outputzip();
    }
}
bool code::inter(string str)
{
    int i;
     
     
    for (i=0;i<5;i++)
    {
         
        if ((str[i]!='0')&&(str[i]!='1')&&(str[i]!='2')&&(str[i]!='3')&&(str[i]!='4')&&(str[i]!='5')&&(str[i]!='6')&&(str[i]!='7')&&(str[i]!='8')&&(str[i]!='9'))
        {
            return false;
        }
    }
    return true;
}
bool code::trans(string q)
{
    int siz=q.size();
    if (siz==5)
    {
        if (inter(q))
        {
           return false;
        }
        else return true;
    }
 
 
    else
        return true;
}
bool code::count(char m[5][5])
{
    int co,cl; 
    for (int i=0;i<5;i++) 
    { 
        co=0;
        cl=0;
        for (int s=0;s<5;s++) 
        { 
            if (m[i][s]=='1') 
            { 
                cl++; 
            }
            else if(m[i][s]=='0')
            {
                co++;
            } 
        }
        if ((co!=3)||(cl!=2))
        {
            return false; 
        }
    }
  
    return true; 
}
void code::outputzip()
{
    for (int i=0;i<5;i++) 
            { 
                if(a[i]=='9') 
                { 
                    cout<<"10100"; 
                }
                else if(a[i]=='8') 
                { 
                    cout<<"10010"; 
                } 
                else if(a[i]=='7') 
                { 
                    cout<<"10001"; 
                } 
                else if(a[i]=='6') 
                { 
                    cout<<"01100"; 
                } 
                else if(a[i]=='5') 
                { 
                    cout<<"01010"; 
                } 
                
                else if(a[i]=='4') 
                { 
                    cout<<"01001"; 
                } 
                else if(a[i]=='3') 
                { 
                    cout<<"00110"; 
                } 
                else if(a[i]=='2') 
                { 
                    cout<<"00101"; 
                } 
                else if(a[i]=='1') 
                { 
                    cout<<"00011"; 
                } 
                 
                 
                 
                else if(a[i]=='0') 
                { 
                    cout<<"11000"; 
                } 
                if (i!=4) 
                { 
                    cout<<" "; 
                } 
                else
                { 
                    cout<<endl; 
                } 
            } 
}
void code::outputbar()
{
     
        for (int i=0;i<5;i++) 
        { 
               
            outp[i]=0; 
            for (int j=0;j<5;j++) 
            { 
                p[i][j]=a[i*6+j]; 
            } 
           
        } 
           
        if (count(p)) 
        { 
            int j; 
            for (j=0;j<5;j++) 
            { 
                if (p[j][0]=='1') 
                { 
                    outp[j]=outp[j]+7; 
                } 
                if (p[j][1]=='1') 
                { 
                    outp[j]=outp[j]+4; 
                } 
                if(p[j][2]=='1') 
                { 
                    outp[j]+=2; 
                } 
                if(p[j][3]=='1') 
                { 
                    outp[j]+=1; 
                } 
                if (outp[j]==11) 
                { 
                    outp[j]=0; 
                } 
            } 
            for (j=0;j<5;j++) 
            { 
                cout<<outp[j]; 
            } 
            cout<<endl; 
               
        } 
        else
        { 
            cout<<"error"<<endl; 
        } 
}
 

