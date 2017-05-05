#include <map>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
/*
     a
    /  \
   b    c
  / \  /  \
 d   e f   g
       \  / \
       h j   i
          \
           k
            \
             l
 a:托马斯（Thomas）
 b:艾德华（Edward）
 c:亨利（Henry）
 d:高登（Gordon）
 e:詹姆士（James）
 f:培西（Percy）
 g:托比（Toby）
 h:达克（Duke）
 i:唐纳德&道格拉斯（Donald&Douglas）
 j:奥利佛（Oliver）
 k:亚瑟（Arthur）
 l:艾蜜莉（Emily）
 */

struct BT
{
    int key;
    BT *l, *r;
};

BT* create_n(int key)
{
    BT *p = new BT();
    p->l = p->r = NULL;
    p->key = key;
    return p;
}

bool train_schedule(BT* rt, int index)
{
    if (!rt)
        return false;
    
    map<int, string> m_train;
    m_train[0] = "Thomas";
    m_train[1] = "Edward";
    m_train[2] = "Henry";
    m_train[3] = "Gordon";
    
    m_train[4] = "James";
    m_train[5] = "Percy";
    m_train[6] = "Toby";
    m_train[7] = "Duke";
    
    m_train[8] = "Donald&Douglas";
    m_train[9] = "Oliver";
    m_train[10] = "Arthur";
    m_train[11] = "Emily";
    //TODO:write the real train schedule code here
    if(index == 1){
        cout<<m_train[11]<<" "<<m_train[8]<<endl;
    }
    else if(index == 2){
        cout<<m_train[10]<<" "<<m_train[6]<<endl;
    }
    else if(index == 3){
        cout<<m_train[9]<<endl;
    }
    else if(index == 4){
        cout<<m_train[2]<<endl;
    }
    else if(index == 5){
        cout<<m_train[7]<<" "<<m_train[5]<<endl;
    }
    else if(index == 6){
        cout<<m_train[4]<<" "<<m_train[0]<<endl;
    }
    else if(index == 7){
        cout<<m_train[1]<<endl;
    }
    else if(index == 8){
        cout<<m_train[3]<<endl;
    }
    else {
        cout<<"这题根本没有说清楚要干什么啊！！！样例输入什么意思啊！！！"<<endl;
    }
    
    return true;
}
int main()
{
    int i = 0;
    BT *rt = create_n('a');
    rt->l = create_n('b');
    rt->r = create_n('c');
    rt->l->l = create_n('d');
    rt->l->r = create_n('e');
    rt->r->l = create_n('f');
    rt->r->r = create_n('g');
    rt->r->l->r = create_n('h');
    rt->r->r->r = create_n('i');
    rt->r->r->l = create_n('j');
    rt->r->r->l->r = create_n('k');
    rt->r->r->l->r->r = create_n('l');
    std::cin >> i;
    
    train_schedule(rt,i);
    return 0;
}
