#ifndef TIME_H
#define TIME_H

#include <iostream>
#include "TimeException.h"

using namespace std;
namespace planning
{

class Time
{
  friend Time operator+(int,const Time&);
  friend Time operator-(int,const Time&);

  friend ostream& operator<<(ostream&,const Time&);
  friend istream& operator>>(istream&,Time&);

  private:
    int hour;
    int minute;
    int comD(const Time&)const;

  public:
    Time();
    Time(int,int);
    Time(int);
    Time(const Time&);
    ~Time();

    
    void setHour(int);
    void setMinute(int);
    
    int getHour() const;
    int getMinute() const;

    void display() const;
    string toString()const;

    Time& operator=(const Time&);
    Time operator+(const Time&)const;

    Time operator-(const Time&)const;

    Time operator+(int)const;
    Time operator-(int)const;

    bool operator<(const Time&)const;
    bool operator>(const Time&)const;
    bool operator==(const Time&)const;

    Time operator++(int);
    Time operator++();
    Time operator--(int);
    Time operator--();







};
}
#endif