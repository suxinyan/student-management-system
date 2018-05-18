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
b)��ʦ�ɲ鿴�Լ������пγ̣��������޿κ�ѡ�޿Σ������ַ�ʽҪ���ֿ�����
c)��ʦ�ɲ鿴�Լ��γ̵�����ѡ��ѧ���������Լ��鿴ָ��ѡ��ѧ����ѧ����Ϣ��
ʵ�ֿγ̳ɼ���¼�롢�޸ġ��ύ����������ʦ���á�
a)�ον�ʦ¼�롢�޸ġ��ύָ��ѡ��ѧ���Ŀγ̳ɼ���
b)�γ̳ɼ����ύ�󲻿��޸ģ�
c)�γ̳ɼ����ύ�󣬲ſɱ�ѧ��������*/

void stu_teacher::show_my_students(const stu_course *c)           //չʾ��ǰ�ҵ�ѧ������Ϣ
{
	if (c != NULL)
	{
		cout << "Students:                         grade:                     " << endl;
		map<string, double>::const_iterator iter;                                      //����ָ��γ̵ĵ�����               
		double g;
		for (iter = c->personnel.begin(); iter != c->personnel.end(); iter++)         // �γ�ָ��Ϊ��ʦ���̿γ̵�ָ��
		{
			cout << iter->first << "\t\t "<< iter->second << endl;
		}
		cout << endl;
	}
	else
		cout << "wrong class name!" << endl;
}
string stu_teacher::get_name()                           //������ʦ����
{
	return te_name;
}

string stu_teacher::get_num()                      //������ʦ����
{
	return te_number;
}             

string stu_teacher::get_course()                      //������ʦ���̿�Ŀ
{
	return te_subject;
}

void stu_teacher::show_my_inf()                     //չʾ��ʦ��ǰ��Ϣ
{
	   cout << "The information of the teacher:" << endl;
		cout << "*name:         " << te_name << "\t" << endl;;
		cout << "*sex:             " << sex << "\t" << endl;
		cout << "*number:      " << te_number << "\t" << endl;
		cout << "*college:        " << te_college << "\t" << endl;
		cout << "*course:         " <<te_subject << "\t" << endl;
}                     

void stu_teacher::show_stu_inf(string name, vector<stu_student*> &stu, const stu_course *c)    //��ʦ�鿴ѧ����Ϣ
{
	map<string, double>::const_iterator iter;
	int flag = 0, flag2 = 0;
	if (c != NULL)                                            //�ҵ��γ�
	{
		for (iter = c->personnel.begin(); iter != c->personnel.end(); iter++)
		{
			if (iter->first == name)                    //�����ҵ�ѧ���ſ�����ʾ
			{
				flag = 1;
				vector<stu_student*>::iterator it1 = stu.begin();     
				for (; it1 != stu.end(); it1++)
				{
					if (name.compare((*it1)->get_name()) == 0)  //�ҵ�ѧ��
					{
						flag2 = 1;
						(*it1)->show_my_inf(); //չʾ��Ϣ
					}
				}
				if (flag2 = 0)
					cout << "not find the person." << endl;
			}
		}
		if (flag == 0)    //û�ҵ���������ʾ
			cout << "The person is not in the class!" << endl;
		cout << endl;
	}
	else
		cout << "wrong student course!" << endl;            //�γ̲���
}

void stu_teacher::record_grade(const string name, const double grade,  vector<selective_course*> &SCourse,  vector<compul_course*> &CCourse)
{                                                                                                           //¼��ɼ�
	int flag = 0;
	vector<compul_course*>::iterator it1 = CCourse.begin();
	vector<selective_course*>::iterator it2 = SCourse.begin();
	for (; it1 != CCourse.end(); it1++)            //�ҵ���Ŀ
	{
		if ((*it1)->co_name == te_subject)
		{
			try
			{
				(*it1)->record_grade(name, grade); //¼��
			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			flag = 1;
		}
	}
	for (; it2 != SCourse.end(); it2++) //�ҵ���Ŀ
	{
		if ((*it2)->co_name == te_subject)
		{
			try
			{
				(*it2)->record_grade(name, grade);         //¼��
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

void stu_teacher::change_grade(const string name, const double grade, vector<stu_student*> &stu, vector<selective_course*> &SCourse, vector<compul_course*> &CCourse) //�޸�ѧ���ɼ�
{
	int flag = 0;
	int flag1 = 0;
	vector<compul_course*>::iterator it1 = CCourse.begin();
	vector<selective_course*>::iterator it2 = SCourse.begin();
	for (; it1 != CCourse.end(); it1++)            //�ҵ���Ŀ
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
						cout << "�޸ĳɹ���" << endl;
					}
				}
				if (flag1 == 0)
					cout << "δ�ҵ���ѧ��" << endl;
			}
			else
				cout << "has been handed!" << endl;
		}
	}
	for (; it2 != SCourse.end(); it2++) //�ҵ���Ŀ
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
						cout << "�޸ĳɹ���" << endl;
					}
				}
				if (flag1 == 0)
					cout << "δ�ҵ���ѧ��" << endl;
			}
			else
				cout << "has been handed!" << endl;
		}
	}
	if (flag == 0)
		cout << "Not find your subject!" << endl;
	
}