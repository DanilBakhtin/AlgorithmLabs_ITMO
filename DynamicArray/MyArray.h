#pragma once
#include <iostream>

using namespace std;

template<typename T>
class MyArray final
{	
public:
	class Iterator {
		T* cur;
		T* first;
		MyArray<T>* arr;
		bool isRev;
	public:
		Iterator(T* first1, MyArray<T>* input, bool isRev) {
			cur = first = first1;
			arr = input;
			this->isRev = isRev;
		}

		T& operator+ (int n) { return *(cur + n); }
		T& operator- (int n) { return *(cur - n); }

		T& operator++ (int) { return *cur++; }
		T& operator-- (int) { return *cur--; }
		T& operator++ () { return *++cur; }
		T& operator-- () { return *--cur; }

		bool operator!= (const Iterator& it) { return cur != it.cur; }
		bool operator== (const Iterator& it) { return cur == it.cur; }
		T& operator* () { return *cur; }

		const T& get() const {
			return *cur;
		};

		void set(const T& value) {
			*cur = value;
		};

		void next() {
			if (!isRev)
				cur += 1;
			else cur -= 1;
		};

		bool hasNext() const {
			if (!isRev) {
				if (cur == arr->size_ + first)
					return false;
				else return true;
			}
			else {
				if (cur == first - arr->size_)
					return false;
				else return true;
			}
		};

	};
	MyArray();
	MyArray(MyArray &other);
	MyArray(MyArray &&other) noexcept;
	MyArray(int capacity);
	~MyArray();
	int insert(const T& value);
	int insert(int index, const T& value);
	void remove(int index);
	const T& operator[](int index) const;
	T& operator[](int index);
	MyArray<T>& operator=(MyArray&other);
	MyArray<T>& operator=(MyArray&&other) noexcept;
	int size() const;
	int capacity() const;
	Iterator iterator() {
		return Iterator(data_,this,false);
	};
	Iterator reverseIterator() {
		return Iterator(data_ + size_ - 1, this, true);
	};
	T* alloc(size_t size)
	{
		auto data = (T*)std::malloc(size * sizeof(T));
		for (int i = 0; i < size; i++)
			new(&data[i]) T{};

		return data;
	}
private:
	size_t size_;
	size_t capacity_;
	const size_t defaultSize_ = 16;
	T* data_;
	void addMemory();
};

//Конструктор по умолчанию
template<typename T>
inline MyArray<T>::MyArray()
{
	capacity_ = defaultSize_;
	size_ = 0;
	data_ = alloc(capacity_);
}
//Конструктор копирования
template<typename T>
inline MyArray<T>::MyArray(MyArray& other)
{
	if (this != &other) {
		data_ = alloc(other.capacity_);
		for (auto i = 0; i < other.size_; ++i)
			data_[i] = other.data_[i];
		size_ = other.size_;
		capacity_ = other.capacity_;
	}
}
//Конструктор move-перемещения
template<typename T>
inline MyArray<T>::MyArray(MyArray&& other) noexcept
{
	if (this != &other) {
		data_ = other.data_;
		size_ = other.size_;
		capacity_ = other.capacity_;
		other.data_ = nullptr;
		other.size_ = other.capacity_ = 0;
	}
}
//Конструктор с начальным размером массива
template<typename T>
inline MyArray<T>::MyArray(int capacity)
{	
	capacity_ = capacity;
	size_ = 0;
	data_ = alloc(capacity_);
}
//Деструктор
template<typename T>
inline MyArray<T>::~MyArray()
{
	for (int i = 0; i < size_; i++)
		(&((T*)data_)[i])->~T();

	free(data_);
}
//Добавление памяти
template<typename T>
inline void MyArray<T>::addMemory()
{
	capacity_ *= 2;
	T* new_data_ = alloc(capacity_);

	for (auto i = 0; i < size_; i++) {
		new_data_[i] = data_[i];
	}

	free(data_);

	data_ = new_data_;
	new_data_ = nullptr;
}
//Вставка элемента в конец
template<typename T>
inline int MyArray<T>::insert(const T& value)
{	
	if (size_ == capacity_) {
		addMemory();
	}
	data_[size_++] = move(value);

	return size_;
}
//Вставка элемента по индексу
template<typename T>
inline int MyArray<T>::insert(int index, const T& value)
{
	if (size_ == capacity_) {
		addMemory();
	}
	if (index < 0 || index >= size_)
		return -1;

	size_++;

	if (is_move_constructible<T>()) {
		T sl = move(data_[index]);
		data_[index] = move(value);

		T sl2;
		for (auto i = index + 1; i < size_; i++) {
			sl2 = move(data_[i]);
			data_[i] = sl;
			sl = move(sl2);
		}
	}
	else {
		T sl = data_[index];
		data_[index] = value;

		T sl2;
		for (auto i = index + 1; i < size_; i++) {
			sl2 = data_[i];
			data_[i] = sl;
			sl = sl2;
		}
	}


	return index;
}
//Удаление элемента по индексу
template<typename T>
inline void MyArray<T>::remove(int index)
{
	if (index < 0 || index >= size_)
		throw "Empty container\n";

	if (is_move_constructible<T>()) {
		for (auto i = index + 1; i < size_; i++)
			data_[i - 1] = move(data_[i]);
	}
	else {
		for (auto i = index + 1; i < size_; i++)
			data_[i - 1] = data_[i];
	}


	size_--;
}
//Оператор, который возвращает константную ссылку на элемент
template<typename T>
inline const T& MyArray<T>::operator[](int index) const
{
	if (index < 0 || index >= size_) {
		throw "Invalid index access\n";
	}
	return data_[index];
}
//Оператор, который возвращает обычную ссылку на элемент
template<typename T>
inline T& MyArray<T>::operator[](int index)
{
	if (index < 0 || index >= size_) {
		throw "Invalid index access\n";
	}
	return data_[index];
}
template<typename T>
inline MyArray<T>& MyArray<T>::operator=(MyArray& other)
{
	if (this != &other) {
		free(data_);
		data_ = alloc(other.capacity_);
		for (size_t i = 0; i < other.size_; ++i) 
			data_[i] = other.data_[i];
		size_ = other.size_;
		capacity_ = other.capacity_;
	}
	return *this;
}
template<typename T>
inline MyArray<T>& MyArray<T>::operator=(MyArray&& other) noexcept
{
	if (this != &other) {
		free(data_);
		data_ = other.data_;
		size_ = other.size_;
		capacity_ = other.capacity_;
		other.data_ = nullptr;
		other.size_ = other.capacity_ = 0;
	}
	return *this;
}
//Размер массива
template<typename T>
inline int MyArray<T>::size() const
{
	return size_;
}
//Размер выделенной памяти
template<typename T>
inline int MyArray<T>::capacity() const
{
	return capacity_;
}
