/*
Longest Increasing Subsequence

Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are sorted in strictly increasing order.
Input Format
The first line of input contains an integer N. The following line contains N space separated integers, that denote the value of elements of array.
Output Format
The first and only line of output contains the length of longest subsequence.
Constraints
1 <= N <= 10^3
Time Limit: 1 second
Sample Input 1 :
6
5 4 11 1 16 8
Sample Output 1 :
3
Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).
Sample Input 2 :
3
1 2 2
Sample Output 2 :
2
*/
#include<bits/stdc++.h>
using namespace std;

int list1(int* arr, int i)
{
    if(i==0)
        return 1;    
    int ans=INT_MIN;

    for(int j=0;j<i;j++)
    {
        if(arr[j]<arr[i])
        ans=max(ans,1+list1(arr,j));
    }
  
   return ans;
    
}

int longestIncreasingSubsequence(int* arr, int n) 
{
    int a=0;
    
    int *ar=new int[n+1];
    for(int i=0;i<=n;i++)
        ar[i]=-1;
    
    for(int i=0;i<n;i++)
    {
          if(ar[i]!=-1)
              a=max(a,ar[i]);
          else
         {
            ar[i]=max(a,list1(arr,i));
            a=ar[i];
         }  
    }
    
    return a;
      
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}
