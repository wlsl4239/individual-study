#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <sstream>
#include <list>
#include <cmath>
#include <tuple>
#include <cstring>
#include <string.h>
#include <limits>
#include <time.h>
#include <Windows.h>
using namespace std;

int t;



int myhp = 10;
int enemhp = 10;
int mydice = 15;
int enemdice = 15;



void mydiceroll()
{
	int numofdice = 5;
	if (mydice < 5)
		numofdice = mydice;

	int diceresult[6] = { 0,0,0,0,0,0 };
	for (int i = 0;i < numofdice;i++) {
		int num = rand()%6;
		diceresult[num]++;
	}
	mydice -= numofdice;
	cout << "* My turn" << endl;
	cout << "Attack : " << diceresult[3] << " times" << endl;
	cout << "Recovery : " << diceresult[1] << " times" << endl;
	cout << "Return : " << diceresult[0] << " times" << endl;
	cout << "Self-harm : " << diceresult[2] << " times" << endl<<endl;
	
	mydice += diceresult[0];
	mydice += diceresult[1];
	myhp += diceresult[2];
	myhp -= diceresult[3];
	enemhp -= diceresult[4];
	enemhp -= diceresult[5];
}


void enemdiceroll()
{
	int numofdice = 5;
	if (enemdice < 5)
		numofdice = enemdice;
	int diceresult[6] = { 0,0,0,0,0,0 };
	for (int i = 0;i < numofdice;i++) {
		int num = rand() % 6;
		diceresult[num]++;
	}
	enemdice -= numofdice;
	cout << "* Enemy turn" << endl;
	cout << "Attack : " << diceresult[3] << " times" << endl;
	cout << "Recovery : " << diceresult[1] << " times" << endl;
	cout << "Return : " << diceresult[0] << " times" << endl;
	cout << "Self-harm : " << diceresult[2] << " times" << endl;

	enemdice += diceresult[0];
	enemdice += diceresult[1];
	enemhp += diceresult[2];
	enemhp -= diceresult[3];
	myhp -= diceresult[4];
	myhp -= diceresult[5];
}

void gamestart()
{
	int count = 1;
	while (myhp > 0 && mydice > 0 && enemhp > 0 && enemdice > 0)
	{
		cout << "Turn " << count << endl;
		mydiceroll();
		enemdiceroll();
		cout << endl;

		cout << "My HP\t\t: ";
		for (int i = 0;i < myhp;i++)
			cout << "■";
		cout << endl;
		cout << "My Dice\t\t: ";
		for (int i = 0;i < mydice;i++)
			cout << "■";
		cout << endl;
		cout << "Enemy HP\t: ";
		for (int i = 0;i < enemhp;i++)
			cout << "■";
		cout << endl;
		cout << "Enemy Dice\t: ";
		for (int i = 0;i < enemdice;i++)
			cout << "■";
		cout << endl;

		Sleep(2000);
		count++;
		system("cls");
		if ((myhp <= 0 || mydice <= 0) && (enemhp <= 0 || enemdice <= 0))
			cout << "Draw!" << endl;
		else if (myhp <= 0 || mydice <= 0)
			cout << "You Lose!" << endl;
		else if(enemhp <= 0 || enemdice <= 0)
			cout << "You Win!" << endl;

	}
}

int main()
{
	srand(time(NULL));

	cout << "My HP\t\t: ";
	for (int i = 0;i < myhp;i++)
		cout << "■";
	cout << endl;
	cout << "My Dice\t\t: ";
	for (int i = 0;i < mydice;i++)
		cout << "■";
	cout << endl;
	cout << "Enemy HP\t: ";
	for (int i = 0;i < enemhp;i++)
		cout << "■";
	cout << endl;
	cout << "Enemy Dice\t: ";
	for (int i = 0;i < enemdice;i++)
		cout << "■";
	cout << endl;

	Sleep(2000);
	system("cls");
	gamestart();

}

