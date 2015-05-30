void getNext(string W){
    memset(next,255,sizeof(next));
    int j=-1;
    for(int i=1;i<W.length();i++){
        while(j>-1&&W[j+1]!=W[i])j=next[j];
        if(W[j+1]==W[i])j++;
        next[i]=j;
    }
}
int KMP(string W,string T){
    int i=0,j=0;
    while(i<T.length()){
        while(j!=-1&&W[j]!=T[i]){
            j=next[j];
        }
        if(j==W.length()){
            return i-W.length()+1;
        }
        else{
            j++;i++;
        }
    }
    return -1;
}
