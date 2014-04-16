#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter words (q to quit):" << endl;

	int vowel, consonant, other;
	vowel = consonant = other = 0;
	string s;
	while(cin >> s)
	{
		if (s == "q")
			break;
		else
		{
			char ch = s[0];
			if (isalpha(ch))
			{
				if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
					vowel++;
				else
					consonant++;
			}
			else
			{
				other++;
			}
		}
	}

	cout << vowel << " words beginning with vowels" << endl
		<< consonant << " words beginning with consonant" << endl
		<< other << " others" << endl;

	return 0;
}