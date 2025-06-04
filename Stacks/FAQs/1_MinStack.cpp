#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Brute Force Approach : O(1) time complexity, O(2n) space complexity


class MinStack {
    public:
        stack<pair<int, int>> st;
    
        MinStack() {
            
        }
        
        void push(int value) {
            if(st.empty()){
                st.push({value, value});
            }
            else st.push({value, min(value, st.top().second)});
        }
    
        void pop() {
            if(st.empty()){
                throw runtime_error("Stack Underflow");
            }
            else{
                st.pop();
            }
        }
    
        int top() {
            if(st.empty()){
                throw runtime_error("Stack Underflow");
            }
    
            return st.top().first;
        }
    
        int getMin() {
            if(st.empty()){
                throw runtime_error("Stack Underflow");
            }
            
            return st.top().second;  
        }
    };
    

    // Optimal Approach : O(1) time complexity, O(n) space complexity

    class MinStack {
        public:
            stack<int> st;
            stack<int> minSt;
        
            MinStack() {}
        
            void push(int value) {
                st.push(value);
                // Push the new minimum
                if (minSt.empty() || value <= minSt.top()) {
                    minSt.push(value);
                }
            }
        
            void pop() {
                if (st.empty()) {
                    throw runtime_error("Stack Underflow");
                }
        
                if (st.top() == minSt.top()) {
                    minSt.pop();
                }
                st.pop();
            }
        
            int top() {
                if (st.empty()) {
                    throw runtime_error("Stack Underflow");
                }
                return st.top();
            }
        
            int getMin() {
                if (minSt.empty()) {
                    throw runtime_error("Stack Underflow");
                }
                return minSt.top();
            }
        };
        