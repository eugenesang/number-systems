#include <iostream>
#include <vector>
#include <algorithm>

class BigNumber {
private:
    std::vector<int> digits;
    bool isNegative;

public:
    BigNumber() : digits(1, 0), isNegative(false) {}

    // Constructor from integer
    BigNumber(int num) {
        if (num < 0) {
            isNegative = true;
            num = -num;
        }
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
    }

    // Display number as text
    void display() const {
        if (isNegative) {
            std::cout << "-";
        }
        for (int i = digits.size() - 1; i >= 0; --i) {
            std::cout << digits[i];
        }
    }

    // Addition
    BigNumber add(const BigNumber& other) const {
        BigNumber result;
        int carry = 0;
        int maxLength = std::max(digits.size(), other.digits.size());
        for (int i = 0; i < maxLength; ++i) {
            int sum = (i < digits.size() ? digits[i] : 0) + (i < other.digits.size() ? other.digits[i] : 0) + carry;
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry) {
            result.digits.push_back(carry);
        }
        result.isNegative = isNegative ^ other.isNegative && result.digits[0] != 0;
        return result;
    }

    // Subtraction
    BigNumber subtract(const BigNumber& other) const {
        return add(other.negate());
    }

    // Multiplication
    BigNumber multiply(const BigNumber& other) const {
        BigNumber result;
        result.digits.resize(digits.size() + other.digits.size());
        int carry = 0;
        for (int i = 0; i < digits.size(); ++i) {
            for (int j = 0; j < other.digits.size(); ++j) {
                int product = digits[i] * other.digits[j] + carry;
                result.digits[i + j] += product % 10;
                carry = product / 10;
                while (carry) {
                    result.digits[i + j + 1] += carry % 10;
                    carry /= 10;
                }
            }
        }
        result.trimLeadingZeros();
        result.isNegative = isNegative ^ other.isNegative;
        return result;
    }

    // Division
    BigNumber divide(const BigNumber& other) const {
        // Implement division logic here (consider handling remainder, potential overflow)
        throw std::runtime_error("Division not implemented yet.");
    }

private:
    void trimLeadingZeros() {
        while (!digits.empty() && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.empty()) {
            isNegative = false;
        }
    }

    BigNumber negate() const {
        BigNumber negated;
        negated.digits = digits;
        negated.isNegative = !isNegative;
        return negated;
    }
};

int main() {
    BigNumber num1(12345);
    BigNumber num2(54321);

    std::cout << "Number 1: ";
    num1.display();
    std::cout << std::endl;

    std::cout << "Number 2: ";
    num2.display();
    std::cout << std::endl;

    std::cout << "Sum: ";
    (num1.add(num2)).display();
    std::cout << std::endl;

    std::cout << "Difference: ";
    (num1.subtract(num2)).display();
    std::cout << std::endl;

    std::cout << "Product: ";
    (num1.multiply(num2)).display();
    std::cout << std::endl;
}