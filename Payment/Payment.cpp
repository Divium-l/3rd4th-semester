#pragma execution_character_set( "utf-8" )

#include "Payment.hpp"
#include <iostream>

using namespace std;



//Constructors
Payment::Payment()
{
	name = "";
	surname = "";
	patronymic = "";

	startYear = 0;
	workingDays = 0;
	workedDays = 0;
	dailySalary = 0.0;
	premiumPercent = 0.0;
	incomeTax = 0.13;

	salary = -1;
	withhold = -1;
	payroll = -1;
}

Payment::Payment(string name, string surname, string patronymic, int startYear, int workingDays, 
				 int workedDays, double dailySalary, double premiumPercent, double incomeTax)
{
	this->name = name;
	this->surname = surname;
	this->patronymic = patronymic;
	this->startYear = startYear;
	this->workingDays = workingDays;
	this->workedDays = workedDays;	
	this->dailySalary = dailySalary;
	this->premiumPercent = premiumPercent;
	this->incomeTax = incomeTax;
	
	reCalc();
}

Payment::Payment(Payment& p)
{
	name = p.name;
	surname = p.surname;
	patronymic = p.patronymic;

	dailySalary = p.dailySalary;
	startYear = p.startYear;
	premiumPercent = p.premiumPercent;
	incomeTax = p.incomeTax;
	workedDays = p.workedDays;
	workingDays = p.workingDays;

	salary = p.salary;
	withhold = p.withhold;
	payroll = p.payroll;
}

//Private methods
void Payment::calcSalary()
{
	salary = (workedDays * dailySalary) * (1 + premiumPercent);
}

void Payment::calcWithhold()
{
	if (salary == -1)
		calcSalary();

	withhold = salary * (incomeTax + 0.01);
}

void Payment::calcPayroll()
{
	if (withhold == -1)
		calcWithhold();

	payroll = salary - withhold;
}

//Getters
int Payment::getExperience(int currentYear)
{
	if (currentYear < startYear)
		return -1;

	return currentYear - startYear;
}

double Payment::getSalary()
{
	if (salary == -1)
		calcSalary();

	return salary;
}

double Payment::getWithhold()
{
	if (withhold == -1)
		calcWithhold();

	return withhold;
}

double Payment::getPayroll()
{
	if (payroll == -1)
		calcPayroll();

	return payroll;
}

string Payment::getName()			{ return name; }
string Payment::getSurname()		{ return surname; }
string Payment::getPatronymic()		{ return patronymic; }

int Payment::getStartYear()			{ return startYear; }
int Payment::getWorkingDays()		{ return workingDays; }
int Payment::getWorkedDays()		{ return workedDays; }
double Payment::getDailySalary()	{ return dailySalary; }
double Payment::getPremiumPercent() { return premiumPercent; }
double Payment::getIncomeTax()		{ return incomeTax; }

//Setters
void Payment::setName(const string name)						{ this->name = name; }
void Payment::setSurname(const string surname)					{ this->surname = surname; }
void Payment::setPatronymic(const string patronymic)			{ this->patronymic = patronymic; }

void Payment::setStartYear(const int startYear)					{ this->startYear = startYear; }
void Payment::setWorkingDays(const int workingDays)				{ this->workingDays = workingDays; }
void Payment::setWorkedDays(const int workedDays)				{ this->workedDays = workedDays; }
void Payment::setDailySalary(const double dailySalary)			{ this->dailySalary = dailySalary; }
void Payment::setPremiumPercent(const double premiumPercent)	{ this->premiumPercent = premiumPercent; }
void Payment::setIncomeTax(const double incomeTax)				{ this->incomeTax = incomeTax; }

//Quality of life function(s)
void Payment::incWorkingDays()
{
	workingDays++;
}

string Payment::getFullName()
{
	return name + " " + surname + " " + patronymic;
}

void Payment::reCalc()
{
	Payment::calcSalary();
	Payment::calcWithhold();
	Payment::calcPayroll();
}

//Operator overloading
ostream &operator<< (ostream &out, const Payment &p) 
{
	out << "Имя: " << p.name << endl;
	out << "Фамилия: " << p.surname << endl;
	out << "Отчество: " << p.patronymic << endl;

	out << "Год начала работы: " << p.startYear << "г." << endl;
	out << "Число рабочих дней: " << p.workingDays << endl;
	out << "Отрабодано дней: " << p.workedDays << endl;
	out << "Оклад: " << p.dailySalary << "₽" << endl;
	out << "Премия: " << p.premiumPercent << "%" << endl;
	out << "Налог: " << p.incomeTax << "%" << endl;

	out << "Зарплата: " << p.salary << "₽" << endl;
	out << "Удержание: " << p.withhold << "₽" << endl;
	out << "Выплата: " << p.payroll << "₽" << endl;

	return out;
}

istream &operator>> (istream &in, Payment &p)
{
	cout << "Имя: ";  in >> p.name;
	cout << "Фамилия: ";  in >> p.surname;
	cout << "Отчество: ";  in >> p.patronymic;

	cout << "Год начала работы: ";  in >> p.startYear;
	cout << "Число рабочих дней: ";  in >> p.workingDays;
	cout << "Отрабодано дней: ";  in >> p.workedDays;
	cout << "Оклад: ";  in >> p.dailySalary;
	cout << "Премия: ";  in >> p.premiumPercent;
	cout << "Налог: "; in >> p.incomeTax;

	p.reCalc();
	return in;
}

bool operator== (const Payment& p1, const Payment& p2)
{
	return
		(
			p1.name._Equal(p2.name)
			&& p1.surname._Equal(p2.surname)
			&& p1.patronymic._Equal(p2.patronymic)
			&& p1.startYear == p2.startYear
			&& p1.workingDays == p2.workingDays
			&& p1.workedDays == p2.workedDays
			&& p1.dailySalary == p2.dailySalary
			&& p1.premiumPercent == p2.premiumPercent
			&& p1.incomeTax == p2.incomeTax
		);
}

bool operator!= (const Payment& p1, const Payment& p2)
{
	return !(p1 == p2);
}