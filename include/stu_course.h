#ifndef _c_H_
#define _c_H_
#include <stu_data.h>

/*!***************************************************
* @file: stu_course.h
* @brief: for testing
* @author:  PPsu
* @date: 2018, 4, 20
* @note:store the basic data stucture of the course class
including basic courses and selective courses.
****************************************************/

class stu_course
{
public:
	string co_number;         // course number
	int co_credit;               //course credit
	string co_name;          //course name
	map<string, double> personnel;
	int num; 

	stu_course() {};
	stu_course(string num, string name, int cre, int init) : co_number(num), co_name(name), co_credit(cre) ,num(init)
	{}//constructor func

	stu_course(const stu_course & one)
	{
		co_credit = one.co_credit;
		co_name = one.co_name;
		co_number = one.co_number;
		num = one.num;
	} //copy constructor func
	double get_grade(string name) const;                 //return grade of the student
	virtual ~stu_course();//destructor func    
	virtual double calcu_GDP(string person) { return 0.0; }  
	void record_grade(string name, double grade);                //record number of a student
	int add_person(string name);            //add a person 
};

class compul_course : public stu_course
{
public:
	compul_course() {};
	compul_course(string num, string name, int cre, int k) : stu_course(num, name, cre, k){} //constructor func
	compul_course(const compul_course & one)               // copy construct function
	{
		co_credit = one.co_credit;
		co_name = one.co_name;
		co_number = one.co_number;
		num = one.num;
		//copy constructor func
	}

    ~compul_course();//destructor func
	virtual double calcu_GDP( string person) const;                    
};

class selective_course : public stu_course
{
public:
	selective_course() {}
	selective_course(string num, string name, int cre, int k) : stu_course(num, name, cre, k) {}; //constructor func
	selective_course(const  selective_course& one)
	{
		co_credit = one.co_credit;
		co_name = one.co_name;
		co_number = one.co_number;
		num = one.num;
	}    //copy constructor func
    ~selective_course();                                                                                                //destructor func
	virtual double calcu_GDP( string person ) const;                              //calculate GDP of a student
};

void show_class(const vector<selective_course*> & course);             //show selective class
void show_class(const vector<compul_course*> & course);                //show compulsive class
int map_insert(map < string, double > *mapStudent, string index, double, int&y);           //insert student
void show_all_course(const vector<selective_course*> &SCourse, const vector<compul_course*> &CCourse);//show all class
int choose_class(string name, string stu, vector<selective_course*> & course, int &i);         //choose class
stu_course* find( vector<selective_course*> &SCourse, vector<compul_course*> &CCourse, string x); //find class
stu_course* find_select(vector<selective_course*> &SCourse, string x);
#endif