#include <iostream>
using namespace std;

int main(int argc, const char * argv[]){
    string input;
    cin >> input;
    int len = (int)input.length();
    bool isRepeatingSymbol = true;
    for (int i = 0, j = len - 1; i <= j; i++, j--) {
        if (input[i] != input[j]) {
            cout << len;
            return 0;
        }
        if (isRepeatingSymbol && input[i] != input[0])
            isRepeatingSymbol = false;
    }
    isRepeatingSymbol ? cout << "-1" : cout << len - 1;
    return 0;
}
