#pragma once
#include <iostream>
#include <string>
#include "user.h"
#include<vector>

using namespace std;
class doner : public user
{
private:
	string otherdises, date_of_donation;
	string desis, day ,month,year;
public:
	doner();
	doner(string n, string o, string p, string q, string w, string e, string r, string t, string y, string j);
	vector<doner>vec;
	void info();
	void login();
	void option();
	void DeleteAccount();
	void updateAccount();
	void adminRequest();
	void donationRequest();
	string getdesis();
	string getotherdesis();
	string getdonation();
	void setdonation(string day,string month,string year);
	string getname();
	string getpass();
	string getage();
	string getid();
	string getmail();
	string getgender();
	string getbloodtype();
	string getmonth();
	string getyear();
	void setmonth(string m) {
		month = m;
	}
	void setyear(string m) {
		year = m;
	}
};

