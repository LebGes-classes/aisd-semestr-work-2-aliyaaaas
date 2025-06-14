#include <iostream>
#include <vector>

void stoogeSort(std::vector<int>& arr, int l, int h) {
    if (l >= h) return;

    if (arr[l] > arr[h]) {
        std::swap(arr[l], arr[h]);
    }

    if (h - l + 1 > 2) {
        int t = (h - l + 1) / 3;
        stoogeSort(arr, l, h - t);     
        stoogeSort(arr, l + t, h);    
        stoogeSort(arr, l, h - t);  
    }
}

void combSort(std::vector<int>& arr) {
    int n = arr.size();
    double shrinkFactor = 1.3;
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = int(gap / shrinkFactor);
        if (gap < 1) gap = 1;

        swapped = false;
        for (int i = 0; i + gap < n; ++i) {
            if (arr[i] > arr[i + gap]) {
                std::swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

int main() {
    std::vector<int> arr1 = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    std::vector<int> arr2 = arr1;

    stoogeSort(arr1, 0, arr1.size() - 1);
    std::cout << "Stooge Sort:\n";
    for (int x : arr1) std::cout << x << " ";
    std::cout << "\n\n";


    combSort(arr2);
    std::cout << "Comb Sort:\n";
    for (int x : arr2) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}