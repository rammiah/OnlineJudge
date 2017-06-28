package Leetcode;

/**
 * Time: 29/06/17 07:43
 * Created by yaning.
 * School: HUST
 * Email: wangyaning6166@gmail.com
 */
public class _067AddBinary {
    public static void main(String[] args){
        _067AddBinary sol = new _067AddBinary();
        System.out.println(sol.addBinary("11", "1"));
    }


    public String addBinary(String a, String b) {
        StringBuilder sol = new StringBuilder();
        int aLen = a.length() - 1;
        int bLen = b.length() - 1;
        int left = 0; // 进位使用
        while (aLen >= 0 || bLen >= 0 || left > 0) {
            if (aLen >= 0) {
                if (a.charAt(aLen) == '1') {
                    left++;
                }
                aLen--;
            }
            if (bLen >= 0) {
                if (b.charAt(bLen) == '1') {
                    left++;
                }
                bLen--;
            }
            // 考虑进位
            sol.append(left % 2);
            left /= 2;
        }
        // 记得翻转，因为这个前面的是低位
        return sol.reverse().toString();
    }
}
