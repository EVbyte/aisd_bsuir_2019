#include <iostream>
using namespace std;

int main(int argc, const char * argv[]){
    string num;
    cin >> num;
    num [num.length() - 1] == '0' ? cout << "NO": cout << num [num.length() - 1];
    return 0;
}
