// Date: 17/06/25
// Leetcode 242 https://leetcode.cn/problems/valid-anagram/description/
// Keywords: Valid Anagram, Character Count, Hash Table
// Idea:
// - Count the occurrences of each character in both strings using an array of size 26 (for lowercase letters).
// - Compare the counts to determine if the strings are anagrams.

#include "HashTable.h"

bool HashTable::_242_valid_anagram::main(string s, string t)
{
	int record[26] = { 0 };
	for (int i = 0; i < s.size(); i++)
	{
		record[s[i] - 'a']++;
	}

	for (int i = 0; i < t.size(); i++)
	{
		record[s[i] - 'a']--;
	}

	for (int i = 0; i < 26; i++)
	{
		if (record[i] != 0)
		{
			return false;
		}
	}

	return true;
}