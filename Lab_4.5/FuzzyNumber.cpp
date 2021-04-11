#include "FuzzyNumber.h"


//конструкторт за умовчанням(без параметрів)
FuzzyNumber::FuzzyNumber() : x(0), l(0), r(0) {}
//конструктор ініціалізації
FuzzyNumber::FuzzyNumber(double v_x, double v_l, double v_r) {
	if (v_x > (v_x - v_l) && (v_x + v_r) > v_x) {
		x = v_x;
		l = v_l;
		r = v_r;
	}
	else {
		x = 0;
		l = 0;
		r = 0;
	}
}

void FuzzyNumber::Set_x(double value) { x = value; }	//встановлення значення поля "x"
void FuzzyNumber::Set_l(double value) { l = value; }	//встановлення значення поля "l"
void FuzzyNumber::Set_r(double value) { r = value; }	//встановлення значення поля "r"

double FuzzyNumber::Get_x() const { return x; }			//отримання значення поля "x"
double FuzzyNumber::Get_l() const { return l; }			//отримання значення поля "l"
double FuzzyNumber::Get_r() const { return r; }			//отримання значення поля "r"

FuzzyNumber* FuzzyNumber::operator + (Pair* obj) {		//віртуальний перевантаження операції додавання
	FuzzyNumber* obj_a = new FuzzyNumber;
	obj_a->Set_x(this->Get_x() + ((FuzzyNumber*)obj)->Get_x() - this->Get_l() - ((FuzzyNumber*)obj)->Get_l());
	obj_a->Set_l(this->Get_x() + ((FuzzyNumber*)obj)->Get_x());
	obj_a->Set_r(this->Get_x() + ((FuzzyNumber*)obj)->Get_x() + this->Get_r() + ((FuzzyNumber*)obj)->Get_r());

	return obj_a;
}

FuzzyNumber* FuzzyNumber::operator - (Pair* obj) {		//віртуальний перевантаження операції віднімання
	FuzzyNumber* obj_a = new FuzzyNumber;
	obj_a->Set_x(this->Get_x() - ((FuzzyNumber*)obj)->Get_x() - this->Get_l() - ((FuzzyNumber*)obj)->Get_l());
	obj_a->Set_l(this->Get_x() - ((FuzzyNumber*)obj)->Get_x());
	obj_a->Set_r(this->Get_x() - ((FuzzyNumber*)obj)->Get_x() + this->Get_r() + ((FuzzyNumber*)obj)->Get_r());

	return obj_a;
}

FuzzyNumber* FuzzyNumber::operator * (Pair* obj) {		//віртуальний перевантаження операції множення
	FuzzyNumber* obj_a = new FuzzyNumber;
	obj_a->Set_x(this->Get_x() * ((FuzzyNumber*)obj)->Get_x() - ((FuzzyNumber*)obj)->Get_x() * this->Get_l() - this->Get_x() * ((FuzzyNumber*)obj)->Get_l() - this->Get_l() * ((FuzzyNumber*)obj)->Get_l());
	obj_a->Set_l(this->Get_x() * ((FuzzyNumber*)obj)->Get_x());
	obj_a->Set_r(this->Get_x() * ((FuzzyNumber*)obj)->Get_x() + ((FuzzyNumber*)obj)->Get_x() * this->Get_r() + this->Get_x() * ((FuzzyNumber*)obj)->Get_r() + this->Get_r() * ((FuzzyNumber*)obj)->Get_r());

	return obj_a;
}

FuzzyNumber* FuzzyNumber::operator / (Pair* obj) {		//віртуальний перевантаження операції ділення
	FuzzyNumber* obj_a = new FuzzyNumber;
	obj_a->Set_x((this->Get_x() - this->Get_l()) / (((FuzzyNumber*)obj)->Get_x() + ((FuzzyNumber*)obj)->Get_r()));
	obj_a->Set_l(this->Get_x() / ((FuzzyNumber*)obj)->Get_x());
	obj_a->Set_r((this->Get_x() + this->Get_r()) / (((FuzzyNumber*)obj)->Get_x() - ((FuzzyNumber*)obj)->Get_l()));

	return obj_a;
}

FuzzyNumber operator / (int one, const FuzzyNumber& obj) {	//перевантаження операції зворотне число(наприклад 1/A)
	FuzzyNumber obj_a;
	if (obj.Get_x() > 0) {
		obj_a.Set_x((one * 1.0) / (obj.Get_x() + obj.Get_r()));
		obj_a.Set_l((one * 1.0) / (obj.Get_x()));
		obj_a.Set_r((one * 1.0) / (obj.Get_x() - obj.Get_l()));
	}
	else
		std::cout << "\n\nThe condition is not met!!!";

	return obj_a;
}

std::ostream& FuzzyNumber::Data_otput(std::ostream& out) const {	//чистий віртуальний метод виводу даних
	out << "\nData_otput object: ";
	out << "\nx = " << x;
	out << "\nl = " << l;
	out << "\nr = " << r;

	return out;
}

std::istream& FuzzyNumber::Data_entry(std::istream& in) {			//чистий віртуальний метод вводу даних
	double a{}, b{}, c{};
	bool perevirka{};

	std::cout << "\n\nData_entry object: ";
	do {
		std::cout << "\nVvedit znachenie x: "; in >> a;
		std::cout << "Vvedit znachenie l: "; in >> b;
		std::cout << "Vvedit znachenie r: "; in >> c;

		if (((a - b) < a) && (a < (a + c)))
			perevirka = true;
		else {
			std::cout << "\nNe chitko vvedeni dani(value)!!!";
			perevirka = false;
		}
	} while (!perevirka);

	x = a;
	l = b;
	r = c;

	return in;
}