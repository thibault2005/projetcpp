#ifndef EXCEPTION_H 
#define EXCEPTION_H 

#include <string>
using namespace std;

namespace planning{

class Exception
{

	protected:
		string message;

	public:
		Exception();
		Exception(const string&);
		Exception(const Exception&);
		~Exception()=default;

		
		void setMessage(const string&);
		string getMessage()const;


};

}
#endif