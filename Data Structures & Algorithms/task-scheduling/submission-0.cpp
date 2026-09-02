class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char, int> freq;

        // Count frequencies
        for (char task : tasks) {
            freq[task]++;
        }

        // Max heap
        priority_queue<int> maxHeap;

        for (auto& [task, count] : freq) {
            maxHeap.push(count);
        }

        int time = 0;

        while (!maxHeap.empty()) {
            
            vector<int> temp;

            // One cycle/window can contain n + 1 tasks
            for (int i = 0; i <= n; i++) {
                
                if (!maxHeap.empty()) {
                    int count = maxHeap.top();
                    maxHeap.pop();

                    count--;

                    if (count > 0) {
                        temp.push_back(count);
                    }

                    time++;
                }
                else {
                    // No task available
                    if (temp.empty()) {
                        break;
                    }

                    time++; // idle
                }
            }

            // Put remaining tasks back
            for (int count : temp) {
                maxHeap.push(count);
            }
        }

        return time;
    }
};
