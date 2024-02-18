// 12.5.cpp
// < Горанов Анастас >
// Лабораторна робота № 12.5
// Стеки
// Варіант 10

#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cassert>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

double performOperation(char op, double operand1, double operand2) {
    switch (op) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    default:
        return 0.0;  // В разі помилки повертаємо 0.0
    }
}

double evaluatePrefixExpression(const std::string& expression, double a, double b, double c, double d) {
    std::stack<double> stack;

    for (int i = expression.length() - 1; i >= 0; i--) {
        char currentChar = expression[i];

        if (isOperator(currentChar)) {
            double operand1 = stack.top();
            stack.pop();
            double operand2 = stack.top();
            stack.pop();
            double result = performOperation(currentChar, operand1, operand2);
            stack.push(result);
        }
        else {
            double value;
            switch (currentChar) {
            case 'a':
                value = a;
                break;
            case 'b':
                value = b;
                break;
            case 'c':
                value = c;
                break;
            case 'd':
                value = d;
                break;
            default:
                value = 0.0;  // В разі помилки використовуємо 0.0
                break;
            }
            stack.push(value);
        }
    }

    return stack.top();
}

int main() {
    // Задані значення змінних
    double a = 5;
    double b = 3;
    double c = 2;
    double d = 4;

    // Вхідний вираз
    std::string expression = "-a*+b-c-/da-bcd";

    // Обчислення
    double result = evaluatePrefixExpression(expression, a, b, c, d);

    // Виведення результату
    std::cout << "Meaning of the expression: " << result << std::endl;

    return 0;
}
