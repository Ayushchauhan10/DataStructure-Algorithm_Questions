/*
Matrix Chain Multiplication

Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
Input Format:
The first line of input contains an integer, that denotes the value of n. The following line contains n+1 integers, that denote the value of elements of array p[].
Output Format:
The first and only line of output prints the minimum number of multiplication needed.
Constraints :
1 <= n <= 100
Time limit: 1 second
Sample Input 1:
3
10 15 20 25
Sample Output 1:
8000
Sample Output Explanation:
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000. 
*/
#include <bits/stdc++.h>
using namespace std;
int matrixChainMultiplication(int* arr, int z,int j,int** v) {
 
    if(z==j)
        return 0;
    
    int k=1,ans=INT_MAX;
    if(v[z][j]!=-1)
             return v[z][j];
    for(int i=z;i<j;i++)
    {
      int a=matrixChainMultiplication(arr,z,i,v)+matrixChainMultiplication(arr,i+1,j,v)+arr[z-1]*arr[i]*arr[j];
       ans=min(ans,a);    
    }    
    return v[z][j]=ans;
 
}

int matrixChainMultiplication(int* arr, int n) {
  int**v =new int*[n+1];
    
    for(int i=0;i<n+1;i++)
    {
        v[i]=new int[n+1];
        for(int j=0;j<n+1;j++)
            v[i][j]=-1;
    }
 return  matrixChainMultiplication(arr, 1,n,v); 
    
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}
