class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int flag = 0;
        int lenA = a.size()-1;
        int lenB = b.size()-1;
        while (lenA >= 0 || lenB >= 0){
            int num1 = ( lenA < 0 ) ? 0 : a[lenA]-'0';
            int num2 = ( lenB < 0 ) ? 0 : b[lenB]-'0';
            if (num1 + num2 + flag >=2){
                char t = num1 + num2 + flag -2 + '0';
                s = t+s;
                flag = 1;
            }else{
                char t = num1 + num2 + flag + '0';
                s = t+s;
                flag = 0;
            }
            lenA--;
            lenB--;
        }
        
        if (flag == 1){
            s="1"+s;
        }
        return s;
    }
};

//mine
class Solution {
public:
    string addBinary(string a, string b) {

        int len = max(a.length(), b.length());
        if(a.length() == b.length()){
            a = "0" + a;
            b = "0" + b;
        }
        if(a.length() < b.length()){
           string s(b.length()-a.length() + 1,'0');
           a = s + a;  
            b = "0"+ b;
        }
        else if(b.length() < a.length()){
            string s(a.length()-b.length() + 1,'0');
            b = s + b;
            a = "0"+ a;
        }
        
        string c(len+1,'0');
        string ans(len+1,'0');
        for(int i = len; i > 0 ; i--){
            
            if(a[i]-'0' + b[i]-'0' + c[i]-'0' == 0){
                ans[i] = '0';
            }
            if(a[i]-'0' + b[i]-'0' + c[i]-'0' == 1){
                ans[i] ='1';
            }
            if(a[i]-'0' + b[i]-'0' + c[i]-'0' == 2){
                ans[i] = '0';
                c[i-1] = '1';
            }
            if(a[i]-'0' + b[i]-'0' + c[i]-'0' == 3){
                ans[i] = '1';
                c[i-1] = '1';
               
                
            }          
        }
        
        if(c[0] == '1'){
            ans[0] = '1';
        }
        else{
            string ret(len,'0');
            for(int i = 1,j=0; i < ans.length(); i++, j++){
                ret[j] = ans[i];
                
            }
            return ret;
            
        }
        return ans;
    }
};
