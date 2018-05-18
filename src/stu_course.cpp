#include "stu_course.h"
#include <stu_data.h>
#include<stu_student.h>

/*!***************************************************
* @file: stu_course.cpp
* @brief: for testing
* @author:  PPsu
* @date: 2018, 4, 27
* @note:the specific function of the course class.
*****************************************************/

/*2��ʵ�����ֿγ̣����޿Ρ�ѡ�޿Ρ�
a)���޿κ�ѡ�޿εĹ������԰������γ̱�š��γ����ơ��γ�ѧ�ֵȣ�
b)���޿κ�ѡ�޿εĲ�ͬ���԰�����������㷽ʽ�����߲�ͬ�������޿ε�Ȩ�ظ��ߡ�*/

extern int  map_insert(map < string, double > *mapStudent, string index, double x, int&y);
extern string all_class[] = { "Math","English","Political", "Literature","Physics","Computer" };//all classes
double stu_course::get_grade( string name) const
{
	map<string, double>::const_iterator  iter = personnel.find(name);
	if (iter != personnel.end())
		return iter->second;
	else
		return FALSE;
}

stu_course :: ~stu_course()
{
	cout << "destruct course" << endl;
}//destructor func



void stu_course::record_grade(string name, double grade )//¼��ɼ�
{
	map<string, double>::iterator it;
	it = personnel.find( name );               //�ҵ�ѧ��
	cout << "The result of the query:";
	if (it == personnel.end())
	{
		cout << name << " not found the person." << endl;
	}           //û�ҵ�
	else
	{
		if (personnel[name] == -1)
		{
			char c;
			cout << "If you want to record the grade as:" << grade << "?( Y/N )";
			cin >> c;
			if (c == 'N')
				cout << "Failed to change his grade!" << endl;
			else if (c == 'Y')
			{
				personnel[name] = grade;
				cout << "Successfully record!" << endl;
			}
			else
				throw"wrong choice!";
		}
		else
			cout << "His grade has already been recorded, it is:" << personnel[name] << endl;
	}
}

int stu_course::add_person(string name)                  //���ѧ��
{
	map<string, double>::iterator it;
	it = personnel.find(name);
	cout << "The result of the query:" << endl;
	if (it != personnel.end())
	{
		cout << name << " has been added." << endl;
		return FALSE;
	}
	else
		return (map_insert(&personnel, name, -1, num));
}

compul_course ::~compul_course()
{
	cout << "destruct" << co_name << endl;
}//destructor func

double compul_course::calcu_GDP(string person ) const      //���GDP
{
	map<string, double>::const_iterator it;
	it = personnel.find(person);
	
	if (it == personnel.end())
	{
		cout << person << " not found this person." << endl;
		return  FAL;
	}
	else if (it->second == -1)
	{
		cout << "There is no grade yet." << endl;
		return FAL;
	}	
	else
		return ((it->second) / 100 * co_credit);               
}

selective_course ::~selective_course()
{
	cout << "destruct" << co_name << endl;
}//destructor func

double selective_course::calcu_GDP(string person) const                 //ѡ�޿�GDP
{
	map<string, double>::const_iterator it= personnel.find(person);
	cout << "The the GDP of " << co_name << ": ";
	if (it == personnel.end())
	{
		cout << person << " not found this person." << endl;
		return  FAL;
	}
	else if (it->second == -1)
	{
		cout << "There is no grade yet." << endl;
		return FAL;
	}
	else
		return ((it->second) / 100 * co_credit);
}
