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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dumy = new ListNode(-1);
        dumy->next=head;
        ListNode* temp = dumy;

        while(temp->next!=NULL){

            if(temp->next->val == val){
                ListNode* del;
                del=temp->next;
                temp->next=temp->next->next;
                delete del;
            }
            else{
                temp=temp->next;
            } 

        }

        ListNode* newhead=dumy->next;
        delete dumy;
        return newhead;
    }
};