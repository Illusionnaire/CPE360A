# Sorting Algorithms

## Bubble Sort
* O(N^2)
* It goes through your input again and again, and with every pass it is trying to find the highest number and put the highest number in its correct place.

```
for(i=1->N-1){
    for(1->i){
        //Comparisons N^2 times
    }
}
```

## Merge Sort
* O(Nlog(N))
* Uses a divide and conquer technique
* Divide all of the numbers in half until you have each one separately
* Combine the buckets and organize them in order. This way you know that the left most number is smaller then the one to its right, so you can lower the amount of comparisons needed
* You always compare the left-most (non-compared) number in the divisions.

## Quicksort
* O(Nlog(N)) at best
* Uses a divide and conquer technique
* Pick a random number to pivot, and then break down into smaller sub-arrays with numbers greater than pivot in one, and less than pivot in other.
* Rewrite as less(left)->pivot->more(right) and you recombine the arrays, but in order.

## HeapSort
* Always O(Nlog(N))
#### Heap object within the CPU
1. Binary Tree
2. Balanced
    * A tree of depth D must have 2 children from 0->(D-2) depth
3. Left Justified
    * All leaf nodes are as far left as possible (fills from left to right)
4. "Heap Property"
    * Parent Node > Both Children Nodes

##### Steps to Fill
1. Fill up one level at a time
2. Go left to right 
3. Check heap property immediately with additions of nodes

##### Steps to Remove
1. Remove Root (Aka, biggest number)
2. Go Right to Left from bottom most leaves and replace the root with one of them to keep the tree left-justified and balanced
3. Recheck the heap property to find the new root
4. Loop through.

