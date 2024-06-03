class AutoTradingSystem {
public:
	AutoTradingSystem(class StockBroker* targetBroker)
		:broker(targetBroker) {

	}

private:
	class StockBroker* broker;
};