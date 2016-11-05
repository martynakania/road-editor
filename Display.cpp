#include "Display.h"
#include <sstream>


void Display:: visit(Curve *c)
{
    if(c->get_direction()==Direction::left)
        std::cout<<"skrec w lewo"<<std::endl;
    else
        std::cout<<"skrec w prawo"<<std::endl;
}

void Display:: visit(Roundabaut *r)
{
    std::cout<<"zjedz z ronda "<<r->get_exit()<<" zjazdem"<<std::endl;
}

void Display:: visit(Straight *s)
{
    std::cout<<"jedz prosto "<<s->get_distance()<<" metrow"<<std::endl;
}
