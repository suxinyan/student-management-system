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
	string te_number;         // 老师工号
	string te_college;          //学院
	string te_subject;           //学科
	string te_name;             //老师姓名
	char sex;                   //性别

public:
	string get_name();                        //得到老师姓名
	string get_num();                      //得到老师工号
	string get_course();                         //得到老师学科
	stu_teacher(){}                                   //默认构造函数
	stu_teacher(string num, string college, string subject, string name, int s) : te_number(num), te_college(college), te_subject(subject), te_name(name), sex(s) {}
	~stu_teacher() { cout << "destruct teacher!" << endl; }//析构函数
	void show_my_students(const stu_course *c);             //显示我的学生
	void record_grade(const string name, const double grade,   vector<selective_course*> &SCourse, vector<compul_course*> &CCourse);
	//录入学生能成绩
	void change_grade(const string name, const double grade, vector<stu_student*> &stu, vector<selective_course*> &SCourse, vector<compul_course*> &CCourse);
	//更改学生成绩
	void show_my_inf();      //显示我的信息
	void show_stu_inf( string name , vector<stu_student*> &stu, const stu_course *c);//显示老师的学生信息
};
void function3(vector<stu_teacher*>&ma_t);  //主函数的老师添加，删除
void function5(vector<stu_teacher*>&ma_t);
#endif