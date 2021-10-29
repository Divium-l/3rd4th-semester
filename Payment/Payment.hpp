#pragma once
#include <string>

using namespace std;
class Payment
{
private:
	double salary;			//зарплата
	double withhold;		//удержание
	double payroll;			//зарплата - удержание

	string name;			//имя
	string surname;			//фамилия
	string patronymic;		//отчество

	int startYear;			//года начала работы
	int workingDays;		//число рабочих дней
	int workedDays;			//кол-во дней, когда чел работал
	double dailySalary;		//оклад за день
	double premiumPercent;	//процент премии
	double incomeTax;		//налог

	void calcSalary();
	void calcWithhold();
	void calcPayroll();

public:
	//Constructors
	Payment();
	Payment(string name, string surname, string patronymic, int startYear, int workingDays, int workedDays, double dailySalary, double premiumPercent, double incomeTax);
	Payment(Payment& p);

	//Getters
	int getExperience(int currentYear);
	double getSalary();
	double getWithhold();
	double getPayroll();

	string getName();
	string getSurname();
	string getPatronymic();

	int getStartYear();
	int getWorkingDays();
	int getWorkedDays();
	double getDailySalary();
	double getPremiumPercent();
	double getIncomeTax();

	//Setters
	void setName(const string name);
	void setSurname(const string surname);
	void setPatronymic(const string patronymic);

	void setStartYear(const int startYear);
	void setWorkingDays(const int workingDays);
	void setWorkedDays(const int workedDays);
	void setDailySalary(const double dailySalary);
	void setPremiumPercent(const double premiumPercent);
	void setIncomeTax(const double incomeTax);

	//Quality of life functions
	void incWorkingDays();
	string getFullName();
};

