#ifndef _A_H_
#define _A_H_
#include<iostream>
#include<fstream>
#include<exception>
#include<string>
#include<vector>
#include<map>
#include<windows.h>
#include<stdlib.h>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::map;
/*!***************************************************
* @file: stu_data.h
* @brief: for testing
* @author:  PPsu
* @date: 2018, 4, 15
* @note:The student score management sysytem can be used to check current information 
about the grade of a student by a student  and to view the course information by a teacher,
who can also change the score of his own course. 
****************************************************/
#define MAX_SIZE 6                //max size of current number of classes
#define MAX_P_SIZE 10              //max size of current number of teachers students
#define MAX_S_SIZE 3              //max size of current number of selective courses
#define MAX_C_SIZE 3              //max size of current number of compulsive courses
#define OK 1                               //define the right expression 
#define FAL -2                        //define the expression of false
string all_class[];//all classes matrix
int menu1();         //menu 1
int menu_ma();         //menu of management
int menu_stu();              //menu of student
int menu_te();                  //menu of teacher
void menu_name1(string &string1, string &string2);          //menu of login

#include<iostream>
using namespace std;
class ExceptionClass
{
	const char* name;
public:
	ExceptionClass(const char* name = "wrong input")
	{
		this->name = name;
	}
	~ExceptionClass() {}
	void mythrow()
	{
		cout << name << endl;

	}
};
#endif