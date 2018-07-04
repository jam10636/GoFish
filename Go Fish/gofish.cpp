#include"gofish.h"
void gofish::getsize(int y)
{
	gamesize = y;
}
void gofish::readfile(string name)
{
	ifstream infile;
	string info;
	string input;
	infile.open(name);
	if (x.size() != 0)
	{
		x.clear();
		player.clear();
		computer.clear();
		list.clear();
		count = 0;
	}
	if (infile.is_open())
	{
		int r = 0;
		string e;
		int w;
		while (getline(infile, info))
		{
			stringstream ss(info);
			if (ss>>e>>w)
			{
				x.insertHead(info);
				x.insertHead(info);
			}
		}
	}
	else
	{
		cout << "Not open" << endl;
	}
}
void gofish::shuffle()
{
	list.clear();
	for (int i = 0; i < x.size(); i++)
	{
		list.push_back(x.at(i));
	}
	random_shuffle(list.begin(), list.end());
	x.clear();
	for (int i = 0; i < list.size(); i++)
	{
		x.insertHead(list[i]);
	}
}
void gofish::drawcard(string cur)
{
	string data;
	int number = 0;
	if (cur == "player")
	{
		if (x.size() != 0)
		{
			number = rand() % x.size();
			data = x.at(number);
			player.insertTail(data);
			x.remove(data);
			drawedcard = data;
		}
		else
		{
			drawedcard = "";
		}
	}
	else
	{
		if (x.size() != 0)
		{
			number = rand() % x.size();
			data = x.atback(number);
			computer.insertTail(data);
			x.remove(data);
			drawedcard = data;
		}
		else
		{
			drawedcard = "";
		}
	}
}
void gofish::dealcard(int input)
{
	string data;
	vector<string>play;
	vector<string>comp;
	while (x.size() != 0 && count <input)
	{
		int number = 0;
		number = rand() % x.size();
		data = x.at(number);
		player.insertTail(data);
		x.remove(data);
		number = rand() % x.size();
		data = x.atback(number);
		computer.insertTail(data);
		x.remove(data);
		count++;
	}
	for (int i = 0; i < player.size(); i++)
	{
		play.push_back(player.at(i));
	}
	for (int i = 0; i < computer.size(); i++)
	{
		comp.push_back(computer.at(i));
	}
	sort(play.begin(), play.end());
	sort(comp.begin(), comp.end());
	int u = 0;
	vector<string>dubplay;
	vector<string>dubcom;
	for (int i = 0; i < play.size() - 1; i++)
	{
		if (play[u] == play[u + 1])
		{
			play[u] = "x";
			play[u + 1] = "x";
		}
		u++;
	}
	u = 0;
	for (int i = 0; i < comp.size()-1; i++)
	{
		if (comp[u] == comp[u + 1])
		{
			comp[u] = "x";
			comp[u + 1] = "x";
		}
		u++;
	}
	for (int i = 0; i < play.size(); i++)
	{
		if (play[i] != "x")
		{
			dubplay.push_back(play[i]);
		}
	}
	for (int i = 0; i < comp.size(); i++)
	{
		if (comp[i] != "x")
		{
			dubcom.push_back(comp[i]);
		}
	}
	player.clear();
	computer.clear();
	for (int i = 0; i < dubplay.size(); i++)
	{
		player.insertTail(dubplay[i]);
	}
	for (int i = 0; i < dubcom.size(); i++)
	{
		computer.insertTail(dubcom[i]);
	}
	/*for (int i = 0; i < dubplay.size(); i++)
	{
		player.remove(dubplay[i]);
		player.remove(dubplay[i]);
	}
	for (int i = 0; i < dubcom.size(); i++)
	{
		computer.remove(dubcom[i]);
		computer.remove(dubcom[i]);
	}*/
	count = 0;
}//fix this part
void gofish::disdeck()
{
	if (x.size() == 0)
	{
		cout << "empty";
	}
	for (int i = 0; i<x.size(); i++)
	{
		if (i != x.size() - 1)
		{
			cout << x.at(i) << ", ";
		}
		else
		{
			cout << x.at(i);
		}
	}
}
void gofish::discomputer()
{
	if (computer.size() == 0)
	{
		cout << "empty" << endl;
	}
	else
	{
		for (int i = 0; i < computer.size(); i++)
		{
			if (i != computer.size() - 1)
			{
				cout << computer.at(i) << ", ";
			}
			else
			{
				cout << computer.at(i);
			}
		}
	}
}
void gofish::displayer()
{
	if (player.size() == 0)
	{
		cout << "empty" << endl;
	}
	else
	{
		for (int i = 0; i < player.size(); i++)
		{
			if (i != player.size() - 1)
			{
				cout << player.at(i) << ", ";
			}
			else
			{
				cout << player.at(i);
			}
		}
	}
} 
bool gofish::checkcard(string name)
{
	if (player.check(name) == false)
	{
		return true;
	}
	return false;
}
bool gofish::checkcom(string name)
{
	if (computer.check(name) == false)
	{
		return true;
	}
	return false;
}
void gofish::clearall()
{
	player.clear();
	computer.clear();
	x.clear();
}
void gofish::removeplay(string name)
{
	player.remove(name);
}
void gofish::removecom(string name)
{
	computer.remove(name);
}
bool gofish::checkdraw(string cur)
{
	int dup = 0;
	string item = drawedcard;
	if (cur == "player")
	{
		for (int i = 0; i < player.size(); i++)
		{
			if (player.at(i) == item)
			{
				dup++;
			}
		}
		if (dup == 2)
		{
			player.remove(drawedcard);
			player.remove(drawedcard);
			return true;
		}
		return false;
	}
	else
	{
		for (int i = 0; i < computer.size();i++)
		{
			if (computer.at(i) == item)
			{
				dup++;
			}
		}
		if (dup == 2)
		{
			computer.remove(drawedcard);
			computer.remove(drawedcard);
			return true;
		}
		return false;
	}
}
int gofish::comsize()
{
	return computer.size();
}
int gofish::playsize()
{
	return player.size();
}
int gofish::decksize() 
{
	return x.size();
}
string gofish::comcard(int num)
{
	return computer.at(num);
}