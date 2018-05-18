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

int map_insert(map < string, double> *mapStudent, string index, double x, int&y)           //���ѧ������
{
	if (y < MAX_P_SIZE)                            //��û���������
	{
		mapStudent->insert(map < string, double>::value_type(index, x));//�������������
		map<string, double>::iterator iter = (*mapStudent).find(index);
		if (iter != (*mapStudent).end() )
		{
			cout << "Successfully insert��" << endl;
			y++;
			return OK;
		}
	}
	else
		cout << "Failed, calss is full!" << endl;
	return FALSE;
}


int choose_class(string name,string stu, vector<selective_course*> & course, int &i)//ѧ��ѡ��
{
	vector<selective_course*>::iterator it;                                                   
	int flag = 0;            //��ע�Ƿ��ҵ��ÿγ�
	char c;
	for (it = course.begin(); it != course.end(); it++)                                 //��������ѡ�޿�                                  
	{
		if ((*it)->co_number.compare(name) == 0 || (*it)->co_name.compare(name) == 0)//�ҵ�ϣ��ѡ��Ŀγ�
		{
			flag = 1;
			cout << " You choose class: " << (*it)->co_name << ", right ( Y/N)?";                               //ȷ���Ƿ�ѡ��ÿγ�
			cin >> c;
			if (c == 'Y')
			{
				if ((*it)->add_person(stu) == OK) 
				{
					for (int y = 0; y < MAX_SIZE; y++)
						if (all_class[y].compare((*it)->co_name) == 0)                                         //�޸�ѧ�����пγ�
							i = y;
					return OK;
				}                                          //���ѧ��
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
	if (flag == 0)                    //δ�ҵ��ÿγ�
	{
		cout << "There is no such class!" << endl;
	}
	return FALSE;
}

void show_class(const vector<selective_course*>  &course)
{
	if (!course.empty())
	{
		for (vector<selective_course*>::const_iterator it = course.begin(); it != course.end(); it++)       //��ʾѡ�޿γ�
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
		for (vector<compul_course*>::const_iterator it = course.begin(); it != course.end(); it++)          //��ʾ���޿γ�
		{
			cout << (*it)->co_number << "\t  " << (*it)->co_name <<"\t "<< (*it)->co_credit << endl; //*it����string����
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
}//��ʾȫ���γ�


	int menu1() {                         //��ʼ������
		int choice;
		do 
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}                                                               //��������int�����ݣ������cin��
			system("cls");
			cout << "\t****************************\n";
			cout << "\t*   ѧ���γ̹���ϵͳ       *\n";
			cout << "\t*==========================*\n";
			cout << "\t*    1����½               *\n";
			cout << "\t*    2��¼����ʦ��Ϣ       *\n";
			cout << "\t*    3��ɾ����ʦ��Ϣ       *\n";
			cout << "\t*    4��¼��ѧ����Ϣ       *\n";
			cout << "\t*    5��ɾ��ѧ����Ϣ       *\n";
			cout << "\t*    0���˳�����ϵͳ       *\n";
			cout << "\t****************************\n";
			cout << "\n\t��ѡ��:";
			cin >> choice;
		} while (choice < 0 || choice > 5 ||cin.good()==0);
		return choice;
	}

	int menu_ma() {                                    //��½��������ѡ����ݻ��߷�����һ��
		int choice;
		do 
		{
			system("cls");
			cout << "\t****************************\n";
			cout << "\t*   ѧ���γ̹���ϵͳ       *\n";
			cout << "\t*==========================*\n";
			cout << "\t*    1��ѧ��               *\n";
			cout << "\t*    2����ʦ               *\n";
			cout << "\t*    0��������һ��         *\n";
			cout << "\t****************************\n";
			cout << "\n\t��ѡ�����/����:";
			cin >> choice;
			if (cin.good() == 0)
				throw "wrong input! Enter to continue" ;
		} while (choice < 0 || choice > 2);                       //�ж�����������������������ѭ��
		return choice;
	}

void menu_name1(string &string1, string &string2)             //��½����
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
			cout << "\t*   ѧ���γ̹���ϵͳ       *\n";
			cout << "\t*==========================*\n";
			cout << "\t*   ������������";
			cin >> name;
			cout << "\t*   ������ѧ��/����:";
			cin >>  number;
		} while (name.empty() || number.empty() ||cin.good()==0);
		string1.assign(name);
		string2 .assign( number);
	}

	int menu_stu()
	{                                     //��½ѧ������
		int choice;
		do {
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			system("cls");
			cout << "\t***********************************\n";
			cout << "\t* ѧ���γ̹���ϵͳѧ������        *\n";
			cout << "\t*=================================*\n";
			cout << "\t*    1���鿴���пγ�              *\n";
			cout << "\t*    2���鿴�ҵĿγ�              *\n";
			cout << "\t*    3��ѡ��                      *\n";
			cout << "\t*    4���˿�                      *\n";
			cout << "\t*    5���鿴�ɼ��ͼ���            *\n";
			cout << "\t*    6���鿴�ҵ���Ϣ              *\n";
			cout << "\t*    0��������һ��                *\n";
			cout << "\t************************************\n";
			cout << "\n\t��ѡ��:";
			cin >> choice;
		} while (choice < 0 || choice > 6 ||cin.good()==0);
		return choice;
	}

	int menu_te()
	{
		int choice;
		do {
			cin.clear();                        //��½��ʦ����
			while (cin.get() != '\n')
			{
				continue;
			}
			system("cls");
			cout << "\t***********************************\n";
			cout << "\t* ѧ���γ̹���ϵͳ��ʦ����        *\n";
			cout << "\t*=================================*\n";
			cout << "\t*    1���鿴���пγ�              *\n";
			cout << "\t*    2���鿴�ҵĿγ�              *\n";
			cout << "\t*    3��¼��ѧ���ɼ�              *\n";
			cout << "\t*    4���鿴ѧ����Ϣ              *\n";
			cout << "\t*    5���鿴�ҵ���Ϣ              *\n";
			cout << "\t*    6���޸�ѧ���ɼ�              *\n";
			cout << "\t*    0��������һ��                *\n";
			cout << "\t***********************************\n";
			cout << "\n\t��ѡ��:";
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
			{                                                                                             //�ҵ��γ�
				ptr = *it;
				return ptr;
			}
		}
	  vector<compul_course*>::const_iterator it2;
		for (it2 = CCourse.begin(); it2 != CCourse.end(); it2++)            //�ҵ��γ�
		{
		    if ((*it2)->co_name.compare(x) == 0)
			{
					ptr = *it2;
					return ptr;
		     }
		}
		
		return NULL;               //δ�ҵ��γ�
	}
	 stu_course* find_select(vector<selective_course*> &SCourse,  string x)
	 {
		 vector<selective_course*>::const_iterator it;
		 stu_course * ptr;
		 for (it = SCourse.begin(); it != SCourse.end(); it++)
		 {
			 if ((*it)->co_name.compare(x) == 0)
			 {                                                                                             //�ҵ��γ�
				 ptr = *it;
				 return ptr;
			 }
		 }
		 return NULL;
	 }


	void function3(vector<stu_teacher*> &ma_t)                                     //�����ʦ
	{
		string name, Class, college, number;
		char sex;
		cout << "����������ӵĽ�ʦ��Ϣ:" << endl;
		cout << "������";
		cin >> name;
		cout << "���ţ�";
		cin >> number;
		cout << "ѧԺ��";
		cin >> college;
		cout << "�γ̣�";
		cin >> Class;
		cout << "�Ա�";
		cin >> sex;
		while (cin.good() == 0)
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "���������Ա�";
			cin >> sex;
		}
		stu_teacher* te = new stu_teacher(number, college, Class, name, sex);
		ma_t.push_back(te);
		cout << "��ӳɹ���\n";
	}
	void function4(vector<stu_student*> &ma_s)        //ɾ����ʦ
	{
		string name;
		char c;
		cout << "��������ɾ����ѧ������:" << endl;
		cout << "������";
		cin >> name;
		vector<stu_student*>::const_iterator it;
		int i = 0,flag = 0;
		for (it = ma_s.begin(),i =0 ; it != ma_s.end(); it++,i++)
		{
			if ((name).compare((*it)->get_name()) == 0)
			{
				cout << "ȷ��ɾ����(Y/N)" << endl;
				cin >> c;
				while (cin.good() == 0)
				{
					cin.clear();
					while (cin.get() != '\n')
					{
						continue;
					}
					cout << "������������������ѡ��";
					cin >> c;
				}
				if (c == 'Y')
				{
					stu_student * ptr = *it;
					it = ma_s.erase(it);
					cout << "ɾ���ɹ���\n";
				}
				else
					cout << "ɾ��ʧ�ܣ�" << endl;
				flag = 1;
			}
		}
		if(flag == 0)
			cout << "����ʧ�ܣ�\n";
	}
	void function5(vector<stu_teacher*> &ma_s)
	{
		string name;
		char c;
		cout << "��������ɾ������ʦ����:" << endl;                            //ɾ����ʦ
		cout << "������";
		cin >> name;
		vector<stu_teacher*>::const_iterator it;
		int i = 0, flag = 0;
		for (it = ma_s.begin(), i = 0; it != ma_s.end(); it++, i++)
		{

			if (name.compare((*it)->get_name()) == 0)
			{
				cout << "ȷ��ɾ����(Y/N)" << endl;
				cin >> c;
				while (cin.good() == 0)
				{
					cin.clear();
					while (cin.get() != '\n')
					{
						continue;
					}
					cout << "������������������ѡ��";
					cin >> c;
				}
				if (c == 'Y')
				{
					stu_teacher * ptr = *it;
					it = ma_s.erase(it);
					cout << "ɾ���ɹ���\n";
				}
				else
					cout << "ɾ��ʧ�ܣ�" << endl;
				flag = 1;
			}
		}
		if (flag == 0)
			cout << "����ʧ�ܣ�\n";
	}