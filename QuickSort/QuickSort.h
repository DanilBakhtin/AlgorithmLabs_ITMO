#pragma once
#include <iostream>
using namespace std;
//Максимальный размер массива для быстрой сортировки
int const M = 43;

//Быстрая сортировка
template<typename T, typename Compare>
void quickSort(T* first, T* last, Compare comp) {

    if (!first || !last) throw ("NULLPTR!");

    
    while (first < last)
    {
        if (last - first <= M)
        {
            insertionSort(first, last, comp);
            return;
        } 
            mediana(first,last,comp);

            T* pivot = partition(first, last, comp);

            if (pivot - first < last - pivot)
            {
                quickSort(first, pivot, comp);
                first = pivot + 1;
            }
            else
            {
                quickSort(pivot + 1, last, comp);
                last = pivot - 1;
            }
        
    }

}

//Нахождение медианы из первого, среднего и последнего элемента массива
template<typename T, typename Compare>
void mediana(T* first, T* last, Compare comp) {

    T* middle = first + (last - first) / 2;
    if (comp(*last, *first)) swap(*last, *first);
    if (comp(*middle, *first)) swap(*middle, *first);
    if (comp(*last, *middle)) swap(*last, *middle);
}

template<typename T, typename Compare>
T* partition(T* first, T* last, Compare comp) {
    
    auto pivot = *(first + (last - first) / 2);

    auto i = first;
    auto j = last;

    while (true)
    {
        while (comp(*(++i), pivot));
        while (comp(pivot, *(--j)));
        if (i >= j) break;

        std::swap(*(i), *(j));
    }
    std::swap(pivot, *(i));
    
    return i;
    
}

//Сортировка вставками
template<typename T, typename Compare>
void insertionSort(T* first, T* last, Compare comp)
{
    for (auto i = first; i <= last; i++)
    {
        auto j = i - 1;

        T val = *(j + 1);
        while (j >= first && comp(val, *j))
        {
            *(j + 1) = move(*j);
            j--;
        }
        *(j + 1) = val;
    }

}

template<typename T>
void printArray(T* first, T* last) {

    for (auto i = first + 1; i <= last; i++) {
        cout << *i << " ";
    }
    cout << endl;
}

template<typename T, typename Compare>
void printArray(T* first, T* last, Compare comp) {

    bool s = true;
    T* sl = first;

    cout << *sl << " ";
    for (auto i = first + 1; i <= last; i++) {
        cout << *i << " ";
        if (!comp(*sl, *i))
            s = false;
        sl = i;
    }
    cout << endl << s << endl;
}