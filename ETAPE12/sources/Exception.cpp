#include "Exception.h"
#include <iostream>
#include <string>
using namespace std;

namespace planning 
{
	Exception::Exception()
	{
		#ifdef DEBUG
        cout << ">>Exception: Constructeur par defaut appelé:<<" <<endl;
        #endif
        setMessage("  ");
	}

	Exception::Exception(const string& myMessage)
	{
		#ifdef DEBUG
        cout << ">>Exception: Constructeur d'initialistion appelé:<<" <<endl;
        #endif

        setMessage(myMessage);
	}

	Exception::Exception(const Exception&c)
	{
		#ifdef DEBUG
        cout << ">>Exception: Constructeur de copie appelé:<<" <<endl;
        #endif

        setMessage(c.getMessage());
	}

	void Exception::setMessage(const string& myMessage)
	{
		this->message=myMessage;
	}

	string Exception::getMessage()const
	{
		return this->message;
	}


}