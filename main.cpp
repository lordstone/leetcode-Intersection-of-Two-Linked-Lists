/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *left = headA;
        ListNode *right = headB;
        if(left == NULL || right == NULL) return NULL;
        int leftct = 1, rightct = 1;
        while(left -> next != NULL){
            left = left -> next;
            leftct++;
        }
        ListNode* lend = left;
        while(right -> next != NULL){
            right = right -> next;
            rightct++;
        }
        if(right != lend) return NULL;
        right = headB;
        left = headA;
        for(int i = abs(rightct - leftct); i > 0; i --){
            rightct > leftct ? right = right -> next : left = left -> next;
        }//syncrhonize both pointer
        while(right != left){
            right = right -> next;
            left = left -> next;
        }
        return right;
    }
};
