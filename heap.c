#include <bits/stdc++.h>
using namespace std;

int heap_top(vector<int> heap) {
    return heap[0];
}

void heap_push(vector<int> &heap, int item) {
    heap.push_back(item);
    int i = heap.size() -1;
    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(heap[(i-1)/2], heap[i]);
        i = (i-1)/2;
    }
}

void heap_pop_helper(vector<int> &heap, int i) {
    int n = heap.size();
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int min_index = i;
    if (l < n && heap[i] > heap[l]) 
        min_index = l;
    if (r < n && heap[min_index] > heap[r])
        min_index = r;
    if (i != min_index) {
        swap(heap[i], heap[min_index]);
        heap_pop_helper(heap, min_index);
    }
}
void heap_pop(vector<int> &heap) {
    heap[0] = heap[heap.size() -1];
    heap.pop_back();
    int i = 0;
    heap_pop_helper(heap, 0);
}

int main() {
    vector<int> v = {2, 10, 100, 15, 14, 5, 28, 17, 50, 8, 22, 46, 3, 80};
    vector<int> heap;
    for (int i : v)
        heap_push(heap, i);
    cout << "Heap is: " << endl;
    for (int i : heap)
        cout << i << " ";
    cout << endl;
    while (!heap.empty()) {
        cout << heap_top(heap) << " ";
        heap_pop(heap);
    }
}
        
