#ifndef SCHEDULABLE_H 
#define SCHEDULABLE_H 

#include <string>
using namespace std;

namespace planning{

class Schedulable
{
	friend ostream& operator<<(ostream&, const Schedulable&);

	protected:
		int id;
		static int currentId;
		

	public:
		Schedulable();
		Schedulable(int);
		Schedulable(const Schedulable&);
		~Schedulable();


		void setId(int);
		static void setCurrentId(int);


		int getId()const;
		static int getCurrentId();

		virtual string toString()const =0;
		virtual string tuple()const =0;

};

}

#endif

