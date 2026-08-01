#include <stdlib.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy; // Dummy head to easily manage list construction
    dummy.next = NULL;
    struct ListNode* tail = &dummy;
    
    int carry = 0;

    // Loop continues as long as there is a node in l1, l2, or an active carry
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        // Calculate carry for next iteration
        carry = sum / 10;

        // Create node for current digit
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;

        // Append to list
        tail->next = newNode;
        tail = tail->next;
    }

    return dummy.next; // Return head of the resulting linked list
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna