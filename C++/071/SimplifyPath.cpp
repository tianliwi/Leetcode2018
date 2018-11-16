class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        int len = path.length();
        stack<string> dir;
        int curPos = 0;
        string token = "";
        while(curPos<len){
            if(path[curPos]=='/') {
                token = "";
                curPos++;
                continue;
            }
            while(path[curPos]!='/'){
                token += path[curPos++];
            }
            if (token=="." || token=="") continue;
            if (token=="..") {
                if (!dir.empty()) dir.pop();
                continue;
            }
            cout << token << endl;
            dir.push(token);
        }
        string ans = "";
        while(!dir.empty()){
            ans = "/" + dir.top() + ans;
            dir.pop();
        }
    
        return ans =="" ? "/" : ans;
    }
};