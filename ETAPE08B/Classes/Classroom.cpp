#include "Classroom.h"
#include <iostream>
#include <string>
#include "Schedulable.h"

using namespace std;

namespace planning 
{
	Classroom::Classroom():Schedulable()
	{
		#ifdef DEBUG
        cout<< ">>Classroom: Constructeur par défaut appelé<<" << endl;
        #endif

        setSeatingCapacity(0);
        setName("----");
        
	}

	Classroom::Classroom(int n,const string& thename,int seat):Schedulable(n)
	{
		#ifdef DEBUG
        cout<< ">>Classroom: Constructeur d'initialisation appelé<<" << endl;
        #endif

        setName(thename);
        setSeatingCapacity(seat);
        

	}

	Classroom::Classroom(const Classroom& c):Schedulable(c)
	{
		#ifdef DEBUG
        cout<< ">>Classroom: Constructeur de copie appelé<<" << endl;
        #endif

        setName(c.getName());
        setSeatingCapacity(c.getSeatingCapacity());
    }


    void Classroom::setName(const string& thename)
    {
    	this->name=thename;
    }

    void Classroom::setSeatingCapacity(int seat)
    {
    	this->seatingCapacity=seat;
    }

    string Classroom::getName() const
    {
    	return this->name;
    }

    int Classroom::getSeatingCapacity() const
    {
    	return this->seatingCapacity;
    } 


    string Classroom::toString()const 
    {
        return name + "(" + to_string(seatingCapacity) + ")";
    }

    string Classroom::tuple()const 
    {
        return to_string(id) +";"+ name + "(" + to_string(seatingCapacity) + ")";
    }

    Classroom& Classroom::operator=(const Classroom& myClassroom) 
    {
	    if (this != &myClassroom) 
	    {
		    Schedulable::operator=(myClassroom); 
		    this->seatingCapacity = myClassroom.seatingCapacity;
		    this->name = myClassroom.name;
	    }

    	return *this;
	}


    istream& operator>>(istream& s,Classroom& room) 
    {
        string sId,sSeatingCapacity,sName,tag;

        getline(s,tag);

        getline(s,tag);
        getline(s,sId);
        getline(s,tag);

        getline(s,tag);
        getline(s,sSeatingCapacity);
        getline(s,tag);

        getline(s,tag);
        getline(s,sName);
        getline(s,tag);

        getline(s,tag);

        room.setId(stoi(sId));
        room.setSeatingCapacity(stoi(sSeatingCapacity));
        room.setName(sName);

        return s;
    }

    ostream& operator<<(ostream& s, const Classroom& room) 
    {

        s<<"<Classroom>"<<endl;

        s<<"<id>"<<endl;
        s<<room.getId()<<endl;
        s<<"</id>"<<endl;

        s<<"<seatingCapacity>"<<endl;
        s<<room.getSeatingCapacity()<<endl;
        s<<"</seatingCapacity>"<<endl;

        s<<"<name>"<<endl;
        s<<room.getName()<<endl;
        s<<"</name>"<<endl;

        s<<"</Classroom>";

        return s;
    }

    bool Classroom::operator<(const Classroom& other) const 
    {
        return this->getName() < other.getName(); // comparaison sur le nom pour <set>
    }
}