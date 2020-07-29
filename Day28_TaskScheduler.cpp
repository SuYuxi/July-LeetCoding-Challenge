class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> counter;
        int maxCount = 0;
        int maxNum = 0;
        for(char& task : tasks)
        {
            counter[task] += 1;
            if(counter[task] > maxNum)
            {
                maxNum = counter[task];
                maxCount = 1;
            }
            else if (counter[task] == maxNum) maxCount += 1;
        }
      
        int partNum = maxNum - 1;
        int partLen = n - maxCount + 1;
        int slots = partNum * partLen;
        int availableTasks = tasks.size() - maxNum * maxCount;
        int idle = max(0, slots - availableTasks);
        return tasks.size() + idle;   
    }
};
