#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define MAXL 100001
using namespace std;

int main(){
    int nums[MAXL];
    for (int i = 0; i < MAXL; i++)
        nums[i] = 0;
    
    int n, m;
    cin >> n >> m;
    vector<pair<int,pair<int, int>>> queriesLeftSort;
    vector<pair<int,pair<int, int>>> queriesRightSort;
    
    for (int i = 0; i < m; i++){
        int l, r, min;
        cin >> l >> r >> min;
        queriesLeftSort.push_back(pair<int, pair<int, int>>(min, pair<int, int> (l, r)));
        queriesRightSort.push_back(pair<int, pair<int, int>>(min, pair<int, int> (l, r)));
    }
    
    sort(queriesLeftSort.begin(), queriesLeftSort.end(),
         [](const pair<int,pair<int, int>> a,
            const pair<int,pair<int, int>> b) {return a.second.first < b.second.first;
         });
    sort(queriesRightSort.begin(), queriesRightSort.end(),
         [](const pair<int,pair<int, int>> a,
            const pair<int,pair<int, int>> b) {return a.second.second < b.second.second;
         });
    
    multiset<int> mins;
    vector<bool> isInSet(m, false);
    int lPointer = 0, rPointer = 0;
    for (int i = 0; i < n; i++){
        while (lPointer < m && i + 1 >= queriesLeftSort[lPointer].second.first){
            mins.insert(queriesLeftSort[lPointer].first);
            lPointer++;
        }
        while (rPointer < m && i + 1 > queriesRightSort[rPointer].second.second){
            mins.erase(mins.lower_bound(queriesRightSort[rPointer].first));
            rPointer++;
        }
        if (mins.size() > 0)
            nums[i] = *(--mins.end());
    }
    
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    
    return 0;
}
