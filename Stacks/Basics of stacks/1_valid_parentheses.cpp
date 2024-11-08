class Solution {

public:
    bool matchCharacters(char previous, char current){

        if((previous == '(' && current == ')') ||
            (previous == '{' && current == '}') ||
            (previous == '[' && current == ']')
           ){
                return true;
           }

        return false;
    }

public:
    bool isValid(string str) {
       stack<char> st;

       for(int i = 0; i < str.size(); i++){

            if(str[i] == '(' || str[i] == '{' || str[i] == '['){
                st.push(str[i]);
            }
            else{

                if(st.empty()){
                    return false;
                }

                char prevCharacter = st.top();
                
                if(!matchCharacters(prevCharacter, str[i])){
                    return false;
                }

                st.pop();
            }
       }

       if(!st.empty()){
        return false;
       }

       return true; 
    }
};