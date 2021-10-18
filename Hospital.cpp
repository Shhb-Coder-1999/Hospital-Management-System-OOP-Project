//
// Created by dell on 12/1/2020.
//
#include <iostream>
#include "Hospital.h"
#include "stdlib.h"
#include "fstream"
#include <typeinfo>
#include <string>

#include <string>
#include <cctype>
#include <algorithm>



#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"
#include <vector>

/*#include <tabulate.hpp>
using namespace tabulate;*/

using namespace std;



void Hospital::menu() {

    vector<Doctor> All_Of_Doctors;
    vector<Nurse> All_Of_Nurses;
    vector<Patient> All_Of_Patients;



    Hospital admin;
    fstream AoD("Doctors.txt");
    fstream AoN("Nurses.txt");
    fstream AoP("Patients.txt");
    fstream Bill("Bill.txt");
    fstream Doctors_Timetable1("Doctors_Timetable.txt");
    fstream Nurses_Timetable1("Nurses_Timetable.txt");
    ofstream ofs;

    Hospital::Read_From_File_And_Create_Objects<Doctor>(All_Of_Doctors, AoD);
    Hospital::Read_From_File_And_Create_Objects<Nurse>(All_Of_Nurses, AoN);
    Hospital::Read_From_File_And_Create_Objects<Patient>(All_Of_Patients, AoP);
    Hospital::Read_From_File_And_Create_Timetable ( Doctors_Timetable , Doctors_Timetable1) ;
    Hospital::Read_From_File_And_Create_Timetable (  Nurses_Timetable , Nurses_Timetable1);
    Hospital::Read_From_File_And_Create_Bill (All_Of_Patients  , Bill );
	
    while (-1) {
        string switch_setter;
        cout << "-------------------Welcome to Our hospital-------------------" << endl;
        cout << "1 = Enter as Admin . " << endl;
        cout << "2 = Enter as Patient . " << endl;
        cout << "3 = Enter as Staff . " << endl;

        cin >> switch_setter;

        while (!Switch_Setter_validator (switch_setter , 1 , 3)){
            cout << "Please enter your choose again : ";
            cin >> switch_setter;
        }

        stringstream switch_setter_before_covert(switch_setter);
        int switch_setter_after_covert = 0;
        switch_setter_before_covert >> switch_setter_after_covert;

        switch (switch_setter_after_covert) {
            case 1: {
                cout << "-------------Admin Control Panel-------------" << endl;
                string user, pass;

                cout << "Please Enter your username : ";
                cin >> user;
                cout << "Please Enter your password : ";
                cin >> pass;

                while (!admin.Validate_username_password(user, pass)) {

                    cout << "Please Enter your username again : ";
                    cin >> user;
                    cout << "Please Enter your password again : ";
                    cin >> pass;
                }

                bool a= true;
                while (a) {
                    string switch_setter;
                    cout << "-------------Admin Control Panel-------------" << endl;
                    cout << "1 = Hire New Doctor " << endl;
                    cout << "2 = Hire New Nurse " << endl;
                    cout << "3 = Fire a Doctor " << endl;
                    cout << "4 = Fire a Nurse " << endl;
                    cout << "5 = Get ino of Doctors" << endl;
                    cout << "6 = Get ino of Nurses " << endl;
                    cout << "7 = Show Timetable of Doctors " << endl;
                    cout << "8 = Show Timetable of Nurses " << endl;
                    cout << "9 = Update info of a doctor " << endl;
                    cout << "10 = Update info of a nurse  " << endl;
                    cout << "11 = Exit " << endl;

                    cin >> switch_setter;

                    while (!Switch_Setter_validator (switch_setter , 1 , 11)){
                        cout << "Please enter your choose again : ";
                        cin >> switch_setter;
                    }

                    stringstream switch_setter_before_covert(switch_setter);
                    int switch_setter_after_covert = 0;
                    switch_setter_before_covert >> switch_setter_after_covert;

                    cout << "---------------------------------------------" << endl;
                    switch (switch_setter_after_covert) {
                        case 1: {

                            cout << "enter your id : " << endl;
                            string id;
                            cin >> id;
                            while (!admin.Id_Validate(All_Of_Doctors, id)) {
                                cout << "enter your id again" << endl;
                                cin >> id;
                            }
                            cout << "enter your name : " << endl;
                            string name;
                            cin >> name;
                            while (!admin.Name_Validate(name)) {
                                cout << "enter your name again" << endl;
                                cin >> name;
                            }
                            cout << "enter your last_name :" << endl;
                            string last_name;
                            cin >> last_name;
                            while (!admin.Last_Name_Validate(last_name)) {
                                cout << "enter your last_name again" << endl;
                                cin >> last_name;
                            }

                            cout << "enter your phone_number :" << endl;
                            string phone_number;
                            cin >> phone_number;
                            while (!admin.Phone_number_Validate(phone_number, All_Of_Nurses , All_Of_Doctors ,All_Of_Patients )) {
                                cout << "enter your phone_number again" << endl;
                                cin >> phone_number;
                            }

                            cout << "enter your username :" << endl;
                            string username;
                            cin >> username;
                            while (!admin.User_name_Validate(username , All_Of_Nurses , All_Of_Doctors ,All_Of_Patients)) {
                                cout << "enter your username again " << endl;
                                cin >> username;
                            }
                            cout << "enter your password :" << endl;
                            string password;
                            cin >> password;
                            while (!admin.Password_Validate(password,All_Of_Nurses , All_Of_Doctors ,All_Of_Patients)) {
                                cout << "enter your password :" << endl;
                                cin >> password;
                            }

                            cout << "enter your age :" << endl;
                            string age;
                            cin >> age;
                            while (!admin.Age_Validate(age)) {
                                cout << "enter your age again :" << endl;
                                cin >> age;
                            }

                            cout << "Please enter Doctors field : "<<endl;
                            cout << "1 = Dentist " << endl;
                            cout << "2 = Dermatologists " << endl;
                            cout << "3=  Emergency Medicine Specialists " << endl;
                            cout << "4 = Plastic Surgeon " << endl;
                            cout << "5 = Radiologists " << endl;
                            cout << "6 = Sports Medicine Specialists " << endl;
                            cout << "7 = General Surgeon " << endl;
                            cout << "8 = Ophthalmologists " << endl;
                            cout << "9 = Neurologists " << endl;

                            string field;
                            cin >> field;

                            while (!Switch_Setter_validator (field , 1 , 9)){
                                cout << "Please enter your choose again : ";
                                cin >> field;
                            }

                            stringstream field_before_covert(field);
                            int field_after_covert = 0;
                            field_before_covert >> field_after_covert;

                            string Field;

                            while (!admin.validate_String_Must_Be_Number(field) &&
                                   !admin.Day_Validate(field_after_covert)) {
                                cout << "1 = Dentist " << endl;
                                cout << "2 = Dermatologists " << endl;
                                cout << "3=  Emergency Medicine Specialists " << endl;
                                cout << "4 = Plastic Surgeon " << endl;
                                cout << "5 = Radiologists " << endl;
                                cout << "6 = Sports Medicine Specialists " << endl;
                                cout << "7 = General Surgeon " << endl;
                                cout << "8 = Ophthalmologists " << endl;
                                cout << "9 = Neurologists " << endl;
                                //   string field;
                                cin >> field;

                                while (!Switch_Setter_validator (field , 1 , 9)){
                                    cout << "Please enter your choose again : ";
                                    cin >> field;
                                }

                                stringstream field_before_covert(field);
                                int field_after_covert = 0;
                                field_before_covert >> field_after_covert;

                            }
                            switch (field_after_covert) {
                                case 1: {
                                    Field = "Dentist";
                                    break;
                                }
                                case 2: {
                                    Field = "Dermatologists";
                                    break;
                                }
                                case 3: {
                                    Field = "Emergency-Medicine-Specialists";
                                    break;
                                }
                                case 4: {
                                    Field = "Plastic-Surgeon";
                                    break;
                                }
                                case 5: {
                                    Field = "Radiologists";
                                    break;
                                }
                                case 6: {
                                    Field = "Sports-Medicine-Specialists";
                                    break;
                                }
                                case 7: {
                                    Field = "General-Surgeon";
                                    break;
                                }
                                case 8: {
                                    Field = "Ophthalmologists";
                                    break;
                                }
                                case 9: {
                                    Field = "Neurologists";
                                    break;
                                }

                            }


                            cout << "Please enter your day : "<<endl;
                            cout << "1 = Monday" << endl;
                            cout << "2 = Tuesday" << endl;
                            cout << "3 = Wednesday" << endl;
                            cout << "4 = Thursday" << endl;
                            cout << "5 = Friday" << endl;
                            cout << "6 = Saturday" << endl;
                            cout << "7 = Sunday" << endl;
                            string day;
                            cin >> day;

                            while (!Switch_Setter_validator (day , 1 , 7)){
                                cout << "Please enter your choose again : ";
                                cin >> day;
                            }

                            stringstream day_before_covert(day);
                            int day_after_covert = 0;
                            day_before_covert >> day_after_covert;

                            string Day;

                            while (!admin.validate_String_Must_Be_Number(day) &&
                                   !admin.Day_Validate(day_after_covert)) {
                                cout << "Please enter your day again : ";
                                cout << "1 = Monday" << endl;
                                cout << "2 = Tuesday" << endl;
                                cout << "3 = Wednesday" << endl;
                                cout << "4 = Thursday" << endl;
                                cout << "5 = Friday" << endl;
                                cout << "6 = Saturday" << endl;
                                cout << "7 = Sunday" << endl;
                                cin >> day;

                                while (!Switch_Setter_validator (day , 1 , 7)){
                                    cout << "Please enter your choose again : ";
                                    cin >> day;
                                }

                                stringstream day_before_covert(day);
                                int day_after_covert = 0;
                                day_before_covert >> day_after_covert;

                            }

                            switch (day_after_covert) {
                                case 1: {
                                    Day = "Monday";
                                    break;
                                }
                                case 2: {
                                    Day = "Tuesday";
                                    break;
                                }
                                case 3: {
                                    Day = "Wednesday";
                                    break;
                                }
                                case 4: {
                                    Day = "Thursday";
                                    break;
                                }
                                case 5: {
                                    Day = "Friday";
                                    break;
                                }
                                case 6: {
                                    Day = "Saturday";
                                    break;
                                }
                                case 7: {
                                    Day = "Sunday";
                                    break;
                                }

                            }


                            cout << "Please enter your on-call shift : "<<endl;
                            cout << "1 = 8->12" << endl;
                            cout << "2 = 12->16" << endl;
                            cout << "3 = 16->20" << endl;
                            cout << "4 = 20->24" << endl;
                            cout << "5 = 24->4" << endl;
                            cout << "6 = 4->8" << endl;
                            string time;
                            cin >> time;

                            while (!Switch_Setter_validator (time , 1 , 7)){
                                cout << "Please enter your choose again : ";
                                cin >> time;
                            }


                            stringstream time_before_covert(time);
                            int time_after_covert = 0;
                            time_before_covert >> time_after_covert;

                            string Time;

                            while (!admin.validate_String_Must_Be_Number(day) &&
                                   !admin.Day_Validate(day_after_covert)) {
                                cout << "Please enter your on-call shift again : ";
                                cout << "1 = 8->12" << endl;
                                cout << "2 = 12->16" << endl;
                                cout << "3 = 16->20" << endl;
                                cout << "4 = 20->24" << endl;
                                cout << "5 = 24->4" << endl;
                                cout << "6 = 4->8" << endl;
                                cin >> time;

                                while (!Switch_Setter_validator (time , 1 , 7)){
                                    cout << "Please enter your choose again : ";
                                    cin >> time;
                                }

                                stringstream time_before_covert(time);
                                int time_after_covert = 0;
                                time_before_covert >> time_after_covert;

                            }
                            switch (time_after_covert) {
                                case 1: {
                                    Time = "8->12";
                                    break;
                                }
                                case 2: {
                                    Time = "12->16";
                                    break;
                                }
                                case 3: {
                                    Time = "16->20";
                                    break;
                                }
                                case 4: {
                                    Time = "20->24";
                                    break;
                                }
                                case 5: {
                                    Time = "24->4";
                                    break;
                                }
                                case 6: {
                                    Time = "4->8";
                                    break;
                                }
                            }
                            ///here i wanna add day and time of doctor to time table

                            day_after_covert = day_after_covert - 1 ;
                            time_after_covert = time_after_covert - 1;

                            admin.Doctors_Timetable_Setter(day_after_covert, time_after_covert, last_name);

                            string visited_patient = "0";

                            Doctor New_Doctor{id, name, last_name, phone_number, username, password, age, Field, Day,
                                              Time, visited_patient};

                            All_Of_Doctors.push_back(New_Doctor);

                            AoD.open("Doctors.txt");
                            Update_Doctor_File(All_Of_Doctors, reinterpret_cast<ofstream &>(AoD));
                            AoP.close();


                            Doctors_Timetable1.open("Doctors_Timetable.txt");
                            Update_Doctors_Time_Table_File (Doctors_Timetable , reinterpret_cast<ofstream &>(Doctors_Timetable1));
                            Doctors_Timetable1.close();



                            cout << "Doctor added !!!" << endl;
                            break;
                        }
                        case 2: {

                            string id;
                            cin >> id;

                            while (!admin.Id_Validate(All_Of_Nurses, id)) {
                                cin >> id;
                            }

                            string name;
                            cin >> name;
                            while (!admin.Name_Validate(name)) {
                                cin >> name;
                            }

                            string last_name;
                            cin >> last_name;
                            while (!admin.Last_Name_Validate(last_name)) {
                                cin >> last_name;
                            }

                            string phone_number;
                            cin >> phone_number;
                            while (!admin.Phone_number_Validate(phone_number, All_Of_Nurses , All_Of_Doctors ,All_Of_Patients )) {
                                cin >> phone_number;
                            }

                            string username;
                            cin >> username;
                            while (!admin.User_name_Validate(username , All_Of_Nurses , All_Of_Doctors ,All_Of_Patients)) {
                                cin >> username;
                            }

                            string password;
                            cin >> password;
                            while (!admin.Password_Validate(password,All_Of_Nurses , All_Of_Doctors ,All_Of_Patients)) {
                                cin >> password;
                            }

                            string age;
                            cin >> age;
                            while (!admin.Age_Validate(age)) {
                                cin >> age;
                            }

                            cout << "Please enter Nurse field : ";
                            cout << "1 = Registered nurse " << endl;
                            cout << "2 = Licensed practical nurse " << endl;
                            cout << "3=  Medical-surgical nurse " << endl;
                            cout << "4 = Nurse practitioner " << endl;
                            cout << "5 = Emergency room nurse " << endl;
                            cout << "6 = Nursing assistant " << endl;
                            cout << "7 = Nurse case manager " << endl;
                            cout << "8 = Home health nurse " << endl;
                            cout << "9 = Staff nurse " << endl;

                            string field;
                            cin >> field;

                            while (!Switch_Setter_validator (field , 1 , 11)){
                                cout << "Please enter your choose again : ";
                                cin >> field;
                            }

                            stringstream field_before_covert(field);
                            int field_after_covert = 0;
                            field_before_covert >> field_after_covert;

                            string Field;

                            while (!admin.validate_String_Must_Be_Number(field) &&
                                   !admin.Day_Validate(field_after_covert)) {
                                cout << "Please enter Nurse field again : ";
                                cout << "1 = Registered nurse " << endl;
                                cout << "2 = Licensed practical nurse " << endl;
                                cout << "3=  Medical-surgical nurse " << endl;
                                cout << "4 = Nurse practitioner " << endl;
                                cout << "5 = Emergency room nurse " << endl;
                                cout << "6 = Nursing assistant " << endl;
                                cout << "7 = Nurse case manager " << endl;
                                cout << "8 = Home health nurse " << endl;
                                cout << "9 = Staff nurse " << endl;
                                string field;
                                cin >> field;

                                while (!Switch_Setter_validator (field , 1 , 11)){
                                    cout << "Please enter your choose again : ";
                                    cin >> field;
                                }

                                stringstream field_before_covert(field);
                                int field_after_covert = 0;
                                field_before_covert >> field_after_covert;
                            }

                            switch (field_after_covert) {
                                case 1: {
                                    Field = "Registered_nurse";
                                    break;
                                }
                                case 2: {
                                    Field = "Licensed_practical_nurse";
                                    break;
                                }
                                case 3: {
                                    Field = "Medical_surgical_nurse";
                                    break;
                                }
                                case 4: {
                                    Field = "Nurse_practitioner";
                                    break;
                                }
                                case 5: {
                                    Field = "Emergency_room_nurse";
                                    break;
                                }
                                case 6: {
                                    Field = "Nursing_assistant";
                                    break;
                                }
                                case 7: {
                                    Field = "Nurse_case_manager";
                                    break;
                                }
                                case 8: {
                                    Field = "Home_health_nurse";
                                    break;
                                }
                                case 9: {
                                    Field = "Staff_nurse";
                                    break;
                                }

                            }


                            cout << "Please enter your day : ";
                            cout << "1 = Monday" << endl;
                            cout << "2 = Tuesday" << endl;
                            cout << "3 = Wednesday" << endl;
                            cout << "4 = Thursday" << endl;
                            cout << "5 = Friday" << endl;
                            cout << "6 = Saturday" << endl;
                            cout << "7 = Sunday" << endl;
                            string day;
                            cin >> day;

                            while (!Switch_Setter_validator (day , 1 , 11)){
                                cout << "Please enter your choose again : ";
                                cin >> day;
                            }

                            stringstream day_before_covert(day);
                            int day_after_covert = 0;
                            day_before_covert >> day_after_covert;

                            string Day;

                            while (!admin.validate_String_Must_Be_Number(day) &&
                                   !admin.Day_Validate(day_after_covert)) {
                                cout << "1 = Monday" << endl;
                                cout << "2 = Tuesday" << endl;
                                cout << "3 = Wednesday" << endl;
                                cout << "4 = Thursday" << endl;
                                cout << "5 = Friday" << endl;
                                cout << "6 = Saturday" << endl;
                                cout << "7 = Sunday" << endl;

                                cin >> day;

                                while (!Switch_Setter_validator (day , 1 , 11)){
                                    cout << "Please enter your choose again : ";
                                    cin >> day;
                                }

                                stringstream day_before_covert(day);
                                int day_after_covert = 0;
                                day_before_covert >> day_after_covert;

                            }

                            switch (day_after_covert) {
                                case 1: {
                                    Day = "Monday";
                                    break;
                                }
                                case 2: {
                                    Day = "Tuesday";
                                    break;
                                }
                                case 3: {
                                    Day = "Wednesday";
                                    break;
                                }
                                case 4: {
                                    Day = "Thursday";
                                    break;
                                }
                                case 5: {
                                    Day = "Friday";
                                    break;
                                }
                                case 6: {
                                    Day = "Saturday";
                                    break;
                                }
                                case 7: {
                                    Day = "Sunday";
                                    break;
                                }

                            }


                            cout << "Please enter your on-call shift : ";
                            cout << "1 = 8->12" << endl;
                            cout << "2 = 12->16" << endl;
                            cout << "3 = 16->20" << endl;
                            cout << "4 = 20->24" << endl;
                            cout << "5 = 24->4" << endl;
                            cout << "6 = 4->8" << endl;

                            string time;
                            cin >> time;

                            while (!Switch_Setter_validator (time , 1 , 11)){
                                cout << "Please enter your choose again : ";
                                cin >> time;
                            }

                            stringstream time_before_covert(time);
                            int time_after_covert = 0;
                            day_before_covert >> day_after_covert;

                            string Time;

                            while (!admin.validate_String_Must_Be_Number(day) &&
                                   !admin.Day_Validate(day_after_covert)) {
                                cout << "1 = 8->12" << endl;
                                cout << "2 = 12->16" << endl;
                                cout << "3 = 16->20" << endl;
                                cout << "4 = 20->24" << endl;
                                cout << "5 = 24->4" << endl;
                                cout << "6 = 4->8" << endl;
                                cin >> time;

                                while (!Switch_Setter_validator (time , 1 , 11)){
                                    cout << "Please enter your choose again : ";
                                    cin >> time;
                                }

                                stringstream time_before_covert(time);
                                int time_after_covert = 0;
                                time_before_covert >> time_after_covert;

                            }
                            switch (time_after_covert) {
                                case 1: {
                                    Time = "8->12";
                                    break;
                                }
                                case 2: {
                                    Time = "12->16";
                                    break;
                                }
                                case 3: {
                                    Time = "16->20";
                                    break;
                                }
                                case 4: {
                                    Time = "20->24";
                                    break;
                                }
                                case 5: {
                                    Time = "24->4";
                                    break;
                                }
                                case 6: {
                                    Time = "4->8";
                                    break;
                                }
                            }
                            string dammy;
                            Nurse New_Nurse{id, name, last_name, phone_number, username, password, age, Field, Day,
                                            Time,dammy};
                            All_Of_Nurses.push_back(New_Nurse);


                            AoN.open("Nurses.txt");
                            Update_Nurse_File(All_Of_Nurses, reinterpret_cast<ofstream &>(AoD));
                            AoN.close();


                            AoN.open("Nurses.txt");
                            Update_Nurses_Time_Table_File(Nurses_Timetable , reinterpret_cast<ofstream &>(AoD));
                            AoN.close();




                            cout << "Nurse added !!!" << endl;
                            break;
                        }
                        case 3: {
                            cout << "please enter id of doctor : ";
                            string id;
                            cin >> id;
                            while (!Id_Validate_for_fire(All_Of_Doctors, id)) {
                                cout << "please enter id of doctor again :";
                                cin >> id;
                            }
                            admin.Delete_Befores_Doctor_Call_Shift_On_Timetable(*Find_Doctor_From_His_Id(All_Of_Doctors, id));
                            admin.Remove_Doctor(All_Of_Doctors, id);


                            AoD.open("Doctors.txt");
                            Update_Doctor_File(All_Of_Doctors, reinterpret_cast<ofstream &>(AoD));
                            AoP.close();


                            AoD.open("Doctors.txt");
                            Update_Doctors_Time_Table_File (Doctors_Timetable , reinterpret_cast<ofstream &>(AoD));
                            AoP.close();


                            cout << "Doctor fired !!!" << endl;
                            break;
                        }
                        case 4: {
                            cout << "please enter id of nurse : ";
                            string id;
                            cin >> id;
                            while (!Id_Validate_for_fire(All_Of_Nurses, id)) {
                                cout << "please enter id of nurse again :";
                                cin >> id;
                            }
                            admin.Remove_Nurse(All_Of_Nurses, id);

                            AoN.open("Nurses.txt");
                            Update_Nurse_File(All_Of_Nurses, reinterpret_cast<ofstream &>(AoD));
                            AoN.close();


                            AoN.open("Nurses.txt");
                            Update_Nurses_Time_Table_File(Nurses_Timetable , reinterpret_cast<ofstream &>(AoD));
                            AoN.close();

                            cout << "Nurse fired !!!" << endl;
                            break;
                        }
                        case 5: {

                            cout << "1 = find specific doctor . " << endl;
                            cout << "2 = Show all doctors with details . " << endl;

                            cin >> switch_setter;

                            while (!Switch_Setter_validator (switch_setter , 1 , 2)){
                                cout << "Please enter your choose again : ";
                                cin >> switch_setter;
                            }

                            stringstream switch_setter_before_covert(switch_setter);
                            int switch_setter_after_covert = 0;
                            switch_setter_before_covert >> switch_setter_after_covert;


                            switch (switch_setter_after_covert) {
                                case 1: {
                                    cout << "Please enter ID of doctor : " << endl;
                                    string id;
                                    cin >> id;
                                    while (!Id_Validate_for_fire(All_Of_Doctors, id)) {
                                        cout << "please enter id of doctor again :";
                                        cin >> id;
                                    }
                                    Show_Specific_Staff(All_Of_Doctors, id);

                                    break;
                                }
                                case 2: {
                                    for (int i = 0; i < All_Of_Doctors.size(); ++i) {
                                        for (int j = 0; j < All_Of_Doctors[i].doctor_all_ino_getter().size(); ++j) {
                                            cout << All_Of_Doctors[i].doctor_all_ino_getter()[j] << endl;
                                        }
                                        cout << endl;
                                    }

                                    /// Show all doctors with details

                                    break;
                                }

                            }

                            break;
                        }
                        case 6: {
                         //   int switch_setter;
                            cout << "1 = find specific nurser . " << endl;
                            cout << "2 = Show all nurses with details . " << endl;
                            cin >> switch_setter;

                            while (!Switch_Setter_validator (switch_setter , 1 , 2)){
                                cout << "Please enter your choose again : ";
                                cin >> switch_setter;
                            }

                            stringstream switch_setter_before_covert(switch_setter);
                            int switch_setter_after_covert = 0;
                            switch_setter_before_covert >> switch_setter_after_covert;

                            switch (switch_setter_after_covert) {
                                case 1: {
                                    cout << "Please enter ID of nurse : " << endl;
                                    string id;
                                    cin >> id;
                                    while (!Id_Validate_for_fire(All_Of_Nurses, id)) {
                                        cout << "please enter id of doctor again :";
                                        cin >> id;
                                    }
                                    Show_Specific_Staff(All_Of_Nurses, id);

                                    break;
                                }
                                case 2: {
                                    for (int i = 0; i < All_Of_Nurses.size(); ++i) {
                                        for (int j = 0; j < All_Of_Nurses[i].nurse_all_ino_getter().size(); ++j) {
                                            cout << All_Of_Nurses[i].nurse_all_ino_getter()[j] << endl;
                                        }
                                        cout << endl;
                                    }

                                    /// Show all nurses with details

                                    break;
                                }

                            }

                            break;

                        }
                        case 7: {
                            Show_Doctors_Timetable();
                            ///cout timetable of doctors.
                            break;
                        }
                        case 8: {
                            Show_Nurses_Timetable();
                            ///cout timetable of nurses.
                            break;
                        }
                        case 9: {
                            cout << "Enter id of doctor you want to edit his/her ino " << endl;
                            string id;
                            cin >> id;
                            while (!admin.Existence_Of_Id_For_Doctors(All_Of_Doctors ,id)) {
                                cout << "enter your id again" << endl;
                                cin >> id;
                            }

                            cout << "Which item do you want to edit ? " << endl;
                            cout << "1 = id " << endl;
                            cout << "2 = name " << endl;
                            cout << "3 = last_Name " << endl;
                            cout << "4 = phone_number " << endl;
                            cout << "5 = user_name" << endl;
                            cout << "6 = password " << endl;
                            cout << "7 = age " << endl;
                            cout << "8 = field " << endl;
                            cout << "9 = day & time " << endl;

                            cin >> switch_setter;


                            while (!Switch_Setter_validator (switch_setter , 1 , 9)){
                                cout << "Please enter your choose again : ";
                                cin >> switch_setter;
                            }

                            stringstream switch_setter_before_covert(switch_setter);
                            int switch_setter_after_covert = 0;
                            switch_setter_before_covert >> switch_setter_after_covert;

                            string new_id;


                            switch (switch_setter_after_covert) {
                                case 1 : {
                                    cout << "Enter you new id : ";
                                    cin >> new_id;
                                    while ( !admin.Id_Validate(All_Of_Doctors ,new_id)) {
                                        cout << "enter your id again" << endl;
                                        cin >> new_id;
                                    }

                               //     string previous_id = admin.Find_Doctor_From_His_Id(All_Of_Doctors, id)->Id_Getter();
                            //   Doctor temp_doctor = admin.Find_Doctor_From_His_Id(All_Of_Doctors, id)- ;

                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors, id)->doctor_all_ino_setter(0,new_id);
                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors, new_id)->Id_Setter(new_id);

                                    cout << "you changed id successfully ..." << endl;
                                    break;
                                }
                                case 2 : {
                                    cout << "Enter you new name : ";
                                    string name;
                                    cin >> name;
                                    while (!admin.Name_Validate(name)) {
                                        cout << "enter your name again" << endl;
                                        cin >> name;
                                    }
                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors, id)->Name_Setter(name);
                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors, id)->doctor_all_ino_getter()[1] = name;
                                    cout << "you changed name successfully ..." << endl;
                                    break;
                                }
                                case 3 : {
                                    cout << "Enter you new last_name : ";
                                    string last_name;
                                    cin >> last_name;
                                    while (!admin.Last_Name_Validate(last_name)) {
                                        cout << "enter your last_name again" << endl;
                                        cin >> last_name;
                                    }
                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors,
                                                                  id)->doctor_all_ino_getter()[2] = last_name;
                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors, id)->Last_Name_Setter(last_name);
                                    cout << "you changed last_name successfully ..." << endl;
                                    break;

                                }
                                case 4 : {
                                    cout << "Enter you new phone_number : ";
                                    string phone_number;
                                    cin >> phone_number;
                                    while (!admin.Phone_number_Validate(phone_number, All_Of_Nurses , All_Of_Doctors ,All_Of_Patients )) {
                                        cout << "enter your phone_number again" << endl;
                                        cin >> phone_number;
                                    }
                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors, id)->Phone_number_Setter(phone_number);
                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors,
                                                                  id)->doctor_all_ino_getter()[3] = phone_number;
                                    cout << "you changed phone_number successfully ..." << endl;
                                    break;

                                }
                                case 5 : {
                                    cout << "Enter you new user_name : ";
                                    string user_name;
                                    cin >> user_name;
                                    while (!admin.User_name_Validate(user_name , All_Of_Nurses , All_Of_Doctors ,All_Of_Patients)) {
                                        cout << "enter your username again " << endl;
                                        cin >> user_name;
                                    }
                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors, id)->User_name_Setter(user_name);
                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors,
                                                                  id)->doctor_all_ino_getter()[4] = user_name;
                                    cout << "you changed user_name successfully ..." << endl;
                                    break;
                                }
                                case 6 : {
                                    cout << "Enter you new password : ";
                                    string password;
                                    cin >> password;
                                    while (!admin.Password_Validate(password,All_Of_Nurses , All_Of_Doctors ,All_Of_Patients)) {
                                        cout << "enter your password again :" << endl;
                                        cin >> password;
                                    }
                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors, id)->Password_Setter(password);
                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors,
                                                                  id)->doctor_all_ino_setter(5,password);

                                    cout << "you changed password successfully ..." << endl;
                                    break;
                                }
                                case 7 : {
                                    cout << "Enter you new age : ";
                                    string age;
                                    cin >> age;
                                    while (!admin.Age_Validate(age)) {
                                        cout << "enter your age again :" << endl;
                                        cin >> age;
                                    }
                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors, id)->Age_Setter(age);
                                    Find_Doctor_From_His_Id(All_Of_Doctors, id)->doctor_all_ino_getter()[6] = age;
                                    cout << "you changed age successfully ..." << endl;
                                    break;
                                }
                                case 8 : {
                                    cout << "Enter your new field : "<<endl;
                                    cout << "1 = Dentist " << endl;
                                    cout << "2 = Dermatologists " << endl;
                                    cout << "3=  Emergency Medicine Specialists " << endl;
                                    cout << "4 = Plastic Surgeon " << endl;
                                    cout << "5 = Radiologists " << endl;
                                    cout << "6 = Sports Medicine Specialists " << endl;
                                    cout << "7 = General Surgeon " << endl;
                                    cout << "8 = Ophthalmologists " << endl;
                                    cout << "9 = Neurologists " << endl;

                                    string field;
                                    cin >> field;

                                    while (!Switch_Setter_validator (field , 1 , 9)){
                                        cout << "Please enter your choose again : ";
                                        cin >> field;
                                    }

                                    stringstream field_before_covert(field);
                                    int field_after_covert = 0;
                                    field_before_covert >> field_after_covert;

                                    string Field;

                                    while (!admin.validate_String_Must_Be_Number(field) &&
                                           !admin.Day_Validate(field_after_covert)) {
                                        cout << "1 = Dentist " << endl;
                                        cout << "2 = Dermatologists " << endl;
                                        cout << "3=  Emergency Medicine Specialists " << endl;
                                        cout << "4 = Plastic Surgeon " << endl;
                                        cout << "5 = Radiologists " << endl;
                                        cout << "6 = Sports Medicine Specialists " << endl;
                                        cout << "7 = General Surgeon " << endl;
                                        cout << "8 = Ophthalmologists " << endl;
                                        cout << "9 = Neurologists " << endl;

                                        string field;
                                        cin >> field;

                                        while (!Switch_Setter_validator (field , 1 , 9)){
                                            cout << "Please enter your choose again : ";
                                            cin >> field;
                                        }

                                        stringstream field_before_covert(field);
                                        int field_after_covert = 0;
                                        field_before_covert >> field_after_covert;

                                    }
                                    switch (field_after_covert) {
                                        case 1: {
                                            Field = "Dentist";
                                            break;
                                        }
                                        case 2: {
                                            Field = "Dermatologists";
                                            break;
                                        }
                                        case 3: {
                                            Field = "Emergency-Medicine-Specialists";
                                            break;
                                        }
                                        case 4: {
                                            Field = "Plastic-Surgeon";
                                            break;
                                        }
                                        case 5: {
                                            Field = "Radiologists";
                                            break;
                                        }
                                        case 6: {
                                            Field = "Sports-Medicine-Specialists";
                                            break;
                                        }
                                        case 7: {
                                            Field = "General-Surgeon";
                                            break;
                                        }
                                        case 8: {
                                            Field = "Ophthalmologists";
                                            break;
                                        }
                                        case 9: {
                                            Field = "Neurologists";
                                            break;
                                        }
                                    }

                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors, id)->Field_setter(Field);
                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors,
                                                                  id)->doctor_all_ino_setter(8,Field) ;
                                    cout << "you changed field successfully ..." << endl;
                                    break;
                                }
                                case 9 : {

                                    cout << "Please enter your new day : ";
                                    cout << "1 = Monday" << endl;
                                    cout << "2 = Tuesday" << endl;
                                    cout << "3 = Wednesday" << endl;
                                    cout << "4 = Thursday" << endl;
                                    cout << "5 = Friday" << endl;
                                    cout << "6 = Saturday" << endl;
                                    cout << "7 = Sunday" << endl;

                                    string day;
                                    cin >> day;

                                    while (!Switch_Setter_validator (day , 1 , 7)){
                                        cout << "Please enter your choose again : ";
                                        cin >> day;
                                    }

                                    stringstream day_before_covert(day);
                                    int day_after_covert = 0;
                                    day_before_covert >> day_after_covert;

                                    string Day;

                                    while (!admin.validate_String_Must_Be_Number(day) &&
                                           !admin.Day_Validate(day_after_covert)) {
                                        cout << "Please enter your new again : ";
                                        cout << "1 = Monday" << endl;
                                        cout << "2 = Tuesday" << endl;
                                        cout << "3 = Wednesday" << endl;
                                        cout << "4 = Thursday" << endl;
                                        cout << "5 = Friday" << endl;
                                        cout << "6 = Saturday" << endl;
                                        cout << "7 = Sunday" << endl;

                                        cin >> day;

                                        while (!Switch_Setter_validator (day , 1 , 7)){
                                            cout << "Please enter your choose again : ";
                                            cin >> day;
                                        }

                                        stringstream day_before_covert(day);
                                        int day_after_covert = 0;
                                        day_before_covert >> day_after_covert;

                                    }
                                    switch (day_after_covert) {
                                        case 1: {
                                            Day = "Monday";
                                            break;
                                        }
                                        case 2: {
                                            Day = "Tuesday";
                                            break;
                                        }
                                        case 3: {
                                            Day = "Wednesday";
                                            break;
                                        }
                                        case 4: {
                                            Day = "Thursday";
                                            break;
                                        }
                                        case 5: {
                                            Day = "Friday";
                                            break;
                                        }
                                        case 6: {
                                            Day = "Saturday";
                                            break;
                                        }
                                        case 7: {
                                            Day = "Sunday";
                                            break;
                                        }

                                    }


                                    cout << "Please enter your on-call shift : ";
                                    cout << "1 = 8->12" << endl;
                                    cout << "2 = 12->16" << endl;
                                    cout << "3 = 16->20" << endl;
                                    cout << "4 = 20->24" << endl;
                                    cout << "5 = 24->4" << endl;
                                    cout << "6 = 4->8" << endl;

                                    string time;
                                    cin >> time;

                                    while (!Switch_Setter_validator (day , 1 , 6)){
                                        cout << "Please enter your choose again : ";
                                        cin >> day;
                                    }

                                    stringstream time_before_covert(time);
                                    int time_after_covert = 0;
                                    time_before_covert >> time_after_covert;

                                    string Time;

                                    while (!admin.validate_String_Must_Be_Number(time) &&
                                           !admin.Day_Validate(time_after_covert)) {
                                        cout << "Please enter your on-call shift again : ";
                                        cout << "1 = 8->12" << endl;
                                        cout << "2 = 12->16" << endl;
                                        cout << "3 = 16->20" << endl;
                                        cout << "4 = 20->24" << endl;
                                        cout << "5 = 24->4" << endl;
                                        cout << "6 = 4->8" << endl;

                                        cin >> time;

                                        while (!Switch_Setter_validator (day , 1 , 7)){
                                            cout << "Please enter your choose again : ";
                                            cin >> day;
                                        }

                                        stringstream time_before_covert(time);
                                        int time_after_covert = 0;
                                        time_before_covert >> time_after_covert;

                                    }
                                    switch (time_after_covert) {
                                        case 1: {
                                            Time = "8->12";
                                            break;
                                        }
                                        case 2: {
                                            Time = "12->16";
                                            break;
                                        }
                                        case 3: {
                                            Time = "16->20";
                                            break;
                                        }
                                        case 4: {
                                            Time = "20->24";
                                            break;
                                        }
                                        case 5: {
                                            Time = "24->4";
                                            break;
                                        }
                                        case 6: {
                                            Time = "4->8";
                                            break;
                                        }
                                    }
                                    admin.Delete_Befores_Doctor_Call_Shift_On_Timetable(*
                                                                                                admin.Find_Doctor_From_His_Id(All_Of_Doctors, id));



                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors, id)->Day_Setter(Day);
                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors, id)->Time_setter(Time);

                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors, id)->doctor_all_ino_setter(9,Day) ;
                                    admin.Find_Doctor_From_His_Id(All_Of_Doctors,
                                                                  id)->doctor_all_ino_setter(10,Time);

                                    admin.Doctors_Timetable_Setter(day_after_covert, time_after_covert,
                                                                   Find_Doctor_From_His_Id(All_Of_Doctors,
                                                                                           id)->doctor_all_ino_getter()[2]);
                                    cout << "you changed day & time successfully ..." << endl;
                                    break;
                                }
                            }


                            AoD.open("Doctors.txt");
                            Update_Doctor_File(All_Of_Doctors, reinterpret_cast<ofstream &>(AoD));
                            AoP.close();


                            AoD.open("Doctors.txt");
                            Update_Doctors_Time_Table_File (Doctors_Timetable , reinterpret_cast<ofstream &>(AoD));
                            AoP.close();

                            break;
                        }
                        case 10: {
                            cout << "Enter id of nurse you want to edit his/her ino " << endl;
                            string id;
                            cin >> id;
                            while (!admin.Id_Validate(All_Of_Nurses, id)) {
                                cout << "enter your id again" << endl;
                                cin >> id;
                            }

                            cout << "Which item do you want to edit ? " << endl;
                            cout << "1 = id " << endl;
                            cout << "2 = name " << endl;
                            cout << "3 = last_Name " << endl;
                            cout << "4 = phone_number " << endl;
                            cout << "5 = user_name" << endl;
                            cout << "6 = password " << endl;
                            cout << "7 = age " << endl;
                            cout << "8 = field " << endl;
                            cout << "9 = day & time " << endl;

                            cin >> switch_setter;

                            while (!Switch_Setter_validator (switch_setter , 1 , 9)){
                                cout << "Please enter your choose again : ";
                                cin >> switch_setter;
                            }

                            stringstream switch_setter_before_covert(switch_setter);
                            int switch_setter_after_covert = 0;
                            switch_setter_before_covert >> switch_setter_after_covert;


                            switch (switch_setter_after_covert) {
                                case 1 : {
                                    cout << "Enter you new id : ";
                                    cin >> id;
                                    while (!admin.Id_Validate(All_Of_Nurses, id)) {
                                        cout << "enter your id again" << endl;
                                        cin >> id;
                                    }
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses, id)->Id_Setter(id);
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses, id)->nurse_all_ino_getter()[0] = id;
                                    cout << "you changed id successfully ..." << endl;
                                    break;
                                }
                                case 2 : {
                                    cout << "Enter you new name : ";
                                    string name;
                                    cin >> name;
                                    while (!admin.Name_Validate(name)) {
                                        cout << "enter your name again" << endl;
                                        cin >> name;
                                    }
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses, id)->Name_Setter(name);
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses, id)->nurse_all_ino_getter()[1] = name;
                                    cout << "you changed name successfully ..." << endl;
                                    break;
                                }
                                case 3 : {
                                    cout << "Enter you new last_name : ";
                                    string last_name;
                                    cin >> last_name;
                                    while (!admin.Last_Name_Validate(last_name)) {
                                        cout << "enter your last_name again" << endl;
                                        cin >> last_name;
                                    }
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses, id)->Last_Name_Setter(last_name);
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses,
                                                                 id)->nurse_all_ino_getter()[2] = last_name;
                                    cout << "you changed last_name successfully ..." << endl;
                                    break;

                                }
                                case 4 : {
                                    cout << "Enter you new phone_number : ";
                                    string phone_number;
                                    cin >> phone_number;
                                    while (!admin.Phone_number_Validate(phone_number, All_Of_Nurses , All_Of_Doctors ,All_Of_Patients )) {
                                        cout << "enter your phone_number again" << endl;
                                        cin >> phone_number;
                                    }
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses, id)->Phone_number_Setter(phone_number);
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses,
                                                                 id)->nurse_all_ino_getter()[3] = phone_number;
                                    cout << "you changed phone_number successfully ..." << endl;
                                    break;

                                }
                                case 5 : {
                                    cout << "Enter you new user_name : ";
                                    string user_name;
                                    cin >> user_name;
                                    while (!admin.User_name_Validate(user_name , All_Of_Nurses , All_Of_Doctors ,All_Of_Patients)) {
                                        cout << "enter your username again " << endl;
                                        cin >> user_name;
                                    }
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses, id)->User_name_Setter(user_name);
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses,
                                                                 id)->nurse_all_ino_getter()[4] = user_name;
                                    cout << "you changed user_name successfully ..." << endl;
                                    break;
                                }
                                case 6 : {
                                    cout << "Enter you new password : ";
                                    string password;
                                    cin >> password;
                                    while (!admin.Password_Validate(password,All_Of_Nurses , All_Of_Doctors ,All_Of_Patients)) {
                                        cout << "enter your password again :" << endl;
                                        cin >> password;
                                    }
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses, id)->Password_Setter(password);
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses,
                                                                 id)->nurse_all_ino_getter()[5] = password;
                                    cout << "you changed password successfully ..." << endl;
                                    break;
                                }
                                case 7 : {
                                    cout << "Enter you new age : ";
                                    string age;
                                    cin >> age;
                                    while (!admin.Age_Validate(age)) {
                                        cout << "enter your age again :" << endl;
                                        cin >> age;
                                    }
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses, id)->Age_Setter(age);
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses, id)->nurse_all_ino_getter()[6] = age;
                                    cout << "you changed age successfully ..." << endl;
                                    break;
                                }
                                case 8 : {

                                    cout << "Please enter new Nurse field : ";
                                    cout << "1 = Registered nurse " << endl;
                                    cout << "2 = Licensed practical nurse " << endl;
                                    cout << "3=  Medical-surgical nurse " << endl;
                                    cout << "4 = Nurse practitioner " << endl;
                                    cout << "5 = Emergency room nurse " << endl;
                                    cout << "6 = Nursing assistant " << endl;
                                    cout << "7 = Nurse case manager " << endl;
                                    cout << "8 = Home health nurse " << endl;
                                    cout << "9 = Staff nurse " << endl;

                                    string field;
                                    cin >> field;

                                    while (!Switch_Setter_validator (field , 1 , 9)){
                                        cout << "Please enter your choose again : ";
                                        cin >> field;
                                    }

                                    stringstream field_before_covert(field);
                                    int field_after_covert = 0;
                                    field_before_covert >> field_after_covert;

                                    string Field;
                                    while (!admin.validate_String_Must_Be_Number(field) &&
                                           !admin.Day_Validate(field_after_covert)) {
                                        cout << "Please enter Nurse field again : ";
                                        cout << "1 = Registered nurse " << endl;
                                        cout << "2 = Licensed practical nurse " << endl;
                                        cout << "3=  Medical-surgical nurse " << endl;
                                        cout << "4 = Nurse practitioner " << endl;
                                        cout << "5 = Emergency room nurse " << endl;
                                        cout << "6 = Nursing assistant " << endl;
                                        cout << "7 = Nurse case manager " << endl;
                                        cout << "8 = Home health nurse " << endl;
                                        cout << "9 = Staff nurse " << endl;

                                        string field;
                                        cin >> field;

                                        while (!Switch_Setter_validator (field , 1 , 9)){
                                            cout << "Please enter your choose again : ";
                                            cin >> field;
                                        }

                                        stringstream field_before_covert(field);
                                        int field_after_covert = 0;
                                        field_before_covert >> field_after_covert;

                                    }
                                    switch (field_after_covert) {
                                        case 1: {
                                            Field = "Registered_nurse";
                                            break;
                                        }
                                        case 2: {
                                            Field = "Licensed_practical_nurse";
                                            break;
                                        }
                                        case 3: {
                                            Field = "Medical_surgical_nurse";
                                            break;
                                        }
                                        case 4: {
                                            Field = "Nurse_practitioner";
                                            break;
                                        }
                                        case 5: {
                                            Field = "Emergency_room_nurse";
                                            break;
                                        }
                                        case 6: {
                                            Field = "Nursing_assistant";
                                            break;
                                        }
                                        case 7: {
                                            Field = "Nurse_case_manager";
                                            break;
                                        }
                                        case 8: {
                                            Field = "Home_health_nurse";
                                            break;
                                        }
                                        case 9: {
                                            Field = "Staff_nurse";
                                            break;
                                        }

                                    }
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses, id)->Age_Setter(Field);
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses, id)->nurse_all_ino_getter()[7] = Field;
                                    cout << "you changed field successfully ..." << endl;
                                    break;
                                }
                                case 9 : {
                                    admin.Delete_Befores_Doctor_Call_Shift_On_Timetable(
                                            *admin.Find_Doctor_From_His_Id(All_Of_Doctors, id));


                                    cout << "Please enter your new day : ";
                                    cout << "1 = Monday" << endl;
                                    cout << "2 = Tuesday" << endl;
                                    cout << "3 = Wednesday" << endl;
                                    cout << "4 = Thursday" << endl;
                                    cout << "5 = Friday" << endl;
                                    cout << "6 = Saturday" << endl;
                                    cout << "7 = Sunday" << endl;

                                    string day;
                                    cin >> day;

                                    while (!Switch_Setter_validator (day , 1 , 7)){
                                        cout << "Please enter your choose again : ";
                                        cin >> day;
                                    }

                                    stringstream day_before_covert(day);
                                    int day_after_covert = 0;
                                    day_before_covert >> day_after_covert;

                                    string Day;

                                    while (!admin.validate_String_Must_Be_Number(day) &&
                                           !admin.Day_Validate(day_after_covert)) {
                                        cout << "Please enter your new again : ";
                                        cout << "1 = Monday" << endl;
                                        cout << "2 = Tuesday" << endl;
                                        cout << "3 = Wednesday" << endl;
                                        cout << "4 = Thursday" << endl;
                                        cout << "5 = Friday" << endl;
                                        cout << "6 = Saturday" << endl;
                                        cout << "7 = Sunday" << endl;

                                        cin >> day;

                                        while (!Switch_Setter_validator (day , 1 , 7)){
                                            cout << "Please enter your choose again : ";
                                            cin >> day;
                                        }

                                        stringstream day_before_covert(day);
                                        int day_after_covert = 0;
                                        day_before_covert >> day_after_covert;

                                    }
                                    switch (day_after_covert) {
                                        case 1: {
                                            Day = "Monday";
                                            break;
                                        }
                                        case 2: {
                                            Day = "Tuesday";
                                            break;
                                        }
                                        case 3: {
                                            Day = "Wednesday";
                                            break;
                                        }
                                        case 4: {
                                            Day = "Thursday";
                                            break;
                                        }
                                        case 5: {
                                            Day = "Friday";
                                            break;
                                        }
                                        case 6: {
                                            Day = "Saturday";
                                            break;
                                        }
                                        case 7: {
                                            Day = "Sunday";
                                            break;
                                        }

                                    }


                                    cout << "Please enter your on-call shift : ";
                                    cout << "1 = 8->12" << endl;
                                    cout << "2 = 12->16" << endl;
                                    cout << "3 = 16->20" << endl;
                                    cout << "4 = 20->24" << endl;
                                    cout << "5 = 24->4" << endl;
                                    cout << "6 = 4->8" << endl;

                                    string time;
                                    cin >> time;

                                    while (!Switch_Setter_validator (time , 1 , 6)){
                                        cout << "Please enter your choose again : ";
                                        cin >> time;
                                    }

                                    stringstream time_before_covert(time);
                                    int time_after_covert = 0;
                                    time_before_covert >> time_after_covert;

                                    string Time;

                                    while (!admin.validate_String_Must_Be_Number(time) &&
                                           !admin.Day_Validate(time_after_covert)) {
                                        cout << "Please enter your on-call shift again : ";
                                        cout << "1 = 8->12" << endl;
                                        cout << "2 = 12->16" << endl;
                                        cout << "3 = 16->20" << endl;
                                        cout << "4 = 20->24" << endl;
                                        cout << "5 = 24->4" << endl;
                                        cout << "6 = 4->8" << endl;

                                        cin >> time;

                                        while (!Switch_Setter_validator (time , 1 , 6)){
                                            cout << "Please enter your choose again : ";
                                            cin >> time;
                                        }

                                        stringstream time_before_covert(time);
                                        int time_after_covert = 0;
                                        time_before_covert >> time_after_covert;
                                    }
                                    switch (time_after_covert) {
                                        case 1: {
                                            Time = "8->12";
                                            break;
                                        }
                                        case 2: {
                                            Time = "12->16";
                                            break;
                                        }
                                        case 3: {
                                            Time = "16->20";
                                            break;
                                        }
                                        case 4: {
                                            Time = "20->24";
                                            break;
                                        }
                                        case 5: {
                                            Time = "24->4";
                                            break;
                                        }
                                        case 6: {
                                            Time = "4->8";
                                            break;
                                        }
                                    }


                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses, id)->Day_Setter(Day);
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses, id)->Time_setter(Time);

                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses, id)->nurse_all_ino_getter()[9] = Day;
                                    admin.Find_Nurse_From_His_Id(All_Of_Nurses, id)->nurse_all_ino_getter()[10] = Time;

                                    admin.Nurses_Timetable_Setter(day_after_covert, time_after_covert,
                                                                  Find_Doctor_From_His_Id(All_Of_Doctors,
                                                                                          id)->doctor_all_ino_getter()[2]);
                                    cout << "you changed day & time successfully ..." << endl;

                                    break;
                                }

                            }
                            AoN.open("Nurses.txt");
                            Update_Nurse_File(All_Of_Nurses, reinterpret_cast<ofstream &>(AoD));
                            AoN.close();


                            AoN.open("Nurses.txt");
                            Update_Nurses_Time_Table_File(Nurses_Timetable , reinterpret_cast<ofstream &>(AoD));
                            AoN.close();


                            break;
                        }
                        case 11:{a= false;}
                    }
                }
                break;
            }
            case 2: {

                cout << "-------------Patient Control Panel-------------" << endl;
                cout << "1 = Fill a new Form " << endl;
                cout << "2 = Already Have an account " << endl;
                cout << "3 = Exit " << endl;


                int choose;
                cin >> choose;

                switch (choose) {
                    case 1:{
                        cout << "enter your id : " << endl;
                        string id;
                        cin >> id;
                        while (!admin.Id_Validate(All_Of_Doctors, id)) {
                            cout << "enter your id again" << endl;
                            cin >> id;
                        }
                        cout << "enter your name : " << endl;
                        string name;
                        cin >> name;
                        while (!admin.Name_Validate(name)) {
                            cout << "enter your name again" << endl;
                            cin >> name;
                        }
                        cout << "enter your last_name :" << endl;
                        string last_name;
                        cin >> last_name;
                        while (!admin.Last_Name_Validate(last_name)) {
                            cout << "enter your last_name again" << endl;
                            cin >> last_name;
                        }

                        cout << "enter your phone_number :" << endl;
                        string phone_number;
                        cin >> phone_number;
                        while (!admin.Phone_number_Validate(phone_number, All_Of_Nurses , All_Of_Doctors ,All_Of_Patients )) {
                            cout << "enter your phone_number again" << endl;
                            cin >> phone_number;
                        }

                        cout << "enter your username :" << endl;
                        string username;
                        cin >> username;
                        while (!admin.User_name_Validate(username , All_Of_Nurses , All_Of_Doctors ,All_Of_Patients)) {
                            cout << "enter your username again " << endl;
                            cin >> username;
                        }
                        cout << "enter your password :" << endl;
                        string password;
                        cin >> password;
                        while (!admin.Password_Validate(password,All_Of_Nurses , All_Of_Doctors ,All_Of_Patients)) {
                            cout << "enter your password :" << endl;
                            cin >> password;
                        }

                        cout << "enter your age :" << endl;
                        string age;
                        cin >> age;
                        while (!admin.Age_Validate(age)) {
                            cout << "enter your age again :" << endl;
                            cin >> age;
                        }

                        cout << "enter your gender :" << endl;
                        cout << "1 - male "<<endl;
                        cout << "2 - female "<<endl;

                        string gender;
                        string gender_switch_setter;
                        cin >> gender_switch_setter;


                        while (!Switch_Setter_validator (gender_switch_setter , 1 , 2)){
                            cout << "Please enter your choose again : "<<endl;
                            cout << "1 - male "<<endl;
                            cout << "2 - female "<<endl;
                            cin >> gender_switch_setter;
                        }

                        stringstream gender_switch_setter_before_covert(gender_switch_setter);
                        int gender_switch_setter_after_covert = 0;
                        gender_switch_setter_before_covert >> gender_switch_setter_after_covert;

                        if (gender_switch_setter_after_covert == 1) gender = "male";
                        else if (gender_switch_setter_after_covert == 2) gender ="female";



                        string cost;
                        cout << "What doctor do you want to reserve ? :" << endl;
                        cout << "1 = Dentist " << endl;
                        cout << "2 = Dermatologists " << endl;
                        cout << "3=  Emergency Medicine Specialists " << endl;
                        cout << "4 = Plastic Surgeon " << endl;
                        cout << "5 = Radiologists " << endl;
                        cout << "6 = Sports Medicine Specialists " << endl;
                        cout << "7 = General Surgeon " << endl;
                        cout << "8 = Ophthalmologists " << endl;
                        cout << "9 = Neurologists " << endl;
                        string field;
                        cin >> field;

                        stringstream field_before_covert(field);
                        int field_after_covert = 0;
                        field_before_covert >> field_after_covert;


                        string Field;
                        while (!admin.validate_String_Must_Be_Number(field)) {
                            cout << "1 = Dentist " << endl;
                            cout << "2 = Dermatologists " << endl;
                            cout << "3=  Emergency Medicine Specialists " << endl;
                            cout << "4 = Plastic Surgeon " << endl;
                            cout << "5 = Radiologists " << endl;
                            cout << "6 = Sports Medicine Specialists " << endl;
                            cout << "7 = General Surgeon " << endl;
                            cout << "8 = Ophthalmologists " << endl;
                            cout << "9 = Neurologists " << endl;
                            string field;
                            cin >> field;
                            stringstream field_before_covert(field);
                            int field_after_covert = 0;
                            field_before_covert >> field_after_covert;
                        }
                        switch (field_after_covert) {
                            case 1: {
                                Field = "Dentist";
                                cost ="100";
                                break;
                            }
                            case 2: {
                                Field = "Dermatologists";
                                cost ="200";
                                break;
                            }
                            case 3: {
                                Field = "Emergency-Medicine-Specialists";
                                cost ="300";
                                break;
                            }
                            case 4: {
                                Field = "Plastic-Surgeon";
                                cost ="400";
                                break;
                            }
                            case 5: {
                                Field = "Radiologists";
                                cost ="600";
                                break;
                            }
                            case 6: {
                                Field = "Sports-Medicine-Specialists";
                                cost ="700";
                                break;
                            }
                            case 7: {
                                Field = "General-Surgeon";
                                cost ="550";
                                break;
                            }
                            case 8: {
                                Field = "Ophthalmologists";
                                cost ="460";
                                break;
                            }
                            case 9: {
                                Field = "Neurologists";
                                cost ="880";
                                break;
                            }
                        }

                        /*int x;*/
                        while (!admin.Find_Doctor_From_His_Field (All_Of_Doctors, Field )){
                            cout << "we dont have your wanted doctor please choose another one or exit !!!"<<endl;
                            cout << "choose another one : " << endl;
                            cout << "1 = Dentist " << endl;
                            cout << "2 = Dermatologists " << endl;
                            cout << "3=  Emergency Medicine Specialists " << endl;
                            cout << "4 = Plastic Surgeon " << endl;
                            cout << "5 = Radiologists " << endl;
                            cout << "6 = Sports Medicine Specialists " << endl;
                            cout << "7 = General Surgeon " << endl;
                            cout << "8 = Ophthalmologists " << endl;
                            cout << "9 = Neurologists " << endl;
                            cout << endl;
                            //   cout << "0 = exit " << endl;

                            cin >> field;
                            stringstream field_before_covert(field);
                            int field_after_covert = 0;
                            field_before_covert >> field_after_covert;


                            switch (field_after_covert) {
                                case 1: {
                                    Field = "Dentist";
                                    cost ="100";
                                    break;
                                }
                                case 2: {
                                    Field = "Dermatologists";
                                    cost ="200";
                                    break;
                                }
                                case 3: {
                                    Field = "Emergency-Medicine-Specialists";
                                    cost ="300";
                                    break;
                                }
                                case 4: {
                                    Field = "Plastic-Surgeon";
                                    cost ="400";
                                    break;
                                }
                                case 5: {
                                    Field = "Radiologists";
                                    cost ="600";
                                    break;
                                }
                                case 6: {
                                    Field = "Sports-Medicine-Specialists";
                                    cost ="700";
                                    break;
                                }
                                case 7: {
                                    Field = "General-Surgeon";
                                    cost ="550";
                                    break;
                                }
                                case 8: {
                                    Field = "Ophthalmologists";
                                    cost ="460";
                                    break;
                                }
                                case 9: {
                                    Field = "Neurologists";
                                    cost ="880";
                                    break;
                                }
                            }

                            /* cin >> x;*/
                            /*if (field== '0'){
                                break;
                            }*/
/*
                                    else continue ;*/

                        }


                   //     if(x==2)break; ///exit and didnt choose any doctor
                        string dammy,damy1,damy2;

                        Patient New_Patient{id, name, last_name, phone_number, username, password, age,gender,damy2,dammy,damy1};
                        All_Of_Patients.push_back(New_Patient);


                        cout << "enter number of your doctor"<<endl;
                        int choose;
                        cin >> choose ;
                        vector<int>index_of_found_doctors;
                        index_of_found_doctors = admin.Find_Doctor_From_His_Field_vector (All_Of_Doctors, Field);

                        admin.Add_TO_Bill (choose , index_of_found_doctors, All_Of_Doctors, New_Patient , cost ,All_Of_Patients, username, password);

                        AoP.open("Patients.txt");
                        Update_Patient_File (All_Of_Patients  , reinterpret_cast<ofstream &>(AoP));
                        AoP.close();


                        Bill.open("Bill.txt");
                        Update_Bill_File (All_Of_Patients , reinterpret_cast<ofstream &>(Bill));
                        Bill.close();




                        cout << "Patient added !!"<<endl;

                        break;
                    }
                    case 2:{

                        string username, password;
                        cout << "Username : ";
                        cin >> username;
                       cout << endl;
                        cout << "password : ";
                        cin >> password;

                        while (!admin.Validate_Patient_To_Enter (username ,password ,All_Of_Patients)){
                            cout << "Please Enter your username again : ";
                            cin >> username;
                            cout << "Please Enter your password again : ";
                            cin >> password;
                        }



                        int switch_setter;
                        cout << "1 = Book Your Doctors' Appointment " << endl;
                        cout << "2 = Check Your Bill " << endl;
                        cin >> switch_setter;
                        switch (switch_setter) {
                            case 1: {

                                string cost;
                                cout << "What doctor do you want to reserve ? :" << endl;
                                cout << "1 = Dentist " << endl;
                                cout << "2 = Dermatologists " << endl;
                                cout << "3=  Emergency Medicine Specialists " << endl;
                                cout << "4 = Plastic Surgeon " << endl;
                                cout << "5 = Radiologists " << endl;
                                cout << "6 = Sports Medicine Specialists " << endl;
                                cout << "7 = General Surgeon " << endl;
                                cout << "8 = Ophthalmologists " << endl;
                                cout << "9 = Neurologists " << endl;
                                string field;
                                cin >> field;

                                stringstream field_before_covert(field);
                                int field_after_covert = 0;
                                field_before_covert >> field_after_covert;


                                string Field;
                                while (!admin.validate_String_Must_Be_Number(field) &&
                                       !admin.Day_Validate(field_after_covert)) {
                                    cout << "1 = Dentist " << endl;
                                    cout << "2 = Dermatologists " << endl;
                                    cout << "3=  Emergency Medicine Specialists " << endl;
                                    cout << "4 = Plastic Surgeon " << endl;
                                    cout << "5 = Radiologists " << endl;
                                    cout << "6 = Sports Medicine Specialists " << endl;
                                    cout << "7 = General Surgeon " << endl;
                                    cout << "8 = Ophthalmologists " << endl;
                                    cout << "9 = Neurologists " << endl;
                                    string field;
                                    cin >> field;
                                    stringstream field_before_covert(field);
                                    int field_after_covert = 0;
                                    field_before_covert >> field_after_covert;
                                }
                                switch (field_after_covert) {
                                    case 1: {
                                        Field = "Dentist";
                                        cost ="100";
                                        break;
                                    }
                                    case 2: {
                                        Field = "Dermatologists";
                                        cost ="200";
                                        break;
                                    }
                                    case 3: {
                                        Field = "Emergency-Medicine-Specialists";
                                        cost ="300";
                                        break;
                                    }
                                    case 4: {
                                        Field = "Plastic-Surgeon";
                                        cost ="400";
                                        break;
                                    }
                                    case 5: {
                                        Field = "Radiologists";
                                        cost ="600";
                                        break;
                                    }
                                    case 6: {
                                        Field = "Sports-Medicine-Specialists";
                                        cost ="700";
                                        break;
                                    }
                                    case 7: {
                                        Field = "General-Surgeon";
                                        cost ="550";
                                        break;
                                    }
                                    case 8: {
                                        Field = "Ophthalmologists";
                                        cost ="460";
                                        break;
                                    }
                                    case 9: {
                                        Field = "Neurologists";
                                        cost ="880";
                                        break;
                                    }
                                }

                                /*int x;*/
                                while (!admin.Find_Doctor_From_His_Field (All_Of_Doctors, Field )){
                                    cout << "we dont have your wanted doctor please choose another one or exit !!!"<<endl;
                                    cout << "choose another one : " << endl;
                                    cout << "1 = Dentist " << endl;
                                    cout << "2 = Dermatologists " << endl;
                                    cout << "3=  Emergency Medicine Specialists " << endl;
                                    cout << "4 = Plastic Surgeon " << endl;
                                    cout << "5 = Radiologists " << endl;
                                    cout << "6 = Sports Medicine Specialists " << endl;
                                    cout << "7 = General Surgeon " << endl;
                                    cout << "8 = Ophthalmologists " << endl;
                                    cout << "9 = Neurologists " << endl;
                                    cout << endl;
                                 //   cout << "0 = exit " << endl;

                                    cin >> field;
                                    stringstream field_before_covert(field);
                                    int field_after_covert = 0;
                                    field_before_covert >> field_after_covert;


                                    switch (field_after_covert) {
                                        case 1: {
                                            Field = "Dentist";
                                            cost ="100";
                                            break;
                                        }
                                        case 2: {
                                            Field = "Dermatologists";
                                            cost ="200";
                                            break;
                                        }
                                        case 3: {
                                            Field = "Emergency-Medicine-Specialists";
                                            cost ="300";
                                            break;
                                        }
                                        case 4: {
                                            Field = "Plastic-Surgeon";
                                            cost ="400";
                                            break;
                                        }
                                        case 5: {
                                            Field = "Radiologists";
                                            cost ="600";
                                            break;
                                        }
                                        case 6: {
                                            Field = "Sports-Medicine-Specialists";
                                            cost ="700";
                                            break;
                                        }
                                        case 7: {
                                            Field = "General-Surgeon";
                                            cost ="550";
                                            break;
                                        }
                                        case 8: {
                                            Field = "Ophthalmologists";
                                            cost ="460";
                                            break;
                                        }
                                        case 9: {
                                            Field = "Neurologists";
                                            cost ="880";
                                            break;
                                        }
                                    }

                                   /* cin >> x;*/
                                    /*if (field== '0'){
                                        break;
                                    }*/
/*
                                    else continue ;*/

                                }



                                cout << "enter number of your doctor"<<endl;
                                int choose;
                                cin >> choose ;
                             //   choose = choose - 1;
                                vector<int>index_of_found_doctors;
                                index_of_found_doctors = admin.Find_Doctor_From_His_Field_vector (All_Of_Doctors, Field);

                              //  string dammy;
                                admin.Add_TO_Bill (choose , index_of_found_doctors, All_Of_Doctors,
                                                 *Entered_Patient(username, password, All_Of_Patients), cost ,All_Of_Patients,username,password
                                );

                                AoP.open("Patients.txt");
                                Update_Patient_File (All_Of_Patients  , reinterpret_cast<ofstream &>(AoP));
                                AoP.close();


                                Bill.open("Bill.txt");
                                Update_Bill_File (All_Of_Patients , reinterpret_cast<ofstream &>(Bill));
                                Bill.close();


                                cout << "Your Doctors' Appointment Successfully Done ... " << endl;
                                break;
                            }
                            case 2: {
                                cout << "Your Bill : " << endl;
                                Entered_Patient(username ,password ,All_Of_Patients)->Show_Bill();
                                break;
                            }
                            default: {
                                cout << "Please enter between 1 or 2 !! ";

                            }
                        }

                    }
                    case 3:{
                    }
                }


                break;
            }
            case 3: {
                int choose;
                cout << "-------------Staff Control Panel-------------" << endl;
                cout << "1 - Enter as doctor "<<endl;
                cout << "2 - Enter as nurse  "<<endl;
                cout << "3 - Exit  "<<endl;


                cin >> choose;

                switch (choose) {
                    case 1: {
                        string username, password;
                        cout << "Enter your username & password : " << endl;
                        cout << "Username : ";
                        cin >> username;
                        cout << endl;
                        cout << "password : ";
                        cin >> password;
                        cout << endl;
                        while(!Validate_Doctor_To_Enter (username , password , All_Of_Doctors)){
                            cout << "Enter your username & password again : " << endl;
                            cout << "Username : ";
                            cin >> username;
                            cout << endl;
                            cout << "password : ";
                            cin >> password;
                            cout << endl;
                        }

                        cout << "-------------Doctor Control Panel-------------" << endl;
                        int switch_setter;
                        cout << "1 - update ino " << endl;
                        cout << "2 - Show ino " << endl;
                        cout << "3 - Exit " << endl;
                        cin >> switch_setter;
                        switch (switch_setter) {
                            case 1: {
                                cout << "Which item do you want to change ?" << endl;
                                int choose;
                                cout << "1 - Phone number " << endl;
                                cout << "2 - User Name " << endl;
                                cout << "3 - Password " << endl;
                                cin >> choose;
                                switch (choose) {
                                    case 1: {
                                        cout << "Enter you new phone_number : ";
                                        string phone_number;
                                        cin >> phone_number;
                                        while (!admin.Phone_number_Validate(phone_number, All_Of_Nurses , All_Of_Doctors ,All_Of_Patients )) {
                                            cout << "enter your phone_number again" << endl;
                                            cin >> phone_number;
                                        }
                                        Entered_Doctor(username ,password ,All_Of_Doctors)->Phone_number_Setter(phone_number);
                                        Entered_Doctor(username ,password ,All_Of_Doctors)->doctor_all_ino_setter(3,phone_number);
                                        cout << "Your Phone number changed successfully" << endl;
                                        break;
                                    }
                                    case 2: {
                                        cout << "Enter you new user_name : ";
                                        string new_user_name;
                                        cin >> new_user_name;
                                        while (!admin.User_name_Validate(new_user_name, All_Of_Nurses , All_Of_Doctors ,All_Of_Patients)) {
                                            cout << "enter your username again " << endl;
                                            cin >> new_user_name;
                                        }
                                        Entered_Doctor(username ,password ,All_Of_Doctors)->User_name_Setter(new_user_name);
                                        Entered_Doctor(new_user_name ,password ,All_Of_Doctors)->doctor_all_ino_setter(4,new_user_name);

                                        cout << "Your User Name changed successfully" << endl;
                                        break;
                                    }
                                    case 3: {
                                        cout << "Enter you new password : ";
                                        string new_password;
                                        cin >> new_password;
                                        while (!admin.Password_Validate(new_password,All_Of_Nurses , All_Of_Doctors ,All_Of_Patients)) {
                                            cout << "enter your password again :" << endl;
                                            cin >> new_password;
                                        }
                                        Entered_Doctor(username ,password ,All_Of_Doctors)->Password_Setter(new_password);
                                        Entered_Doctor(new_password ,password ,All_Of_Doctors)->doctor_all_ino_setter(5,new_password);

                                        cout << "Your User Password changed successfully" << endl;
                                        break;
                                    }
                                    default: {
                                        cout << "Please enter between 1 or 3 !! ";
                                    }
                                        break;
                                }


                                AoD.open("Doctors.txt");
                                Update_Doctor_File(All_Of_Doctors, reinterpret_cast<ofstream &>(AoD));
                                AoP.close();

                                break;

                            }
                            case 2: {
                                for (int i = 0; i <Entered_Doctor(username ,password ,All_Of_Doctors)->doctor_all_ino_getter().size() ; ++i) {
                                    cout << Entered_Doctor(username ,password ,All_Of_Doctors)->doctor_all_ino_getter()[i]<<"    "<<endl;
                                }
                            }
                            case 3: {
                            }

                        }
                        break;
                    }
                    case 2: {
                        string username, password;
                        cout << "Enter your username & password : " << endl;
                        cout << "Username : ";
                        cin >> username;
                        cout << endl;
                        cout << "password : ";
                        cin >> password;
                        cout << endl;

                        while (! Validate_Nurse_To_Enter (username , password , All_Of_Nurses)){
                            cout << "Enter your username & password again : " << endl;
                            cout << "Username : ";
                            cin >> username;
                            cout << endl;
                            cout << "password : ";
                            cin >> password;
                            cout << endl;
                        }


                        int switch_setter;
                        cout << "1 - update ino " << endl;
                        cout << "2 - Show ino " << endl;
                        cout << "3 - Exit " << endl;
                        cin >> switch_setter;
                        switch (switch_setter) {
                            case 1: {
                                cout << "Which item do you want to change ?" << endl;
                                int choose;
                                cout << "1 - Phone number " << endl;
                                cout << "2 - User Name " << endl;
                                cout << "3 - Password " << endl;
                                cin >> choose;
                                switch (choose) {
                                    case 1: {
                                        cout << "Enter you new phone_number : ";
                                        string phone_number;
                                        cin >> phone_number;
                                        while (!admin.Phone_number_Validate(phone_number, All_Of_Nurses , All_Of_Doctors ,All_Of_Patients )) {
                                            cout << "enter your phone_number again" << endl;
                                            cin >> phone_number;
                                        }
                                        Entered_Nurse(username ,password ,All_Of_Nurses)->Phone_number_Setter(phone_number);
                                        Entered_Nurse(username ,password ,All_Of_Nurses)->nurse_all_ino_setter(3,phone_number);
                                        cout << "Your Phone number changed successfully" << endl;
                                        break;
                                    }
                                    case 2: {
                                        string User_Name;
                                        cout << "Enter your new User_Name : " << endl;
                                        cin >> User_Name;
                                        while (!admin.User_name_Validate(User_Name , All_Of_Nurses , All_Of_Doctors ,All_Of_Patients)) {
                                            cout << "enter your User_Name again" << endl;
                                            cin >> User_Name;
                                        }
                                        Entered_Nurse(username ,password ,All_Of_Nurses)->User_name_Setter(User_Name);
                                        Entered_Nurse(username ,password ,All_Of_Nurses)->nurse_all_ino_setter(4,User_Name);

                                        cout << "Your User Name changed successfully" << endl;
                                        break;
                                    }
                                    case 3: {
                                        string Password;
                                        cout << "Enter your new Password : " << endl;
                                        cin >> Password;

                                        while (!admin.Password_Validate(Password,All_Of_Nurses , All_Of_Doctors ,All_Of_Patients)) {
                                            cout << "enter your Password again" << endl;
                                            cin >> Password;
                                        }
                                        Entered_Nurse(username ,password ,All_Of_Nurses)->Password_Setter(Password);
                                        Entered_Nurse(username ,password ,All_Of_Nurses)->nurse_all_ino_setter(5,Password);

                                        cout << "Your User Password changed successfully" << endl;
                                        break;
                                    }
                                    default: {
                                        cout << "Please enter between 1 or 3 !! ";
                                    }

                                }

                                AoN.open("Nurses.txt");
                                Update_Nurse_File(All_Of_Nurses, reinterpret_cast<ofstream &>(AoD));
                                AoN.close();

                                break;

                            }
                            case 2: {
                                for (int i = 0; i <Entered_Nurse(username ,password ,All_Of_Nurses)->nurse_all_ino_getter().size() ; ++i) {
                                    cout << Entered_Nurse(username ,password ,All_Of_Nurses)->nurse_all_ino_getter()[i]<<"    "<<endl;
                                }
                                break;
                            }
                            case 3: {
                                break;
                            }
                        }
                        break;
                    }
                    default: {
                        cout << "Please enter between 1 or 2 !! ";
                    }
                    case 3:{}
                }
                break;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////

Hospital :: Hospital() {
    Admin_Username = "123";
    Admin_Password = "78";
}

string Hospital ::Getter_Username(){
    return Admin_Username;
}

string Hospital ::Getter_Password(){
    return Admin_Password;
}

bool Hospital ::Validate_username_password(string user , string pass){
    if ((user != Admin_Username) || (pass != Admin_Password)){
        cout << "your Username or Password is incorrect !!! "<<endl;
        return false;
    }
    else {
        cout << "You entered successfully ..." << endl;
        return true;
    }
}


///////////////////////////////////////////////////////////////////////////////////


bool Hospital:: validate_String_Must_Be_Number(string id){
    int countr = 0;
    for (int i = 0; i <id.length() ; ++i) {
        if(id[i]>=48 && id[i]<=57 && id[0]!='0')countr ++;
        else {
            return false;
        }
    }
    if(countr == id.length())return true ;
}

bool Hospital::validate_String_Must_Be_character(string name) {
    int countr = 0;
    for (int i = 0; i <name.length() ; ++i) {
        if((name[i]>=65 && name[i]<=90) || (name[i]>=97 && name[i]<=122) )countr ++;
        else {
            return false;
        }
    }
    if(countr == name.length())return true ;
}


///////////////////////////////////////////////////////////////////////////////////



bool Hospital :: Id_Validate(vector<Doctor> All_Of_Doctors,string id) {
    try {
        if (!validate_String_Must_Be_Number(id)) {
            cout << "Your id must consist of numbers !" << endl;
            return false;
        } else if (id.length() != 8 ) {
            cout << "Your id length must be equal to 8 !" << endl;
            return false;

        } else if (Existence_Of_Id_For_Doctors(All_Of_Doctors, id)) {
            cout << "This id already exists !!!" << endl;   ///add bool func to search in file and check existence of id
            return false;
        } else throw id;
    }
    catch (string id) {
        cout << "your id entered successfully ." << endl;
        return true;
    }

}
///////////////////////////////////////////////////////////////////////////////////

bool Hospital :: Id_Validate_for_fire(vector<Doctor> All_Of_Doctors,string id){
    try {
        if(id.length() != 8) {
            cout <<"Your id length must be equal to 8 !"<<endl;
            return false;
        }
        else if(!validate_String_Must_Be_Number(id)) {
            cout <<"Your id must consist of numbers !"<<endl;
            return false;
        }
        else if(! Existence_Of_Id_For_Doctors(All_Of_Doctors ,id)){
            cout << "This id already not exists !!!"<<endl;   ///add bool func to search in file and check existence of id
            return false;
        }
        else throw id;
    }
    catch(string id) {
        cout << "your id entered successfully ."<<endl;
        return true;
    }
}

///////////////////////////////////////////////////////////////////////////////////

bool Hospital :: Id_Validate(vector<Nurse> All_Of_Nurses,string id) {
    try {
        if (id.length() != 8) {
            cout << "Your id length must be equal to 8 !" << endl;
            return false;
        } else if (!validate_String_Must_Be_Number(id)) {
            cout << "Your id must consist of numbers !" << endl;
            return false;

        } else if (Existence_Of_Id_For_Nurses(All_Of_Nurses, id)) {
            cout << "This id already exists !!!" << endl;   ///add bool func to search in file and check existence of id
            return false;
        } else throw id;
    }
    catch (string id) {
        cout << "your id entered successfully ." << endl;
        return true;
    }

}
///////////////////////////////////////////////////////////////////////////////////


bool Hospital :: Id_Validate_for_fire(vector<Nurse> All_Of_Nurses,string id){
    try {
        if(id.length() != 8) {
            cout <<"Your id lenght must be equal to 8 !"<<endl;
            return false;
        }
        else if(!validate_String_Must_Be_Number(id)) {
            cout <<"Your id must consist of numbers !"<<endl;
            return false;
        }
        else if(! Existence_Of_Id_For_Nurses(All_Of_Nurses ,id)){
            cout << "This id already not exists !!!"<<endl;   ///add bool func to search in file and check existence of id
            return false;
        }
        else throw id;
    }
    catch(string id) {
        cout << "your id entered successfully ."<<endl;
        return true;
    }
}



bool Hospital :: Name_Validate(string Name){
    try {
        if(!validate_String_Must_Be_character(Name)){
            cout <<"Your name must consist of numbers character !"<<endl;
            return false;
        }
        else throw Name;
    }
    catch(string Name) {
        cout << "your Name entered successfully ."<<endl;
        return true;
    }
}

///////////////////////////////////////////////////////////////////////////////////



bool Hospital :: Last_Name_Validate(string Last_Name){
    try {
        if(!validate_String_Must_Be_character(Last_Name)) {
            cout <<"Your Last_Name must consist of numbers character !"<<endl;
            return false;
        }
        else throw Last_Name;
    }
    catch(string Last_Name) {
        cout << "your Last_Name entered successfully ."<<endl;
        return true;
    }
}

///////////////////////////////////////////////////////////////////////////////////


bool Hospital :: Phone_number_Validate(string Phone_number , vector<Nurse> All_Of_Nurses , vector<Doctor> All_Of_Doctors , vector<Patient>All_Of_Patients ) {
    try {
        if (!validate_String_Must_Be_Number(Phone_number)) {
            cout << "Your Phone_number must consist of numbers numbers !" << endl;
            return false;

        } else if (Existence_Of_Phone_Number (Phone_number ,All_Of_Nurses ,All_Of_Doctors ,All_Of_Patients )){
            cout << "This Phone_number already exists !!!" << endl;
            return false;

        }

        else throw Phone_number;
    }
    catch(string Phone_number) {
        cout << "your Phone_number entered successfully ."<<endl;
        return true;
    }
}


///////////////////////////////////////////////////////////////////////////////////


bool Hospital :: User_name_Validate(string user_name , vector<Nurse> All_Of_Nurses , vector<Doctor> All_Of_Doctors , vector<Patient>All_Of_Patients ) {
    try {
        if (Existence_Of_User_Name (user_name , All_Of_Nurses , All_Of_Doctors ,All_Of_Patients )) {
            cout << "This user_name already exists !!!"<<endl;
            return false;
        }
        else throw user_name;
    }
    catch(string user_name) {
        cout << "your user_name entered successfully ."<<endl;
        return true;
    }
}

///////////////////////////////////////////////////////////////////////////////////



bool Hospital :: Password_Validate(string password , vector<Nurse> All_Of_Nurses , vector<Doctor> All_Of_Doctors , vector<Patient>All_Of_Patients) {
    try {
        if (Existence_Of_Password (password,All_Of_Nurses , All_Of_Doctors ,All_Of_Patients )) {
            cout << "This password already exists !!!"<<endl;   ///add bool func to search in file and check existence of user_name
            return false;
        }
        else throw password;
    }
    catch(string password) {
        cout << "your password  entered successfully ."<<endl;
        return true;
    }
}

///////////////////////////////////////////////////////////////////////////////////

bool Hospital :: Age_Validate(string age) {
    stringstream age_before_covert(age);
    int age_after_covert = 0;
    age_before_covert >> age_after_covert ;
    try {
        if (age_after_covert <= 0  || age_after_covert >= 125) {
            cout << "Your age must be greater than 0 and smaller than 125  !!!"<<endl;
            return false;

        }
        else throw age;
    }
    catch(string age) {
        cout << "your age entered successfully ."<<endl;
        return true;
    }
}

///////////////////////////////////////////////////////////////////////////////////

bool Hospital :: Day_Validate(int day){
    try {
        if((day < 0 || day>7)) {
            cout <<"your number must be between 1 and 7 !!"<<endl;

            return false;
        }
        else throw day;
    }
    catch(string day) {
        cout << "your day number entered successfully ." << endl;
        return true;

    }
}

///////////////////////////////////////////////////////////////////////////////////

bool Hospital :: Doctor_Field(int field){
    try {
        if((field < 0 || field>7)) {
            cout <<"your number must be between 1 and 7 !!"<<endl;

            return false;
        }
        else throw field;
    }
    catch(string field) {
        cout << "your field number entered successfully ." << endl;
        return true;

    }
}

///////////////////////////////////////////////////////////////////////////////////

void Hospital :: Remove_Doctor(vector<Doctor> &All_Of_Doctors, string id){

    for (int i = 0; i <All_Of_Doctors.size() ; ++i) {
        if(All_Of_Doctors[i].doctor_all_ino_getter()[0] == id){
            All_Of_Doctors.erase(All_Of_Doctors.begin()+i);
            ///remove from files
            break;
        }
    }
}


///////////////////////////////////////////////////////////////////////////////////


bool Hospital :: Existence_Of_Id_For_Doctors(vector<Doctor> All_Of_Doctors , string id){
    for (int i = 0; i <All_Of_Doctors.size() ; ++i) {
        if (All_Of_Doctors[i].doctor_all_ino_getter()[0] == id)
            return true;
        break;

    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////////

bool Hospital :: Existence_Of_Id_For_Nurses(vector<Nurse> All_Of_Nurses , string id){
    for (int i = 0; i <All_Of_Nurses.size() ; ++i) {
        if (All_Of_Nurses[i].nurse_all_ino_getter()[0] == id)
            return true;
        break;

    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////////
void Hospital :: Remove_Nurse(vector<Nurse>& All_Of_Nurses , string id){

    for (int i = 0; i <All_Of_Nurses.size() ; ++i) {
        if(All_Of_Nurses[i].nurse_all_ino_getter()[0] == id){
            All_Of_Nurses.erase(All_Of_Nurses.begin()+i);
            ///remove from files
            break;
        }
    }
}


///////////////////////////////////////////////////////////////////////////////////

void Hospital:: Show_Specific_Staff(vector<Doctor> All_Of_Doctors , string id){
    for (int i = 0; i <All_Of_Doctors.size() ; ++i) {
        if (All_Of_Doctors[i].doctor_all_ino_getter()[0]==id){
            for (int j = 0; j <All_Of_Doctors[i].doctor_all_ino_getter().size() ; ++j) {
                cout <<All_Of_Doctors[i].doctor_all_ino_getter()[j]<<endl;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////

void Hospital:: Show_Specific_Staff(vector<Nurse> All_Of_Nurses , string id){
    for (int i = 0; i <All_Of_Nurses.size() ; ++i) {
        if (All_Of_Nurses[i].nurse_all_ino_getter()[0]==id){
            for (int j = 0; j <All_Of_Nurses[i].nurse_all_ino_getter().size() ; ++j) {
                cout <<All_Of_Nurses[i].nurse_all_ino_getter()[j]<<endl;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////


vector<vector<string>> Hospital :: Doctors_Timetable {

        {"    0    ", "    0    ", "    0    ", "    0    ","    0    ", "    0    "},
        {"    0    ", "    0    ", "    0    ", "    0    ","    0    ", "    0    "},
        {"    0    ", "    0    ", "    0    ", "    0    ","    0    ", "    0    "},
        {"    0    ", "    0    ", "    0    ", "    0    ","    0    ", "    0    "},
        {"    0    ", "    0    ", "    0    ", "    0    ","    0    ", "    0    "},
        {"    0    ", "    0    ", "    0    ", "    0    ","    0    ", "    0    "},
        {"    0    ", "    0    ", "    0    ", "    0    ","    0    ", "    0    "}
};

vector<vector<string>> Hospital :: Doctors_Timetable_Getter() {
    return Doctors_Timetable;
}


void Hospital :: Doctors_Timetable_Setter(int day , int time ,string last_name) {

    Doctors_Timetable[day][time] = "    " + last_name + "    ";
    cout << "Doctor s on-call shift added !!"<<endl;
}

void Hospital :: Show_Doctors_Timetable() {
  //  Table table;

  //  table.add_row({ "         ","  8->12  ","  12->16  ","  16->20  ","  20->24  ","  24->4  ","  4->8  "});



    vector< string >days {" Monday   "," Tuesday   "," Wednesday"," Thursday "," Friday   "," Saturday "," Sunday   "};
  cout <<"         "<<"  8->12  "<<"  12->16  "<<"  16->20  "<<"  20->24  "<<"  24->4  "<<"  4->8  "<<endl;
   // Table Doctors_Timetable;
    for (int i = 0; i <Doctors_Timetable.size() ; ++i) {
        cout <<days[i];
        for (int j = 0; j <Doctors_Timetable[0].size() ; ++j) {
          //  table.add_row({days[i],Doctors_Timetable[i][0],Doctors_Timetable[i][1],Doctors_Timetable[i][2],Doctors_Timetable[i][3],Doctors_Timetable[i][4],Doctors_Timetable[i][5]});
           cout <<Doctors_Timetable[i][j];
        }
       cout << endl;
    }

   // cout << table <<endl;
}



///////////////////////////////////////////////////////////////////////////////////


vector<vector<string>> Hospital :: Nurses_Timetable {

        {"    0    ", "    0    ", "    0    ", "    0    ","    0    ", "    0    "},
        {"    0    ", "    0    ", "    0    ", "    0    ","    0    ", "    0    "},
        {"    0    ", "    0    ", "    0    ", "    0    ","    0    ", "    0    "},
        {"    0    ", "    0    ", "    0    ", "    0    ","    0    ", "    0    "},
        {"    0    ", "    0    ", "    0    ", "    0    ","    0    ", "    0    "},
        {"    0    ", "    0    ", "    0    ", "    0    ","    0    ", "    0    "},
        {"    0    ", "    0    ", "    0    ", "    0    ","    0    ", "    0    "}
};

vector<vector<string>> Hospital :: Nurses_Timetable_Getter() {
    return Doctors_Timetable;
}


void Hospital :: Nurses_Timetable_Setter(int day , int time ,string last_name) {
    day = day -1;
    time = time-1;
    Nurses_Timetable[day][time] = last_name;
    cout << "Doctor s on-call shift added !!"<<endl;
}

void Hospital :: Show_Nurses_Timetable() {
    vector< string >days {" Monday   "," Tuesday   "," Wednesday"," Thursday "," Friday   "," Saturday "," Sunday   "};
    cout <<"         "<<"  8->12  "<<"  12->16  "<<"  16->20  "<<"  20->24  "<<"  24->4  "<<"  4->8  "<<endl;
    for (int i = 0; i <Nurses_Timetable.size() ; ++i) {
        cout <<days[i];
        for (int j = 0; j <Nurses_Timetable[0].size() ; ++j) {
            cout <<Nurses_Timetable[i][j];
        }
        cout << endl;
    }
}


///////////////////////////////////////////////////////////////////////////////////

Doctor* Hospital:: Find_Doctor_From_His_Id (vector<Doctor>& All_Of_Doctors,string id){
    for (int A = 0; A < All_Of_Doctors.size() ; ++A) {
        if (All_Of_Doctors[A].doctor_all_ino_getter()[0]==id)
            return  &All_Of_Doctors [A];
        break;
    }
}


void Hospital ::  Delete_Befores_Doctor_Call_Shift_On_Timetable(Doctor doctor){
    int cntr = 0;
    for (int i = 0; i <Doctors_Timetable.size() ; ++i) {
        for (int j = 0; j <Doctors_Timetable[0].size() ; ++j) {
            int pos=Doctors_Timetable[i][j].find(doctor.Last_Name_Getter());
            if (pos!=string::npos&&Doctors_Timetable[i][j].substr(pos,doctor.Last_Name_Getter().length()+1)==doctor.Last_Name_Getter()+" "){
                Doctors_Timetable_Setter(i,j,"    0    ");
           //     Doctors_Timetable[i][j] = "    0    ";
                cntr ++ ;
                break;
            }
        }
        if(cntr == 1)break;
    }
    cout << "Before Doctor s Call_Shift Deleted ... "<<endl;

}

///////////////////////////////////////////////////////////////////////////////////

Nurse* Hospital:: Find_Nurse_From_His_Id (vector<Nurse>& All_Of_Nurses,string id){
    for (int A = 0; A < All_Of_Nurses.size() ; ++A) {
        if (All_Of_Nurses[A].nurse_all_ino_getter()[0]==id)
            return &All_Of_Nurses[A];
        break;
    }
}


void Hospital:: Delete_Befores_Nurse_Call_Shift_On_Timetable(Nurse nurse){
    int cntr = 0;
    for (int i = 0; i <Nurses_Timetable.size() ; ++i) {
        for (int j = 0; j <Nurses_Timetable[0].size() ; ++j) {
            if (nurse.nurse_all_ino_getter()[2] == Nurses_Timetable[i][j] ) {
                Nurses_Timetable_Setter(i,j,"    0    ");
              //  Nurses_Timetable[i][j] = "    0    ";
                cntr ++ ;
                break;
            }
        }
        if(cntr == 1)break;
    }
    cout << "Before Doctor s Call_Shift Deleted ... "<<endl;
}

///////////////////////////////////////////////////////////////////////////////////

bool Hospital::  Find_Doctor_From_His_Field (vector<Doctor> All_Of_Doctors,string field){
    vector<int> found ;
    int cntr = 1;
    for (int i = 0; i <All_Of_Doctors.size() ; ++i) {
        if (All_Of_Doctors[i].Field_getter() == field){
            cout << cntr <<" = "<<All_Of_Doctors[i].Name_Getter()<<" " <<All_Of_Doctors[i].Last_Name_Getter()<<"       day : "<<All_Of_Doctors[i].Day_Getter()<<"      time : "<<All_Of_Doctors[i].Time_getter()<<endl;
            found.push_back(i);
            cntr ++;
        }
    }

    if(found.size() != 0 ){
        return true;
    } else return false;

}


vector<int>  Hospital::  Find_Doctor_From_His_Field_vector (vector<Doctor> All_Of_Doctors,string field){
    vector<int> finded ;
    for (int i = 0; i <All_Of_Doctors.size() ; ++i) {
        if (All_Of_Doctors[i].Field_getter() == field){
            finded.push_back(i);
        }
    }
    return finded;
}

void  Hospital::  Add_TO_Bill (int choose , vector<int>found , vector<Doctor>All_Of_Doctors, Patient &patient , string cost ,vector<Patient>&All_Of_Patients , string username , string password){

    vector<string>temp;

    temp.push_back(All_Of_Doctors[found[choose - 1]].Last_Name_Getter());
    temp.push_back(All_Of_Doctors[found[choose - 1]].Field_getter());
    temp.push_back(All_Of_Doctors[found[choose - 1]].Day_Getter());
    temp.push_back(All_Of_Doctors[found[choose - 1]].Time_getter());
    temp.push_back(cost);

    patient.Bill_Info_setter(temp);

    for (int i = 0; i <All_Of_Patients.size() ; ++i) {
        if(All_Of_Patients[i].User_name_Getter() == username   &&   All_Of_Patients[i].Password_Getter()==password){
            All_Of_Patients[i].Bill_Info_setter(temp);
            break;
        }
    }

}

///////////////////////////////////////////////////////////////////////////////////

bool Hospital :: Validate_Patient_To_Enter (string username , string password , vector<Patient>All_Of_Patients) {
    int cntr = 0;

    for (int i = 0; i < All_Of_Patients.size(); ++i) {
        if (All_Of_Patients[i].User_name_Getter() == username && All_Of_Patients[i].Password_Getter() == password) {
            cntr++;
            break;
        }
    }

    try {
        if (cntr == 0) {
            cout << "your username or password is incorrect ." << endl;
            return false;
        } else throw username;
    }
    catch (string username) {
        cout << "you entered successfully ." << endl;
        return true;
    }
}



Patient* Hospital :: Entered_Patient(string username , string password , vector<Patient>All_Of_Patients){
    int g =0;
    for (int i = 0; i < All_Of_Patients.size(); ++i) {
        if (All_Of_Patients[i].User_name_Getter() == username && All_Of_Patients[i].Password_Getter() == password) {
            g = i;
            break;
        }
    }

    return &All_Of_Patients[g];
}

///////////////////////////////////////////////////////////////////////////////////

bool Hospital :: Validate_Doctor_To_Enter (string username , string password , vector<Doctor> All_Of_Doctors){
    int cntr = 0;

    for (int i = 0; i < All_Of_Doctors.size(); ++i) {
        if (All_Of_Doctors[i].User_name_Getter() == username && All_Of_Doctors[i].Password_Getter() == password) {
            cntr++;
            break;
        }
    }

    try {
        if (cntr == 0) {
            cout << "your username or password is incorrect ." << endl;
            return false;
        } else throw username;
    }
    catch (string username) {
        cout << "you entered successfully ." << endl;
        return true;
    }
}

Doctor* Hospital :: Entered_Doctor(string username , string password , vector<Doctor> &All_Of_Doctors){
    int g =0;
    for (int i = 0; i < All_Of_Doctors.size(); ++i) {
        if (All_Of_Doctors[i].User_name_Getter() == username && All_Of_Doctors[i].Password_Getter() == password) {
            g = i;
            break;
        }
    }
    return &All_Of_Doctors[g];
}


///////////////////////////////////////////////////////////////////////////////////

bool Hospital :: Validate_Nurse_To_Enter (string username , string password , vector<Nurse> All_Of_Nurses){
    int cntr = 0;

    for (int i = 0; i < All_Of_Nurses.size(); ++i) {
        if (All_Of_Nurses[i].User_name_Getter() == username && All_Of_Nurses[i].Password_Getter() == password) {
            cntr++;
            break;
        }
    }

    try {
        if (cntr == 0) {
            cout << "your username or password is incorrect ." << endl;
            return false;
        } else throw username;
    }
    catch (string username) {
        cout << "you entered successfully ." << endl;
        return true;
    }
}

Nurse* Hospital :: Entered_Nurse(string username , string password , vector<Nurse> & All_Of_Nurses){
    int g =0;
    for (int i = 0; i < All_Of_Nurses.size(); ++i) {
        if (All_Of_Nurses[i].User_name_Getter() == username && All_Of_Nurses[i].Password_Getter() == password) {
            g = i;
            break;
        }
    }
    return &All_Of_Nurses[g];
}

///////////////////////////////////////////////////////////////////////////////////

bool Hospital:: Existence_Of_Phone_Number (string Phone_Number , vector<Nurse> All_Of_Nurses , vector<Doctor> All_Of_Doctors , vector<Patient>All_Of_Patients ){

    for (int i = 0; i <All_Of_Nurses.size() ; ++i) {
        if (All_Of_Nurses[i].Phone_number_Getter() == Phone_Number) return true;
    }
    for (int i = 0; i <All_Of_Doctors.size() ; ++i) {
        if (All_Of_Doctors[i].Phone_number_Getter() == Phone_Number) return true;
    }
    for (int i = 0; i <All_Of_Patients.size() ; ++i) {
        if (All_Of_Patients[i].Phone_number_Getter() == Phone_Number) return true;
    }
    return false;
}

bool Hospital:: Existence_Of_User_Name (string User_Name , vector<Nurse> All_Of_Nurses , vector<Doctor> All_Of_Doctors , vector<Patient>All_Of_Patients ){

    for (int i = 0; i <All_Of_Nurses.size() ; ++i) {
        if (All_Of_Nurses[i].User_name_Getter() == User_Name) return true;
    }
    for (int i = 0; i <All_Of_Doctors.size() ; ++i) {
        if (All_Of_Doctors[i].User_name_Getter() == User_Name) return true;
    }
    for (int i = 0; i <All_Of_Patients.size() ; ++i) {
        if (All_Of_Patients[i].User_name_Getter() == User_Name) return true;
    }
    return false;
}


bool Hospital:: Existence_Of_Password (string Password , vector<Nurse> All_Of_Nurses , vector<Doctor> All_Of_Doctors , vector<Patient>All_Of_Patients ){

    for (int i = 0; i <All_Of_Nurses.size() ; ++i) {
        if (All_Of_Nurses[i].Password_Getter() == Password) return true;
    }
    for (int i = 0; i <All_Of_Doctors.size() ; ++i) {
        if (All_Of_Doctors[i].Password_Getter()  == Password) return true;
    }
    for (int i = 0; i <All_Of_Patients.size() ; ++i) {
        if (All_Of_Patients[i].Password_Getter()  == Password) return true;
    }
    return false;
}



///////////////////////////////////////////////////////////////////////////////////

template<typename T>
void Hospital::Read_From_File_And_Create_Objects (vector<T>& All_Of_Humans , fstream& inFile){

    if (inFile.fail()){
        cerr << "Error opening file !!! " <<endl;
        exit(1) ;
    }

    int counter = 0 ;
    string item;
    vector<string>temp;
    string s=typeid(T).name();
    while(!inFile.eof()){

        inFile >> item ;
        temp.push_back(item);
        if(s.find("Nurse")!=string::npos && counter == 9){

            T New_Nurse(temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8],
                        temp[9] ,"salam");
            All_Of_Humans.push_back(New_Nurse);
            temp.clear();
            counter = -1;

        }
        else if(s.find("Doctor")!=string::npos  && counter == 10) {

            T New_Doctor(temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8],
                         temp[9], temp[10] );

            All_Of_Humans.push_back(New_Doctor);
            temp.clear();
            counter =-1;

        }
        else if (s.find("Patient")!=string::npos  && counter == 7) {

            T New_Patient(temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7],"salam1","salam1","salam2"
            );
            All_Of_Humans.push_back(New_Patient);
            temp.clear();
            counter = -1;
        }

        counter++;

    }
}


void Hospital::Read_From_File_And_Create_Timetable (vector<vector<string>>& Timetable , fstream& inFile) {

    if (inFile.fail()){
        cerr << "Error opening file 3!!! " <<endl;
        exit(1) ;
    }

    vector<string>temp;
    string item;
    int counter=0 , index = 0;

    while(!inFile.eof() && index != 7 ) {
        inFile >> item ;
        temp.push_back(item);

        if(counter==6){
            Timetable[index][0] ="    "+ temp[0]+ "    ";
            Timetable[index][1] ="    "+ temp[1]+ "    ";
            Timetable[index][2] ="    "+ temp[2]+ "    ";
            Timetable[index][3] ="    "+ temp[3]+ "    ";
            Timetable[index][4] ="    "+ temp[4]+ "    ";
            Timetable[index][5] ="    "+ temp[5]+ "    ";

//            Timetable[index][0] =temp[0];
//            Timetable[index][1] =temp[1];
//            Timetable[index][2] =temp[2];
//            Timetable[index][3] =temp[3];
//            Timetable[index][4] =temp[4];
//            Timetable[index][5] =temp[5];

            temp.clear();
            counter = 0;
            index++;
        }
        counter++;
    }

}

void Hospital::Read_From_File_And_Create_Bill (vector<Patient>&All_Of_Patients  , fstream& inFile ){

    if (inFile.fail()){
        cerr << "Error opening file !!! " <<endl;
        exit(1) ;
    }

    vector<string>temp;
    string items;
    int counter=0;
    int Patients_Index=0;

    while(!inFile.eof()) {

        getline(inFile, items);
        istringstream ss(items);
        string word;

        while (ss >> word)
        {
            temp.push_back(word);
            if(counter == 4){
                All_Of_Patients[Patients_Index].Bill_Info_getter().push_back(temp);
                temp.clear();
                counter = -1;
            }
            counter++;
        }
        Patients_Index++;
    }

}


///////////////////////////////////////////////////////////////////////////////////


void Hospital:: Update_Doctor_File (vector<Doctor>& All_Of_Doctors , ofstream& inFile) {
    system("pause");
  //  cout << "hiiiii";
    ofstream abus;
    abus.open("Doctors.txt");
    //abus <<"Asghar";

    for (int i = 0; i < All_Of_Doctors.size(); i++) {
        for (int j = 0; j < All_Of_Doctors[i].doctor_all_ino_getter().size(); ++j) {
            abus << All_Of_Doctors[i].doctor_all_ino_getter()[j] << " ";
//            abus <<"Asghar";
        }
        abus << "\n";
    }
    //inFile.close();

}
//}

///////////////////////////////////////////////////////////////////////////////////


void Hospital:: Update_Patient_File ( vector<Patient>&All_Of_Patients , ofstream& inFile) {
    system("pause");
    //  cout << "hiiiii";
    ofstream abus;
    abus.open("Patients.txt");
    //abus <<"Asghar";

    for (int i = 0; i < All_Of_Patients.size(); i++) {
        for (int j = 0; j < All_Of_Patients[i].patient_all_ino_getter().size(); ++j) {
            abus << All_Of_Patients[i].patient_all_ino_getter()[j] << " ";
//            abus <<"Asghar";
        }
        abus << "\n";
    }
    //inFile.close();

}
//}


///////////////////////////////////////////////////////////////////////////////////


void Hospital:: Update_Nurse_File (vector<Nurse>& All_Of_Nurses , ofstream& inFile) {
    system("pause");
    //  cout << "hiiiii";
    ofstream abus;
    abus.open("Nurses.txt");
    //abus <<"Asghar";

    for (int i = 0; i < All_Of_Nurses.size(); i++) {
        for (int j = 0; j < All_Of_Nurses[i].nurse_all_ino_getter().size(); ++j) {
            abus << All_Of_Nurses[i].nurse_all_ino_getter()[j] << " ";
//            abus <<"Asghar";
        }
        abus << "\n";
    }
    //inFile.close();

}
//}

///////////////////////////////////////////////////////////////////////////////////

//
void Hospital:: Update_Bill_File (vector<Patient>&All_Of_Patients , ofstream& inFile) {
    system("pause");
    //  cout << "hiiiii";
    ofstream abus;
    abus.open("Bill.txt");
    //abus <<"Asghar";

    for (int i = 0; i < All_Of_Patients.size(); i++) {
        for (int j = 0; j < All_Of_Patients[i].Bill_Info_getter().size(); ++j) {
            for (int k = 0; k <All_Of_Patients[i].Bill_Info_getter()[0].size() ; ++k) {
                abus << All_Of_Patients[i].Bill_Info_getter()[j][k] << " ";
            }
//            abus <<"Asghar";
        }
        abus << "\n";
    }
    //inFile.close();

}


///////////////////////////////////////////////////////////////////////////////////

//
void Hospital:: Update_Doctors_Time_Table_File (vector<vector<string>> Doctors_Timetable , ofstream& inFile) {

    system("pause");
    //  cout << "hiiiii";
    ofstream abus;
    abus.open("Doctors_Timetable.txt");
    //abus <<"Asghar";

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; ++j) {
            Doctors_Timetable[i][j] .erase(remove(Doctors_Timetable[i][j] .begin(), Doctors_Timetable[i][j] .end(), ' '), Doctors_Timetable[i][j] .end());
            //    Doctors_Timetable[i][j].erase(std::remove_if(Doctors_Timetable[i][j].begin(), Doctors_Timetable[i][j].end(), ::isspace), Doctors_Timetable[i][j].end());
                abus << Doctors_Timetable[i][j] << " ";
//            abus <<"Asghar";
        }
        abus << "\n";
    }
    //inFile.close();

}

///////////////////////////////////////////////////////////////////////////////////

//
void Hospital::  Update_Nurses_Time_Table_File (vector<vector<string>>& Nurses_Timetable , ofstream& inFile){
    system("pause");
    //  cout << "hiiiii";
    ofstream abus;
    abus.open("Nurses_Timetable.txt");
    //abus <<"Asghar";

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; ++j) {
     //       Nurses_Timetable[i][j].erase(std::remove_if(Nurses_Timetable[i][j].begin(), Nurses_Timetable[i][j].end(), ::isspace), Nurses_Timetable[i][j].end());
            abus << Nurses_Timetable[i][j] << " ";
//            abus <<"Asghar";
        }
        abus << "\n";
    }
    //inFile.close();

}





///////////////////////////////////////////////////////////////////////////////////


bool Hospital:: Switch_Setter_validator (string input , int first_of_range , int end_of_range){

    stringstream input_before_covert(input);
    int input_after_covert = 0;
    input_before_covert >> input_after_covert;

    try {
        if (!validate_String_Must_Be_Number(input)){
            cout << "Your input must be consist of numbers !!!"<<endl;
            return false;
        }
        else if (input_after_covert < first_of_range || input_after_covert > end_of_range) {
            cout << "Your input is out of our range !!!"<<endl;
            return false;
        }
        else throw input;
    }
    catch(string input) {
        cout << "your input entered successfully ."<<endl;
        return true;
    }
}


///////////////////////////////////////////////////////////////////////////////////
