/*#include"iostream"
#include"LinkedList.h"
#include<string>
#include<fstream>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;
void state()
{
	cout << "please choose from following option" << endl;
	cout << "1.Create deck: " << endl;
	cout << "2.Display Deck: " << endl;
	cout << "3.Play: " << endl;
	cout << "4.Quit: " << endl;
}
void readfile(LinkedList<string>&y,vector<string>&z)
{
	ifstream infile;
	string info;
	string x;
	infile.open("deck_small.txt");
	if (y.size() != 0)
	{
		y.clear();
		z.clear();
	}
	if (infile.is_open())
	{
		cout << "open" << endl;
		x.clear();
		while (getline(infile, info))
		{
			z.push_back(info);
			y.insertHead(info);
			z.push_back(info);
			y.insertHead(info);
		}
	}
	else
	{
		cout << "Not open" << endl;
	}

}
void shuffle(LinkedList<string>&y,vector<string>&x)
{
	random_shuffle(x.begin(), x.end());
	y.clear();
	for (int i = 0; i < x.size(); i++)
	{
		y.insertHead(x[i]);
	}
}
void draw(LinkedList<string>&deck1, LinkedList<string>&player1, LinkedList<string>&computer1,int cards)
{
	while()
	{
		int number = 0;
		number = rand() % deck1.size();
		string data = deck1.at(number);
		player1.insertTail(data);
		deck1.remove(data);
		number = rand() % deck1.size();
		data = deck1.at(number);
	}
}
int main()
{
	vector<string>list;
	string currentplayer;
	int playerpoint = 0;
	int computerpoint = 0;
	srand(time(0));
	LinkedList<string> player;
	LinkedList<string> computer;
	LinkedList<string> deck;
	int option = 0;
	while (option != 4)
	{
		state;
		cin >> option;
		while (option < 1 || option>4 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter again" << endl;
			state;
			cin >> option;
		}
		if (option == 1)
		{
			readfile(deck,list);
			cout << deck.size() << endl;
		}
		else if (option == 2)
		{
			shuffle(deck, list);
			for (int i = 0; i < deck.size(); i++)
			{
				cout << deck.at(i) << endl;
			}
		}
		else if (option == 3)
		{
		}
		else
		{

		}
	}

	system("pause");
	return 0;
}*/