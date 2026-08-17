class Solution {
public:
   bool CanEat(vector<int>& piles,int speed,int time){
    int ans =0;
       for(int i =0;i<piles.size();i++){
        ans+=piles[i]/speed;
        if(piles[i]%speed!=0)ans++;
       }
       return ans<=time;
   }
    int minEatingSpeed(vector<int>& piles, int h) {
        int st =1;
        int end = *max_element(piles.begin(),piles.end());
        while(st<end){
            int mid = (st+end)/2;
            if(CanEat(piles,mid,h)){
                end = mid;
            }else{
                st = mid+1;
            }
        }
        return st;
    }
};
