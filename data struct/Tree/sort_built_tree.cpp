#include<bits/stdc++.h>
using namespace std;
/*
��Ŀ��������ȫ�������ĵĺ����������

*/
// ����˼·�� ���нṹȷ���õĶ�������ֻ��Ҫģ��һ�����еı�����ʽ�����ɻ�ԭ�����
//��ȫ�������Ľṹ�Ѿ�ȷ���ã�����������ģ�⡣ �������磺����ȫ������Ϊ�ṹ�����ݽṹ�У��ѡ� 

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
