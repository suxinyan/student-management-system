#include "stu_student.h"
#include "stu_teacher.h"
#include"stu_data.h"
#include"stu_course.h"



/*!***************************************************
* @file: stu_teacher.cpp
* @brief: for testing
* @author:  PPsu
* @date: 2018, 5,7
* @note:the specific function of the teacher class.
*****************************************************/
/*
b)教师可查看自己的所有课程，包括必修课和选修课（但呈现方式要区分开）；
c)教师可查看自己课程的所有选课学生名单，以及查看指定选课学生的学生信息。
实现课程成绩的录入、修改、提交操作，仅老师可用。
a)任课教师录入、修改、提交指定选课学生的课程成绩；
b)课程成绩在提交后不可修改；
c)课程成绩在提交后，才可被学生看到。*/

void stu_teacher::show_my_students(const stu_course *c)           //展示当前我的学生的信息
{
	if (c != NULL)
	{
		cout << "Students:                         grade:                     " << endl;
		map<string, double>::const_iterator iter;                                      //定义指向课程的迭代器               
		double g;
		for (iter = c->personnel.begin(); iter != c->personnel.end(); iter++)         // 课程指针为老师所教课程的指针
		{
			cout << iter->first << "\t\t "<< iter->second << endl;
		}
		cout << endl;
	}
	else
		cout << "wrong class name!" << endl;
}
string stu_teacher::get_name()                           //返回老师姓名
{
	return te_name;
}

string stu_teacher::get_num()                      //返回老师工号
{
	return te_number;
}             

string stu_teacher::get_course()                      //返回老师所教科目
{
	return te_subject;
}

void stu_teacher::show_my_inf()                     //展示老师当前信息
{
	   cout << "The information of the teacher:" << endl;
		cout << "*name:         " << te_name << "\t" << endl;;
		cout << "*sex:             " << sex << "\t" << endl;
		cout << "*number:      " << te_number << "\t" << endl;
		cout << "*college:        " << te_college << "\t" << endl;
		cout << "*course:         " <<te_subject << "\t" << endl;
}                     

void stu_teacher::show_stu_inf(string name, vector<stu_student*> &stu, const stu_course *c)    //老师查看学生信息
{
	map<string, double>::const_iterator iter;
	int flag = 0, flag2 = 0;
	if (c != NULL)                                            //找到课程
	{
		for (iter = c->personnel.begin(); iter != c->personnel.end(); iter++)
		{
			if (iter->first == name)                    //课里找到学生才可以显示
			{
				flag = 1;
				vector<stu_student*>::iterator it1 = stu.begin();     
				for (; it1 != stu.end(); it1++)
				{
					if (name.compare((*it1)->get_name()) == 0)  //找到学生
					{
						flag2 = 1;
						(*it1)->show_my_inf(); //展示信息
					}
				}
				if (flag2 = 0)
					cout << "not find the person." << endl;
			}
		}
		if (flag == 0)    //没找到不可以显示
			cout << "The person is not in the class!" << endl;
		cout << endl;
	}
	else
		cout << "wrong student course!" << endl;            //课程不对
}

void stu_teacher::record_grade(const string name, const double grade,  vector<selective_course*> &SCourse,  vector<compul_course*> &CCourse)
{                                                                                                           //录入成绩
	int flag = 0;
	vector<compul_course*>::iterator it1 = CCourse.begin();
	vector<selective_course*>::iterator it2 = SCourse.begin();
	for (; it1 != CCourse.end(); it1++)            //找到科目
	{
		if ((*it1)->co_name == te_subject)
		{
			try
			{
				(*it1)->record_grade(name, grade); //录入
			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			flag = 1;
		}
	}
	for (; it2 != SCourse.end(); it2++) //找到科目
	{
		if ((*it2)->co_name == te_subject)
		{
			try
			{
				(*it2)->record_grade(name, grade);         //录入
			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "Not find your subject!" << endl;
}

void stu_teacher::change_grade(const string name, const double grade, vector<stu_student*> &stu, vector<selective_course*> &SCourse, vector<compul_course*> &CCourse) //修改学生成绩
{
	int flag = 0;
	int flag1 = 0;
	vector<compul_course*>::iterator it1 = CCourse.begin();
	vector<selective_course*>::iterator it2 = SCourse.begin();
	for (; it1 != CCourse.end(); it1++)            //找到科目
	{
		if ((*it1)->co_name == te_subject)
		{
			if ((*it1)->personnel[name] == -1)
			{
				flag1 = 1;
				vector<stu_student*>::iterator it = stu.begin();
				for (; it != stu.end(); it++)
				{
					if ((*it)->get_name().compare(name) == 0)
					{
						flag = 1;
						(*it)->change_state(te_subject, grade);
						cout << "修改成功！" << endl;
					}
				}
				if (flag1 == 0)
					cout << "未找到该学生" << endl;
			}
			else
				cout << "has been handed!" << endl;
		}
	}
	for (; it2 != SCourse.end(); it2++) //找到科目
	{
		if ((*it2)->co_name == te_subject)
		{
			if ((*it2)->personnel[name] == -1)
			{
				flag1 = 1;
				vector<stu_student*>::iterator it = stu.begin();
				for (; it != stu.end(); it++)
				{
					if ((*it)->get_name().compare(name) == 0)
					{
						flag = 1;
						(*it)->change_state(te_subject, grade);
						cout << "修改成功！" << endl;
					}
				}
				if (flag1 == 0)
					cout << "未找到该学生" << endl;
			}
			else
				cout << "has been handed!" << endl;
		}
	}
	if (flag == 0)
		cout << "Not find your subject!" << endl;
	
}