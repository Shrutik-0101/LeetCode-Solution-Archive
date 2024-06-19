# Process
# The problem revolves around transforming a Binary Search Tree (BST) into a Greater Sum Tree (GST).

# Binary Search Tree (BST):
# A BST is a binary tree where for each node, its left subtree contains only nodes with values less than the node's value, and its right subtree contains only nodes with values greater than the node's value.

# Greater Sum Tree (GST):
# In a GST, each node's value is replaced with the sum of all node values greater than or equal to its own value.

# The problem involves manipulating a BST such that each node is replaced with the sum of all nodes greater than or equal to it.
# By leveraging reverse in-order traversal and maintaining a cumulative sum, we efficiently transform the tree as required.

# Solution
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.sum = 0
        self.reverse_inorder(root)
        return root
    
    def reverse_inorder(self, node: TreeNode):
        if node:
            # Traverse right subtree first
            self.reverse_inorder(node.right)
            
            # Process current node
            self.sum += node.val
            node.val = self.sum
            
            # Traverse left subtree
            self.reverse_inorder(node.left)
