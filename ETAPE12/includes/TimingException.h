#ifndef TIMINGEXCEPTION_H 
#define TIMINGEXCEPTION_H 

#include <string>
#include "Exception.h"
using namespace std;

namespace planning{


class TimingException : public Exception
{
	private:
		int code;

	public:
		TimingException();
		TimingException(const string&,int);
		TimingException(const TimingException&);
		~TimingException()=default;

		
		void setCode(int);
		int getCode()const;

		static const int INVALID_DAY;
		static const int NO_TIMING;

};




}
#endif