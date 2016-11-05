#ifndef ROUNDABAUT_H_INCLUDED
#define ROUNDABAUT_H_INCLUDED
#include "Visitor.h"


class Roundabaut: public Instruction
{
    int exit;

    public:
        void accept(Visitor &v);
        Roundabaut()
            {};
        Roundabaut( int number);
        int get_exit();
        bool operator==(Instruction*);

        bool operator==( Roundabaut& toCompare);
        bool operator!=( Roundabaut& toCompare);
        ~Roundabaut()
            {};
};


#endif // ROUNDABAUT_H_INCLUDED
