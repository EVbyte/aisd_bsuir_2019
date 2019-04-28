#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const ll mod = 1e10+7;

ll modMultiply(ll a, ll b){
    return ((a % mod) * (b % mod)) % mod;
}

int main(int argc, const char * argv[]){
    int quantity, k;
    ll result = 1;
    cin >> quantity >> k;
    ll nums [100000];
    for (int i = 0; i < quantity; i++)
        cin >> nums[i];
    
    sort(nums, nums + quantity);
    
    if (nums[0] >= 0)
        for (int i = quantity - 1; i > quantity - k - 1; i--)
            result = modMultiply(result, nums[i]);
    
    else if (nums[quantity - 1] <= 0){
        if (k % 2 == 0)
            for (int i = 0; i > k; i++)
                result = modMultiply(result, nums[i]);
        else
            for (int i = quantity - 1; i > quantity - k - 1; i--)
                result = modMultiply(result, nums[i]);
    }
    else{
        int left = 0, right = quantity - 1;
        while (k > 0){
            if (k > 1 && (nums[left] * nums[left + 1]) >= (nums[right] * nums[right - 1])){
                result = modMultiply(result, modMultiply(nums[left], nums[left + 1]));
                left += 2;
                k -= 2;
            }
            else{
                result = modMultiply(result, nums[right]);
                right--;
                k--;
            }
        }
    }
    
    result = (result + mod) % mod;
    cout << result;
    return 0;
}


