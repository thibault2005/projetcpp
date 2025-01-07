#include "XmlFileSerializerException.h"
#include <iostream>
#include <string>
using namespace std;


using namespace planning;

XmlFileSerializerException::XmlFileSerializerException():Exception()
{
	#ifdef DEBUG
    cout << ">>XmlFileSerializerException: Constructeur par défaut appelé<<" << endl;
    #endif

    setCode(0);
}

XmlFileSerializerException::XmlFileSerializerException(const string& myMessage ,int myCode):Exception(myMessage)
{
	#ifdef DEBUG
    cout << ">>XmlFileSerializerException: Constructeur d'initialisation appelé<<" << endl;
    #endif

    setCode(myCode);
}

XmlFileSerializerException::XmlFileSerializerException(const XmlFileSerializerException& c):Exception(c)
{
	#ifdef DEBUG
    cout << ">>XmlFileSerializerException: Constructeur de copie appelé<<" << endl;
    #endif

   setCode(c.getCode());
}

void XmlFileSerializerException::setCode(int myCode)
{
	this->code=myCode;
}

int XmlFileSerializerException::getCode()const
{
	return this->code;
}

const int XmlFileSerializerException::NOT_ALLOWED = 1;
const int XmlFileSerializerException::FILE_NOT_FOUND = 2;
const int XmlFileSerializerException::END_OF_FILE = 3;
