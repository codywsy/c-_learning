class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         map<int, int> m;
        for (int i=0; i<nums.size(); i++){
            m[nums[i]]=i;
        }
        
        int max_seq=0; 
        for (int i=0; i<nums.size(); i++){
            int cnt=1;
            
            for(int n = nums[i]+1;m.find(n)!=m.end();n++){
                m.erase(m.find(n));
                cnt++;
                
            }
            for(int n = nums[i]-1;m.find(n)!=m.end();n--){
                m.erase(m.find(n));
                cnt++;
            }
            if (max_seq < cnt){
                max_seq = cnt;
            }
            if (m.size()==0){
                break;
            }
        }
        return max_seq;
    }
};