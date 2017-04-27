// TEST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <string.h>
using namespace std;

class Employee{
private:
	int Emp_Id;
	char* Name;
	char* Designation;
public:
	Employee(int id = 0, const char *name = NULL, char *role = NULL);
	/* In shallow copy we get Double free run time error also as both objects point to same location. 
	Freeing same memory two times which is not valid */
	/*~Employee(){
		delete [] Name;
		delete [] Designation;
	}
	/* Deep Copy - Copy Constructor Uncomment below code to avoid shallow copy */
	/*Employee(  const Employee&  e) {
		this->Emp_Id = e.Emp_Id;
		this->Name = new char[strlen(e.Name)+1];
		strcpy(this->Name,e.Name);
		this->Designation = new char[strlen(e.Designation)+1];
		strcpy(this->Designation,e.Designation);
	}*/
	void Role_Change(const char *New_Designation) {
		if(Designation != NULL)
			delete []Designation;
		int size = strlen(New_Designation);
		Designation = new char[size+1];
		strcpy(this->Designation,New_Designation);
	}
	void Print_Designation() {
		std::cout<<"Current Designation is "<<this->Designation<<std::endl;
	}

};

/* Shallow copy */
Employee::Employee(int id, const char * name, char * role){
	Name = new char[strlen(name)+1];
	strcpy(Name, name);
	Designation = new char[strlen(role)+1];
	strcpy(Designation, role);
	Emp_Id = id;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *a= "SE";
	Employee E1(519377,"XYZ",a);
	Employee E2 = E1;
	E1.Print_Designation();
	E2.Print_Designation();
	std::cout<<"Changing E1 Designation "<< std::endl;
	const char * var = "SSE";
	E1.Role_Change(var);
	std::cout<<"Changing E1 Designation will change E2 also because of deafult constructor which does shallow copy "<< std::endl;
	E1.Print_Designation();
	E2.Print_Designation();
	return 0;
}

