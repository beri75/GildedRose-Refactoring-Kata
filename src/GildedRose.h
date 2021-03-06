#include <string>
#include <vector>
#include <memory>

using namespace std;

const string _brieName = "Aged Brie";
const string _backName = "Backstage passes to a TAFKAL80ETC concert";
const string _sulfurName = "Sulfuras, Hand of Ragnaros";
const string _conjured = "Conjured";

class Item
{
protected:
    string name;
    int sellIn;
    int quality;

public:

    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}

    string GetName() const
    {
        return name;
    }

    int GetSellIn() const
    {
        return sellIn;
    }

    int GetQuality() const
    {
        return quality;
    }

    void increaseQuality() {
        quality = min(50, ++quality);
    }

    virtual void decreaseQuality() {
        quality = max(0, --quality);
    }

    void resetQuality() {
        quality = 0;
    }

    void decreaseSellIn() {
        --sellIn;
    }

    virtual void update() 
    {
        decreaseQuality();
        decreaseSellIn();

        if (sellIn < 0)
            decreaseQuality();
    }
};

class Brie : public Item 
{
public:
    Brie(int sellIn, int quality) : Item(_brieName, sellIn, quality) {}
    void update() override
    {
        increaseQuality();
        decreaseSellIn();
    }
};

class Backstage : public Item
{
public:
    Backstage(int sellIn, int quality) : Item(_backName, sellIn, quality) {}
    void update() override
    {
        increaseQuality();
        
        if (sellIn > 0)
        {
            if (sellIn < 11) 
                increaseQuality();
            if (sellIn < 6) 
                increaseQuality();
        }
        else
            resetQuality();

        decreaseSellIn();
    }
};

class Sulfuras : public Item
{
public:
    Sulfuras(int sellIn) : Item(_sulfurName, sellIn, 80) {}
    void update() override
    {
    }
};

class Conjured : public Item
{
public:
    Conjured(int sellIn, int quality) : Item(_conjured, sellIn, quality) {}

    void decreaseQuality() override
    {
        quality = max(0, quality - 2);
    }
};

typedef shared_ptr<Item> itemPtr;
class GildedRose
{
public:
    vector<itemPtr> items;      

    GildedRose(vector<itemPtr> & items);
    GildedRose(vector<Item>& _items);
    
    void updateQuality();    
};

