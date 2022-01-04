#include<iostream>
#include<vector>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int n = nums1.size();
    int m = nums2.size();
    if(n > m)   //保证对数组长度最短的进行二分
        return findMedianSortedArrays(nums2,nums1);
    int L1,L2,R1,R2,c1,c2,left = 0, right = 2*n;  //虚拟加#符号之后，数组长度为2n+1,但是数组下标从0开始，所以要减去1
    while(left <= right)//二分法框架
    {
        c1 = (left + right) / 2;  //c1是二分的结果
        c2 = m + n - c1;//k = m+n 确保两个数组左半部分加起来等于k
        L1 = (c1 == 0)?INT_MIN:nums1[(c1-1)/2]; //根据映射关系还原数组元素的原下标
        R1 = (c1 == 2*n)?INT_MAX:nums1[c1/2];
        L2 = (c2 == 0)?INT_MIN:nums2[(c2-1)/2];
        R2 = (c2 == 2*m)?INT_MAX:nums2[c2/2];
        
        if(L1 > R2)
        {
            left = c1-1;
        }
        else if(L2 > R1)
        {
            right = c1+1;
        }
        else
        {
            break;
        }
    }
    return (double)(max(L1,L2)+ min(R1,R2))/2;
}
 
 
int main()
{
    vector<int>nums1(4);
    vector<int>nums2(3);
    for(int i=0; i<4;i++)
    {
        cin >> nums1[i];
    }
    for(int i=0; i<3; i++)
    {
        cin >> nums2[i];
    }
    cout<< findMedianSortedArrays(nums1,nums2)<< endl;
    return 0;
 
}