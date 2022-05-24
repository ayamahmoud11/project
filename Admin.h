#pragma once
#include <string>
using namespace std;
class Admin
{
private:
	string name, email, password, gender, blood_type, otherdises, date_of_donation, doc_of_case, hospital, mail;
	string desis;
	string id,quantity,startdate,expiredate;
	int age;
	
public:
	string getname();
	string getpass();
	void login();
	void option();
	void doner_info();
	void recip_info();
	void blod_type();
	void updatedoner();
	void updaterecipient();
	void updateblooddata();
	void updatebloodreq();
	void updatedonationreq();
	void deletedoner();
	void deleterecipient();
	void deleteblooddata();
	void displayuser();
	void displayBl();
	void deletedonerrec();
	void deletebloodreq();
};

class Blood
{
private:
	string sname, darecieve;
	string blood_Type, qua, s_date, E_date;
public:

	Blood(string n,string k,string b ,string m) 
	{
		blood_Type = n;
		qua = k;
		s_date = b;
		E_date = m;
	}
	Blood(string q, string w, string t,string br, string l)
	{
		sname = q;
		blood_Type = w;
		darecieve = t;
		qua = br;
		E_date = l;
	}

Blood(string q, string w, string br)
	{
	sname = q;
	blood_Type = w;
	darecieve = br;
	}
	string getrecipientsname() {
		return sname;
	}
	string getdarecieve() {
		return darecieve;
	}
	string getbloodtype() {
		return blood_Type;
	}
	string getbloodquan() {
		return qua;
	}
	string getbloodsdate() {
		return s_date;
	}
	string getbloodedate() {
		return E_date;
	}
	void settype(string s) {
		blood_Type = s;
	}
	void setquantity(string s) {
		qua = s;
	}
	void setsdate(string s) {
		s_date = s;
	}
	void setedate(string s) {
		E_date = s;
	}
	void setredate(string s) {
		darecieve = s;
	}
};