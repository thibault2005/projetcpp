#ifndef PROFESSOR_H 
#define PROFESSOR_H 

#include <string>
#include "Schedulable.h"
using namespace std;

namespace planning 
{

	class Professor : public Schedulable 
	{

	    private:
	        string lastName;
	        string firstName;

	    public:
	        Professor();
	        Professor(int, const string &, const string &);
			
	        Professor(const Professor &);
	        ~Professor() = default;

	        void setLastName(const string &);
	        void setFirstName(const string &);

	        string getLastName() const;
	        string getFirstName() const;

	        string toString()const override;
	        string tuple()const override;


	    	Professor& operator=(const Professor&);

		 	bool operator<(const Professor& ) const ;
	};

}
#endif
