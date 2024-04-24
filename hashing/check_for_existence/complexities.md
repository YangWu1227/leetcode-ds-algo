# Hash Map Interface

## C++

```c++
#include <unordered_map>
#include <iostream>

unordered_map<int, int> hashMap;

// Initialize it with some key value pairs
unordered_map<int, int> hashMap = {{1, 2}, {5, 3}, {7, 2}};

// Checking if a key exists: use the following syntax
hashMap.find(1) != hashMap.end(); // true
hashMap.find(9) != hashMap.end(); // false
// New addition from C++ 20
hashMap.contains(1); // true
hashMap.contains(9); // false

// Accessing a value given a key
hashMap[5]; // 3

// Access a key that does not exist creates the key with a default value of 0
hashMap[342]; // 0

// Adding or updating a key
// If the key already exists, the value will be updated
hashMap[5] = 6;

// If the key doesn't exist yet, the key value pair will be inserted
hashMap[9] = 15;

// Deleting a key: use the .erase() method
hashMap.erase(9);

// Get size
hashMap.size(); // 3

// Iterate over the key value pairs: .first gets the key and .second gets the value
for (auto const& pair: hashMap) {
    std::cout << pair.first << " " << pair.second << std::endl;
}
```

## Python

```python
hash_map = {}

# Initialize it with some key value pairs
hash_map = {1: 2, 5: 3, 7: 2}

# Checking if a key exists
1 in hash_map # True
9 in hash_map # False

# Accessing a value given a key
hash_map[5] # 3

# Access a key that does not exist raises a KeyError
hash_map[342] # KeyError

# Adding or updating a key
# If the key already exists, the value will be updated
hash_map[5] = 6

# If the key doesn't exist yet, the key value pair will be inserted
hash_map[9] = 15

# Deleting a key
del hash_map[9]

# Get size
len(hash_map) # 3

# Iterate over the key value pairs
for key, value in hash_map.items():
    print(key, value)

# Just the keys
for key in hash_map:
    print(key)

# Comprehension to get just the values
{key: hash_map[key] for key in hash_map}
```

---

# Two Sum

Given an array of integers `nums` and an integer `target`, return indices of two numbers such that they add up to `target`. We cannot use  the same index twice.

We may assume that each input would have exactly one solution.

## Time Complexity

There are two ways to implement this problem:

### One pass hash table

In one pass hash table, we iterate through the array and check if the complement of the current element exists in the hash table, i.e. `target - nums[i]`. If it does, we return the indices of the current element and the complement. If it doesn't, we add the current element to the hash table.

We iterate through the array once and each insertion and look up in the hash table costs $O(1)$ average. Therefore, the overall time complexity is $O(2n) = O(n)$.

### Two pass hash table

In two-pass hash table, we iterate through the array and build a hash table that maps the elements to their indices. Because insertion have have a time complexity of $O(1)$, the time complexity of building the hash table is $O(n)$.

We then iterate through the array and check if the complement of the current element exists in the hash table, i.e. `target - nums[i]`. If it does, we return the indices of the current element and the complement. This has a time complexity of $O(n)$ since each look up in the hash table costs $O(1)$ average.

The overall time complexity is $O(n + n) = O(2n) = O(n)$.

## Space Complexity

The space complexity of both approaches is $O(n)$ since we store the elements of the array in the hash table.

---

# First Letter to Appear Twice

Given a string `s`, return the first letter that appears twice in the string. We can assume that each input would have exactly one solution.

## Time Complexity

The time complexity of this approach is $O(n)$ where $n$ is the length of the string. We iterate through the string once and check if the current character has already appeared in the hash table. 

Regardless of whether we use a set or a hash map, the time complexity of insertion and look up is $O(1)$ average. Therefore, the overall time complexity is $O(n)$.

## Space Complexity

The space complexity of this approach is $O(n)$ since we store the characters of the string in the hash table.

For sets, the space complexity is $O(n)$; at worst, we store all the characters of the string in the set.