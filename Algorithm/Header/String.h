#pragma once

#include <vector>
#include <string>

using namespace std;

namespace String
{
	class _151_reverse_words_in_a_string
	{
	private:
		void trim(string& s);
		void reverse(string& s, int left, int right);
	public:
		string main(string s);
	};

	class _344_reverse_string
	{
	public:
		void main(vector<char>& s);
	};

	class _541_reverse_string_ii
	{
	public:
		string main(string s, int k);
	};

	class replaceNumber
	{
	public:
		void main();
	};

	class rightHandedString
	{
	public:
		void main();
	};
}