#include "ApprovalTests.hpp"
#include "doctest/doctest.h"

#include "XMLExporter.h"
#include "StoreEvent.h"
#include "Util.h"


void verifyXml(std::string xml, ApprovalTests::Options options = ApprovalTests::Options()) {
    xml = ApprovalTests::StringUtils::replaceAll(xml, ">", ">\n");
    ApprovalTests::Approvals::verify(xml, options.fileOptions().withFileExtension(".xml"));
}


TEST_CASE("XMLExporter") {
    Product* CherryBloom = new Product("Cherry Bloom", "LIPSTICK01", 30, new Price(14.99, "USD"));
    Product* RosePetal = new Product("Rose Petal", "LIPSTICK02", 30, new Price(14.99, "USD"));
    Product* BlusherBrush = new Product("Blusher Brush", "TOOL01", 50, new Price(24.99, "USD"));
    Product* EyelashCurler = new Product("Eyelash curler", "TOOL01", 100, new Price(19.99, "USD"));
    Product* WildRose = new Product("Wild Rose", "PURFUME01", 200, new Price(34.99, "USD"));
    Product* CocoaButter = new Product("Cocoa Butter", "SKIN_CREAM01", 250, new Price(10.99, "USD"));

    std::vector<Product *> storeProducts;
    storeProducts.push_back(CherryBloom);
    storeProducts.push_back(RosePetal);
    storeProducts.push_back(BlusherBrush);
    storeProducts.push_back(EyelashCurler);
    storeProducts.push_back(WildRose);
    storeProducts.push_back(CocoaButter);

    Store* FlagshipStore = new Store("Nordstan", "4189", storeProducts);
    /* Store events add themselves to the stocked items at their store */
    Product* Masterclass = new StoreEvent("Eyeshadow Masterclass", "EVENT01",
                                          FlagshipStore, new Price(119.99, "USD"));
    Product* Makeover = new StoreEvent("Makeover", "EVENT02",
                                       FlagshipStore, new Price(149.99, "USD"));

    std::vector<Product *> orderProducts;
    orderProducts.push_back(Makeover);
    Order* RecentOrder = new Order("1234", from_iso_date("2018-09-01T00:00Z"),
                                   FlagshipStore, orderProducts);


    SUBCASE("export store") {
        // TODO: write this test case
    }
}


