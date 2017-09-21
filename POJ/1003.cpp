#include <iostream>

int binarySearch(const double array[], int left, int right, double target) {
    // 二分查找大于等于target的下标
    int L = left, R = right;
    int mid = 0;
    if (target > array[R])return -1;
    while (L < R) {
        mid = (L + R) / 2;
        if (array[mid] < target) {
            L = mid + 1;
        } else {
            R = mid;
        }
    }

    // 返回左边界
    return L;
}

int main() {
    double length = 0;
    const int count = 100000;
    double *sum = new double[count];
    sum[0] = 0;
    // 先打表
    for (int i = 1; i < count; ++i) {
        sum[i] = sum[i - 1] + 1.0 / (i + 1);
    }
    // 处理数据
    while ((std::cin >> length), length != 0) {
        std::cout << binarySearch(sum, 1, count - 1, length) << " card(s)\n";
    }

    delete[] sum;

    return 0;
}

