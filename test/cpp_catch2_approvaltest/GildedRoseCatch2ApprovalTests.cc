#define APPROVALS_CATCH
#include "ApprovalTests.hpp"
#include "GildedRose.h"

std::ostream& operator<<(std::ostream& os, const Item& obj)
{
    return os
        << "name: " << obj.GetName()
        << ", sellIn: " << obj.GetSellIn()
        << ", quality: " << obj.GetQuality();
}

TEST_CASE("GildedRoseApprovalTests", "VerifyCombinations")
{
    std::vector<string> names { "Foo" };
    std::vector<int> sellIns { 1 };
    std::vector<int> qualities { 1 };

    auto f = [](string name, int sellIn, int quality) {
        vector<Item> items = {Item(name, sellIn, quality)};
        GildedRose app(items);
        app.updateQuality();
        return items[0];
    };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(
            f,
            names, sellIns, qualities);
}
