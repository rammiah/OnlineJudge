public class Solution {
    public boolean isPalindrome(int x) {
        int t = 0;
        if (x < 0){
            return false;
        }
        int temp = x;
        while (temp > 0){
            t = temp % 10 + t * 10;
            temp /= 10;
        }
        return x == t;
    }
}
