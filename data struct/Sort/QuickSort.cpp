#include<iostream>
#include<time.h>
#include<algorithm>
#include"../base.h"
using namespace std;
int *A,N;
int p=0;
void quickSort(int v[],int begin,int end){
    if(begin>=end-1)return ;
    int L=begin,R=end-1;
    int index=v[L];
    while(L<R){
        while(L<R){
            if(v[R]<index){
                v[L++]=v[R];
                break;
            }
            --R;
        }
        while(L<R){
            if(v[L]>index){
                v[R--]=v[L];
                break;
            }
            ++L;
        }
    }
    v[L]=index;
    cout<<"《"<<index<<"》";
    cout<<"第"<<++p<<"趟：";
    base::Print(A,N);
    quickSort(v,begin,L);
    quickSort(v,R+1,end);
}
void quicksort_2_0(int A[],int left,int right){
    if(left>=right)return ;
    int index=A[left];
    // cout<<index<<endl;
    int L=left,R=right-1;
    while(L<R){
        while(L<R&&A[R]>=index)R--;
        while(L<R&&A[L]<index)L++;
        swap(A[L],A[R]);
    }
    A[L]=index;
    base::Print(A,N);
    quicksort_2_0(A,left,L);
    quicksort_2_0(A,R+1,right);
}
struct node_{
    int L,R;
};
const int maxSize=100;
void qSortbyStack(int A[],int L,int R){
    struct node_ S[maxSize];
    int top=0;
    struct node_ t;
    t.L=L,t.R=R;
    S[top++]=t;
    while(top){
        t=S[--top];
        int low=t.L,high=t.R;
        if(low>high-1)//千万别漏
            continue;
        L=low;R=high-1;
        int index=A[L];
        while(L<R){
            while(L<R){
                if(A[R]<index){
                    swap(A[L++],A[R]);
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
        t.L=low; t.R=L;    S[top++]=t;//左区间排序
        t.L=R+1; t.R=high; S[top++]=t;//右区间排序
    }
}

void qSortbyQueue(int A[],int L,int R){
    struct node_ S[maxSize];
    int rear=0,front=0;
    struct node_ t;
    t.L=L,t.R=R;
    S[rear++]=t;
    while(rear!=front){
        t=S[front++];
        int low=t.L,high=t.R;
        if(low>high-1)//千万别漏
            continue;
        L=low;R=high-1;
        int index=A[L];
        while(L<R){
            while(L<R){
                if(A[R]<index){
                    swap(A[L++],A[R]);
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
        t.L=low; t.R=L;    S[rear++]=t;//左区间排序
        t.L=R+1; t.R=high; S[rear++]=t;//右区间排序
    }
}

void Print(int *A,int N){
    for(int i=0;i<N;i++){
        cout<<A[i]<<' ';
    }
    cout<<endl;
}
void qSortByRandomKey(int A[],int low,int high){
    if(low>high-1)return ;
    int L=low,R=high-1;
    srand(unsigned(time(NULL)));
    int i=rand()%(high-low);
    int j=i+low;
    // cout<<low<<' '<<high<<' '<<high-low<<' '<<j<<endl;
    int index=A[j];
    cout<<index<<endl;
    swap(A[j],A[low]);
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
    base::Print(A,N);
    qSortByRandomKey(A,low,L);
    qSortByRandomKey(A,R+1,high);
}

//找第k大的数，即当快速排序选的基准，在经过一趟排序后，所在的位置为k-1即是
//所找的数
int FindKthnum(int A[],int low,int high,int k){
    if(low>high-1)return -1;
    int L=low,R=high-1;
    srand(unsigned(time(NULL)));
    int x=low+rand()%(high-low);
    cout<<A[x]<<endl;
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

void QSORT(int A[],int low,int high){
    if(low>=high)return;
    int L=low,R=high-1;
    int index=A[L];
    cout<<index<<' '<<endl;
    while(L<R){
        while(L<R){
            if(A[R]<index){
                swap(A[R],A[L++]);
                break;
            }
            R--;
        }
        // base::Print(A,N);
        while(L<R){
            if(A[L]>index){
                swap(A[L],A[R--]);
                break;
            }
            L++;
        }
    }
    A[L]=index;
    base::Print(A,N);
    // cout<<"第"<<++p<<"趟：";
    // for(int i=0;i<N;i++){
    //     cout<<A[i]<<' ';
    // }
    // cout<<endl;
    QSORT(A,low,R);
    QSORT(A,R+1,high);
}

void QuickClassify(int *A,int begin,int end){
    if(begin>=end)return ;
    int L=begin,R=end;
    int sum=0;
    for(int i=L;i<=R;i++)
        sum+=A[i];
    int avg=sum/(R-L+1);
    cout<<avg<<endl;
    while(L<R){
        while(L<R&&A[R]>avg)R--;
        while(L<R&&A[L]<avg)L++;
        swap(A[L],A[R]);
    }
    base::Print(A,N);
    QuickClassify(A,begin,L);
    QuickClassify(A,R+1,end);
}
void QUICKSORT(int *A,int low,int high){
    if(low>=high)return; 
    int L=low,R=high-1;
    int index=A[low];
    while(L<R){
        while(L<R&&A[R]>index)R--;
        while(L<R&&A[L]<index)L++;
        swap(A[L],A[R]);
    }
    // A[L]=index;
    cout<<"``````````````\n"<<index<<endl;
    base::Print(A,N);
    QUICKSORT(A,low,L);
    QUICKSORT(A,R+1,high);
}
int main(){
    // int A[N]={8,5,2,6,3,1,9,4,7,N};
    // int A[N]={7,3,1,30,9,11,23,41,44,17};
    cin>>N;
    A=base::Cin(N);

    quickSort(A,0,N);
    base::Print(A,N);
    // QuickClassify(A,0,9);
    // base::Print(A,N);
    // Qsort(A,0,N);
    // QSORT(A,0,N);
    // QUICKSORT(A,0,N);
    // quicksort_2_0(A,0,N);
    base::Print(A,N);
    // qSortbyStack(A,0,N);//用栈
    // qSortbyQueue(A,0,N);//用队列
    // qSortByRandomKey(A,0,N);//基准随机选择
    // cout<<FindKthnum(A,0,N,8)<<endl;
    // cout<<kth_elem(A,N,7)<<endl;
    return 0;
}