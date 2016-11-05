#ifndef USERINTERFACE_H_INCLUDED
#define USERINTERFACE_H_INCLUDED
#include "Road.h"

int cin_int(std::string what="");
int cin_int_between(int smaller, int bigger,std::string what="");
int cin_int_bigger_than(int number, std::string what="");

Roundabaut interface_create_roundabaut();
Straight interface_create_straight();
Curve interface_create_curve();
void interface_add_instruction(Road& road);
void interface_delete_instruction(Road& road);
void interface_get_amount_of_instructions(const Road &road);
void interface_edit_instruction(Road& road);
void interface_is_there_roundabaut(const Road& road);
void interface_save_to_the_file(const Road &road);
void interface_load_from_the_file(Road &road);


#endif // USERINTERFACE_H_INCLUDED
