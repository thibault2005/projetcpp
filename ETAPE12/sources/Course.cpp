#include "Course.h"

namespace planning{

    
    Course::Course()
    {
        setProfessorId(-1);
        setClassroomId(-1);
    }

    /*Course::Course(int code, const char*title,const Timing& timing, int professorId, int classroomId):Event(code, title,timing)
    {
        setProfessorId(professorId);
        setClassroomId(classroomId);
    }*/

    int Course::getProfessorId() const 
    {
        return professorId;
    }

    void Course::setProfessorId(int id) 
    {
        professorId = id;
    }

    int Course::getClassroomId() const 
    {
        return classroomId;
    }

    void Course::setClassroomId(int id) 
    {
        classroomId = id;
    }

    const set<int>& Course::getGroupsIds() const 
    {
        return groupsIds;
    }

    void Course::addGroupId(int id) 
    {
        groupsIds.insert(id);
    }

   bool Course::isGroupIdPresent(int id) const 
    {
        for (const auto& groupId : groupsIds) 
        {
            if (groupId == id)
            {
                return true;
            }
        }
        return false; 
    }


    // Comparaison pour ordre chronologique
    bool Course::operator<(const Course& c)const
    {
        return this->getCode() < c.getCode(); // Compare les timings , bon je mets un peu sur le code
    }

    Course& Course::operator=(const Course& c)
    {
        if (this != &c) // Éviter l'auto-affectation
        {
        
            Event::operator=(c); 

            
            this->professorId = c.professorId;
            this->classroomId = c.classroomId;
            this->groupsIds = c.groupsIds; // Le set<int> gère sa propre copie
        }
        return *this;
    }


    // Opérateur <<
    ostream& operator<<(ostream& s, const Course& course) 
    {
        s << "<Course>" << endl;

        s << "<code>" << endl;
        s << course.getCode() << endl;
        s << "</code>" << endl;

        s << "<title>" << endl;
        s << course.getTitle() << endl;
        s << "</title>" << endl;

        s << "<timing>" << endl;
        s << course.getTiming()<<endl; 
        s << "</timing>" << endl;

        s << "<professorId>" << endl;
        s << course.getProfessorId() << endl;
        s << "</professorId>" << endl;

        s << "<classroomId>" << endl;
        s << course.getClassroomId() << endl;
        s << "</classroomId>" << endl;

        s << "<groupsIds>" << endl;
        for (const auto& groupId : course.getGroupsIds()) 
        {
            s << groupId << " ";
        }
        s << endl;
        s << "</groupsIds>" << endl;

        s << "</Course>";

        return s;
    }


    istream& operator>>(istream& s, Course& course) 
    {
        string tag, sProfessorId, sClassroomId, sGroupIds;
        Timing tmp;

        getline(s, tag); // <course>

        // Lecture du code
        getline(s, tag); // <code>
        getline(s, tag); 
        course.setCode(stoi(tag));
        getline(s, tag); 

        // Lecture du titre
        getline(s, tag); // <title>
        getline(s, tag); 
        course.setTitle(tag.c_str());
        getline(s, tag); 

        // Lecture du Timing
        getline(s, tag); // <timing>
        s >> tmp;        // Désérialisation du Timing via son opérateur >>
        course.setTiming(tmp);
        getline(s, tag); 

        // Lecture de professorId
        getline(s, tag); // <professorId>
        getline(s, sProfessorId);
        course.setProfessorId(stoi(sProfessorId));
        getline(s, tag); 

        // Lecture de classroomId
        getline(s, tag); // <classroomId>
        getline(s, sClassroomId);
        course.setClassroomId(stoi(sClassroomId));
        getline(s, tag); 

        // Lecture de groupsIds
        getline(s, tag); // <groupsIds>
        getline(s, sGroupIds);

        istringstream groupStream(sGroupIds);
        int groupId;
        while (groupStream >> groupId)
        {
            course.addGroupId(groupId);
        }
        getline(s, tag); // </groupsIds>

        getline(s, tag); // </course>
        
        return s;
}

}



