#include <iostream>
#include "stack.h"
#include "float.h"

void printMenu() {
    std::cout << "����:\n"
        << "1. �������� �������\n"
        << "2. ������� �������\n"
        << "3. ���������� ++ ��������\n"
        << "4. ����������� ++ ��������\n"
        << "5. ���������� -- ��������\n"
        << "6. ����������� -- ��������\n"
        << "7. ��������� ���� �� ������� ���������\n"
        << "8. ������� ����\n"
        << "9. ������������ �����\n"
        << "0. �����\n"
        << "q. ������������ ������ �����������\n"
        << "�����: ";
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
            std::cout << "������� ��������:";
            std::cin >> value;
            if (value == 0)
                myStack.push();
            else
                myStack.push(value);
            break;
        }
        case '2': {
            if (!myStack) {
                std::cout << "���� ����." << std::endl;
            }
            else {
                std::cout << "��������� ��������: " << myStack.pop() << std::endl;
            }
            break;
        }
        case '3':
            ++myStack;
            std::cout << "���������� ++ ��������." << std::endl;
            break;
        case '4':
            myStack++;
            std::cout << "����������� ++ ��������." << std::endl;
            break;
        case '5':
            --myStack;
            std::cout << "���������� -- ��������." << std::endl;
            break;
        case '6':
            myStack--;
            std::cout << "����������� -- ��������." << std::endl;
            break;
        case '7':
            if (!myStack) {
                std::cout << "���� ����." << std::endl;
            }
            else {
                std::cout << "���� �� ������." << std::endl;
            }
            break;
        case '8':
            std::cout << "����: ";
            myStack.display();
            break;
        case '9': {
            double val1, val2;
            std::cout << "������� ��� ����� ����������� ��������: ";
            std::cin >> val1 >> val2;

            RealNumber num1(val1);
            RealNumber num2(val2);

            std::cout << "�������� � �������:\n"
                << "1. ��������\n"
                << "2. ���������\n"
                << "3. ��������� (>, <, ==, !=)\n"
                << "�����: ";

            char realChoice;
            std::cin >> realChoice;

            switch (realChoice) {
            case '1':
                std::cout << "��������� ��������: ";
                (num1 + num2).display();
                std::cout << std::endl;
                break;
            case '2':
                std::cout << "��������� ���������: ";
                (num1 - num2).display();
                std::cout << std::endl;
                break;
            case '3':
                std::cout << "���������� ���������:\n"
                    << "num1 > num2: " << (num1 > num2) << std::endl
                    << "num1 < num2: " << (num1 < num2) << std::endl
                    << "num1 == num2: " << (num1 == num2) << std::endl
                    << "num1 != num2: " << (num1 != num2) << std::endl;
                break;
            default:
                std::cout << "������������ �����." << std::endl;
                break;
            }
            break;
        }

        case '0':
            exit = true;
            std::cout << "����� �� ���������..." << std::endl;
            break;
        case 'q': {
            int value;
            std::cout << "������� ��������: ";
            std::cin >> value;
            Stack stack2(value);
            myStack = stack2;
            break; }
        default:
            std::cout << "������������ �����." << std::endl;
            break;
        }

        std::cout << "\n������� enter ��� �����������...";
        getchar();
        while (getchar() != '\n') {}
    }

    return 0;
}
