#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

double globalVariable = 1.121212121212;
constexpr long int MAX = 10000;

int* FunctionOne(int x);
void FunctionTwo(int x);
template <typename T>
T PrintAddress(const char* message, T* pointer);


int main() {
    int localMainVariable = 0xFF;
    unsigned long int* dynamicVariable = new unsigned long int;
    *dynamicVariable = 0xFFFFFF;

    cout << "Global Variables: " << endl;
    PrintAddress("&globalVariable", &globalVariable);
    PrintAddress("&MAX", &MAX);
    cout << endl;
    cout << "Main Local Variables: " << endl;
    PrintAddress("&localVariable", &localMainVariable);
    PrintAddress("&dynamicVariable", &dynamicVariable);
    PrintAddress("dynamicVariable", dynamicVariable);
    cout << endl;

    int* address = FunctionOne(0);
    cout << "Main Local Variables: " << endl;
    PrintAddress("&address", &address);
    PrintAddress("address", address);
    cout << endl;
    FunctionTwo(3);



    delete dynamicVariable;
    delete address;
    return 0;
}

int* FunctionOne(int x) {
    int localF1Variable = 0xFF00;
    int* dynamicVariable = new int[10];
    cout << "Function One Local Variables: " << endl;
    PrintAddress("&localF1Variable", &localF1Variable);
    PrintAddress("&dynamicVariable", &dynamicVariable);
    PrintAddress("dynamicVariable", dynamicVariable);
    cout << endl;
    return dynamicVariable;
}
void FunctionTwo(int x) {
    int localF2Variable = 0xFFFF;
    long double veryBigArray[10000] = {0};
    cout << "Function Two (" << x << ") Local Variables: " << endl;
    PrintAddress("&localF2Variable", &localF2Variable);
    PrintAddress("&veryBigArray", reinterpret_cast<long double**>(&veryBigArray));
    PrintAddress("veryBigArray", veryBigArray);
    cout << endl;
    if (x > 1)
        FunctionTwo(x - 1);
}
template <typename T>
T PrintAddress(const char* message, T* pointer) {
    cout << setw(20) << message << "\t" << pointer << endl;
    return *static_cast<T *>(pointer);
}
