// has_cycle.cpp
#include "has_cycle.hpp"
#include "node.hpp"

bool hasCycle(const ListNode::Ptr &head)
{
    // Pointers
    auto fast = head;
    auto slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        // Iterate the pointers
        fast = fast->next->next;
        slow = slow->next;

        // Check for cycle
        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}
