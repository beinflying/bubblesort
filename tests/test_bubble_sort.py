import unittest
import sys
import os

# 添加src目录到路径
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', 'src'))

from algorithms.bubble_sort import bubble_sort, bubble_sort_inplace


class TestBubbleSort(unittest.TestCase):
    """测试冒泡排序算法"""

    def test_empty_list(self):
        """测试空列表"""
        self.assertEqual(bubble_sort([]), [])

    def test_single_element(self):
        """测试单元素列表"""
        self.assertEqual(bubble_sort([5]), [5])

    def test_already_sorted(self):
        """测试已排序列表"""
        self.assertEqual(bubble_sort([1, 2, 3, 4, 5]), [1, 2, 3, 4, 5])

    def test_reverse_sorted(self):
        """测试逆序列表"""
        self.assertEqual(bubble_sort([5, 4, 3, 2, 1]), [1, 2, 3, 4, 5])

    def test_random_order(self):
        """测试随机顺序列表"""
        self.assertEqual(bubble_sort([3, 1, 4, 1, 5, 9, 2, 6]),
                         [1, 1, 2, 3, 4, 5, 6, 9])

    def test_duplicates(self):
        """测试重复元素"""
        self.assertEqual(bubble_sort([3, 3, 1, 1, 2, 2]), [1, 1, 2, 2, 3, 3])

    def test_negative_numbers(self):
        """测试负数"""
        self.assertEqual(bubble_sort([-5, 3, -2, 0, 1]),
                         [-5, -2, 0, 1, 3])

    def test_float_numbers(self):
        """测试浮点数"""
        result = bubble_sort([3.14, 2.71, 1.618, 0.577])
        expected = [0.577, 1.618, 2.71, 3.14]
        self.assertEqual(result, expected)

    def test_inplace_sort(self):
        """测试原地排序"""
        arr = [5, 4, 3, 2, 1]
        bubble_sort_inplace(arr)
        self.assertEqual(arr, [1, 2, 3, 4, 5])

    def test_inplace_does_not_create_copy(self):
        """测试原地排序不创建新列表"""
        arr = [3, 1, 2]
        original_id = id(arr)
        bubble_sort_inplace(arr)
        self.assertEqual(id(arr), original_id)

    def test_original_list_unchanged(self):
        """测试原列表不被修改（非原地版本）"""
        original = [5, 4, 3, 2, 1]
        original_copy = original.copy()
        bubble_sort(original)
        self.assertEqual(original, original_copy)


if __name__ == '__main__':
    unittest.main()
