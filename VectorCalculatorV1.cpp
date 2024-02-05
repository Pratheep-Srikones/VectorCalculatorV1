#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

class Vector {
private:
	double x, y, z;
public:
	Vector() {
		x = 0;
		y = 0;
		z = 0;
	}
	Vector(double x, double y) {
		this->x = x;
		this->y = y;
		z = 0;
	}
	Vector(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vector operator+(Vector v) {
		Vector resultVector;
		resultVector.x += this->x + v.x;
		resultVector.y += this->y + v.y;
		resultVector.z += this->z + v.z;
		return resultVector;
	}
	Vector operator-(Vector v) {
		Vector resultVector;
		resultVector.x += this->x - v.x;
		resultVector.y += this->y - v.y;
		resultVector.z += this->z - v.z;
		return resultVector;
	}
	Vector operator*(Vector v) {
		Vector resultVector;
		resultVector.x += this->x * v.x;
		resultVector.y += this->y * v.y;
		resultVector.z += this->z * v.z;
		return resultVector;
	}
	// % operator means vector multiplication
	Vector operator%(Vector v) {
		Vector resultVector;
		resultVector.x += ((this->y * (v.z)) - (this->z * (v.y)));
		resultVector.y += -((this->x * (v.z)) - (this->z * (v.x)));
		resultVector.z += ((this->x * (v.y)) - (this->y * (v.x)));
		return resultVector;
	}
	double findSize() {
		double size = sqrt(x * x + y * y + z * z);
		return size;
	}
	Vector findUnitVector() {
		double size = findSize();
		Vector unitVector;
		unitVector.x += this->x / size;
		unitVector.y += this->y / size;
		unitVector.z += this->z / size;
		return unitVector;
	}
	void printVector() {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
		cout << "Result: <" << x << ", " << y << ", " << z << ">" << endl;
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	void printDirectionalAngles() {
		double size = findSize();
		double alpha, beta, gamma;
		alpha = acos(x / size);
		beta = acos(y / size);
		gamma = acos(z / size);
		cout << "α = " << alpha << " β = " << beta << " γ = " << gamma << endl;

	}
	void printInfo() {
		printVector();
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
		cout << "Size: " << findSize() << endl;
		cout << "Directional Angles(in radions): " << flush;
		printDirectionalAngles();
		cout << "Unit vector along the direction: " << flush;
		findUnitVector().printVector();
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		

	}

};

void printInstructions() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "Please consider the number systems for the functions" << endl;
	cout << "1. Addition" << endl;
	cout << "2. Subtraction" << endl;
	cout << "3. Scalar Multiplication" << endl;
	cout << "4. Vector Multiplication" << endl;
	cout << "5. Get information of a vector" << endl;
	cout << "0. Close the program" << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int getUserInput() {
	int input;
	cout << "Please enter your choice: " << flush;
	cin >> input;
	return input;
}

Vector createVector() {
	double x, y, z;
	cout << "Please enter the coordinates of the vector (x, y, z)-space separated: " << flush;
	cin >> x >> y >> z;
	Vector inputVector(x, y, z);
	return inputVector;
}

Vector add() {
	cout << "Please Enter First vector" << endl;
	Vector vector1 = createVector();
	cout << "Please Enter Second vector" << endl;
	Vector vector2 = createVector();
	return vector1 + vector2;
}

Vector subtract() {
	cout << "Please Enter First vector" << endl;
	Vector vector1 = createVector();
	cout << "Please Enter Second vector" << endl;
	Vector vector2 = createVector();
	return vector1 - vector2;
}

Vector scalarMultiplication() {
	cout << "Please Enter First vector" << endl;
	Vector vector1 = createVector();
	cout << "Please Enter Second vector" << endl;
	Vector vector2 = createVector();
	return vector1 * vector2;
}

Vector vectorMultiplication() {
	cout << "Please Enter First vector" << endl;
	Vector vector1 = createVector();
	cout << "Please Enter Second vector" << endl;
	Vector vector2 = createVector();
	return vector1 % vector2;
}
int main() {
	cout << "Welcome to Vector calculator" << endl;
	while (true) {
		printInstructions();
		int input = getUserInput();
		if (input == 0) {
			cout << "Done" << endl;
			exit(0);
		}
		else if (input == 1) {
			Vector result1 = add();
			result1.printVector();
		}
		else if (input == 2) {
			Vector result2 = subtract();
			result2.printVector();
		}
		else if (input == 3) {
			Vector result3 = scalarMultiplication();
			result3.printVector();
		}
		else if (input == 4) {
			Vector result4 = vectorMultiplication();
			result4.printVector();
		}
		else if (input == 5) {
			Vector result5 = createVector();
			result5.printInfo();
		}
		else {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			cout << "Please enter a valid choice!" << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
	}
}
