# Description

This folder contains the implementation of a generic tree.

> ### What is a generic tree?
> A generic tree is a tree in which each node can have multiple
> subtrees and not only two like in the binary ones.
>
>
> ### What about the implementation?
> There are many different possible implementations, this 
> are the most common ones:
> 1. Vector of children:
>   - Reference to the parent node
>   - Vector of children
>   - Item of that node
>   - When to use: few children. 
> 2. First child, next sibiling:
>   - Pointer to the parent tree
>   - Pointer to the leftmost child
>   - Pointer to the next sibiling
>   - Value that needs to store
> 3. Vector of parents
>
> **In the directory is presented the second solution**

## Functions:
1. tree init(int) -> create a tree with an item v
2. void read() -> read the item stored in the tree
3. void write(tree,int) -> write or subwrite the item stored in the tree
4. tree parent(tree) -> return the parent of this three
5. **tree leftmostchild(tree) -> return the leftmost child of this three**
6. **tree rightsibiling(tree) -> return the sibiling on the right**
7. void insertchild(tree) -> insert a tree as a child, the old child  will be considered sibiling of the new child
8. void insertsibiling(tree, tree) -> insert a tree as a sibiling, this will be the first sibiling of t1, the old sibiling will be the sibiling of t2
9. void deletechild(tree) -> delete the leftmost child (not all the subtrees) if he has sibiling this are preserved
10. deletesibiling(tree) -> delete the sibiling on the right
11. deletetree(tree)-> delete the tree and all the subtrees
12. depthfirstsearch()
13. breadthfirstsearch()