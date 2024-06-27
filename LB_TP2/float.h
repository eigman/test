#include <iostream>

class RealNumber {
private:
    double value;

public:
    RealNumber();
    explicit RealNumber(double val);
    RealNumber(const RealNumber& other);
    ~RealNumber();

    RealNumber operator-(const RealNumber& other);

    friend RealNumber operator+(const RealNumber& num1, const RealNumber& num2);

    bool operator<(const RealNumber& other) const;
    bool operator>(const RealNumber& other) const;
    bool operator==(const RealNumber& other) const;
    bool operator!=(const RealNumber& other) const;

    void display() const;
};