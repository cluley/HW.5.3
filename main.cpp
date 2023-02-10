#include <iostream> 

class Figure {
public:
	bool virtual check();
	void virtual print_info();
	std::string get_intro() { return intro; }
protected:
	int sides = 0;
	std::string intro = "Фигура: ";
};

bool Figure::check() {
	if (sides == 0) {
		return true;
	}
	else {
		return false;
	}
}

void Figure::print_info() {
	std::cout << intro << std::endl;

	if (check()) {
		std::cout << "Правильная" << std::endl;
	}
	else {
		std::cout << "Неправильная" << std::endl;
	}
	
	std::cout << "Колличество сторон: " << sides << '\n' << std::endl;
}

class Triangle : public Figure {
public:
	Triangle(int a, int b, int c, int A, int B, int C);
	bool check() override;
	void print_info() override;
protected:
	int side_a;
	int side_b;
	int side_c;
	int angle_A;
	int angle_B;
	int angle_C;
};

Triangle::Triangle(int a, int b, int c, int A, int B, int C) {
	sides = 3;
	intro = "Треугольник: ";
	side_a = a;
	side_b = b;
	side_c = c;
	angle_A = A;
	angle_B = B;
	angle_C = C;
}

bool Triangle::check() {
	if (sides == 3 && (angle_A + angle_B + angle_C) == 180) {
		return true;
	}
	else {
		return false;
	}
}

void Triangle::print_info() {
	std::cout << intro << std::endl;

	if (check()) {
		std::cout << "Правильная" << std::endl;
	}
	else {
		std::cout << "Неправильная" << std::endl;
	}

	std::cout << "Колличество сторон: " << sides << std::endl;
	std::cout << "Стороны: a = " << side_a << " b = " << side_b << " c = " << side_c << std::endl;
	std::cout << "Углы: A = " << angle_A << " B = " << angle_B << " C = " << angle_C << std::endl;
	std::cout << std::endl;
}

class R_Triangle : public Triangle {
public:
	R_Triangle(int a, int b, int c, int A, int B);
	bool check() override;
};

R_Triangle::R_Triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
	intro = "Прямоугольный треугольник: ";
	side_a = a;
	side_b = b;
	side_c = c;
	angle_A = A;
	angle_B = B;
	angle_C = 90;
}

bool R_Triangle::check() {
	if (angle_C == 90) {
		return true;
	}
	else {
		return false;
	}
}

class I_Triangle : public Triangle {
public:
	I_Triangle(int a, int b, int A, int B);
	bool check() override;
};

I_Triangle::I_Triangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
	intro = "Равнобедренный треугольник: ";
	side_a = a;
	side_b = b;
	side_c = a;
	angle_A = A;
	angle_B = B;
	angle_C = A;
}

bool I_Triangle::check() {
	if (side_a == side_c && angle_A == angle_C) {
		return true;
	}
	else {
		return false;
	}
}

class E_Triangle : public Triangle {
public:
	E_Triangle(int a, int A);
	bool check() override;
};

E_Triangle::E_Triangle(int a, int A) : Triangle(a, a, a, A, A, A) {
	intro = "Равносторонний треугольник: ";
	side_a = a;
	side_b = a;
	side_c = a;
	angle_A = A;
	angle_B = A;
	angle_C = A;
}

bool E_Triangle::check() {
	if (side_a == side_c && side_c == side_b && angle_A == angle_C && angle_C == angle_B) {
		return true;
	}
	else {
		return false;
	}
}

class Quadrangle : public Figure {
public:
	Quadrangle();
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);
	bool check() override;
	void print_info() override;
protected:
	int side_a;
	int side_b;
	int side_c;
	int side_d;
	int angle_A;
	int angle_B;
	int angle_C;
	int angle_D;
};

Quadrangle::Quadrangle() {
	sides = 4;
	intro = "Четырехугольник: ";
	side_a = 10;
	side_b = 20;
	side_c = 30;
	side_d = 40;
	angle_A = 50;
	angle_B = 60;
	angle_C = 70;
	angle_D = 80;
}

Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
	sides = 4;
	intro = "Четырехугольник: ";
	side_a = a;
	side_b = b;
	side_c = c;
	side_d = d;
	angle_A = A;
	angle_B = B;
	angle_C = C;
	angle_D = D;
}

bool Quadrangle::check() {
	if (sides == 4 && (angle_A + angle_B + angle_C + angle_D) == 360) {
		return true;
	}
	else {
		return false;
	}
}

void Quadrangle::print_info() {
	std::cout << intro << std::endl;

	if (check()) {
		std::cout << "Правильная" << std::endl;
	}
	else {
		std::cout << "Неправильная" << std::endl;
	}

	std::cout << "Колличество сторон: " << sides << std::endl;
	std::cout << "Стороны: a = " << side_a << " b = " << side_b << " c = " << side_c << " d = " << side_d << std::endl;
	std::cout << "Углы: A = " << angle_A << " B = " << angle_B << " C = " << angle_C << " D = " << angle_D << std::endl;
	std::cout << std::endl;
}

class Rectangle : public Quadrangle {
public:
	Rectangle(int a, int b);
	bool check() override;
};

Rectangle::Rectangle(int a, int b) : Quadrangle(a, a, a, a, 90, 90, 90, 90) {
	intro = "Прямоугольник: ";
	side_a = a;
	side_b = b;
	side_c = a;
	side_d = b;
	angle_A = 90;
	angle_B = 90;
	angle_C = 90;
	angle_D = 90;
}

bool Rectangle::check() {
	if (side_a == side_c && side_b == side_d && angle_A == 90 && angle_B == 90 && angle_C == 90 && angle_D == 90) {
		return true;
	}
	else {
		return false;
	}
}

class Square : public Quadrangle {
public:
	Square(int a);
	bool check() override;
};

Square::Square(int a) {
	intro = "Квадрат: ";
	side_a = a;
	side_b = a;
	side_c = a;
	side_d = a;
	angle_A = 90;
	angle_B = 90;
	angle_C = 90;
	angle_D = 90;
}

bool Square::check() {
	if (side_a == side_c && side_b == side_d && side_a == side_b && angle_A == angle_C && angle_B == angle_D && angle_A == angle_B) {
		return true;
	}
	else {
		return false;
	}
}

class Parallelogram : public Quadrangle {
public:
	Parallelogram(int a, int b, int A, int B);
	bool check() override;
};

Parallelogram::Parallelogram(int a, int b, int A, int B) {
	intro = "Параллелограмм: ";
	side_a = a;
	side_b = b;
	side_c = a;
	side_d = b;
	angle_A = A;
	angle_B = B;
	angle_C = A;
	angle_D = B;
}

bool Parallelogram::check() {
	if (side_a == side_c && side_b == side_d && angle_A == angle_C && angle_B == angle_D) {
		return true;
	}
	else {
		return false;
	}
}

class Rhombus : public Quadrangle {
public:
	Rhombus(int a, int A, int B);
	bool check() override;
};

Rhombus::Rhombus(int a, int A, int B) {
	intro = "Ромб: ";
	side_a = a;
	side_b = a;
	side_c = a;
	side_d = a;
	angle_A = A;
	angle_B = B;
	angle_C = A;
	angle_D = B;
}

bool Rhombus::check() {
	if (side_a == side_c && side_b == side_d && side_a == side_b && angle_A == angle_C && angle_B == angle_D) {
		return true;
	}
	else {
		return false;
	}
}

int main(int argc, char** argv) {
	Figure figure;

	Triangle triangle(10, 20, 30, 50, 60, 70);
	Figure* triangle_P = &triangle;

	R_Triangle r_triangle(10, 20, 30, 40, 50);
	Figure* r_triangle_P = &r_triangle;

	I_Triangle i_triangle(10, 20, 40, 80);
	Figure* i_triangle_P = &i_triangle;

	E_Triangle e_triangle(30, 60);
	Figure* e_triangle_P = &e_triangle;

	Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	Figure* quadrangle_P = &quadrangle;

	Rectangle rectangle(20, 40);
	Figure* rectangle_P = &rectangle;

	Square square(20);
	Figure* square_P = &square;

	Parallelogram parallelogram(20, 30, 40, 50);
	Figure* parallelogram_P = &parallelogram;

	Rhombus rhombus(30, 40, 50);
	Figure* rhombus_P = &rhombus;

	figure.print_info();
	triangle_P->print_info();
	r_triangle_P->print_info();
	i_triangle_P->print_info();
	e_triangle_P->print_info();
	quadrangle_P->print_info();
	rectangle_P->print_info();
	square_P->print_info();
	parallelogram_P->print_info();
	rhombus_P->print_info();

	return 0;
}