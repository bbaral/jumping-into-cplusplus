#include <iostream>;
#include <string>;

using namespace std;

string ordinalizeInt(int day);

int main()
{
	for (int i = 1; i <= 12; i++)
	{
		cout << ordinalizeInt(i) << " Day!" << endl;
		cout << "On the " << ordinalizeInt(i) << " day of Christmas my true love sent to me" << endl;

		switch (i)
		{
			case 12:
				cout << "Twelve Drummers Drumming," << endl;
			case 11:
				cout << "Eleven Pipers Piping," << endl;
			case 10:
				cout << "Ten Lords a-Leaping," << endl;
			case 9:
				cout << "Nine Ladies Dancing," << endl;
			case 8:
				cout << "Eight Maids a-Milking," << endl;
			case 7:
				cout << "Seven Swans a-Swimming," << endl;
			case 6:
				cout << "Six Geese a-Laying," << endl;
			case 5:
				cout << "Five Gold Rings," << endl;
			case 4:
				cout << "Four Calling Birds," << endl;
			case 3:
				cout << "Three French Hens," << endl;
			case 2:
				cout << "Two Turtle Doves" << endl;
			case 1:
				if (i == 1)
				{
					cout << "a Partridge in a Pear Tree." << endl;
				}
				else
				{
					cout << "and a Partridge in a Pear Tree." << endl;
				}
		}

		cout << endl;
	}
	cin.get();
}

string ordinalizeInt(int day)
{
	switch (day)
	{
		case 1:
			return "First";
			break;
		case 2:
			return "Second";
			break;
		case 3:
			return "Third";
			break;
		case 4:
			return "Fourth";
			break;
		case 5:
			return "Fifth";
			break;
		case 6:
			return "Sixth";
			break;
		case 7:
			return "Seventh";
			break;
		case 8:
			return "Eigth";
			break;
		case 9:
			return "Ninth";
			break;
		case 10:
			return "Tenth";
			break;
		case 11:
			return "Eleventh";
			break;
		case 12:
			return "Twelvth";
			break;
		default:
			return "";
			break;
	}
}