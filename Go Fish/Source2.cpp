#include"iostream"
#include<string>
#include<fstream>
#include<ctime>
#include<vector>
#include<algorithm>
#include"gofish.h"
using namespace std;
void state()
{
	cout << "please choose from following option" << endl;
	cout << "1.Create deck" << endl;
	cout << "2.Display Deck" << endl;
	cout << "3.Play" << endl;
	cout << "4.Quit" << endl;
}
void state1()
{
	cout << "1:Make Guess" << endl; 
	cout << "2:Shuffle Desk" << endl;
	cout << "3:Display Desk" << endl;
	cout << "4:Display computer hand" << endl;
	cout << "5:Display Player hand" << endl;
	cout << "6:Give up" << endl;
}
void winner(int play, int computer)
{
	if (play > computer)
	{
		cout << "Winner: You" << endl;
	}
	else
	{
		cout << "Winnder: Computer" << endl;
	}
}
int main()
{
	srand(time(0));
	bool correct = true;
	int option = 0;
	bool game = true;
	int playerpoint = 0;
	int computerpoint = 0;
	gofish card;
	string comcard;
	string input;
	string currenplayer = "player";
	int turn = 0;
	int option1 = 0;
	string cardname;
	string cardtype;
	int cardnum;
	int sizebeg = 6;
	while (option != 4)
	{
		state();
		cin >> option;
		while (option < 1 || option>4 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please enter again" << endl;
			state();
			cin >> option;
		}
		if (option == 1)
		{
			cout << "Enter file name" << endl;
			cin >> input;
			card.readfile(input);
			card.shuffle(); 
		}
		else if (option == 2)
		{
			cout << "Deck: ";
			card.disdeck();
			cout << endl;
		}
		else if (option == 3)
		{
			if (card.decksize() != 0)
			{
				cout << "Please choose initilization size" << endl;
				cin >> sizebeg;
				while (sizebeg < 1 || cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Please Rechoose initilization size" << endl;
					cin >> sizebeg;
				}
				card.dealcard(sizebeg);
				if (card.playsize() == 0 || card.comsize() == 0)
				{
					game = false;
					card.clearall();
					cout << "Please reload the file because one of the player's hand size is 0" << endl;
				}
				else
				{
					game = true;
				}
				playerpoint = 0;
				computerpoint = 0;
				currenplayer = "player";
				while (game == true)
				{
					cout <<"PlayerPoints: "<< playerpoint  << "," <<"Computer Points: "<< computerpoint << endl;
					cout << "Turn: " << currenplayer << endl;
					state1();
					cin >> option1;
					while (option1 < 1 || option1>6|| cin.fail())
					{
						cin.clear();
						cin.ignore(1000, '\n');
						cout << "Please enter again" << endl;
						state1();
						cin >> option1;
					}
					cin.ignore();
					if (option1 == 1)
					{
						if (currenplayer == "player")
						{
							correct = true;
							while (correct == true)
							{
								cout << "Please enter the card name" << endl;
								getline(cin, cardname);
								stringstream ss(cardname);
								if (ss >> cardtype >> cardnum)
								{
									if (card.checkcard(cardname) == true)
									{
										if (card.checkcom(cardname) == true)
										{
											card.removecom(cardname);
											card.removeplay(cardname);
											playerpoint += 1;
										}
										else
										{
											card.drawcard(currenplayer);
											if (card.checkdraw(currenplayer) == true)
											{
												playerpoint += 1;
											}
										}
										currenplayer = "com";
										correct = false;
									}
									else
									{
										cout << "No matched cards on hands" << endl;
										correct == true;
									}
								}
								else
								{
									cout << "Wrong input" << endl;
									correct = true;
								}
							}
						}
						else
						{
							int digit = rand() % card.comsize();
							comcard = card.comcard(digit);
							if (card.checkcard(comcard) == true)
							{
								card.removecom(cardname);
								card.removeplay(cardname);
								computerpoint += 1;
							}
							else
							{
								card.drawcard(currenplayer);
								if (card.checkdraw(currenplayer) == true)
								{
									computerpoint += 1;
								}
							}
							currenplayer = "player";
							correct = false;
						}
						if (card.playsize() == 0 && card.comsize() == 0)
						{
							playerpoint += 3;
							computerpoint += 3;
							game = false;
							card.clearall();
							winner(playerpoint, computerpoint);
						}
						else if (card.playsize() == 0)
						{
							playerpoint += 3;
							game = false;
							card.clearall();
							winner(playerpoint, computerpoint);
						}
						else if (card.comsize() == 0)
						{
							computerpoint += 3;
							game = false;
							card.clearall();
							winner(playerpoint, computerpoint);
						}
					}
					else if (option1 == 2)
					{
						card.shuffle();
					}
					else if (option1 == 3)
					{
						card.disdeck();
						cout << endl;
					}
					else if (option1 == 4)
					{
						card.discomputer();
						cout << endl;
					}
					else if (option1 == 5)
					{
						card.displayer();
						cout << endl;
					}
					else 
					{
						card.clearall();
						game = false;
					}
				}
			}
			else
			{
				cout << "Empty deck" << endl;
			}
		}
	}
	system("pause");
	return 0;
}