#include "stu_course.h"                //ͷ�ļ�
#include <stu_data.h>
#include<stu_student.h>
#include "stu_teacher.h"
/*!***************************************************
* @file: main.cpp
* @brief: for testing
* @author:  PPsu
* @date: 2018, 5, 15
* @note:achieve the function of the system.
****************************************************/

void init(vector<stu_student*> &ma_s, vector<stu_teacher*>&ma_t, vector<selective_course*>&ma_sc,
	vector<compul_course*>&ma_c)                          //��ʼ������
{
	cout << "��ʼ����Ϣ��" << endl;
	ifstream fin("E:\\sususu\\mystudy\\book.txt");                      //���ļ���
	ifstream xin("E:\\sususu\\mystudy\\clas.txt");
	string name, Class, college, number;                            //ѧ�� ѧԺ �༶ ���� �Ա�
	int cre, k;                         //ѧ�֣� ��ʼ���Ŀγ������������޿���Ϊ-1000����ʾ�ܴ�ѡ�޿���Ϊ0�������ܳ������ֵMAX_P_SIZE;
	char sex;               //�Ա�wŮ��m��
	if (!fin.is_open())                               //���ļ�ʧ��
	{
		cout << "Error opening file"; 
		exit(1);
	}
	if (!xin.is_open())                   //���ļ�ʧ��
	{
		cout << "Error opening file"; 
		exit(1);
	}
	for (int i = 0; i< MAX_SIZE - 1; i++)
	{
		fin >> number >> college >> Class >> name >> sex;          //ѧ�� ѧԺ �༶ ���� �Ա�  ��ѧ����
		stu_student* stu = new stu_student(number, college, Class, name, sex);
		ma_s.push_back(stu);
	}
	for (int i = 0; i< MAX_SIZE - 1; i++)
	{
		fin >> number >> college >> Class >> name >> sex;                 //��ʦ�ĳ�ʼ��
		stu_teacher* te = new stu_teacher(number, college, Class, name, sex);
		ma_t.push_back(te);
	}
	for (int i = 0; i< MAX_C_SIZE; i++)
	{
		xin >> number >> name;                           //�γ̺� �γ��� 
		xin >> cre >> k;                     //ѧ�� ������
		compul_course* te = new compul_course(number, name, cre, k);
		vector<stu_student*>::iterator it1 = ma_s.begin();
		for (; it1 != ma_s.end(); it1++)                                      
		{
			te->add_person((*it1)->get_name());                   //������ѧ������ȫ�����޿�����
		}
		ma_c.push_back(te);
	}
	for (int i = 0; i< MAX_S_SIZE; i++)
	{
		xin >> number >> name;
		xin >> cre >> k;
		selective_course* te = new selective_course(number, name, cre, k);        //ѡ�޿�����
		ma_sc.push_back(te);
	}
	fin.close();            //�ر��ļ�
	xin.close();
	cout << "\n\nInit successfully!" << endl;
	cout << "��ENTER������..." << endl;
}

void function2(vector<stu_student*> &ma_s, vector<compul_course*>&ma_cs)               //���ѧ��
{
	string name, Class, college, number;
	char sex;
	cout << "����������ӵ�ѧ����Ϣ:" << endl;
	cout << "������";
	cin >> name;
	cout << "ѧ�ţ�";
	cin >> number;
	cout << "ѧԺ��";
	cin >> college;
	cout << "�༶��";
	cin >> Class;
	cout << "�Ա�";
	cin >> sex;
	while (cin.good() == 0)                    //�Ա���������Ĵ���
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			continue;
		}
		cout << "���������Ա�";
		cin >> sex;
	}
	stu_student* stu = new stu_student(number, college, Class, name, sex);
	ma_s.push_back(stu);
	vector<compul_course*>::iterator it1 = ma_cs.begin();
	for (; it1 != ma_cs.end(); it1++)
	{
		(*it1)->add_person(stu->get_name());                   //������ѧ������ȫ�����޿�����
	}
	cout << "��ӳɹ���\n";

}

void func_q()                                                //�ڸô���ͣ��
{
	char f;
	cout << "\n\nInput 'q' to last window.";
	cin >> f;
	while (f != 'q')
		cin >> f;
}

int main()
{
	int an, bn, cn, dn;                     //�˵���

	int flag = 0, flag2 = 0, flag3 = 0;              //�жϱ�ʶ
	string name, number;                         //�洢������ ѧ�ŵı���
	double grade;                                        //�洢�����ı���
	stu_course * ptr = NULL;                            //ָ��ѧ���γ̱�����ָ��
	stu_course * ptr1 = NULL;
	vector<stu_teacher*>ma_t;                           //�洢��ʦָ�������
	vector<selective_course*>ma_sc;                //�洢ѡ�޿�ָ�������
	vector<compul_course*>ma_c;                 //�洢���޿�ָ�������
	vector<stu_student *> ma_s;                      //�洢ѧ��ָ�������
	vector<stu_teacher*>::iterator it1 = ma_t.begin();               //������
	vector<selective_course*>::iterator it2 = ma_sc.begin();
	vector<compul_course*>::iterator it3 = ma_c.begin();
	vector<stu_student *> ::iterator it4 = ma_s.begin();

	init(ma_s, ma_t, ma_sc, ma_c);          //��ʼ��
	do {
		Sleep(1000);                             //����������ת�ٶ�
		an = menu1();                 //�˵�һ
		switch (an)
		{
		case 4:
			function2(ma_s,ma_c);                      //���ѧ��
			func_q();                                 //ͣ���ڵ�ǰ����
			break;
		case 2:                             
			function3(ma_t);                //¼����ʦ
			func_q();
			break;
		case 3:
			function5(ma_t);                         //ɾ����ʦ
			func_q();
			break;
		case 1:               //��½
			do {
				Sleep(1000);
				try                                           
				{
					bn = menu_ma();                                  //��½���
				}
				catch (const char* str)
				{
					cout << str << endl;                      //���������ѡ��Ĵ���
					cin.clear();
					while (cin.get() != '\n')
					{
						continue;                                     //���cin������
					}
					bn = 0;
				}
				switch (bn)
				{
				case 1:                                                 //ѧ����½
					name.clear();
					number.clear();                            //��մ洢����
					menu_name1(name, number);                                        //�˵�2
					flag3 = 0;                                //�ж��Ƿ��ҵ�����
					for (it4 = ma_s.begin(); it4 != ma_s.end(); it4++)               //����ѧ������
					{
						//cout << "debug1:"<<(*it4)->get_name() << endl;
						if (name.compare((*it4)->get_name()) == 0 && number.compare((*it4)->get_num()) == 0)
						{                                                   //������ѧ�ű��붼ƥ��
							flag3 = 1;                 //�ҵ������
							do
							{
								Sleep(1000);
								cn = menu_stu();                                     //ѧ����½����
								system("cls");                      //����
								switch (cn) 
								{
								case 1: 
									show_all_course(ma_sc, ma_c);                           //չʾ���пγ�
									func_q();
									break;
								case 2:
									(*it4)->show_my_course();                               //չʾ��ѧ���Ŀγ�
									func_q();
									break;
								case 3:
									(*it4)->select_course(ma_sc);                           //ѡ��
									func_q();
									break;
								case 4:
									(*it4)->Delete_my_course   (ma_sc);                           //ѡ��
									func_q();
									break;
								case 5:
									(*it4)->show_GDP_grade(ma_sc, ma_c);                //��ɼ���GDP
									func_q();
									break;
								case 6:
									(*it4)->show_my_inf();                       //չʾѧ������Ϣ
									func_q();
									break;
								case 0: break;                              //������һ����
								default: cout << "ѡ�����\n"; break;                 //�������
								}
							} while (cn);
						}
						else if (name.compare((*it4)->get_name()) != 0 && number.compare((*it4)->get_num()) == 0) //��������
						{
							flag3 = 1;
							cout << "�����������\n";
						}
						else if (name.compare((*it4)->get_name())== 0 && number.compare((*it4)->get_num()) != 0)//ѧ�ų���
						{
							flag3 = 1;
							cout << "ѧ���������\n";
						}
					}
					if (flag3 == 0 && it4 == ma_s.end())                      //û�ҵ�ƥ����
						cout << "�����ڸ��û�" << endl;
					break;
				case 2:
					name.clear();                                                                      //��ʦ��½
					number.clear();                                                                    //��ձ���
					menu_name1(name, number);                                                       //�˵�2
					flag2 = 0;
					for (it1 = ma_t.begin(); it1 != ma_t.end(); it1++)
					{
						if (name.compare((*it1)->get_name()) == 0 && number.compare((*it1)->get_num()) == 0)
						{
							flag2 = 1;
							do
							{
								Sleep(1000);
								dn = menu_te();                      //��ʦ�˵�
								system("cls");
								switch (dn)
								{
								case 1:
									show_all_course(ma_sc, ma_c);                    //չʾ���пγ�
									func_q();
									break;
								case 2:
									ptr = find(ma_sc, ma_c, (*it1)->get_course());           //�ҵ���ʦ���̵Ŀγ�
									(*it1)->show_my_students(ptr);                       //չʾ��ʦ��ѧ��
									func_q();
									break;
								case 3:
									ptr = find(ma_sc, ma_c, (*it1)->get_course());           //�ҵ���ʦ���̵Ŀγ�
									(*it1)->show_my_students(ptr);                                    //չʾ��ʦ��ѧ��
									cout << "��������Ҫ¼���ѧ�������ͳɼ�:";                            //¼��ѧ���ɼ�
									name.clear();
									cin >> name >> grade;                                                                //����ѧ���ͷ���
									(*it1)->record_grade(name, grade, ma_sc, ma_c);
									func_q();
									break;
								case 4:
									cout << "��������Ҫ�鿴��ѧ������:";                        //�鿴ѧ����Ϣ
									name.clear();
									cin >> name;
									ptr1 = find(ma_sc, ma_c, (*it1)->get_course());//�ҵ���ʦ���̵Ŀγ�
									(*it1)->show_stu_inf(name, ma_s, ptr1);                //չʾѧ����Ϣ
									func_q();
									break;
								case 5:
									(*it1)->show_my_inf();                      //չʾ��ʦ��Ϣ
									func_q();
									break;
									
								case 6:
									ptr = find(ma_sc, ma_c, (*it1)->get_course());           //�ҵ���ʦ���̵Ŀγ�
									(*it1)->show_my_students(ptr);                                    //չʾ��ʦ��ѧ��
									cout << "��������Ҫ�޸ĵ�ѧ�������ͳɼ�:";                            //¼��ѧ���ɼ�
									name.clear();
									cin >> name >> grade;                                                                //����ѧ���ͷ���
									(*it1)->change_grade( name,  grade, ma_s,ma_sc, ma_c);
									func_q();
									break;
								case 0: break;                    //������һѡ�����
								default: cout << "ѡ�����\n"; break;
								}
							} while (dn);
						}
						else if (name.compare((*it1)->get_name()) != 0 && number.compare((*it1)->get_num()) == 0) //��������
						{
							flag2 = 1;
							cout << "�����������\n";
						}
						else if (name.compare((*it1)->get_name()) == 0 && number.compare((*it1)->get_num()) != 0)//���ų���
						{
							flag2 = 1;
							cout << "�����������\n";
						}
					}
					if (flag2 == 0 && it1 == ma_t.end())                      //δ�ҵ������ʦ
						cout << "�����ڸ��û�" << endl;
					break;
				case 0:     break;                                      //���ص�½����
				default: cout << "ѡ�����\n"; break;
				}
			} while (bn);
			break;
		case 5:
			function4(ma_s);                                           //ɾ��ѧ��
			func_q();
			break;
		case 0:     break;
		default: cout << "ѡ�����\n";
		}
	}while (an);            //ѭ���˵�
		cout << "��л����ʹ�ã�" << endl;                                              
		for (int i = 0; i <= ma_s.size() - 1; i++)                        //�˳�ϵͳ�� �ͷ��ڴ�
			delete ma_s.at(i);
		for (int i = 0; i <= ma_sc.size() - 1; i++)
			delete ma_sc.at(i);
		for (int i = 0; i <= ma_t.size() - 1; i++)
			delete ma_t.at(i);
		for (int i = 0; i <= ma_c.size() - 1; i++)
			delete ma_c.at(i);

		return 0;
	}
