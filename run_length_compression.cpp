#include<bits/stdc++.h>
using namespace std;
class RLE{
private:
	string msg;
public:
	void get_input(){
		cin>>msg;
	}
	string itos(int cnt){
		string ans = "";
		int rem = 0;
		while(cnt){
			ans += '0' + cnt%10;
			cnt = cnt/10;
		}
		reverse(ans.begin(),ans.end());
		return ans;
	}
	string encoder(){
		string ans = "";
		int cnt = 1;
		for(int i=1;i<msg.length();i++){
			if(msg[i]==msg[i-1])
				cnt++;
			else if(msg[i]!=msg[i-1]){
				ans+=msg[i-1];
				ans += itos(cnt);
				cnt = 1;
			}
		}
		ans+=msg[msg.length()-1];
		ans+=itos(cnt);
		return ans;
	}
	string decoder(string en_str){
		string ans = "";
		string temp="";
		bool chk = false;
		for(int i=0;i<en_str.length();i++){
			if(i==0){
				ans+=en_str[i];
			}
			else if(((int)en_str[i]>=65&&(int)en_str[i]<=90)||((int)en_str[i]>=97&&(int)en_str[i]<=122)){
				ans += string(stoi(temp)-1,ans[ans.length()-1]);
				temp = "";
				ans+=en_str[i];
			}

			else if((int)en_str[i]>=48&&(int)en_str[i]<=57){
				temp+=en_str[i];
			}
		}
		ans += string(stoi(temp)-1,ans[ans.length()-1]); 
		// string ( size_t n, char c );
		// Content is initialized as a string formed by a 
		// repetition of character c, n times.
		return ans;
	}
};
int main(){
	freopen("..//input.txt","r",stdin);
	freopen("..//output.txt","w",stdout);
	RLE r1;
	r1.get_input();
	string encoded_string = r1.encoder();
	string decoded_string = r1.decoder(encoded_string);
	cout<<"Encoded String: "<<encoded_string<<"\n";
	cout<<"Decoded String: "<<decoded_string<<"\n";
	return 0;
}