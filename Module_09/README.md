# Module_09


## `std::map` (ex 00)

In C++, `std::map` is a standard library container that stores elements in key-value pairs. It is implemented as a balanced binary tree, typically a Red-Black Tree, which ensures that the elements are always sorted by their keys. This allows for efficient insertion, deletion, and lookup operations, all of which have logarithmic time complexity, O(log n).

### Key Features of `std::map`:
- **Associative Container**: Elements are referenced by their keys, not by their position in the container.
- **Sorted Order**: Elements are always sorted by their keys.
- **Unique Keys**: Each key in a `std::map` is unique.
- **Logarithmic Complexity**: Insertion, deletion, and lookup operations are efficient, with O(log n) complexity.

### Why `std::map` for the BitcoinExchange Exercise

In the BitcoinExchange exercise, we need to store and retrieve exchange rates based on dates. The `std::map` is an ideal choice for this purpose due to the following reasons:

1. **Efficient Lookup**: We can quickly find the exchange rate for a specific date using the key (date). This is crucial for operations like checking if a date exists and retrieving the corresponding exchange rate.
2. **Sorted Order**: Since `std::map` maintains the elements in sorted order, it allows us to easily find the closest earlier date if the exact date is not present. This is useful for calculating exchange rates for dates that are not explicitly listed.
3. **Unique Dates**: Each date should have only one exchange rate, and `std::map` enforces unique keys, ensuring that no duplicate dates are stored.
4. **Logarithmic Complexity**: The logarithmic time complexity for insertion and lookup operations ensures that the program remains efficient even with a large number of dates and exchange rates.


## `std::stack` (ex01)

In C++, `std::stack` is a standard library container adapter that provides a stack (LIFO - Last In, First Out) data structure. It is typically implemented using a `std::deque` or `std::vector` as the underlying container. The `std::stack` provides a simple interface for pushing, popping, and accessing the top element.

### Key Features of `std::stack`:
- **LIFO Order**: Elements are added and removed from the top of the stack, ensuring last-in, first-out order.
- **Simple Interface**: Provides basic operations such as `push`, `pop`, `top`, `empty`, and `size`.
- **Container Adapter**: Can be implemented using different underlying containers like `std::deque`, `std::vector`, or `std::list`.

### Why `std::stack` for the RPN Exercise

In the RPN (Reverse Polish Notation) exercise, we need to evaluate mathematical expressions written in postfix notation. The `std::stack` is an ideal choice for this purpose due to the following reasons:

1. **LIFO Order**: The nature of RPN requires that the most recently encountered operands be used first in operations. The LIFO order of `std::stack` perfectly matches this requirement.
2. **Efficient Operations**: The `push` and `pop` operations are efficient and allow us to easily manage the operands as we parse through the RPN expression.
3. **Simple Interface**: The `std::stack` provides a straightforward interface to push operands onto the stack and pop them off when performing operations, making the implementation of the RPN evaluation logic simple and clear.
4. **Exception Safety**: The `std::stack` ensures that operations are exception-safe, which is crucial for handling invalid RPN expressions gracefully.


## `std::vector` and `std::deque` (ex02)

In C++, `std::vector` and `std::deque` are standard library containers that provide dynamic array and double-ended queue functionalities, respectively. Both containers are highly versatile and efficient for different types of operations.

### `std::vector`

`std::vector` is a sequence container that encapsulates dynamic size arrays. It provides fast random access to elements and efficient insertion and deletion at the end.

#### Key Features of `std::vector`:
- **Dynamic Size**: Automatically resizes as elements are added or removed.
- **Contiguous Memory**: Elements are stored in contiguous memory locations, allowing fast random access.
- **Efficient End Operations**: Insertion and deletion at the end are amortized constant time, O(1).

### `std::deque`

`std::deque` (double-ended queue) is a sequence container that allows fast insertion and deletion at both the beginning and the end. It is implemented as a dynamic array of fixed-size arrays.

#### Key Features of `std::deque`:
- **Double-Ended**: Efficient insertion and deletion at both the beginning and the end.
- **Dynamic Size**: Automatically resizes as elements are added or removed.
- **Non-Contiguous Memory**: Elements are not stored in contiguous memory locations, but still provide fast access.

### Why `std::vector` and `std::deque` for the PMergeMe Exercise

In the PMergeMe exercise, we need to sort sequences of integers using a combination of merge sort and insertion sort. Both `std::vector` and `std::deque` are ideal choices for this purpose due to the following reasons:

1. **Dynamic Size**: Both containers can dynamically resize, which is essential for handling sequences of varying lengths.
2. **Efficient Access and Modification**:
   - `std::vector` provides fast random access, which is beneficial for accessing elements during sorting.
   - `std::deque` allows efficient insertion and deletion at both ends, which can be useful for certain sorting operations.

## Ford-Johnson Merge-Insert Algorithm (ex02)
The Ford-Johnson Merge-Insert algorithm is a sorting algorithm that aims to minimize the number of comparisons, which can sometimes make it faster than traditional merge sort, especially for small sequences. However, it is typically more complex and may not always be faster in practice, depending on the implementation and the specific dataset.

### How It Works:
1. **Divide the Sequence**: The algorithm first divides the input sequence into smaller sub-sequences or pairs of elements.
2. **Sort Pairs Using Insertion Sort**: Each of these pairs is sorted using insertion sort. Insertion sort is particularly efficient for small sequences or pairs because it has a minimal number of comparisons for a small number of elements.
3. **Merge the Sorted Pairs**: After sorting the pairs, the algorithm merges them into a single sorted sequence. This is done using a method similar to merge sort but optimized to use fewer comparisons by leveraging the already partially sorted nature of the input.

### Example with Threshold 3:
Let’s take a more complex example with a threshold of 3, meaning that any sequence of three or fewer elements will be sorted using insertion sort:

Given the sequence `[8, 3, 7, 4, 2, 6, 5, 1]`, the algorithm works as follows:

1. **Divide and Conquer**:
   - Divide the sequence into sub-sequences: `[(8, 3, 7), (4, 2, 6), (5, 1)]`.
2. **Insertion Sort**:
   - Sort each sub-sequence using insertion sort:
     - `(8, 3, 7)` -> `[3, 7, 8]`
     - `(4, 2, 6)` -> `[2, 4, 6]`
     - `(5, 1)` -> `[1, 5]`
3. **Merge Sort**:
   - Merge the sorted sub-sequences together:
     - First, merge `[3, 7, 8]` and `[2, 4, 6]` -> `[2, 3, 4, 6, 7, 8]`
     - Then, merge `[2, 3, 4, 6, 7, 8]` with `[1, 5]` -> `[1, 2, 3, 4, 5, 6, 7, 8]`

The final sorted sequence is `[1, 2, 3, 4, 5, 6, 7, 8]`.

### Why the Ford-Johnson Merge-Insert Algorithm Sorts Slower with `std::deque` Compared to `std::vector`

When using the Ford-Johnson Merge-Insert algorithm to sort sequences of integers, `std::vector` often outperforms `std::deque`. The key reasons are differences in memory layout and access patterns between these two containers.

| Aspect                 | `std::deque`                                            | `std::vector`                                           |
|------------------------|---------------------------------------------------------|---------------------------------------------------------|
| Memory Layout          | Non-contiguous memory blocks                            | Contiguous memory block                                 |
| Random Access Speed    | Slower due to non-contiguous memory                     | Faster due to contiguous memory                         |
| Insertion/Deletion     | Efficient at both ends, but generally slower than `std::vector`   | Efficient at the end, faster than `std::deque`|
| Cache Performance      | Potentially worse due to scattered memory               | Better due to sequential memory access                  |

The Ford-Johnson Merge-Insert algorithm involves frequent random access to elements during merging and sorting. `std::vector` provides quicker random access because it stores elements in a contiguous block of memory, allowing for faster and more predictable retrieval times. In contrast, `std::deque` uses non-contiguous memory, leading to slower random access due to the need for additional pointer dereferencing.

Moreover, while `std::deque` is designed for efficient insertion and deletion at both ends, it typically performs these operations slower than `std::vector` because managing its non-contiguous structure adds overhead.

Finally, `std::vector` tends to have better cache performance. The contiguous memory layout allows the CPU to make better use of the cache, speeding up repeated accesses. `std::deque`, with its scattered memory, often suffers from less efficient cache usage.

In summary, `std::vector` is generally preferable over `std::deque` for the Ford-Johnson Merge-Insert algorithm due to its faster random access and better cache performance.
