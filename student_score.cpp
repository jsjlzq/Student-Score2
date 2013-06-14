#include "stdio.h"
#include "iostream.h"
#include "string.h"

class Stud
{
	int id;
	char *name;
	int cpp;	
public:
	static float sum,num;//定义两个静态成员数据，数值需要不断累加的sum，可以定义
	     //为静态，使每次修改的值都可以被保留，相对地，定义它的静态成员函数
	Stud()
	{
		name=NULL;
		num++;
	};
	~Stud()
	{
		if(name) delete [] name;
		num--;
	};
	void setdata(char *s,int m_id,int m_cpp);
	void print();
	static float avg();
    friend void printgrade(Stud &stu);//按题目要求，定义友元函数输出，可以
	                                  //访问类的任何成员
};

float Stud::sum=0;//定义静态变量，原型说明和定义型说明
float Stud::num=0;

void Stud::setdata(char *s,int m_id,int m_cpp)
{
	name=new char[strlen(s)+1];
	strcpy(name,s);
	id=m_id;
	cpp=m_cpp;
	sum+=cpp;
}

 float Stud::avg()//静态函数的定义型说明，此时不用加static对函数进行原型说明
{
	float res;
	if(num>0) res=sum/num;
	else cout<<"没有学生对象!";
	return res;
}

void Stud::print()
{
	cout<<"学号: "<<id<<" 姓名: "<<name<<" C++成绩: "<<cpp<<endl;
}


void printgrade(Stud &stu)
{
	//cout<<"学号"<<stu.id<<" 姓名"<<stu.name<<"C++成绩等级: ";
	cout<<"C++成绩等级: ";
	if(stu.cpp>=90) cout<<"优"<<endl;
	else if(stu.cpp>=80) cout<<"良"<<endl;
	else if(stu.cpp>=70) cout<<"中"<<endl; 
	else if(stu.cpp>=70) cout<<"中"<<endl; 
	else if(stu.cpp>=60) cout<<"及格"<<endl; 
	else cout<<"不及格"<<endl;
}

void main()
{
	int i,n;
	char name[100];
	int id,cpp;
	cout<<"请输入学生个数: ";
	cin>>n;
    Stud *pstu=new Stud[n];
	for(i=0;i<n;i++)
	{
		cout<<"请分别输入学号,姓名和C++成绩 ";
		cin>>id>>name>>cpp;
		pstu[i].setdata(name,id,cpp);
	}
	for(i=0;i<n;i++) {pstu[i].print();printgrade(pstu[i]);}
	cout<<Stud::num<<"个学生平均分: "<<Stud::avg()<<endl;
}