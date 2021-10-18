//
// Created by dell on 12/2/2020.
//

#include "Human.h"
#include <string>
#include <sstream>
#include <vector>
///////////////////////////////////////////////////////////////////////////////////
Human :: Human(string id,string name,string last_Name,string phone_number,string user_name,string password,string age){
    Id = id;
    Name = name;
    Last_Name =last_Name;
    Phone_number =phone_number;
    User_name = user_name;
    Password = password;
    Age = age;

}


///////////////////////////////////////////////////////////////////////////////////

void Human :: Id_Setter(string id){
    Id = id;
}

string Human ::Id_Getter(){
    return Id;
}


///////////////////////////////////////////////////////////////////////////////////

void Human :: Name_Setter(string name){
    Name = name;
}

string Human ::Name_Getter(){
    return Name;
}


///////////////////////////////////////////////////////////////////////////////////

void Human :: Last_Name_Setter(string last_name){
    Last_Name = last_name;

}

string Human ::Last_Name_Getter(){
    return Last_Name;
}


///////////////////////////////////////////////////////////////////////////////////

void Human :: Phone_number_Setter(string phone_number){
    Phone_number = phone_number;
}

string Human ::Phone_number_Getter(){
    return Phone_number;
}


///////////////////////////////////////////////////////////////////////////////////

void Human :: User_name_Setter(string user_name){
    User_name = user_name;
}

string Human ::User_name_Getter(){
    return User_name;
}

///////////////////////////////////////////////////////////////////////////////////

void Human :: Password_Setter(string password){
    Password = password;
}

string Human ::Password_Getter(){
    return Password;
}


///////////////////////////////////////////////////////////////////////////////////

void Human :: Age_Setter(string age){
    Age = age;

}

string Human ::Age_Getter(){
    return Age;
}



///////////////////////////////////////////////////////////////////////////////////
