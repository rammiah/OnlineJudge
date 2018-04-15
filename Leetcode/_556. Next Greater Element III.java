class Solution {
    // 下一个数
    public int nextGreaterElement(int n) {
        char[] bits = Integer.toString(n).toCharArray();
        // 从后向前找数
        int smallIndex = bits.length - 2;
        while (smallIndex >= 0) {
            if (bits[smallIndex] < bits[smallIndex + 1]) {
                break;
            }
            --smallIndex;
        }
        // 已经最大
        if (smallIndex < 0) {
            return -1;
        }

        int x = bits[smallIndex], smallest = smallIndex + 1;
        for (int i = smallIndex + 1; i < bits.length; i++) {
            if (bits[i] > x && bits[i] <= bits[smallest]) {
                smallest = i;
            }
        }
        
        // 交换smallIndex和smallIndex + 1处元素
        char t = bits[smallIndex];
        bits[smallIndex] = bits[smallest];
        bits[smallest] = t;
        // smallIndex + 1到最后的反转
        int begin = smallIndex + 1;
        int end = bits.length - 1;
        while (begin < end) {
            t = bits[begin];
            bits[begin] = bits[end];
            bits[end] = t;
            ++begin;
            --end;
        }
        // try catch 会让时间增加1~2ms, 换成这样吧
        long res = Long.valueOf(new String(bits));
        return res <= Integer.MAX_VALUE ? (int) res : -1;

    }
}