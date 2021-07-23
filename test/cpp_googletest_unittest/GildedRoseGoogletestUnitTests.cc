#include <gtest/gtest.h>
#include "GildedRose.h"

TEST(GildedRoseTest, con10GiorniRestanti_laNuovaQualitaDelFormaggioDiventa) {

    vector<itemPtr> items;
    items.push_back(make_shared<Brie>(10, 10));
    
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ("Aged Brie", app.items[0]->GetName());
    EXPECT_EQ(9, app.items[0]->GetSellIn());
    EXPECT_EQ(11, app.items[0]->GetQuality());
}

TEST(GildedRoseTest, con9Restanti_laNuovaQualitaDelFormaggioDiventa) {

    vector<itemPtr> items;
    items.push_back(make_shared<Brie>(9, 10));

    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(8, app.items[0]->GetSellIn());
    EXPECT_EQ(11, app.items[0]->GetQuality());
}

TEST(GildedRoseTest, raggiuntaLaScadenza_laQualitaDegradaIlDoppio) {

    vector<itemPtr> items;
    items.push_back(make_shared<Item>("CiccioPasticcio", 0, 10));

    GildedRose app(items);
    app.updateQuality();   
    
    EXPECT_EQ(-1, app.items[0]->GetSellIn());
    EXPECT_EQ(8, app.items[0]->GetQuality());
}

TEST(GildedRoseTest, raggiuntaLaScadenza_laQualitaNonEMaiNegativa) {

    vector<itemPtr> items;
    items.push_back(make_shared<Item>("CiccioPasticcio", 0, 0));

    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(-1, app.items[0]->GetSellIn()); //!!! ouch
    EXPECT_EQ(0, app.items[0]->GetQuality());
}

TEST(GildedRoseTest, trascorsoUnGiorno_laQualitaDelBrieAumenta) {

    vector<itemPtr> items;
    items.push_back(make_shared<Brie>(5, 10));
    
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(11, app.items[0]->GetQuality());
    EXPECT_EQ(4, app.items[0]->GetSellIn());
}

TEST(GildedRoseTest, raggiuntaLaQualitaMassima_trascorsoUnGiorno_laQualitaRestaInvariata) {

    vector<itemPtr> items;
    items.push_back(make_shared<Brie>(5, 50));

    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(50, app.items[0]->GetQuality());
    EXPECT_EQ(4, app.items[0]->GetSellIn());
}

TEST(GildedRoseTest, Sulfuras_raggintaLaQualitaMassima_trascorsoUnGiorno_laQualitaRestaInvariata) {

    vector<itemPtr> items;
    items.push_back(make_shared<Sulfuras>(5));

    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(5, app.items[0]->GetSellIn());
    EXPECT_EQ(80, app.items[0]->GetQuality());
}

TEST(GildedRoseTest, Backstage_raggintaLaQualitaMassima_trascorsoUnGiorno_laQualitaRestaInvariata) {

    vector<itemPtr> items;
    items.push_back(make_shared<Backstage>(11, 10));
    items.push_back(make_shared<Backstage>(10, 10));
    items.push_back(make_shared<Backstage>(5, 10));

    GildedRose app(items);
    app.updateQuality();
    
    EXPECT_EQ(11, app.items[0]->GetQuality());    
    EXPECT_EQ(12, app.items[1]->GetQuality());
    EXPECT_EQ(13, app.items[2]->GetQuality());

    EXPECT_EQ(10, app.items[0]->GetSellIn());
    EXPECT_EQ(9, app.items[1]->GetSellIn());
    EXPECT_EQ(4, app.items[2]->GetSellIn());
}

TEST(GildedRoseTest, sellInRimastoZero_QualitaItemGenericoDecrementaDiDue) 
{
    vector<itemPtr> items;
    items.push_back(make_shared<Item>("CiccioPasticcio", 0, 10));

    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(8, app.items[0]->GetQuality());
    EXPECT_EQ(-1, app.items[0]->GetSellIn());
}

TEST(GildedRoseTest, sellInRimastoZero_QualitaBrieAumentaSellInScende)
{
    vector<itemPtr> items;
    items.push_back(make_shared<Brie>(0, 10));

    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(11, app.items[0]->GetQuality());
    EXPECT_EQ(-1, app.items[0]->GetSellIn());
}

TEST(GildedRoseTest, sellInRimastoZero_QualitaBackstageAumentaSellInScende)
{
    vector<itemPtr> items;
    items.push_back(make_shared<Backstage>(0, 10));

    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(0, app.items[0]->GetQuality());
    EXPECT_EQ(-1, app.items[0]->GetSellIn());
}

TEST(GildedRoseTest, sellInRimastoZero_QualitaSulfuras80SellInRimaneInvariato)
{
    vector<itemPtr> items;
    items.push_back(make_shared<Sulfuras>(0));

    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(80, app.items[0]->GetQuality());
    EXPECT_EQ(0, app.items[0]->GetSellIn());
}

TEST(GildedRoseTest, passaUnGiorno_ConjuredDegradaDiQualitaIlDoppio)
{
    vector<itemPtr> items;
    items.push_back(make_shared<Conjured>(10, 10));

    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(8, app.items[0]->GetQuality());
    EXPECT_EQ(9, app.items[0]->GetSellIn());
}