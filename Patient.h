#ifndef FINAL_PROJECT_PATIENT_H
#define FINAL_PROJECT_PATIENT_H

#include "Human.h"
#include <vector>
#include "Patient.h"
#include "Hospital.h"

class  Patient : public Human {
private:
    string Gender;
    string Cost;
    vector<string>patient_all_ino;
    vector<vector<string>> Bill_Info;

public:
    string Gender_getter();
    void Gender_setter(string gender);

    vector<vector<string>> & Bill_Info_getter();
    void Bill_Info_setter(vector<string> Bill_Info);
    void Show_Bill ();

    vector<string> patient_all_ino_getter()const ;



    Patient(string id,string name,string last_Name,string phone_number,string user_name,string password,string age, string gender , string dammy2,string dammy,string dammy1 );
};


#endif //FINAL_PROJECT_PATIENT_H