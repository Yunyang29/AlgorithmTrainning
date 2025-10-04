// Date: 23/09/25
// Link: https://leetcode.com/problems/reverse-string-ii/

#include "..\Header\String.h" 
#include <algorithm> // Add this include at the top if not present
#include <iostream>

using namespace std;

string String::_541_reverse_string_ii::main(string s, int k)
{
	for (int i = 0; i < s.size(); i += 2 * k)
	{
		if (i + k < s.size())
			std::reverse(s.begin() + i, s.begin() + i + k);
		else
			std::reverse(s.begin() + i, s.end());
	}
	return s;
}