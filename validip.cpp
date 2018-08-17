//https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#define FOR(i,n) for(int i = 0; i < n; i++)

using namespace std;

bool lIsValidField(const string& s) 
{
	if (s.empty()) 
		return false;
	
	// it can be 0
	if (s == "0") 
		return true;

	// it can not start with 0 
	if (s[0] == '0') 
		return false;

	// should not greater than 255
	unsigned long long  num = strtoull(s.c_str(), NULL, 10);
	if (num > 255) 
		return false;
	return true;
}

void genIpInternal(const string& s, int xStart, int xLevel, vector<string>& xOneIpField, vector<string>& xResult) 
{
	if (xStart >= s.size()) 
		return ;
	
	if (xLevel == 4) 
	{
		// at last level we need to form string from start to end
		string tmp = s.substr(xStart);
		if(lIsValidField(tmp)) 
		{
			xOneIpField.push_back(tmp);
			// yes, we got a final IP 
			string lResult;
			for (int i = 0; i < 4; i ++) 
			{
				lResult += xOneIpField[i];
				if (i != 3) 
					lResult += ".";
			}
			xResult.push_back(lResult);
			xOneIpField.pop_back();
		}
	}
	else 
	{
		for (int i =  1; i < s.size(); i++) 
		{
			if (xLevel == 1) 
			{
				xOneIpField.clear();
			}
			string tmp = s.substr(xStart, i);
			if (lIsValidField(tmp)) 
			{
				xOneIpField.push_back(tmp);
				genIpInternal(s, xStart+i, xLevel+1, xOneIpField, xResult);
				xOneIpField.pop_back();
			}
		}
	}
}

vector<string> genIp(const string& s) 
{
	vector<string> lResult;
	vector<string> lOneIP;
	genIpInternal(s, 0, 1, lOneIP, lResult);
	if (lResult.size()>0) 
		cout<<1<<endl;
	else 
		cout<<0<<endl;
	return lResult;
}

int main() 
{
	std::ios_base::sync_with_stdio(false);
	string s;
	cin>>s;
	auto lResult = genIp(s);
	for (auto v:lResult) 
		cout<<v<<" ";
	cout<<"\n";
}
