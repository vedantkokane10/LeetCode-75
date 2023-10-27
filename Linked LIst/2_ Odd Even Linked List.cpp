/*
328. Odd Even Linked List
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
*/

ListNode* oddEvenList(ListNode* head) {
    ListNode* oddHead =NULL;
    ListNode* oddTail =NULL;
    ListNode* evenHead =NULL;
    ListNode* evenTail =NULL;
    int count = 1;
    while(head != NULL){
        if(count % 2 == 0){
            if(evenHead == NULL){
                evenHead = head;
                evenTail = head;
            }
            else{
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        } 
        else{
            if(oddHead == NULL){
                oddHead = head;
                oddTail = head;
            }
            else{
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        }
        count++;
        head = head->next;
    }
    if(evenHead == NULL){
        return oddHead;
    }
    if(oddHead == NULL){
        return evenHead;
    }
    evenTail->next = NULL;
    oddTail->next = evenHead;
    return oddHead;
}
