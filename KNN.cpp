#include<iostream>
#include<cmath>
#include <windows.h>
using namespace std;

void Color(int color)//to change colour
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int mini(float arr[], int n)
{
	int index;
	int loc = 0;
	float minimum = 1000;
	for (index = 0; index < n; index++) {
		if (arr[index] != -1 && minimum > arr[index])
		{
			minimum = arr[index];
			loc = index;
		}

	}
	arr[loc] = -1;
	return loc;
}

void selectminindex(float arr[], int brr[], int size) {
	for (int index = 0; index < size; index++) {
		brr[index] = mini(arr, size);
	}
}
void copyarray(float arr[], float brr[]) {
	for (int index = 0; index < 15; index++) {
		brr[index] = arr[index];
	}
}
float Euclideandistance(float x1, float x2, float y1, float y2)
{
	float ed = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	return ed;
}

void KNN(int order[15], int label[15], int k)
{
	int  a;
	int bowler = 0, batsman = 0, allrounder = 0;
	for (int i = 0; i < k; i++)
	{
		a = order[i];

		if (label[a] == 0)
		{
			batsman++;
		}
		else if (label[a] == 1)
		{

			bowler++;
		}
		else if (label[a] == 2)
		{
			allrounder++;
		}
		system("CLS");
		Color(10);

		cout << "\n\n\n\n\n\t\t\t\t\t:::::::::::::::::::::::::::::\n";
		cout << "\t\t\t\t\t::";
		Color(6);
		cout << "  K-NEAREST NEIGHBORS";
		Color(2);
		cout << "    ::" << endl;
		cout << "\t\t\t\t\t:::::::::::::::::::::::::::::\n\n\n";
	}
	if (batsman > bowler && batsman > allrounder)
	{
		Color(4);
		cout << "\t\t\t\t\tThe new player is a batsman\n\n\n\n\n\n\n\n\n\n" << endl;
		Color(017);
	}
	if (bowler > batsman && bowler > allrounder)
	{
		Color(3);
		cout << "\t\t\t\t\tThe new player is a bowler\n\n\n\n\n\n\n\n\n\n" << endl;
		Color(017);
	}
	if (allrounder > bowler && allrounder > batsman)
	{
		Color(6);
		cout << "\t\t\t\t\tThe new player is an allrounder\n\n\n\n\n\n\n\n\n\n" << endl;
		Color(017);
	}


}
void display(int x2[15], int y2[15])
{
	Color(10);
	cout << "\t\t\t\t\t\t:::::::::::::::::::::::::::::\n";
	cout << "\t\t\t\t\t\t::";
	Color(6);
	cout << "  K-NEAREST NEIGHBORS";
	Color(2);
	cout << "    ::" << endl;
	cout << "\t\t\t\t\t\t:::::::::::::::::::::::::::::\n";

	cout << "\n\n\n\n        ---------------------------------------------------------------------------------------------------\n";
	Color(6);
	cout << "        \n        \t\t\t\t\t:: PLAYERS BATTING AVERAGE :: " << endl;
	cout << "\t\t\t";

	cout << " | ";
	Color(2);
	for (int i = 0; i < 15; i++)
	{
		cout << x2[i] << " | ";
	}
	cout << "\n\n\n        ---------------------------------------------------------------------------------------------------\n";

	Color(3);
	cout << "\n\n\n\t\t\t\t\t\tPLAYERS BOWLING AVERAGE : " << endl;
	cout << "\t\t\t";

	cout << " | ";

	Color(6);
	for (int i = 0; i < 15; i++)
	{
		cout << y2[i] << " | ";
	}
	cout << "\n\n\n        ---------------------------------------------------------------------------------------------------\n\n\n";
}

int main()
{
	int x1, y1, index, order[15], z, q, k = 5;
	Color(10);

	cout << "\n\n\n\n\n\t\t\t\t\t:::::::::::::::::::::::::::::\n";
	cout << "\t\t\t\t\t::";
	Color(6);
	cout << "  K-NEAREST NEIGHBORS";
	Color(2);
	cout << "    ::" << endl;
	cout << "\t\t\t\t\t:::::::::::::::::::::::::::::\n\n\n";

	Color(4);
	cout << "\t\t\t\t\tMENU:\n" << endl;

	Color(3);
	cout << "\t\t\t\t\tPRESS 1 TO ADD NEW PLAYER DATA: " << endl;
	cout << "\t\t\t\t\tPRESS 2 TO SEE THE DETAILS OF OLD PLAYERS: " << endl;
	cout << "\n\n\t\t\t\t\tEnter Option No: "; cin >> z; cout << endl;



	int label[15] = { 1,2,0,2,2,0,1,1,0,0,2,1,2,1,1 };
	int x2[15] = { 50, 45, 48, 62, 48,15,12,12,25,16,35,34,55,26,31 };
	int y2[15] = { 50,50,58,65,43,21,20,15,12,23,29,26,29,41,28 };
	float ED[15], copyED[15];
	if (z == 1)
	{
		system("CLS");
		cout << "\n\n\n\n\n\t\t\t\t\t:::::::::::::::::::::::::::::\n";
		cout << "\t\t\t\t\t::";
		Color(6);
		cout << "  K-NEAREST NEIGHBORS";
		Color(5);
		cout << "    ::" << endl;
		cout << "\t\t\t\t\t:::::::::::::::::::::::::::::\n\n\n";
		cout << "\t\t\t\t\t::DATA::";
		Color(2);
		cout << "\n\n\n\t\t\t\t\tENTER BATTING AVERAGE OF NEW PLAYER: "; cin >> x1; cout << endl;

		cout << "\t\t\t\t\tENTER BOWLING AVERAGE OF NEW PLAYER: "; cin >> y1; cout << endl;

		cout << "\t\t\t\t\tHOW MANY PLAYER WOULD U LIKE TO USE IN K";
		Color(017);
		cout << "\n\t\t\t\t\t(ODD NUMBER FROM 1  to  15)     :"; cin >> k; cout << endl;

		for (index = 0; index < 15; index++)
		{
			ED[index] = Euclideandistance(x1, x2[index], y1, y2[index]);
		}
	}

	if (z == 2)
	{
		system("CLS");
		display(x2, y2);
		while (1)
		{

			cout << "PRESS 1 TO OPEN MENU" << endl;
			cout << "PRESS 2 TO END PROGRAME" << endl;
			cin >> q;


			if (q == 1)
			{
				system("CLS");
				Color(10);
				cout << "\n\n\n\n\n\t\t\t\t\t\t:::::::::::::::::::::::::::::\n";
				cout << "\t\t\t\t\t\t::";
				Color(6);
				cout << "  K-NEAREST NEIGHBORS";
				Color(2);
				cout << "    ::" << endl;
				cout << "\t\t\t\t\t\t:::::::::::::::::::::::::::::\n";
				Color(4);
				cout << "\n\n\n\t\t\t\t\tMENU:\n" << endl;

				Color(3);
				cout << "\t\t\t\t\tPRESS 1 TO ADD NEW PLAYER DATA: " << endl;
				cout << "\t\t\t\t\tPRESS 2 TO SEE THE DETAILS OF OLD PLAYERS: " << endl;
				cout << "\n\n\t\t\t\t\tEnter Option No: "; cin >> z;

				if (z == 2)
				{
					system("CLS");
					display(x2, y2);
					Color(017);
					break;


				}
				else if (z == 1)
				{
					system("CLS");
					cout << "\n\n\n\n\n\t\t\t\t\t:::::::::::::::::::::::::::::\n";
					cout << "\t\t\t\t\t::";
					Color(6);
					cout << "  K-NEAREST NEIGHBORS";
					Color(5);
					cout << "    ::" << endl;
					cout << "\t\t\t\t\t:::::::::::::::::::::::::::::\n\n\n";
					cout << "\t\t\t\t\t::DATA::";
					Color(2);
					cout << "\n\n\n\t\t\t\t\tENTER BATTING AVERAGE OF NEW PLAYER: "; cin >> x1; cout << endl;

					cout << "\t\t\t\t\tENTER BOWLING AVERAGE OF NEW PLAYER: "; cin >> y1; cout << endl;

					cout << "\t\t\t\t\tHOW MANY PLAYER WOULD U LIKE TO USE IN K";
					Color(017);
					cout << "\n\t\t\t\t\t(ODD NUMBER FROM 1  to  15)     :"; cin >> k; cout << endl;

					for (index = 0; index < 15; index++)
					{
						ED[index] = Euclideandistance(x1, x2[index], y1, y2[index]);
					}
					break;

				}

			}

			else if (q == 2)
				Color(017);
			break;
		}

	}
	if (z == 1)
	{
		copyarray(ED, copyED);


		selectminindex(copyED, order, 15);


		KNN(order, label, k);
	}


}