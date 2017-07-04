package Leetcode;

/**
 * Time: 28/06/17 21:47
 * Created by yaning.
 * School: HUST
 * Email: wangyaning6166@gmail.com
 */
public class _066PlusOne {
    public static void main(String[] args) {
    }

    public int[] plusOne(int[] digits) {
        boolean allNine = true;
        /* 判断是否全部是9 */
        for (int digit : digits) {
            if (digit != 9) {
                allNine = false;
                break;
            }
        }
        /* 如果全是9，多一位，第一个是1，后面是0 */
        if (allNine) {
            int[] sol = new int[digits.length + 1];
            sol[0] = 1;
            return sol;
        } else {
            /* 直接使用原来的数组 */
            int left = 0;
            for (int i = digits.length - 1; i >= 0; i--) {
                left = left + digits[i];
                digits[i] = left % 10;
                left /= 10;
            }
            return digits;
        }
    }
}
