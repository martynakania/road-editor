
#include "Road.h"
#include <stdexcept>
Road::Road()
{}

Road::Road(const std::vector<Instruction*>& vect)
{
    this->vector=vect;
}

void Road::add_instruction( Instruction* instruction)
{
    vector.push_back(instruction);
}

void Road::delete_instruction(int index)
{
    Instruction *in=vector[index];
    vector.erase(vector.begin()+index);
    delete in;
}
void Road::delete_last_instruction()
{
    Instruction *in=vector[vector.size()-1];
    vector.pop_back();
    delete in;
}
void Road::edit_instruction(int index, Instruction* newInstruction)
{
    Instruction* temp;
    if(vector[index]==newInstruction)
        return;
    temp=vector[index];
    vector[index]=newInstruction;
    delete temp;
}

Instruction* Road::get_instruction(int index) const
{
    return(vector[index]);
}

bool Road::is_there_a_roundabaut() const
{
    for(int i=0; i<vector.size(); i++)
    {
        if(dynamic_cast<Roundabaut*>(vector[i]))
            return true;
    }
    return false;
}

void Road::display_all_instruction() const
{
    Display visitor;
    for(int i=0; i<vector.size(); i++)
    {
        std::cout<<i<<". ";
        vector[i]->accept(visitor);
    }
}

int Road::get_amount_of_instructions() const
{
    return this->vector.size();
}
bool Road::is_empty() const
{
    return vector.empty();
}
bool Road::operator==(const Road& compareTo) const
{
    if( ! this->get_amount_of_instructions()==compareTo.get_amount_of_instructions() )
        return false;
    for(int i=0; i<vector.size(); i++)
        if(! (*(this->vector[i]) == (compareTo.vector[i]) ) )
           {
            return false;
           }
    return true;
}

void Road::save_to_the_file(std::string fileName) const
{
    std::fstream file;
    file.open (fileName, std::fstream::binary | std::fstream::out | std::fstream::trunc);
    file.close();
    WritingVisitor visitor(fileName);
    for(int i=0; i<vector.size(); i++)
    {
        vector[i]->accept(visitor);
    }
}
void Road::load_curve(std::fstream &file)
{
        Direction direction;
        file.read(reinterpret_cast<char *>(&direction), sizeof(Direction));
        Curve* c= new Curve(direction);
        this->add_instruction(c);
}
void Road::load_straight(std::fstream &file)
{
        int distance;
        file.read(reinterpret_cast<char *>(&distance), sizeof(int));
        Straight* s= new Straight(distance);
        this->add_instruction(s);
}
void Road::load_roundabaut(std::fstream &file)
{
        int exit;
        file.read(reinterpret_cast<char *>(&exit), sizeof(int));
        Roundabaut* r= new Roundabaut(exit);
        this->add_instruction(r);
}
void Road::clearVector()
{
    for(int i=0; i<vector.size(); i++)
            delete vector[i];
    vector.clear();
}
void Road::load_from_the_file(std::string fileName)
{
    Display d;
    std::fstream file;
    file.open(fileName, std::fstream::binary | std::fstream::in);
    if(!file)
        throw std::runtime_error( "can not open the file" );
    clearVector();
    WhichInstruction which ;
    while (!file.eof() )
    {
        file.read((char *)(&which), sizeof(WhichInstruction));//file.read
        if(which==WhichInstruction::curve)
        {
            load_curve(file);
        }
        else if(which==WhichInstruction::roundabaut)
        {
            load_roundabaut(file);
        }
        else if(which==WhichInstruction::straight)
        {
            load_straight(file);
        }
        else break;
    }
    file.close();
    if(vector.size()>1)
    delete_last_instruction();
}
