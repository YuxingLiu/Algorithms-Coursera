# Algorithm-Part2-Week3
Heaps, balanced binary search trees.

## Problem 1
The goal of this problem is to implement the "Median Maintenance" algorithm (covered in the Week 3 lecture on heap applications). The text file [Median.txt](https://github.com/YuxingLiu/Algorithms-Coursera/blob/master/Part2-Week3/Median.txt) contains a list of the integers from 1 to 10000 in unsorted order; you should treat this as a stream of numbers, arriving one by one. Letting x_i denote the i-th number of the file, the k-th median m_k is defined as the median of the numbers x_1,...,x_k. (So, if k is odd, then m_k is ((k+1)/2)th smallest number among x_1,...,x_k; if k is even, then m_k is the (k/2)(k/2)th smallest number among x_1,...,x_k.)

In the box below you should type the sum of these 10000 medians, modulo 10000 (i.e., only the last 4 digits). That is, you should compute (m1+m2+m3+⋯+m10000)mod10000.

OPTIONAL EXERCISE: Compare the performance achieved by heap-based and search-tree-based implementations of the algorithm.
