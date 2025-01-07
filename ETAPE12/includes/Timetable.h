#ifndef TIMETABLE_H 
#define TIMETABLE_H 

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
#include <set>
#include <list>
#include "Classroom.h"
#include "Professor.h"
#include "Group.h"
#include "Schedulable.h"
#include "Course.h"
#include "XmlFileSerializer.hpp"
#include "TimingException.h"

namespace planning {
class Timetable 
{ 
  private: 
    set<Classroom> classrooms; 
    set<Professor> professors; 
    set<Group>     groups;
    list<Course> courses; 

    static Timetable* instance;

    Timetable();
    Timetable(const Timetable&) = delete;
    Timetable& operator=(const Timetable&) = delete;
 
  public: 
   ~Timetable(); 

   static Timetable& getInstance();

   const set<Professor>& getProfessors() const;
   const set<Classroom>& getClassrooms() const;
   const set<Group>& getGroups() const;

   list<Course>& getCourses();

 
   int addClassroom(const string& name,int seatingCapacity); 
   void displayClassrooms() const; 
   Classroom findClassroomByIndex(int index) const; 
   Classroom findClassroomById(int id) const; 
   void deleteClassroomByIndex(int index); 
   void deleteClassroomById(int id); 
 
   int addProfessor(const string& lastName,const string& firstName); 
   void displayProfessors() const; 
   Professor findProfessorByIndex(int index) const; 
   Professor findProfessorById(int id) const; 
   void deleteProfessorByIndex(int index); 
   void deleteProfessorById(int id); 
 
   int addGroup(const string& name); 
   void displayGroups() const; 
   Group findGroupByIndex(int index) const; 
   Group findGroupById(int id) const; 
   void deleteGroupByIndex(int index); 
   void deleteGroupById(int id); 

   void save(const string& timetableName);
   void load(const string& timetableName);
   void vider(); 

   bool isProfessorAvailable(int id, const Timing& timing) const;
   bool isGroupAvailable(int id, const Timing& timing) const ;
   bool isClassroomAvailable(int id, const Timing& timing) const ; 
   void schedule(Course& c, const Timing& t);

   string tuple(const Course& c) const;

   void importProfessorsFromCsv(const string& filename);
   void importGroupsFromCsv(const string& filename);
   void importClassroomsFromCsv(const string& filename);

   void exportProfessorTimetable(int id);
   void exportGroupTimetable(int id);
   void exportClassroomTimetable(int id);
}; 

}

#endif