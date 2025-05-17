#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
class Meal;
class Reservation;
class DiningHall;
class User
{
protected:
int userID;
string name;
string lastname;
string hashed_password;
public:
User(int u=1000,string n="none",string ln="_",string hp="None"){
    setuserId(u);
    name=n;
    lastname=ln;
    hashed_password=hp;
}
virtual void print()const;
virtual void getType();
void setuserId(int);
void setname(string);
void setlastname(string);
void sethashpassword(string);
int getuserID(){return userID;}  
string getname(){return name;}
string getlastname(){return lastname;}
string gethashpassword(){return hashed_password;} 
};
void User::setuserId(int i){
if(i<0){
    userID=(i*-1);}
    else userID=i;   
}
void User::setname(string n){
    name=n;
}
void User::setlastname(string ln){
    lastname=ln;
}
void User::sethashpassword(string hs){
    hashed_password=hs;
}
void User::print()const{
    cout<<"\nname:"<<name<<"\tlastname:"<<lastname<<"\tuser ID:"<<userID
    <<"\thashed password:"<<hashed_password;
}
void User::getType(){
    cout<<"user";
}
class Admin:public User{
    public:
    Admin(int u, string n, string ln, string hp):User(u,n,ln,hp){}
    void print()const;
    void gettype(){cout<<"Admin";}
};
void Admin::print()const{
    User::print();
    cout<<"\tAdmin";
}
class student:public User
{
private:
string student_id;
string phone;
string email;
float balance;
bool is_active;
vector<Reservation> reservations;

public:
student(int uid,string sid="403122",string n,string p,string mail="nothing@email.com",
float ba=00.00,bool active=true,string ln, string hp):User(uid,n,ln,hp){
    setstudent_id(sid);
    setphone(p);
    setemail(mail);
    setbalance(ba);
    setis_active(active);
}
void setstudent_id(string);
void setemail(string);
void setbalance(float);
void setis_active(bool);
void setphone(string);
string getstudent_id();
string getemail();
float getbalance();
bool getis_active();
string getphone();
void print();
bool cancel_reservation(Reservation);
void reserve_meal(Meal,DiningHall);
void getType();
};
void getType(){
    cout<<"student";
}
void student::setstudent_id(string sid){
    student_id=sid;}
void student::setbalance(float ba){
    balance=ba;}
void student::setis_active(bool active){
is_active=active;}            
void student::setphone(string p){
    phone=p;}
string student::getstudent_id(){return student_id;}
string student::getemail(){return email;}
float student::getbalance(){return balance;}
bool student::getis_active(){return is_active;}
string student::getphone(){return phone;}
void student::print(){
    User::print();
    getType();
    cout<<"\tstudent id:"<<student_id
    <<"\temail:"<<email<<"\tbalance:"<<balance
    <<"\tis active:"<<is_active;
}
bool student::cancel_reservation(Reservation res){
for (Reservation&r:reservations){
    if (r.getreservation_id()==res.getreservation_id()){
        if(r.cancel()){
            balance+= res.getmeal().getprice()*0.8;
            return true;
        }
    }  
}
return false;}
void student::reserve_meal(Meal meal, DiningHall hall) {
    if (is_active){
    if (balance < meal.getprice()) {
        cout << "Error:no many\n";
    }
    for (const auto& r : reservations) {
        if (r.getmeal().getReserveday() == meal.getReserveday() &&
            r.getmeal().getmeal_type() == meal.getmeal_type()) {
            cout << "Error:reserve tekrari ast\n";
}
    else{
    balance -= meal.getprice();
    time_t now = time(0);
    Reservation new_reservation(rand(),hall, meal,reserv, now);
    reservations.push_back(new_reservation);
    cout << "Reservation successful\n";
}
}
}
}
enum Reserveday{Saturday, Sunday, Monday, Tuesday, Wednesday, Thursday};
enum meal_type { breakfast , lunch , dinner};
class Meal{
    int meal_id;
    string namemeal;
    meal_type t;
    Reserveday r;
    float price;
    vector<string> side_items;
public:
Meal(int id=100,string nm="None",meal_type s=lunch,Reserveday a=Sunday ,float p=00.00,const vector<string>& items={}){
setmeal_id(id);
setnamemeal(nm);
setprice(p);
meal_type t= meal_type(s);
setside_item(items);
}
Meal(const Meal& ob){
    meal_id=ob.meal_id;
    namemeal=ob.namemeal;
    price=ob.price;
    meal_type t=ob.t;
    Reserveday r=ob.r;
}
void setmeal_id(int);
void setnamemeal(string);
void setmeal_type(meal_type);
void setReserveday(Reserveday);
void setside_item(const vector<string>& newside_item);
void setprice(float);
void update_price(float);
void add_side_item(const string& sid_item);
int getmeal_id()const{return meal_id;}
string getnamemeal()const{return namemeal;}
float getprice()const{return price;}
meal_type getmeal_type()const{return t;}    
Reserveday getReserveday(){return r;}
void print();
};
void Meal::setmeal_id(int id){
    meal_id=id;}
void Meal::setnamemeal(string n){
    namemeal=n;}
void Meal::setmeal_type(meal_type s){
    meal_type t = meal_type(s);}
void Meal::setReserveday(Reserveday a){
    r=a;
}
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
DiningHall(const DiningHall&ob){
    hall_id=ob.hall_id;
    name_dininghall=ob.name_dininghall;
    address=ob.address;
    capacity=ob.capacity;
}
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
enum Status{reserv ,notreserv,cancelreserv};
class Reservation{
int reservation_id;
DiningHall* dhall;
Meal*meal;
Status status;
time_t created_at;
public:
    Reservation(int id=10000,DiningHall hall, Meal m, Status s=notreserv, time_t craet){
        reservation_id=id;
        DiningHall dhall(hall);
        Meal meal(m);
        status=s;
        created_at=craet;
    }
    void setreservatin_id(int);
    void setdhll(DiningHall);
    void setmeal(Meal);
    void setstatus(Status);
    void setcreated_at(time_t);
    int getreservation_id()const{return reservation_id;}
    DiningHall getdhall()const{return *dhall;}
    Meal getmeal()const{return *meal;}
    Status getstatus ()const{return status;}
    time_t getcreated_at()const{return created_at;}
    bool cancel();
    void print();
    };
    void Reservation::setreservatin_id(int id){
        reservation_id=id;}
    void Reservation::setdhll(DiningHall d){
        DiningHall dhall(d);}
    void Reservation::setmeal(Meal m){
        Meal meal(m);}
    void Reservation::setstatus(Status s){
        status=s;}            
    void Reservation::setcreated_at(time_t t){
        created_at=t;}
    bool Reservation::cancel(){
        if(status==reserv){
            status= cancelreserv;
            return true;}
        else return false;
    }
    void Reservation::print(){
        meal->print();
        dhall->print();
        cout<<"\nreservation id:"<<reservation_id
        <<"\ncreated at :"<<created_at;
    }
class Panel{
public:
void Action(int);
void showMenu();
void showStudentInfo();
void checkBalance();
void viewReservations();
void addReservation(Reservation);
void addToShoppingcart();
void confirmShoppingcart();
void removeShoppingCartItem();
void increaseBalance();
void viewRecentTransactions();
void cancelReservatin(int);
void exit();
    };
class storage{
int mealIDCounter=10;
int diningHallIDCounter=1000;
vector<Meal>allMeals;
vector<DiningHall>allDiningHalls;
storage(){}
public:
storage(const storage&)= delete;
void operator=(const storage&)= delete;
static storage& getInstance(){
    static storage instance;
    return instance;
}
int generateMealId(){
    return mealIDCounter++;}
int generateHallId(){
    return diningHallIDCounter++;}    
};    
enum TransactionType{TRANSFER,PAYMENT};
enum TransactionStatus{PENDING,COMPLETED,FIALED};
class Transaction{
    int transactionID;
    string trackingCode;
    float amount;
    TransactionType type;
    TransactionStatus status;
    time_t createdAt;
public:
Transaction(int tID,string tcode,float at,TransactionType t,TransactionStatus s,time_t creat){
settransaction(tID);
settrackingCode(tcode);
setamount(at);
setTransactionType(t);
setTransactionStatus(s);
setcreatedAt(creat);    
}
void settransaction(int);
void settrackingCode(string);
void setamount(float);
void setTransactionType(TransactionType);
void setTransactionStatus(TransactionStatus);
void setcreatedAt(time_t);
};