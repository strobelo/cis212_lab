# Data Structures: Linked List (And ADTs)
Derek Strobel  
CIS212 University of Oregon  
Spring 2020

# Linked List: An Ordered Collection
Why use Linked List over something like ArrayList or just an array?
    
*It all depends on what your program is doing often! (Complexity)*


**ArrayList Worst Case Complexities**
<details>
    <summary>Get item i</summary>
    O(1)! Constant access, huge advantage of arrays.
</details>

<details>
    <summary>Append item to beginning or end</summary>
    O(n). In the worst case, might have to copy the whole array if we run out of room. Huge downside.
</details>

**Linked List Worst Case Complexities**
<details>
    <summary>Get item i</summary>
    O(n). Need to traverse the linked list one node at a time.
</details>

<details>
    <summary>Append item to front or back</summary>
    O(1)! All the nodes are individual heap memory, so we can just allocate a new one and set its next to the head (to add to front) or add end's next to it (add to back).
</details>

Think about how the complexity of other operations (like removing an element or adding an element at a specific index) might differ as well!