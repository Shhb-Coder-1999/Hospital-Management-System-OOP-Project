//
// Created by dell on 12/2/2020.
//

#ifndef FINAL_PROJECT_DOCTOR_H
#define FINAL_PROJECT_DOCTOR_H

#include "Human.h"
#include <sstream>


class Doctor : public Human {
private:
    string Day;
    string Time;
    string Field;
    string Visited_Patients;
    vector<string> doctor_all_ino;

public:
    void Day_Setter(string day);
    string Day_Getter();
    bool Day_Validate(string day);


    vector<string> doctor_all_ino_getter()const;

    string Time_getter();
    void Time_setter(string time);

    string Field_getter();
    void Field_setter(string field);

    string Visited_Patients_getter();
    void Visited_Patients_setter(string visited_patients);

    void doctor_all_ino_setter (int index , string Value);


    ///////////////////////////////////////////////////////////////////////////////////
//    friend ofstream& operator<<(ofstream& out,const Doctor& x);

    Doctor(string id, string name, string last_Name, string phone_number, string user_name, string password, string age, string field, string day, string time, string visited_patients);
};


#endif //FINAL_PROJECT_DOCTOR_H
