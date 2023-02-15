// declaration of class Sales and members
#pragma once
#include <string>

class Sales {
private:
    int id;
    int units;
    double prices;
    std::string description;
    bool TaxExempt;

public:
    double sale_amt();

    void setId(int id);
    void setUnits(int unit);
    void setPrices(double price);
    void setDescription(std::string desc);
    void setTax(bool x);

    int getId();
    int getUnits();
    double getPrice();
    std::string getDesc();
    bool getTax();

};
