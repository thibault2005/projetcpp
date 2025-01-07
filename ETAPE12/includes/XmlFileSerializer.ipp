#include "XmlFileSerializer.hpp"
#include "XmlFileSerializerException.h"




using namespace std;

namespace planning {
template <typename T>
XmlFileSerializer<T>::XmlFileSerializer(const string&fn,char m, const string& cn)
{
	#ifdef DEBUG
        cout << ">>XmlFileSerializer: Constructeur  d'initialisation appelé:<<" <<endl;
    #endif
    filename=fn;
    mode=m;
    collectionName= cn;

    if(mode ==WRITE)
    {
    	file.open(filename,ios::out);
    	file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" <<endl;
    	file<< "<"<<collectionName<<">"<<endl;
    }

    if(mode==READ)
    {
    	string s;
    	file.open(filename,ios::in);

    	 if (!file.is_open())
        {
            throw XmlFileSerializerException("Le fichier n'est pas ouvert", XmlFileSerializerException::FILE_NOT_FOUND);
        }

        
        getline(file, s);
        getline(file, s);
        collectionName = s.substr(1, s.length() - 2);
		
	 
    }
	
}

template <typename T>
XmlFileSerializer<T>::~XmlFileSerializer()
{
	if(mode==WRITE)
	{
		file<< "</"<<collectionName<<">"<<endl;
	}
	file.close();

}

template <typename T>
string XmlFileSerializer<T>::getFilename() const
{
	return filename;
}

template <typename T>
string XmlFileSerializer<T>::getCollectionName() const
{
	return collectionName;
}


template <typename T>
void XmlFileSerializer<T>::write(const T& obj)
{
	if (mode != WRITE) 
	{
        throw XmlFileSerializerException("Le fichier n'est pas ouvert en mode WRITE",XmlFileSerializerException::NOT_ALLOWED);
    }

    file << obj<<'\n';

}

template <typename T>
T XmlFileSerializer<T>::read()
{
    if (mode != READ) 
    {
        throw XmlFileSerializerException("Le fichier n'est pas ouvert en mode READ", XmlFileSerializerException::NOT_ALLOWED);
    }

    T obj;
    string ligne;

    streampos position = file.tellg();

    file >> ligne;
     
    if (ligne == "</" + collectionName + ">") 
    {
        throw XmlFileSerializerException("Fin du fichier atteinte", XmlFileSerializerException::END_OF_FILE);
    }

      

    
    file.seekg(position);
    file >> obj;

    return obj;
}




template <typename T>
bool XmlFileSerializer<T>::isReadable() const
{
	if(mode==READ)
	{
		return true;
	}
	else
	{
		return false;
	}

}

template <typename T>
bool XmlFileSerializer<T>::isWritable() const
{
	if(mode==WRITE)
	{
		return true;
	}
	else
	{
		return false;
	}

}
template <typename T>
const char XmlFileSerializer<T>::READ = 'R';

template <typename T>
const char XmlFileSerializer<T>::WRITE = 'W';

}