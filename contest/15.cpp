#include <iostream>
using namespace std;

int main(){
    long long maxNum, prevNum, num, sum = 0;
    int length;
    cin >> length >> prevNum;
    maxNum = prevNum;
    for (int i = 1; i < length; i++) {
        cin >> num;
        if (num > maxNum) {
            sum += (num - maxNum);
            maxNum = num;
        }
        else
            if (num < prevNum)
                sum += (prevNum - num);
        prevNum = num;
    }
    cout << sum;
    return 0;
}
