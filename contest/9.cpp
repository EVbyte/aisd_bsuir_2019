#include <iostream>
#include <vector>

using namespace std;

int main(){
    string S;
    cin >> S;
    vector<int> numsOfChanges(S.length() + 1);
    for (int i = 0; i < S.length(); i++)
        numsOfChanges[i] = 0;
    
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++){
        int L, R;
        cin >> L >> R;
        if (R < L) swap(L, R);
        numsOfChanges[L - 1]++;
        numsOfChanges[R]--;
    }
    
    for (int i = 1; i < numsOfChanges.size(); i++)
        numsOfChanges[i] += numsOfChanges[i - 1];
    
    for (int i = 0; i < S.length(); i++){
        if(numsOfChanges[i] % 2 == 1)
            isupper(S[i]) ? S[i] = tolower(S[i]) : S[i] = toupper(S[i]);
    }
    
    cout << S;
    return 0;
}
