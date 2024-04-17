//
// Created by Administrator on 2024/3/8.
//

#ifndef LEETCODE_LISTNODE_H
#define LEETCODE_LISTNODE_H


class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x);
    ListNode(int x, ListNode *next);
    ListNode();
    ListNode* dynamicchian(int n);

};


#endif //LEETCODE_LISTNODE_H
