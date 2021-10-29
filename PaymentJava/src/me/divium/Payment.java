package me.divium;

public class Payment
{
    private double salary;			//зарплата
    private double withhold;		//удержание
    private double payroll;			//зарплата - удержание

    private String name;			//имя
    private String surname;			//фамилия
    private String patronymic;		//отчество

    private int startYear;			//года начала работы
    private int workingDays;		//число рабочих дней
    private int workedDays;			//кол-во дней, когда чел работал
    private double dailySalary;		//оклад за день
    private double premiumPercent;	//процент премии
    private double incomeTax;		//налог

    //Private funcs
    private void calcSalary() {
        salary = (workedDays * dailySalary) * (1 + premiumPercent);
    }
    private void calcWithhold() {
        if (salary == -1)
            calcSalary();

        withhold = salary * (incomeTax + 0.01);
    }
    private void calcPayroll() {
        if (withhold == -1)
            calcWithhold();

        payroll = salary - withhold;
    }
    private void initializeSalary() {
        salary = -1;
        withhold = -1;
        payroll = -1;
    }

    //Constructors
    public Payment() {
        name = "";
        surname = "";
        patronymic = "";
        startYear = 0;
        workingDays = 0;
        workedDays = 0;
        dailySalary = 0.0;
        premiumPercent = 0.0;
        incomeTax = 0.13;

        initializeSalary();
    }
    public Payment(String name, String surname, String patronymic, int startYear, int workingDays,
                   int workedDays, double dailySalary, double premiumPercent, double incomeTax) {
        this.name = name;
        this.surname = surname;
        this.patronymic = patronymic;
        this.startYear = startYear;
        this.workingDays = workingDays;
        this.workedDays = workedDays;
        this.dailySalary = dailySalary;
        this.premiumPercent = premiumPercent;
        this.incomeTax = incomeTax;

        initializeSalary();
    }
    public Payment(Payment p) {
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

    //Getters
    public int getExperience(int currentYear) {
        if (currentYear < startYear)
            return -1;

        return currentYear - startYear;
    }
    public double getSalary() {
        if (salary == -1)
            calcSalary();

        return salary;
    }
    public double getWithhold() {
        if (withhold == -1)
            calcWithhold();

        return withhold;
    }
    public double getPayroll() {
        if (payroll == -1)
            calcPayroll();

        return payroll;
    }

    public String getName()         {   return name;}
    public String getSurname()          { return surname; }
    public String getPatronymic()       { return patronymic; }
    public int getStartYear()           { return startYear; }
    public int getWorkingDays()         { return workingDays; }
    public int getWorkedDays()          { return workedDays; }
    public double getDailySalary()      { return dailySalary; }
    public double getPremiumPercent()   { return premiumPercent; }
    public double getIncomeTax()        { return incomeTax; }

    //Setters
    public void setName(String name)                    {this.name = name;}
    public void setSurname(String surname)              {this.surname = surname;}
    public void setPatronymic(String patronymic)        {this.patronymic = patronymic;}
    public void setStartYear(int startYear)             {this.startYear = startYear;}
    public void setWorkingDays(int workingDays)         {this.workedDays = workingDays;}
    public void setWorkedDays(int workedDays)           {this.workedDays = workedDays;}
    public void setDailySalary(double dailySalary)      {this.dailySalary = dailySalary;}
    public void setPremiumPercent(double premiumPercent){this.premiumPercent = premiumPercent;}
    public void setIncomeTax(double incomeTax)          {this.incomeTax = incomeTax;}

    //Quality of life functions
    public void incWorkingDays() {
        workedDays++;
    }
    String getFullName() {
        return name + " " + surname + " " + patronymic;
    }
}
