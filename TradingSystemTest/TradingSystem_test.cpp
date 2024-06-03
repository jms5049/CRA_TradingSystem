#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TradingSystem/NemoAPI.cpp"
#include "../TradingSystem/KiwerAPI.cpp"

using namespace testing;

class BrokerMock : public StockBroker {
public:
	MOCK_METHOD(void, selectBroker, (string brokerName), (override));
	MOCK_METHOD(void, login, (string id, string pw), (override));
	MOCK_METHOD(void, buy, (string stockCode, int price, int amount), (override));
	MOCK_METHOD(void, sell, (string stockCode, int price, int amount), (override));
	MOCK_METHOD(int, getPrice, (string stockCode), (override));
	MOCK_METHOD(void, buyNiceTiming, (string stockCode, int price), (override));
	MOCK_METHOD(void, sellNiceTiming, (string stockCode, int price), (override));

};

class KiwerMock : public KiwerDriver{
public:
	MOCK_METHOD(void, login, (string id, string pw), (override));
	MOCK_METHOD(void, buy, (string stockCode, int price, int amount), (override));
	MOCK_METHOD(void, sell, (string stockCode, int price, int amount), (override));
	MOCK_METHOD(int, getPrice, (string stockCode), (override));
};

class NemoMock : public NemoDriver {
public:
	MOCK_METHOD(void, login, (string id, string pw), (override));
	MOCK_METHOD(void, buy, (string stockCode, int price, int amount), (override));
	MOCK_METHOD(void, sell, (string stockCode, int price, int amount), (override));
	MOCK_METHOD(int, getPrice, (string stockCode), (override));
};

class DriverFixture : public testing::Test {
public:
	KiwerMock kMock;
	NemoMock nMock;
};

TEST_F(DriverFixture, loginNemo) {
}

TEST_F(DriverFixture, buyKiwer) {
}

TEST_F(DriverFixture, sellKiwer) {
}

TEST_F(DriverFixture, sellKiwer) {
}

TEST_F(DriverFixture, getCurrentPriceKiwer) {
}

TEST_F(DriverFixture, buyNemo) {
}

TEST_F(DriverFixture, sellNemo) {
}

TEST_F(DriverFixture, sellNemo) {
}

TEST_F(DriverFixture, getCurrentPriceNemo) {
}
