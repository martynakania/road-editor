#include "Straightaway.h"
#include<sstream>

#include <stdexcept>


Straight::Straight(int distance_)
{
    if(distance_<=0)
        throw std::invalid_argument( "received negative value" );
    distance=distance_;
}

void Straight::accept(Visitor &visitor)
{
  visitor.visit(this);
}
int Straight::get_distance()
{
    return distance;
}
bool Straight::operator==( Straight& toCompare)
{
    if( this->distance==toCompare.distance )
        return true;
    return false;
}

bool Straight::operator!=( Straight& toCompare)
{
    return !(this->operator==(toCompare));
}

bool Straight::operator==( Instruction* instruction)
{
    Straight *temp=dynamic_cast<Straight*>(instruction);
    if(! temp )
        return false;
    if( *this != *temp )
        return false;
    return true;
}
