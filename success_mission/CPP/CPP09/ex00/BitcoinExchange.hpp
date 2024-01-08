#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__

#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string txtName);
    BitcoinExchange(const std::string csvName, const std::string txtName);
    ~BitcoinExchange();

    bool calculate(const std::string& fileName);
    double getValue(const int& key);
private:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& copy);
    const BitcoinExchange& operator=(const BitcoinExchange& copy);
    std::map<int, double> _data;
};

#endif
