class LRUCache {
    static class Node {
        int key;
        int value;
        Node pre;
        Node next;

        Node() {
            pre = next = null;
        }

        Node(int key, int value) {
            this.key = key;
            this.value = value;
            pre = next = null;
        }

        @Override
        public int hashCode() {
            return super.hashCode();
        }
    }

    int cap;
    Node head;
    HashMap<Integer, Node> map;

    private void promotedNode(Node n) {
        n.next.pre = n.pre;
        n.pre.next = n.next;
        head.next.pre = n;
        n.pre = head;
        n.next = head.next;
        head.next = n;
    }

    public LRUCache(int capacity) {
        // 创建LRU cache
        head = new Node();
        head.next = head.pre = head;
        map = new HashMap<>(capacity);
        cap = capacity;
    }

    public int get(int key) {
        Node n = map.get(key);
        if (n != null) {
            // 将n提到前面
            promotedNode(n);
            return n.value;
        }
        return -1;
    }

    public void put(int key, int value) {
        Node n = map.get(key);
        if (n != null) {
            // 将n提到前面
            promotedNode(n);
            n.value = value;
        } else if (map.size() < cap) {
            // 插入到里面就好了，首先找到最旧的元素
            n = new Node(key, value);
            n.next = head.next;
            n.pre = head;
            head.next.pre = n;
            head.next = n;
            map.put(n.key, n);
        } else {
            // LRU删除
            n = head.pre;
            map.remove(n.key);
            promotedNode(n);
            n.key = key;
            n.value = value;
            map.put(n.key, n);
            head.next = n;
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
