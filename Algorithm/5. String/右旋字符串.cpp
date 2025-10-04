// Date: 25/09/25
// Link: https://kamacoder.com/problempage.php?pid=1065

#include "..\Header\String.h" 
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