#pragma once
#include<iostream>
using namespace std;
#include<string>
template<class T>
struct node
{
	node<T>*next;
	node<T>*previous;
	T itemtype;
	string cardname;
	int cardnum;

	node(){
		cardname = "";
		cardnum = 0;
		next = NULL;
		previous = NULL;
	}
	~node(){}
};