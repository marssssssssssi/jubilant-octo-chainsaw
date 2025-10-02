# Бинарная куча (Binary Heap) - min-heap
class BinaryHeap:
    def __init__(self): self.heap = []
    def insert(self, key): self.heap.append(key); self._up(len(self.heap)-1)
    def delete_min(self): return self._extract()
    def get_min(self): return self.heap[0] if self.heap else None
    def _up(self, i): while i > 0 and self.heap[(i-1)//2] > self.heap[i]: self.heap[i], self.heap[(i-1)//2] = self.heap[(i-1)//2], self.heap[i]; i = (i-1)//2
    def _down(self, i): size = len(self.heap); while True: smallest = i; l, r = 2*i+1, 2*i+2; if l < size and self.heap[l] < self.heap[smallest]: smallest = l; if r < size and self.heap[r] < self.heap[smallest]: smallest = r; if smallest == i: break; self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]; i = smallest
    def _extract(self): if not self.heap: return None; min_val = self.heap[0]; self.heap[0] = self.heap.pop(); self._down(0); return min_val

# Куча Фибоначчи (Fibonacci Heap) - упрощённая
class FibonacciNode: def __init__(self, key): self.key = key; self.child = None; self.sibling = None
class FibonacciHeap:
    def __init__(self): self.min_node = None
    def insert(self, key): node = FibonacciNode(key); if not self.min_node or key < self.min_node.key: self.min_node = node
    def extract_min(self): if not self.min_node: return None; min_key = self.min_node.key; self.min_node = None; return min_key

# Хеш-таблица (Hash Table)
class HashTable:
    def __init__(self, size=10): self.size = size; self.table = [[] for _ in range(size)]
    def _hash(self, key): return hash(key) % self.size
    def set(self, key, value): self.table[self._hash(key)].append([key, value])
    def get(self, key): for k, v in self.table[self._hash(key)]: if k == key: return v; raise KeyError
    def remove(self, key): for i, (k, v) in enumerate(self.table[self._hash(key)]): if k == key: del self.table[self._hash(key)][i]; return

# Пример использования
bh = BinaryHeap(); bh.insert(3); bh.insert(1); print(bh.get_min())  # 1
fh = FibonacciHeap(); fh.insert(5); fh.insert(3); print(fh.extract_min())  # 3
ht = HashTable(); ht.set('Alice', 'Jan'); print(ht.get('Alice'))  # Jan
