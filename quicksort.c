using namespace std;
#include <bits/stdc++.h>

int findpivot(vector<int> &v, int begin, int end) {
    int p = v[end];
    int i = begin;
    for (int j = begin; j < end; j++) {
        if (v[j] < p) {
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[end]);
    return i;
}
void quicksort(vector<int> &v, int begin, int end) {
    if (begin < end) {
        int p = findpivot(v, begin, end);
        quicksort(v, begin, p-1);
        quicksort(v, p+1, end);
    }
}
int main() {
    vector<int> v = {10, 8, 5, 12, 17, 23, 2, 15, 100, 14, 7, 80, 56};
    quicksort(v, 0, v.size()-1);
    for (int i : v)
        cout << i << " ";
}
