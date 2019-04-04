## Non-Linear Structures
Non-Linear Structures have nodes that point to more than one node. It acts like a tree structure or a graph.
A graph is a non-linear data structure that consists of nodes and edges. Graphs are used to solve real-life network problems, be it circuits, telephone networks, or social media networks.

### Linear Structure
```
class Node{
    int value;
    Node *next;
}
```

### Non-Linear Structure
```
class TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;
}
```

The very first node created is called the "root" node.
The very last line of nodes are called "leaf" nodes.
All intermediate nodes between the root and leaf are "internal" nodes.

> "level" = how many hops from the root does it take to get to your node.
> "path to a node"
> parent <-> child
>
> h = max(level) = height

A balanced tree is one that:
>The constraint is generally applied recursively to every subtree. That is, the tree is only balanced if:
>
> 1. The left and right subtrees' heights differ by at most one, AND
> 2. The left subtree is balanced, AND
> 3. The right subtree is balanced

A completely balanced tree is one where the subtree does not differ in height at all from other sub-trees.
* If a node is expected to have two children, then it should have two children under every node.

Logarithmic time is the fastest way to do a function, like searching.
* Binary Search Tree (has nodes with 2 pointers)
* Tertiary Search Tree (has nodes with 3 pointers)
* n-ary Search Tree (has nodes with n pointers)

## Binary Search Tree
If a list of items is unordered, it would take O(N) time to search through the list, however if you have an ordered list O(log N)

<table>
<tr>
<th>N</th>
<th>O(N)</th>
<th>O(log N)</th>
</tr>
<tr>
<td>10</td>
<td>10</td>
<td>3</td>
</tr>
<tr>
<td>100</td>
<td>100</td>
<td>7</td>
</tr>
<tr>
<td>1,000</td>
<td>1,000</td>
<td>10</td>
</tr>
<tr>
<td>10,000</td>
<td>10,000</td>
<td>14</td>
</tr>
<tr>
<td>1,000,000</td>
<td>1,000,000</td>
<td>20</td>
</tr>
</table>

Creating a Tree Structure
> 15 17 19 12 1 0 2 23 94 -1 13 11 10
> 1. Starts with a root of 15, with a node for greater and a node for less than.
> 2. 17 comes next and goes within the node that signifies greater than 15.
> 3. 19 comes next and goes within the node that signifies it is greater than 15 and 17.
> 4. 12 comes next and goes within the node that signifies less than 15.


