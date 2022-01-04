#include<bits/stdc++.h>
using namespace std;
/*
题目描述：完全二叉树的的后序遍历建树

*/
// 解题思路： 所有结构确定好的二叉树，只需要模拟一个序列的遍历方式，即可还原这颗树
//完全二叉树的结构已经确定好，可用数组来模拟。 常见的如：以完全二叉树为结构的数据结构有：堆、 

int T[50],a[50];
int N,index;
void postordered(int root){
	if(root>N||index>=N)return ;
	postordered(root*2);
	postordered(root*2+1);
	T[root]=a[index++];
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	postordered(1);
	for(int i=1;i<=N;i++){
		cout<<T[i]<<' ';
	}
	return 0;
} 
