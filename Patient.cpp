//
// Created by dell on 12/2/2020.
//

#include "Patient.h"
#include <vector>
#include <sstream>




string Patient :: Gender_getter(){
    return Gender;
}

void Patient:: Gender_setter(string gender){
    Gender = gender;
}

vector<vector<string>>& Patient:: Bill_Info_getter(){
    return Bill_Info;
}
void Patient :: Bill_Info_setter(vector<string> bill_Info){
    Bill_Info.push_back(bill_Info);
}

vector<string> Patient :: patient_all_ino_getter()const {
    return patient_all_ino;
}


void Patient ::Show_Bill (){
    int cost = 0;
    for (int i = 0; i <Bill_Info.size() ; ++i) {
        for (int j = 0; j <Bill_Info[0].size() ; ++j) {
            cout <<Bill_Info[i][j];
            cout << "   ";
        }
        stringstream cost_before_covert(Bill_Info[i][4]);
        int cost_after_covert = 0;
        cost_before_covert >> cost_after_covert;
        cost = cost + cost_after_covert;
        cout << endl;  
    }
    cout <<"----------------------------------------------------"<<endl;
    cout <<"Total cost : "<<cost<<"$"<<endl;
}

Patient::Patient(string id, string name, string last_Name, string phone_number, string user_name, string password,
                 string age, string gender, string dammy2, string dammy, string dammy1)
        :Human{id,name,last_Name,phone_number,user_name,password,age}{
    Gender = gender;
 //   Cost =cost;
    patient_all_ino.push_back(id);
    patient_all_ino.push_back(name);
    patient_all_ino.push_back(last_Name);
    patient_all_ino.push_back(phone_number);
    patient_all_ino.push_back(user_name);
    patient_all_ino.push_back(password);
    patient_all_ino.push_back(age);
    patient_all_ino.push_back(gender);
  //  patient_all_ino.push_back(cost);
}
