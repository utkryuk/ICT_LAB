#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define rep(i, n) for(ll i = 0; i < n; i++)
void file_in_out(){    
    #ifndef ONLINE_JUDGE
    freopen("//home//ryuk//Documents//cp//input.txt", "r", stdin);
    freopen("//home//ryuk//Documents//cp//output.txt", "w", stdout);
    #endif
}
bitset<32> decimal2Binary(double fraction){
	bitset<32> bin = 0;
	int i = 1;
	while (i <= 32 && fraction)
	{
		fraction *= 2;
		if (floor(fraction))
		{
			bin[32 - i] = 1;
			fraction -= 1;
		}
		i++;
	}
	return bin;
}
void encoder(string in, map<char, double> prob){
	srand(time(NULL));
	double ans = 0, low = 0, new_range = 1;
	double high = low + new_range;
	rep(i,in.length()){
		if(in[i]==prob.begin()->first){
			low = low;
			high = low + new_range*(prob[in[i]]);
			new_range = high - low;
		}
		else{
			map<char, double>:: iterator prev = prob.lower_bound(in[i]);
			high = low + new_range*(prob[prev->first]);
			prev--;
			low = low + new_range*(prob[prev->first]);
			new_range = high - low;
		}
	}
	cout<<"Final Interval in floating point is: ["<<low<<" , "<<high<<"]"<<"\n";
	cout<<"\nSo, We can take any number between this interval and then convert into binary,\n";
	cout<<"\nSo, taking the mid point of this interval : "<<(low+high)/2<<"\n";
	cout<<"\nBinary Equivalent for transmission : "<<decimal2Binary(double((low+high)/2));

}
int main(){
	int tt = clock(); 		
	file_in_out();
	cout<<"\t\tWELCOME TO ARITHMETIC ENCODER\n\n";
	string in;
	cin>>in;
	map<char, ll> alpha;
	rep(i,in.length()){
		alpha[in[i]]++; 
	}
	map<char, double> prob;
	for(auto i:alpha){
		prob[i.first] = double(i.second)/double(in.length());
	}
	map<char,double>::iterator i = prob.begin();
	for(i = next(i,1);i!=prob.end();i++){
		i->second = i->second + prev(i,1)->second;
	}
	encoder(in,prob);
	cerr << "TIME = " << (double) 1.0 * (clock() - tt) / CLOCKS_PER_SEC << " seconds" << endl;
	return 0;
}


/*

Input: ARBER (or Any other string)

Output:

		WELCOME TO ARITHMETIC ENCODER

Final Interval in floating point is: [0.14432 , 0.1456]

So, We can take any number between this interval and then convert into binary,

So, taking the mid point of this interval : 0.14496

Binary Equivalent for transmission : 00100101000111000001100100111011

*/