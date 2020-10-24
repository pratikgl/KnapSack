// KnapSack using dynamic programming

const int N = 2e4 + 5;
int dp[N][N];

int KnapSack_dp(vector<int> &weight,  vector<int> &value, int capacity)
{
	// total number of items
	int n = weight.size();

	for (int j = 1; j < n + 1; ++j)
	{
		int x = weight[j - 1];
		int y = value[j - 1];

		for (int i = 0; i < capacity + 1; ++i)
		{
			if (i - x >= 0)
				dp[j][i] =  max(dp[j - 1][i], dp[j - 1][i - x] + y);
			else
				dp[j][i] = dp[j - 1][i];
		}
	}

	return dp[n][capacity];
}