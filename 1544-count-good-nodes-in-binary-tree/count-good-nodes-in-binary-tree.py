# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        def dfs(node,curmax):
            if not node:
                return
            if node.val>=curmax:
                count[0]+=1
                curmax=node.val
            dfs(node.left,curmax)
            dfs(node.right,curmax)
        count=[0]
        dfs(root,root.val)
        return count[0]
        