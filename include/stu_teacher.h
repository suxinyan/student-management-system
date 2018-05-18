#ifndef _C_H_
#define _C_H_
#include <stu_data.h>

/*!***************************************************
* @file: stu_teacher.h
* @brief: for testing
* @author:  PPsu
* @date: 2018, 4, 20
* @note:store the basic data stucture of the teacher class.
****************************************************/
class stu_teacher
{
private:
	string te_number;         // ��ʦ����
	string te_college;          //ѧԺ
	string te_subject;           //ѧ��
	string te_name;             //��ʦ����
	char sex;                   //�Ա�

public:
	string get_name();                        //�õ���ʦ����
	string get_num();                      //�õ���ʦ����
	string get_course();                         //�õ���ʦѧ��
	stu_teacher(){}                                   //Ĭ�Ϲ��캯��
	stu_teacher(string num, string college, string subject, string name, int s) : te_number(num), te_college(college), te_subject(subject), te_name(name), sex(s) {}
	~stu_teacher() { cout << "destruct teacher!" << endl; }//��������
	void show_my_students(const stu_course *c);             //��ʾ�ҵ�ѧ��
	void record_grade(const string name, const double grade,   vector<selective_course*> &SCourse, vector<compul_course*> &CCourse);
	//¼��ѧ���ܳɼ�
	void change_grade(const string name, const double grade, vector<stu_student*> &stu, vector<selective_course*> &SCourse, vector<compul_course*> &CCourse);
	//����ѧ���ɼ�
	void show_my_inf();      //��ʾ�ҵ���Ϣ
	void show_stu_inf( string name , vector<stu_student*> &stu, const stu_course *c);//��ʾ��ʦ��ѧ����Ϣ
};
void function3(vector<stu_teacher*>&ma_t);  //����������ʦ��ӣ�ɾ��
void function5(vector<stu_teacher*>&ma_t);
#endif