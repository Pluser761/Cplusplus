#pragma once

using namespace std;

class table
{
private:
	char ***data; // ���� �������, � ������� ������ ������� - ����
	int i, j, **arr; // i,j - ����� � �������� data � arr, arr - ������ ����� ����� � data
public:
	table();
	table(int,int);
	~table();
};

table::table()
{
	data = 0;
	i = 0;
	j = 0;
	arr = 0;
}

table::table(int i, int j)
{
}

table::~table()
{
}