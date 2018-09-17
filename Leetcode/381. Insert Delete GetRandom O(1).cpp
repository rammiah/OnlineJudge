class RandomizedCollection {
    int nums[10000];
    int size;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        // 构造函数随便写
        memset(nums, 0, sizeof(nums));
        size = 0;
    }

    bool search(int val) {
        int left = 0, right = size - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] < val) {
                left = mid + 1;
            }
            else if (nums[mid] > val) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool inserted = true;
        if (search(val)) {
            inserted = false;
        }
        nums[size++] = val;
        // 将其设置为有序
        int index = size - 2;
        while (index >= 0 && nums[index] > val) {
            nums[index + 1] = nums[index];
            --index;
        }
        nums[index + 1] = val;

        return inserted;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        // 替换数据到最后一个
        int left = 0, right = size - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] > val) {
                right = mid - 1;
            }
            else if (nums[mid] < val) {
                left = mid + 1;
            }
            else {
                // 将后面的顶上来
                while (mid < size - 1) {
                    nums[mid] = nums[mid + 1];
                    ++mid;
                }
                --size;
                return true;
            }
        }
        return false;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        // random
        if (size == 0) {
            return 0;
        }
        return nums[rand() % size];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */