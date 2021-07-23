#include "GildedRose.h"

GildedRose::GildedRose(vector<itemPtr> & items) : items(items) 
{
}

GildedRose::GildedRose(vector<Item>& _items)
{
}

void GildedRose::updateQuality() 
{
    for (auto item : items)
        item->update();
}