#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

#include "Timing.h"


namespace planning{


Timing::Timing()
{
  #ifdef DEBUG
  cout<< ">>Timing: Constructeur par defaut appelé:<<" <<endl;
  #endif
  setDay("leJourEstNonDefini");
  setStart(0);
  setDuration(0);

}

Timing::Timing(const string d,const Time s,const Time Du)
{
  #ifdef DEBUG
  cout<< ">>Timing: Constructeur d'initialisation appelé:<<" <<endl;
  #endif
  setDay(d);
  setStart(s);
  setDuration(Du);
}

Timing::Timing(const Timing &a)
{
  setDay(a.getDay());
  setStart(a.getStart());
  setDuration(a.getDuration());
}

Timing::~Timing()
{
  #ifdef DEBUG
  cout<<"Timing: appel du destructeur"<<endl;
  #endif
}

void Timing::setDay(const string& myDay) 
{
  static const string tableDay[14] = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche",
  "LUNDI","MARDI","MERCREDI","JEUDI","VENDREDI","SAMEDI","DIMANCHE"};

  if (myDay == "leJourEstNonDefini") 
  {
    day = myDay;
    return;
  }

  

  for (int i = 0; i < 14; i++) 
  {
    if (myDay == tableDay[i]) 
    {
      day = myDay; 
      return;
    }
  }

  throw TimingException("JOUR INVALIDE !!", TimingException::INVALID_DAY);
}

void Timing::setStart(const Time s)
{
  start.setHour(s.getHour());
  start.setMinute(s.getMinute());
}
void Timing::setDuration(const Time D)
{
  duration.setHour(D.getHour());
  duration.setMinute(D.getMinute());
}

std::string Timing::getDay()const
{
  return day;
}
Time Timing::getStart()const
{
  return start;
}
Time Timing::getDuration()const
{
  return duration;
}

void Timing::display() const
{
  cout<<endl;
  cout<<"jour = "<<day<<endl;
  cout<<"heure de debut = ";
  start.display();
  cout<<endl;
  cout<<"duree totale = ";
  duration.display();
  cout<<endl; 
}

string Timing::toString() const
{
  string ret;

  ret="jour = ";
  ret+= day;
  ret+=" heure de debut = ";
  ret+=start.toString();
  ret+=" duree totale = ";
  ret+=duration.toString();

  return ret;
}



int Timing::operator<(const Timing& t)const
{
 return comD(t)==-1;
}
int Timing::operator>(const Timing& t)const
{
  return comD(t)==1;
}
int Timing::operator==(const Timing& t)const
{
  return comD(t) == 0;
}
int Timing::comD(const Timing& t)const
{
  if(day<t.day) return -1;
  if(day>t.day) return 1;

  if(start<t.start) return -1;
  if(start>t.start) return 1;

  if(duration<t.duration) return -1;
  if(duration>t.duration) return 1;


  return 0;
}

ostream& operator<<(ostream& s, const Timing& yourTiming)
{
  s<<"<Timing>"<<endl;

  s<<"<day>"<<endl;
  s<<yourTiming.getDay()<<endl;
  s<<"</day>"<<endl;

  s<<"<start>"<< endl;
  s<< yourTiming.getStart()<<endl;
  s<<"</start>"<<endl;

  s<<"<duration>"<< endl;
  s<< yourTiming.getDuration()<<endl;
  s<<"</duration>"<<endl;

  s<<"</Timing>";

  return s;
}

istream& operator>>(istream& s, Timing& yourTiming) 
{
  string sDay,tag;

  getline(s,tag);

  getline(s,tag);
  getline(s,sDay);
  getline(s,tag);

  getline(s,tag);
  s>>yourTiming.start;
  getline(s,tag);

  getline(s,tag);
  s>>yourTiming.duration;
  getline(s,tag);

  getline(s,tag);

  yourTiming.setDay(sDay);

  return s;
}

const string Timing::MONDAY = "Lundi";
const string Timing::TUESDAY = "Mardi";
const string Timing::WEDNESDAY = "Mercredi";
const string Timing::THURSDAY = "Jeudi";
const string Timing::FRIDAY = "Vendredi";
const string Timing::SATURDAY = "Samedi";
const string Timing::SUNDAY = "Dimanche";

bool Timing::intersect(const Timing& t) const 
{
    if (day != t.day) 
        return false;

    // Calcul des plages horaires
    Time finPremierHoraire = getStart() + getDuration();         // Heure de fin du timing actuel
    Time finDeuxiemeHoraire = t.getStart() + t.getDuration();    // Heure de fin de l'autre timing

    // Vérifie s'il y a un chevauchement temporel
    if(finPremierHoraire<t.getStart() || finPremierHoraire==t.getStart())
      return false;

    if(finDeuxiemeHoraire<getStart() || finDeuxiemeHoraire==getStart())
      return false;

    return true;
}

}
