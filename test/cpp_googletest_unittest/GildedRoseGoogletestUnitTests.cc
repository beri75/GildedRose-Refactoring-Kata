#include <gtest/gtest.h>
#include "GildedRose.h"



TEST(GildedRoseTest, con10GiorniRestanti_laNuovaQualitaDelFormaggioDiventa) {

    vector<itemPtr> items;
    items.push_back(make_shared<Item>("Aged Brie", 10, 10));
    
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ("Aged Brie", app.items[0]->name);
    EXPECT_EQ(9, app.items[0]->sellIn);
    EXPECT_EQ(11, app.items[0]->quality);
}

TEST(GildedRoseTest, con9Restanti_laNuovaQualitaDelFormaggioDiventa) {

    vector<itemPtr> items;
    items.push_back(make_shared<Item>("Aged Brie", 9, 10));

    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(11, app.items[0]->quality);
}

TEST(GildedRoseTest, raggiuntaLaScadenza_laQualitaDegradaIlDoppio) {

    vector<itemPtr> items;
    items.push_back(make_shared<Item>("CiccioPasticcio", 0, 10));

    GildedRose app(items);
    app.updateQuality();   
    
    EXPECT_EQ(8, app.items[0]->quality);
}

TEST(GildedRoseTest, raggiuntaLaScadenza_laQualitaNonEMaiNegativa) {

    vector<itemPtr> items;
    items.push_back(make_shared<Item>("CiccioPasticcio", 0, 0));

    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(-1, app.items[0]->sellIn); //!!! ouch
    EXPECT_EQ(0, app.items[0]->quality);
}

TEST(GildedRoseTest, trascorsoUnGiorno_laQualitaDelBrieAumenta) {

    vector<itemPtr> items;
    items.push_back(make_shared<Item>("Aged Brie", 5, 10));
    
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(11, app.items[0]->quality);
}

TEST(GildedRoseTest, raggiuntaLaQualitaMassima_trascorsoUnGiorno_laQualitaRestaInvariata) {

    vector<itemPtr> items;
    items.push_back(make_shared<Item>("Aged Brie", 5, 50));

    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(50, app.items[0]->quality);
}

TEST(GildedRoseTest, Sulfuras_raggintaLaQualitaMassima_trascorsoUnGiorno_laQualitaRestaInvariata) {

    vector<itemPtr> items;
    items.push_back(make_shared<Item>("Sulfuras, Hand of Ragnaros", 5, 10));

    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(5, app.items[0]->sellIn);
    EXPECT_EQ(10, app.items[0]->quality);
}

TEST(GildedRoseTest, Backstage_raggintaLaQualitaMassima_trascorsoUnGiorno_laQualitaRestaInvariata) {

    vector<itemPtr> items;
    items.push_back(make_shared<Item>("Backstage passes to a TAFKAL80ETC concert", 11, 10));
    items.push_back(make_shared<Item>("Backstage passes to a TAFKAL80ETC concert", 10, 10));
    items.push_back(make_shared<Item>("Backstage passes to a TAFKAL80ETC concert", 5, 10));

    GildedRose app(items);
    app.updateQuality();
    
    EXPECT_EQ(11, app.items[0]->quality);    
    EXPECT_EQ(12, app.items[1]->quality);
    EXPECT_EQ(13, app.items[2]->quality);
}


