#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <map>
#include <cstring>

#define MAX
#define INF
#define MOD
#define MP make_pair
#define AA first
#define BB second
#define IS(X) cout << #X << " = " << X << endl;
#define PI 3.14159265
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef vector<int> VI;
typedef queue<int> QI;
typedef priority_queue<int> PQI;
template <typename T>
class AVL {
public:
    class node {
    public:
        node *l,*r;
        int h,size;
        T dat;
        node() : l(0) ,r(0), h(1),size(0) {};
        node(T tdat) : dat(tdat),l(0),r(0), h(1),size(1) {};
        int geth() {
            if(!this) return 0;
            else return h;
        }
        int getsize() {
            if(!this) return 0;
            else return size;
        }
        void update() {
            if(this) {
                h = max(l->geth() ,r->geth()) + 1;
                size = l->getsize() + r->getsize() + 1;
            }
        }
    }*root;
    void Lrotate(node * &p) {
        node * t = p->r->l;
        p->r->l = p;
        p= p->r;
        p->l->r =t;
        p->l->update();
        p->update();
    }
    void Rrotate(node * &p) {
        node * t = p->l->r;
        p->l->r = p;
        p= p->l;
        p->r->l = t;
        p->r->update();
        p->update();
    }
    void maintain(node * &p) {
        int lh ,rh;
        if(p->l->geth() > p->r->geth() + 1) { // To balance the left tree
            lh = p->l->l->geth();
            rh = p->l->r->geth();
            if(lh >= rh)
                Rrotate(p);
            else {
                Lrotate(p->l);
                Rrotate(p);
            }
        }
        if(p->r->geth() > p->l->geth() + 1 ) { // To balance the right tree
            lh = p->r->l->geth();
            rh = p->r->r->geth();
            if(rh >= lh)
                Lrotate(p);
            else {
                Rrotate(p->r);
                Lrotate(p);
            }
        }
    }
    void insert(node  * & p, T dat) {
        if(!p) {
            p = new node(dat);
            return;
        }
        if(dat <= p->dat)
            insert(p->l,dat);
        else
            insert(p->r,dat);
        maintain(p);
        p->update();
    }
    void erase(node * & p, T dat) {
        if(!p) return;
        if(p ->dat == dat) {
            if(p->l && p->r) {
                node * t = p->r;
                while(t->l)
                    t = t->l;
                p->dat = t->dat;
                erase(p->r,t->dat);
                maintain(p);
            } else if(p->l) {
                p->dat = p->l->dat;
                p->l = 0;
            } else if(p->r) {
                p->dat = p->r->dat;
                p->r = 0;
            } else p = 0;
            p->update();
            return;
        } else if(dat < p->dat)
            erase(p->l,dat);
        else
            erase(p->r,dat);
        maintain(p);
        p->update();
    }
    T findk(node * p, int k) {
        if(k == p->l->getsize() + 1)
            return p->dat;
        else if(k <= p->l->getsize())
            return findk(p->l,k);
        else if(k > p->getsize() - p->r-> getsize())
            return findk(p->r, k- p->getsize() + p->r->getsize());
    }
    int finddat(node* p, T dat) {
        if(!p) return 0;
        if(dat < p->dat) {
            if(!p->l) {
                if (p->dat <= root->dat)
                    return p->getsize() - p->r->getsize() - 1;
                else
                    return root->getsize() - p->r->getsize();
            }
            finddat(p->l,dat);
        } else if(dat > p->dat) {
            if(!p->r) {
                // if(dat == 2) {IS(p->getsize());IS(p->r->getsize());}
                if (p->dat <= root->dat)
                    return p->getsize() - p->r->getsize();
                else
                    return root->getsize() - p->getsize() + 1 + p->l->getsize();
            }
            finddat(p->r,dat);
        } else if(dat == p->dat) {
            if(p->dat <= root->dat) {
                return p->getsize() - p->r->getsize();
            } else {
                return root->getsize() - p->r->getsize();
            }
        }
        return 0;
    }
public:
    AVL() : root(0) {};
    void init() {
        root = new node(0);
    }
    void insert(T dat) {
        insert(root, dat);
    }
    void erase(T dat) {
        erase(root, dat);
    }
    T findk(int k) {
        if( k <= 0) return -1;
        return findk(root, k);
    }
    void clear(node * p) {
        if(!p)
            return;
        clear(p->l);
        clear(p->r);
        delete p;
    }
    bool empty() {
        return (root->getsize() == 0);
    }
    int size() {
        return root->getsize();
    }
    node* getroot() {
        return root;
    }
    void print(node* p) {
        if(!p) return;
        cout << p->dat << endl;
        if(p->l) print(p->l);
        if(p->r) print(p->r);
    }
    int finddat(T dat) {
        return finddat(root,dat);
    }
};
LL n,k;
LL num[100005];
AVL<LL> tree;
struct E{
    int u,v,next;
}e[100005];
int cnte;
int head[100005];
bool flag[100005];
LL ans;
void adde(int u,int v) {
    e[cnte].u = u;e[cnte].v = v;
    e[cnte].next = head[u];head[u] = cnte++;
}
void dfs(int x,int fa) {
    ans += tree.finddat(k/num[x]);
    //IS(ans);IS(x);IS(k/num[x]);tree.print(tree.root);puts("");
    tree.insert(num[x]);
    for(int i = head[x];i != -1;i = e[i].next) {
        dfs(e[i].v,x);
    }
    tree.erase(num[x]);
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;cin >> t;
    while(t--) {
        //IS(tree.size());
        cin >> n >> k;
        cnte = 0;
        memset(head,-1,sizeof head);
        memset(flag,0,sizeof flag);
        for(int i = 1;i <= n;i++) scanf("%lld",&num[i]);
        for(int i = 1;i < n;i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            adde(x,y);flag[y] = 1;
        }
        ans = 0;
        for(int i = 1;i <= n;i++) if(!flag[i]) {dfs(i,-1);break;}
        cout << ans << endl;
    }
    return 0;
}
/*
 6
 5 100 1 2 3 4 5 1 2 1 3 2 4 2 5
 5 5 1 2 3 4 5 1 2 1 3 2 4 2 5
 7 10 1 2 3 4 5 6 7 1 2 1 3 2 4 2 5 3 6 3 7
 2 1 1 1 1 2
 4 4 2 2 1 4 1 2 2 3 3 4
 3 2 2 2 1 1 2 2 3
 
 */
