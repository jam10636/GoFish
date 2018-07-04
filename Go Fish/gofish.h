#pragma once
#include"LinkedList.h"
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class gofish
{
public:
	gofish(){}
	~gofish() {
		clearall();
	}
	void readfile(string name);
	void getsize(int y);
	void shuffle();
	void drawcard(string cur);
	void displayer();
	void discomputer();
	void disdeck();
	void dealcard(int input);
	void clearall();
	bool checkcard(string name);
	bool checkcom(string name);
	void removeplay(string name);
	void removecom(string name);
	bool checkdraw(string cur);
	int comsize();
	int playsize();
	int decksize();
	string comcard(int num);
protected:
	LinkedList<string>x;
	LinkedList<string>player;
	LinkedList<string>computer;
	vector<string>list;
	int count = 0;
	string drawedcard;
	int gamesize = 0;
};
