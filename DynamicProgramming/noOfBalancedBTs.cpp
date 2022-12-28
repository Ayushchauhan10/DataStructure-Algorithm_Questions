/*
Code : No. of balanced BTs using DP

Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 10^6
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/

#include <iostream>
using namespace std;

int balancedBTs(int n) 
{    
    long long int* a=new long long int[n+1];
    a[0]=0;
    a[1]=1;
    a[2]=3;
    
    for(int i=3;i<=n;i++)
    {
        a[i]=((2*a[i-1]*a[i-2])+(a[i-1]*a[i-1]))%1000000007;    
    }
    
    return a[n]%1000000007;
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}

