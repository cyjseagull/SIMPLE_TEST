/*************************************************************************
    > File Name: Subject.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Tue 10 Feb 2015 02:46:04 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <iostream>
using namespace std;

//common interface of ConcreteSubject and Proxy
class Subject
{
	public:
		//for call successors' destructor function,this must added
		virtual ~Subject(){

		}

		virtual void Request()=0;
};


class ConcreteSubject:public Subject
{
	public:
		void Request()
		{
			cout<<"real request"<<endl;
		}

};

class Proxy:public Subject
{
	public:
		Proxy()
		{
			cout<<"create a new light level proxy object"<<endl;
		}

		~Proxy()
		{
			if(con_object)
			{
				cout<<"destructor light level proxy object"<<endl;
				delete con_object;
				con_object = NULL;
			}
		}

		//delay ConcreteSubject operation till this function
		void Request()
		{
			if(!con_object)
			{
				con_object = new ConcreteSubject();
			}
			this->DoSomething1();
			con_object->Request();
			this->DoSomething2();
			
		}

		void DoSomething1()
		{
			cout<<"do something before call real request"<<endl;
		}

		void DoSomething2()
		{
			cout<<"do something after call real request"<<endl;
		}

	private:
		ConcreteSubject *con_object;
};


#endif
