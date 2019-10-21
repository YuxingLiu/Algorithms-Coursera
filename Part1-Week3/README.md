# Algorithm-Part1-Week3
QuickSort algorithm.

# Problem 1
The file [QuickSort.txt](https://github.com/YuxingLiu/Algorithms-Coursera/blob/master/Part1-Week3/QuickSort.txt) contains all of the integers between 1 and 10,000 (inclusive, with no repeats) in unsorted order. The integer in the i-th row of the file gives you the i-th entry of an input array.

Your task is to compute the total number of comparisons used to sort the given input file by QuickSort. As you know, the number of comparisons depends on which elements are chosen as pivots, so we'll ask you to explore three different pivoting rules.

You should not count comparisons one-by-one. Rather, when there is a recursive call on a subarray of length m, you should simply add m−1 to your running total of comparisons. (This is because the pivot element is compared to each of the other m−1 elements in the subarray in this recursive call.)

The Partition subroutine can be implemented in several different ways, and different implementations can give you differing numbers of comparisons. For this problem, you should implement the Partition subroutine in the following 3 ways:

1. the first element of the given array;
2. the last element of the given array;
3. the "median-of-three" pivot rule, namely the median among first, middle and last elements.
