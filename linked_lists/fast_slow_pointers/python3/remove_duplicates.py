from node import ListNode
from singly import SinglyLinkedList

def remove_duplicates(head: ListNode) -> ListNode:
    """
    Given the `head` of a sorted linked list, delete all duplicates such that each element appears only once. 

    Parameters
    ----------
    head : ListNode
        The sentinel head of the singly linked list

    Returns
    -------
    ListNode
        The new sentinel head of the sorted, deduplciated linked list
    """
    # Dummy pointer for traversal
    current = head
    while current and current.next:
        # If the current node and the next nodes are duplicated, remove the next node
        if current.data == current.next.data:
            # Skip the next (duplicated) node by setting the next pointer of the current node to node after the currently next node
            current.next = current.next.next
        else:
            # If the current node is not a duplicate of the next node, step to the next node
            current = current.next

    return head

def main() -> int:

    test_cases = [[1, 1, 2], [1, 1, 2, 3, 3], [9, 12, 12, 7, 3, 7, 3, 4, 4, 5]]

    for data_array in test_cases:
        nodes = (ListNode(data=data) for data in sorted(data_array))
        sll = SinglyLinkedList()
        for node in nodes:
            sll.add_to_end(node)
        dedup_head = remove_duplicates(sll.head)
        print(f"The new first node is {sll.head.next} and the new linked list is:")
        sll.display()

    return 0

if __name__ == "__main__":

    main()
