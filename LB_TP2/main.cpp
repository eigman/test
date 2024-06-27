#include <iostream>
#include "stack.h"
#include "float.h"

void printMenu() {
    std::cout << "Меню:\n"
        << "1. Добавить элемент\n"
        << "2. Удалить элемент\n"
        << "3. Префиксный ++ оператор\n"
        << "4. Постфиксный ++ оператор\n"
        << "5. Префиксный -- оператор\n"
        << "6. Постфиксный -- оператор\n"
        << "7. Проверить стек на наличие элементов\n"
        << "8. Вывести стек\n"
        << "9. Вещественные числа\n"
        << "0. Выход\n"
        << "q. Использовать второй конструктор\n"
        << "Выбор: ";
}

int desk(){}

int main() {
    setlocale(LC_ALL, "Russian");
    Stack myStack;

    char choice;
    bool exit = false;

  /*  int intValue = 5;
    RealNumber num = intValue;*/

    while (!exit) {
        system("cls");
        printMenu();
        std::cin >> choice;

        switch (choice) {
        case '1': {
            int value;
            std::cout << "Введите значение:";
            std::cin >> value;
            if (value == 0)
                myStack.push();
            else
                myStack.push(value);
            break;
        }
        case '2': {
            if (!myStack) {
                std::cout << "Стек пуст." << std::endl;
            }
            else {
                std::cout << "Удаленное значение: " << myStack.pop() << std::endl;
            }
            break;
        }
        case '3':
            ++myStack;
            std::cout << "Префиксный ++ применен." << std::endl;
            break;
        case '4':
            myStack++;
            std::cout << "Постфиксный ++ применен." << std::endl;
            break;
        case '5':
            --myStack;
            std::cout << "Префиксный -- применен." << std::endl;
            break;
        case '6':
            myStack--;
            std::cout << "Постфиксный -- применен." << std::endl;
            break;
        case '7':
            if (!myStack) {
                std::cout << "Стек пуст." << std::endl;
            }
            else {
                std::cout << "Стек не пустой." << std::endl;
            }
            break;
        case '8':
            std::cout << "Стек: ";
            myStack.display();
            break;
        case '9': {
            double val1, val2;
            std::cout << "Введите два числа разделенных пробелом: ";
            std::cin >> val1 >> val2;

            RealNumber num1(val1);
            RealNumber num2(val2);

            std::cout << "Операции с числами:\n"
                << "1. Сложение\n"
                << "2. Вычитание\n"
                << "3. Сравнения (>, <, ==, !=)\n"
                << "Выбор: ";

            char realChoice;
            std::cin >> realChoice;

            switch (realChoice) {
            case '1':
                std::cout << "Результат сложения: ";
                (num1 + num2).display();
                std::cout << std::endl;
                break;
            case '2':
                std::cout << "Результат вычетания: ";
                (num1 - num2).display();
                std::cout << std::endl;
                break;
            case '3':
                std::cout << "Результаты сравнений:\n"
                    << "num1 > num2: " << (num1 > num2) << std::endl
                    << "num1 < num2: " << (num1 < num2) << std::endl
                    << "num1 == num2: " << (num1 == num2) << std::endl
                    << "num1 != num2: " << (num1 != num2) << std::endl;
                break;
            default:
                std::cout << "Неправильный выбор." << std::endl;
                break;
            }
            break;
        }

        case '0':
            exit = true;
            std::cout << "Выход из программы..." << std::endl;
            break;
        case 'q': {
            int value;
            std::cout << "Введите значение: ";
            std::cin >> value;
            Stack stack2(value);
            myStack = stack2;
            break; }
        default:
            std::cout << "Неправильный выбор." << std::endl;
            break;
        }

        std::cout << "\nНажмите enter для продолжения...";
        getchar();
        while (getchar() != '\n') {}
    }

    return 0;
}
