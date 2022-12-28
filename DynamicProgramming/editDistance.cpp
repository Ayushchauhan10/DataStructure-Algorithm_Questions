/*
Code : Edit Distance (Memoization and DP)

You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note :
Strings don't contain spaces in between.
 Input format :
The first line of input contains the string S of length M.

The second line of the input contains the String T of length N.
Output format :
Print the minimum 'Edit Distance' between the strings.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
abc
dc
Sample Output 1 :
2
 Explanation to the Sample Input 1 :
 In 2 operations we can make string T to look like string S.
First, insert character 'a' to string T, which makes it "adc".

And secondly, replace the character 'd' of string T with 'b' from the string S. This would make string T as "abc" which is also string S. 

Hence, the minimum distance.
Sample Input 2 :
whgtdwhgtdg
aswcfg
Sample Output 2 :
9
*/
#include <iostream>
#include <cstring>
using namespace std;

int editDistanceHelper(string s1, string s2, int **a)
{
  int m = s1.size(), n = s2.size();
  if (m <= 0 || n <= 0)
  {
    return max(m, n);
  }
  if (a[m][n] != -1)
  {
    return a[m][n];
  }
  else
  {
    if (s1[0] == s2[0])
  {
    int x = editDistanceHelper(s1.substr(1), s2.substr(1), a);
    a[m - 1][n - 1] = x;
    a[m][n] = x;
  }
  else
  {
    a[m][n - 1] = editDistanceHelper(s1, s2.substr(1), a);
    a[m -1][n - 1] = editDistanceHelper(s1.substr(1), s2.substr(1), a);
    a[m - 1][n] = editDistanceHelper(s1.substr(1), s2, a);
    a[m][n] = min(a[m][n - 1], min(a[m - 1][n - 1], a[m - 1][n])) + 1;
  }
  }
    return a[m][n];
  }

  int editDistance(string s1, string s2)
  {
    int m = s1.size() + 1, n = s2.size() + 1;
    int **ans = new int *[m];
    for (int i = 0; i < m; i++)
    {
      ans[i] = new int[n];
      for (int j = 0; j < n; j++)
      {
        ans[i][j] = -1;
      }
    }
    return editDistanceHelper(s1, s2, ans);
}

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}
