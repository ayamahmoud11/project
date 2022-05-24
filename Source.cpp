#include<iostream>
#include "recipient_.h"
#include "doner.h"
#include<fstream>
#include<vector>
#include "Admin.h"
using namespace std;

int main() {
	doner d;
	recipient_ r;
	Admin ad;
	int i;
	bool a = true;
	cout << "\t\t\t**WELCOME TO BLOOD BANK YOU ARE A-AN**\n1: DONER\n2: RECIPIENT\n3: ADMIN\n";
	cin >> i;
	while (a == true) {
		if (i == 1)
		{
			int x;
			cout << "PRESS \n1:FOR LOGIN\t2:FOR REGISTER\n";
			cin >> x;
			if (x == 1)
			{
				d.login();
				break;
			}
			if (x == 2)
			{
				d.info();
				break;
			}

		}

		else if (i == 2)
		{
			int x;
			cout << "PRESS \n1:FOR LOGIN\t2:FOR REGISTER\n";
			cin >> x;
			if (x == 1)
			{
				r.login();
				break;
			}
			if (x == 2)
			{
				r.info();
				break;
			}
			a = false;
		}
		else if (i == 3) {
			ad.login();
		}
	}
	return 0;
}