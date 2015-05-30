#include<cstdio>
#include<iostream>
using namespace std;
int gcd(int x,int y){
    if(x<y){
        int t = x;
        x = y;
        y = t;
    }
    if(y==0)return x;
    else return gcd(y , x % y );
}
class Number{
    public:
        Number(int x=1);
        Number add(Number b);
        Number sub(Number b);
        Number mul(Number b);
        Number div(Number b);
        bool less(Number b);
        void output();
    private:
        int x,y;
        bool neg;
        int getneg(bool t);
}; 
int main(){
    int a,b,c,d;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    while(cin>>a>>b>>c>>d){
        Number  numA(a),// = new Number(a) , 
                numB(b),// = new Number(b) , 
                numC(c),// = new Number(c) , 
                numD(d);// = new Number(d) ;
        Number adivb = numA.div(numB) , cdivd = numC.div(numD);
        //adivb.output();
        //cdivd.output();
        Number first = adivb.add(cdivd);
        first.output();
        //delete first;
        Number second = adivb.sub(cdivd);
        second.output();
        //delete second;
        Number third = adivb.mul(cdivd);
        third.output();
        //delete third;
        Number forth = adivb.div(cdivd);
        forth.output();
        //delete forth;
        bool t = adivb.less(cdivd);
        if(t)cout<<"true"<<endl;
        else cout<<"false"<<endl;
        //delete numA , numB , numC , numD , adivb , cdivd;
    }
    return 0;
}
Number::Number(int x){
    if(x<0){
        neg = true;
        this->x = -x;
        y = 1;
    }
    else {
        neg = false;
        this->x = x;
        y = 1;
    }
}

Number Number::add(Number b){
    Number t;
    t.y = this->y * b.y;
    t.x = getneg(this->neg) * this->x * b.y + getneg(b.neg) * b.x * this->y;
    if(t.x < 0){
        t.x = -t.x;
        t.neg = true;
    }
    else t.neg = false;
    int k = gcd(t.x , t.y);
    t.x /= k;
    t.y /= k;
    return t;
}

Number Number::sub(Number b){
    Number t;
    t.y = this->y * b.y;
    t.x = getneg(this->neg) * this->x * b.y - getneg(b.neg) * b.x * this->y;
    if(t.x < 0){
        t.x = -t.x;
        t.neg = true;
    }
    else t.neg = false;
    int k = gcd(t.x , t.y);
    t.x /= k;
    t.y /= k;
    return t;
}

Number Number::mul(Number b){
    Number t;
    t.y = this->y * b.y;
    t.x = this->x * b.x;
    t.neg = this->neg ^ b.neg;
    int k = gcd(t.x , t.y);
    t.x /= k;
    t.y /= k;
    return t;
}

Number Number::div(Number b){
    Number t;
    t.y = this->y * b.x;
    t.x = this->x * b.y;
    t.neg = this->neg ^ b.neg;
    int k = gcd(t.x , t.y);
    t.x /= k;
    t.y /= k;
    return t;
}

bool Number::less(Number b){
    int l = this->x * b.y;
    int r = this->y * b.x;
    if(this->neg && b.neg)return l > r;
    else if(this->neg && !b.neg)return true;
    else if(!this->neg && b.neg)return false;
    else return l < r;
}

void Number::output(){
    if(this->neg)printf("-");
    printf("%d", this->x);
    if(y>1)printf("/%d ", this->y);
    else printf(" ");
}

int Number::getneg(bool t){
    if(t)return -1;
    else return 1;
}
