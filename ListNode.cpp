//
// Created by Administrator on 2024/3/8.
//

#include "ListNode.h"
#include <iostream>
ListNode::ListNode(int x) : val(x), next(nullptr) {};
ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {};
ListNode::ListNode() : val(0), next(nullptr) {};

ListNode* ListNode::dynamicchian(int n)
{
    ListNode* dumy = new ListNode(-1), *pre = dumy;
    for(int i = 0; i < n; i++)
    {
        ListNode* cur = new ListNode(i);
        pre->next = cur;
        pre = cur;
    }
    return dumy->next;
};
