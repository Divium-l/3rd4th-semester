package me.divium;

public class Main {

    public static void main(String[] args) {
        //==================================
        Payment pay = new Payment();
        pay.setWorkedDays(100);
        pay.setDailySalary(1);
        pay.setPremiumPercent(0);
        pay.setIncomeTax(0);
        System.out.println(pay.getPayroll()); //99

        //==================================
        Payment pay2 = new Payment(pay);
        System.out.println(pay2.getPayroll()); //99

        //==================================
        Payment pay3 = new Payment("Имя", "Фамилия", "Отчество", 1994, 30, 100, 2, 0, 0);
        System.out.println(pay3.getPayroll()); //198
    }
}
