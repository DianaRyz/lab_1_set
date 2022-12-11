#pragma once
#include <iostream>


class Set {
	int* arr;
	int size;

public:
	Set() : arr(nullptr), size(0) {} 
	Set(int size) : arr(new int[size]), size(size) {} 
	Set(const Set& second); 
	~Set();

	int operator[](const int index);

	Set operator+(const Set& second);
	Set operator-(const Set& second);

	Set& operator+(int num);
	Set& operator-(int num);

	friend Set& operator+=(Set &_arr, int num);
	Set& operator-=(int num);

	Set intersection(const Set& second);
	bool check_count(const Set& second);
	bool check_num(int num);

	bool operator==(const Set& second);
	bool operator!=(const Set& second);

	friend std::ostream& operator<<(std::ostream& s, const Set& set);
};