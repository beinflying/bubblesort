def bubble_sort(arr):
    """
    冒泡排序算法

    时间复杂度: O(n²)
    空间复杂度: O(1)

    Args:
        arr: 待排序的列表

    Returns:
        排序后的列表
    """
    n = len(arr)
    # 创建副本以避免修改原列表
    result = arr.copy()

    for i in range(n):
        # 优化: 如果这一轮没有交换，说明已经有序
        swapped = False

        # 每一轮将最大的元素"冒泡"到末尾
        for j in range(0, n - i - 1):
            if result[j] > result[j + 1]:
                result[j], result[j + 1] = result[j + 1], result[j]
                swapped = True

        # 如果没有发生交换，提前退出
        if not swapped:
            break

    return result


def bubble_sort_inplace(arr):
    """
    冒泡排序算法（原地排序）

    时间复杂度: O(n²)
    空间复杂度: O(1)

    Args:
        arr: 待排序的列表（会被原地修改）
    """
    n = len(arr)

    for i in range(n):
        swapped = False

        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True

        if not swapped:
            break
