#include "String.h"
#include <iostream>

using namespace std;
using namespace String;

void rightHandedString::main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	reverse(s.begin(), s.end());
	reverse(s.begin(), s.begin() + n);
	reverse(s.begin() + n, s.end());
	cout << s << endl;
}