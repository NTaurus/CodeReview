#include<iostream>
#include<algorithm>
#include"../base.h"
using namespace std;
struct Index{
    int maxVal;
    int start;
};
int m=0;
void BlockSearch(Index Index[],int L,int R,int A[],int AL,int num){
    int low=L;
    int high=R-1;
    m=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(num>Index[mid].maxVal)
            low=mid+1;
        else
            high=mid-1;
        m++;
        // cout<<mid<<endl;
    }
    int is=0,i;
    printf("折半查找长度：%d；",m);
    for(i=Index[low].start;i<Index[low+1].start;i++){
        m++;
        if(A[i]==num){
            is=1;
            break;
        }
    }
    if(!is)
        printf("查找失败! 查找长度为：%d\n",m);
    else   
        printf("查找成功！%d在第%d块，位置为：%d; 查找长度为：%d\n",num,low+1,i,m);
}

int BSearch(int A[],int R,int num){
    int L=0;
    R--;
    while(L<=R){
        int mid=(L+R)/2;
        if(A[mid]==num)
            return mid;
        else if(A[mid]<num)
            L=mid+1;
        else R=mid-1;
    }
    return -1;
}
int BDFS(int A[],int L,int R,int num){
    if(L>R)return -1;
    if(L==R&&A[L]==num)return L;
    int mid=(L+R)/2;
    if(A[mid]<num)
        return BDFS(A,mid+1,R,num);
    else if(A[mid]>num)
        return BDFS(A,L,mid-1,num);
    else return mid;
}
int search(int A[],int L,int R,int num){
    if(L>R)return -1;
    int mid=(L+R)/2;
    if(num>A[mid])
        return search(A,mid+1,R,num);
    else if(num<A[mid])
        return search(A,L,mid-1,num);
    else return mid;
}
int mulSearch(int A[],int K,int L,int R,int num){
    if(L>R)return -1;
    if(L==R&&A[L]==num)return L;
    int n=R-L;
    for(int i=1;i<K;i++){
        int index=i*n/K;
        if(A[index]==num)return index;
        else {
            int begin=L+(i-1)*n/K;
            int end=index-1;
            int x=mulSearch(A,K,begin,end,num);
            if(x!=-1&&A[x]==num)return x;
        }
    }
    if(n%K){
            int x=mulSearch(A,K,R-(n%K)+1,R,num);
            if(A[x]==num)return x;      
    }
    return -1;
}
//K分查找
int multiplyPathSearch(int A[],int L,int R,int K,int x){
    if(L>R)return -1;
    int i,begin,end;
    int n=(R-L)/K;//K个区间中元素的个数
    for(i=0;i<K-1;i++){
        m++;
        begin=n*(i)+L;
        end=n*(i+1)+L;
        if(A[end]==x)return end;
        else if(A[end]>x||begin==end)
            break;
    }
    // m++;
    if(A[end]<x)
        return multiplyPathSearch(A,end+1,R,K,x);
    else
        return multiplyPathSearch(A,begin,end,K,x);
}
// int thirdSearch(int A[],int L,int R,int x){
//     if(L>R)return -1;
//     int d=(R-L)/3;
//     if(A[L+d-1]==x)return L+d-1;
//     else if(A[L]<=x&&x<=A[L+d-1])
//         thirdSearch(A,L,L+d-1,x);

//     if(A[L+d*2-1]==x)return L+d-1;
//     else if(A[L+d]<=x&&x<=A[L+d*2-1])
//         thirdSearch(A,L,L+d*2-1,x);
//     if(A[L+d*3-1]==x)return L+d-1;
//     else if(A[L]<=x&&x<=A[L+d-1])
//         thirdSearch(A,L,L+d-1,x);
// }
int BSearch_2_0(int A[],int L,int R,int x){
    if(L>R)return -1;
    int mid=(L+R)/2;
    m++;
    if(A[mid]==x)return mid;
    else if(A[mid]>x)
        return BSearch_2_0(A,L,mid-1,x);
    else return BSearch_2_0(A,mid+1,R,x);
}
int BSearch_3_0(int A[],int N,int x){
    int L=0,R=N;
    while(L<=R){
        m++;
        int mid=(R+L)/2;
        if(A[mid]==x)return mid;
        else if(A[mid]<x)
            L=mid+1;
        else R=mid-1;
    }
    return -1;
}
int getMax(int A[],int L,int R){
    if(L>=R-1)return max(A[L],A[R]);
    int mid=(L+R)/2;
    return max(getMax(A,L,mid),getMax(A,mid+1,R));
}
int getMax_2_0(int A[],int L,int R){
    if(L==R)return A[L];
    int mid=(L+R)/2;
    return max(getMax(A,L,mid),getMax(A,mid+1,R));
}
int main(){
    int AL=20;
    int A[500]={24,21,6,11,8,22,32,31,54,72,61,78,88,83,84,82,92,97,94,91};
    Index Index[10];
    Index[0].maxVal=24,Index[0].start=0;
    Index[1].maxVal=54,Index[1].start=6;//32
    Index[2].maxVal=78,Index[2].start=9;//72
    Index[3].maxVal=88,Index[3].start=12;//88
    Index[4].maxVal=97,Index[4].start=16;//92
    Index[5].start=AL;//表长
    int num=1;
    // for(int i=0;i<AL;i++)
    //     BlockSearch(Index,0,5,A,20,A[i]);
    // base::Print(A,20);
    sort(A,A+AL);
    // base::Print(A,AL);
    for(int i=0;i<300;i++)
        A[i]=i+1;
    // base::Print(A,300);
    // cout<<search(A,0,AL-1,num)<<endl;
    // cout<<BSearch(A,AL-1,num)<<'\n';
    // cout<<BSearch_2_0(A,0,300,num)<<'\n';
    // cout<<BSearch_3_0(A,300,num)<<' '<<m<<endl;
    // int a=0,b=0,N=300,K=3;
    // for(int x=1;x<=300;x++){
    //     m=0;
    //     cout<<"二分 "<<BSearch_2_0(A,0,300,x)<<' '<<m<<"          ";
    //     a+=m;
    //     m=0;
    //     cout<<"K分查找"<<' '<<multiplyPathSearch(A,0,300,K,x)<<' '<<m<<endl;
    //     b+=m;
    // }
    // // 总查找长度
    // cout<<a<<' '<<b<<endl;
    cout<<getMax(A,0,300)<<endl<<getMax_2_0(A,0,300);

    return 0;
}