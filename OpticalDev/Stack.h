#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
template <class T>
class Stack
{
private:
	T* pStack;
	int Index;
	int Size;
public:
	Stack();
	Stack(int);
	void push(T&& );
	void pop();
	void Sort(bool (*cmp)(const T& a, const T& b));
	template <class N>
	T* Search(N val, bool (*find)(N val, const T& tmp));
	void Print();
	int Length() const;
	T& operator [](int);
};
template <class T>
Stack<T>::Stack()
{
	pStack = new T[10];
	Index = 0;
	Size = 2;
}
template <class T>
Stack<T>::Stack(int size)
{
	pStack = new T[size];
	Index = 0;
	Size = size;
}
template <class T>
void Stack<T>::push(T&& val)
{
	try
	{
		if (Index >= Size) throw OpticalDevEx("Стек полон!");
		else pStack[Index++] = val;
	}
	catch (OpticalDevEx(e)) { cout << "Ошибка: " << e.GetError() << endl; }
}
template <class T>
void Stack<T>::pop()
{
	try {
		if (Index == 0) throw OpticalDevEx("Стек пуст!");
	T* tmp = new T[Size - 1];
	for (int i = 0; i < Size - 1; i++) { tmp[i] = pStack[i]; }
	delete[] pStack;
	pStack = new T[Size - 1];
	pStack = tmp;
	Size--;
	Index--;
	}
	catch (OpticalDevEx(e)) { cout << "Ошибка: " << e.GetError() << endl; }
}
template <class T>
void Stack<T>::Print()
{
	try {
		if (Index == 0) throw OpticalDevEx("Стек пуст!");
	else {
		cout << "Стек: " << endl;
		for (int i = 0; i < Index; i++)
		{
			cout << i << " - " << pStack[i] << endl;
		}
		cout << endl;
	}
	}
	catch (OpticalDevEx(e)) { cout << "Ошибка: " << e.GetError() << endl; }
}
template <class T>
int Stack<T> ::Length() const 
{
	return Index;
}
template <class T>
void Stack<T>::Sort(bool (*val)(const T& a, const T& b))
{
	try {
		if (Index == 0) throw OpticalDevEx("Стек пуст!");
		int step = Size / 2;
		while (step > 0)
		{
			for (int i = 0; i < Index - step; i++)
			{
				int j = i;
				while (j >= 0 && val(pStack[j], pStack[j + step]))
				{
					swap(pStack[j], pStack[j + step]);
					j -= step;
				}
			}
			step /= 2;
		}
	}
	catch (OpticalDevEx(e)) { cout << "Ошибка: " << e.GetError() << endl; }
}
template <class T> template <class N>
T* Stack<T>::Search(N val, bool (*find)(N val, const T& tmp))
{
	try {
		if (Index == 0) throw OpticalDevEx("Стек пуст!");
		int tmp = 0;
		for (int i = 0; i < Index; i++)
		{
			if (FindName(val, pStack[i])) return &pStack[i];
		}
		return nullptr;
	}
	catch (OpticalDevEx(e)) { cout << "Ошибка: " << e.GetError() << endl; }
}
template <class T>
T& Stack<T> ::operator[](int val)
{
	try {
		if (val<0 || val>Size - 1) throw OpticalDevEx("Нет такого индекса");
	}
	catch (OpticalDevEx(e)) { cout << "Ошибка: " << e.GetError() << endl; }
	return pStack[val];
}