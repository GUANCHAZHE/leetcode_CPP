//
// Created by Administrator on 2024/3/8.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include "ListNode.h"
#include "tree.h"
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *dumy = new ListNode(0, head), *p0 = dumy;
        for (int i = 0; i < left - 1; i++)
            p0 = p0->next;

        ListNode *pre = nullptr, *cur = p0->next;

        for (int i = 0; i < right - left + 1; i++) {
            ListNode *tem = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tem;
        }

        p0->next->next = cur;
        p0->next = pre;

        return dumy->next;
    }

    ListNode *reverseList(ListNode *head) {
        // 申请节点，pre和 cur，pre指向null
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            // 记录当前节点的下一个节点
            ListNode *tmp = cur->next;
            cur->next = pre; //pre是空指针，所以就把cur的指向变成了空
            // pre和cur节点都前进一位
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        // 得到链表大小
        int n = 0;
        while(cur!= nullptr)
        {
            n++;
            cur = cur->next;
        }

        //k个一组翻转
        ListNode* dummy = new ListNode(-1,head);
        ListNode* p0 = dummy;
        while( n >= k)
        {
            n -= k;
            ListNode* cur = p0->next, *pre = nullptr;
            for(int j = 0; j < k; j++)
            {
                ListNode* tem = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tem;
            }
            ListNode* p0_nxt = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = p0_nxt;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        // 1取链表数据，存入可排序容器，
        // 循环链表，存入set，
        vector<int> num;
        ListNode* cur = head;
        while(cur != nullptr)
        {
            num.push_back(cur->val);
            cur = cur->next;
        }
        // 2动态创建链表，插入排序后数据
        cur = head;
        sort(num.begin(),num.end());
        for(auto it = num.begin(); it != num.end(); it++)
        {
            cur->val = *it;
            cur = cur->next;
        }
        return head;
    }


    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        /**  解法1 myown
        // 还是后弦创建一个vector变量，存储这个书，遍历第一个数组，结束之后连接第二个链表
        vector<int> nums;
        ListNode* cur1 = list1, *cur2 =list2;
        ListNode* dumy1 = new ListNode(-1,list1);
        ListNode* dumy2 = new ListNode(-1,list2);
        while(dumy1 != nullptr && dumy1->next != nullptr)
        {
            nums.push_back(dumy1->next->val);
            dumy1 = dumy1->next;
        }
        // 循环第二个链表，继续存入数据，结束之后
        while(dumy2 != nullptr && dumy2->next != nullptr)
        {
            nums.push_back(dumy2->next->val);
            dumy2 = dumy2->next;
        }
        //开始重新循环整合之后的链表，将排序之后的数据存入相关节点。
        sort(nums.begin(),nums.end());

        // 创建动态链表存入数组数据
        ListNode* dumy = new ListNode(-1), *head = dumy;
        for(auto it = nums.begin(); it != nums.end(); it++)
        {
            ListNode* cur = new ListNode(*it);
            dumy->next = cur;
            dumy = cur;
        }
        delete dumy1,dumy2,dumy;
        return head->next;
       **/


        //解法2
        if(list1 == nullptr)
        {
            return list2;
        }else if(list2 == nullptr) {
            return list1;
        }else if(list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }


    bool hasCycle(ListNode *head) {
        //古典解法
//        vector<ListNode*> add;
//        while(head != nullptr)
//        {
//            add.push_back(head);
//            head = head->next;
//            auto it = find(add.begin(),add.end(),head);
//            if(it != add.end()){
//                return true;
//            }
//        }
//        return false;

        //高效解法
        ListNode* slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }


    //version 1 效率低下版
//    ListNode *detectCycle(ListNode *head) {
//        map<ListNode*,int> mymap;
//        int count = 0;
//        while(head!= nullptr)
//        {
//            mymap.insert(pair<ListNode*,int>(head,count));
//            head = head->next;
//            auto it = mymap.find(head);
//            if(it != mymap.end()){
//                return it->first;
//            }
//        }
//        return nullptr;
//    }

    // 高效版
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while( fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                ListNode* l1 = head;
                ListNode* l2 = fast;
                while(l1 != l2){
                    l1 = l1->next;
                    l2 = l2->next;
                }
                return l1;
            }
        }
        return nullptr;
    }


    ListNode* trainingPlan(ListNode* head, int cnt) {
        ListNode* fast = head, *slow = head;
        while(cnt--) fast = fast->next;
        while(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dumy = new ListNode(-1,head);
        ListNode* fast = dumy, *slow = dumy;
        n++;
        while(n--) fast = fast->next;
        while(fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        delete dumy;
        return dumy->next;
    }


    void reorderList(ListNode* head) {
        //解法1 存储存入到数组
        vector<ListNode*> record;
        ListNode* cur = head;
        while(cur!= nullptr){
            record.push_back(cur);
            cur = cur->next;
        }

//        auto slow = record.begin();
//        auto fast = record.end();
//        fast--;
//        while(fast != slow){
//            (*slow)->next = (*fast);
//            (*fast)->next = (*slow)->next->next;
//            fast--;
//            slow++;
//        }

        int i = 0, j = record.size()-1;
        while (i < j ){
            record[i]->next = record[j];
            i++;
            if(i == j) break;
            record[j]->next = record[i];
            j--;
        }
        record[i]->next = nullptr;

        // 解法2
        // 也就只有三步做法，第一步找到中间节点
        // 反转之间结点之后的部分
        // 快慢指针，一步一步迭代

    }


    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head, * slow = head;
        while(fast!= nullptr && fast->next != nullptr ){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if  (l1 == nullptr) return l2;
        if  (l2 == nullptr) return l1;

        ListNode* dumy = new ListNode();
        ListNode* prev = dumy;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carry = 0;

        while(p1 != nullptr || p2 != nullptr || carry > 0 ){
            int val1 = p1 == nullptr ? 0 : p1->val;
            int val2 = p2 == nullptr ? 0 : p2->val;

            int sum = val1 + val2 + carry;
            carry = sum / 10;
            int data = sum % 10;

            ListNode* cur = new ListNode(data);
            prev->next = cur;
            prev = cur;

            p1 = p1 == nullptr ? nullptr : p1->next;
            p2 = p2 == nullptr ? nullptr : p2->next;
        }
        return dumy->next;
    }
    bool isValid(string s) {
        stack<char> sta;
        for(char c :s){
            if(c =='(' || c =='[' || c =='{'){
                sta.push(c);
                continue;
            }else{
                if (sta.empty())
                    return false;
            }
            if(c ==')')
                if( sta.top() == '(') sta.pop();
                else return false;
            if(c ==']')
                if( sta.top() == '[') sta.pop();
                else return false;
            if(c =='}')
                if( sta.top() == '{') sta.pop();
                else return false;
        }
        if(sta.empty()) return true;
        else return false;
    }


    int calculate(string s) {
        //两个栈，一个放数，一个放运算符
        stack<int> num1;
        stack<char> operator1;
        // 空格删除
        s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());

        // 从左到右扫描，数字放入
        for(auto c: s){
            if(isdigit(c)) num1.push(c);
            else{

            }
        }
        // 操作符放入右边栈
        //当扫描到操作符优先级比栈顶的高，那就放入
        // 相等或小于，都要把俩栈顶操作数和栈顶运算符计
        // 得到结果放入数值，再次比较
        return 0;
    }

    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size() - 1, k);
    }
    int findKthLargest(vector<int>& nums, int l, int r, int k) {
        int p = partition(nums, l, r);
        int rank = r - p + 1;

        if (rank == k) {
            return nums[p];
        } else if (rank > k) {
            return findKthLargest(nums, p + 1, r, k);
        } else {
            return findKthLargest(nums, l, p - 1, k - rank);
        }
    }

    void quick_sort(vector<int>& nums, int l, int r){
        if(l >= r)   return ;
        int q = partition(nums,l,r);
        quick_sort(nums,l,q - 1);
        quick_sort(nums,q+1, r);
    }
    int partition( vector<int> &nums, int l,int r ){
        int pivot = nums[r];
        int i = l;
        for (int j = l; j< r; j++){
            if(nums[j] < pivot){ //这个带括号很重要，一i的那个不要漏写了。
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[r]);
        return i; //为什么要分会i
    }
    int random_partition(vector<int>& nums, int l, int r){
        int i =rand() % (r - l + 1) + l;
        swap(nums[r],nums[i]);
        return partition(nums,l,r);
        //这么书写就是为了继续使用partition函数，随即替换一个数字之后继续partition
    }

    void preorder(TreeNode* root, vector<int>& res){
        if(root == nullptr) return;
        res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }



    vector<int> levelOrdermy(TreeNode* root){
        queue<TreeNode*> queue;
        queue.push(root);
        vector<int> vec;
        while(!queue.empty()){
            TreeNode* node = queue.front();
            queue.pop();
            vec.emplace_back(node->val);
            if(node->left != nullptr){
                queue.push(node->left);
            }
            if(node->right != nullptr){
                queue.push(node->right);
            }
        }
        return vec;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        //判断是否为空数组，空数组直接返回
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        // 需要注意que不可以使用初始化列表，需要push
        que.push(root);
        //遍历完的条件就是队列为空
        while(!que.empty()){
            // 开始循环遍历每一层，记录当前层的节点个数
            int que_size = que.size();
            // 记录每一层的数值，每一层都会自动创建一个新的
            vector<int> lev;
            for(int i = 0; i < que_size; i++){
                //
                TreeNode* node = que.front();
                que.pop();
                lev.emplace_back(node->val);
                if(node->left != nullptr) {
                    que.push(node->left);}
                if(node-> right != nullptr){
                    que.push((node->right));
                }
            }
            ans.push_back(lev);
        }
        return ans;
    }


    int res = 0;
    int depth = 0;
    int maxDepth(TreeNode* root) {
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root){
        if ( root == nullptr){
            return;
        }
        depth++;
        if( (root->left == nullptr) && (root->right == nullptr)){
            res = max(depth,res);
        }
        traverse(root->left);
        traverse(root->right);
        depth--;
    }

    int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth1(root);
        return maxDiameter;
    }
    int maxDepth1(TreeNode* root){
        if( root == nullptr){
            return 0;
        }
        int leftMax = maxDepth1(root->left);
        int rightMax = maxDepth1(root->right);
        maxDiameter = max(maxDiameter, ( leftMax + rightMax + 1));

        return 1 + max(leftMax, rightMax);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr){
            return {};
        }
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> ans;

        while( !que.size()){
            int n = que.size();
            vector<int> vec;
            for(int i = 0; i < n; i++){
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(root->val);

                if(node->left != nullptr){
                    que.push(node->left);
                }
                if(node->right != nullptr){
                    que.push(node->right);
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }

    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int que_size = que.size();
            vector<int> lev;
            for(int i = 0; i< que_size; i++){
                TreeNode* node = que.front();
                que.pop();
                if( i == que_size -1){
                    ans.emplace_back(node->val);
                }
                if(node->left != nullptr){
                    que.push(node->left);
                }
                if(node->right != nullptr){
                    que.push(node->right);
                }
            }
        }
        return ans;
    }

    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<double> ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int que_size = que.size();
            vector<int> lev;
            double temp = 0;
            for(int i = 0; i< que_size; i++){
                TreeNode* node = que.front();
                que.pop();
                temp += (node->val);
                if(node->left != nullptr){
                    que.push(node->left);
                }
                if(node->right != nullptr){
                    que.push(node->right);
                }
            }
            ans.emplace_back(temp / que_size);
        }
        return ans;
    }


    // 图
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int numIsland = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dirs = {{-1, 0},
                                      {1,  0},
                                      {0,  -1},
                                      {0,  1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    numIsland++;
                    grid[i][j] = '0';
                }
                queue<pair<int, int>> que;
                que.push({i, j});
                while(! que.empty()){
                    // 这个写法牛逼啊，没见过，直接获取一个pair里面对应的两个数值
                    auto [x,y] = que.front();
                    que.pop();

                    for(auto dir : dirs){
                        int nx = x + dir[0];
                        int ny = y + dir[1];
                        if(nx>=0 && nx <m && ny >= 0 && ny< n && grid[nx][ny] =='1'){
                            que.push({nx,ny});
                            grid[nx][ny] = '0';
                        }
                    }
                }

            }
            return numIsland;
        }
    }


    int numIslands1(vector<vector<char>>& grid) {
        int res = 0;
        for(int r = 0; r<grid.size();r++){
            for(int c = 0; c<grid[0].size();c++){
                if(grid[r][c] =='1'){
                    dfs(grid,r,c);
                    res++;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& grid,int r, int c){
        if(!inArea(grid,r,c)){
            return ;
        }
        if(grid[r][c] != '1'){
            return;
        }
        grid[r][c] ='2';
        dfs(grid,r-1,c);
        dfs(grid, r+1,c);
        dfs(grid,r,c-1);
        dfs(grid,r,c+1);
    }
    bool inArea(vector<vector<char>>& grid,int r, int c){
        return 0<= r && r < grid.size() && 0<=c && c < grid[0].size();
    }

    void dfs(TreeNode* root, vector<int> path, vector<vector<int>>& ans){
        if(root == nullptr){
            return;
        }
        path.push_back(root->val);
        if(! root->left && !root->right){
            ans.push_back(path);
        }
        dfs(root->left,path,ans);
        dfs(root->right,path,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        dfs(root,"",paths);
        return paths;
    }
    void dfs(TreeNode* root, string path, vector<string>& paths){
        if( root == nullptr){
            return ;
        }
        path += to_string(root->val);
        if(!root->left && !root->right){
            paths.push_back(path);
        }
        path +="->";
        dfs(root->left,path, paths);
        dfs(root->right,path,paths);
    }

    vector<vector<int>> res1;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<bool> used(nums.size(),false);
        backtrack(nums,path,used);
        return res1;
    }
    void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& used){
        if( path.size() == nums.size()){
            res1.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size();i++){
            if(used[i] == true){
                continue;
            }
            path.push_back(nums[i]);
            used[i]=true;
            backtrack(nums,path,used);
            path.pop_back();
            used[i]=false;
        }
    }

    //leetcode 78
    vector<vector<int>> res78;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> state;
        vector<bool> used(nums.size(),false);
        int start = 0;
        sort(nums.begin(),nums.end());
        backtrack(state,nums,start);
        return res78;
    }

    void backtrack(vector<int>& state, vector<int>& choices, int start){
        res78.push_back(state);
        for (int i = start; i < choices.size(); i++){
            state.push_back(choices[i]);
            backtrack(state, choices, i +1);
            state.pop_back();
        }
    }
    vector<string> res93;
    int pointnum = 0;
    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4 || s.size()>12){
            return {};
        }
        backtrack(s,0);
        return res93;

    }
    void backtrack( string& s,int start){
        if(pointnum == 3){
            if( isValid(s,start,s.size()-1))
                res93.emplace_back(s);
            return;
        }
        for(int i = start; i < s.size();i++){
            if(isValid(s,start,i)){
                s.insert(s.begin()+i+1,'.');
                pointnum++;
                backtrack(s,i+2);
                s.erase(s.begin()+i+1);
                pointnum--;
            } else break;
        }
    }
    bool isValid(string&s, int start, int end){
        if(start > end){
            return false;
        }
        // 0开头的数字不合法，但是直接选取0就可以
        if(s[start] == '0' && start != end){
            return false;
        }
        int num = 0;
        for(int i = start; i <= end ; i++){
            if(s[i] >'9' || s[i] < '0'){
                return false;
            }
            num = num*10 + (s[i]-'0');
            //这一步太牛逼了，字符型到int的转换，这样效率是高
            if(num > 255){
                return false;
            }
        }
        return true;
    }
    string reverseWords(string s) {
        removespace(s);
        reverse(s.begin(),s.end());
        int start = 0;
        for(int i = 0; i <= s.size(); i++){
            if( i == s.size() || s[i] ==' '){
                revers_num(s,start,i - 1);
                start = i + 1;
            }
        }
        return s;
    }
    void removespace(string& s){
        for(int i = s.size()-1; i > 0; i--){
            if(s[i] == s[i-1] && s[i]==' '){
                s.erase(s.begin() + i);
            }
        }
        if(s.size() > 0 && s[s.size()-1]==' '){
            s.erase(s.begin() + s.size() - 1);
        }
        if(s.size() > 0 && s[0] ==' '){
            s.erase(s.begin());
        }
    }
    void revers_num(string& s,int start, int end){
        for(int i = start, j = end;i < j; i++, j--){
            swap(s[i],s[j]);
        }
    }

    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0] = 1;
        for(int j = 0; j <= amount; j++){
            for(int coin : coins){
                if(j >= coin){
                    dp[j] += dp[j - coin];
                    cout<<dp[j]<<endl;
                }
            }
        }
        return dp[amount];

    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int count = 0;
        for (int i = 0; i < nums1.size(); i++) {
            auto find_pos = find(nums2.begin(), nums2.end(), nums1[i]);
            if (find_pos != nums2.end()) {
                int index2 = find_pos - nums2.begin();
                for (int j = index2 + 1, k = i + 1; j < nums2.size();) {
                    if (nums2[j] == nums1[k]) {
                        j++;
                        k++;
                        count++;
                    } else {
                        count = 0;
                        break;
                    }
                }
            }
        }
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        for(int index = 0; index < nums.size(); index++){
            int left = 0;
            int right = left + index;
            for(;right < nums.size(); left++, right++){
                int s = sum(nums,left,right);
                if( s > target){
                    return right - left;
                }
            }
        }
        return 0;
    }
    int sum(vector<int>& nums, int start, int end){
        int ans = 0;
        while(start <= end){
            ans += nums[start];
            start++;
        }
        return ans;
    }


};


#endif //LEETCODE_SOLUTION_H
