#ifndef TIMING_H
#define TIMING_H
#include <string>
using namespace std;
#include "Time.h"
#include "TimingException.h"
#include <iostream>

namespace planning{


class Timing
{

  friend ostream& operator<<(ostream&,const Timing&);
  friend istream& operator>>(istream&,Timing&);

  private:
    string day;
    Time start;
    Time duration;
    int comD(const Timing&)const;

  public:
    Timing();
    Timing(const string,const Time,const Time);
    Timing(const Timing&);
    ~Timing();

    void setDay(const string&);
    void setStart(const Time );
    void setDuration(const Time);

    string getDay() const;
    Time getStart()const;
    Time getDuration()const;

    void display() const;
    string toString()const; 

    int operator<(const Timing&)const;
    int operator>(const Timing&)const;
    int operator==(const Timing&)const;


    static const string MONDAY;
    static const string TUESDAY;
    static const string WEDNESDAY;
    static const string THURSDAY;
    static const string FRIDAY;
    static const string SATURDAY;
    static const string SUNDAY;

    bool intersect(const Timing& t) const ;

};
}
#endif