#include <bits/stdc++.h>

using namespace std;



string cutLeadingSpaces(string str){

    string newStr = "";
    bool get = false;
    int len = str.size();

    for(int i = 0; i < len; i++){
        if(get == false && str[i] != '0'){
            get = true;
            newStr += str[i];

        }else if(get){
            newStr += str[i];
        }
    }

    return str = newStr;

}

int powerFunc(int base, int limit){

    int ans = 1;

    for(int i = 1; i <= limit; i++){
        ans *= base;
    }

    return ans;
}

int convertIntoInt(string str){

    int len = str.size();
    int res = 0, x = 0;
    for(int i = len - 1; i >= 0; i--){
        res += powerFunc(10, x) * (str[i] - '0');
        x++;
    }

    return res;
}

string divideByTwo(string str){



    string newStr = "", temp = "";
    int num, mod,len = str.size();

    for(int i = 0; i < len; i++){
        temp+= str[i];
       // cout << temp ;
        num = convertIntoInt(temp);
        mod = num%2;
        num /= 2;
        temp = (mod + '0');
        newStr += (num + '0');
        //cout << " " << newStr << endl;
    }//loop

    return str = cutLeadingSpaces(newStr);

}//func

int solution(string str){

    while(true){
        int len = str.size();
        int lastDigit = str[len-1] -'0';
        if(lastDigit%2 != 0 ) return 0;
        else {
            str = divideByTwo(str);
            if(str == "1") return 1;
        }
    } //loop

    return 0;
}

int main()
{
   string str;

   while(cin >> str){
     if(solution(str)) cout << "power of two" << endl;
     else cout << "not a power of two\n";
   }//loop
}





