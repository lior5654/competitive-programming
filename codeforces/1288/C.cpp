/*
 * sol.cpp
 *
 *  Created on: 16 בינו׳ 2020
 *      Author: liory
 */

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
int main()
{
	int m, n;
	int i = 0;
	int j = 0;
	int k = 0;
	long long int out;
	vector<vector<unsigned long long int>> seq;

	cin >> n >> m;
	seq.resize(m, std::vector<unsigned long long int>(n, 0));
	for (i = 0; i < n; i++)
	{
		seq[0][i] = i + 1 % 1000000007;
		//dp[0][i] = (i + 1) * (i + 2) / 2;
	}
	for (i = 1; i < m; i++)
	{
		seq[i][0] = 1;
		for (j = 1; j < n; j++)
		{
			seq[i][j] = 1; // the option in which all of them are n+1
			for (k = 0; k <= i; k++)
			{
				seq[i][j] += seq[k][j - 1] % 1000000007;  // k+1 th element is n+1, all the rest n or below. if k is i-1 then all of them are n or below. yay!
			}

		}
	}
	out = 0;
	if (m == 1)
	{
		out = (n * (n + 1) / 2) % 1000000007;
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			out += ((seq[m - 1][i] % 1000000007 )* seq[m - 2][n - i - 1] % 1000000007) % 1000000007;
		}
	}

	cout << out % 1000000007<< std::endl;

	return 0;
	// dp[i][j] - length i + 1& max element j + 1
	// dp[0][0] = 1
	// dp[i][j+1] = dp[i][j] +
	// increasing m by 1


}




