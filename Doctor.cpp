//
// Created by dell on 12/2/2020.
//

#include "Doctor.h"
#include "iostream"
#include "Human.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////

void Doctor :: Day_Setter(string day){
    Day = day;
    }


string Doctor ::Day_Getter(){
    return Day;
}


///////////////////////////////////////////////////////////////////////////////////


vector<string> Doctor :: doctor_all_ino_getter()const {
    return doctor_all_ino;
}

///////////////////////////////////////////////////////////////////////////////////

string Doctor :: Time_getter(){
    return Time;
}
void Doctor :: Time_setter(string time){
    Time = time;
}

///////////////////////////////////////////////////////////////////////////////////

void Doctor :: Field_setter(string field){
    Field=field;
    
}
string Doctor :: Field_getter(){
    return Field;
}

///////////////////////////////////////////////////////////////////////////////////

string Doctor :: Visited_Patients_getter(){
    return Visited_Patients;
}
void Doctor :: Visited_Patients_setter(string visited_patients){
    Visited_Patients=visited_patients;
}

Doctor::Doctor(string id, string name, string last_Name, string phone_number, string user_name, string password, string age, string field, string day, string time, string visited_patients)
    :Human{ id,name,last_Name,phone_number,user_name,password,age } {
    Field = field;
    Day = day;
    Time = time;
    doctor_all_ino.push_back(id);
    doctor_all_ino.push_back(name);
    doctor_all_ino.push_back(last_Name);
    doctor_all_ino.push_back(phone_number);
    doctor_all_ino.push_back(user_name);
    doctor_all_ino.push_back(password);
    doctor_all_ino.push_back(age);
    doctor_all_ino.push_back(field);
    doctor_all_ino.push_back(day);
    doctor_all_ino.push_back(time);
    doctor_all_ino.push_back(visited_patients);
}

void Doctor::doctor_all_ino_setter (int index , string Value){
    doctor_all_ino[index]=Value;
}

///////////////////////////////////////////////////////////////////////////////////
