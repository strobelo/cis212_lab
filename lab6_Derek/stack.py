'''
Derek Strobel
University of Oregon
CIS212 Spring 2020
For instructional use
'''

import doctest

class Stack():
    def __init__(self, data=None):
        if data == None:
            self._data = []
        else:
            self._data = data

    def push(self, item):
        '''
        (object) -> None
        Pushes an item onto the stack.
        Complexity: O(1)
        '''
        self._data.append(item)

    def peek(self):
        '''
        () -> object
        Retrieves (but do not remove) the top element of the stack
        If stack is empty, returns None
        Complexity: O(1)
        '''
        if not self.isEmpty():
            return self._data[-1]
        else:
            return None

    def pop(self):
        '''
        () -> object
        Retrieves and remove the top element of the stack
        If stack is empty, returns None
        Complexity: O(1)
        '''
        if not self.isEmpty():
            item = self._data[-1]
            del self._data[-1]
            return item
        else:
            return None

    def size(self):
        '''
        () -> int
        Returns the number of elements in the stack
        Complexity: O(1)
        '''
        return len(self._data)

    def isEmpty(self):
        '''
        () -> bool
        Return True if stack has no elements, False otherwise
        Complexity: O(1)
        '''
        return len(self._data) == 0

    def clear(self):
        self._data = []

    def __repr__(self):
        return f'Stack({self._data})'

def test_parentheses(str):
    '''
    (string) -> int
    Uses a stack to determine whether a string expression has valid parenthesization.
    If so, returns the number of pairs of valid parentheses in the string.
    If the string is invalidly parenthesized (too many left parens,
    too many right parens, or in the wrong order), returns -1.

    Examples:
    >>> test_parentheses('x + (3 + 5)')
    1
    >>> test_parentheses('(3 + (2/12)) / 5 + (3 - 33)')
    3
    >>> test_parentheses(') x + 32 + (3 + 3) )')
    -1
    '''

    stack = Stack() # Initialize an empty stack
    nValid = 0 # Keep a counter of valid pairs of parentheses
    for c in str: # Loop over every character in the expression
        if c == '(':
            stack.push(c) # Push open parens onto the stack
        elif c == ')': # Close parens: Pop from the stack
            if stack.pop() == None: # stack was empty; there was no open paren, so must be invalid
                return -1
            else:
                nValid += 1 # close paren matched to open paren; increment valid counter
    return nValid


if __name__ == '__main__':
    # s = Stack()
    # print(s)
    # s.push('a')
    # print(s)
    # s.push('b')
    # print(s)
    # s.push('c')
    # print(s)
    # print(s.peek())
    # print(s.pop())
    # print(s)

    print(doctest.testmod())
