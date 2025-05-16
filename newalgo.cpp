#include <iostream>
#include <vector>

int main() {
    // Starter list
    std::vector<int> numbers = {12, 5, 8, 3, 15, 1, 6};

    // Print list before sorting
    std::cout << "Before sorting: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    <light>// Selection sort algorithm </light>
    for (size_t i = 0; i < numbers.size(); ++i) {
        // Assume the current index i holds the smallest value
        size_t minIndex = i;

        // Check the rest of the array for a smaller value
        for (size_t j = i + 1; j < numbers.size(); ++j) {
            if (numbers[j] < numbers[minIndex]) {
                minIndex = j;  // Found new minimum, update minIndex
            }
        }

        // Swap the smallest element found with element at position i
        std::swap(numbers[i], numbers[minIndex]);
    }

    // Print list after sorting
    std::cout << "After sorting: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}
