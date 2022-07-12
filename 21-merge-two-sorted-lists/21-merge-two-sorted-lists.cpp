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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* ptrAns = ans;
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        while(ptr1 && ptr2){
            if(ptr1->val <= ptr2->val){
                ptrAns->next = new ListNode(ptr1->val);
                ptr1 = ptr1->next;
            } else {
                ptrAns->next = new ListNode(ptr2->val);
                ptr2 = ptr2->next;
            }
            ptrAns = ptrAns->next;
        }

        if(ptr1){
            ptrAns->next = ptr1;    
        } else if (ptr2){
            ptrAns->next = ptr2;    
        }
        
        return ans->next;
    }
};