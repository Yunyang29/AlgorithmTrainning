
#include "..\Header\String.h" 
#include <algorithm> // Add this include at the top if not present
#include <iostream>

using namespace std;

void String::_151_reverse_words_in_a_string::trim(string& s)
{
	int slow = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			continue;

		if (slow > 0)
			s[slow++] = ' ';


		while (i < s.size() && s[i] != ' ')
			s[slow++] = s[i++];
	}
	s.resize(slow);
}

void String::_151_reverse_words_in_a_string::reverse(string& s, int left, int right)
{
	while (left < right)
		swap(s[left++], s[right--]);
}

string String::_151_reverse_words_in_a_string::main(string s)
{
	trim(s);
	reverse(s, 0, s.size() - 1);
	int last = 0;
	for (int i = 0; i <= s.size(); i++)
	{
		if (i == s.size() || s[i] == ' ')
		{
			reverse(s, last, i - 1);
			last = i + 1;
		}
	}

	return string();
}