#include <iostream>
#include <cstring>
#include <climits>

int main()
{
	using namespace std;

	cout << "Enter words (to stop, type the word done):" << endl;
	
	int count = 0;

	while(true)
	{
		char line[80];
		cin.getline(line, 80);

		string word;

		for(int i = 0; i < strlen(line); i++)
		{
			if (line[i] != ' ')
			{
				word = word + line[i];
			}
			else
			{
				if (word == "done")
					break;
				
				count++;
				word = "";
			}
		}
		// left word in line
		if (word == "done")
			break;
		
		count++;
		word = "";
	}

	cout << "Your entered a total of " << count << " words.";

	return 0;
}