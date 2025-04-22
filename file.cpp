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
void setuser_id(int uid);
void setstudent_id(string sid);
void setname(string n);
void setemail(string mail);
void setbalance(float ba);
void setis_active(bool active);

};