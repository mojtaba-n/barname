#include <iostream>
using namespace std;

class student
{
private:
int user_id;
string student_id;
string name;
string email;
float balance;
bool is_active;

public:
student(int uid,string sid,string n,string mail,float ba,bool active){
    setuser_id(uid);
    setstudent_id(sid);
    setname(n);
    setemail(mail);
    setbalance(ba);
    setis_active(active);
};
void setuser_id(int);
void setstudent_id(string);
void setname(string);
void setemail(string);
void setbalance(float);
void setis_active(bool);
int getuser_id();
string getstudent_id();
string getname();
string getemail();
float getbalance();
bool getis_active();

};
void student::setuser_id(int uid){
    if(uid<1000 || uid>9999){
        user_id=1000;}
    else user_id=uid ;}
void student::setstudent_id(string sid){
    student_id=sid;}
void student::setname(string n){
    name=n;}
void student::setbalance(float ba){
    if(ba>20||ba<0)
    balance=11.11;
    else balance=ba;}
void student::setis_active(bool active){
is_active=active;}            
int student::getuser_id(){return user_id;}
string student::getstudent_id(){return student_id;}
string student::getname(){return name;}
string student::getemail(){return email;}
float student::getbalance(){return balance;}
bool student::getis_active(){return is_active;}
