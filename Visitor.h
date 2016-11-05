#ifndef VISITOR_H_INCLUDED
#define VISITOR_H_INCLUDED

#include "Instruction.h"

class Curve;
class Roundabaut;
class Straight;
class Instruction;

class Visitor
{
  public:
    virtual void visit(Curve *c) = 0;
    virtual void visit(Roundabaut *r) = 0;
    virtual void visit(Straight *s) = 0;
};

#endif // VISITOR_H_INCLUDED
