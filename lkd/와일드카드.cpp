#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

bool match(string w, string s)
{
	int pos = 0;
	// 문제 없는 상황에 진행한다면
	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
	{
		pos += 1;
	}
	// 만약 둘의 길이의 마지막에 만났다면 w의 끝까지 왔다면 
	if (pos == w.size())
	{
		return pos == s.size();
	}
	if (w[pos] == '*')
	{
		for (int skip = 0; pos + skip <= s.size(); ++skip)
		{
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;
		}
		return false;
	}
}


int main()
{
	//? : 어떤 글자와도 대응된다 사이즈는 같아야 한다
	//* : 0글자 이상의 어떤 문자열에도 대응

	vector<string> vecstr{"help", "heap", "helpp"};
	vector<string> vecanswer;
	string str; //너는 사용자가 입력한 값

	str = "*p*";
	match(str, vecstr[2]);
	for (int i = 0; i < str.size(); ++i)
	{
		//대문자가 들어갈 확률 65 ~ 90
		if (str[0] >= 'A' || str[0] <= 'Z')
		{
			//
		}
		
		str[i];
	}


	return 0;
}