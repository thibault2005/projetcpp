#include "TimeException.h"
#include <iostream>
#include <string>
using namespace std;

namespace planning 
{
	TimeException::TimeException():Exception()
	{
		#ifdef DEBUG
        cout << ">>TimeException: Constructeur par défaut appelé<<" << endl;
        #endif

        setCode(0);
	}

	TimeException::TimeException(const string& myMessage ,int myCode):Exception(myMessage)
	{
		#ifdef DEBUG
        cout << ">>TimeException: Constructeur d'initialisation appelé<<" << endl;
        #endif

        setCode(myCode);
	}

	TimeException::TimeException(const TimeException& c):Exception(c)
	{
		#ifdef DEBUG
        cout << ">>TimeException: Constructeur de copie appelé<<" << endl;
        #endif

       setCode(c.getCode());
	}

	void TimeException::setCode(int myCode)
	{
		this->code=myCode;
	}

	int TimeException::getCode()const
	{
		return this->code;
	}

	const int TimeException::INVALID_HOUR = 1;
	const int TimeException::INVALID_MINUTE = 2;
	const int TimeException::OVERFLOW = 3;

}