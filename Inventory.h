//Brief:
/**************************************************************
This header holds the definition of an Inventory class that
will provide the following elements:
-The ability to store "Equipment" items
-The ability to store "Consumable" items
-The ability to swap contents between two inventory objects
-The ability to copy over contents between two inventory
   objects (mainly for when inventory objects are switched)
-In addition, how many items the inventory can store is
   fixed per object instance. Therefore, if contents are switched
   or copied over to a smaller inventory, items may be lost.

This class will also have the following requirements:
-The Inventory may only store objects of type Equipment and
   Consumable

This definition is subject to change until the design of the
"items" is finalized.
**************************************************************/
#ifndef INVENTORY_H
#define INVENTORY_H

#include <cstddef>
#include <list>
#include <string>

class Inventory{
    public:
  //Type aliases
        typedef std::list<Equipment>  E_Inv;
        typedef std::list<Consumable> C_Inv;
        typedef std::string           Name;
  //Read-only
      //The total number of items the object can hold
        size_t size() const;
      //The total amount of equipment the object can hold
        size_t e_size() const;
      //The total number of consumable items the object can hold
        size_t c_size() const;
      //The total number of items currently in the object
        size_t count() const;
      //The total amount quipment currently in the object
        size_t e_count() const;
      //The total number of consumable items currently in the object
        size_t c_count() const;
  //Getters and setters (-ish)
      //The following extract items from the object and require
      //    a name to access it. If no item is found, the function
      //    will return a default constructed Item
        Equipment get_equipment(const Name&);
        Consumable get_consumable(const Name&);
      //The following inserts items into the object
        void add(const Equipment&);
        void add(const Consumable&);
  //Constructors and destructor
      //Construct object with a certain size
        Inventory(size_t, size_t);
      //Construct object with items
        //template<Equipment... E_pack>
        //Inventory(size_t, size_t, E_pack...);
        //template<Consumable... C_pack>
        //Inventory(size_t, size_t, C_pack...);
        ~Inventory();
  //Friends
         void swap(Inventory&, Inventory&);
         void move(const Inventory&, Inventory&);
    private:
        E_Inv   equipment;
        C_Inv   consumables;
        size_t  e_size, c_size;
};

   void swap(Inventory&, Inventory&);
//Move from left parameter to right parameter
   void move(const Inventory&, Inventory&);

#endif
