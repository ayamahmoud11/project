#include"doner.h"
#include<iostream>
#include<ostream>
#include<string>
#include<vector>
#include<fstream>
#include <ctime>
using namespace std;
doner::doner() {

}
doner::doner(string n, string o, string p, string q, string w, string e, string r, string t, string y, string j) : user(n, o, p, q, w, e, r)
{
	desis = t; otherdises = y; date_of_donation = j;
}
void doner::info()
{
	cout << "Enter your name : ";
	cin.ignore();
	getline(cin, name);

	cout << " " << endl;

	cout << "Enter your id : ";
	getline(cin, id);

	cout << " " << endl;

	cout << "Enter your  email : ";
	getline(cin, email);

	cout << " " << endl;

	cout << "Enter your password : ";
	getline(cin, password);

	cout << " " << endl;

	cout << "Enter your gender : ";
	getline(cin, gender);

	cout << " " << endl;

	cout << "Enter your blood type : ";
	getline(cin, blood_type);

	cout << " " << endl;

	cout << "Do you suffer from any disease (blood preasure disorders , thyroid disease , diabetes , cancer , heart disorder , hepatitis ) ?" << endl;
	getline(cin, desis);

	cout << " " << endl;

	cout << "Do you suffer from any other disease or take medicine ? " << endl;
	getline(cin, otherdises);
	cout << " " << endl;

	cout << "what was the date of your last donation ? " << endl;
	cin >> date_of_donation;
	cout << " " << endl;

	cout << "ENTER your age : ";
	cin >> age;
	cout << " " << endl;
	fstream db;
	db.open("donor.txt", std::ios::in | std::ios::out | std::ios::ate);
	db << name << " " << password << " " << age << " " << email << " " << id << " " << gender << " " << blood_type << " " << desis << " " << otherdises << " " << date_of_donation << "  " << endl;
	db.close();

	option();
}

void doner::login()
{
	string N;
	string P;
	string username;
	string pass;
	int x;
	int y;
	bool v = false;
	int t = 0;
	cout << "PLEASE ENTER YOUR NAME:  " << endl;
	cin.ignore();
	getline(cin, N);
	cout << "PLEASE ENTER YOUR PASSWORD :  " << endl;
	getline(cin, P);
	fstream read("donor.txt");
	string line;
	doner d;
	string q, w, e, m, to, yo, u, n, p, s, jo;
	while (getline(read, q, ' '))
	{
		d.name = q;
		getline(read, w, ' ');
		d.password = w;
		getline(read, m, ' ');
		getline(read, to, ' ');
		getline(read, yo, ' ');
		getline(read, u, ' ');
		getline(read, n, ' ');
		getline(read, p, ' ');
		getline(read, s, ' ');
		getline(read, jo, '\n');

		vec.push_back(d);
	}
	for (int i = 0; i < vec.size(); i++) {
		if (N == vec[i].getname() && P == vec[i].getpass()) {
			t = 1;
		}
	}
	vec.clear();
	if (t == 1)
	{
		option();
	}
	else if (t == 0) {
		cout << "INVALID ACCOUNT DO YOU WANT TO REGISTER?\n";
		cout << "1:Yes\n2:NO\n";
		cin >> y;
		while (y != 2)
		{
			if (y == 1)
			{
				info();
			}
			else
				break;
		}
	}
}
void doner::option() {
	int x;
	cout << "\t\t\t" << "PLEASE PRESS " << endl;
	cout << "1:TO UPDATE YOU ACCOUNT\n2:FO DELETE YOUR ACCOUNT\n3:TO MAKE A DONATION REQUEST\n4:TO REQUEST FOR BEING ADMIN\n5:LOGOUT\n";
	cin >> x;
	while (x != 5)
	{
		if (x == 1)
		{
			updateAccount();
		}
		if (x == 2)
		{
			DeleteAccount();
			break;
		}
		else if (x == 3)
		{
			donationRequest();
		}
		else if (x == 4) {
			adminRequest();
		}
		else {
			cout << "please enter a valid choise";
		}
	}
}
void doner::donationRequest()
{
	string pass;
	doner d;
	vector<doner>vi;
	int answer;
	cout << "\nDo you want to donate ?\n1:yes\n2:no\n " << endl;
	cin >> answer;
	cout << "please enter your password\n";
	cin >> pass;
	cout << " " << endl;
	fstream dd("donor.txt");
	string q, w, e, m, to, yo, u, n, p, s, je;
	while (getline(dd, q, ' '))
	{
		d.name = q;
		getline(dd, w, ' ');
		d.password = w;
		getline(dd, m, ' ');
		d.age = m;
		getline(dd, to, ' ');
		d.email = to;
		getline(dd, yo, ' ');
		d.id = yo;
		getline(dd, u, ' ');
		d.gender = u;
		getline(dd, n, ' ');
		d.blood_type = n;
		getline(dd, p, ' ');
		d.desis = p;
		getline(dd, s, ' ');
		d.otherdises = s;
		getline(dd, je, '\n');
		d.date_of_donation = je;
		vi.push_back(d);
	}
	string dat;
	cout << "WHEN WILL YOU VISIT US?";
	cin >> dat;
	fstream db("donationreq.txt", std::ios::in | std::ios::out | std::ios::ate);
	for (int i = 0; i < vi.size(); i++) {
		if (answer == 1) {
			if (pass == vi[i].getpass()&& vi[i].getotherdesis() == "no")
			{

				db << vi[i].getname() << " " << vi[i].getbloodtype() << " " << dat << endl;
				cout << "YOUR DONATION HAS BEEN ACCEPTED!!\n";
			}
		}
		else
		{
			cout << "Thank you.";
		}
	}
	db.close();
	int sP;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> sP;
	if (sP == 1)
	{
		option();
	}
}
void doner::DeleteAccount()
{
	fstream dd("donor.txt");
	string line;
	string t;
	doner d;
	cout << "-------------------------------------------------------------------\n\n";
	cout << "FOR SURE ENTER YOUR PASSWORD :" << endl;
	cin >> t;
	int l = 0;
	string q, w, m, to, yo, u, n, p, s, je;
	while (getline(dd, q, ' '))
	{
		d.name = q;
		getline(dd, w, ' ');
		d.password = w;
		getline(dd, m, ' ');
		d.age = m;
		getline(dd, to, ' ');
		d.email = to;
		getline(dd, yo, ' ');
		d.id = yo;
		getline(dd, u, ' ');
		d.gender = u;
		getline(dd, n, ' ');
		d.blood_type = n;
		getline(dd, p, ' ');
		d.desis = p;
		getline(dd, s, ' ');
		d.otherdises = s;
		getline(dd, je, '\n');
		d.date_of_donation = je;
		vec.push_back(d);
	}

	for (int i = 0; i < vec.size(); i++) {
		if (t == vec[i].getpass()) {
			vec.erase(vec.begin() + i);
			l = 1;
		}

	}if (l == 1) {

		cout << "ACCOUNT DELETED SUCCESSFULY! " << endl;

	}
	dd.close();
	fstream fill;
	fill.clear();
	fill.open("donor.txt", ios::out);
	for (int i = 0; i < vec.size(); i++) {
		fill << vec[i].getname() << ' ' << vec[i].getpass() << ' ' << vec[i].getage() << ' ' << vec[i].getmail() << ' ' << vec[i].getid() << ' ' << vec[i].getgender() << ' ' << vec[i].getbloodtype() << ' ' << vec[i].getdesis() << ' ' << vec[i].getotherdesis() << ' ' << vec[i].getdonation() << endl;

	}
	fill.close();

}
void doner::updateAccount()
{
	vector<doner>ve;
	fstream update("donor.txt");
	string line;
	string t;
	string id2;
	doner dod;
	cout << "-------------------------------------------------------------------\n\n";
	cout << "For sure enter your password :" << endl;
	cin >> t;
	string n, p, ag, em, i_d, gen, bt, dis, oth, dat, je;
	while (getline(update, n, ' '))
	{
		dod.name = n;
		getline(update, p, ' ');
		dod.password = p;
		getline(update, ag, ' ');
		dod.age = ag;
		getline(update, em, ' ');
		dod.email = em;
		getline(update, i_d, ' ');
		dod.id = i_d;
		getline(update, gen, ' ');
		dod.gender = gen;
		getline(update, bt, ' ');
		dod.blood_type = bt;
		getline(update, dis, ' ');
		dod.desis = dis;
		getline(update, oth, ' ');
		dod.otherdises = oth;
		getline(update, dat, '\n');
		dod.date_of_donation = dat;
		ve.push_back(dod);
	}


	int counter = 0;
	int c;
	for (int i = 0; i < ve.size(); i++) {
		if (t == ve[i].getpass()) {

			cout << "1 to update name \n";
			cout << "2 to update age \n";
			cout << "3 to update email \n";
			cout << "4 to update password\n";
			cout << "5 to update blood type \n";
			cout << "6 to update date of donation \n";
			cout << "7 to update All \n";
			cout << "Enter Option\n";
			cin >> c;
			switch (c) {
			case 1: cout << "Enter Doner Name\n";
				cin.ignore();
				getline(cin, ve[i].name); break;
			case 2:cout << "Enter Doner Age\n";
				cin.ignore();
				getline(cin, ve[i].age); break;
			case 3:cout << "Enter Email\n";
				cin.ignore();
				getline(cin, ve[i].email); break;
			case 4:cout << "Enter password\n";
				cin.ignore();
				getline(cin, ve[i].password); break;
			case 5:cout << "Enter blood type\n";
				cin.ignore();
				getline(cin, ve[i].blood_type); break;
			case 6: cout << "Enter date of donation\n";
				cin.ignore();
				getline(cin, ve[i].date_of_donation); break;
			case 7: cout << "Enter Doner Name\n";
				cin.ignore();
				getline(cin, ve[i].name);
				cout << "Enter Doner Age\n";  getline(cin, ve[i].age);
				cout << "Enter Email\n";  getline(cin, ve[i].email);
				cout << "Enter password\n";  getline(cin, ve[i].password);
				cout << "Enter blood type\n";  getline(cin, ve[i].blood_type);
				cout << "Enter date of donation\n";  getline(cin, ve[i].date_of_donation);
				break;
			}
			counter = 1;
		}
	}
	if (counter == 0) {
		cout << "cannot updated your data\n";
	}
	else { cout << "Updated Successfully\n"; }
	update.close();
	fstream full;
	full.clear();
	full.open("donor.txt", ios::out);
	for (int i = 0; i < ve.size(); i++) {
		full << ve[i].name << ' ' << ve[i].password << ' ' << ve[i].age << ' ' << ve[i].email << ' ' << ve[i].id << ' ' << ve[i].gender << ' ' << ve[i].blood_type << ' ' << ve[i].desis << ' ' << ve[i].otherdises << ' ' << ve[i].date_of_donation << endl;

	}
	full.close();
	ve.clear();
	int sP;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> sP;
	if (sP == 1)
	{
		option();
	}
}
void doner::adminRequest()
{

	fstream dr("donor.txt");
	string p;
	int R = 0;
	doner de;
	string daa, mon, yea;
	cout << "to make sure please enter your password : \n";
	cin >> p;
	string a, b, c, d, f, g, h, k, m;
	while (getline(dr, a, ' '))
	{
		de.name = a;
		getline(dr, b, ' ');
		de.password = b;
		getline(dr, c, ' ');
		de.age = c;
		getline(dr, d, ' ');
		de.email = d;
		getline(dr, f, ' ');
		de.id = f;
		getline(dr, g, ' ');
		de.gender = g;
		getline(dr, h, ' ');
		de.blood_type = h;
		getline(dr, h, ' ');
		de.desis = h;
		getline(dr, k, ' ');
		de.otherdises = k;
		getline(dr, daa, '-');
		getline(dr, mon, '-');
		de.setmonth(mon);
		getline(dr, yea, '\n');
		de.setyear(yea);
		de.setdonation(day, month, year);
		vec.push_back(de);
	}

	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int Month = 1 + newtime.tm_mon;
	int Year = 1900 + newtime.tm_year;


	int mo = 0;
	string na, em, pas, ge, bl, ot, da, dem, dn, ag;

	for (int i = 0; i < vec.size(); i++) {
		if (p == vec[i].getpass()) {
			if (Year == stoi(vec[i].getyear())) {
				mo = Month - stoi(vec[i].getmonth());
			}
			else if (Year > stoi(vec[i].getyear())) {
				mo = Month + (12 - stoi(vec[i].getmonth()));
			}
			if (mo >= 3) {
					if (stoi(vec[i].getage()) >= 17 && stoi(vec[i].getage()) <= 60) {
						if (vec[i].getotherdesis() == "no") {
							na = vec[i].getname(); pas = vec[i].getpass(); em = vec[i].getage(); ge = vec[i].getmail(); bl = vec[i].getid();
							ot = vec[i].getgender(); da = vec[i].getbloodtype(); dn = vec[i].getdesis(); ag = vec[i].getotherdesis(); 
							R = 1;
						}
				}
			}
		}
		fstream RR;
		if (R == 1)
		{
			RR.open("Admin.txt", std::ios::in | std::ios::out | std::ios::ate);
			RR << na << " " << pas << " " << em << " " << ge << " " << bl << " " << ot << " " << da << " " << dn << " " << ag << endl;
			RR.close();

			cout << "now you are an admin! \n";
		}
		else {
			cout << "sorry your request has been rejected\n";
		}
		RR.close();
		dr.close();
		int sP;
		cout << "BACK TO MAIN?\n1:yes\n2:no\n";
		cin >> sP;
		if (sP == 1)
		{
			option();
		}
	}
}
string doner::getname() {
	return name;
}
string doner::getpass() {
	return password;
}
string doner::getbloodtype() {
	return blood_type;
}
string doner::getage() {
	return age;
}
string doner::getid() {
	return id;
}
string doner::getmail() {
	return email;
}
string doner::getgender() {
	return gender;
}
string doner::getdesis() {
	return desis;
}
string doner::getotherdesis() {
	return otherdises;
}
string doner::getdonation() {
	return date_of_donation;
}
void doner::setdonation(string day, string month, string year)
{
	date_of_donation = day + "-" + month + "-" + year;
}
string doner::getmonth() {
	return month;
}
string doner::getyear() {
	return year;
}