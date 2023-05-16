#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__

#include <map>
#include <ctime>
#define ZERO -1

class BitcoinExchange {
public:
    BitcoinExchange();
    ~BitcoinExchange();

    double getValue(const int& key);
private:
    BitcoinExchange(const BitcoinExchange& copy);
    const BitcoinExchange& operator=(const BitcoinExchange& copy);
    std::map<int, double> _data;
};

#endif
