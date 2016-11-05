#ifndef STRAIGHTAWAY_H_INCLUDED
#define STRAIGHTAWAY_H_INCLUDED
#include "Visitor.h"

class Straight: public Instruction
{
    int distance;

    public:
        Straight()
                {};
        Straight( int distance);

        void accept(Visitor &v);
        int get_distance();


        bool operator==( Straight& toCompare);
        bool operator!=( Straight& toCompare);
        bool operator==(Instruction*);

        ~Straight()
                {};


};

#endif // STRAIGHTAWAY_H_INCLUDED
