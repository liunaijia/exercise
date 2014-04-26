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

		char word[80];
		word[0] = '\0';

		for(int i = 0; i < strlen(line); i++)
		{
			if (line[i] != ' ')
			{
				int len = strlen(word);
				word[len] = line[i];
				word[len + 1] = '\0';
			}
			else
			{
				if (strcmp(word, "done") == 0)
					break;
				
				count++;
				word[0] = '\0';
			}
		}
		// left word in line
		if (strcmp(word, "done") == 0)
			break;
		
		count++;
		word[0] = '\0';
	}

	cout << "Your entered a total of " << count << " words.";

	return 0;
}