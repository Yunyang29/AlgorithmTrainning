// ¡Ì https://www.programmercarl.com/kamacoder/0058.%E5%8C%BA%E9%97%B4%E5%92%8C.html#%E6%80%9D%E8%B7%AF
//
// ¡Ì Keywords: Prefix Sum, Range Sum Query, Array
// 
// ¡Ì Idea:
// - Use a prefix sum array to efficiently calculate the sum of elements in a given range.


#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
	int main()
	{
		int n;
		cin >> n;

		vector<int> nums(n, 0);
		vector<int> sums(n, 0);
		int presum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> nums[i];
			presum += nums[i];
			sums[i] = presum;
		}

		int a, b = 0;

		while (cin >> a >> b) {
			if (a == 0)
				return sums[b];
			else
				return sums[b] - sums[a - 1];
		}
	}

	void test()
	{
		int result = main();
		cout << result << endl;
		// Example input: 5 1 2 3 4 5 1 3
		// Expected output: 6 (sum of elements from index 1 to 3)
	}
};