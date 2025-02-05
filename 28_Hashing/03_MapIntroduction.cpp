/*
    In C++, `unordered_map` and `map` are two different types of associative containers that store key-value pairs, but they differ in terms of implementation, performance, and ordering.

    1. Implementation
      - `map`: Implemented using Red-Black Tree (Self-Balancing Binary Search Tree).
      - `unordered_map`: Implemented using Hash Table.

    2. Ordering
      - `map`: Stores elements in sorted order based on the key (ascending by default).
      - `unordered_map`: Stores elements in no particular order.

    3. Time Complexity
      +-----------------------------------------------------------------------------------------------+
      | Operation  | `map` (RB Tree) | `unordered_map` (Hash Table)                                   |
      |------------|-----------------|----------------------------------------------------------------|
      | Insert     | O(log N)        | O(1) (Average), O(N) (Worst Case - when hash collisions occur) |
      | Erase      | O(log N)        | O(1) (Average), O(N) (Worst Case)                              |
      | Search     | O(log N)        | O(1) (Average), O(N) (Worst Case)                              |
      +-----------------------------------------------------------------------------------------------+

      - `unordered_map` generally provides faster access than `map` because hash table operations are on average O(1), whereas `map` operations are O(log N).
      - Worst-case in `unordered_map` occurs when multiple keys hash to the same index, causing collisions.

    4. Memory Usage
      - `map` requires less memory because it only stores tree nodes.
      - `unordered_map` consumes more memory due to hash table overhead.

    5. Use Cases
      - Use `map` when ordering is required (e.g., maintaining sorted keys).
      - Use `unordered_map` when fast lookup is needed and ordering is not required.

    Conclusion
    - Use `map` when ordering matters.
    - Use `unordered_map` when performance (O(1) lookup) is a priority.
    
*/