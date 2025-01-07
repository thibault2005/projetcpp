#include "TimingException.h"
using namespace std;
#include <iostream>
#include <string.h>

namespace planning
{
	TimingException::TimingException():Exception()
	{
		#ifdef DEBUG
        cout << ">>TimingException: Constructeur par défaut appelé<<" << endl;
        #endif

        setCode(0);
	}

	TimingException::TimingException(const string& myMessage, int myCode):Exception(myMessage)
	{
		#ifdef DEBUG
        cout << ">>TimingException: Constructeur d'initialisation appelé<<" << endl;
        #endif

        setCode(myCode);

	}

	TimingException::TimingException(const TimingException&c):Exception(c)
	{
		#ifdef DEBUG
        cout << ">>TimingException: Constructeur de copie appelé<<" << endl;
        #endif

       setCode(c.getCode());
	}

	void TimingException::setCode(int myCode)
	{
		this->code=myCode;
	}

	int TimingException::getCode()const
	{
		return this->code;
	}

	const int TimingException::INVALID_DAY = 4;
	const int TimingException::NO_TIMING = 5;

	










}

