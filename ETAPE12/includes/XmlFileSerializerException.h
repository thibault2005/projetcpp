#ifndef XML_FILE_SERIALIZER_EXCEPTION_H 
#define XML_FILE_SERIALIZER_EXCEPTION_H 
#include "Exception.h"
#include <string>


using namespace std;

namespace planning{


class XmlFileSerializerException : public Exception
{
    private:
        int code;

    public:
        XmlFileSerializerException();
        XmlFileSerializerException(const string&, int);
        XmlFileSerializerException(const XmlFileSerializerException&);
        ~XmlFileSerializerException()=default;

        
        void setCode(int);
        int getCode()const;

        static const int NOT_ALLOWED;
        static const int FILE_NOT_FOUND;
        static const int END_OF_FILE;
};

}

#endif