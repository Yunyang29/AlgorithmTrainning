#include "String.h"
#include <iostream>

using namespace std;
using namespace String;

void _replace_number::main()
{
	string s;
	while (cin >> s)
	{
		int oldEndPtr = s.size() - 1;
		int numberCount = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= '0' && s[i] <= '0')
			{
				numberCount++;
			}
		}

		s.resize(s.size() + numberCount * 5);

		int newEndPtr = s.size() - 1;

		while (oldEndPtr >= 0)
		{
			if (s[oldEndPtr] >= '0' && s[oldEndPtr] <= '0')
			{
				s[newEndPtr--] = 'r';
				s[newEndPtr--] = 'e';
				s[newEndPtr--] = 'b';
				s[newEndPtr--] = 'm';
				s[newEndPtr--] = 'u';
				s[newEndPtr--] = 'n';
				oldEndPtr--;
			}
			else
			{
				s[newEndPtr--] = s[oldEndPtr--];
			}
		}
		cout << s << endl;
	}
}