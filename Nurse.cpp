//
// Created by dell on 12/2/2020.
//

#include "Nurse.h"
#include "Human.h"




///////////////////////////////////////////////////////////////////////////////////


vector<string> Nurse :: nurse_all_ino_getter(){
    return nurse_all_ino;
}

///////////////////////////////////////////////////////////////////////////////////

string Nurse :: Time_getter(){
    return Time;
}
void Nurse :: Time_setter(string time){
    Time = time;
}

///////////////////////////////////////////////////////////////////////////////////

void Nurse :: Field_setter(string field){
    Field=field;
}
string Nurse :: Field_getter(){
    return Field;
}

///////////////////////////////////////////////////////////////////////////////////

void Nurse :: Day_Setter(string day){
    Day = day;
}


string Nurse ::Day_Getter(){
    return Day;
}

Nurse::Nurse(string id, string name, string last_Name, string phone_number, string user_name, string password, string age, string field, string day, string time,string dammy)
    :Human{ id,name,last_Name,phone_number,user_name,password,age } {
    Field = field;
    Day = day;
    Time = time;
    nurse_all_ino.push_back(id);
    nurse_all_ino.push_back(name);
    nurse_all_ino.push_back(last_Name);
    nurse_all_ino.push_back(phone_number);
    nurse_all_ino.push_back(user_name);
    nurse_all_ino.push_back(password);
    nurse_all_ino.push_back(age);
    nurse_all_ino.push_back(field);
    nurse_all_ino.push_back(day);
    nurse_all_ino.push_back(time);
}

void Nurse::nurse_all_ino_setter (int index , string Value){
    nurse_all_ino[index]=Value;
}
