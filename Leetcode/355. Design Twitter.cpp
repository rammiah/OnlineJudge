class Twitter {
private:
    /** Initialize your data structure here. */
    typedef std::pair<int, int> post;
    std::map<int, std::list<post>> posts;
    std::map<int, std::set<int>> followings;
    int time_stamp = 0;

public:
    Twitter() = default;

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        // 必须找个办法记录顺序
        auto &had = posts[userId];
        had.emplace_front(-time_stamp, tweetId);
        ++time_stamp;
        // 每个人都只保存自己的最近的10条消息
        if (had.size() > 10) {
            had.pop_back();
        }
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        // 返回最近的10条消息
        // 插入排序
        std::list<post> all = posts[userId];
        for (auto id : followings[userId]) {
            for (post &p : posts[id]) {
                // 插入排序，但是是使用的lower_bound
                auto pos = std::lower_bound(all.begin(), all.end(), p);
                if (pos == all.end()) {
                    all.push_back(p);
                } else {
                    all.insert(pos, p);
                }
            }
            // 限制在10条
            if (all.size() > 10) {
                all.resize(10);
            }
        }
        std::vector<int> res;
        res.reserve(10);
        // 复制数据到一个vector
        for (auto it : all) {
            res.push_back(it.second);
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        followings[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        followings[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

