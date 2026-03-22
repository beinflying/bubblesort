#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

/**
 * 冒泡排序算法（原地排序）
 *
 * 时间复杂度: O(n²)
 * 空间复杂度: O(1)
 *
 * @param arr 待排序的数组
 * @param n   数组长度
 */
void bubble_sort(int *arr, int n);

/**
 * 打印数组
 *
 * @param arr 待打印的数组
 * @param n   数组长度
 */
void print_array(const int *arr, int n);

#endif // BUBBLE_SORT_H
