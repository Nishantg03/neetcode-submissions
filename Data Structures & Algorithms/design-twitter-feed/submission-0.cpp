class Twitter {
public:
    // userId -> {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    // follower -> set of people they follow
    unordered_map<int, unordered_set<int>> following;

    int time = 0;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        time++;

        tweets[userId].push_back({time, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        // {timestamp, tweetId}
        priority_queue<pair<int, int>> maxHeap;

        // Include user's own tweets
        for (auto tweet : tweets[userId]) {
            maxHeap.push(tweet);
        }

        // Include tweets of people user follows
        for (int followee : following[userId]) {
            for (auto tweet : tweets[followee]) {
                maxHeap.push(tweet);
            }
        }

        vector<int> ans;

        // Get 10 most recent tweets
        while (!maxHeap.empty() && ans.size() < 10) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};