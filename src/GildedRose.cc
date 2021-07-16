#include "GildedRose.h"

GildedRose::GildedRose(vector<itemPtr> & items) : items(items) 
{
}

GildedRose::GildedRose(vector<Item>& _items)
{
}

void GildedRose::updateQuality() 
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i]->name == _brieName)
        {
            items[i]->increaseQuality();            
        }
        else if (items[i]->name == _sulfurName)
        {            
        }
        else if (items[i]->name == _backName)
        {
            items[i]->increaseQuality();
            handleBackStage(*items[i]);            
        }
        else
        {
            items[i]->decreaseQuality();
        }   

        decreaseSellIn(*items[i]);
        
        if (items[i]->sellIn < 0)
        {
            if (items[i]->name == _brieName)
            { 
                items[i]->increaseQuality();
            }
            else if (items[i]->name == _backName)
            { 
                items[i]->resetQuality();
            }
            else if (items[i]->name == _sulfurName)
            {
            }
            else
            {
                items[i]->decreaseQuality();                    
            }            
        } 
    }
}

void GildedRose::handleBackStage(Item & item)
{
    if (item.sellIn < 11)        
        item.increaseQuality();        

    if (item.sellIn < 6)        
        item.increaseQuality();            
}

void GildedRose::decreaseSellIn(Item & item)
{
    if (item.name != "Sulfuras, Hand of Ragnaros")
        item.decreaseSellIn();
}