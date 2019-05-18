#include <iostream>
#include <algorithm>
#include <vector>
#define maxNodes 10001
using namespace std;

vector<int> graph[maxNodes];
bool checked[maxNodes];
int nodesCount, linesCount;

void dfs(int node){
    checked[node] = true;
    for (int i = 0; i < graph[node].size(); i++){
        int nextNode = graph[node][i];
        if (!checked[nextNode])
            dfs(nextNode);
    }
}

bool isGraphConnected(){
    dfs(1);
    for (int i = 2; i < nodesCount; i++)
        if (!checked[i])
            return false;
    return true;
}

int main(){
    cin >> nodesCount >> linesCount;
    
    for (int i = 0; i < linesCount; i++){
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;
        graph[firstNode].push_back(secondNode);
        graph[secondNode].push_back(firstNode);
    }
    
    if (isGraphConnected())
        cout << linesCount - nodesCount + 1;
    else
        cout << -1;
    return 0;
}
