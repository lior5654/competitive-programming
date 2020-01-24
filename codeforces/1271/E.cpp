#include <iostream>
#include <cmath>
unsigned long long int paths(unsigned long long int M, unsigned long long int n);
int main()
{
	unsigned long long int n = 0;
	unsigned long long int k = 0;
	long long int L = 0;
	long long int R = 0;
	unsigned long long int M = 0;
	unsigned long long int best = 0;
	std::cin >> n >> k;
	for (int i = 0; i <= 1; i++)
	{
		R = n / 2 + (i * n & 1);
		L = 1;
		while (L <= R)
		{
			M = L + (R - L) / 2;
			if (paths(2 * M - i, n) >= k)
			{
				L = M + 1;
				if (2 * M - i > best)
				{
					best = 2 * M - i;
				}
			}
			else
			{
				R = M - 1;
			}
		}
	}
	std::cout << best << std::endl;
}

unsigned long long int paths(unsigned long long int M, unsigned long long int n)
{
	unsigned long long int output = 0;
	unsigned long long int curr = 0;
	unsigned short line = 1;
	if (M & 1)
	{
		output = 1;
		M *= 2;
	}
	while (n >= M + (((long long int)2) << (line - 1)) - 1)
	{
		curr = curr * 2 + 2;
		M *= 2;
		line++;
	}
	if (n >= M)
	{
		curr += n - M;
		curr += 1;
	}
	output += curr;


	/*unsigned long long int query = (n / M) >> 1;
	unsigned long long int maxPow = 0;
	while (query)
	{
		maxPow++;
		query >>= 1;
	}
	output +=  2 * ( ((unsigned long long int)1 << maxPow) - 1);*/
	return output;
}