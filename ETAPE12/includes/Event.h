#ifndef EVENT_H
#define EVENT_H
#include "Timing.h"
#include<iostream>
#include<string.h>
using namespace std;

namespace planning
{

class Event
{

friend ostream& operator<<(ostream&,const Event&);
friend istream& operator>>(istream&,Event&);

protected:
  int code;
  char *title;
  Timing *timing;

public:
  Event();
  Event(int,const char*);
  Event(const Event&);
  ~Event();



  void setCode(int);
  void setTitle(const char*);
  void setTiming(const Timing&);

  int getCode() const;
  static int getCurrentCode();

  const Timing getTiming() const;
  const char* getTitle() const;

  void display() const;
  string toString()const;

  static int currentCode;
};

}
#endif