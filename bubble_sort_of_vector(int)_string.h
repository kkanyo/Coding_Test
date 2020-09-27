#pragma once
#include <vector>
#include <iostream>

using std::vector;
using std::string;

//정수 벡터에 대한 버블 정렬
void BubbleSortVector(vector<int> &v)
{
	int temp;
	
	for (int i = v.size() - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[j] > v[j + 1])
			{
				temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
	return;
}

//문자열에 대한 버블 정렬
void BubbleSortString(string &s)
{
	char temp;

	//변수 i와 j는 string::iterator타입임에 주의
	for (auto i = s.end() - 1; i != s.begin(); i--)
	{
		for (auto j = s.begin(); j != i; j++)
		{
			if (*j > *(j + 1))
			{
				temp = *j;
				*j = *(j + 1);
				*(j + 1) = temp;
			}
		}
	}
	return;
}