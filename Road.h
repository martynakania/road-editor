#ifndef ROAD_H_INCLUDED
#define ROAD_H_INCLUDED

#include "Display.h"
#include "WritingVisitor.h"
#include <vector>
class Road
{
    std::vector<Instruction*> vector;
    void load_curve(std::fstream &file);
    void load_straight(std::fstream &file);
    void load_roundabaut(std::fstream &file);
    public:

        Road();
        Road(const std::vector<Instruction*>&);
        void add_instruction(Instruction*);
        void delete_instruction(int);
        void delete_last_instruction();
        void delete_all_instruction(int);
        void edit_instruction(int, Instruction*);
        Instruction* get_instruction(int) const;
        bool is_there_a_roundabaut() const;
        int get_amount_of_instructions() const;
        bool is_empty() const;
        bool operator==(const Road& compareTo) const;
        void display_all_instruction() const;
        void save_to_the_file(std::string) const;
        void load_from_the_file(std::string);
        void clearVector();


    ~Road()
    {
        for(int i=0; i<vector.size(); i++)
            delete vector[i];
    }
};


#endif // ROAD_H_INCLUDED
