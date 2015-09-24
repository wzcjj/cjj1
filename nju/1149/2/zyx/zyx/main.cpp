#include <iostream>
using namespace std;

int n, s, a[100001];
long long sum[100001];

int finds(int ss, int p, int q)//∑µªÿµ⁄“ª∏ˆ–Ú¡–µƒ◊Ó∫Û“ª∏ˆŒª÷√
{
    if (p<q) return 0;
    int mid=(p+q)/2;
    if (p==q)
    {
        if (sum[q]<=ss) return q;
        else return 0;//all<ss
    }
    else if (sum[mid]<=ss)
    {
        int temp=finds(ss, mid+1, q);
        if (temp==0) return mid;
        else return temp;
    }
    else
    {
        return finds(ss, p, mid-1);
    }
}

int main()
{
    int pivot = 0, begin = 0;
    bool pivotfind= true, beginfind = true;
    sum[0]=0;
    cin >> n >> s;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        sum[i]=sum[i-1]+a[i];
        if (sum[i]>s && pivotfind)
        {
            pivot = i;
            pivotfind = false;
        }
        if (sum[i]>2*s && beginfind)
        {
            begin = i;
            beginfind = false;
        }
    }
    if (pivotfind)
    {
        for (int k=1; k<=n; k++)
        {
            cout << (n-k+1)/2*2 << endl;
        }
        return 0;
    }
    pivot--;//pivot:µ⁄“ª∏ˆ–Ú¡–µƒ◊Ó∫Û“ª∏ˆ÷µµƒŒª÷√
    if (beginfind) begin=n+1;
    begin--;
    if(begin>2*pivot) begin=2*pivot;
    else
    {
        pivot=begin/2;
        begin=pivot*2;
    }
    while ((sum[begin]-sum[pivot]) > s && pivot>0)
    {
        pivot--;
        begin-=2;
    }
    cout << begin << endl;
    
    for (int j=2; j<n; j++)
    {
        if (sum[j]>s+sum[j-1])
        {
            cout << 0 << endl;
        }
        else
        {
            pivot = j-1;
            while ((pivot+1<=(j+(n-j-1)/2)) && (finds(s+sum[j-1], j, pivot+1)!=0) && (finds(s+sum[pivot+1], pivot+2, 2*pivot-j+3)!=0))
            {
                pivot++;
            }
            cout << 2*(pivot-j+1) << endl;
        }
        
    }
    cout << 0 << endl;
    
    return 0;
} 
