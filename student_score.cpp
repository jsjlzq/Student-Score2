#include "stdio.h"
#include "iostream.h"
#include "string.h"

class Stud
{
	int id;
	char *name;
	int cpp;	
public:
	static float sum,num;//����������̬��Ա���ݣ���ֵ��Ҫ�����ۼӵ�sum�����Զ���
	     //Ϊ��̬��ʹÿ���޸ĵ�ֵ�����Ա���������Եأ��������ľ�̬��Ա����
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
    friend void printgrade(Stud &stu);//����ĿҪ�󣬶�����Ԫ�������������
	                                  //��������κγ�Ա
};

float Stud::sum=0;//���徲̬������ԭ��˵���Ͷ�����˵��
float Stud::num=0;

void Stud::setdata(char *s,int m_id,int m_cpp)
{
	name=new char[strlen(s)+1];
	strcpy(name,s);
	id=m_id;
	cpp=m_cpp;
	sum+=cpp;
}

 float Stud::avg()//��̬�����Ķ�����˵������ʱ���ü�static�Ժ�������ԭ��˵��
{
	float res;
	if(num>0) res=sum/num;
	else cout<<"û��ѧ������!";
	return res;
}

void Stud::print()
{
	cout<<"ѧ��: "<<id<<" ����: "<<name<<" C++�ɼ�: "<<cpp<<endl;
}


void printgrade(Stud &stu)
{
	//cout<<"ѧ��"<<stu.id<<" ����"<<stu.name<<"C++�ɼ��ȼ�: ";
	cout<<"C++�ɼ��ȼ�: ";
	if(stu.cpp>=90) cout<<"��"<<endl;
	else if(stu.cpp>=80) cout<<"��"<<endl;
	else if(stu.cpp>=70) cout<<"��"<<endl; 
	else if(stu.cpp>=70) cout<<"��"<<endl; 
	else if(stu.cpp>=60) cout<<"����"<<endl; 
	else cout<<"������"<<endl;
}

void main()
{
	int i,n;
	char name[100];
	int id,cpp;
	cout<<"������ѧ������: ";
	cin>>n;
    Stud *pstu=new Stud[n];
	for(i=0;i<n;i++)
	{
		cout<<"��ֱ�����ѧ��,������C++�ɼ� ";
		cin>>id>>name>>cpp;
		pstu[i].setdata(name,id,cpp);
	}
	for(i=0;i<n;i++) {pstu[i].print();printgrade(pstu[i]);}
	cout<<Stud::num<<"��ѧ��ƽ����: "<<Stud::avg()<<endl;
}