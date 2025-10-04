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
		// �Ӹ�λ��ʼ������ÿλ���ֵ�ƽ����
		while (temp)
		{
			sum += (temp % 10) * (temp % 10);
			temp /= 10;
		}

		// ���sum����1��˵���ǿ�����
		if (sum == 1)
			return true;

		// ���sum�Ѿ�������set�У�˵��������ѭ��
		if (set.find(sum) != set.end())
			return false; // ���sum�Ѿ�������set�У�˵��������ѭ��
		else
			set.insert(sum);
	}
	return false;
}