#ifndef XML_FILE_SERIALIZER_H
#define XML_FILE_SERIALIZER_H

#include <fstream>
#include <iostream>
#include <string>
#include "XmlFileSerializerException.h"




using namespace std;

namespace planning {
template <typename T>
class XmlFileSerializer
{
    private:
        fstream file;        
        string filename;         
        char mode;                 
        string collectionName;

    public:
        XmlFileSerializer()=delete;
        XmlFileSerializer(const string&,char m,const string& cn="entities");
        XmlFileSerializer(const XmlFileSerializer&)=delete;
        ~XmlFileSerializer();
        
        string getFilename() const;
        string getCollectionName() const;
        void write(const T&);
        T read();   

        XmlFileSerializer<T>& operator=( const XmlFileSerializer<T>&) =delete;     
        
        bool isReadable() const;
        bool isWritable() const;

        static const char READ; 
        static const char WRITE;
};
}

#include "XmlFileSerializer.ipp"
#endif
