#include "Complex.h"


//конструкторт за умовчанням(без параметрів)
Complex::Complex() : a(0), b(0) {}
//конструктор ініціалізації
Complex::Complex(double v_a, double v_b) : a(v_a), b(v_b) { }

void Complex::Set_a(double value) { a = value; }		//встановлення значення поля "a"
void Complex::Set_b(double value) { b = value; }		//встановлення значення поля "b"

double Complex::Get_a() const { return a; }		//отримання значення поля "a"
double Complex::Get_b() const { return b; }		//отримання значення поля "b"

Complex* Complex::operator + (Pair* obj) {		//віртуальний перевантаження операції додавання
	Complex* obj_a = new Complex;
	obj_a->Set_a(this->Get_a() + ((Complex*)obj)->Get_a());
	obj_a->Set_b(this->Get_b() + ((Complex*)obj)->Get_b());

	return obj_a;
}

Complex* Complex::operator - (Pair* obj) {		//віртуальний перевантаження операції віднімання
	Complex* obj_a = new Complex;
	obj_a->Set_a(this->Get_a() - ((Complex*)obj)->Get_a());
	obj_a->Set_b(this->Get_b() - ((Complex*)obj)->Get_b());

	return obj_a;
}

Complex* Complex::operator * (Pair* obj) {		//віртуальний перевантаження операції множення
	Complex* obj_a = new Complex;
	obj_a->Set_a(this->Get_a() * ((Complex*)obj)->Get_a() - this->Get_b() * ((Complex*)obj)->Get_b());
	obj_a->Set_b(this->Get_a() * ((Complex*)obj)->Get_b() + ((Complex*)obj)->Get_a() * this->Get_b());

	return obj_a;
}

Complex* Complex::operator / (Pair* obj) {		//віртуальний перевантаження операції ділення
	Complex* obj_a = new Complex;
	obj_a->Set_a((this->Get_a() * ((Complex*)obj)->Get_a() + this->Get_b() * ((Complex*)obj)->Get_b()) / (((Complex*)obj)->Get_a() * ((Complex*)obj)->Get_a() + ((Complex*)obj)->Get_b() * ((Complex*)obj)->Get_b()));
	obj_a->Set_b((((Complex*)obj)->Get_a() * this->Get_b() - this->Get_a() * ((Complex*)obj)->Get_b()) / (((Complex*)obj)->Get_a() * ((Complex*)obj)->Get_a() + ((Complex*)obj)->Get_b() * ((Complex*)obj)->Get_b()));

	return obj_a;
}


bool operator == (Complex& obj_1, Complex& obj_2) {		//перевантаження операції порівняння
	if ((obj_1.Get_a() == obj_2.Get_a()) && (obj_1.Get_b() == obj_2.Get_b())) {
		return true;
	}
	return false;
}

void Complex::Conj() {		//метод --- комплексне спряжене число
	b = -b;
}

std::ostream& Complex::Data_otput(std::ostream& out) const {	//чистий віртуальний метод виводу даних
	out << "\nData_otput complex number: ";
	out << "\na = " << a;
	out << "\nb = " << b;

	return out;
}

std::istream& Complex::Data_entry(std::istream& in) {			//чистий віртуальний метод вводу даних
	std::cout << "\n\nData_entry object: ";
	std::cout << "\nVvedit znachenie a: "; in >> a;
	std::cout << "Vvedit znachenie b: "; in >> b;

	return in;
}