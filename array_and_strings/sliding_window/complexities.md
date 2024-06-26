# Psuedocode For Sliding Window

<div style="text-align: center;">
    <img src="diagrams/sub_arrays.png" width="525" height="270">
</div>

## Dynamic Window Size

```
function fn(arr):
    left = 0
    for (int right = 0; right < arr.length; right++):
        Do some logic to "add" element at arr[right] to window

        while WINDOW_IS_INVALID:
            Do some logic to "remove" element at arr[left] from window
            left++

        Do some logic to update the answer
```

## Fixed Window Size

```
function fn(arr, k):
    curr = some data to track the window

    // build the first window
    for (int i = 0; i < k; i++)
        Do something with curr or other variables to build first window

    ans = answer variable, probably equal to curr here depending on the problem
    for (int i = k; i < arr.length; i++)
        Add arr[i] to window
        Remove arr[i - k] from window
        Update ans

    return ans
```

## Efficiency

For any array withe length `n`, there are 

1. `n` subarrays of length 1
2. `n - 1` subarrays of length 2
3. `n - 2` subarrays of length 3
...
4. `1` subarray of length `n`

The total number of subarrays is:

$$
\sum_{k=1}^{n}k=\frac{n(n+1)}{2}
$$

A sliding window algorithm guarantees a maximum of $2n$ window iterations. The right pointer can move at most `n` times, and the left pointer can move at most `n` times. This means that if the logic inside each window iteration is efficient, $O(1)$, then the total time complexity of the algorithm is $O(n) + O(n) = O(2n) = O(n)$.

This algorithm employs a `for` loop and a nested `while` loop. At first glance, the presence of these loops might suggest a quadratic time complexity, $O\left(n^2\right)$. However, due to the specific behavior of the `while` loop, the actual complexity is linear, $O(n)$. This is because the `while` loop's total number of iterations across the entire algorithm is capped at $n$, not $n$ per for loop iteration.

```
for (int right = 0; right < arr.length; right++):

    Do some logic to "add" element at arr[right] to window

    while WINDOW_IS_INVALID:

        Do some logic to "remove" element at arr[left] from window
        left++
```

The overall complexity of the algorithm is $O(n)$, not $O\left(n^2\right)$, because the key insight of amortized analysis is recognizing that high-cost operations in some iterations (e.g. `while` loop runs $n$ iterations for a single iteration of the `for`) are balanced by lower-cost operations in others (e.g., for all other iterations of `for`, the `while` will not run at all), leading to a lower average cost per operation across the algorithm's total runtime.

---

# Length of Longest Subarray

 Given an array of positive integers `nums` and an integer `k`, find the length of the longest subarray whose sum is less than or equal to `k`. 

## Time Complexity

This algorithm has a time complexity of $O(n)$, because the operations inside the `for` loop and the `while` loop are $O(1)$.

## Space Complexity

The space complexity is constant because we are only using integer variables to store the left and right pointers, the sum of the current window, and the maximum length of the subarray.

---

# Length of Consecutive 1's Single Flip

Given a binary string `s` (a string containing only "0" and "1"). You may choose up to one "0" and flip it to a "1". Find the length of the longest substring achievable that contains only "1". Another way to look at this problem is to find the longest substring that contains at most one 0. 

For example, given `s = "1101100111"`, the answer is 5. If we flip the element at index 2, the string becomes "1111100111".

Considering this problem as finding the longest substring that contains at most one 0 makes it easy to solve the problem with a sliding window. The constraint metric and numeric restriction combined to be `window.count("0") <= 1`. We can use an integer variable to keep track of how many "0" we currently have in our window.

## Time Complexity

The time complexity of this algorithm is amortized $O(n)$, because the operations inside the `for` loop and the `while` loop are $O(1)$. The while loop will run at most `n` times across the entire algorithm, not `n` times per iteration of the `for` loop.

## Space Complexity

The space complexity is constant because we are using only integer variables to store the pointers, the count of zeros in the current window, and the maximum length of the subarray.

---

# Subarray Product Less Than K

Given an array of positive integers `nums` and an integer `k`, return the number of subarrays where the product of all the elements in the subarray is strictly less than `k`.

For example, given the input `nums = [10, 5, 2, 6]`, `k = 100`, the answer is `8`. The subarrays with products less than k are:

```
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
```

In the context of the sliding window algorithm, for a current window defined by indices `(left, right)`, the number of valid sub-windows that end at index `right` is determined by the position of the `left` index. Given that the window can be adjusted to start from any index between `left` and `right` inclusive, the total number of valid windows ending at `right` is equal to the length of the window, calculated as `right - left + 1`. This accounts for all possible starts from `left` to `right`, including the window consisting of just the element at `right`.

## Example 1

- Array: `[4, 7, 1, 2, 5]`, examining the window ending at index `4` (`right = 4`).
- `left` can range from `0` to `4`, inclusive.
- Total valid windows ending at index `4`: `5` (`right - left + 1` = `4 - 0 + 1`).
- The valid windows are: `[4, 7, 1, 2, 5]`, `[7, 1, 2, 5]`, `[1, 2, 5]`, `[2, 5]`, `[5]`.

## Example 2

- Array: `[2, 1, 5]`, examining the window ending at index `2` (`right = 2`).
- For window ending at index `2`: `3` (`right - left + 1` = `2 - 0 + 1`).
- The valid windows are: `[2, 1, 5]`, `[1, 5]`, `[5]`.

## Time Complexity

Again, because the work in each `for` and `while` loop iteration is constant $O(1)$, the overall time complexity of this algorithm is amortized $O(n)$, where $n$ is the length of the input array.

## Space Complexity

The space complexity is constant because we are using only integer variables to store the pointers, the product of the current window, and the count of valid subarrays.

---

# Largest Sum of Subarray with Length K

Given an integer array `nums` and an integer `k`, find the sum of the subarray with the largest sum whose length is `k`.

## Time Complexity

The time complexity of this algorithm is $O(n)$. The first loop to construct the fist window is $O(k)$, and the second loop to slide the window is $O(n - k)$. The total time complexity is $O(k) + O(n - k) = O(n)$.

## Space Complexity

The space complexity is constant because we are using only integer variables to store the pointers, the sum of the current window, and the maximum sum of the subarray.

---

# Largest Average of Subarray with Length K

Given an integer array `nums` consisting of `n` elements, and an integer `k`. Find a contiguous subarray whose length is equal to `k` that has the maximum average value and return this value.

## Time Complexity

The time complexity of this algorithm is $O(n)$, since the two loops at most iterate through the entire array $O(k) + O(n - k) = O(n)$.

## Space Complexity

The space complexity is constant for the same reasons as the previous examples.

---

# Length of Consecutive 1's with K Flips

Given a binary array `nums`, you can perform at most `k` flips. Return the maximum number of consecutive 1's in the array after performing at most `k` flips.

<div style="text-align: center;">
    <img src="diagrams/longest_ones_k_flips-transformed.png" width="350" height="500">
</div>

## Time Complexity

Similar to the problem where we can flip at most one zero, the time complexity of this algorithm is amortized $O(n)$. The operations inside `while` is $O(1)$, and the total number of iterations across the entire algorithm for the `while` is capped at $n$, not $n$ per iteration of the `for` loop. 

## Space Complexity

The space complexity is constant for the same reasons as the previous examples.

---

# Minimum Size Subarray Sum

Given an array of positive integers `nums` and a positive integer `target`, return the minimal length of a subarray whose sum is greater than or equal to `target`. If there is no such subarray, return 0 instead.

## Approach using Sliding Window (Dynamic Window Size)

Initialize `left` pointer to `0` and `curr_sum` to `0`.
Iterate over the `nums`:
- Add `nums[right]` to `sum`.
- While `sum` is greater than or equal to `target` (i.e. the window is valid):
  - Update `window_len` = `min(window_len, right - left + 1)`, where `right - left + 1` is the size of the current window. This means that the left index can now safely be incremented. It is no longer possible to find a even smaller window starting at this `left` index that will have a sum greater than or equal to `target`.
  - Subtract `nums[left]` from `curr_sum` (i.e. this element is no longer a part of the current window) and increment `left`.
  
## Time Complexity

The time complexity of this algorithm is $O(n)$; we iterate through `nums` using the `for` loop. The `while` loop inside can run at most `n` times. Each element is visited at most twice, once by the right pointer and once by the left pointer.

## Space Complexity

The space complexity is constant since the variables we use do not change with the size of the input.

--- 

# Maximum Number of Vowels in a Substring of Given Length

Given a string `s` and an integer `k`, return the maximum number of vowel letters in any substring of `s` with length `k`.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

## Time Complexity

### Python

1. We have a $O(n)$ operation to convert the string to a list of characters
2. The first loop to construct the first window is $O(k)$, where $k$ is the length of the substring
3. The second loop to slide the window is $O(n - k)$
4. The set operation to check if a character is a vowel is $O(1)$ on average (not worst-case)

Thus, the total time complexity is $O(n) + O(k) + O(n - k) = O(n + k + n - k) = O(2n) = O(n)$.

### C++

1. We have a $O(z)$ operation (i.e. `for` loop) to create a set of vowels, where $z$ is the number of vowels.
2. The first loop to construct the first window is $O(k)$.
3. The second loop to slide the window is $O(n - k)$.

The total time complexity is $O(z) + O(k) + O(n - k) = O(z + k + n - k) = O(z + n) = O(n)$.

## Space Complexity

Outside of the variables and pointers we use, the space complexity is determined by the space used to store the vowels.

### Python

The space complexity of the set used to store the vowels is $O(z)$ where $z$ is the number of vowels. We also use a list to store the characters of the string, which is $O(n)$. The space complexity is $O(n + z)=O(n)$.

### C++

We use a boolean array to store the vowels, which is $O(z)$. Finally, unlike python, we can iterate, i.e., index over the string directly, so the space complexity is just the array used to store the vowels: $O(z)$.

---

# Get Equal Substrings Within Budget

Given two strings `s` and `t` of the same length and an integer `max_cost`, change `s` to `t`, change `s` to `t`. 

Changing the ith character of `s` to ith character of `t` costs `|s[i] - t[i]|` (i.e., the absolute difference between the ASCII values of the characters). 

Return the maximum length of a substring of `s` that can be changed to be the 
same as the corresponding substring of `t` with a cost less than or equal to `max_cost`. If there is no substring from `s` that can be changed to its corresponding substring from `t`, return 0.

## Examples

```
Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd".
That costs 3, so the maximum length is 3.
```

```
Input: s = "abcd", t = "cdef", maxCost = 3
Output: 1
Explanation: Each character in s costs 2 to change to character in t,  so the maximum length is 1.
```

```
Input: s = "abcd", t = "acde", maxCost = 0
Output: 1
Explanation: Not possible to make any change, so the maximum length is 1.
```

## Time Complexity

### Python

In python, we have two $O(n)$ operations to convert `s` and `t` to lists of characters. 

Then, the `for` loop and the nested `while` loop inside perform the sliding window. The amortized time complexity for the sliding window is $O(n)$. All operations inside the `for` and `while` loops are $O(1)$.

The total time complexity is $O(n) + O(n) + O(n) = O(3n) = O(n)$.

### C++

In C++, there is no need to convert the strings to lists of characters. The amortized time complexity is $O(n)$, for the same reason as in the python implementation.

## Space Complexity

The space complexity is constant for the same reasons as the previous examples. However, in python, if we consider the lists used to store the characters of the strings `s` and `t`, then the space complexity is $O(n) + O(n) = O(2n) = O(n)$.

---

# K Radius Subarray Averages

The k-radius average for a subarray of `nums` centered at index `i` with the radius `k` is the average of all elements in `nums` between the indices `i - k` and `i + k` (inclusive). If there are less than `k` elements before or after the index `i`, then the k-radius average is `-1`. Build and return an array `avgs` of length `n` where `avgs[i]` is the k-radius average for the subarray centered at index `i`.

<div style="text-align: center;">
    <img src="diagrams/k_radius_avg.png" width="500" height="170">
</div>

In the above example:

1. The k-radius average for index `1` is -1, since there are less then `k = 2` elements before it.
2. The k-radius average for index `2` is 2.5, since the subarray is `[2, 1, 3, 4, 5]` and the average is `(2 + 1 + 3 + 4 + 5) // 5 = 3`.

So on and so forth.

## Time Complexity

This algorithm can also be solved by first building a prefix sum. In terms of time complexity, both approaches--- sliding window and prefix sum--- have a time complexity of $O(n)$.

In both Python and C++, we have the following operations:

1. Initialize the `avg` array with -1s, which costs $O(n)$
2. Build the first window by summing and taking the average of the first `2k + 1` elements, which costs $O(2k + 1) = O(k)$
3. Slide the window across the array; since we only iterate over elements that have `k` elements before and after them, the time complexity is $O((n - k) - (k + 1))=O(n - 2k - 1)=O(n - k)$

The total time complexity is $O(n) + O(k) + O(n - k) = O(2n) = O(n + k + n - k) = O(2n) = O(n)$.

## Space Complexity

Compared to the prefix sum approach, if we do not include the output array, the space complexity is constant, $O(1)$. This is because the sliding window approach does not require any additional space to store the prefix sum.
