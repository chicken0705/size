#include <iostream>
#include <algorithm> // 為了使用 std::copy

using namespace std;

extern void print_arr(int* arr, int size);
extern void change_size(int*& arr, int size, int new_size);

int main() {
    int size = 1000;
    int* arr = new int[size];

    // 插入元素
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    print_arr(arr, size);  // 打印初始陣列

    int new_size = size * 2; // 使用指數增長的方式擴展
    change_size(arr, size, new_size);
    print_arr(arr, new_size);  // 打印新陣列

    delete[] arr; // 釋放分配的內存
}

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << '\n';
}

void change_size(int*& arr, int size, int new_size) {
    int* new_arr = new int[new_size];

    // 只複製較小的舊大小或新大小的元素
    int elements_to_copy = min(size, new_size);
    copy(arr, arr + elements_to_copy, new_arr);

    // 如果新大小更大，則初始化新元素為零
    for (int i = elements_to_copy; i < new_size; i++) {
        new_arr[i] = 0; // 或者你可以選擇其他默認值
    }

    delete[] arr; // 釋放舊內存
    arr = new_arr; // 重新賦值指針
}
