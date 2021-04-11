#pragma once

#include "Pair.h"

//клас "FuzzyNumber" --- для представлення нечітких чисел і виконання арифметичних операцій
class FuzzyNumber : public Pair {
private:
	//поля "x", "l" і "r" ---  потрібні для роботи з нечіткими числами
	double x, l, r;
public:
	FuzzyNumber();							//конструкторт за умовчанням(без параметрів)
	FuzzyNumber(double, double, double);	//конструктор ініціалізації

	void Set_x(double);			//встановлення значення поля "x"
	void Set_l(double);			//встановлення значення поля "l"
	void Set_r(double);			//встановлення значення поля "r"

	double Get_x() const;		//отримання значення поля "x"
	double Get_l() const;		//отримання значення поля "l"
	double Get_r() const;		//отримання значення поля "r"

	virtual FuzzyNumber* operator + (Pair*);					//віртуальний перевантаження операції додавання
	virtual FuzzyNumber* operator - (Pair*);					//віртуальний перевантаження операції віднімання
	virtual FuzzyNumber* operator * (Pair*);					//віртуальний перевантаження операції множення
	virtual FuzzyNumber* operator / (Pair*);					//віртуальний перевантаження операції ділення

	friend FuzzyNumber operator / (int, const FuzzyNumber&);	//перевантаження операції зворотне число(наприклад 1/A)

	virtual std::ostream& Data_otput(std::ostream& out) const;		//чистий віртуальний метод виводу даних
	virtual std::istream& Data_entry(std::istream& in);			//чистий віртуальний метод вводу даних
};