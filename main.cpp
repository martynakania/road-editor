
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include "UserInterface.h"
#include <vector>

using namespace std;


int main()
{
    Road road;
    int what;
    while(true)
    {
    std::string text="\n 1.Wyswietl wskazowki\n 2.Dodaj wskazowke\n 3.Usun wskazowke\n 4.Edytuj wskazowke\n 5.Sprawdz ile jest wskazowek\n 6.Sprawdz czy po drodze jest rondo\n 7.Zapisz do pliku\n 8.Odczytaj z pliku\n 9.Wyjdz\n";
        std::cout<<text;
        what=cin_int_between(1,9,text);
        switch(what)
        {
        case(1):
            interface_get_amount_of_instructions(road);
            road.display_all_instruction();
            break;
        case(2):
            interface_add_instruction(road);
            break;
        case(3):
            interface_delete_instruction(road);
            break;
        case(4):
            interface_edit_instruction(road);
            break;
        case(5):
            interface_get_amount_of_instructions(road);
            break;
        case(6):
            interface_is_there_roundabaut(road);
            break;
        case (7):
            interface_save_to_the_file(road);
            break;
        case (8):
            interface_load_from_the_file(road);
            break;
        case (9):
            return 0;
        }
    }
}
