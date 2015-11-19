class Number{
public:
    Number(long long x = 0){
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
        return y < x;
    }
    friend bool operator>=(Number x,Number y){
        return !(x < y);
    }
    friend bool operator<=(Number x,Number y){
        return !(y < x);
    }
    friend bool operator==(Number x,Number y){
        return !(y < x) && !(x < y);
    }
    friend bool operator!=(Number x,Number y){
        return (x < y) || (y < x);
    }
    friend ostream& operator<<(ostream& out,Number t){
        if(t.neg)out << "-";
        out << t.x;
        if(t.y > 1)out << "/" << t.y;
        return out;
    }
    friend istream& operator>>(istream& in,Number& t){
        int m;
        in >> m;
        Number s(m);
        t = s;
        return in;
    }
private:
    long long x,y;
    bool neg;
    
    long long gcd(long long x,long long y){
        if(x < y){
            long long t = x;
            x = y;
            y = t;
        }
        if(y == 0)return x;
        else return gcd(y , x % y);
    }
    Number add(Number b){
        Number t;
        t.y = this->y * b.y;
        t.x = getneg(this->neg) * this->x * b.y + getneg(b.neg) * b.x * this->y;
        if(t.x < 0){
            t.x = -t.x;
            t.neg = true;
        }
        else t.neg = false;
        long long k = gcd(t.x, t.y);
        t.x /= k;
        t.y /= k;
        return t;
    }
    
    Number sub(Number b){
        Number t;
        t.y = this->y * b.y;
        t.x = getneg(this->neg) * this->x * b.y - getneg(b.neg) * b.x * this->y;
        if(t.x < 0){
            t.x = -t.x;
            t.neg = true;
        }
        else t.neg = false;
        long long k = gcd(t.x, t.y);
        t.x /= k;
        t.y /= k;
        return t;
    }
    
    Number mul(Number b){
        Number t;
        t.y = this->y * b.y;
        t.x = this->x * b.x;
        t.neg = this->neg ^ b.neg;
        long long k = gcd(t.x, t.y);
        t.x /= k;
        t.y /= k;
        if(t.x == 0)t.neg = false;
        return t;
    }
    
    Number div(Number b){
        Number t;
        t.y = this->y * b.x;
        t.x = this->x * b.y;
        t.neg = this->neg ^ b.neg;
        long long k = gcd(t.x, t.y);
        t.x /= k;
        t.y /= k;
        if(t.x == 0)t.neg = false;
        return t;
    }
    
    bool less(Number b){
        long long l = this->x * b.y;
        long long r = this->y * b.x;
        if(this->neg && b.neg)return l > r;
        else if(this->neg && !b.neg)return true;
        else if(!this->neg && b.neg)return false;
        else return l < r;
    }
    
    void output(){
        if(this->neg)cout << '-';
        cout << this->x;
        if(this->y>1)cout << '/' << this->y;
    }
    
    int getneg(bool t){
        if(t)return -1;
        else return 1;
    }
};