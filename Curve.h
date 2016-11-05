#ifndef CURVE_H_INCLUDED
#define CURVE_H_INCLUDED
#include "Visitor.h"

 enum Direction: char
{
    left,
    right
};

class Curve: public Instruction
{
    Direction direction=Direction::left;


    public:
    Curve()
        {};
    Curve(Direction direction_)
    {
        direction=direction_;
    };
    void accept(Visitor &v);
    std::string what(void);
    Direction get_direction();

    bool operator==( Curve& toCompare);
    bool operator!=( Curve& toCompare);
    bool operator==(Instruction*);
    ~Curve() {};

};

#endif // CURVE_H_INCLUDED
