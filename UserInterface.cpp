#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Road.h"
using namespace std;
int cin_int(std:: string what="")
{
    int myNumber = 0;
    std::string input="";

    while (true)
    {
        getline(std::cin, input);
        stringstream myStream(input);
        if (myStream >> myNumber)
            break;
        std::cout << "Podany ciag znakow nie jest liczba lub jest za dlugi. Sprobuj ponownie\n"<< what<<std::endl;
    }
    return myNumber;
}

int cin_int_between(int smaller, int bigger, string what="")
{
    while (true)
    {
        int cinInt=cin_int(what);
        if( smaller<=cinInt && cinInt<=bigger)
            return cinInt;
       std:: cout << "Nieprawidlowa liczba. Sprobuj ponownie. Podaj liczbe z zakresu: <"<<smaller<<" , "<<bigger <<">"<< std::endl<<what<<std::endl;
    }
}

int cin_int_bigger_than(int number,std:: string what="")
{
    while (true)
    {
        int cinInt=cin_int(what);
        if(number<cinInt)
            return cinInt;
        std::cout << "Podany liczba jest za mala. Podaj wieksza niz"<<number<<std::endl<<what;
    }
}

std::string cin_string(string what="")
{
    std::string input = "";
    std::cin>>input;
    std::cin.clear();
    std::cin.sync();
    return input;
}

Roundabaut interface_create_roundabaut()
{
    int number;
    std::cout<<"Podaj numer zjazdu"<<std::endl;
    number=cin_int_between(1,30);
    return Roundabaut(number);
}
Straight interface_create_straight()
{
    int distance;
    std::cout<<"Podaj ile metrow bedziesz jechac prosto"<<endl;;
    distance=cin_int_bigger_than(0);
    return Straight(distance);
}
Curve interface_create_curve()
{
    int what;
        std::string text="wybierz:\n 1)skret w lewo 2)skret w prawo\n";
        std::cout<<text<<std::endl;
        what=cin_int_between(1,2,text);
        if(what==1)
            return Curve(Direction::left);
        else if(what=2)
            return Curve(Direction::right);
}
Instruction* interface_create_instruction(){
    int what;
    std::string text="wybierz nowa instrukcje:\n 1)rondo 2)droga prosta 3)zakret\n";
    std::cout<<text<<std::endl;
    what=cin_int_between(1,3,text);
    if(what==1)
    {
        Roundabaut *r= new Roundabaut(interface_create_roundabaut());
        return r;
    }
    else if(what==2)
    {
        Straight *s= new Straight(interface_create_straight());
        return s;
    }
    else if(what==3)
    {
        Curve *c= new Curve(interface_create_curve());
        return c;
    }
}

void interface_add_instruction(Road& road)
{
    road.add_instruction(interface_create_instruction());
}

void interface_get_amount_of_instructions(const Road &road)
{
    std::cout<<"Lista liczy "<<road.get_amount_of_instructions()<<" wskazowek"<<endl;
}

void interface_delete_instruction(Road &road)
{
    if(road.is_empty())
    {
        std::cout<<"Lista jest pusta"<<endl;
        return;
    }
    int index;
    std::cout<<"Podaj numer instrukcji, ktora chcesz usunac"<<endl;
    index=cin_int_between(0,road.get_amount_of_instructions()-1);
    road.delete_instruction(index);
}

void interface_edit_instruction(Road &road)
{
    if(road.is_empty())
    {
       std::cout<<"Lista jest pusta"<<endl;
        return;
    }
    int index;
    std::cout<<"Podaj numer instrukcji, ktora chcesz edytowac"<<endl;;
    index=cin_int_between(0,road.get_amount_of_instructions()-1);
    road.edit_instruction(index,interface_create_instruction());
}

void interface_is_there_roundabaut(const Road &road)
{
    if(road.is_there_a_roundabaut())
        std::cout<<"Na trasie jest rondo"<<endl;
    else
        std::cout<<"Po drodze nie ma ronda"<<endl;
}

void interface_save_to_the_file(const Road &road)
{
    std::cout<<"Podaj nazwe pliku, do ktorego chcesz zapisac liste wskazowek"<<endl;
    std::string fileName=cin_string();
    try
    {
    road.save_to_the_file(fileName);
    }
    catch (const std::runtime_error &error)
    {
     std::cout<<"Nie udalo sie utworzyc  pliku o podanej nazwie"<<endl;
    }
}

void interface_load_from_the_file(Road &road)
{
    std::cout<<"Podaj nazwe pliku,z ktorego chcesz odczytac liste wskazowek"<<endl;
    std::string fileName=cin_string();
    try{
    road.load_from_the_file(fileName);
    }
    catch (std::runtime_error)
    {
     std::cout<<"Nie udalo sie otworzyc podanego pliku"<<endl;
    }
}
            //
