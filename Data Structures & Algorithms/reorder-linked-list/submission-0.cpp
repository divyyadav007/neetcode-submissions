/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        // Base Case: Agar list khali hai ya sirf ek hi element hai, toh reorder nahi karna
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        
        // ==========================================================
        // STEP 1: Find the Middle of the Linked List (Slow & Fast)
        // ==========================================================
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // slow 1 kadam chalega
            fast = fast->next->next;  // fast 2 kadam chalega
        }
        
        // slow ab perfectly middle node par khada hai.
        // Second half ka head slow ke agla node hoga.
        ListNode* secondHalfHead = slow->next;
        slow->next = nullptr; // First half ko yahin break karke NULL set kar diya
        
        // ==========================================================
        // STEP 2: Reverse the Second Half of the Linked List
        // ==========================================================
        ListNode* prev = nullptr;
        ListNode* curr = secondHalfHead;
        ListNode* forward = nullptr;
        
        while (curr != nullptr) {
            forward = curr->next; // Aage ka address safe karo
            curr->next = prev;    // Link ko ulta ghumao
            prev = curr;          // prev ko aage khiskao
            curr = forward;       // curr ko aage khiskao
        }
        
        // Ab reverse hone ke baad, second half ka naya head pointer 'prev' par hai.
        
        // ==========================================================
        // STEP 3: Zigzag Merge (Alternate Merge) Dono Halves Ka
        // ==========================================================
        ListNode* first = head;   // First half shuruat se
        ListNode* second = prev;  // Second half (reversed) ke shuruat se
        
        while (second != nullptr) {
            // Aage ke connections tootne se pehle unka address safe karo (t1 aur t2 me)
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;
            
            // Asli pointer swapping game:
            first->next = second;  // Pehle wale ka link aakhiri wale se jodo
            second->next = t1;     // Aakhiri wale ka link pehle wale ke agle se jodo
            
            // Pointers ko agle round ke liye aage badha do
            first = t1;
            second = t2;
        }
    }
};