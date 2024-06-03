#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string>
using namespace testing;

class BrokerMock : public StockBroker {
public:
	MOCK_METHOD(void, selectBroker, (string brokerName), (override));
	MOCK_METHOD(void, login, (string id, string pw), (override));
	MOCK_METHOD(void, buy, (string stockCode, int price, int amount), (override));
	MOCK_METHOD(void, sell, (string stockCode, int price, int amount), (override));
	MOCK_METHOD(int, getPrice, (string stockCode), (override));
};


TEST(sdfsdf, test1) {
	BrokerMock mock;
	AutoTradingSystem *app = new AutoTradingSystem(&mock);

	EXPECT_TRUE(app != nullptr);
}