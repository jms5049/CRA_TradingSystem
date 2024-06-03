#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string>

#include "../TradingSystem/AutoTradingSystem.cpp"
#include "../TradingSystem/StockBroker.cpp"
using namespace testing;

class BrokerMock : public StockBroker {
public:
	MOCK_METHOD(void, selectBroker, (string brokerName), (override));
	MOCK_METHOD(void, login, (string id, string pw), (override));
	MOCK_METHOD(void, buy, (string stockCode, int price, int amount), (override));
	MOCK_METHOD(void, sell, (string stockCode, int price, int amount), (override));
	MOCK_METHOD(int, getPrice, (string stockCode), (override));
};

TEST(Init, test1) {
	BrokerMock mock;
	AutoTradingSystem *app = new AutoTradingSystem(&mock);

	EXPECT_TRUE(app != nullptr);
}

TEST(Init, verifyBroker) {
	BrokerMock mock;
	AutoTradingSystem* app = new AutoTradingSystem(&mock);
	app->selectBroker("AA");
	EXPECT_EQ(app->getBroker(), "AA");
}

TEST(Init, verifyLogin) {
	BrokerMock mock;
	AutoTradingSystem* app = new AutoTradingSystem(&mock);
	app->signUp("AA", "BB");	//string id, string pw
	app->login("AA","BB");		//expect login
	EXPECT_THROW(app->login("AA", "CC"), std::exception);
}

TEST(Init, buyStockNemo) {
	BrokerMock mock;
	AutoTradingSystem* app = new AutoTradingSystem(&mock);
	app->selectBroker("Nemo");
	app->buy("AnyStockCode", "3000", 5);
	EXPECT_TRUE(app->stock != nullptr);
}

TEST(Init, sellStockNemo) {
	BrokerMock mock;
	AutoTradingSystem* app = new AutoTradingSystem(&mock);
	app->selectBroker("Nemo");
	app->buy("AnyStockCode", "3000", 5);
	app->sell("AnyStockCode", "3000", 5);
	EXPECT_TRUE(app->stock == nullptr);
}