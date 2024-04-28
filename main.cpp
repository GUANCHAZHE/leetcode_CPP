#include <iostream>
#include "ListNode.h"
#include "Solution.h"
#include <vector>
#include <set>
#include<unordered_set>
#include "GraphAdjMat.h"

enum weekday { s, m, t, w, thu, f, s1};

// 全局函数和全局变量
void printVector(const vector<int>& nums){
    for(auto num: nums){
        cout<< num<<endl;
    }
}

void printVectorMatrix(const vector<vector<int>> & matrix){
    for(auto row: matrix){
        for(auto num: row){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}


int main(int argc, char* argv[]) {
    using namespace std;
//
//    ListNode* n0 = new ListNode(2);
//    ListNode* n1 = new ListNode(4);
//    ListNode* n2 = new ListNode(3);
//    ListNode* n3 = new ListNode(2);
//    ListNode* n4 = new ListNode(3);
//
//    n0->next = n1;
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;

//    ListNode* head1 = n0;
//
//
//    ListNode* m0 = new ListNode(5);
//    ListNode* m1 = new ListNode(6);
//    ListNode* m2 = new ListNode(4);
//    ListNode* m3 = new ListNode(2);
//    ListNode* m4 = new ListNode(3);
//
//    m0->next = m1;
//    m1->next = m2;
//    m2->next = m3;
//    m3->next = m4;
//    m4->next = m1;

//    ListNode* head2 = m0;

//    while(head != nullptr)
//    {
//        cout<<head->val<<endl;
//        head = head->next;
//    }

//    ListNode* a = new ListNode;
//    ListNode* head = new ListNode(0);
//    a = head;
//    for(int i = 0; i< 5;i++)
//    {
//        ListNode *phead = new ListNode(i);
//        phead->next = nullptr;
//        a->next = phead;
//        a = phead;
//    }

//    while(head != nullptr)
//    {
//        cout<<head->val<<endl;
//        head = head->next;
//    }

//    set<int> set1;
//    set1.insert(3);
//    set1.insert(2);
//    set1.insert(6);
//    set1.insert(1);
//
//    for( auto it = set1.begin(); it !=set1.end();it++)
//    {
//        cout<<*it<<endl;
//    }
//
//    cout<<set1.size()<<endl;


//    ListNode *a = nullptr;
//    ListNode* b1 = new ListNode(0);
//
//    Solution s;
//    ListNode* b = s.mergeTwoLists(a,b1);
//    ListNode* b = s.detectCycle()
//    ListNode* b = s.removeNthFromEnd(head1,2);
//    s.reorderList(head1);
//     ListNode* ans = s.middleNode(head1);
//     cout<<ans->val<<endl;
//    ListNode* b = head1;
//    while(b != nullptr)
//    {
//        cout<<b->val<<endl;
//        b = b->next;
//    }
//    while(b != nullptr)
//    {
//        cout<<b->val<<endl;
//        b = b->next;
//    }

//    bool ans = s.detectCycle(head2);
//    cout<<boolalpha<<ans<<endl;



//    ListNode*b =  s.addTwoNumbers(head1, head2 );


//    vector<int> z {4,2,1,3,6};
//    for( int nu:z){
//        cout<<nu<<endl;
//    }
//    sort(z.begin(),z.end());
//    for( int nu:z){
//        cout<<nu<<endl;
//    }
//
//    vector<int> aaa {4,1,2,2,5,1};
//    Solution sol;
//    sol.quick_sort(aaa,0,5);
//
//    for(auto x:aaa){
//        cout<<x;
//    }

//    weekday wek = s;
//    for(int i = wek; i != f; i++){
//        cout<<i<<endl;
//        cout<<wek + s <<endl;
//        cout<<" -------nice!!!!----"<<endl;
//    }


    // 二叉树部分
/* 初始化二叉树 */
// 初始化节点
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
// 构建节点之间的引用（指针）
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
//
//    Solution s;
//    vector<vector<int>>ans;
//    vector<int> vec;
//    ans = s.levelOrder(n1);
//    for(auto row:ans){
//        for(auto j :row){
//            cout<<j<<" ";
//        }
//        cout<<endl;
//    }

//    cout<<s.diameterOfBinaryTree(n1)<<endl;
//
//    vec = s.rightSideView(n1);
//    for(auto x: vec){
//        cout<<x<<" ";
//    }
//    vector<double> vec1;
//    vec1 = s.averageOfLevels(n1);
//    for(auto x: vec1){
//        cout<<x<<" ";
//    }
//
//    cout<<endl<<endl;
//    unordered_set<int> test;
//    test.insert(4);
//    test.insert(3);
//    test.insert(4);
//    if(test.count(4)){
//        cout<<test.count(4)<<endl;
//    }



//    multiset<int> se;
//    se.insert(1);
//    se.insert(2);
//    se.insert(1);
//    se.insert(4);
//
//    cout<<se.count(1)<<endl;
//    Solution s;
//    vector<vector<char>> grid = {
//            {'1','1','1','1','0'},
//            {'1','1','0','1','0'},
//            {'1','1','0','0','0'},
//            {'0','0','0','0','0'}
//    };
//    cout<<s.numIslands1(grid)<<endl;
//
//    int a=3;
//    vector<string> test;
//    test.push_back(to_string(a));
//    cout<<test.front()<<endl;

//    Solution s;
//    vector<vector<int>> ans;
//    vector<int> path;
//    s.dfs(n1,path,ans);
//    printVectorMatrix(ans);

//    Solution s;
//    vector<string> ans;
//    ans = s.binaryTreePaths(n1);
//    for(auto s: ans){
//        cout<< s<<endl;
//    }
//    string a = "";
//    a+="1";
//    vector<string> qwe;
//    qwe.push_back(a);
//    cout<<qwe.front()<<endl;

    vector<int> nums = {1,2,3};
    Solution s;
    vector<vector<int>> res = s.subsets(nums);
    printVectorMatrix(res);
    cout<<res.size()<<endl;
    string str={"123"};
    cout<<(int)str[1]<<endl;
    string str93{"25525511135"};
    vector<string> ans93;
    ans93 = s.restoreIpAddresses(str93);
    cout<<"finish"<<endl;
    return 0;
}
