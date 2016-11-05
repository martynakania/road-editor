#include "WritingVisitor.h"


void WritingVisitor:: visit(Curve *c)
{
    WhichInstruction temp = curve;
    Direction direction=c->get_direction();
    std::fstream file;
    file.open (this->fileName, std::fstream::binary | std::fstream::app | std::fstream::out );
    file.write(reinterpret_cast<char *>(&temp), sizeof(WhichInstruction));
    file.write(reinterpret_cast<char *>(&direction), sizeof(Direction));
    file.close();
}

void WritingVisitor:: visit(Roundabaut *r)
{
    WhichInstruction temp =  roundabaut;
    int exit=r->get_exit();
    std::fstream file;
    file.open (this->fileName, std::fstream::binary | std::fstream::app | std::fstream::out );
    file.write(reinterpret_cast<char *>(&temp), sizeof(WhichInstruction));
    file.write(reinterpret_cast<char *>(&exit), sizeof(int));
    file.close();
}

void WritingVisitor:: visit(Straight *s)
{
    WhichInstruction temp = straight;
    int distance=s->get_distance();
    std::fstream file;
    file.open (this->fileName, std::fstream::binary | std::fstream::app | std::fstream::out );
    file.write(reinterpret_cast<char *>(&temp), sizeof(WhichInstruction));
    file.write(reinterpret_cast<char *>(&distance), sizeof(int));
    file.close();
}

