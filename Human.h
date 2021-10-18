//
// Created by dell on 12/2/2020.
//

#ifndef FINAL_PROJECT_HUMAN_H
#define FINAL_PROJECT_HUMAN_H

#include "iostream"
#include <vector>
using namespace std;


class Human {
private:
    string Id;
    string Name;
    string Last_Name;
    string Phone_number;
    string User_name;
    string Password;
    string Age;


public:
    Human(string id,string name,string last_Name,string phone_number,string user_name,string password,string age);


    void Id_Setter(string name);
    string Id_Getter();
    bool Id_Validate(string id);

    void Name_Setter(string name);
    string Name_Getter();
    bool Name_Validate(string id);

    void Last_Name_Setter(string last_name);
    string Last_Name_Getter();
    bool Last_Name_Validate(string id);

    void Phone_number_Setter(string Phone_number);
    string Phone_number_Getter();
    bool Phone_number_Validate(string id);

    void User_name_Setter(string user_name);
    string User_name_Getter();
    bool User_name_Validate(string id);

    void Password_Setter(string password);
    string Password_Getter();
    bool Password_Validate(string id);

    void Age_Setter(string age);
    string Age_Getter();
    bool Age_Validate(string id);

    bool validate_String_Must_Be_Number(string id);
    bool validate_String_Must_Be_character(string name);

};


#endif //FINAL_PROJECT_HUMAN_H
