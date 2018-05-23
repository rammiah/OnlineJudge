class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        if (bits == null || bits.length == 0) {
            return false;
        }

        int index = 0;
        int last = 1;
        while (index < bits.length) {
            if (bits[index] == 1) {
                index += 2;
                last = 2;
            } else {
                index++;
                last = 1;
            }
        }


        return last == 1;
    }
}