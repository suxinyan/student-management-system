#include "stu_course.h"
#include <stu_data.h>
#include<stu_student.h>
#include "stu_teacher.h"

/*!***************************************************
* @file: achieve.cpp
* @brief: for testing
* @author:  PPsu
* @date: 2018, 5, 15
* @note:achieve the partial function of the system.
****************************************************/

int map_insert(map < string, double> *mapStudent, string index, double x, int&y)           //添加学生分数
{
	if (y < MAX_P_SIZE)                            //课没满可以添加
	{
		mapStudent->insert(map < string, double>::value_type(index, x));//添加姓名，分数
		map<string, double>::iterator iter = (*mapStudent).find(index);
		if (iter != (*mapStudent).end() )
		{
			cout << "Successfully insert！" << endl;
			y++;
			return OK;
		}
	}
	else
		cout << "Failed, calss is full!" << endl;
	return FALSE;
}


int choose_class(string name,string stu, vector<selective_course*> & course, int &i)//学生选课
{
	vector<selective_course*>::iterator it;                                                   
	int flag = 0;            //标注是否找到该课程
	char c;
	for (it = course.begin(); it != course.end(); it++)                                 //查找现有选修课                                  
	{
		if ((*it)->co_number.compare(name) == 0 || (*it)->co_name.compare(name) == 0)//找到希望选择的课程
		{
			flag = 1;
			cout << " You choose class: " << (*it)->co_name << ", right ( Y/N)?";                               //确认是否选择该课程
			cin >> c;
			if (c == 'Y')
			{
				if ((*it)->add_person(stu) == OK) 
				{
					for (int y = 0; y < MAX_SIZE; y++)
						if (all_class[y].compare((*it)->co_name) == 0)                                         //修改学生已有课程
							i = y;
					return OK;
				}                                          //添加学生
				else
					return FALSE;
			}
			else if(c == 'N')
			{
				cout << "failed to choose the class!" << endl;
				return FALSE;
			}
			else
				throw ExceptionClass();
			}
	
		}
	if (flag == 0)                    //未找到该课程
	{
		cout << "There is no such class!" << endl;
	}
	return FALSE;
}

void show_class(const vector<selective_course*>  &course)
{
	if (!course.empty())
	{
		for (vector<selective_course*>::const_iterator it = course.begin(); it != course.end(); it++)       //显示选修课程
		{
			cout << (*it)->co_number << "\t  " << (*it)->co_name << " \t " << (*it)->co_credit << " \t" << MAX_P_SIZE - (*it)->num << endl;
		}
		cout << endl;
	}
	else
		cout << "empty!" << endl;
}

void show_class(const vector<compul_course*> & course)
{
	if (!course.empty())
	{
		for (vector<compul_course*>::const_iterator it = course.begin(); it != course.end(); it++)          //显示必修课程
		{
			cout << (*it)->co_number << "\t  " << (*it)->co_name <<"\t "<< (*it)->co_credit << endl; //*it才是string数据
		}
	}
	else
		cout << "empty!" << endl;
}

void show_all_course(const vector<selective_course*> &SCourse, const vector<compul_course*> &CCourse)
{
	cout << "All selective classes:" << endl;
	cout << "number\t\tname \t\tcredit\trest:" << endl;
	show_class(SCourse);
	cout << "All compulsory classes:" << endl;
	cout << "number\t\tname\t \tcredit\t:" << endl;
	show_class(CCourse);
}//显示全部课程


	int menu1() {                         //初始界面栏
		int choice;
		do 
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}                                                               //如果输入非int型数据，会清空cin流
			system("cls");
			cout << "\t****************************\n";
			cout << "\t*   学生课程管理系统       *\n";
			cout << "\t*==========================*\n";
			cout << "\t*    1、登陆               *\n";
			cout << "\t*    2、录入老师信息       *\n";
			cout << "\t*    3、删除老师信息       *\n";
			cout << "\t*    4、录入学生信息       *\n";
			cout << "\t*    5、删除学生信息       *\n";
			cout << "\t*    0、退出管理系统       *\n";
			cout << "\t****************************\n";
			cout << "\n\t请选择:";
			cin >> choice;
		} while (choice < 0 || choice > 5 ||cin.good()==0);
		return choice;
	}

	int menu_ma() {                                    //登陆界面栏，选择身份或者返回上一栏
		int choice;
		do 
		{
			system("cls");
			cout << "\t****************************\n";
			cout << "\t*   学生课程管理系统       *\n";
			cout << "\t*==========================*\n";
			cout << "\t*    1、学生               *\n";
			cout << "\t*    2、教师               *\n";
			cout << "\t*    0、返回上一栏         *\n";
			cout << "\t****************************\n";
			cout << "\n\t请选择身份/返回:";
			cin >> choice;
			if (cin.good() == 0)
				throw "wrong input! Enter to continue" ;
		} while (choice < 0 || choice > 2);                       //判断条件，输入有误则不能跳出循环
		return choice;
	}

void menu_name1(string &string1, string &string2)             //登陆界面
	{
		string name, number;
		do 
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			system("cls");
			cout << "\t****************************\n";
			cout << "\t*   学生课程管理系统       *\n";
			cout << "\t*==========================*\n";
			cout << "\t*   请输入姓名：";
			cin >> name;
			cout << "\t*   请输入学号/工号:";
			cin >>  number;
		} while (name.empty() || number.empty() ||cin.good()==0);
		string1.assign(name);
		string2 .assign( number);
	}

	int menu_stu()
	{                                     //登陆学生界面
		int choice;
		do {
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			system("cls");
			cout << "\t***********************************\n";
			cout << "\t* 学生课程管理系统学生界面        *\n";
			cout << "\t*=================================*\n";
			cout << "\t*    1、查看所有课程              *\n";
			cout << "\t*    2、查看我的课程              *\n";
			cout << "\t*    3、选课                      *\n";
			cout << "\t*    4、退课                      *\n";
			cout << "\t*    5、查看成绩和绩点            *\n";
			cout << "\t*    6、查看我的信息              *\n";
			cout << "\t*    0、返回上一栏                *\n";
			cout << "\t************************************\n";
			cout << "\n\t请选择:";
			cin >> choice;
		} while (choice < 0 || choice > 6 ||cin.good()==0);
		return choice;
	}

	int menu_te()
	{
		int choice;
		do {
			cin.clear();                        //登陆老师界面
			while (cin.get() != '\n')
			{
				continue;
			}
			system("cls");
			cout << "\t***********************************\n";
			cout << "\t* 学生课程管理系统教师界面        *\n";
			cout << "\t*=================================*\n";
			cout << "\t*    1、查看所有课程              *\n";
			cout << "\t*    2、查看我的课程              *\n";
			cout << "\t*    3、录入学生成绩              *\n";
			cout << "\t*    4、查看学生信息              *\n";
			cout << "\t*    5、查看我的信息              *\n";
			cout << "\t*    6、修改学生成绩              *\n";
			cout << "\t*    0、返回上一栏                *\n";
			cout << "\t***********************************\n";
			cout << "\n\t请选择:";
			cin >> choice;
		} while (choice < 0 || choice > 6||cin.good()==0);
		return choice;
	}

	 stu_course* find(vector<selective_course*> &SCourse,  vector<compul_course*> &CCourse, string x)
	{
		vector<selective_course*>::const_iterator it;
		stu_course * ptr;
		for (it = SCourse.begin(); it != SCourse.end(); it++)
		{
			if ((*it)->co_name.compare(x) == 0)
			{                                                                                             //找到课程
				ptr = *it;
				return ptr;
			}
		}
	  vector<compul_course*>::const_iterator it2;
		for (it2 = CCourse.begin(); it2 != CCourse.end(); it2++)            //找到课程
		{
		    if ((*it2)->co_name.compare(x) == 0)
			{
					ptr = *it2;
					return ptr;
		     }
		}
		
		return NULL;               //未找到课程
	}
	 stu_course* find_select(vector<selective_course*> &SCourse,  string x)
	 {
		 vector<selective_course*>::const_iterator it;
		 stu_course * ptr;
		 for (it = SCourse.begin(); it != SCourse.end(); it++)
		 {
			 if ((*it)->co_name.compare(x) == 0)
			 {                                                                                             //找到课程
				 ptr = *it;
				 return ptr;
			 }
		 }
		 return NULL;
	 }


	void function3(vector<stu_teacher*> &ma_t)                                     //添加老师
	{
		string name, Class, college, number;
		char sex;
		cout << "输入您想添加的教师信息:" << endl;
		cout << "姓名：";
		cin >> name;
		cout << "工号：";
		cin >> number;
		cout << "学院：";
		cin >> college;
		cout << "课程：";
		cin >> Class;
		cout << "性别：";
		cin >> sex;
		while (cin.good() == 0)
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "重新输入性别：";
			cin >> sex;
		}
		stu_teacher* te = new stu_teacher(number, college, Class, name, sex);
		ma_t.push_back(te);
		cout << "添加成功！\n";
	}
	void function4(vector<stu_student*> &ma_s)        //删除老师
	{
		string name;
		char c;
		cout << "输入您想删除的学生姓名:" << endl;
		cout << "姓名：";
		cin >> name;
		vector<stu_student*>::const_iterator it;
		int i = 0,flag = 0;
		for (it = ma_s.begin(),i =0 ; it != ma_s.end(); it++,i++)
		{
			if ((name).compare((*it)->get_name()) == 0)
			{
				cout << "确认删除？(Y/N)" << endl;
				cin >> c;
				while (cin.good() == 0)
				{
					cin.clear();
					while (cin.get() != '\n')
					{
						continue;
					}
					cout << "输入有误，请重新输入选择：";
					cin >> c;
				}
				if (c == 'Y')
				{
					stu_student * ptr = *it;
					it = ma_s.erase(it);
					cout << "删除成功！\n";
				}
				else
					cout << "删除失败！" << endl;
				flag = 1;
			}
		}
		if(flag == 0)
			cout << "查找失败！\n";
	}
	void function5(vector<stu_teacher*> &ma_s)
	{
		string name;
		char c;
		cout << "输入您想删除的老师姓名:" << endl;                            //删除老师
		cout << "姓名：";
		cin >> name;
		vector<stu_teacher*>::const_iterator it;
		int i = 0, flag = 0;
		for (it = ma_s.begin(), i = 0; it != ma_s.end(); it++, i++)
		{

			if (name.compare((*it)->get_name()) == 0)
			{
				cout << "确认删除？(Y/N)" << endl;
				cin >> c;
				while (cin.good() == 0)
				{
					cin.clear();
					while (cin.get() != '\n')
					{
						continue;
					}
					cout << "输入有误，请重新输入选择：";
					cin >> c;
				}
				if (c == 'Y')
				{
					stu_teacher * ptr = *it;
					it = ma_s.erase(it);
					cout << "删除成功！\n";
				}
				else
					cout << "删除失败！" << endl;
				flag = 1;
			}
		}
		if (flag == 0)
			cout << "查找失败！\n";
	}