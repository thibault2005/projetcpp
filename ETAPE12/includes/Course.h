#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <set>
#include "Event.h"
#include<iostream>
#include <sstream>

using namespace std;

namespace planning 
{
    
    class Course : public Event 
    {
        // Définition de l'opérateur <<
        friend ostream& operator<<(ostream& os, const Course& course);
        friend istream& operator>>(istream& is, Course& course);

    private:
        int professorId;
        int classroomId;
        set<int> groupsIds;

    public:
        // Constructeurs
        Course();
        //Course(int code, const char* title, const Timing& timing, int professorId, int classroomId);

        // Accesseurs et mutateurs
        int getProfessorId() const;
        void setProfessorId(int id);

        int getClassroomId() const;
        void setClassroomId(int id);

        const set<int>& getGroupsIds() const;
        void addGroupId(int id);
        bool isGroupIdPresent(int id) const;

        // Méthodes de comparaison (ordre chronologique)
        bool operator<(const Course&)const;
        Course& operator=(const Course&);


        
    };
}

#endif
