// S01E02. Data structures. Heap sort

#include <iostream>
#include <vector>

using namespace std;

void sift_down(vector<int>& a, int start, int end) { // as remove_min()
    int root = start;
    
    while ((root * 2 + 1) <= end) {
        int swapIdx = root * 2 + 1; // Left child
        
        if (swapIdx + 1 <= end && a[swapIdx + 1] < a[swapIdx] ) {
            swapIdx++;
        }
        
        if (a[swapIdx] > a[root]) {
            return;
        }
        swap(a[root], a[swapIdx]);
        root = swapIdx;
    }
}

void heapify(vector<int>& a, int size) {
    int start = (size - 2) / 2; // Number of levels
    
    while (start >= 0) {
        sift_down(a, start, size - 1);
        start--;
    }
}

void sort(vector<int>& a) {
    int size = (int)a.size();
    
    heapify(a, size);
    
    cout << "Min-heap: ";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    int end = size - 1;
    while (end > 0) {
        swap(a[end], a[0]);
        end--;
        sift_down(a, 0, end);
    }
}

int main() {
    vector<int> a = {26, 2, 7, 10, 9, 8, 18, 13, 15, 5};
    
    sort(a);
    
    cout << "Sorted array (descending): ";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}
