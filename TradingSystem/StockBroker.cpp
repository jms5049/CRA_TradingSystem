#include <string>
using namespace std;

class StockBroker {
private:
	virtual void selectBroker(string brokerNAme) = 0;
	virtual void login(string id, string pw) = 0;
	virtual void buy(string stockCode, int price, int amount) = 0;
	virtual void sell(string stockCode, int price, int amount) = 0;
	virtual int getPrice(string stockCode) = 0;
};