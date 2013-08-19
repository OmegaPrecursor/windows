#include "Inventory.h"

//Notes since the "items" design is incomplete:
/******************************************************************
-All functions will treat "items" as objects of type
    Equipment or Consumable, which are in addition treated
    as derivations from an Item class.
-Some functions will call a Item::name() read-only function.
-Due to the design of a couple functions, those functions will
    call the default constructor Item::Item().
******************************************************************/

#include <algorithm>

//Read-only
  //The total number of items the object can hold
size_t Inventory::size() const
    {return e_max + c_max;}
  //The total amount of equipment the object can hold
size_t Inventory::e_size() const
    {return e_max;}
  //The total number of consumable items the object can hold
size_t Inventory::c_size() const
    {return c_max;}
  //The total number of items currently in the object
size_t Inventory::count() const
    {return equipment.size() + consumables.size();}
  //The total amount quipment currently in the object
size_t Inventory::e_count() const
    {return equipment.size();}
  //The total number of consumable items currently in the object
size_t Inventory::c_count() const
    {return consumables.size();}

//Getters and setters (-ish)
Inventory::E_Item Inventory::get_equipment()
    {return get_item_helper(equipment.front().name(), equipment);}
Inventory::C_Item Inventory::get_consumable()
    {return get_item_helper(equipment.front().name(), consumables);}
  //The following extract items from the object and require
  //    a name to access it. If no item is found, the function
  //    will return a default constructed Item
Inventory::E_Item Inventory::get_equipment(const Name& key)
    {return get_item_helper(key, equipment);}
Inventory::C_Item Inventory::get_consumable(const Name& key)
    {return get_item_helper(key, consumables);}
   //The following inserts items into the object
void Inventory::add(const E_Item& newitem){
    if(equipment.size() < e_max)
        equipment.push_back(newitem);
}
void Inventory::add(const C_Item& newitem){
    if(consumables.size() < e_max)
        consumables.push_back(newitem);
}

//Other methods
void Inventory::clear()
    {this->e_clear(); this->c_clear();}
void Inventory::e_clear()
    {equipment.clear();}
void Inventory::c_clear()
    {consumables.clear();}

//Constructors and destructor
  //Construct object with a certain size
Inventory::Inventory(size_t newesize, size_t newcsize)
    : equipment({})
    , consumables({})
    , e_max(newesize)
    , c_max(newcsize)
{}
Inventory::~Inventory(){}

    //No move semantics since this is C++03
void swap_contents(Inventory& f, Inventory& s){
    Inventory hold(f);
    f.clear();
    while(s.e_count() > 0) f.add(s.get_equipment());
    while(s.c_count() > 0) f.add(s.get_consumable());
    s.clear();
    while(hold.e_count() > 0) s.add(hold.get_equipment());
    while(hold.c_count() > 0) s.add(hold.get_consumable());
}
    //Replace contents of right parameter with left parameter
void replace_contents(Inventory f, Inventory& s){
    s.clear();
    while(f.e_count > 0) s.add(f.get_equipment());
    while(f.c_count > 0) s.add(f.get_consumable());
}
    //Add from left parameter to the right parameter
void copy_contents(Inventory f, Inventory& s){
    while(f.e_count > 0) s.add(f.get_equipment());
    while(f.c_count > 0) s.add(f.get_consumable());
}
