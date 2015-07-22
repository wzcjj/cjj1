#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<set>
#include<vector>
#include<utility> 
using namespace std;
struct node{
    int x,y;
    friend bool operator <(node x,node y){
        return x.x*x.x+x.y*x.y<y.x*y.x+y.y*y.y;
    }
};
struct node1{
    int x,y;
    friend bool operator <(node1 x,node1 y){
        return x.x*x.x+x.y*x.y>y.x*y.x+y.y*y.y;
    }
};
node heap[100000];
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
    heap[++heap[0].x]=x;
    int i=heap[0].x;
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
    heap[1]=heap[heap[0].x--];
    int i=1;
    while(i*2<=heap[0].x){
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
pair< vector<int>,vector<int> > get_input(){
    int x,y;
    scanf("%d%d",&x,&y);
    pair< vector<int>,vector<int> > p;
    while(true){
        if(x==0&&y==0){
            return p;
        }
        else{
            p.first.push_back(x);
            p.second.push_back(y);
        }
        scanf("%d%d",&x,&y);
    }
}
void heap_sort(pair< vector<int>,vector<int> > p){
    heap[0].x=0;
    for(int i=0;i<p.first.size();i++){
        node t;
        t.x=p.first[i];
        t.y=p.second[i];
        push(t);
    }
    while(heap[0].x){
        node t=top();
        printf("%d",t.x*t.x+t.y*t.y);
        pop();
        if(heap[0].x)printf(" ");
    }
    printf("\n");
}
void priority_queue_sort(pair< vector<int>,vector<int> > p){
    priority_queue< node1 > q;
    for(int i=0;i<p.first.size();i++){
        node1 t;
        t.x=p.first[i];
        t.y=p.second[i];
        q.push(t);
    }
    while(!q.empty()){
        node1 t=q.top();
        printf("%d",t.x*t.x+t.y*t.y);
        q.pop();
        if(!q.empty())printf(" ");
    }
    printf("\n");
}
void set_sort(pair< vector<int>,vector<int> > p){
    multiset<node> s;
    for(int i=0;i<p.first.size();i++){
        node t;
        t.x=p.first[i];
        t.y=p.second[i];
        s.insert(t);
    }
    for(multiset<node>::iterator i=s.begin();i!=s.end();i++){
        printf("%d",(*i).x*(*i).x+(*i).y*(*i).y);
        multiset<node>::iterator j=i;
        j++;
        if(j!=s.end())printf(" ");
    }
}
int main(int argc, char *argv[]) {

    pair< vector<int>,vector<int> > p;

    p=get_input();

    heap_sort(p);

    priority_queue_sort(p);

    set_sort(p);

}
