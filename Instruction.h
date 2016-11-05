#ifndef DIRECTION_H_INCLUDED
#define DIRECTION_H_INCLUDED

#include <iostream>
#include <string>
class Visitor;
//using namespace std;
class Instruction
{
  public:

    virtual void accept(Visitor &v) = 0;
    virtual bool operator==(Instruction*)=0;
    virtual ~Instruction() {};
};

#endif // DIRECTION_H_INCLUDED
