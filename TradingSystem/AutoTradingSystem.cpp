#include <string>

using std::string;

class AutoTradingSystem {
public:
	AutoTradingSystem(class StockBroker* targetBroker)
		:broker(targetBroker) {

	}

	void selectBroker(string brokerName) {

	}

private:
	class StockBroker* broker;
};