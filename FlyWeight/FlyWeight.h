/*************************************************************************
    > File Name: FlyWeight.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Tue 10 Feb 2015 09:27:53 AM CST
    > Function: 
    > Para:
 ************************************************************************/
#ifndef _FLYWEIGHT_H_
#define _FLYWEIGHT_H_
#include <map>
#include <iterator>

#include <iostream>
using namespace std;

class FlyWeight
{
	public:
		virtual void Operation(){};

};

class External:public FlyWeight
{
	public:
		void Operation()
		{
			cout<<"I'm External FlyWeight operation"<<endl;
		}
};


class Internal:public FlyWeight
{
	public:

		Internal(int key)
		{
			this->key = key;
		}

		void Operation()
		{
			cout<<"my key is："<<this->key<<endl;
		}

		int GetKey()
		{
			return key;
		}

		void SetKey(int key)
		{
			this->key = key;
		}
	private:
		int key;
};


class FlyWeightFactory
{
	public:
		FlyWeight *GetFlyWeight(int key)
		{
			 FlyWeight* flyweight;
		     std::map<int,FlyWeight *>::iterator it;
			 it = FlyWeight_map.find(key);
			 if( it!=FlyWeight_map.end() )
			 {
				 cout<<"find key specified FlyWeight"<<endl;
				 return it->second;			
			 }
			 else
			 {
				flyweight = new Internal(key);
				FlyWeight_map.insert(pair<int,FlyWeight*>(key,flyweight));
				return flyweight;
			 }
		}

		int GetSize()
		{
			return FlyWeight_map.size();
		}
	private:
		std::map<int,FlyWeight *> FlyWeight_map;
		
};

#endif

