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
        friend Number operator+(Number x,Number y){
            return x.add(y);
        } 
        friend Number operator-(Number x,Number y){
            return x.sub(y);
        } 
        friend Number operator*(Number x,Number y){
            return x.mul(y);
        } 
        friend Number operator/(Number x,Number y){
            return x.div(y);
        } 
        friend bool operator<(Number x,Number y){
            return x.less(y);
        } 
        friend bool operator>(Number x,Number y){
            return y<x;
        } 
        friend bool operator>=(Number x,Number y){
            return !(x<y);
        } 
        friend bool operator<=(Number x,Number y){
            return !(y<x);
        } 
        friend bool operator==(Number x,Number y){
            return !(y<x)&&!(x<y);
        } 
        friend ostream& operator<<(ostream& out,Number t){
            if(t.neg)out<<"-";
            out<<t.x;
            if(t.y>1)out<<"/"<<t.y;
            return out;
        }
        friend istream& operator>>(istream& in,Number& t){
            int m;
            in>>m;
            Number s(m);
            t=s;
            return in;
        }
    private:
        Number add(Number b);
        Number sub(Number b);
        Number mul(Number b);
        Number div(Number b);
        bool less(Number b);
        int x,y;
        bool neg;
        int getneg(bool t);
        void output();
}; 
int main(){
    int a,b,c,d;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    Number numA,numB,numC,numD;
    while(cin>>numA>>numB>>numC>>numD){
        //Number  numA(a),// = new Number(a) , 
        //        numB(b),// = new Number(b) , 
        //        numC(c),// = new Number(c) , 
        //        numD(d);// = new Number(d) ;
        Number adivb = numA/numB , cdivd = numC/numD;
        //adivb.output();
        //cdivd.output();
        Number first = adivb+cdivd;
        cout<<first<<' ';
        //delete first;
        Number second = adivb-cdivd;
        cout<<second<<' ';
        //delete second;
        Number third = adivb*cdivd;
        cout<<third<<' ';
        //delete third;
        Number forth = adivb/cdivd;
        cout<<forth<<' ';
        //delete forth;
        bool t = adivb<cdivd;
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
    if(this->y>1)printf("/%d ", this->y);
    else printf(" ");
}

int Number::getneg(bool t){
    if(t)return -1;
    else return 1;
}
