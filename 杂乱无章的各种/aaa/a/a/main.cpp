#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;
char s[100]="nbqfrsmxzfyawjufhwffeskgqcfwdqafnbqftilofcwp";
double a[30];
int main(){
    //cout<<log(exp(1))<<endl;
    a[1]=1.27;
    a[2]=2.16;
    a[3]=2.86;
    a[4]=3.44;
    a[5]=3.87;
    a[6]=4.15;
    a[7]=4.37;
    a[8]=4.51;
    a[9]=4.58;
    a[10]=4.62;
    a[11]=4.64;
    double ans=0,ans2=0,ans3=0,ans4=0;
    for(int i=1;i<=11;i++){
        a[i]=log(a[i]);
        ans+=a[i];
        ans2+=1.0/i;
        ans3+=1.0/i/i;
        ans4+=a[i]/i;
    }
    printf("%.6lf\n",ans);
    printf("%.6lf\n",ans2);
    printf("%.6lf\n",ans3);
    printf("%.6lf\n",ans4);
    //cout<<ans<<endl;
    //cout<<ans2<<endl;
    //printf("%lf\n",3000*(45+46/(10.1+46)*15)+2000*(60+27/(10.1+27)*10)+4000*(20+27/(10.1+27)*5));
    //int ans=1;
    /*for(int i=1;i<=62;i++){
        int cnt=1;
        for(int j=1;j<=31;j++)cnt=cnt*i%63;
        printf("%d %d\n",i, cnt);
    }*/
    //cout<<ans<<endl;
    //gets(s);
    //s="nbqfrsmxzf yawjufhwff eskgqcfwdq afnbqftilo fcwp";
    /*int n = strlen(s);
    for(int i=0;i<n;i++){
        if(s[i]>='a'&&s[i]<='z')a[s[i]-'a']++;
    }
    for(int i=0;i<26;i++)printf("%d ",a[i]);
    char s1[100] = "abcdefghijklmnopqrstuvwxyz";
    char s2[100] = "hbcdeeghijklmnoparstuvtxyz";
    for(int j=1;j<26;j++){
        for(int i=0;i<n;i++){
            if(s[i]>='a'&&s[i]<='z'){
                //if(s[i]=='a')s[i]+=26;
                s[i]--;
                if(s[i]<'a')s[i]+=26;
            }
        }
        printf("%s\n",s);
    }*/
    /*srand(unsigned (time(0)));
    double a[10];
    memset(a,0,sizeof(a));
    long long sum=0;
    for(int I=1;I<=100;I++){
        int t = rand()%(int)pow(10,6);
        double now = 1;
        double po = (rand()%1000+1)/1000.0+1;
        while(now<t){
            long long s = (int) now;
            int j=0;
            while(s){
                j=s%10;
                s/=10;
            }
            a[j]++;
            sum++;
            now*=po;
        }
    }
    for(int i=1;i<=9;i++)cout<<a[i]/sum<<endl;*/
    return 0;
}