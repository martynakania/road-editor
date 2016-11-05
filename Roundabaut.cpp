#include "Roundabaut.h"
#include <sstream>
#include <stdexcept>


Roundabaut::Roundabaut(int number)
{
    if(number<1||number>30)
        throw std::invalid_argument( "received wrong value" );
    exit=number;
}
void Roundabaut::accept(Visitor &visitor)
{
  visitor.visit(this);
}
int Roundabaut::get_exit()
{
    return exit;
}

bool Roundabaut::operator==( Roundabaut& toCompare)
{
    if( this->exit==toCompare.exit)
        return true;
    return false;
}

bool Roundabaut::operator!=( Roundabaut& toCompare)
{
    return !(this->operator==(toCompare));
}

bool Roundabaut::operator==( Instruction* instruction)
{
    Roundabaut *temp=dynamic_cast<Roundabaut*>(instruction);
    if(! temp )
        return false;
    if( *this != *temp )
        return false;
    return true;
}
