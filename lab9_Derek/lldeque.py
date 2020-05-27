class dllnode():
    def __init__(self, value, next=None, prev=None, sentinel=False):
        self.value = value
        self.sentinel = sentinel
        if sentinel:
            self.next = self
            self.prev = self
        else:
            self.next = next
            self.prev = prev
        
    def __str__(self):
        return f'dllnode({self.value})'

class lldeque():
    def __init__(self):
        self.sentinel = dllnode(value=None, sentinel=True)
        self.size = 0

    def push_back(self, value):
        newnode = dllnode(value, next=self.sentinel, prev=self.sentinel.prev)
        self.sentinel.prev.next = newnode
        self.sentinel.prev = newnode
        self.size += 1
    
    def push_front(self, value):
        newnode = dllnode(value, next=self.sentinel.next, prev=self.sentinel)
        self.sentinel.next.prev = newnode
        self.sentinel.next = newnode
        self.size += 1
    
    def pop_front(self):
        n = self.sentinel.next
        n.next.prev = self.sentinel
        self.sentinel.next = self.sentinel.next.next
        self.size -= 1
        return n.value
        
    def pop_back(self):
        n = self.sentinel.prev
        n.prev.next = self.sentinel
        self.sentinel.prev = self.sentinel.prev.prev
        self.size -= 1
        return n.value
    
    def peek_front(self):
        return self.sentinel.next.value
    
    def peek_back(self):
        return self.sentinel.prev.value
    
    def __len__(self):
        return self.size
    
    def __str__(self):
        s = ''
        k = self.sentinel.next
        while k.sentinel == False:
            s += str(k) + ', '
            k = k.next
        return s
    
if __name__ == '__main__':
    d = lldeque()
    print(d)
    d.push_back(5)
    print(d)
    d.push_back(2)
    print(d)
    d.push_front(7)
    print(d)
    print(len(d))
    print(d.pop_back())
    print(d)
    print(d.peek_front())
    print(d)
    print(d.pop_front())
    print(d)
