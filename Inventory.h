//Brief:
/**************************************************************
This header holds the definition of an Inventory class that
will provide the following capabilities:
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

Other notes:
-All members prefixed with "e_" refer to equipment while
    members prefixed with "c_" refer to consumables.

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
        typedef Equipment               E_Item;
        typedef Consumable              C_Item;
        typedef std::list<Equipment>    E_Inv;
        typedef std::list<Consumable>   C_Inv;
        typedef std::string             Name;
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
            //The following return the first item in the inventory
        E_Item get_equipment();
        C_Item get_consumable();
            //The following extract items from the object and require
            //    a name to access it. If no item is found, the function
            //    will return a default constructed Item
        E_Item get_equipment(const Name&);
        C_Item get_consumable(const Name&);
             //The following inserts items into the object
        void add(const E_Item&);
        void add(const C_Item&);
    //Other methods
        void clear();
        void e_clear();
        void c_clear();
    //Constructors and destructor
            //Construct object with a certain size
            //    Parameters reflect the new capacity for Equipment,
            //    and the new capcity for Consumables
        Inventory(size_t, size_t);
            //Construct object with items. This function can take
            //  iterators from any container or array. Whether the
            //  items are Consumables or Equipment shall be
            //  resolved internally.
        template <typename InIter>
            Inventory(size_t, size_t, InIter, InIter)
        ~Inventory();
    protected:
    //Helpers
        template <class Container>
            Item get_item_helper(const Name&, Container&);
    private:
        E_Inv           equipment;
        C_Inv           consumables;
        const size_t    e_max, c_max;
};

void swap_contents(Inventory&, Inventory&);
    //Replace contents of right parameter with left parameter's
void replace_contents(Inventory, Inventory&);
    //Add from left parameter to right parameter
void copy_contents(Inventory, Inventory&);

#include "Inventory.inl"

#endif
