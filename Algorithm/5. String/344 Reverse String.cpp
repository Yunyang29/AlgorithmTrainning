#include "..\Header\String.h" 

using namespace std;

void String::_344_reverse_string::main(vector<char>& s)
{
	int left = 0, right = s.size() - 1;
	while (left < right)
	{
		swap(s[left++], s[right--]);
	}

}