#include "Admin.h"
#include <string>
#include <iostream>
#include<vector>
#include<fstream>
#include"doner.h"
#include"recipient_.h"
using namespace std;

void Admin::doner_info()
{
	cout << "Enter doner's name : ";
	cin.ignore();
	getline(cin, name);
	cout << " " << endl;

	cout << "Enter doner's id : ";
	getline(cin, id);
	cout << " " << endl;

	cout << "Enter doner's  email : ";
	getline(cin, email);
	cout << " " << endl;

	cout << "Enter doner's password : ";
	getline(cin, password);
	cout << " " << endl;

	cout << "Enter doner's gender : ";
	cin.ignore();
	getline(cin, gender);
	cout << " " << endl;

	cout << "Enter doner's blood type : ";
	cin.ignore();
	getline(cin, blood_type);
	cout << " " << endl;

	cout << "Does the doner suffer from any disease (blood preasure disorders , thyroid disease , diabetes , cancer , heart disorder , hepatitis ) ?" << endl;
	getline(cin, desis);
	cout << " " << endl;

	cout << "Does the doner suffer from any other disease or take medicine ? " << endl;
	getline(cin, otherdises);
	cout << " " << endl;

	cout << "what was the date of doner's last donation ? " << endl;
	cin >> date_of_donation;
	cout << " " << endl;

	cout << "ENTER doner's age : ";
	cin >> age;
	cout << " " << endl;
	fstream db;
	db.open("donor.txt", std::ios::in | std::ios::out | std::ios::ate);
	db << name << " " << password << " " << age << " " << email << " " << id << " " << gender << " " << blood_type << " " << desis << " " << otherdises << " " << date_of_donation << "  " << endl;
	db.close();
	int s;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> s;
	if (s == 1)
	{
		option();
	}
}

void Admin::recip_info()
{

	cout << "Enter recipient name : \n";
	cin.ignore();
	getline(cin, name);
	cout << " " << endl;

	cout << "Enter recipient mail : \n";
	getline(cin, mail);
	cout << " " << endl;

	cout << "Enter recipient password : \n";
	getline(cin, password);
	cout << " " << endl;

	cout << "Enter recipient gender (MALE/FEMALE) : \n";
	getline(cin, gender);
	while (gender != "female" && gender != "male") {
		cout << " invalid gender ! \n please try again \n";
		getline(cin, gender);
	}
	cout << " " << endl;

	cout << "Enter recipient hospital : \n";
	getline(cin, hospital);
	cout << " " << endl;

	cout << "Enter recipient doctor of the case : \n ";
	getline(cin, doc_of_case);
	cout << " " << endl;

	cout << "Enter recipient blood type : \n";
	getline(cin, blood_type);
	cout << " " << endl;

	cout << "Enter recipient id : \n";
	getline(cin, id);
	cout << " " << endl;

	cout << "Enter recipient age : \n";
	cin >> age;
	cout << " " << endl;
	fstream c;
	c.open("recipient.txt", ios::in | ios::out | ios::ate);

	c << name << " " << password << " " << age << " " << mail << " " << id << " " << gender << " " << blood_type << " " << doc_of_case << " " << hospital << endl;
	c.close();
	int s;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> s;
	if (s == 1)
	{
		option();
	}

}

void Admin::blod_type()
{
	cout << "enter the blood type please : " << endl;
	cin >> blood_type;
	cout << " " << endl;
	cout << "enter the blood quantity please : " << endl;
	cin >> quantity;
	cout << " " << endl;
	cout << "enter the donation date please : " << endl;
	cin >> startdate;
	cout << " " << endl;
	cout << "enter the expire date please : " << endl;
	cin >> expiredate;
	cout << " " << endl;
	fstream file;
	file.open("blooddata.txt", ios::in | ios::out | ios::ate);

	file << blood_type << " " << quantity << " " << startdate << " " << expiredate << endl;
	file.close();
	int s;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> s;
	if (s == 1)
	{
		option();
	}

}
void Admin::updatedoner()
{
	fstream dd("donor.txt");
	vector<doner>kk;
	string t;
	cout << "-------------------------------------------------------------------\n\n";
	cout << "ENTER DONER`S NAME YOU WANT TO UPDATE :" << endl;
	cin >> t;
	int l = 0;
	string q, w, e, m, to, yo, u, n, p, s, je;
	while (getline(dd, q, ' '))
	{

		getline(dd, w, ' ');
		getline(dd, m, ' ');
		getline(dd, to, ' ');
		getline(dd, yo, ' ');
		getline(dd, u, ' ');
		getline(dd, n, ' ');
		getline(dd, p, ' ');
		getline(dd, s, ' ');
		getline(dd, je, '\n');
		doner d(q, w, m, to, yo, u, n, p, s, je);
		kk.push_back(d);
	}
	string dt, mt, yt;

	int counter = 0;
	int c;
	for (int i = 0; i < kk.size(); i++) {
		if (t == kk[i].getname()) {

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
				getline(cin, kk[i].name); break;
			case 2:cout << "Enter Doner Age\n";
				cin.ignore();
				getline(cin, kk[i].age); break;
			case 3:cout << "Enter Email\n";
				cin.ignore();
				getline(cin, kk[i].email); break;
			case 4:cout << "Enter password\n";
				cin.ignore();
				getline(cin, kk[i].password); break;
			case 5:cout << "Enter blood type\n";
				cin.ignore();
				getline(cin, kk[i].blood_type); break;
			case 6: cout << "Enter date of donation\n";
				cin.ignore();
				cin >> dt >> mt >> yt;
				kk[i].setdonation(dt, mt, yt); break;
			case 7: cout << "Enter Doner Name\n";
				cin.ignore();
				getline(cin, kk[i].name);
				cout << "Enter Doner Age\n";  getline(cin, kk[i].age);
				cout << "Enter Email\n";  getline(cin, kk[i].email);
				cout << "Enter password\n";  getline(cin, kk[i].password);
				cout << "Enter blood type\n";  getline(cin, kk[i].blood_type);
				cout << "Enter date of donation\n";  string dt, mt, yt;
				cin >> dt >> mt >> yt;
				kk[i].setdonation(dt, mt, yt);;
				break;
			}
			counter = 1;
		}
	}
	if (counter == 0) {
		cout << "cannot updated your data\n";
	}
	else { cout << "Updated Successfully\n"; }
	dd.close();
	fstream full;
	full.clear();
	full.open("donor.txt", ios::out);
	for (int i = 0; i < kk.size(); i++) {
		full << kk[i].name << ' ' << kk[i].password << ' ' << kk[i].age << ' ' << kk[i].email << ' ' << kk[i].id << ' ' << kk[i].gender << ' ' << kk[i].blood_type << ' ' << kk[i].getdesis() << ' ' << kk[i].getotherdesis() << ' ' << kk[i].getdonation() << endl;

	}
	full.close();
	kk.clear();
	int sP;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> sP;
	if (sP == 1)
	{
		option();
	}
}
void Admin::updaterecipient()
{
	fstream dd("recipient.txt");
	vector<recipient_>kk;
	string line;
	string t;

	cout << "-------------------------------------------------------------------\n\n";
	cout << "ENTER RECIPIENT`S NAME YOU WANT TO DELETE :" << endl;
	cin >> t;
	int l = 0;
	string q, w, m, to, yo, u, n, p, s;
	while (getline(dd, q, ' '))
	{

		getline(dd, w, ' ');
		getline(dd, m, ' ');
		getline(dd, to, ' ');
		getline(dd, yo, ' ');
		getline(dd, u, ' ');
		getline(dd, n, ' ');
		getline(dd, p, ' ');
		getline(dd, s, '\n');
		recipient_ d(q, w, m, to, yo, u, n, p, s);
		kk.push_back(d);
	}
	int c, counter = 0;
	for (int i = 0; i < kk.size(); i++)
	{
		if (t == kk[i].getname()) {
			cout << "1 to update name \n";
			cout << "2 to update age \n";
			cout << "3 to update email \n";
			cout << "4 to update password\n";
			cout << "5 to update blood type \n";
			cout << "6 to update All \n";
			cout << "Enter Option\n";
			cin >> c;
			switch (c) {
			case 1: cout << "Enter Doner Name\n";
				cin.ignore();
				getline(cin, kk[i].name); break;
			case 2:cout << "Enter Doner Age\n";
				cin.ignore();
				getline(cin, kk[i].age); break;
			case 3:cout << "Enter Email\n";
				cin.ignore();
				getline(cin, kk[i].email); break;
			case 4:cout << "Enter password\n";
				cin.ignore();
				getline(cin, kk[i].password); break;
			case 5:cout << "Enter blood type\n";
				cin.ignore();
				getline(cin, kk[i].blood_type); break;
			case 6: cout << "Enter Doner Name\n";
				cin.ignore();
				getline(cin, kk[i].name);
				cout << "Enter Doner Age\n";  getline(cin, kk[i].age);
				cout << "Enter Email\n";  getline(cin, kk[i].email);
				cout << "Enter password\n";  getline(cin, kk[i].password);
				cout << "Enter blood type\n";  getline(cin, kk[i].blood_type);
				break;
			}
			counter = 1;
		}
	}
	if (counter == 0)
	{
		cout << "cannot updated your data\n";
	}
	else { cout << "Updated Successfully\n"; }
	dd.close();
	fstream full;
	full.clear();
	full.open("recipient.txt", ios::out);
	for (int i = 0; i < kk.size(); i++) {
		full << kk[i].name << ' ' << kk[i].password << ' ' << kk[i].age << ' ' << kk[i].email << ' ' << kk[i].id << ' ' << kk[i].gender << ' ' << kk[i].blood_type << ' ' << kk[i].gethospital() << ' ' << kk[i].getdoc() << endl;

	}
	full.close();
	kk.clear();
	int sP;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> sP;
	if (sP == 1)
	{
		option();
	}
}
void Admin::updateblooddata()
{
	fstream f("blooddata.txt");;
	vector<Blood>v;
	string f1, f2, f3, f4, b;
	int lo = 0;
	string ntype, nqua, sdat, ndat;

	cout << "ENTER THE BLOOD TYPE YOU WANT TO UPDATE: ";
	cin >> b;
	while (getline(f, f1, ' '))
	{
		getline(f, f2, ' ');
		getline(f, f3, ' ');
		getline(f, f4, '\n');
		Blood blood(f1, f2, f3, f4);
		v.push_back(blood);
	}
	int c;
	for (int i = 0; i < v.size(); i++) {
		if (b == v[i].getbloodtype()) {
			cout << "1 :TO UPDATE BLOOD TYPE \n";
			cout << "2 :TO UPDATE BLOOD QUANTITY \n";
			cout << "3 :TO UPDATE BLOOD START DATE \n";
			cout << "4 :TO UPDATE BLOOD EXPIRE DATE\n";
			cout << "5 update all\n";
			cin >> c;
			switch (c) {

			case 1:
				cout << "ENTER THE NEW BLOOD TYPE\n";
				cin >> ntype; v[i].settype(ntype); break;
			case 2:
				cout << "ENTER THE NEW BLOOD QUANTITY\n";
				cin >> nqua; v[i].setquantity(nqua); break;
			case 3:
				cout << "ENTER THE NEW BLOOD START DATE\n";
				cin >> sdat; v[i].setsdate(sdat); break;
			case 4:
				cout << "ENTER THE NEW EXPIRE DATE\n";
				cin >> ndat; v[i].setedate(ndat); break;
			case 5:
				cout << "ENTER THE NEW BLOOD QUANTITY\n";
				cin >> ntype; v[i].settype(ntype); cout << "ENTER THE NEW BLOOD QUANTITY";
				cin >> nqua; v[i].setquantity(nqua);
				cout << "ENTER THE NEW BLOOD START DATE";
				cin >> sdat; v[i].setsdate(sdat);
				cout << "ENTER THE NEW EXPIRE DATE";
				cin >> ndat; v[i].setedate(ndat);
				break;
			}
			lo = 1;
		}
	}
	if (lo == 1) {
		cout << "UPDATED SUCCESSFULY\n";
	}
	f.close();
	fstream fill;
	fill.clear();
	fill.open("blooddata.txt", ios::out);
	for (int i = 0; i < v.size(); i++)
	{
		fill << v[i].getbloodtype() << ' ' << v[i].getbloodquan() << ' ' << v[i].getbloodsdate() << ' ' << v[i].getbloodedate() << endl;
	}
	fill.close();
	int s;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> s;
	if (s == 1)
	{
		option();
	}
}
void Admin::updatebloodreq()
{
	fstream f("bloodrequest.txt");;
	vector<Blood>sp;
	string f1, f2, f3, f4, f5, t;
	string ntype, nqua, n_dat;
	cout << "PLEASE ENTER THE NAME REQUEST : ";
	cin >> t;
	while (getline(f, f1, ' '))
	{
		getline(f, f2, ' ');
		getline(f, f3, ' ');
		getline(f, f4, ' ');
		getline(f, f5, '\n');
		Blood ou(f1, f2, f3, f4, f5);
		sp.push_back(ou);
	}
	int c = 0, ll;
	for (int i = 0; i < sp.size(); i++)
	{
		if (t == sp[i].getrecipientsname()) {
			cout << "1:UPDATE ALL \n2:PUT RECIVING DATE\n";
			cin >> ll;
			if (ll == 1) {
				cout << "ENTER THE NEW REQUIRED BLOOD TYPE : \n";
				cin >> ntype;
				cout << "ENTER THE NEW QUANTITY\n"; cin >> nqua;
				cout << "ENTER THE NEW RECIVING DATE \n"; cin >> n_dat;
				sp[i].settype(ntype);
				sp[i].setquantity(nqua);
				sp[i].setredate(n_dat);
			}
			if (ll == 2)
			{
				cout << "ENTER THE RECIVING DATE \n";
				cin >> n_dat;
				sp[i].setredate(n_dat);
			}
			c = 1;
		}
	}
	if (c == 1) {
		cout << "UPDATED SUCCESSFULY\n";
	}
	f.close();
	fstream fill;
	fill.clear();
	fill.open("bloodrequest.txt", ios::out);
	for (int i = 0; i < sp.size(); i++)
	{
		fill << sp[i].getrecipientsname() << ' ' << sp[i].getbloodtype() << ' ' << sp[i].getdarecieve() << ' ' << sp[i].getbloodquan() << ' ' << sp[i].getbloodedate() << endl;
	}
	fill.close();
	int s;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> s;
	if (s == 1)
	{
		option();
	}
}
void Admin::deletedoner()
{
	fstream dd("donor.txt");
	vector<doner>kk;
	string t;
	cout << "-------------------------------------------------------------------\n\n";
	cout << "ENTER DONER`S NAME YOU WANT TO DELETE :" << endl;
	cin >> t;
	int l = 0;
	string q, w, e, m, to, yo, u, n, p, s, je;
	while (getline(dd, q, ' '))
	{

		getline(dd, w, ' ');
		getline(dd, m, ' ');
		getline(dd, to, ' ');
		getline(dd, yo, ' ');
		getline(dd, u, ' ');
		getline(dd, n, ' ');
		getline(dd, p, ' ');
		getline(dd, s, ' ');
		getline(dd, je, '\n');
		doner d(q, w, m, to, yo, u, n, p, s, je);
		kk.push_back(d);
	}

	for (int i = 0; i < kk.size(); i++)
	{
		if (t == kk[i].getname()) {
			kk.erase(kk.begin() + i);
			l = 1;
		}

	}if (l == 1)
	{

		cout << "account deleted successfully " << endl;
	}
	dd.close();
	fstream fill;
	fill.clear();
	fill.open("donor.txt", ios::out);
	for (int i = 0; i < kk.size(); i++) {
		fill << kk[i].getname() << ' ' << kk[i].getpass() << ' ' << kk[i].getage() << ' ' << kk[i].getmail() << ' ' << kk[i].getid() << ' ' << kk[i].getgender() << ' ' << kk[i].getbloodtype() << ' ' << kk[i].getdesis() << ' ' << kk[i].getotherdesis() << ' ' << kk[i].getdonation() << endl;

	}
	fill.close();
	int sP;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> sP;
	if (sP == 1)
	{
		option();
	}
}
void Admin::deleterecipient()
{
	fstream dd("recipient.txt");
	vector<recipient_>kk;
	string line;
	string t;

	cout << "-------------------------------------------------------------------\n\n";
	cout << "ENTER RECIPIENT`S NAME YOU WANT TO DELETE :" << endl;
	cin >> t;
	int l = 0;
	string q, w, m, to, yo, u, n, p, s;
	while (getline(dd, q, ' '))
	{

		getline(dd, w, ' ');
		getline(dd, m, ' ');
		getline(dd, to, ' ');
		getline(dd, yo, ' ');
		getline(dd, u, ' ');
		getline(dd, n, ' ');
		getline(dd, p, ' ');
		getline(dd, s, '\n');
		recipient_ d(q, w, m, to, yo, u, n, p, s);
		kk.push_back(d);
	}

	for (int i = 0; i < kk.size(); i++)
	{
		if (t == kk[i].getname()) {
			kk.erase(kk.begin() + i);
			l = 1;
		}

	}if (l == 1)
	{

		cout << "account deleted successfully " << endl;
	}
	dd.close();
	fstream fill;
	fill.clear();
	fill.open("recipient.txt", ios::out);
	for (int i = 0; i < kk.size(); i++) {
		fill << kk[i].getname() << ' ' << kk[i].getpass() << ' ' << kk[i].getage() << ' ' << kk[i].getmail() << ' ' << kk[i].getid() << ' ' << kk[i].getgender() << ' ' << kk[i].getbloodtype() << ' ' << kk[i].gethospital() << ' ' << ' ' << kk[i].getdoc() << endl;

	}
	fill.close();
	int sP;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> sP;
	if (sP == 1)
	{
		option();
	}
}
void Admin::deleteblooddata()
{
	fstream f("blooddata.txt");;
	vector<Blood>v;
	string f1, f2, f3, f4, b;
	int lo = 0;
	string date;
	cout << "ENTER THE BLOOD TYPE YOU WANT TO DELETE: ";
	cin >> b;
	while (getline(f, f1, ' '))
	{
		getline(f, f2, ' ');
		getline(f, f3, ' ');
		getline(f, f4, '\n');
		Blood blood(f1, f2, f3, f4);
		v.push_back(blood);
	}
	for (int i = 0; i < v.size(); i++) {
		if (b == v[i].getbloodtype()) {
			v[i].setquantity("0");
			v[i].setsdate("0");
			v[i].setedate("0");
			lo = 1;
		}
	}
	if (lo == 1) {
		cout << "deleted successfully\n";
	}
	f.close();
	fstream fill;
	fill.clear();
	fill.open("blooddata.txt", ios::out);
	for (int i = 0; i < v.size(); i++)
	{
		fill << v[i].getbloodtype() << ' ' << v[i].getbloodquan() << ' ' << v[i].getbloodsdate() << ' ' << v[i].getbloodedate() << endl;
	}
	fill.close();
	int s;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> s;
	if (s == 1)
	{
		option();
	}
}
void Admin::deletedonerrec()
{
	fstream f("donationreq.txt");;
	vector<Blood>sp;
	string f1, f2, f3;
	int lo = 0;
	string na;
	cout << "ENTER THE NAME OF THE REQUEST YOU WANT TO DELETE:  ";
	cin >> na;
	while (getline(f, f1, ' '))
	{
		getline(f, f2, ' ');
		getline(f, f3, '\n');
		Blood b(f1, f2, f3);
		sp.push_back(b);
	}
	for (int i = 0; i < sp.size(); i++) {
		if (na == sp[i].getrecipientsname())
		{
			sp.erase(sp.begin() + i);
			lo = 1;
		}
	}
	if (lo == 1) {
		cout << "DELETED SUCCESSFULY\n";
	}
	f.close();
	fstream fill;
	fill.clear();
	fill.open("donationreq.txt", ios::out);
	for (int i = 0; i < sp.size(); i++)
	{
		fill << sp[i].getrecipientsname() << ' ' << sp[i].getbloodtype() << ' ' << sp[i].getdarecieve() << endl;
	}
	fill.close();

	int s;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> s;
	if (s == 1)
	{
		option();
	}
}
void Admin::deletebloodreq()
{
	fstream f("bloodrequest.txt");;
	vector<Blood>sp;
	Admin ll;
	string f1, f2, f3, f4, f5;
	int lo = 0;
	string na;
	cout << "ENTER THE NAME OF THE REQUEST YOU WANT TO DELETE:  ";
	cin >> na;
	while (getline(f, f1, ' '))
	{
		getline(f, f2, ' ');
		getline(f, f3, ' ');
		getline(f, f4, ' ');
		getline(f, f5, '\n');
		Blood b(f1, f2, f3, f4, f5);
		sp.push_back(b);
	}
	for (int i = 0; i < sp.size(); i++) {
		if (na == sp[i].getrecipientsname())
		{
			sp.erase(sp.begin() + i);
			lo = 1;
		}
	}
	if (lo == 1) {
		cout << "DELETED SUCCESSFULY\n";
	}
	f.close();
	fstream fill;
	fill.clear();
	fill.open("bloodrequest.txt", ios::out);
	for (int i = 0; i < sp.size(); i++)
	{
		fill << sp[i].getrecipientsname() << ' ' << sp[i].getbloodtype() << ' ' << sp[i].getbloodquan() << ' ' << sp[i].getbloodedate() << ' ' << sp[i].getdarecieve() << endl;
	}
	fill.close();
	int s;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> s;
	if (s == 1)
	{
		option();
	}
}
void Admin::displayuser()
{
	cout << "you want to display\n1)donor " << endl << "2)recipient\n ";

	int opt;
	
	cin >> opt;
	if (opt == 1) {
		string n, p, ag, em, i_d, gen, bt, dis, oth, dat, je;
		vector<doner>ve;
		fstream ff("donor.txt");
		while (getline(ff, n, ' '))
		{
			getline(ff, p, ' ');
			getline(ff, ag, ' ');
			getline(ff, em, ' ');
			getline(ff, i_d, ' ');
			getline(ff, gen, ' ');
			getline(ff, bt, ' ');
			getline(ff, dis, ' ');
			getline(ff, oth, ' ');
			getline(ff, dat, '\n');
			doner dod(n, p, ag, em, i_d, gen, bt, dis, oth, dat);
			ve.push_back(dod);
		}
		for (int i = 0; i < ve.size(); i++) {
			cout << "Name : " << ve[i].getname() << "  " << "password : " << ve[i].getpass() << "  "  << "age : " << ve[i].getage() << "  "  << "email : " << ve[i].getmail() << "  "  << "id : " << ve[i].getid() << "  "  << "gender : " << ve[i].getgender() << "  " ;
			cout << "blood type : " << ve[i].getbloodtype() << "  "  << "desis : " << ve[i].getdesis() << "  "  << "other dises : " << ve[i].getotherdesis() << "  "  << "date of donation : " << ve[i].getdonation() << endl;
		}
		ff.close();
	}
	else if (opt == 2) {
		fstream dd("recipient.txt");
		vector<recipient_> v;
		string q, w, m, to, yo, u, n, p, s;
		while (getline(dd, q, ' '))
		{

			getline(dd, w, ' ');
			getline(dd, m, ' ');
			getline(dd, to, ' ');
			getline(dd, yo, ' ');
			getline(dd, u, ' ');
			getline(dd, n, ' ');
			getline(dd, p, ' ');
			getline(dd, s, '\n');
			recipient_ d(q, w, m, to, yo, u, n, p, s);
			v.push_back(d);
		}
		for (int i = 0; i < v.size(); i++) {
			cout << "Name : " << v[i].getname() << endl << "password : " << v[i].getpass() << "  "  << "age : " << v[i].getage() << "  "  << "email : " << v[i].getmail() << "  "  << "id : " << v[i].getid() << "  "  << "gender : " << v[i].getgender() << "  ";
			cout << "blood type : " << v[i].getbloodtype() << "  "  << "hospital : " << v[i].gethospital() << "  "  << "doctor : " << v[i].getdoc() << endl;
		}
	}
	else {
		cout << "error" << endl;
	}
	int s;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> s;
	if (s == 1)
	{
		option();
	}
}
string Admin::getname() {
	return name;
}
string Admin::getpass() {
	return password;
}
void Admin::option() {
	int x;
	cout << "\t\t\t" << "PLEASE PRESS" << endl;
	cout << "1:FOR INSERT\n2:FOR UPDATE\n3:FOR DELETE\n4:FOR DISPLAY\n5:FOR BLOOD DATA \n";
	cin >> x;
	while (x != 6)
	{
		if (x == 1)
		{
			int l; cout << "you want to insert\n1:donor\n2:recipient\n";
			cin >> l;
			if (l == 1) {
				doner_info();
				break;
			}
			else if (l == 2) {
				recip_info();
				break;
			}
			break;
		}
		if (x == 2)
		{
			int l; cout << "you want to update\n1:donor\n2:recipient\n3:donation request\n4:Blood request\n";
			cin >> l;
			if (l == 1) {
				updatedoner();
				break;
			}
			else if (l == 2) {
				updaterecipient();
				break;
			}
			else if (l == 3) {
				updatedonationreq();
			}
			else if (l == 4) {
				updatebloodreq();
			}
		}
		else if (x == 3)
		{
			int l; cout << "you want to delete\n1:donor\n2:recipient\n3:donation request\n4:Blood request\n";
			cin >> l;
			if (l == 1) {
				deletedoner();
				break;
			}
			else if (l == 2) {
				deleterecipient();
				break;
			}
			else if (l == 3) {
				deletedonerrec();
			}
			else if (l == 4) {
				deletebloodreq();
			}
		}
		else if (x == 4) {
			int l; cout << "DISPLAY \n1:USER\n2:REQUEST\n";
			cin >> l;
			if (l == 1) {
				displayuser();
			}
			if (l == 2) {
				displayBl();
			}
			break;
		}
		else if (x == 5) {
			int l; cout << "you want to[1:insert  2:delete  3:update] Blood data\n";
			cin >> l;
			if (l == 1) {
				blod_type();
				break;
			}
			else if (l == 2) {
				deleteblooddata();
				break;
			}
			else if (l == 3) {
				updateblooddata();
				break;
			}
		}

	}
}
void Admin::login() {
	string N;
	string P;
	string username;
	string pass;
	vector<Admin>ad;
	int x;
	int y;
	bool v = false;
	int t = 0;
	cout << "PLEASE ENTER YOUR NAME : " << endl;
	cin.ignore();
	getline(cin, N);
	cout << "PLEASE ENTER YOUR PASSWORD : " << endl;
	getline(cin, P);
	fstream read("Admin.txt");
	string line;
	Admin d;
	string q, w, m, to, yo, u, n, p, s;
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
		getline(read, s, '\n');

		ad.push_back(d);
	}
	for (int i = 0; i < ad.size(); i++) {
		if (N == ad[i].getname() && P == ad[i].getpass()) {
			t = 1;
		}
	}
	ad.clear();
	if (t == 1)
	{
		option();
	}
	else if (t == 0) {
		cout << "Invalid account\n";
	}
}
void Admin::displayBl()
{
	int op;
	cout << "YOU WANT TO DISPLAT\n1:BLOOD REQUEST\n2:DONATION REQUEST\n"; cin >> op;
	if (op == 1) {
		fstream f("bloodrequest.txt");;
		vector<Blood>sp;
		string f1, f2, f3, f4, f5;
		while (getline(f, f1, ' '))
		{
			getline(f, f2, ' ');
			getline(f, f3, ' ');
			getline(f, f4, ' ');
			getline(f, f5, '\n');
			Blood ou(f1, f2, f3, f4, f5);
			sp.push_back(ou);
		}
		for (int i = 0; i < sp.size(); i++) {
			cout << sp[i].getrecipientsname() << "  " << sp[i].getbloodtype() << "  " << sp[i].getdarecieve() << "  " << sp[i].getbloodquan() << "  " << sp[i].getbloodedate() << endl;

		}
	}
	else if (op == 2) {
		fstream f("donationreq.txt");;
		vector<Blood>sp;
		string f1, f2, f3;
		int lo = 0;
		while (getline(f, f1, ' '))
		{
			getline(f, f2, ' ');
			getline(f, f3, '\n');
			Blood b(f1, f2, f3);
			sp.push_back(b);
		}
		for (int i = 0; i < sp.size(); i++) {
			cout << sp[i].getrecipientsname() << "  " << sp[i].getbloodtype() << "  " << sp[i].getdarecieve() << endl;
		}
	}
	int s;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> s;
	if (s == 1)
	{
		option();
	}
}
void Admin::updatedonationreq()
{
	fstream f("donationreq.txt");
	string t;
	cout << "PLEASE ENTER THE NAME REQUEST : ";
	cin >> t;
	vector<Blood>sp;
	string f1, f2, f3;
	string ntype, nqua, n_dat;
	int lo = 0;
	while (getline(f, f1, ' '))
	{
		getline(f, f2, ' ');
		getline(f, f3, '\n');
		Blood b(f1, f2, f3);
		sp.push_back(b);
	}
	int c = 0, ll;
	for (int i = 0; i < sp.size(); i++) {
		if (t == sp[i].getrecipientsname()) {

			cout << "ENTER THE NEW REQUIRED BLOOD TYPE : \n";
			cin >> ntype;
			cout << "ENTER THE NEW RECIVING DATE \n"; cin >> n_dat;
			sp[i].settype(ntype);
			sp[i].setredate(n_dat);
		}
		c = 1;
	}
	if (c == 1) {
		cout << "UPDATED SUCCESSFULY\n";
	}
	f.close();
	fstream fill;
	fill.clear();
	fill.open("donationreq.txt", ios::out);
	for (int i = 0; i < sp.size(); i++)
	{
		fill << sp[i].getrecipientsname() << " " << sp[i].getbloodtype() << " " << sp[i].getdarecieve() << endl;
	}
	fill.close();
	int s;
	cout << "BACK TO MAIN?\n1:yes\n2:no\n";
	cin >> s;
	if (s == 1)
	{
		option();
	}
}