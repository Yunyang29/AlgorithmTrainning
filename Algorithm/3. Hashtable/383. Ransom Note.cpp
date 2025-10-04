#include "..\Header\HashTable.h" 

bool HashTable::_383_ransom_note::main(string ransomNote, string magazine)
{
	int res[26];
	for (int i = 0; i < magazine.size(); i++)
	{
		res[magazine[i] - 'a']++;
	}

	for (int i = 0; i < ransomNote.size(); i++)
	{
		res[ransomNote[i] - 'a']--;
		if (res[ransomNote[i] - 'a'] < 0)
			return false;
	}
	return true;
}