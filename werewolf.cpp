#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
void decision(string[]);
void place(int[]);
void role1(string[], int[]);
void role2(string[], int[]);

int main()
{
	string player[8];
	//condition 1=idup,0=mati
	int cond[8] = { 1,1,1,1,1,1,1,1 }, x;
	cout << "                                          Werewolf\n\n\n\nYou got the role of :\t";
	srand(time(0));
	x = rand() % 2 + 1;
	if (x == 1)
	{
		cout << "werewolf\n\n";
		player[0] = "werewolf";
	}
	else if (x == 2)
	{
		cout << "Human\n\n";
		player[0] = "Human";
	}
	place(cond);
	decision(player);

	cout << "Day 1 Everyone is Alive \n";
	if (player[0] == "werewolf")
	{
		role1(player, cond);
	}
	else if (player[0] == "Human")
	{
		role2(player, cond);
	}
	system("pause");
	return 0;
}

void role1(string p1[], int c1[])
{
	for (int x = 0; x < 8; x++)
	{
		cout << p1[x] << endl;
	}
	while (true)
	{
		int x = 0, y, n = 7;
		cout << "Night has come please choose which number would you kill : ";
		cin >> x;
		if (p1[x] == "werewolf")
		{
			cout << "cant kill your own kind\n";
			continue;
		}

		else if (c1[x] == 0)
		{
			cout << "You can't kill a dead human dude\n";
			continue;
		}
		else if (x > 0 && x < 8)
		{
			cout << "you have killed a  " << p1[x] << endl;
			c1[x] = 0;
			for (int j = 1; j < 8; j++);
			{
				if (c1[1] == 0 && c1[2] == 0 && c1[3] == 0 && c1[4] == 0 && c1[5] == 0 && c1[6] == 0 && c1[7] == 0)
				{
					cout << endl << "Congratz you killer" << endl;
					break;
				}
			}
			cout << " its morning and the citizen is suprised to see the dead body \n the citizen discussed and chosed that number ";
			while (true)
			{
				y = rand() % 8;
				if (c1[y] != 0)
					break;
			}
			cout << " " << y << " is the culprit" << endl;
			c1[y] = 0;

			if (p1[y] == "werewolf")
				cout << " " << y << " is the werewolf and had been killed\n";
			else if (p1[y] == "Human")
				cout << " " << y << " is a Human and had been killed\n";

			if (y == 0)
			{
				cout << "game over you have been killed XD\n";
				break;
			}
		}
		else
		{
			cout << "Error" << endl;
			continue;
		}
		while (true) //subrole healer
		{
			int chance;
			if ((p1[1] == "healer" && c1[1]) || (p1[2] == "healer" && c1[2]) || (p1[3] == "healer" && c1[3]) || (p1[4] == "healer" && c1[4]) || (p1[5] == "healer" && c1[5]) || (p1[6] == "healer" && c1[6]) || (p1[7] == "healer" && c1[7]))
			{
				chance = rand() % 100 + 1;
				if (chance <= 10 && chance > 0)
				{
					while (true)
					{
						int idup;
						idup = rand() % 8;
						if (c1[idup] == 0)
						{
							c1[idup] = 1;
							cout << idup << " has lived again !" << endl;
							break;
						}
						else
						{
							break;
						}
					}
					break;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		place(c1);
	}
}

void role2(string p1[], int c1[])
{
	for (int x = 0; x < 8; x++)
	{
		cout << p1[x] << endl;
	}
	int k;
	k = rand() % 7 + 1; //karna kalo gk modulus 7 ma tambah 1, werewolfnya diri lu sendiri dan di program gk bisa bunuh diri wow amajing
	p1[k] = "werewolf";
	while (true)
	{
		int y, x;
		while (true)
		{
			y = rand() % 8;
			if (p1[y] == "werewolf")
			{
				continue;
			}
			c1[y] = 0;
				break;
		}
		while (true) //subrole healer
		{
			int chance;
			if ((p1[1] == "healer" && c1[1]) || (p1[2] == "healer" && c1[2]) || (p1[3] == "healer" && c1[3]) || (p1[4] == "healer" && c1[4]) || (p1[5] == "healer" && c1[5]) || (p1[6] == "healer" && c1[6]) || (p1[7] == "healer" && c1[7]))
			{
				chance = rand() % 100 + 1;
				if (chance <= 10 && chance > 0)
				{
					while (true)
					{
						int idup;
						idup = rand() % 8;
						if (c1[idup] == 0)
						{
							c1[idup] = 1;
							cout << idup << " has lived again !" << endl;
							break;
						}
						else
						{
							break;
						}
					}
					break;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		cout << "A werewolf attacked and killed a " << p1[y] << endl;
		c1[y] = 0;
		place(c1);
		//di fungsi role2, x itu buat player human sedangkan y itu untuk werewolf komputer
		if (y == 0)
		{
			cout << " game over you have been killed XD\n";
			break;
		}
		cout << " its morning and the citizen is suprised to see the dead body\nthe citizen discussed and chose a suspect  (input number) " << endl;
		while (true)
		{
			cin >> x;
			if (x == 0)
			{
				cout << "can't kill urself !\n";
				continue;
			}
			else if (x > 0 && x < 8)
			{
				break;
			}
			else if (c1[x] == 0)
			{
				cout << "The dude died, why kill him again ?" << endl;
				continue;
			}
			else
			{
				cout << "Error" << endl;
				continue;
			}
		}
		cout << x << " is the culprit and has been executed" << endl;
		c1[x] = 0;
		if (p1[x] == "werewolf")
		{
			cout << x << " is the werewolf and had been killed\n";
			cout << "Congratz you survived" << endl;
			break;
		}
		else if (p1[x] == "Human")
		{
			cout << x << " is a Human and had been killed\n";
		}
		else if (p1[x] == "healer")
		{
			cout << x << " is a healer and had been killed\n";
		}
		else
		{
			cout << "error" << endl;
			for (int x = 0; x < 7; x++)
			{
				cout << p1[x] << endl;
			}
		}
	}
}


void place(int con[])
{
	for (int n = 0, t = 1; n < 8; n++, t++)
	{
		if (con[n] == 1)
			cout << setw(5) << n;
		else
			cout << setw(5) << 'X';
		if ((t % 4) == 0)
		{
			cout << endl << endl;
		}
	}
}
void decision(string play[])
{
	
	for (int n = 1, x = 0; n < 8; n++)
	{
		x = rand() % 7 + 1;
		if (x == 0)
		{
			continue;
		}
		play[x] = "Human";
	}

	for (int n = 0, x ; n < 1; n++)
	{

		x = rand() % 7 + 1;
		if (play[0] == "werewolf")
		{
			break;
		}
		else
		{
			play[x] = "werewolf";
		}

	}
	for (int y = 1; y < 8; y++)
	{
		if (play[y] != "werewolf" && play[y] != "Human")
		{
			play[y] = "healer";
		}
	}

}