#include <vector>

/**
 * https://www.codewars.com/kata/54521e9ec8e60bc4de000d6c/train/cpp
 * @param arr an array or list of integers
 * @return the maximum sum subarray
 */
int maxSequence(const std::vector<int> &arr) {
    int current = 0;
    int maximum = 0;

    for (int value: arr) {
        current = std::max(0, current + value);
        maximum = std::max(current, maximum);
    }

    return maximum;
}
