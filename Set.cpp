#include "Set.h"
#include <iostream>

Set::Set(const Set& second) {
    size = second.size;
    arr = second.arr;
}

Set::~Set() {
    if (!arr)
        delete[] arr;
}


int Set::operator[](const int index) { //получение числа по его индексу 
    if (!arr)
        throw std::logic_error("arr == nullptr");
    if (index > size - 1 || index < 0)
        throw std::logic_error("invalide index");
    return arr[index];
}


Set Set::operator+(const Set& second) { //объединение множеств 
    Set res(size + second.size);
    res.size = 0;
    for (int i = 0; i < size; i++) {
        res.arr[i] = arr[i];
        res.size++;
    }
    for (int i = 0; i < second.size; i++) {
        if (check_num(second.arr[i]) == false)
        {
            res.arr[res.size] = second.arr[i];
            res.size++;
        }
    }
    return res;
}


Set Set::operator-(const Set& second) { //разность множеств  
    Set res(size);
    res.size = 0;
    bool flag = false;
    for (int i = 0; i < size; i++) {
        flag = false;
        for (int j = 0; j < second.size; j++) {
            if (arr[i] == second.arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            res.arr[res.size] = arr[i];
            res.size++;
        }
    }
    return res;
}

Set& Set::operator+(int num) { //добавление числа во множество
    if (!arr)
    {
        arr = new int[size];
        arr[0] = num;
        size++;
    }
    if (check_num(num) == false)
    {
        Set arr_n(size + 1);
        for (int i = 0; i < size; i++) {
            arr_n.arr[i] = arr[i];
        }
        arr_n.arr[size] = num;
        arr = arr_n.arr;
        size++;
    }
    return *this;
}

Set& Set::operator-(int num) //удаление числа из множества
{
    if (check_num(num) == false)
        throw std::logic_error("Set have not got this num");
    for (int i = 0; i < size; i++) {
        if (arr[i] == num)
        {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            break;
        }
    }
    return *this;
}

Set& Set::operator+=(int num) { //добавление числа во множество 

    if (!arr)
    {
        arr = new int[size];
        arr[0] = num;
        size++;
    }
    if (check_num(num) == false)
    {
        Set _arr(size + 1);
        for (int i = 0; i < size; i++) {
            _arr.arr[i] = arr[i]; 
            _arr.arr[size] = 0;
        }
        _arr.arr[size] += num;
        arr = _arr.arr;
        size++;
    }
    return *this;
}

Set& Set::operator-=(int num) { //удаление числа из множества
    if (check_num(num) == false)
        throw std::logic_error("Set have not got this num");
    for (int i = 0; i < size; i++) {
        if (arr[i] == num)
        {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            break;
        }
    }
    return *this;
}

Set Set::intersection(const Set& second) { //пересечение множеств
    Set res(size);
    res.size = 0;
    bool flag = false;
    for (int i = 0; i < size; i++) {
        flag = false;
        for (int j = 0; j < second.size; j++) {
            if (arr[i] == second.arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            res.arr[res.size] = arr[i];
            res.size++;
        }
    }
    return res;
}

bool Set::check_count(const Set& second) { // элементы 1 множества хотя бы раз встречаются во втором
    if (!arr)
        throw std::logic_error("arr == nullptr");
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        flag = false;
        for (int j = 0; j < second.size; j++) {
            if (arr[i] == second.arr[j])
                flag = true;
        }
        if (flag == false)
            return false;
    }
    return true;
}

bool Set::operator==(const Set& second) { //равенство множеств
    if (second.size != size)
        return false;
    else
    {
        bool flag = false; // 2 3 и 3 2 
        for (int i = 0; i < size; i++)
        {
            flag = false;
            for (int j = 0; j < second.size; j++) {
                if (arr[i] == second.arr[j]) {
                    flag = true;
                }
            }
            if (flag == false)
                return false;
        }
        return true;
    }
}

bool Set::operator!=(const Set& second) { //неравенство множеств 
    if (second.size != size)
        return true;
    else
    {
        bool flag = true; // 2 3 и 3 2 
        for (int i = 0; i < size; i++)
        {
            flag = true;
            for (int j = 0; j < second.size; j++) {
                if (arr[i] == second.arr[j]) {
                    flag = false;
                }
            }
            if (flag == true)
                return true;
        }
        return false;
    }
}

bool Set::check_num(int num) { //проверка наличия числа во множестве
    if (!arr)
        throw std::logic_error("arr == nullptr in check_num");
    for (int i = 0; i < size; i++) {
        if (num == arr[i])
            return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& s, const Set& set) //вывод
{
    for (int i = 0; i < set.size; i++) {
        s << set.arr[i] << " ";
    }
    return s;
}
