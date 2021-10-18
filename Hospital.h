//
// Created by dell on 12/1/2020.
//

#ifndef FINAL_PROJECT_HOSPITAL_H
#define FINAL_PROJECT_HOSPITAL_H

/*#include <tabulate.hpp>*/
//using namespace tabulate;


#include <iostream>
#include <vector>

#include "Human.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"
using namespace std;
class Patient;

class Hospital {
private:
	static vector<vector<string>> Doctors_Timetable;
	static vector<vector<string>> Nurses_Timetable;
	string Admin_Username;
	string Admin_Password;




public:
    vector<Doctor> All_Of_Doctors;
    vector<Nurse> All_Of_Nurses;
    vector<Patient> All_Of_Patients;


    Hospital();
	void menu();
	string Getter_Username();
	string Getter_Password();



	static vector<vector<string>> Doctors_Timetable_Getter();
	void Doctors_Timetable_Setter(int day, int time, string last_name);
	void Show_Doctors_Timetable();

	static vector<vector<string>> Nurses_Timetable_Getter();
	void Nurses_Timetable_Setter(int day, int time, string last_name);
	void Show_Nurses_Timetable();

	bool Validate_username_password(string user, string pass);
	bool Id_Validate(vector<Doctor> All_Of_Doctors, string id);
	bool Id_Validate(vector<Nurse> All_Of_Nurses, string id);
	bool Id_Validate_for_fire(vector<Doctor> All_Of_Doctors, string id);
	bool Id_Validate_for_fire(vector<Nurse> All_Of_Nurses, string id);
	bool Name_Validate(string name);
	bool Last_Name_Validate(string last_name);
	bool Phone_number_Validate(string Phone_number, vector<Nurse> All_Of_Nurses, vector<Doctor> All_Of_Doctors, vector<Patient>All_Of_Patients);
	bool User_name_Validate(string id, vector<Nurse> All_Of_Nurses, vector<Doctor> All_Of_Doctors, vector<Patient>All_Of_Patients);
	bool Password_Validate(string password, vector<Nurse> All_Of_Nurses, vector<Doctor> All_Of_Doctors, vector<Patient>All_Of_Patients);
	bool Age_Validate(string age);
	bool validate_String_Must_Be_Number(string id);
	bool validate_String_Must_Be_character(string name);
	bool Day_Validate(int day);
	bool Doctor_Field(int field);

	void Remove_Doctor( vector<Doctor>& All_Of_Doctors, string id);
	void Remove_Nurse( vector<Nurse>& All_Of_Nurses, string id);

	bool Existence_Of_Id_For_Doctors(vector<Doctor> All_Of_Doctors, string id);
	bool Existence_Of_Id_For_Nurses(vector<Nurse> All_Of_Nurses, string id);

	void Show_Specific_Staff(vector<Doctor> All_Of_Doctors, string id);
	void Show_Specific_Staff(vector<Nurse> All_Of_Nurses, string id);

	Doctor* Find_Doctor_From_His_Id(vector<Doctor>& All_Of_Doctors, string id);
	void Delete_Befores_Doctor_Call_Shift_On_Timetable(Doctor doctor);

	Nurse* Find_Nurse_From_His_Id(vector<Nurse>& All_Of_Nurses, string id);
	void Delete_Befores_Nurse_Call_Shift_On_Timetable(Nurse nurse);

	bool  Find_Doctor_From_His_Field(vector<Doctor> All_Of_Doctors, string day);
	vector<int> Find_Doctor_From_His_Field_vector(vector<Doctor> All_Of_Doctors, string field);

	void Add_TO_Bill(int choose , vector<int>found , vector<Doctor>All_Of_Doctors, Patient &patient , string cost ,vector<Patient>&All_Of_Patients , string username , string password);

	bool Validate_Patient_To_Enter(string username, string password, vector<Patient>All_Of_Patients);

	Patient* Entered_Patient(string username, string password, vector<Patient>All_Of_Patients);

	bool Validate_Doctor_To_Enter(string username, string password, vector<Doctor> All_Of_Doctors);
	Doctor* Entered_Doctor(string username, string password, vector<Doctor>& All_Of_Doctors);

	bool Validate_Nurse_To_Enter(string username, string password, vector<Nurse> All_Of_Nurses);
	Nurse* Entered_Nurse(string username, string password, vector<Nurse>& All_Of_Nurses);

	bool Existence_Of_Phone_Number(string Phone_Number, vector<Nurse> All_Of_Nurses, vector<Doctor> All_Of_Doctors, vector<Patient>All_Of_Patients);

	bool Existence_Of_User_Name(string, vector<Nurse>, vector<Doctor>, vector<Patient>);
	bool Existence_Of_Password(string, vector<Nurse>, vector<Doctor>, vector<Patient>);



	bool Switch_Setter_validator (string input , int first_of_range , int end_of_range);


	template<typename T>
	void Read_From_File_And_Create_Objects(vector<T>& All_Of_Humans, fstream& inFile);

	void Read_From_File_And_Create_Timetable(vector<vector<string>> &Timetable, fstream& inFile);

	void Read_From_File_And_Create_Bill(vector<Patient>& All_Of_Patients, fstream& inFile);


    void Update_Doctor_File (vector<Doctor>& All_Of_Doctors , ofstream& inFile);
    void Update_Nurse_File (vector<Nurse>& All_Of_Nurses , ofstream& inFile);
    void Update_Patient_File (vector<Patient>&All_Of_Patients  , ofstream& inFile);
    void Update_Bill_File (vector<Patient>&All_Of_Patients , ofstream& inFile);
    void Update_Doctors_Time_Table_File (vector<vector<string>> Doctors_Timetable , ofstream& inFile);
    void Update_Nurses_Time_Table_File (vector<vector<string>> &Nurses_Timetable , ofstream& inFile);

};



#endif //FINAL_PROJECT_HOSPITAL_H
