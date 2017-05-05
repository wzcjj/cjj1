const long double PI = 3.14159265358979323846264338327950288419716939937510;
struct comp
{
    long double r,i;
    comp(long double _r = 0.0,long double _i = 0.0)
    {
        r = _r; i = _i;
    }
    comp operator +(const comp &b)
    {
        return comp(r+b.r,i+b.i);
    }
    comp operator -(const comp &b)
    {
        return comp(r-b.r,i-b.i);
    }
    comp operator *(const comp &b)
    {
        return comp(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};
void change(comp y[],int len)
{
    int i,j,k;
    for(i = 1, j = len/2;i < len-1; i++)
    {
        if(i < j)swap(y[i],y[j]);
        k = len/2;
        while( j >= k)
        {
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    }
}
void fft(comp *y,int len,int on=1)
{
    change(y,len);
    for(int h = 2; h <= len; h <<= 1)
    {
        comp wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j+=h)
        {
            comp w(1,0);
            for(int k = j;k < j+h/2;k++)
            {
                comp u = y[k];
                comp t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}