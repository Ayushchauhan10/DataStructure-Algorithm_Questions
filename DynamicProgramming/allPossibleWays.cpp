/*
All possible ways

Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-
10 = 1^2 + 3^2 
Hence, answer is 1.
Note : x^y represents x raise to the power y
Input Format:
The first line of input contains two space separated integers, that denote the value of a and b.
Output Format:
The first and only line of output contains count of ways in which a can be represented as sum of unique integers raised to power b.
Constraints :
1 <= a <= 10^4
1 < b <= 20
Time Limit: 1 second
Sample Input 1 :
10 2
Sample Output 1 :
1
Sample Input 2 :
100 2
Sample Output 2 :
3
Explanation:
Following are the three ways: 
1. 100 = 10^2
2. 100 = 8^2 + 6^2
3. 100 = 7^2+5^2+4^2+3^2+1^2
*/

#include <iostream>
using namespace std;

int get(int a,int b,int n)
{
    int r=pow(n,b);
    
    if(r==a)
        return 1;
    
    if(r>a)
      return 0;
    
    int x=get(a-r,b,n+1);
    int y=get(a,b,n+1);
    
    return x+y;
  
}

int getAllWays(int a, int b) {
 
    return get(a,b,1);

}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}
