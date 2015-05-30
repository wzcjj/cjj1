typedef int* int1;
typedef int1* int2;
int main(){
    int2 a;
    a = new int1[5];
    a[1] = new int[5];
    delete []a;
    return 0;
} 
