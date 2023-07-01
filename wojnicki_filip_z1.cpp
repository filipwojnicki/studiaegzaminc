#include <iostream>

template <int X, int Y>
class NWD {
public:
    static const int wynik = NWD<Y, X % Y>::wynik;
};

// Specialization to end the recursive process when one of the arguments reaches 0
template <int X>
class NWD<X, 0> {
public:
    static const int wynik = X;
};

int main() {
    int nwd1 = NWD<40, 10>::wynik;
    int nwd2 = NWD<366, 60>::wynik;

    std::cout << "NWD of 40 and 10: " << nwd1 << std::endl;
    std::cout << "NWD of 366 and 60: " << nwd2 << std::endl;

    return 0;
}