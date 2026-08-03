class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int i =0;i<nums.size();i++){
            freq[nums[i]]++;
        }
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
       for(pair<const int,int> p : freq){
        int num = p.first;
        int f = p.second;
             if(pq.size()<k){
                pq.push({p.second,p.first});
             }
             else if (pq.top().first<f){
                pq.pop();
                 pq.push({p.second,p.first});
             }
       }
       vector<int>ans;
       while(!pq.empty()){
        int val = pq.top().second;
        pq.pop();
        ans.push_back(val);
       }
       return ans;
    }
};
