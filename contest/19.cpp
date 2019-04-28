#include <iostream>
using namespace std;

void Merge(int* a, int left, int right, int center, unsigned long* inverseCount){
    int capacity = right - left + 1;
    int* b = new int [capacity];
    int i = left, j = center + 1, k = 0;
    while(i <= center && j <= right){
        b[k] = min(a[i], a[j]);
        if (min(a[i], a[j]) == a[i]) i++;
        else{
            j++;
            (*inverseCount) += (center - i + 1);
        }
        k++;
    }
    if (i > center)
        while (j <= right){
            b[k] = a[j];
            j++; k++;
        }
    else
        while (i <= center){
            b[k] = a[i];
            i++; k++;
        }
    
    for (int i = left, k = 0; i <= right; i++, k++)
        a[i] = b[k];
    delete [] b;
}

void MergeSort(int* a, int left, int right, unsigned long* inverseCount){
    if (left < right){
        int center = left + (right - left) / 2;
        MergeSort(a, left, center, inverseCount);
        MergeSort(a, center + 1, right, inverseCount);
        Merge(a, left, right, center, inverseCount);
    }
}

int main(){
    unsigned long answer = 0;
    int len = 0;
    cout << endl;
    cin >> len;
    int* a = new int[len];
    for (int i = 0; i < len; i++)
        cin >> a[i];
    MergeSort(a, 0, len - 1, &answer);
    cout << answer;
    return 0;
}
