* In search, in the realm of comparisons, we cannot get much faster than O(log(n)) with a binary search tree.
* However, there are ways to find things without comparing at all. One of these is the Hash Table.
* If you never compare anything at all, the time frame to find something becomes a constant. (Independent of N)

### When to use what search
1. A linear comparison should almost never be used, but it is fine for less than 100 items
2. For Binary Search Trees, they are strongly used in databases, and can be effectively used if there are less than 10^6 items
3. A hash table should be used when there are more than 10 * 10^6 items to compare, as they have constant time values to search

## Hash Tables
<html>
    <table>
        <tr>
        <th>Key</th>
        <th>Value</th>
        </tr>
        <tr>
        <td>"0"</td>
        <td>Input 1, Input 2, Input 3</td>
        </tr>
    </table>
</html>

* To make a hash, you take all of our input and make it go through a hashing function.
#### (input) --> H(x) --> key --> "slot" in hash table --> input is placed
* H(x) has a constant processing time to create your key from an input.

## Properties of a Hashing Function
1. A hashing function must produce the same key for the same input
2. Small deviations in the input should create a large deviation in the key
3. The hashing function should be computationally inexpensive to use
4. A load factor = <html>&lambda;</html> is a good way to measure the effectiveness of a hash table
    * <html>&lambda;</html> = M (# of slots occupied) / N (size of table)



* If multiple inputs get placed in the same key of a hash function, the function undergoes "Collision"

### Collision Techniques
1. Duplication
    * If there is a collision, create a new Hash Table
    * During lookup, beyond figuring out the key, there is now a level of comparisons.
        * Typically less than 10.
2. Separate Chaining
    * Grow outward when there is a collision
    * It creates a Linked List at each value of the hash table and creates a linear search within the key of the table.
3. Linear Probing
    * When there is collision, it looks into the current hash table for empty slots, hoping to find an empty slot to insert the item into the hash table without chaining.
    * When redoing the lookup, it also goes through a linear probing technique. A name will have a different slot than its original key, so it will search down the list until it finds the name or an empty slot.
4. Quadratic Probing
    * Similar to linear probing, but becomes more and more aggressive with how far you are able to go from the slot that causes collisions.
    * Acts as a linear probing but with a weighted value towards the distance that it travels away from the cluster.
        * i^2 slots away with i growing
    
