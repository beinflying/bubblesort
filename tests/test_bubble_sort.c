#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../src/algorithms/bubble_sort.h"

// 测试统计
int tests_run = 0;
int tests_passed = 0;
int tests_failed = 0;

// 测试宏
#define RUN_TEST(test_func) \
    do { \
        tests_run++; \
        printf("Running: %s... ", #test_func); \
        test_func(); \
        printf("PASS\n"); \
        tests_passed++; \
    } while(0)

// 辅助函数：比较两个数组
int arrays_equal(const int *a, const int *b, int n)
{
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

// 辅助函数：复制数组
void copy_array(const int *src, int *dst, int n)
{
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

void test_empty_array(void)
{
    int arr[] = {};
    bubble_sort(arr, 0);
}

void test_single_element(void)
{
    int arr[] = {5};
    int expected[] = {5};
    bubble_sort(arr, 1);
    assert(arrays_equal(arr, expected, 1));
}

void test_already_sorted(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int expected[] = {1, 2, 3, 4, 5};
    bubble_sort(arr, 5);
    assert(arrays_equal(arr, expected, 5));
}

void test_reverse_sorted(void)
{
    int arr[] = {5, 4, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5};
    bubble_sort(arr, 5);
    assert(arrays_equal(arr, expected, 5));
}

void test_random_order(void)
{
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int expected[] = {1, 1, 2, 3, 4, 5, 6, 9};
    bubble_sort(arr, 8);
    assert(arrays_equal(arr, expected, 8));
}

void test_duplicates(void)
{
    int arr[] = {3, 3, 1, 1, 2, 2};
    int expected[] = {1, 1, 2, 2, 3, 3};
    bubble_sort(arr, 6);
    assert(arrays_equal(arr, expected, 6));
}

void test_negative_numbers(void)
{
    int arr[] = {-5, 3, -2, 0, 1};
    int expected[] = {-5, -2, 0, 1, 3};
    bubble_sort(arr, 5);
    assert(arrays_equal(arr, expected, 5));
}

void test_all_same(void)
{
    int arr[] = {5, 5, 5, 5};
    int expected[] = {5, 5, 5, 5};
    bubble_sort(arr, 4);
    assert(arrays_equal(arr, expected, 4));
}

void test_two_elements(void)
{
    int arr[] = {2, 1};
    int expected[] = {1, 2};
    bubble_sort(arr, 2);
    assert(arrays_equal(arr, expected, 2));
}

void test_large_array(void)
{
    int arr[100];
    int expected[100];

    // 填充随机值
    for (int i = 0; i < 100; i++) {
        expected[i] = i;
        arr[99 - i] = i;
    }

    bubble_sort(arr, 100);
    assert(arrays_equal(arr, expected, 100));
}

int main(void)
{
    printf("=== Bubble Sort Test Suite ===\n\n");

    RUN_TEST(test_empty_array);
    RUN_TEST(test_single_element);
    RUN_TEST(test_already_sorted);
    RUN_TEST(test_reverse_sorted);
    RUN_TEST(test_random_order);
    RUN_TEST(test_duplicates);
    RUN_TEST(test_negative_numbers);
    RUN_TEST(test_all_same);
    RUN_TEST(test_two_elements);
    RUN_TEST(test_large_array);

    printf("\n=== Test Summary ===\n");
    printf("Total:  %d\n", tests_run);
    printf("Passed: %d\n", tests_passed);
    printf("Failed: %d\n", tests_failed);

    return tests_failed > 0 ? 1 : 0;
}
