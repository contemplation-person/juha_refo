#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__

#include <map>
#include <cstdio>

template <typename T>
class BitcoinExchange {
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& copy);
    const BitcoinExchange& operator=(const BitcoinExchange& copy);

    void setData(std::FILE* fp);
    std::string getDate();
    std::string getValue(std::vector<std::string, T> data);
private:
    std::map<std::string, T> data;
};
#endif
