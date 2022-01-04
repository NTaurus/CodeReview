#include "./base.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void solve(int A[], int N)
{
    int i = 0, j = N - 1;
    while (i < j)
    {
        if (A[i] < 0)
            i++;
        if (A[j] > 0)
            j--;
        if (A[i] > 0 && A[j] < 0)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
}
struct student
{
    int id;
    string name;
    student(int a, string str)
    {
        id = a;
        name = str;
    }
    // bool operator <(const student &a) const
    // {
    //     if(a.id != id)
    //         return id < a.id;
    //     return name > a.name;
    // }
    bool operator<(const student &a) const
    {
        if (id != a.id)
            return id > a.id;
        return name < a.name;
    }
};
void TestPriorityQueue()
{
    student stu1(8, "nlm"), stu2(26, "zq"), stu3(8, "zoe");
    priority_queue<student> Q;
    Q.push(stu1);
    ]
    Q.push(stu2);
    Q.push(stu3);
    while (!Q.empty())
    {
        cout << Q.top().id << ' ' << Q.top().name << endl;
        Q.pop();
    }
}
int main()
{
    // int N;
    // cin>>N;
    // int *A=base::Cin(N);
    // solve(A,N);
    // base::Print(A,N);
    // ofstream out("./a.txt", ios::out);
    // out << "hello world";
    // out << "\nppp";
    // out.close();
    // ifstream in("./a.txt", ios::in);

    // // while(in){
    // //     char data;
    // //     in>>data;
    // //     cout<<data;
    // // }
    // cout << "hello world!" << endl;

    TestPriorityQueue();
    return 0;
}

//什么狗屁O(1)，牺牲空间来假装是O(1)，申请空间也要时间啊
// #include<iostream>
// using namespace std;
// typedef long long ll;
// class Temp
// {
// public:
//     Temp(){
//         ++N;
//         Sum += N;
//     }
//     static void Reset(){
//         N = 0;
//         Sum = 0;
//     }
//     static ll GetSum(){
//         return Sum;
//     }
// private:
//     static ll  N;
//     static ll Sum;
// };
// ll Temp::N = 0;
// ll Temp::Sum = 0;
// int solution_Sum(int n){
//     Temp::Reset();
//     Temp *a = new Temp[n];
//     delete[]a;
//     a = 0;
//     return Temp::GetSum();
// }
// ll getsum(ll num){
//     return num*1+(num-1)*(num)/2;
// }
// ll Sum(int num){
//     ll sum=0;
//     for(int i=1;i<=num;i++)
//         sum+=i;
//     return sum;
// }
// int main(){
//     int num=1000000000;
//     cout << solution_Sum(num) << endl;
//     // cout << Sum(num) <<endl;
//     // cout << getsum(num) <<endl;
//     return 0;

// }