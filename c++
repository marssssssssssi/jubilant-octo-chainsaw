#include <vector>
#include <iostream>

// Бинарная куча (Binary Heap) - min-heap
class BinaryHeap {
private:
    std::vector<int> heap;
    void heapifyUp(int i) { while (i > 0 && heap[(i-1)/2] > heap[i]) { std::swap(heap[i], heap[(i-1)/2]); i = (i-1)/2; } }
    void heapifyDown(int i) { int size = heap.size(); while (true) { int smallest = i; int l = 2*i+1, r = 2*i+2; if (l < size && heap[l] < heap[smallest]) smallest = l; if (r < size && heap[r] < heap[smallest]) smallest = r; if (smallest == i) break; std::swap(heap[i], heap[smallest]); i = smallest; } }
public:
    void insert(int key) { heap.push_back(key); heapifyUp(heap.size()-1); }
    int deleteMin() { if (heap.empty()) return -1; int minVal = heap[0]; heap[0] = heap.back(); heap.pop_back(); heapifyDown(0); return minVal; }
    int getMin() { return heap.empty() ? -1 : heap[0]; }
};

// Куча Фибоначчи (Fibonacci Heap) - упрощённая
struct FibonacciNode { int key; FibonacciNode* child; FibonacciNode* sibling; FibonacciNode(int k) : key(k), child(nullptr), sibling(nullptr) {} };
class FibonacciHeap {
private:
    FibonacciNode* minNode;
public:
    FibonacciHeap() : minNode(nullptr) {}
    void insert(int key) { FibonacciNode* node = new FibonacciNode(key); if (!minNode || key < minNode->key) minNode = node; }
    int extractMin() { if (!minNode) return -1; int minKey = minNode->key; delete minNode; minNode = nullptr; return minKey; }
};

// Хеш-таблица (Hash Table)
class HashTable {
private:
    std::vector<std::vector<std::pair<std::string, std::string>>> table;
    size_t hash(const std::string& key) { size_t h = 0; for (char c : key) h += c; return h % table.size(); }
public:
    HashTable(int size) : table(size) {}
    void put(const std::string& key, const std::string& value) { table[hash(key)].push_back({key, value}); }
    std::string get(const std::string& key) { for (auto& p : table[hash(key)]) if (p.first == key) return p.second; return ""; }
    void remove(const std::string& key) { for (auto it = table[hash(key)].begin(); it != table[hash(key)].end(); ++it) if (it->first == key) { table[hash(key)].erase(it); break; } }
};

int main() {
    BinaryHeap bh; bh.insert(3); bh.insert(1); std::cout << bh.getMin() << std::endl;  // 1
    FibonacciHeap fh; fh.insert(5); fh.insert(3); std::cout << fh.extractMin() << std::endl;  // 3
    HashTable ht(10); ht.put("Alice", "Jan"); std::cout << ht.get("Alice") << std::endl;  // Jan
    return 0;
}
