#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define maxLength 1000000000000
#define maxWeight 1000000
#define maxNodesCount 100001

using namespace std;

struct Node{
    int num;
    long long lengthOfWay;
    bool operator<(const Node& other) const{
        return lengthOfWay > other.lengthOfWay;
    }
};

long long minLength[maxNodesCount];
bool isNodeChecked[maxNodesCount];
priority_queue<Node> lengths;
vector<vector<pair<int, int>>> graph;

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> t;
    for (int i = 0; i<= N; i++){
        graph.push_back(t);
        minLength[i] = maxLength;
        isNodeChecked[i] = false;
    }
    
    for (int i = 0; i < M; i++){
        int n1, n2, C;
        cin >> n1 >> n2 >> C;
        graph[n1].push_back(pair<int, int>(n2, C));
        graph[n2].push_back(pair<int, int>(n1, C));
    }
    
    int start, finish;
    cin >> start >> finish;
    
    lengths.push(Node{start, 0});
    minLength[start] = 0;
    
    for (int c = 0; c < N; c++){
        Node t;
        while(true){
            t = lengths.top();
            lengths.pop();
            if (isNodeChecked[t.num]) continue;
            isNodeChecked[t.num] = true;
            break;
        }
        
        for (int i = 0; i < (int)graph[t.num].size(); i++){
            long long check = t.lengthOfWay + graph[t.num][i].second;
            if (minLength[graph[t.num][i].first] > check){
                minLength[graph[t.num][i].first] = check;
                lengths.push(Node{graph[t.num][i].first, check});
            }
        }
    }
    cout << minLength[finish];
    return 0;
}
