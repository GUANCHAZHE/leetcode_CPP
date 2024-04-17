//
// Created by Administrator on 2024/3/27.
//

#ifndef LEETCODE_TREE_H
#define LEETCODE_TREE_H


class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#endif //LEETCODE_TREE_H
