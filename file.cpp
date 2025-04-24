#include <iostream>
#include <vector>
#include <ctime>
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
student(int uid=1000,string sid="403122",string n="None",string mail="nothing@email.com",float ba=00.00,bool active=true){
    setuser_id(uid);
    setstudent_id(sid);
    setname(n);
    setemail(mail);
    setbalance(ba);
    setis_active(active);
}
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
Meal(int id=100,string nm="None",meal_type s=type1,float p=00.00,const vector<string>& items={}){
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
void print();
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
void Meal::print(){
    cout<<"name meal:"<<namemeal<<"\n id meal:"<<meal_id
    <<"\n price:"<<price<<"\n meal type:"<<t;
    cout<<"\n side items:";
    for (int i=0;i<side_items.size();++i){
        cout<<" "<<side_items[i];}
}
class DiningHall{
int hall_id;
string name_dininghall;
string address;
int capacity;
public:
DiningHall(int id=10 ,string name="None" ,string ads="nothing",int cpc=0){
sethall_id(id);
name_dininghall=name;
address=ads;
setcapacity(cpc);}
void sethall_id(int);
void setname_dininghall(string);
void setaddress(string);
void setcapacity(int);   
int gethall_id(){return hall_id;}
string getname_dininghall(){return name_dininghall;}
string getaddress(){return address;}
int getcapacity(){return capacity;}
void print();
};
void DiningHall::sethall_id(int id){
    if(id<1000||9999<id)
     hall_id=1000;
     else hall_id=id;}
void DiningHall::setname_dininghall(string name){
    name_dininghall=name;}
void DiningHall::setaddress(string ads){
    address=ads;}
void DiningHall::setcapacity(int cpc){
    if(cpc<0){
        capacity=cpc*(-1);}
    else capacity=cpc;}
void DiningHall::print(){
    cout<<"\nname Dininghall:"<<name_dininghall
    <<"\nId Dininghall:"<<hall_id<<"\naddress:"
    <<address<<"\ncapacity:"<<capacity;}        
class Reservation{
int reservation_id;
student Student;
DiningHall dhall;
Meal meal;
enum Status{reserv ,notreserv,cancelreserv};
Status status;
time_t created_at;
public:
    Reservation(int id,student stu ,DiningHall hall, Meal m, Status s, time_t craet){
        reservation_id=id;
        Student=stu;
        dhall=hall;
        meal=m;
        status=s;
        created_at=craet;
    }
    void setreservatin_id(int);
    void setstudent(student);
    void setdhll(DiningHall);
    void setmeal(Meal);
    void setstatus(Status);
    void setcreated_at(time_t);
    };
    void Reservation::setreservatin_id(int id){
        reservation_id=id;}
    void Reservation::setstudent(student st){
        Student=st;}
    void Reservation::setdhll(DiningHall d){
        dhall=d;}
    void Reservation::setmeal(Meal m){
        meal=m;}
    void Reservation::setstatus(Status s){
        status=s;}            
    void Reservation::setcreated_at(time_t t){
        created_at=t;}
          