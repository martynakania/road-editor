#ifndef WRITINGVISITOR_H_INCLUDED
#define WRITINGVISITOR_H_INCLUDED
#include <fstream>
#include "Visitor.h"
#include "Roundabaut.h"
#include "Straightaway.h"
#include "Curve.h"

class WritingVisitor: public Visitor
{
    std::string fileName;
public:
    WritingVisitor(std::string name="example.txt"):fileName(name)
            {};
    void visit(Curve *c);
    void visit(Roundabaut *r);
    void visit(Straight *s) ;
};

 enum WhichInstruction :char
{
    curve='c',
    roundabaut='r',
    straight='s'
};
#endif // WRITINGVISITOR_H_INCLUDED
