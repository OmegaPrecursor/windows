//Notes since the "items" design is incomplete:
/******************************************************************
-All functions will treat "items" as objects of type
    Equipment or Consumable, which are in addition treated
    as derivations from an Item class.
-Some functions will call a Item::name() read-only function.
-Due to the design of a couple functions, those functions will
    call the default constructor Item::Item().
******************************************************************/

  //Construct object with items (Parameter packs only in C++11)
//template<E_Item... E_pack>
//Inventory::Inventory(size_t, size_t, E_pack...);
//template<C_Item... C_pack>
//Inventory::Inventory(size_t, size_t, C_pack...);

template <class Container>
    Item Inventory::get_item_helper(const Name& key, Container& container)
{
    struct Name_Matcher{
        Name_Matcher(const Name& newname) : test(key) {};
        bool operator() (const Item& testee)
            {return testee.name() == test;};
        Name test;
    } nm_functor(key);
    auto iter(std::find_if(
        container.begin(), container.end(),
        nm_functor
    ));
    if(iter == container.end()) return Item();
    auto toreturn(*iter);
    container.erase(iter);
    return toreturn;
}
