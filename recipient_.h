#pragma once
#include <iostream>
using namespace std;
#include <string>
#include<vector>
#include "user.h"
class recipient_ : public user
{
private:
	string doc_of_case, hospital;
	
public:
	recipient_();
	recipient_(string n, string o, string p, string q, string w, string e, string r, string t, string y);
	vector<recipient_>vi;
	void info();
	void login();
	void option();
	void DeleteAccount();
	void updateAccount();
	string gethospital();
	string getdoc();
	void DisplayBloodType();
	vector<string> SearchBloodType(string file_name, string search_term);
	void RequestBloodType();
	string getname();
	string getpass();
	string getage();
	string getid();
	string getmail();
	string getgender();
	string getbloodtype();
};

