// Date: 21/05/25
// Keywords: Interval Sum
// Idea:
// - Use a 2D vector to represent the land prices.
// - Calculate the total sum of land prices.



#include "..\Header\Array.h" 
#include <iostream>

using namespace Array;

void land_purchasing::main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> vec(0, vector<int>(m, 0));

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int val;
			cin >> val;
			vec[i][j] = val;
			sum += val;
		}
	}


	int res = INT_MAX;
	int count = 0;

	// 以行划分
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			count += vec[i][j];
			if (j == m - 1)
				res = min(res, abs(sum - count - count));
		}
	}

	// 以列划分
	count = 0;
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			count += vec[i][j];
			if (i == n - 1)
				res = min(res, abs(sum - count - count));
		}
	}

	cout << res;
}