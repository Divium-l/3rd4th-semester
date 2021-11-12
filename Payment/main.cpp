#pragma execution_character_set( "utf-8" )

#include <iostream>
#include "Payment.hpp"
#include <Windows.h>

using namespace std;

//+ перегрузить оператор ввода, вывода и ещё(+-= на выбор)
//+ сделать поля приватными

void testPayment_1()
{
    //==================================
    Payment pay;
    pay.setWorkedDays(100);
    pay.setDailySalary(1);
    pay.setPremiumPercent(0);
    pay.setIncomeTax(0);

    cout << pay.getPayroll() << endl; //99

    //==================================
    Payment pay2 = pay;

    cout << pay2.getPayroll() << endl; //99

    //==================================      
    Payment pay3("Имя", "Фамилия", "Отчество", 1994, 30, 100, 2, 0, 0);

    cout << pay3.getPayroll() << endl; //198
}

int main()
{
    SetConsoleOutputCP(65001);

    //testPayment_1();
    
    Payment pay1("Иван", "Иванов", "Иванович", 2014, 22, 18, 1000.0, 0.0, 0.0);
    cout << pay1 << "\n";

    Payment pay2;
    cin >> pay2;
    cout << "\n\n";
    cout << pay2 << "\n";

    Payment pay3("Иван", "Иванов", "Иванович", 2014, 22, 18, 1000.0, 0.0, 0.0);
    Payment pay4("Иван", "Иванов", "Иванович", 2014, 22, 18, 999.9, 0.0, 0.0);

    if (pay1 == pay3)
        cout << "\npay1 == pay3\n";
    else
        cout << "\npay1 != pay3\n";

    if (pay4 == pay3)
        cout << "\npay4 == pay3\n";
    else
        cout << "\npay4 != pay3\n";
}