#include <iostream>
#include <vector>
#define matrix vector<vector<long long>>
using namespace std;

const int mod = 1e9 + 7;

matrix multiplyMatrix (matrix a, matrix b){
    int size = (int) a.size();
    matrix c (size, vector<long long>(size , 0));
    
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            for (int k = 0; k < size; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % mod) % mod;
        }
    }
    return c;
}

matrix binPowerMatrix(matrix a, int k) {
    int size = (int) a.size();
    matrix b (size, vector<long long>(size, 0));
    for (int i = 0; i < size; i ++)
        b[i][i] = 1;
    
    while (k)
        if (k % 2 == 1) {
            b = multiplyMatrix(b, a);
            k--;
        }
        else {
            a = multiplyMatrix(a, a);
            k /= 2;
        }
    return b;
}

int main(){
    int N, M;
    cin >> N >> M;
    
    int U, V, L;
    cin >> U >> V >> L;
    
    matrix inputMatrix (N, vector<long long>(N, 0));
    for (int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        A --;
        B --;
        if (A == B)
            inputMatrix[A][B] += 2;
        else{
            inputMatrix[A][B] += 1;
            inputMatrix[B][A] += 1;
        }
    }
    
    inputMatrix = binPowerMatrix(inputMatrix, L);
    
    cout << inputMatrix[U - 1][V - 1];
}
