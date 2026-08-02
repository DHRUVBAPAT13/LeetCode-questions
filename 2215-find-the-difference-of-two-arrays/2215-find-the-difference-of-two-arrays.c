#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    // 1. Define constraints for the offset hash array
    // Since numbers range from -1000 to 1000, we shift by 1000 (size = 2001)
    int present1[2001] = {0};
    int present2[2001] = {0};

    // 2. Mark presence of unique elements from both arrays
    for (int i = 0; i < nums1Size; i++) {
        present1[nums1[i] + 1000] = 1;
    }
    for (int i = 0; i < nums2Size; i++) {
        present2[nums2[i] + 1000] = 1;
    }

    // 3. Allocate the 2D output grid required by LeetCode
    *returnSize = 2;
    int** answer = (int**)malloc(2 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2 * sizeof(int));

    // Dynamic temporary buffers to store the filtered results
    int* res0 = (int*)malloc(nums1Size * sizeof(int));
    int* res1 = (int*)malloc(nums2Size * sizeof(int));
    int len0 = 0, len1 = 0;

    // 4. Find elements in nums1 not present in nums2
    for (int i = 0; i < nums1Size; i++) {
        int idx = nums1[i] + 1000;
        if (present1[idx] == 1 && present2[idx] == 0) {
            res0[len0++] = nums1[i];
            present1[idx] = 0; // Avoid duplicate entries in the result
        }
    }

    // 5. Find elements in nums2 not present in nums1
    for (int i = 0; i < nums2Size; i++) {
        int idx = nums2[i] + 1000;
        if (present2[idx] == 1 && present1[idx] == 0) {
            res1[len1++] = nums2[i];
            present2[idx] = 0; // Avoid duplicate entries in the result
        }
    }

    // 6. Assign sizes and structured memory blocks to the final answer
    (*returnColumnSizes)[0] = len0;
    (*returnColumnSizes)[1] = len1;
    answer[0] = res0;
    answer[1] = res1;

    return answer;
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna