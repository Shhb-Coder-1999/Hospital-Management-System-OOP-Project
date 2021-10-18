//
// Created by dell on 12/2/2020.
//

#ifndef FINAL_PROJECT_NURSE_H
#define FINAL_PROJECT_NURSE_H
#include "Human.h"

class Nurse : public Human  {
private:
    string Day;
    string Time;
    string Field;
    vector<string> nurse_all_ino;
public:
    vector<string> nurse_all_ino_getter();

    string Time_getter();
    void Time_setter(string time);

    string Field_getter();
    void Field_setter(string field);

    void Day_Setter(string day);
    string Day_Getter();

    Nurse(string id, string name, string last_Name, string phone_number, string user_name, string password, string age, string field, string day, string time,string dammy)
        ;
    void nurse_all_ino_setter (int index , string Value);

};


#endif //FINAL_PROJECT_NURSE_H
