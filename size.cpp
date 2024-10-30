#include <iostream>
#include <algorithm> // ���F�ϥ� std::copy

using namespace std;

extern void print_arr(int* arr, int size);
extern void change_size(int*& arr, int size, int new_size);

int main() {
    int size = 1000;
    int* arr = new int[size];

    // ���J����
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    print_arr(arr, size);  // ���L��l�}�C

    int new_size = size * 2; // �ϥΫ��ƼW�����覡�X�i
    change_size(arr, size, new_size);
    print_arr(arr, new_size);  // ���L�s�}�C

    delete[] arr; // ������t�����s
}

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << '\n';
}

void change_size(int*& arr, int size, int new_size) {
    int* new_arr = new int[new_size];

    // �u�ƻs���p���¤j�p�ηs�j�p������
    int elements_to_copy = min(size, new_size);
    copy(arr, arr + elements_to_copy, new_arr);

    // �p�G�s�j�p��j�A�h��l�Ʒs�������s
    for (int i = elements_to_copy; i < new_size; i++) {
        new_arr[i] = 0; // �Ϊ̧A�i�H��ܨ�L�q�{��
    }

    delete[] arr; // �����¤��s
    arr = new_arr; // ���s��ȫ��w
}
