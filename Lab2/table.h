#pragma once

using namespace std;

class table
{
private:
	char ***data; // сама таблица, в которой первый столбец - хеши
	int i, j, **arr; // i,j - строк и столбцов data и arr, arr - массив длинн строк в data
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