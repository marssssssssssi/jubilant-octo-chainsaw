// Бинарная куча (Binary Heap) - min-heap
class BinaryHeap {
    private int[] heap;
    private int size;

    public BinaryHeap(int capacity) {
        heap = new int[capacity];
        size = 0;
    }

    public void insert(int key) {
        if (size == heap.length) return;
        heap[size] = key;
        heapifyUp(size++);
    }

    public int deleteMin() {
        if (size == 0) return -1;
        int min = heap[0];
        heap[0] = heap[--size];
        heapifyDown(0);
        return min;
    }

    public int getMin() {
        return size > 0 ? heap[0] : -1;
    }

    private void heapifyUp(int i) {
        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
            swap((i - 1) / 2, i);
            i = (i - 1) / 2;
        }
    }

    private void heapifyDown(int i) {
        while (true) {
            int smallest = i;
            int left = 2 * i + 1, right = 2 * i + 2;
            if (left < size && heap[left] < heap[smallest]) smallest = left;
            if (right < size && heap[right] < heap[smallest]) smallest = right;
            if (smallest == i) break;
            swap(i, smallest);
            i = smallest;
        }
    }

    private void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
}

// Куча Фибоначчи (Fibonacci Heap) - упрощённая
class FibonacciNode {
    int key;
    FibonacciNode child, sibling;

    FibonacciNode(int key) {
        this.key = key;
    }
}

class FibonacciHeap {
    private FibonacciNode minNode;

    public void insert(int key) {
        FibonacciNode node = new FibonacciNode(key);
        if (minNode == null || key < minNode.key) minNode = node;
    }

    public int extractMin() {
        if (minNode == null) return -1;
        int minKey = minNode.key;
        minNode = null; // Упрощено
        return minKey;
    }
}

// Хеш-таблица (Hash Table)
class HashTable {
    private class Entry {
        String key;
        String value;
        Entry next;

        Entry(String key, String value) {
            this.key = key;
            this.value = value;
        }
    }

    private Entry[] table;
    private int size;

    public HashTable(int size) {
        this.size = size;
        table = new Entry[size];
    }

    private int hash(String key) {
        return Math.abs(key.hashCode() % size);
    }

    public void put(String key, String value) {
        int index = hash(key);
        Entry entry = table[index];
        while (entry != null) {
            if (entry.key.equals(key)) {
                entry.value = value;
                return;
            }
            entry = entry.next;
        }
        Entry newEntry = new Entry(key, value);
        newEntry.next = table[index];
        table[index] = newEntry;
    }

    public String get(String key) {
        int index = hash(key);
        Entry entry = table[index];
        while (entry != null) {
            if (entry.key.equals(key)) return entry.value;
            entry = entry.next;
        }
        return null;
    }

    public void remove(String key) {
        int index = hash(key);
        Entry prev = null, entry = table[index];
        while (entry != null) {
            if (entry.key.equals(key)) {
                if (prev == null) table[index] = entry.next;
                else prev.next = entry.next;
                return;
            }
            prev = entry;
            entry = entry.next;
        }
    }
}

// Пример использования
public class Main {
    public static void main(String[] args) {
        // Бинарная куча
        BinaryHeap bh = new BinaryHeap(10);
        bh.insert(3);
        bh.insert(1);
        System.out.println(bh.getMin()); // 1
        System.out.println(bh.deleteMin()); // 1

        // Куча Фибоначчи
        FibonacciHeap fh = new FibonacciHeap();
        fh.insert(5);
        fh.insert(3);
        System.out.println(fh.extractMin()); // 3

        // Хеш-таблица
        HashTable ht = new HashTable(10);
        ht.put("Alice", "Jan");
        System.out.println(ht.get("Alice")); // Jan
        ht.remove("Alice");
        System.out.println(ht.get("Alice")); // null
    }
}
