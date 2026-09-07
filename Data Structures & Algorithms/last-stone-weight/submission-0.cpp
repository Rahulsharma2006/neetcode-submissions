class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i =0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
          int element1 = pq.top();
          pq.pop();
          int element2 = pq.top();
          pq.pop();
          int NewElement = abs(element1-element2);
          pq.push(NewElement);
        }
        return pq.top();
    }
};