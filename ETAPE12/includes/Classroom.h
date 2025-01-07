#ifndef CLASSROOM_H 
#define CLASSROOM_H 

#include <string>
#include <iostream>
#include "Schedulable.h"
using namespace std;

namespace planning 
{

    class Classroom : public Schedulable 
    {
        friend ostream& operator<<(ostream&,const Classroom&);
        friend istream& operator>>(istream&,Classroom&);

        private:
            int seatingCapacity;
            string name;

        public:
            Classroom();
            Classroom(int,const string&,int);
            
            Classroom(const Classroom &);
            ~Classroom() = default;

            void setSeatingCapacity(int);
            void setName(const string&);
            
            
            int getSeatingCapacity() const; 
            string getName() const;
            

            string toString()const override;
            string tuple()const override;

            Classroom& operator=(const Classroom&);

            bool operator<(const Classroom& ) const ;
    

    };

}
#endif