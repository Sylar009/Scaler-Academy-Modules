/*
Problem Description

You are given an array A of integers that represent the lengths of ropes.




You need to connect these ropes into one rope. The cost of joining two ropes equals the sum of their lengths.

Find and return the minimum cost to connect these ropes into one rope.






Problem Constraints

1 <= length of the array <= 100000
1 <= A[i] <= 1000



Input Format

The only argument given is the integer array A.



Output Format

Return an integer denoting the minimum cost to connect these ropes into one rope.



Example Input

Input 1:

 A = [1, 2, 3, 4, 5]
Input 2:

 A = [5, 17, 100, 11]


Example Output

Output 1:

 33
Output 2:

 182


Example Explanation

Explanation 1:

 Given array A = [1, 2, 3, 4, 5].
 Connect the ropes in the following manner:
 1 + 2 = 3
 3 + 3 = 6
 4 + 5 = 9
 6 + 9 = 15

 So, total cost  to connect the ropes into one is 3 + 6 + 9 + 15 = 33.
Explanation 2:

 Given array A = [5, 17, 100, 11].
 Connect the ropes in the following manner:
 5 + 11 = 16
 16 + 17 = 33
 33 + 100 = 133

 So, total cost  to connect the ropes into one is 16 + 33 + 133 = 182.

*/

class Heap {
    int * heap;
    int heap_size;
    int heap_capacity;

    public:
    Heap() {
        heap_size = 0;
        heap_capacity = 0;
        heap = nullptr;
    }

    Heap(int val) {
        heap_size = 0;
        heap_capacity = val;
        heap = new int[val];
    } 

    void insert_val(int val) {
        if (heap_size == heap_capacity) return;

        heap[heap_size++] = val;

        int idx = heap_size - 1;
        int parent_idx = (idx-1) >> 1;

        while (idx > 0 && heap[idx] < heap[parent_idx]) {
            swap(idx, parent_idx);
            idx = parent_idx;
            parent_idx = (idx - 1) >> 1;
        }
     }

    void delete_min() {
        heap[0] = heap[heap_size-1];
        heap[heap_size-1] = -1;
        heap_size--;

        int idx = 0;
        while (2*idx + 1 < heap_size) {
            int left_child = (2 * idx) + 1;
            int right_child = (2 * idx) + 2;

            int min_val = min(heap[idx], heap[left_child]);
            min_val = (right_child < heap_size) ? min(min_val, heap[right_child]) : min_val;

            if (min_val == heap[left_child]){
                swap(idx, left_child);
                idx = left_child;
            }
            else if (right_child  < heap_size && min_val == heap[right_child]) {
                swap(idx, right_child);
                idx = right_child;                
            }
            else break;
        }
    }
    void swap (int x, int y) {
        heap[x] = heap[x] + heap[y];
        heap[y] = heap[x] - heap[y];
        heap[x] = heap[x] - heap[y];
    }

    int get_min() { 
        return heap[0];
    }

    int get_size() {
        return heap_size;
    }

    bool is_empty() {
        return (heap_size == 0);
    }
};

int Solution::solve(vector<int> &A) {
    int min_rope_len = 0;
    int rope_count = A.size();

    Heap ropes(A.size());

    for (int i =0; i < rope_count; i++) ropes.insert_val(A[i]);

    while (rope_count-- > 1) {
        int first_rope_len = ropes.get_min();
        ropes.delete_min();
        int second_rope_len = ropes.get_min();
        ropes.delete_min();

        min_rope_len += first_rope_len + second_rope_len;

        ropes.insert_val(first_rope_len + second_rope_len);
     }

     return min_rope_len;
}
