#include "Payment.hpp"

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
	
	salary = -1;
	withhold = -1;
	payroll = -1;
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

//Operator overloading