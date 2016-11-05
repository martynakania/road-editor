#include "Curve.h"

//namespace Projekt;
/*
Curve::Curve(Direction direct)
       // :direction(direct)
            {this->direction=direct;};
*/
void Curve::accept(Visitor &visitor)
{
    visitor.visit(this);
}
Direction Curve::get_direction()
{
    return direction;
}
bool Curve::operator==( Curve& toCompare)
{
    if( this->direction==toCompare.direction )
        return true;
    return false;
}

bool Curve::operator!=( Curve& toCompare)
{
    return !(this->operator==(toCompare));
}

bool Curve::operator==( Instruction* instruction)
{
    Curve *temp=dynamic_cast<Curve*>(instruction);
    if(! temp )
        return false;
    if( *this != *temp )
        return false;
    return true;
}

