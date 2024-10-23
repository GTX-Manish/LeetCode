# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):

    def mergeTwoLists(self, list1, list2):
        # Initialize a dummy node to serve as the starting point of the merged list
        head = ListNode()  
        lst = head  # Pointer to keep track of the current end of the merged list

        # Iterate as long as both lists are not empty
        while list1 and list2:
            # Compare the current nodes of both lists
            if list1.val < list2.val:
                lst.next = list1  # Point the next of the merged list to list1's current node
                list1 = list1.next  # Move to the next node in list1
            else:
                lst.next = list2  # Point the next of the merged list to list2's current node
                list2 = list2.next  # Move to the next node in list2
            
            # Move the lst pointer to the last node in the merged list
            lst = lst.next

        # At this point, one of the lists is exhausted, so append the remaining nodes of the other list
        lst.next = list1 or list2  # If list1 is not None, assign it; otherwise, assign list2

        # Return the merged list, skipping the dummy head node
        return head.next
