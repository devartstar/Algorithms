// CPP program to check if one number is
// power of other
#include <bits/stdc++.h>
using namespace std;

bool isGreaterThanEqualTo(string s1, string s2)
{
	if (s1.size() > s2.size())
		return true;

	return (s1 == s2);
}

string multiply(string s1, string s2)
{
	int n = s1.size();
	int m = s2.size();

	vector<int> result(n + m, 0);

	// Multiply the numbers. It multiplies
	// each digit of second string to each
	// digit of first and stores the result.
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--)
			result[i + j + 1] +=
			(s1[i] - '0') * (s2[j] - '0');

	// If the digit exceeds 9, add the
	// cumulative carry to previous digit.
	int size = result.size();
	for (int i = size - 1; i > 0; i--) {
		if (result[i] >= 10) {
			result[i - 1] += result[i] / 10;
			result[i] = result[i] % 10;
		}
	}

	int i = 0;
	while (i < size && result[i] == 0)
		i++;

	// if all zeroes, return "0".
	if (i == size)
		return "0";

	string temp;

	// Remove starting zeroes.
	while (i < size) {
		temp += (result[i] + '0');
		i++;
	}
	return temp;
}

// Removes Extra zeroes from front of a string.
string removeLeadingZeores(string s)
{
	int n = s.size();

	int i = 0;
	while (i < n && s[i] == '0')
		i++;

	if (i == n)
		return "0";

	string temp;
	while (i < n)
		temp += s[i++];

	return temp;
}

bool isPower(string s1, string s2)
{
	// Make sure there are no leading zeroes
	// in the string.
	s1 = removeLeadingZeores(s1);
	s2 = removeLeadingZeores(s2);

	if (s1 == "0" || s2 == "0")
		return false;

	if (s1 == "1" && s2 == "1")
		return true;

	if (s1 == "1" || s2 == "1")
		return true;

	// Making sure that s1 is smaller.
	// If it is greater, we recur we
	// reversed parameters.
	if (s1.size() > s2.size())
		return isPower(s2, s1);

	string temp = s1;
	while (!isGreaterThanEqualTo(s1, s2))
		s1 = multiply(s1, temp);

	return s1 == s2;
}

int main()
{
	string s1 = "12", s2 = "144";
	cout << (isPower(s1, s2) ? "YES\n" : "NO\n");

	s1 = "4099", s2 = "2";
	cout << (isPower(s1, s2) ? "YES\n" : "NO\n");

	return 0;
}
