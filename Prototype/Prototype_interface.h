/*************************************************************************
    > File Name: Prototype_interface.h
    > Author: YuJie Chen
    > Mail: cyjseagull@163.com 
    > Created Time: Sat 07 Feb 2015 04:40:21 PM CST
    > Function: 
    > Para:
 ************************************************************************/
#ifndef _PROTOTYPE_INTERFACE_H_
#define _PROTOTYPE_INTERFACE_H_

//interface of prototype
class PrototypeInterface
{
	public:

		virtual PrototypeInterface(){

		}

		virtual ~PrototypeInterface(){
			
		}

		virtual PrototypeInterface *Clone(){

		}
		
		virtual void SetName(char *name){

		}
		
		virtual void Show(){

		}

	protected:
		char *name;
};


class ConcretePrototype: public PrototypeInterface
{
	public:
		//constructor
		ConcretePrototype( char *name);
		//copy constructor
		ConcretPrototype( const ConcretPrototype &r);
		~ConcretPrototype();
		//clone
		ConcretePrototype* Clone();

		void show();

};


#endif

