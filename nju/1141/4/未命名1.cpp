#include<cstdio>
struct node{
    int v,i,now;
    friend bool operator <(node x,node y){
        return x.v<y.v;
    }
}heap[100000];
int a[3000005],l[100000],r[100000],b[3000005];
void swap(int &x,int &y){
    int t=x;
    x=y;
    y=t;
}
void swap(node &x,node &y){
    node t=x;
    x=y;
    y=t;
}
void push(node x){
    heap[++heap[0].v]=x;
    int i=heap[0].v;
    while(i>1){
        if(heap[i]<heap[i/2])swap(heap[i],heap[i/2]);
        else break;
        i/=2;
    }
}
node top(){
    return heap[1];
}
void pop(){
    heap[1]=heap[heap[0].v--];
    int i=1;
    while(i*2<=heap[0].v){
        if(heap[i*2]<heap[i*2+1]){
            if(heap[i*2]<heap[i])swap(heap[i],heap[i*2]);
            else break;
            i*=2;
        }
        else{
            if(heap[i*2+1]<heap[i])swap(heap[i],heap[i*2+1]);
            else break;
            i=2*i+1;
        }
    }
}
int main(){
    int i,j,m,n;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    n=0;
    while(scanf("%d",&m)!=EOF)a[++n]=m;
    m=l[1]=1;
    for(i=1;i<n;i++)if(a[i]>a[i+1]){
        r[m++]=i;
        l[m]=i+1;
    }
    r[m]=n;
    heap[0].v=0;
    for(i=1;i<=m;i++){
        node t;
        t.v=a[l[i]];
        t.i=i;
        t.now=l[i];
        push(t);
    }
    for(i=1;i<=n;i++){
        node t=top(); 
        b[i]=t.v;
        pop();
        if(t.now<r[t.i]){
            node s;
            s.v=a[t.now+1];
            s.i=t.i;
            s.now=t.now+1;
            push(s);
        }
    }
    for(i=1;i<n;i++)printf("%d ",b[i]);
    printf("%d\n",b[n]);
    return 0;
}
        
 
