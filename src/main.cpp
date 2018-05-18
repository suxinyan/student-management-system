#include "stu_course.h"                //头文件
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
	vector<compul_course*>&ma_c)                          //初始化函数
{
	cout << "初始化信息：" << endl;
	ifstream fin("E:\\sususu\\mystudy\\book.txt");                      //打开文件读
	ifstream xin("E:\\sususu\\mystudy\\clas.txt");
	string name, Class, college, number;                            //学号 学院 班级 姓名 性别
	int cre, k;                         //学分， 初始化的课程冗余量，必修课设为-1000，表示很大，选修课设为0，均不能超过最大值MAX_P_SIZE;
	char sex;               //性别，w女，m男
	if (!fin.is_open())                               //打开文件失败
	{
		cout << "Error opening file"; 
		exit(1);
	}
	if (!xin.is_open())                   //打开文件失败
	{
		cout << "Error opening file"; 
		exit(1);
	}
	for (int i = 0; i< MAX_SIZE - 1; i++)
	{
		fin >> number >> college >> Class >> name >> sex;          //学号 学院 班级 姓名 性别  （学生）
		stu_student* stu = new stu_student(number, college, Class, name, sex);
		ma_s.push_back(stu);
	}
	for (int i = 0; i< MAX_SIZE - 1; i++)
	{
		fin >> number >> college >> Class >> name >> sex;                 //老师的初始化
		stu_teacher* te = new stu_teacher(number, college, Class, name, sex);
		ma_t.push_back(te);
	}
	for (int i = 0; i< MAX_C_SIZE; i++)
	{
		xin >> number >> name;                           //课程号 课程名 
		xin >> cre >> k;                     //学分 课余量
		compul_course* te = new compul_course(number, name, cre, k);
		vector<stu_student*>::iterator it1 = ma_s.begin();
		for (; it1 != ma_s.end(); it1++)                                      
		{
			te->add_person((*it1)->get_name());                   //把所有学生加入全部必修课名单
		}
		ma_c.push_back(te);
	}
	for (int i = 0; i< MAX_S_SIZE; i++)
	{
		xin >> number >> name;
		xin >> cre >> k;
		selective_course* te = new selective_course(number, name, cre, k);        //选修课名单
		ma_sc.push_back(te);
	}
	fin.close();            //关闭文件
	xin.close();
	cout << "\n\nInit successfully!" << endl;
	cout << "按ENTER键继续..." << endl;
}

void function2(vector<stu_student*> &ma_s, vector<compul_course*>&ma_cs)               //添加学生
{
	string name, Class, college, number;
	char sex;
	cout << "输入您想添加的学生信息:" << endl;
	cout << "姓名：";
	cin >> name;
	cout << "学号：";
	cin >> number;
	cout << "学院：";
	cin >> college;
	cout << "班级：";
	cin >> Class;
	cout << "性别：";
	cin >> sex;
	while (cin.good() == 0)                    //性别输入有误的处理
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			continue;
		}
		cout << "重新输入性别：";
		cin >> sex;
	}
	stu_student* stu = new stu_student(number, college, Class, name, sex);
	ma_s.push_back(stu);
	vector<compul_course*>::iterator it1 = ma_cs.begin();
	for (; it1 != ma_cs.end(); it1++)
	{
		(*it1)->add_person(stu->get_name());                   //把所有学生加入全部必修课名单
	}
	cout << "添加成功！\n";

}

void func_q()                                                //在该窗口停留
{
	char f;
	cout << "\n\nInput 'q' to last window.";
	cin >> f;
	while (f != 'q')
		cin >> f;
}

int main()
{
	int an, bn, cn, dn;                     //菜单栏

	int flag = 0, flag2 = 0, flag3 = 0;              //判断标识
	string name, number;                         //存储姓名， 学号的变量
	double grade;                                        //存储分数的变量
	stu_course * ptr = NULL;                            //指向学生课程变量的指针
	stu_course * ptr1 = NULL;
	vector<stu_teacher*>ma_t;                           //存储老师指针的向量
	vector<selective_course*>ma_sc;                //存储选修课指针的向量
	vector<compul_course*>ma_c;                 //存储必修课指针的向量
	vector<stu_student *> ma_s;                      //存储学生指针的向量
	vector<stu_teacher*>::iterator it1 = ma_t.begin();               //迭代器
	vector<selective_course*>::iterator it2 = ma_sc.begin();
	vector<compul_course*>::iterator it3 = ma_c.begin();
	vector<stu_student *> ::iterator it4 = ma_s.begin();

	init(ma_s, ma_t, ma_sc, ma_c);          //初始化
	do {
		Sleep(1000);                             //减慢画面跳转速度
		an = menu1();                 //菜单一
		switch (an)
		{
		case 4:
			function2(ma_s,ma_c);                      //添加学生
			func_q();                                 //停留在当前窗口
			break;
		case 2:                             
			function3(ma_t);                //录入老师
			func_q();
			break;
		case 3:
			function5(ma_t);                         //删除老师
			func_q();
			break;
		case 1:               //登陆
			do {
				Sleep(1000);
				try                                           
				{
					bn = menu_ma();                                  //登陆入口
				}
				catch (const char* str)
				{
					cout << str << endl;                      //输入非数字选项的处理
					cin.clear();
					while (cin.get() != '\n')
					{
						continue;                                     //清空cin输入流
					}
					bn = 0;
				}
				switch (bn)
				{
				case 1:                                                 //学生登陆
					name.clear();
					number.clear();                            //清空存储变量
					menu_name1(name, number);                                        //菜单2
					flag3 = 0;                                //判断是否找到此人
					for (it4 = ma_s.begin(); it4 != ma_s.end(); it4++)               //遍历学生向量
					{
						//cout << "debug1:"<<(*it4)->get_name() << endl;
						if (name.compare((*it4)->get_name()) == 0 && number.compare((*it4)->get_num()) == 0)
						{                                                   //姓名和学号必须都匹配
							flag3 = 1;                 //找到这个人
							do
							{
								Sleep(1000);
								cn = menu_stu();                                     //学生登陆界面
								system("cls");                      //清屏
								switch (cn) 
								{
								case 1: 
									show_all_course(ma_sc, ma_c);                           //展示所有课程
									func_q();
									break;
								case 2:
									(*it4)->show_my_course();                               //展示该学生的课程
									func_q();
									break;
								case 3:
									(*it4)->select_course(ma_sc);                           //选课
									func_q();
									break;
								case 4:
									(*it4)->Delete_my_course   (ma_sc);                           //选课
									func_q();
									break;
								case 5:
									(*it4)->show_GDP_grade(ma_sc, ma_c);                //查成绩和GDP
									func_q();
									break;
								case 6:
									(*it4)->show_my_inf();                       //展示学生的信息
									func_q();
									break;
								case 0: break;                              //返回上一界面
								default: cout << "选择错误。\n"; break;                 //输入出错
								}
							} while (cn);
						}
						else if (name.compare((*it4)->get_name()) != 0 && number.compare((*it4)->get_num()) == 0) //姓名出错
						{
							flag3 = 1;
							cout << "姓名输入错误！\n";
						}
						else if (name.compare((*it4)->get_name())== 0 && number.compare((*it4)->get_num()) != 0)//学号出错
						{
							flag3 = 1;
							cout << "学号输入错误！\n";
						}
					}
					if (flag3 == 0 && it4 == ma_s.end())                      //没找到匹配项
						cout << "不存在该用户" << endl;
					break;
				case 2:
					name.clear();                                                                      //老师登陆
					number.clear();                                                                    //清空变量
					menu_name1(name, number);                                                       //菜单2
					flag2 = 0;
					for (it1 = ma_t.begin(); it1 != ma_t.end(); it1++)
					{
						if (name.compare((*it1)->get_name()) == 0 && number.compare((*it1)->get_num()) == 0)
						{
							flag2 = 1;
							do
							{
								Sleep(1000);
								dn = menu_te();                      //老师菜单
								system("cls");
								switch (dn)
								{
								case 1:
									show_all_course(ma_sc, ma_c);                    //展示所有课程
									func_q();
									break;
								case 2:
									ptr = find(ma_sc, ma_c, (*it1)->get_course());           //找到老师所教的课程
									(*it1)->show_my_students(ptr);                       //展示老师的学生
									func_q();
									break;
								case 3:
									ptr = find(ma_sc, ma_c, (*it1)->get_course());           //找到老师所教的课程
									(*it1)->show_my_students(ptr);                                    //展示老师的学生
									cout << "请输入您要录入的学生姓名和成绩:";                            //录入学生成绩
									name.clear();
									cin >> name >> grade;                                                                //输入学生和分数
									(*it1)->record_grade(name, grade, ma_sc, ma_c);
									func_q();
									break;
								case 4:
									cout << "请输入您要查看的学生姓名:";                        //查看学生信息
									name.clear();
									cin >> name;
									ptr1 = find(ma_sc, ma_c, (*it1)->get_course());//找到老师所教的课程
									(*it1)->show_stu_inf(name, ma_s, ptr1);                //展示学生信息
									func_q();
									break;
								case 5:
									(*it1)->show_my_inf();                      //展示老师信息
									func_q();
									break;
									
								case 6:
									ptr = find(ma_sc, ma_c, (*it1)->get_course());           //找到老师所教的课程
									(*it1)->show_my_students(ptr);                                    //展示老师的学生
									cout << "请输入您要修改的学生姓名和成绩:";                            //录入学生成绩
									name.clear();
									cin >> name >> grade;                                                                //输入学生和分数
									(*it1)->change_grade( name,  grade, ma_s,ma_sc, ma_c);
									func_q();
									break;
								case 0: break;                    //返回上一选择界面
								default: cout << "选择错误。\n"; break;
								}
							} while (dn);
						}
						else if (name.compare((*it1)->get_name()) != 0 && number.compare((*it1)->get_num()) == 0) //姓名出错
						{
							flag2 = 1;
							cout << "姓名输入错误！\n";
						}
						else if (name.compare((*it1)->get_name()) == 0 && number.compare((*it1)->get_num()) != 0)//工号出错
						{
							flag2 = 1;
							cout << "工号输入错误！\n";
						}
					}
					if (flag2 == 0 && it1 == ma_t.end())                      //未找到这个老师
						cout << "不存在该用户" << endl;
					break;
				case 0:     break;                                      //返回登陆界面
				default: cout << "选择错误。\n"; break;
				}
			} while (bn);
			break;
		case 5:
			function4(ma_s);                                           //删除学生
			func_q();
			break;
		case 0:     break;
		default: cout << "选择错误。\n";
		}
	}while (an);            //循环菜单
		cout << "感谢您的使用！" << endl;                                              
		for (int i = 0; i <= ma_s.size() - 1; i++)                        //退出系统， 释放内存
			delete ma_s.at(i);
		for (int i = 0; i <= ma_sc.size() - 1; i++)
			delete ma_sc.at(i);
		for (int i = 0; i <= ma_t.size() - 1; i++)
			delete ma_t.at(i);
		for (int i = 0; i <= ma_c.size() - 1; i++)
			delete ma_c.at(i);

		return 0;
	}
