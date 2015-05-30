#include <iostream> 
using namespace std; 
int gcd(int m,int n) 
{ 
    if(n == 0) 
        return m; 
    else return gcd(n,m%n); 
} 
class rational_number 
{ 
public:  
    void add(); 
    void sub(); 
    void mul(); 
    void div(); 
    bool less(); 
    int a,b,c,d; 
}; 
int main() 
{ 
    rational_number num; 
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
    while(cin >> num.a >> num.b >> num.c >> num.d) 
    { 
        num.add();  
        num.sub(); 
        num.mul(); 
        num.div(); 
        if(num.less()) 
            cout << "true";
		else cout << "false";
        cout << endl; 
    } 
    return 0; 
} 
void rational_number::add() 
{ 
    int p = a*d + b*c; 
    int q = b*d; 
    int p1 = p/gcd(p,q); 
    int q1 = q/gcd(p,q); 
    if(p1 < 0&&q1 > 0&&q1 != 1) 
        cout << p1 << "/" << q1 << " "; 
    else if(p1 < 0&&q1 > 0&&q1 == 1) 
        cout << p1 << " "; 
    else if(p1 < 0&&q1 < 0&&q1 != -1) 
        cout << -p1 << "/" << -q1 << " "; 
    else if(p1 < 0&&q1 < 0&&q1 == -1) 
        cout << -p1 << " "; 
    else if(p1 == 0) 
        cout << p1 << " "; 
    else if(p1 > 0&&q1 < 0&&q1 != -1) 
        cout << -p1 << "/" << -q1 << " "; 
    else if(p1 > 0&&q1 < 0&&q1 == -1) 
        cout << -p1 << " "; 
    else if(p1 > 0&&q1 > 0&&q1 != 1) 
        cout << p1 << "/" << q1 << " "; 
    else if(p1 > 0&&q1 > 0&&q1 == 1) 
        cout << p1 << " "; 
} 
void rational_number::sub() 
{ 
    int p = a*d - b*c; 
    int q = b*d; 
    int p1 = p/gcd(p,q); 
    int q1 = q/gcd(p,q); 
    if(p1 < 0&&q1 > 0&&q1 != 1) 
        cout << p1 << "/" << q1 << " "; 
    else if(p1 < 0&&q1 > 0&&q1 == 1) 
        cout << p1 << " "; 
    else if(p1 < 0&&q1 < 0&&q1 != -1) 
        cout << -p1 << "/" << -q1 << " "; 
    else if(p1 < 0&&q1 < 0&&q1 == -1) 
        cout << -p1 << " "; 
    else if(p1 == 0) 
        cout << p1 << " "; 
    else if(p1 > 0&&q1 < 0&&q1 != -1) 
        cout << -p1 << "/" << -q1 << " "; 
    else if(p1 > 0&&q1 < 0&&q1 == -1) 
        cout << -p1 << " "; 
    else if(p1 > 0&&q1 > 0&&q1 != 1) 
        cout << p1 << "/" << q1 << " "; 
    else if(p1 > 0&&q1 > 0&&q1 == 1) 
        cout << p1 << " "; 
} 
void rational_number::mul() 
{ 
    int p = a*c; 
    int q = b*d; 
    int p1 = p/gcd(p,q); 
    int q1 = q/gcd(p,q); 
    if(p1 < 0&&q1 > 0&&q1 != 1) 
        cout << p1 << "/" << q1 << " "; 
    else if(p1 < 0&&q1 > 0&&q1 == 1) 
        cout << p1 << " "; 
    else if(p1 < 0&&q1 < 0&&q1 != -1) 
        cout << -p1 << "/" << -q1 << " "; 
    else if(p1 < 0&&q1 < 0&&q1 == -1) 
        cout << -p1 << " "; 
    else if(p1 == 0) 
        cout << p1 << " "; 
    else if(p1 > 0&&q1 < 0&&q1 != -1) 
        cout << -p1 << "/" << -q1 << " "; 
    else if(p1 > 0&&q1 < 0&&q1 == -1) 
        cout << -p1 << " "; 
    else if(p1 > 0&&q1 > 0&&q1 != 1) 
        cout << p1 << "/" << q1 << " "; 
    else if(p1 > 0&&q1 > 0&&q1 == 1) 
        cout << p1 << " "; 
} 
void rational_number::div() 
{ 
    int p = a*d; 
    int q = b*c; 
    int p1 = p/gcd(p,q); 
    int q1 = q/gcd(p,q); 
    if(p1 < 0&&q1 > 0&&q1 != 1) 
        cout << p1 << "/" << q1 << " "; 
    else if(p1 < 0&&q1 > 0&&q1 == 1) 
        cout << p1 << " "; 
    else if(p1 < 0&&q1 < 0&&q1 != -1) 
        cout << -p1 << "/" << -q1 << " "; 
    else if(p1 < 0&&q1 < 0&&q1 == -1) 
        cout << -p1 << " "; 
    else if(p1 == 0) 
        cout << p1 << " "; 
    else if(p1 > 0&&q1 < 0&&q1 != -1) 
        cout << -p1 << "/" << -q1 << " "; 
    else if(p1 > 0&&q1 < 0&&q1 == -1) 
        cout << -p1 << " "; 
    else if(p1 > 0&&q1 > 0&&q1 != 1) 
        cout << p1 << "/" << q1 << " "; 
    else if(p1 > 0&&q1 > 0&&q1 == 1) 
        cout << p1 << " "; 
} 
bool rational_number::less() 
{ 
    int p = a*d - b*c; 
    int q = b*d; 
    if(p*q < 0) 
        return true; 
    else return false; 
} 
