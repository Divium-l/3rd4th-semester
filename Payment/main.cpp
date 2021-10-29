#include <iostream>
#include "Payment.hpp"

using namespace std;

//- перегрузить оператор ввода, вывода и ещё(+-= на выбор)
//+ сделать поля приватными

int main()
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