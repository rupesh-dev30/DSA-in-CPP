/*
    Heaps: 

    A heap is a specialized tree-based data structure that satisfies the heap property: 

      - the parent node is either greater than (in a max heap) or less than (in a min heap) its child nodes. 
    
      - Heaps are often used to implement priority queues.


      Priority Queue
        
        1. Max Heap
              Largest Value -> Top Priority (useful during marks)
        
        2. Min Heap
              Smallest Value -> Top Priority (useful during rank)


    Priority Queue(PQ) <- HEAP -> Visualize as Complete Binary Tree(CBT) -> Vector/Array 

    - CBT is Binary Tree where all levels are filled except maybe the last one, which is filled from left to right

    - PARENT >= Children  //Max Heap
    

                     9
                    / \
                   /   \
                  4     5
                 / \ 
                /   \  
               1     2

    - PARENT <= Children  //Min Heap

                     1
                    / \
                   /   \
                  2     3
                 / \ 
                /   \  
               4     5

*/