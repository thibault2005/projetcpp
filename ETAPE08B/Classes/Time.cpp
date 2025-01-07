#include "Event.h"
#include <iostream>
#include <string.h>
#include "Time.h"

using namespace std;

namespace planning 
{

Time::Time() 
{
  #ifdef DEBUG
  cout << ">>Time: Constructeur par defaut appelé:<<" << endl;
  #endif

  setHour(0);
  setMinute(0);
}

Time::Time(int h, int m) 
{
  setHour(h);
  setMinute(m);
}

Time::Time(int m)
{
  if(m<0 || m>1440) 
    throw TimeException("HEURE HORS DE L'INTERVALLE 00H-23h59",TimeException::OVERFLOW);
 
  setHour(m / 60);
  setMinute(m % 60);
  
}

Time::Time(const Time &x) 
{
  #ifdef DEBUG
  cout << ">>> Time : appel du constructeur de copie  <<<" << endl;
  #endif
  setHour(x.getHour());
  setMinute(x.getMinute());
}

Time::~Time() 
{
  #ifdef DEBUG
  cout << "Time: appel du destructeur" << endl;
  #endif
}

void Time::setHour(int h)
{
  if (h < 0||h > 23) 
    throw TimeException("Heure invalide !(doit être entre 0 et 23)",TimeException::INVALID_HOUR);
  
  hour = h;
}

void Time::setMinute(int m) 
{
  if (m < 0 || m > 59) 
  {
    throw TimeException("Minutes invalides (doivent être entre 0 et 59)", TimeException::INVALID_MINUTE);
  }
  minute = m;
}

int Time::getHour() const 
{
    return hour;
}

int Time::getMinute() const 
{
    return minute;
}

void Time::display() const 
{
  if (getHour() < 10)
    cout << "0";
  cout << getHour() << "h";

  if (getMinute() < 10)
    cout << "0";
  cout << getMinute();
}

string Time::toString()const
{
  string ret;

  if (getHour() < 10)
    ret="0";

  ret+=to_string(getHour());
  ret+="h";

  if (getMinute() < 10)
    ret+="0";
  
  ret+=to_string(getMinute());

  return ret;
}

Time& Time::operator=(const Time &t) 
{
  setHour(t.getHour());
  setMinute(t.getMinute());

  return (*this);
}

Time Time::operator+(int n) const 
{

  Time result = *this;
  result.minute=result.getMinute() +result.getHour()*60 + n;

  return Time(result.minute);
}


Time operator+(int n, const Time& time) 
{
  return time + n;
}

Time Time::operator+(const Time &t) const 
{
  Time time(*this);

  int total,totalA,totalB;

  totalA=time.hour*60 +time.minute;
  totalB=t.getMinute()+t.getHour()*60;
  total=totalA+totalB;

  return Time(total);
}

Time Time::operator-(int n) const 
{
    Time result = *this;

    int total=result.getMinute()+result.getHour()*60 -n;

    return Time(total);

}

Time operator-(int n, const Time& time) 
{

  int totalMinutes = 60*time.getHour() + time.getMinute();

  int resultMinutes = n-totalMinutes;

  return Time(resultMinutes);

}


Time Time::operator-(const Time &t) const 
{
  Time time(*this);

  int total,totalA,totalB;

  totalA=time.hour*60 +time.minute;
  totalB=t.getMinute()+t.getHour()*60;
  total=totalA-totalB;

  return Time(total);

}

bool Time::operator<(const Time& t) 
{
  return comD(t) == -1;
}

bool Time::operator>(const Time& t) 
{
  return comD(t) == 1;
}

bool Time::operator==(const Time& t)
{
  return comD(t) == 0;
}

int Time::comD(const Time& t) const 
{
    if (getHour() < t.getHour()) return -1;
    if (getHour() > t.getHour()) return 1;

    if (getMinute() < t.getMinute()) return -1;
    if (getMinute() > t.getMinute()) return 1;

    return 0;
}

ostream& operator<<(ostream& s, const Time& h) 
{
  s<< "<Time>" << endl;
  s<< "<hour>" << endl;
  s<< h.getHour() << endl;  
  s<< "</hour>" << endl;
  s<< "<minute>" << endl;
  s<< h.getMinute() << endl;  
  s<< "</minute>" << endl;
  s<< "</Time>";

  return s;
}

istream& operator>>(istream& s, Time& h) 
{
  string sHour,sMinute, tag;

  getline(s,tag);
  getline(s,tag);
  getline(s,sHour);
  getline(s,tag);
  getline(s,tag);
  getline(s,sMinute);
  getline(s,tag);
  getline(s,tag);

  h.setHour(stoi(sHour));
  h.setMinute(stoi(sMinute));

  return s;
}


Time Time::operator++(int b) //post inc
{
  Time temp(*this); 
  *this = *this + 30; 
  return temp; 
}


Time Time::operator++() // pre 
{
  *this = *this + 30;
  return *this;
}


Time Time::operator--(int b) //post dec
{
  Time temp(*this);
  *this = *this - 30;
  return temp;
}


Time Time::operator--() //pré
{
  *this = *this - 30; 
  return *this;
}


}
