/*
Создать шаблонный класс-контейнер Array, который представляет собой массив, 
позволяющий хранить объекты заданного типа.

Класс должен реализовывать следующие функции:
	■ GetSize – получение размера массива (количество элементов,
под которые выделена память);
	■ SetSize(int size, int grow = 1) – установка размера массива
(если параметр size больше предыдущего размера массива, то
выделяется дополнительный блок памяти, если нет, то «лишние» элементы теряются и память освобождается); параметр
grow определяет для какого количества элементов необходимо выделить память, если количество элементов превосходит
текущий размер массива. Например, SetSize(5, 5); означает,
что при добавлении 6-го элемента размер массива становится
равным 10, при добавлении 11-го - 15 и т. д.;
	■ GetUpperBound - получение последнего допустимого индекса в массиве. Например, если при размере массива 10, вы добавляете в него 4 элемента, то функция вернет 3;
	■ IsEmpty - массив пуст?;
	■ FreeExtra - удалить «лишнюю» память (выше последнего допустимого индекса);
	■ RemoveAll – удалить все;
	■ GetAt-получение определенного элемента (по индексу);
	■ SetAt – установка нового значения для определенного элемента (индекс элемента должен быть меньше текущего размера
массива);
	■ operator [] – для реализации двух предыдущих функций;
	■ Add – добавление элемента в массив (при необходимости
массив увеличивается на значение grow функции SetSize);
	■ Append – «сложение» двух массивов;
	■ operator =;
	■ GetData – получения адреса массива с данными;
	■ InsertAt – вставка элемента(-ов) в заданную позицию;
	■ RemoveAt – удаление элемента(-ов) с заданной позиции

*/
#include <stdexcept>

template<typename T>
class Array
{
private:
	T* data;
	int size;
	int capacity;
	int grow;
	int upperBound;

public:
	Array(int initSize=1, int growSize=1) : grow(growSize), upperBound(-1) {
			capacity = size = initSize;
			data = (size > 0) ? new T[size] : nullptr;

	}

	Array(const Array& other) {
		copyObj(other);
	}

	~Array() {
		if (data) delete[] data;
	}

	Array& operator=(const Array& other) {
		if (this != &other) {
			if (data) delete[] data;
			copyObj(other);
		}
	}

	int GetSize() const {
		return size;
	}

	void SetSize(int newSize, int newGrow = 1) {

		// newSize - новый размер массива
		// newGrow - шаг, на который увеличивается capacity.
		grow = newGrow;

		if (newSize == size) return;
	
		if (newSize > size) {
			int newCapacity = size;
			while (newCapacity < newSize) {
				newCapacity += grow;
			}
			reserve(newCapacity);

		}

		size = newSize;
		
		
		if (upperBound >= size)
			upperBound = size - 1;
	}

	int GetUpperBound() const { return upperBound; }

	bool IsEmpty() const { return upperBound == -1; }


	void FreeExtra() {
		if (size > upperBound + 1) {
			size = upperBound + 1;
			T* newData = new T[size];
			for (int i = 0; i < upperBound; i++) {
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
			capacity = size;
		}
	}

	void RemoveAll() {
		upperBound = -1;
		size = 0;
		capacity = 0;
		if (data) {
			delete[] data;
			data = nullptr;
		}
	}
	
	T GetAt(int indx) const {
		if (indx < 0 || indx > upperBound) {
			throw std::out_of_range("Invalid invalid");
		}
		return data[indx];
	}

	void SetAt(int index, const T& value) {
		if (index < 0 || index > upperBound) {
			throw std::out_of_range("Invalid invalid");
		}

		data[index] = value;

		if (index > upperBound) {
			upperBound = index;
		}
	}

	T& operator[](int index) {
		if (index < 0 || index > upperBound) {
			throw std::out_of_range("Invalid invalid");
		}
		return data[index];
	}

	const T& operator[](int index) const {
		if (index < 0 || index > upperBound) {
			throw std::out_of_range("Invalid invalid");
		}
		return data[index];
	}

	void Add(const T& value) {
		if (upperBound + 1 >= size) {
			SetSize(size + grow, grow);
		}
		data[++upperBound] = value;

	}

	void Append(const Array& other) {
		int newUpper = upperBound + other.GetUpperBound() + 1;
		if (newUpper >= size) {
			SetSize(newUpper + 1, grow);
		}

		for (int i = 0; i <= other.GetUpperBound(); i++) {
			data[++upperBound] = other[i];
		}
	}

	T* GetData() const { return data; }

	void InsertAt(int index, const T& value) {
		if (index < 0 || index > upperBound + 1) {
			throw std::out_of_range("Invalid index");
		}

		if (upperBound + 1 >= size) {
			SetSize(size + grow, grow);
		}

		for (int i = upperBound + 1; i > index; i--) {
			data[i] = data[i - 1];
		}

		data[index] = value;
		upperBound++;
	}

	void RemoveAt(int index) {
		if (index < 0 || index > upperBound) {
			throw std::out_of_range("Invalid index");
		}


		for (int i = index; i < upperBound; i++) {
			data[i] = data[i + 1];
		}

		upperBound--;
	}



private:
	void copyObj(const Array& other) {
		size = other.size;
		capacity = other.capacity;
		grow = other.grow;
		upperBound = other.upperBound;
		data = new T[capacity];
		for (int i = 0; i <= upperBound; i++) {
			data[i] = other.data[i];
		}
	}

	void reserve(int newCapacity) {
		if (newCapacity <= capacity) return;

		T* newData = new T[newCapacity];

		for (int i = 0; i <= upperBound; i++) {
			newData[i] = data[i];
		}

		if (data) delete[] data;
		data = newData;
		capacity = newCapacity;
	}

};