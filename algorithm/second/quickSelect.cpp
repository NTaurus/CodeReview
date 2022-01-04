#include<iostream>
#include<time.h>
#include"../base.h"
using namespace std;

int kth_elem(int A[],int N,int K){
    if(K<=0||K>N)return -1;
    int low=0,high=N-1;
    while(1){
        int L=low,R=high;
        int index=A[L];
        while(L<R){
            if(A[R]<index){
                swap(A[R],A[L++]);
                break;
            }
            R--;
        }
        while(L<R){
            if(A[L]>index){
                swap(A[L],A[R--]);
                break;
            }
            L++;
        }
        A[L]=index;
        if(L==K-1)return A[L];
        else if(L>K-1)
            high=L;
        else
            low=R+1;
    }
}

int FindKthnum(int A[],int low,int high,int k){
    if(low>high-1)return A[low];
    srand(unsigned(time(NULL)));
    int L=low,R=high-1;
    int x=low+rand()%(high-low);
    swap(A[x],A[L]);
    int index=A[L];
    while(L<R){
        while(L<R){
            if(A[R]<index){
                swap(A[R],A[L++]);
                break;
            }
            R--;
        }
        while(L<R){
            if(A[L]>index){
                swap(A[L],A[R--]);
                break;
            }
            L++;
        }
    }
    A[L]=index;
    if(L>k-1)
        return FindKthnum(A,low,L,k);
    else if(L<k-1)
        return FindKthnum(A,R+1,high,k);
    else return A[L];
}

int kth_elem_2_0(int A[],int low,int high,int k){
    if(low>=high)return -1;
    int L=low,R=high-1;
    int index=A[L];
    while(L<R){
        while(L<R&&index<A[R])R--;
        swap(A[R],A[L++]);
        while(L<R&&index>A[L])L++;
        swap(A[L],A[R--]);
    }
    A[L]=index;
    if(L==k-1)return A[L];
    else if(L>k-1)
        return kth_elem_2_0(A,low,L,k);
    else
        return kth_elem_2_0(A,R+1,high,k);
}

void QS(int A[],int low,int high){
    if(low>=high-1)return ;
    int L=low,R=high-1;
    int index=A[L];
    while(L<R){
        while(L<R&&A[R]>index)R--;
        swap(A[R],A[L]);
        while(L<R&&A[L]<index)L++;
        swap(A[L],A[R]);
    }
    A[L]=index;
    QS(A,low,L);
    QS(A,R+1,high);
}
int main(){
    int A[100]={4,1,5,8,6,2,9,10,21};
    int N=9;
    // cout<<FindKthnum(A,0,N,6)<<endl;
    // cout<<kth_elem_2_0(A,0,N,6)<<endl;
    QS(A,0,N);
    base::Print(A,N);
    return 0;
}