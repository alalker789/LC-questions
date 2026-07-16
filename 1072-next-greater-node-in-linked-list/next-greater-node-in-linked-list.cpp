/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        stack<int> st;

        ListNode *ptr = head;

        while(ptr){
            v.push_back(ptr->val);
            ptr = ptr->next;
        }

        int n = v.size();
        vector<int> res(n);

        for(int i=v.size()-1; i>=0; i--){
            while(!st.empty() && st.top() <= v[i]){
                st.pop();
            }

            if(st.empty()){
                res[i] = 0;
            }
            else{
                res[i] = st.top();
            }

            st.push(v[i]);
        }

        return res;
    }
};