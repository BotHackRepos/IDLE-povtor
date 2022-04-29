// python_compieler.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <Python.h>



const char* ConvertStringToCharacter(std::string _str) {//это функция будет конвертировать из строки в строку  другово типа
    int size = _str.length() + 1;
    char* arr = new char[size];
    for (int i = 0; i < _str.length(); ++i) {
       arr[i] = (char)_str[i];
    }
    arr[size - 1] = '\0';
    return (const char*)arr;
}


int main()
{
    Py_Initialize();//инициализируется python
    std::string cmd;//переменная в которую будем вводить строку
    char* pointer;//указатель на строку - тип который мы можем передать как команду python а том числ
    std::cout << "Python compieler created by Nethunter( url https://t.me/NethunterHacker) Inc. Compieler not supported symbols " << std::endl;//вывод сообщения
    while (cmd != "exit") {//пока мы не ввели exit
        std::cout << "> ";//выводим >
        getline(std::cin, cmd);//ввод строки
        if (cmd == "exit" || cmd == "exit\n") {//еще одна проверка
            break;
        }
        pointer = (char*)ConvertStringToCharacter(cmd);//конвертирование строки в строку
        PyRun_SimpleString((const char*)pointer);//запуск  строки
        delete[] pointer;//чистим память указателя
    }
    Py_Finalize();//закрываем компилятор
}