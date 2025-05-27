class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
          int n = asteroids.size();
          vector<int> st;
    
            for(int i = 0; i < n; i++){
                if(asteroids[i] > 0){
                    st.push_back(asteroids[i]);
                }
                else{
                    while(!st.empty() && st.back() > 0 && abs(asteroids[i]) > st.back()){ 
                        st.pop_back();
                    }
                    
                    if(st.empty() || st.back() < 0) st.push_back(asteroids[i]);
                    else if(!st.empty() && abs(asteroids[i]) == st.back()){
                        st.pop_back();
                    }
                }
            }
    
            return st;  
        }
    };