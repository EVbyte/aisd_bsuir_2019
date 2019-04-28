#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct coordinates{
    int x;
    int y;
    
    bool operator< (const coordinates& other) const{
        if(x != other.x)
            return x < other.x;
        return y < other.y;
    }
};

const int maxTableSize = 102;
map<coordinates, vector<coordinates>> graphOfMoves;
bool isSquarePossible[102][102];

int numOfMoves[102][102];
bool isVisited[102][102];

int rowsNum, columnsNum;

void addPossibleSquares(coordinates square){
    vector<coordinates> possibleMoves;
    isSquarePossible[square.x][square.y] = true;
    
    for (int i = -2; i < 3; i++)
        for (int j = -2; j < 3; j++){
            if (i == 0 || j == 0 || (abs(i) == 2 && abs(j) == 2)
                || (abs(i) == 1 && abs(j) == 1)) continue;
            if (square.x + j <= rowsNum && 1 <= square.x + j
                && square.y + i <= columnsNum && 1 <= square.y + i)
                possibleMoves.push_back(coordinates{square.x + j, square.y +i});
        }
    
    graphOfMoves.insert(pair<coordinates, vector<coordinates>> (square, possibleMoves));
    
    for (int i = 0; i < (int)possibleMoves.size(); i++)
    {
        if (!isSquarePossible[possibleMoves[i].x][possibleMoves[i].y])
            addPossibleSquares(possibleMoves[i]);
    }
}

void bfs(coordinates square){
    isVisited[square.x][square.y] = true;
    queue<coordinates> moves;
    moves.push(square);
    while (!moves.empty()) {
        coordinates from = moves.front();
        moves.pop();
        vector<coordinates> c = graphOfMoves[from];
        for (int i = 0; i < c.size(); i++) {
            coordinates to = c[i];
            if (!isVisited[to.x][to.y]) {
                isVisited[to.x][to.y] = true;
                moves.push(to);
                numOfMoves[to.x][to.y] = numOfMoves[from.x][from.y] + 1;
            }
        }
    }
}

int main(){
    cin >> rowsNum >> columnsNum;
    int finalRowNum, finalColumnNum;
    cin >> finalRowNum >> finalColumnNum;
    
    for (int i = 0; i < maxTableSize; i++)
        for (int j = 0; j < maxTableSize; j++){
            isSquarePossible[i][j] = false;
            isVisited[i][j] = false;
            numOfMoves[i][j] = 0;
        }
    
    coordinates firstSquare = {1, 1};
    addPossibleSquares(firstSquare);
    
    if(!isSquarePossible[finalRowNum][finalColumnNum]){
        cout << "NEVAR";
        return 0;
    }
    
    bfs(firstSquare);
    cout  << numOfMoves[finalRowNum][finalColumnNum];
    return 0;
}
