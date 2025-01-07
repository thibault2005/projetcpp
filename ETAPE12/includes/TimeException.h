#ifndef TIMEEXCEPTION_H 
#define TIMEEXCEPTION_H 

#include <string>
#include "Exception.h"
using namespace std;

namespace planning{


class TimeException : public Exception
{
	private:
		int code;

	public:
		TimeException();
		TimeException(const string&, int);
		TimeException(const TimeException&);
		~TimeException()=default;

		
		void setCode(int);
		int getCode()const;

 		static const int INVALID_HOUR;
    	static const int INVALID_MINUTE;
    	static const int OVERFLOW;
};




}
#endif