#include "Event.h"
namespace planning{



Event::Event()
{
  #ifdef DEBUG
  cout<< ">>Event: Constructeur par defaut appelé:<<" <<endl;
  #endif
  setCode(0);
  title = nullptr;
  timing=nullptr;
  setTitle("---");

}


Event::Event(int c,const char* t)
{
  #ifdef DEBUG
  cout << ">>> Event : appel au constructeur d'initialisation <<<" << endl;
  #endif
  setCode(c);
  title=nullptr;
  setTitle(t);
  timing=nullptr;
  
}

Event::Event(const Event& e)
{
  #ifdef DEBUG
  cout << ">>> Event : appel du constructeur de copie <<<" << endl;
  #endif
  setCode(e.getCode());
  title= nullptr;
  setTitle(e.getTitle());
  timing=nullptr;
  setTiming(e.getTiming());
}


Event::~Event() {
  #ifdef DEBUG
  cout << "Event: Appel du destructeur" << endl;
  #endif
  if (title) 
  {
    delete[] title;
    title = nullptr;
  }
  if (timing) 
  {
    delete timing;
    timing = nullptr;
  }
}



void Event::setCode(int c)
{
  if(c<1) return;
  code=c;
}


void Event::setTitle(const char* t)
{
  if(t==nullptr) return;
  if(title) delete title;
  title = new char[strlen(t)+1];
  strcpy(title,t);
}

void Event::setTiming(const Timing& ptiming)
{
  if (timing) delete timing;
  timing = new Timing(ptiming);
}

int Event::getCode() const
{
  return code;
}


const char* Event::getTitle() const
{
  return title;
}


const Timing Event::getTiming() const
{
  if(timing==nullptr)
    throw TimingException("EVENEMENT NON PLANIFIE !!", TimingException::NO_TIMING);
  return *timing;
}

void Event::display()const
{
  cout << "Event : code = " <<code<< " et Title = "<< title << endl;
  if (timing != nullptr)
    {
      cout << "Timing : ";
      timing->display(); 
    } 
  else 
    {
      cout << "Timing : non defini" << endl;
    }
}

int Event::currentCode=1;

string Event::toString()const 
{
  string ret;
  ret= "Event : code =";
  ret += to_string(getCode());
  ret+=" et Titre =";
  ret+=title;

  if (timing != nullptr)
  {
    ret+=" Timing : ";
    ret += timing->toString(); 
  } 
  else 
  {
    ret+=" Timing : non defini";
  }

  return ret;
}


ostream& operator<<(ostream& s, const Event& yourEvent)
{
  s<<"<Event>"<<endl;

  s<<"<code>"<<endl;
  s<<yourEvent.getCode()<<endl;
  s<<"</code>"<<endl;

  s<<"<title>"<< endl;
  s<< yourEvent.getTitle()<<endl;
  s<<"</title>"<<endl;

  
  if (yourEvent.timing != nullptr) 
  {
    s << "<timing>" << endl;
    s <<*(yourEvent.timing)<<endl; 
    s<<"</timing>"<< endl;
  } 
  
  s<<"</Event>";

  return s;
}

istream& operator>>(istream& s, Event& yourEvent) 
{
  string tag;
  Timing tempTiming;

  getline(s,tag);


  getline(s,tag);
  getline(s,tag);
  yourEvent.setCode(stoi(tag));
  getline(s,tag);

  getline(s,tag);
  getline(s,tag);
  yourEvent.setTitle(tag.c_str());
  getline(s,tag);

  
  getline(s,tag); 
  if (tag =="<timing>") 
  {
    s>>tempTiming;
    yourEvent.setTiming(tempTiming);
    getline(s, tag);
    getline(s, tag);
    return s;
  }
  else
  {
    return s;
  }
  

  
}

}


