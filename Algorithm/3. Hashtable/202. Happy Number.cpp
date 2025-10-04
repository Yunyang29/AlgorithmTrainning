// Date: 25/06/26
// Leetcode: https://leetcode.cn/problems/happy-number/description/
// Keywords: Happy Number, Hash Table, Set
// Idea:
// - Use a set to track previously seen sums.

#include "..\Header\HashTable.h" 
#include <unordered_set>

bool HashTable::_202_happy_number::main(int n)
{
	unordered_set<int> set;
	int sum = n;
	while (true)
	{
		int temp = sum;
		sum = 0;
		// 从个位开始，计算每位数字的平方和
		while (temp)
		{
			sum += (temp % 10) * (temp % 10);
			temp /= 10;
		}

		// 如果sum等于1，说明是快乐数
		if (sum == 1)
			return true;

		// 如果sum已经存在于set中，说明进入了循环
		if (set.find(sum) != set.end())
			return false; // 如果sum已经存在于set中，说明进入了循环
		else
			set.insert(sum);
	}
	return false;
}