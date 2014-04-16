#include <iostream>

int main()
{
	using namespace std;

	const int SIZE = 10;
	double donations[SIZE];
	int length = 0;
	double sum = 0;
	for(int i = 0; i < SIZE; i++)
	{
		if (!(cin >> donations[i]))
			break;
		length++;
		sum += donations[i];
	}

	if (length > 0)
	{
		double avg = sum / length;
		cout << "you input " << length << " double numbers" << endl
			<< "avg number is " << avg << endl;	

		int count = 0;
		for(int i = 0; i < length; i++)
		{
			if (donations[i] > avg)
				count++;
		}
		cout << count << " numbers above the avg number";
	}
	


	return 0;
}