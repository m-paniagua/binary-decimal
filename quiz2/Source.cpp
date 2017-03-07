#include <iostream>
#include <string>

using namespace std;


int main()
{
	string binaryString, continu = "Y";
	int stringLength, counter, decimal, base;

	while (continu == "Y" || continu == "y")
	{
		counter = 0;
		decimal = 0;

		cout << "\nPlease enter a binary string:  and press <ENTER>" << endl;
		getline(cin, binaryString);

		stringLength = binaryString.length();
		

		while (counter < stringLength || stringLength == 0)  //Validates that string entered is comprised only of 1's and 0's
		{
			if (binaryString[counter] != '1' && binaryString[counter] != '0')
			{
				cout << "Input is not a binary string, please try again:\n";
				getline(cin, binaryString);
				stringLength = binaryString.length();
				counter = 0;
			}
			else
			{
				counter++;
			}
		}

		base = pow(2, (stringLength - 1));  //Calculates value for multiplying leftmost char

		for (int x = 0; x < binaryString.size(); x++)  //Begins with leftmost char, continues till it reaches rightmost char 
		{
			
			decimal = decimal + ((binaryString[x] - '0') * base);  //Sets int value of characters by subtracting ASCII value of 0, and multiplying base
			base = base / 2;
		}

		cout << "\nYou entered: " << binaryString << endl;
		cout << "It's base 10 equivalent is: " << decimal << endl;

		cout << "\ny/Y to continue, or any other char to exit: ";
		getline(cin, continu);
	}
	cout << "\nEnd of program" << endl;
	system("pause");
	return 0;
}