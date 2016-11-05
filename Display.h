#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include "Visitor.h"
#include "Roundabaut.h"
#include "Straightaway.h"
#include "Curve.h"

class Display: public Visitor
{
    void visit(Curve *c);
    void visit(Roundabaut *r);
    void visit(Straight *s) ;
};

#endif // DISPLAY_H_INCLUDED
