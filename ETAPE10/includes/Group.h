#ifndef GROUP_H 
#define GROUP_H 

#include <string>
#include "Schedulable.h"
using namespace std;

namespace planning 
{

    class Group : public Schedulable 
    {
        friend ostream& operator<<(ostream&, const Group&);
        friend istream& operator>>(istream&, Group&);

        private:
            string name;

        public:
            Group();
            Group(int, const string&);
            
            Group(const Group &);
            ~Group() = default;

            void setName(const string&);
            
            string getName() const;

            string toString()const override;
            string tuple()const override;

            Group& operator=(const Group&);

            bool operator<(const Group& ) const ;
    };

}
#endif
