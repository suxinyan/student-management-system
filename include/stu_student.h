#ifndef _B_H_
#define _B_H_
#include <stu_data.h>
#include <stu_course.h>

/*!***************************************************
* @file: stu_student.h
* @brief: for testing
* @author:  PPsu
* @date: 2018, 4, 15
* @note:store the basic data stucture of the student class.
****************************************************/
class stu_student
{
private:
	string stu_number;         // student number
	string stu_college;
	string stu_class;
	string stu_name;
	char stu_sex;
	int my_course[MAX_SIZE];              //storage of the student's classes, ''1'' stands for chosen
										  //selected whlie ''0''stands for not chosen

public:
	double my_state[MAX_SIZE];              //storage of the student's grades, which are  not recorded
	stu_student() {};
	stu_student(const string num, const string college, const string Class, const string name, int s) :
		stu_number(num), stu_college(college), stu_class(Class), stu_name(name), stu_sex(s)          //initial
	{
		for (int i = 0; i < MAX_C_SIZE; i++)
			my_course[i] = 1;                                        //compulsory class is chosen at first
		for (int i = MAX_C_SIZE; i < MAX_SIZE; i++)
			my_course[i] = 0;                            //select class is not chosen
		for (int i = 0; i < MAX_SIZE; i++)
			my_state[i] = -1;                         //grade not handed
		
	}
	void change_state(string name, double grade);
	~stu_student() { cout << "student is destructed. " << endl; }; //distruct function              
	void change_stu_college(string new_co);             //change college
	void change_stu_class(string new_cl);              //change class
	string get_name();            //get student name
	string get_num();                  //get student number
	void show_my_course();           //show his course
	void select_course( vector<selective_course*> &SCourse); //select course
	void show_GDP_grade(const vector<selective_course*> &SCourse, const vector<compul_course*> &CCourse);//show grade and GDP
	void show_my_inf();     //show his information
	void Delete_my_course( vector<selective_course*> &SCourse);    //delete class
};
void function4(vector<stu_student*> &ma_s);             //delete
#endif
