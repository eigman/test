#include "float.h"

RealNumber::RealNumber() : value(0.0) {}
RealNumber::RealNumber(double val) : value(val) {}
RealNumber::RealNumber(const RealNumber& other) : value(other.value) {}
RealNumber::~RealNumber() {}

RealNumber RealNumber::operator-(const RealNumber& other) {
    return RealNumber(value - other.value);
}

RealNumber operator+(const RealNumber& num1, const RealNumber& num2) {
    return RealNumber(num1.value + num2.value);
}

bool RealNumber::operator<(const RealNumber& other) const {
    return value < other.value;
}

bool RealNumber::operator>(const RealNumber& other) const {
    return value > other.value;
}

bool RealNumber::operator==(const RealNumber& other) const {
    return value == other.value;
}

bool RealNumber::operator!=(const RealNumber& other) const {
    return !(*this == other);
}

void RealNumber::display() const {
    std::cout << value;
}
