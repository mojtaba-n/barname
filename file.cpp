#include <iostream>
#include <vector>
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
    balance=ba;}
void student::setis_active(bool active){
is_active=active;}            
int student::getuser_id(){return user_id;}
string student::getstudent_id(){return student_id;}
string student::getname(){return name;}
string student::getemail(){return email;}
float student::getbalance(){return balance;}
bool student::getis_active(){return is_active;}
enum meal_type{type1,type2};
class Meal{
    int meal_id;
    string namemeal;
    enum meal_type{type1,type2};
    meal_type t;
    float price;
    vector<string> side_items;
public:
Meal(int id,string nm,meal_type s,float p,const vector<string>& items){
setmeal_id(id);
setnamemeal(nm);
setprice(p);
meal_type t= meal_type(s);
setside_item(items);
}
void setmeal_id(int);
void setnamemeal(string);
void setmeal_type(meal_type);
void setside_item(const vector<string>& newside_item);
void setprice(float);
void update_price(float);
void add_side_item(const string& sid_item);
int getmeal_id()const{return meal_id;}
string getnamemeal()const{return namemeal;}
float getorice()const{return price;}
meal_type getmeal_type()const{return t;}    
};
void Meal::setmeal_id(int id){
    meal_id=id;}
void Meal::setnamemeal(string n){
    namemeal=n;}
void Meal::setmeal_type(meal_type s){
    meal_type t = meal_type(s);}
void Meal::setside_item(const vector<string>& newside_item){
    side_items=newside_item;}
void Meal::setprice(float p){
    price=p;}
void Meal::update_price(float new_price){
    price=new_price;}
void Meal::add_side_item(const string& sid_item){
    side_items.push_back(sid_item);}
    


  