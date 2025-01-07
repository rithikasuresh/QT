#include <iostream>

int incomeTaxSlab(int taxableIncome) {
    int taxSlab;
    if (taxableIncome <= 300000) {
        taxSlab = 0;
    }
    else if (taxableIncome > 300000 && taxableIncome <= 700000) {
        taxSlab = 5;
    }
    else if (taxableIncome > 700000 && taxableIncome <= 1000000) {
        taxSlab = 10;
    }
    else if (taxableIncome > 1000000 && taxableIncome <= 1200000) {
        taxSlab = 15;
    }
    else if (taxableIncome > 1200000 && taxableIncome <= 1500000) {
        taxSlab = 20;
    }
    else if (taxableIncome > 1500000) {
        taxSlab = 30;
    }
    std::cout << "Your tax slab is " << taxSlab << "%" << std::endl;
    return taxSlab;
}

int taxCalculator(int taxableIncome, int taxSlab) {
    int totalTax = 0;
    if (taxSlab == 10) {
        totalTax = totalTax + (700000 - 300000) * 0.05;
        totalTax = totalTax + (taxableIncome - 700000) * 0.10;
    }
    else if (taxSlab == 15) {
        totalTax = totalTax + (700000 - 300000) * 0.05;
        totalTax = totalTax + (1000000 - 700000) * 0.10;
        totalTax = totalTax + (taxableIncome - 1000000) * 0.15;
    }
    else if (taxSlab == 20) {
        totalTax = totalTax + (700000 - 300000) * 0.05;
        totalTax = totalTax + (1000000 - 700000) * 0.10;
        totalTax = totalTax + (1200000 - 1000000) * 0.15;
        totalTax = totalTax + (taxableIncome - 1200000) * 0.20;
    }
    else if (taxSlab == 30) {
        totalTax = totalTax + (700000 - 300000) * 0.05;
        totalTax = totalTax + (1000000 - 700000) * 0.10;
        totalTax = totalTax + (1200000 - 1000000) * 0.15;
        totalTax = totalTax + (1500000 - 1200000) * 0.20;
        totalTax = totalTax + (taxableIncome - 1500000) * 0.30;
    }
    return totalTax;
}

int main() {
    std::cout << "Gross income = Rs " ;
    int grossIncome;
    std::cin >> grossIncome;

    int stdDeduction = 75000;
    int taxableIncome = grossIncome - stdDeduction;
    std::cout << "Your taxable income = Rs " << taxableIncome << std::endl;

    int taxSlab = incomeTaxSlab(taxableIncome);

    int totalTax;
    if(taxableIncome <= 300000) {
        totalTax = 0;
        std::cout << "Tax liability = Rs " << totalTax << std::endl;
    }
    else if(taxableIncome <= 700000) {
        std::cout << "The New Tax Regime provides a rebate under section 87A for individuals with taxable income up to Rs 7 lakh, effectively making their tax liability zero" << std::endl;
        totalTax = 0;
        std::cout << "Tax liability = Rs " << totalTax << std::endl;
    }
    else {
        totalTax = taxCalculator(taxableIncome, taxSlab);
        int cess = totalTax * 0.04;
        std::cout << "Total Tax = Rs " << totalTax << std::endl;
        std::cout << "Health and education cess = Rs " << cess << std::endl;
        std::cout << "Tax liability = Rs " << totalTax + cess << std::endl;
    }
}