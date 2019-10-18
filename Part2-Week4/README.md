# Algorithm-Part2-Week4
Hash table, Bloom filter.

## Problem 1
The goal of this problem is to implement a variant of the 2-SUM algorithm covered in this week's lectures.

The file [prob-2sum.txt](https://d18ky98rnyall9.cloudfront.net/_6ec67df2804ff4b58ab21c12edcb21f8_algo1-programming_prob-2sum.txt?Expires=1571529600&Signature=DVqOfo8NDn-iaGDj4wFfvonZmdTQIhK3nv~ZWpcxizaELcKSgyhME7Jyyvg2L8Ae6hta2XHgfkm6AoD~mkwQfUa7~-i56OkgKu-oQoAgoyBmgFc~0FLp571AhkL4-G~85UlLrQn90AHmR4GAKhPif8TCluu4VCC6WXvTeNo62UQ_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A) contains 1 million integers, both positive and negative (there might be some repetitions!).This is your array of integers, with the i-th row of the file specifying the i-th entry of the array.

Your task is to compute the number of target values t in the interval [-10000,10000] (inclusive) such that there are distinct numbers x,y in the input file that satisfy x+y=t. (NOTE: ensuring distinctness requires a one-line addition to the algorithm from lecture.)

Write your numeric answer (an integer between 0 and 20001) in the space provided.

OPTIONAL CHALLENGE: If this problem is too easy for you, try implementing your own hash table for it. For example, you could compare performance under the chaining and open addressing approaches to resolving collisions.
