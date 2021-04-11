#pragma once

#include <sstream>
#include <iostream>

class Pair {	//інтерфейс(базовий клас) --- відповідає за виконання арифметичних операцій
public:
	virtual Pair* operator + (Pair*) = 0;	//віртуальний перевантаження операції додавання
	virtual Pair* operator - (Pair*) = 0;	//віртуальний перевантаження операції віднімання
	virtual Pair* operator * (Pair*) = 0;	//віртуальний перевантаження операції множення
	virtual Pair* operator / (Pair*) = 0;	//віртуальний перевантаження операції ділення

	virtual std::ostream& Data_otput(std::ostream& out) const = 0;	//чистий віртуальний метод виводу даних
	virtual std::istream& Data_entry(std::istream& in) = 0;			//чистий віртуальний метод вводу даних
};