#include "recipient_.h"
#include <iostream>
#include <vector>
#include "user.h"
#include<fstream>
using namespace std;
#include <string>
recipient_::recipient_() {

}
recipient_::recipient_(string n, string o, string p, string q, string w, string e, string r, string y, string t) : user(n, o, p, q, w, e, r)
{
	 hospital = y; doc_of_case = t;
}
void recipient_::info()
{
	cout << "Enter recipient name : \n";
	cin.ignore();
	getline(cin, name);

	cout << "Enter recipient mail : \n";
	getline(cin, email);
	cout << "Enter recipient password : \n";
	getline(cin, password);
	cout << "Enter recipient gender (MALE/FEMALE) : \n";
	getline(cin, gender);
	while (gender != "female" && gender != "male") {
		cout << " invalid gender ! \n please try again \n";
		getline(cin, gender);

	}

	cout << "Enter recipient hospital : \n";
	getline(cin, hospital);
	cout << "Enter recipient doctor of the case : \n ";
	getline(cin, doc_of_case);
	cout << "Enter recipient blood type : \n";
	getline(cin, blood_type);
	cout << "Enter recipient id : \n";
	cin >> id;

	cout << "Enter recipient age : \n";
	cin >> age;

	fstream c;
	c.open("recipient.txt", ios::in | ios::out | ios::ate);

	c << name << " " << password << " " << age << " " << email << " " << id << " " << gender << " " << blood_type << " " << doc_of_case << " " << hospital << endl;
	c.close();

	option();
}
void recipient_::login()
{
	string username;
	string pass;
	string N;
	string P;
	int t = 0;
	int y;
	bool v = true;
	cout << "PLEASE ENTER YOUR NAME :" << endl;
	cin.ignore();
	getline(cin, N);
	cout << "PLEASE ENTER YOUR PASSWORD : " << endl;
	getline(cin, P);
	fstream read("recipient.txt");
	string line;
	recipient_ d;
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

		vi.push_back(d);
	}
	for (int i = 0; i < vi.size(); i++) {
		if (N == vi[i].getname() && P == vi[i].getpass()) {
			t = 1;
		}
	}
	vi.clear();
	if (t == 1)
	{
		option();
	}
	else {
		cout << "Invalid account Do you want to register?\n";
		cout << "1:Yes\n2:NO\n";
		cin >> y;
		while (y != 2) {
			if (y == 1)
			{
				info();

			}
			else
				break;
		}
	}
}
void recipient_::option() {
	int x;
	cout << "\t\t\t" << "PLEASE PRESS : " << endl;
	cout << "1:TO UPDAT YOU ACCOUNT\n2:FO DELETE YOUR ACCOUNT\n3:SEARCH FOR BLOOD TYPE\n4:DISPLAY BLOOD TYPE\n5:REQUEST BLOOD TYPE\n6:LOGOUT\n";
	cin >> x;
	while (x != 6)
	{
		if (x == 1)
		{
			updateAccount();
			break;
		}
		else if (x == 2)
		{
			DeleteAccount();
			break;
		}
		else if (x == 3)
		{
			cout << "enter the blood type" << endl;
			string type;
			cin >> type;
			vector<string>data = SearchBloodType("bloodData.txt", type);
			break;
		}
		else if (x == 4) {
			DisplayBloodType();
			break;
		}
		else if (x == 5)
		{
			RequestBloodType();
			break;
		}


	}
}
vector<string> recipient_::SearchBloodType(string file_name, string search_term)
{
	vector <string> record;

	ifstream file;
	file.open("blooddata.txt");


	bool found_record = false;
	string field_one;
	string field_two;
	string field_three;
	string field_four;

	while (getline(file, field_one, ' ') && !found_record) {

		getline(file, field_two, ' ');
		getline(file, field_three, ' ');
		getline(file, field_four, '\n');
		if (field_one == search_term) {
			found_record = true;
			record.push_back(field_one);
			record.push_back(field_two);
			record.push_back(field_three);
			record.push_back(field_four);
		}
	}

	cout << "the blood type:" << "  " << "the quantity : " << "  " << "the recieved date:" << "  " << "the expiry date:" << endl;

	cout << record[0] << " " << record[1] << " " << record[2] << " " << record[3] << endl;



	return record;
	file.close();
	int s;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> s;
	if (s == 1)
	{
		option();
	}

}

void recipient_::DisplayBloodType() {
	ifstream f;
	f.open("blooddata.txt");
	string type;
	int quantity;
	string Rdate;
	string Edate;

	cout << "the blood type:" << "  " << "the quantity : " << "  " << "the recieved date:" << "  " << "the expiry date:" << endl;

	while (f >> type >> quantity >> Rdate >> Edate) 
	{

		cout << type << "                " << quantity << "                  " << Rdate << "                  " << Edate << "           " << endl;
	}

	f.close();
	int s;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> s;
	if (s == 1)
	{
		option();
	}
}
void recipient_::RequestBloodType()
{
	vector<string>v; 
	ifstream f;
	f.open("blooddata.txt");
	string req_type;
	string req_quantity;
	string f1, f2, f3, f4;
	int l = 0;
	string date;
	cout << "Enter the blood type you want: ";
	cin >> req_type;
	cout << "Enter the blood quantity you want: ";
	cin >> req_quantity;
	while (getline(f, f1, ' ') ) {

		getline(f, f2, ' ');
		getline(f, f3, ' ');
		getline(f, f4, '\n');
		if (f1 ==  req_type&&req_quantity<=f2) {
			l = 1;
			v.push_back(f1);
			v.push_back(req_quantity);
			v.push_back(f3);
			v.push_back(f4);
		}
	}
	string rname;
	fstream h; 
	h.open("bloodrequest.txt", std::ios::in | std::ios::out | std::ios::ate);
	if (l==1) {
		cout << "please enter your name:\n";
		cin >> rname;
		cout <<"The request is in processing\n";
		h << rname << " " << req_type<<" " << "processing" << " " << req_quantity << " " << f4 << " " << date << endl;;

	}
	else {
		cout << "sorry there is not enough quantity you can check for it later\n";
	}
	h.close();
	int s;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> s;
	if (s == 1)
	{
		option();
	}
}
void recipient_::DeleteAccount()
{
	fstream dd("recipient.txt");
	string t;
	recipient_ d;
	cout << "-------------------------------------------------------------------\n\n";
	cout << "FOR SURE ENTER YOUR PASSWORD : " << endl;
	cin >> t;
	int l = 0;
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
		d.hospital = p;
		getline(dd, s, '\n');
		d.doc_of_case = s;
		vi.push_back(d);
	}

	for (int i = 0; i < vi.size(); i++) {
		if (t == vi[i].getpass()) {
			vi.erase(vi.begin() + i);
			l = 1;
		}

	}if (l == 1) {

		cout << "ACCOUNT DELETED SUCCESSFULY! " << endl;
	}
	dd.close();
	fstream fill;
	fill.clear();
	fill.open("recipient.txt", ios::out);
	for (int i = 0; i < vi.size(); i++) {
		fill << vi[i].name << ' ' << vi[i].password << ' ' << vi[i].age << ' ' << vi[i].email << ' ' << vi[i].id << ' ' << vi[i].gender << ' ' << vi[i].blood_type<<' ' << vi[i].hospital << ' ' << vi[i].doc_of_case << endl;

	}
	fill.close();

}
void recipient_::updateAccount()
{
	vector< recipient_>vec;
		fstream update("recipient.txt");
		string line;
		string t;
		string id2;
		recipient_ dod;
		cout << "-------------------------------------------------------------------\n\n";
		cout << "FOR SURE ENTER YOUR PASSWORD :" << endl;
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
			dod.hospital = dis;
			getline(update, dat, '\n');
			dod.doc_of_case = dat;
			vec.push_back(dod);
		}


		int counter = 0;
		int c;

		
		for (int i = 0; i < vec.size(); i++) {
			if (t == vec[i].getpass()) {
				cout << "1 to update name \n";
				cout << "2 to update age \n";
				cout << "3 to update email \n";
				cout << "4 to update password\n";
				cout << "5 to update blood type \n";
				cout << "6 to update All \n";
				cout << "Enter Option\n";
				cin >> c;
		    		switch (c)
					{
					case 1: cout << "Enter Name\n";  
						cin.ignore();
						getline(cin, vec[i].name); break;
					case 2:cout << "Enter Age\n";  
						cin.ignore(); 
						getline(cin, vec[i].age); break;
					case 3:cout << "Enter Email\n"; cin.ignore();
						getline(cin, vec[i].email); break;
					case 4:cout << "Enter password\n"; 
						cin.ignore(); 
						getline(cin, vec[i].password); break;
					case 5:cout << "Enter blood type\n";
						cin.ignore(); 
						getline(cin, vec[i].blood_type); break;
					case 6: cout << "Enter Doner Name\n";
						cin.ignore(); 
						getline(cin, vec[i].name);
						cout << "Enter Doner Age\n";  getline(cin, vec[i].age);
						cout << "Enter Email\n";  getline(cin, vec[i].email);
						cout << "Enter password\n";  getline(cin, vec[i].password);
						cout << "Enter blood type\n";  getline(cin, vec[i].blood_type);
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
		full.open("recipient.txt", ios::out);
		for (int i = 0; i < vec.size(); i++) {
			full << vec[i].name << ' ' << vec[i].password << ' ' << vec[i].age << ' ' << vec[i].email << ' ' << vec[i].id << ' ' << vec[i].gender << ' ' <<vec[i].blood_type<< ' ' << vec[i].hospital << ' ' << vec[i].doc_of_case << endl;

		}
		full.close();
		vec.clear();
		int sP;
		cout << "BACK TO MAIN?\n1:yes\n2:no\n";
		cin >> sP;
		if (sP == 1)
		{
			option();
		}
}

string recipient_::getname() {
	return name;
}
string recipient_::getpass() {
	return password;
}
string recipient_::getbloodtype() {
	return blood_type;
}
string recipient_::getage() {
	return age;
}
string recipient_::getid() {
	return id;
}
string recipient_::getmail() {
	return email;
}
string recipient_::getgender() {
	return gender;
}string recipient_::gethospital() {
	return hospital;
}string recipient_::getdoc() {
	return doc_of_case;
}