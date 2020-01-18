#include <vector>
#include <iostream>

int question(int n, int l, int r);
int main()
{
	int n;
	int l, r;
	std::cin >> n >> l >> r;
	std::cout << question(n, l, r) << std::endl;
	return 0;

}
int question(int n, int l, int r)
{
	std::vector<std::vector<long long int>> dp;
	dp.resize(n, std::vector<long long int>(3));
	dp[0][0] = ((r - l + l % 3) / 3 + (l % 3 == 0)) % 1000000007;
	dp[0][1] = ((r - l + (l - 1 + 3) % 3) / 3 + (l % 3 == 1)) % 1000000007;
	dp[0][2] = ((r - l +(l - 2 + 3) % 3) / 3 + (l % 3 == 2)) % 1000000007;
	// issue: double counting	
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = (dp[i - 1][1] * dp[0][2] + dp[i - 1][2] * dp[0][1] + dp[i - 1][0] * (dp[0][0] - 0)) % 1000000007;
		dp[i][1] = (dp[i - 1][0] * dp[0][1] + dp[i - 1][1] * dp[0][0] + dp[i - 1][2] * (dp[0][2] - 0)) % 1000000007;
		dp[i][2] = (dp[i - 1][0] * dp[0][2] + dp[i - 1][2] * dp[0][0] + dp[i - 1][1] * (dp[0][1] - 0)) % 1000000007;
	}

	return dp[n - 1][0];
}