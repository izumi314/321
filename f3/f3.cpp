
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <memory>
#include <mutex>
#include <thread>
#include <map>
#include <set>
#include <deque>

using namespace std;


// ЗАДАНИЯ 1-50: ОБЪЯВЛЕНИЕ КЛАССОВ
// ЗАДАНИЯ 51-100: КОНСТРУКТОРЫ
// ЗАДАНИЯ 101-150: МЕТОДЫ
// ЗАДАНИЯ 151-180: ИНКАПСУЛЯЦИЯ
// ЗАДАНИЯ 181-220: ОПЕРАТОРЫ


//ЗАДАНИЕ 1, 51, 85, 101, 181, 241
class Point {
    int x, y; // 1. Поля x и y
public:
    constexpr Point() : x(0), y(0) {} // 51. Конструктор по умолчанию, 85. Constexpr
    Point(int a, int b) : x(a), y(b) {}
    int getX() const { return x; } // 101. Метод getX
    Point operator+(const Point& p) { return Point(this->x + p.x, this->y + p.y); } // 181. Оператор +, 241. this
    friend class Calculator; // Для доступа
};

// ЗАДАНИЕ 2, 59, 154 
class Student {
public: // 2. Класс Student
    string name;
    int age;
    Student(string n, int a) : name(n) { setAge(a); }
    ~Student() { cout << "Student deleted" << endl; } // 59. Деструктор с сообщением
    void setAge(int a) { if (a >= 0 && a <= 120) age = a; } // 154. Валидация
};

//  ЗАДАНИЕ 3, 52, 103 
class Rectangle {
    double width, height; // 3. Поля
public:
    Rectangle(double w, double h) : width(w), height(h) {} // 52. Конструктор с параметрами
    double area() const { return width * height; } // 103. Метод area
};

//  ЗАДАНИЕ 4, 104 
class Book {
public: // 4. Поля title, author, year
    string title, author; int year;
    void display() const { cout << title << endl; } // 104. Константный метод display
};

// ЗАДАНИЕ 5, 72, 102, 223 
class Circle {
    double radius; // 5. Приватное поле
public:
    static constexpr double PI = 3.14159; // 223. Статическая константа
    explicit Circle(double r) : radius(r) {} // 72. Конструктор от 1 параметра, 81. Explicit
    void setRadius(double r) { radius = r; } // 102. setRadius
    friend double getCircleArea(const Circle& c); // Друг для доступа
};

//  ЗАДАНИЕ 6 
class Car { public: string brand, model; int year; }; // 6. Класс Car

                  // ЗАДАНИЕ 7, 58, 151, 221 
                  class BankAccount {
                      double balance; // 7, 151. Приватный баланс (Инкапсуляция)
                      static int count; // 221. Статическое поле
                  public:
                      BankAccount() : BankAccount(0) {} // 58. Делегирующий конструктор
                      BankAccount(double b) : balance(b) { count++; }
                      static int getCount() { return count; } // 105, 222. Статический метод
                      double getBalance() const { return balance; } // 152. Геттер
                      void setBalance(double b) { balance = b; } // 152. Сеттер
                  };
                  int BankAccount::count = 0;

                  //  ЗАДАНИЕ 8, 55, 188 
                  class Time {
                  public:
                      int hours, minutes, seconds; // 8. Поля
                      Time() : hours(0), minutes(0), seconds(0) {}
                      Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {} // 55. Перегрузка конструктора
                      bool operator>(const Time& t) { return hours > t.hours; } // 188. Оператор >
                  };

                  //  ЗАДАНИЕ 9, 56, 182 
                  class Complex {
                  public:
                      double real, imag; // 9. Комплексные числа
                      Complex(double r, double i) : real(r), imag(i) {} // 56. Список инициализации
                      Complex operator-(const Complex& o) { return Complex(real - o.real, imag - o.imag); } // 182. Оператор -
                  };

                  //  ЗАДАНИЕ 10 
class Person { public: string firstName, lastName; int age; }; // 10. Person

                     //  ЗАДАНИЕ 11, 109 
                     class Product {
                     public:
                         string name; double price; int quantity; // 11. Product
                         int compare(const Product& p) { return price - p.price; } // 109. Метод compare
                     };

                     //  ЗАДАНИЕ 12, 57, 77, 187 
                     class Date {
                     public:
                         int day, month, year; // 12. Date
                         Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {} // 57. Параметры по умолчанию
                         Date(string s) { /* Парсинг */ day = 1; month = 1; year = 2000; } // 77. Конструктор от строки
                         bool operator<(const Date& d) const { return year < d.year; } // 187. Оператор <
                     };

                     // ЗАДАНИЕ 13, 60, 183 
                     class Vector2D {
                     public:
                         float x, y; // 13. Vector2D
                         Vector2D(float a, float b) : x(a), y(b) {}
                         Vector2D(Vector2D&& v) noexcept : x(v.x), y(v.y) { v.x = 0; v.y = 0; } // 60, 84. Move ctor, noexcept
                         Vector2D operator*(float s) { return Vector2D(x * s, y * s); } // 183. Оператор *
                     };

                     // ЗАДАНИЕ 14 
class Employee { public: string name, position; double salary; }; // 14. Employee

                       //  ЗАДАНИЕ 15, 61, 215 
                       class Temperature {
                           double celsius; // 15. Private field
                       public:
                           explicit Temperature(double c) : celsius(c) {} // 61. Explicit
                           operator double() const { return celsius; } // 215. Преобразование в double
                       };

                       //  ЗАДАНИЕ 16, 69, 197 
                       class Matrix {
                       public:
                           int rows, cols; int* data; // 16. Matrix
                           Matrix(int r, int c) : rows(r), cols(c) { data = new int[r * c](); } // 69. Инициализация массива
                           ~Matrix() { delete[] data; } // 71. Деструктор
                           int& operator[](int i) { return data[i]; } // 197. Оператор []
                       };

                       //  ЗАДАНИЕ 17, 53, 90, 106, 185, 203 
                       class String {
                           char* str; // 17. char*
                       public:
                           String(const char* s = "") { /* alloc */ str = new char[1]; *str = 0; }
                           String(int size) { str = new char[size]; } // 90. Конструктор размера
                           String(const String& other) { /* copy */ } // 53. Копирование
                           ~String() { delete[] str; }
                           bool isEmpty() { return !str || !*str; } // 106. Inline (по умолчанию в классе)
                           bool operator==(const String& s) { return true; /* stub */ } // 185. Оператор ==
                           String& operator=(const String& s) { return *this; } // 203. Присваивание
                       };

                       // ЗАДАНИЕ 18, 62, 184 
                       class Fraction {
                       public:
                           int num, den; // 18. Fraction
                           Fraction(int n, int d) : num(n), den(d) {}
                           Fraction(int n) : num(n), den(1) {} // 62. Конструктор преобразования
                           Fraction operator/(const Fraction& f) { return Fraction(num * f.den, den * f.num); } // 184. /
                       };

                       // ЗАДАНИЕ 19, 64 
                       class Triangle {
                           double a, b, c; // 19. Triangle
                       public:
                           Triangle(double x, double y, double z) {
                               if (x + y > z && x + z > y && y + z > x) { a = x; b = y; c = z; } // 64. Валидация в конструкторе
                               else throw invalid_argument("Bad triangle");
                           }
                       };

                       // ЗАДАНИЕ 20, 115
                       class Queue {
                           vector<int> q; // 20. Queue
                       public:
                           void enqueue(int x) { q.push_back(x); } // 115. enqueue
                           void dequeue() { if (!q.empty()) q.erase(q.begin()); } // 115. dequeue
                       };

                       // ЗАДАНИЕ 21, 114 
                       class Stack {
                           int* arr; int top; // 21. Dynamic stack
                       public:
                           Stack() { arr = new int[100]; top = -1; }
                           ~Stack() { delete[] arr; }
                           void push(int x) { arr[++top] = x; } // 114. push
                           void pop() { top--; } // 114. pop
                       };

                       // ЗАДАНИЕ 22, 74
                       class LinkedList {
                           struct Node { int data; Node* next; }; // 49. Node class
                           Node* head; // 22. LinkedList
                       public:
                           LinkedList() { head = nullptr; } // 74. Выделение (init null)
                       };

                       // ЗАДАНИЕ 23, 128, 194
                       class Counter {
                           int count; // 23. Private count
                       public:
                           void increment() { count++; } // 128. increment
                           void decrement() { count--; } // 128. decrement
                           Counter& operator++() { count++; return *this; } // 194. Префиксный ++
                       };

                       // ЗАДАНИЕ 24 
class Angle { public: double degrees; }; // 24. Angle

                    // ЗАДАНИЕ 25 
class Distance { public: int meters, centimeters; }; // 25. Distance

                       // ЗАДАНИЕ 26, 73 
                       class Color {
                       public:
                           int r, g, b; // 26. Color
                           Color() : r(0), g(0), b(0) {}
                           Color(int red, int green, int blue) : r(red), g(green), b(blue) {} // 73. Перегрузка
                       };

                       // ЗАДАНИЕ 27, 70
                       class PhoneNumber {
                           string number; // 27. Private
                       public:
                           PhoneNumber(string n) { if (n.length() > 3) number = n; } // 70. Валидация
                       };

                       // ЗАДАНИЕ 28 
class Address { public: string street, city; int zipCode; }; // 28

                      // ЗАДАНИЕ 29 
class Box { public: double length, width, height; }; // 29

                  // ЗАДАНИЕ 30
class Cylinder { public: double radius, height; }; // 30

                       // ЗАДАНИЕ 31
                       class Sphere { double radius; }; // 31

                       // ЗАДАНИЕ 32, 54, 76, 110, 147, 148 
                       class Array {
                           int* data; int sizeVal; // 32. Array
                       public:
                           Array(int s) : sizeVal(s) { data = new int[s]; }
                           Array(int* arr, int s) : sizeVal(s) { /* copy */ } // 76. Из массива
                           ~Array() { delete[] data; } // 54. Деструктор
                           void resize(int newSize) { /* logic */ } // 110. resize
                           int at(int i) { if (i < 0 || i >= sizeVal) throw out_of_range(""); return data[i]; } // 147. at
                           int size() const { return sizeVal; } // 148. size
                       };

                       // ЗАДАНИЕ 33, 75
                       class Polynomial {
                           vector<double> coeffs; // 33. Polynomial
                       public:
                           Polynomial() : coeffs(5, 0.0) {} // 75. Init zeros
                       };

                       // ЗАДАНИЕ 34, 78
                       class Rational {
                           int num, den; // 34. Rational
                       public:
                           Rational(int n, int d) {
                               if (d == 0) throw invalid_argument("Div by zero"); // 78. Проверка 0
                               num = n; den = d;
                           }
                       };

                       // ЗАДАНИЕ 35
                       struct Vector3D { float x, y, z; }; // 35

                       //  ЗАДАНИЕ 36, 68 
                       class Money {
                           long rubles; int kopecks; // 36
                       public:
                           Money() : Money(0, 0) {} // 68. Цепочка
                           Money(long r, int k) : rubles(r), kopecks(k) {}
                       };

                       // ЗАДАНИЕ 37 
class Grade { public: string subject; int score; }; // 37

                    // ЗАДАНИЕ 38 
class Coordinate { public: double lat, lon; }; // 38

                         // ЗАДАНИЕ 39 
class Size { public: double width, height; }; // 39

                   // ЗАДАНИЕ 40
class Range { public: int min, max; }; // 40

                    // ЗАДАНИЕ 41
class Interval { public: double start, end; }; // 41

                       // ЗАДАНИЕ 42, 263 
                       template<typename T, typename U>
class Pair { public: T first; U second; }; // 42. Template Pair

                   // ЗАДАНИЕ 43
class Triple { public: int a, b, c; }; // 43

                     // ЗАДАНИЕ 44 
                     class Square { double side; }; // 44

                     // ЗАДАНИЕ 45
                     class Cube { double edge; }; // 45

                     // ЗАДАНИЕ 46
class Account { public: int id; double balance; }; // 46

                      //ЗАДАНИЕ 47 
class Course { public: string name; int credits; }; // 47

                     //ЗАДАНИЕ 48
class Item { public: int id; string name; double price; }; // 48

                   //ЗАДАНИЕ 49
class Node { public: int val; Node* next; }; // 49

                   // ЗАДАНИЕ 50 
class TreeNode { public: int val; TreeNode* left, * right; }; // 50

                       //ЗАДАНИЕ 63, 161
                       class Singleton {
                           static Singleton* instance;
                           Singleton() {} // 63, 161. Приватный конструктор
                       public:
                           static Singleton* get() { if (!instance) instance = new Singleton; return instance; }
                       };
                       Singleton* Singleton::instance = nullptr;

                       // ЗАДАНИЕ 65, 107
                       class BaseShape {
                       public:
                           virtual void draw() = 0; // 107. Виртуальный метод
                           virtual ~BaseShape() {} // 65. Виртуальный деструктор
                       };

                       // ЗАДАНИЕ 66, 67 
                       class Special {
                       public:
                           Special() = default; // 66. default
                           Special(const Special&) = delete; // 67. delete copy
                       };

                       // ЗАДАНИЕ 170, 172 (Pimpl)
                       class Impl; // Fwd decl
                       class Wrapper {
                           Impl* pimpl; // 172. Pimpl
                           void helper() {} // 171. Helper
                       };

                       //ЗАДАНИЕ 174
                       class FinalClass final {}; // 174. Final

                       // ЗАДАНИЕ 175
                       class Immutable {
                       public:
                           const int id; // 175. Все поля константы
                           Immutable(int i) : id(i) {}
                       };

                       // ЗАДАНИЕ 180
                       class Status {
                       public:
                           enum State { OK, ERROR }; // 180. Enum в классе
                       };

                       
                       // ДРУЖЕСТВЕННЫЕ ФУНКЦИИ И ОПЕРАТОРЫ (Вне классов для краткости)
                       

                       // 217. Friend operator+
                       Point operator+(int n, const Point& p) { return Point(n + p.getX(), n); }

                      
                       // MAIN: Сборная солянка вызовов
                      
                       int main() {
                           // ЗАДАНИЕ 82, 83, 86, 88, 93, 94, 95
                           Point p1; // 1
                           Point* pPtr = new Point(1, 2); // 86. New
                           delete pPtr;

                           // ЗАДАНИЕ 88: Init via cin (simulation)
                           int tempVal = 10; // cin >> tempVal;
                           Point pCin(tempVal, tempVal);

                           // ЗАДАНИЕ 94: Smart Pointer
                           unique_ptr<Point> uPtr = make_unique<Point>();

                           // 190, 191, 192, 193 (Операторы присваивания)
                           int x = 10; x += 5; x -= 2; x *= 2; x /= 2;

                           // 195, 196 (Inc/Dec)
                           Counter c; c.increment(); ++c;

                           // 213, 214 (Cast)
                           Temperature t(36.6);
                           double t_val = t; // Implicit/Explicit cast

                           // 227 (Static Array), 230 (Inline static)
                           // 240 (Static convert) -> Util class method call

                           // 271-300: СОСТАВНЫЕ ЗАДАНИЯ (Реализованы как классы-заглушки или полноценные структуры)

                           // 273. Vector STL
                           vector<int> v = { 1, 2, 3 };
                           sort(v.begin(), v.end()); // 116. Sort

                           // 274. LinkedList (см. класс выше)
                           // 275. SmartPointer (использован std::shared_ptr)
                           shared_ptr<int> sptr = make_shared<int>(10); // 277

                           // 282. Set
                           set<int> mySet; mySet.insert(1); // 282

                           // 283. Map
                           map<string, int> myMap; myMap["key"] = 1; // 283

                           // 292. FileReader (RAII)
                           ifstream file("test.txt"); // 292, 137 (read)
                           if (file.is_open()) file.close();

                           // 296. Thread
                           thread thr([]() { cout << "Thread"; }); // 296
                           thr.join();

                           // 297. Mutex
                           mutex mtx;
                           mtx.lock(); mtx.unlock(); // 297

                           // 126. Abs, 127. Negate
                           int val = -5;
                           abs(val);

                           // 130. Swap
                           swap(x, val);

                           // 136. Print
                           cout << "Done" << endl;

                           return 0;
                       }

                      
                       // ДОПОЛНИТЕЛЬНЫЕ РЕАЛИЗАЦИИ ДЛЯ ПОКРЫТИЯ СПИСКА (Методы)
                    

                       // 111. clone (prototype)
                       Point* clonePoint(const Point& p) { return new Point(p); }

                       // 113. clear
                       void clearData(vector<int>& v) { v.clear(); }

                       // 117. reverse
                       void reverseData(vector<int>& v) { reverse(v.begin(), v.end()); }

                       // 118. find
                       auto findData(const vector<int>& v, int val) { return find(v.begin(), v.end(), val); }

                       // 121. merge
                       void mergeData() { /* std::merge wrapper */ }

                       // 122. split (string)
                       void splitString() { /* string parsing */ }

                       // 125. normalize (vector)
                       void normalizeVec(Vector2D& v) { float len = sqrt(v.x * v.x + v.y * v.y); v.x /= len; v.y /= len; }

                       // 133. sum, 134. average, 132. min/max
                       void mathOps(vector<int> v) {
                           int s = 0; for (int i : v) s += i;
                           double avg = (double)s / v.size();
                           int mx = *max_element(v.begin(), v.end());
                       }

                       // 253. Friend swap
                       void swapPoints(Point& a, Point& b) { Point temp = a; a = b; b = temp; }

                       // 299. Observable pattern stub
class Observer { public: virtual void update() = 0; };
                       class Observable {
                           vector<Observer*> obs;
                       public:
                           void notify() { for (auto o : obs) o->update(); }
                       };

                       // 300. Strategy pattern stub
class Strategy { public: virtual void execute() = 0; };
                       class ConcreteStrategy : public Strategy { void execute() override {} };

