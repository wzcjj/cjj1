#include <iostream>
#include <map>
#include <string>

using namespace std;
struct ty{
    int i,j,k;
};
string ttt="\a";
char de[10000];int lde=0;
map <string,ty> d;
int lo=0;

string trans(int d,string a)
{
    char b[30];
    itoa(d,b,10);
    return string(b)+ttt+a;
}

void put(string a)
{
    for (int i=0;i<a.length();i++)
    {
        de[i+lde]=a[i];
    }
    lde+=a.length();
}

void put(char a)
{
    de[lde]=a;
    lde++;
}

void p(int i)
{
    char t[30],t4[30],t1;int t3;
    ty b;
    t1='{';
    printf("%d\n",i);
    while (t1!='}')
    {
        scanf("\"%[^\"]s\"",t);
        put("\""+string(t)+"\"");
        cin>>t1;
        printf("%c-- 1 \n",t1,t);
        cin>>t1;
        printf("%c-- 2 \n",t1,t);
        put(t1);
        //printf("%c--\n",t1);
        if (t1=='}') break;
        cin>>t1;
        put(t1);
        printf("%c-- %s \n",t1,t);
        printf("%s   d\n",de);
        if (t1=='"')
        {
            scanf("%[^\"]s\"",t4);
            cin>>t1;
            printf("%s 4\n",t4);
            b.i=lde-1;
            put(string(t4)+"\"");
            b.j=lde;
            b.k=0;
            d[trans(i,t)]=b;
             printf("%s 5\n",trans(i,t).c_str());
        }
        else
        {
            b.i=lde;
            b.k=lo;
            p(lo++);
            b.j=lde;
            d[trans(i,t)]=b;
             printf("%s 6\n",trans(i,t).c_str());
        }
        cin>>t1;
        put(t1);
    }
}

int main()
{
    de[20]='\0';
    int T,Q,b,b1;
    char t1[30],t2[30],t;
    ty u;
    bool f;
    scanf("%d\n",&T);
    for (int i=0;i<T;i++)
    {
        lo=0;
        lde=0;
        cin>>t;
        put(t);
        p(lo++);
        scanf("%d\n",&Q);
        for (int j=0;j<Q;j++)
        {
            cin>>t;
            b=0;
            b1=0;
            f=true;
            while (t!='\n' && t!='\r' && t!='~')  ///
            {
                if (t!='\"')
                    cin>>t;
                else 
                {
                     scanf("%[^\"]s\"",t1);
                     cin>>t;
                }
                if (d.find(trans(b,t1))!=d.end())
                {
                    u=d[trans(b,t1)];
                    b=b1;
                    b1=u.k;
                }
                else
                {
                    printf("Error!\n");
                    f=false;
                    break;
                }
            }
            if (f) {
               for (int k=u.i;k<u.j;k++)
               {
                    printf("%c",de[k]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
            
                    
        
            
        
