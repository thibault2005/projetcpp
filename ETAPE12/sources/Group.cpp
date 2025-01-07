#include "Group.h"
#include <iostream>
#include <string>
#include "Schedulable.h"
using namespace std;

namespace planning 
{
	Group::Group():Schedulable()
	{
		#ifdef DEBUG
        cout<< ">>Group: Constructeur par défaut appelé<<" << endl;
        #endif

        setName("----");
	}

	Group::Group(int n,const string& m):Schedulable(n)
	{
		#ifdef DEBUG
        cout<< ">>Group: Constructeur d'initialisation appelé<<" << endl;
        #endif

        setName(m);

	}

	Group::Group(const Group& c):Schedulable(c)
	{
		#ifdef DEBUG
        cout<< ">>Group: Constructeur de copie appelé<<" << endl;
        #endif

        setName(c.getName());

	}


	void Group::setName(const string& c)
	{
		this->name=c;
	}

	string Group::getName()const
	{
		return this->name;
	}

	string Group::toString()const 
    {
        return name;
    }

    string Group::tuple()const 
    {
        return to_string(id) + ";" + name;
    }

    Group& Group::operator=(const Group& myGroup) 
    {
	    if (this != &myGroup) 
	    {
		    Schedulable::operator=(myGroup); 
		    this->name = myGroup.name;
	    }

    	return *this;
	}

	bool Group::operator<(const Group& other) const 
    {
        return this->getName() < other.getName(); // comparaison sur le nom pour <set>
    }

	 ostream& operator<<(ostream& s, const Group& group) 
	 {
        s << "<Group>" << endl;

        s << "<id>" << endl;
        s << group.getId() << endl;
        s << "</id>" << endl;

        s << "<name>" << endl;
        s << group.getName() << endl;
        s << "</name>" << endl;

        s << "</Group>";
        return s;
    }

    istream& operator>>(istream& s, Group& group) 
	{
        string tag, sId, sName;

        getline(s, tag); // <Group>
        getline(s, tag); // <id>
        getline(s, sId);
        getline(s, tag); // </id>

        getline(s, tag); // <name>
        getline(s, sName);
        getline(s, tag); // </name>

        getline(s, tag); // </Group>

        group.setId(stoi(sId));
        group.setName(sName);

        return s;
    }



}