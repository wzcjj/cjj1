int niyuan(int n,int a){
    int b1=0,b2=1,b3,q,r1,r2,r3;  
    r1=n;  
    r2=a;  
    q=r1/r2;  
    r3=r1%r2;  
    b3=b1-q*b2; 
    while(r3>1){ 
        r1=r2;   
        r2=r3;   
        b1=b2;   
        b2=b3;   
        q=r1/r2;   
        r3=r1%r2;   
        b3=b1-q*b2;   
    }   
    return (b3+n)%n;   
}
