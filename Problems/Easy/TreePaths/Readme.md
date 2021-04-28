Tree Paths
==========

	Goal
	
	You are given a binary tree, where each node in the tree has two or zero children. If a node X has two children, they are called L Left & R Right children respectively. **X is a Parent of L and R**

	All trees have one root node, which is the only node without parent. All the other nodes have exactly one parent.

	All tree nodes have assigned a unique number called index.
	Given a tree and an index V, print the path from the root to the tree node with index V

	A tree path starts at the root node, and it goes down by choosing the left or the right children until it arrives to the target value. Print the Left & Right elements from the path in a single line.

	For instance, if we have the following tree.


					     1
					    / \
					   /   \
					  2     \
					 / \     3
					4   5   / \
					       9   \
						    8
						   / \
						  6   7


	For this sample tree, Node 1 is the root, the only one without parents.
	if V = 5, the Tree Path is Left Right
	if V = 7, the Tree Path is Right Right Right
	if V = 6, the Tree Path is Right Right Left
