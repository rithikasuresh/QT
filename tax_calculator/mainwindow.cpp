#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the calculate button to the calculateTax slot
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::calculateTax);
    connect(ui->exit, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::incomeTaxSlab(int taxableIncome)
{
    if (taxableIncome <= 300000) {
        return 0;
    } else if (taxableIncome <= 700000) {
        return 5;
    } else if (taxableIncome <= 1000000) {
        return 10;
    } else if (taxableIncome <= 1200000) {
        return 15;
    } else if (taxableIncome <= 1500000) {
        return 20;
    } else {
        return 30;
    }
}

int MainWindow::taxCalculator(int taxableIncome, int taxSlab)
{
    int totalTax = 0;

    if (taxSlab == 10) {
        totalTax += (700000 - 300000) * 0.05;
        totalTax += (taxableIncome - 700000) * 0.10;
    } else if (taxSlab == 15) {
        totalTax += (700000 - 300000) * 0.05;
        totalTax += (1000000 - 700000) * 0.10;
        totalTax += (taxableIncome - 1000000) * 0.15;
    } else if (taxSlab == 20) {
        totalTax += (700000 - 300000) * 0.05;
        totalTax += (1000000 - 700000) * 0.10;
        totalTax += (1200000 - 1000000) * 0.15;
        totalTax += (taxableIncome - 1200000) * 0.20;
    } else if (taxSlab == 30) {
        totalTax += (700000 - 300000) * 0.05;
        totalTax += (1000000 - 700000) * 0.10;
        totalTax += (1200000 - 1000000) * 0.15;
        totalTax += (1500000 - 1200000) * 0.20;
        totalTax += (taxableIncome - 1500000) * 0.30;
    }

    return totalTax;
}

void MainWindow::calculateTax()
{
    // Get gross income from the input field
    bool ok;
    int grossIncome = ui->incomeInput->text().toInt(&ok);

    if (!ok || grossIncome <= 0) {
        QMessageBox::warning(this, "Error", "Please enter a valid gross income.");
        return;
    }

    // Calculate taxable income
    int stdDeduction = 75000;
    int taxableIncome = grossIncome - stdDeduction;

    // Determine the tax slab
    int taxSlab = incomeTaxSlab(taxableIncome);

    // Calculate total tax
    int totalTax = 0;
    QString result;

    if (taxableIncome <= 300000) {
        result = "Tax liability: Rs 0 (Income is below the tax-free limit)";
    } else if (taxableIncome <= 700000) {
        result = "Tax liability: Rs 0 (Eligible for rebate under Section 87A)";
    } else {
        totalTax = taxCalculator(taxableIncome, taxSlab);
        int cess = totalTax * 0.04;
        int totalLiability = totalTax + cess;

        result = QString("Gross Income: Rs %1\nTax Slab:  %2%\n Taxable Income: Rs %3\nTax: Rs %4\nCess: Rs %5\nTotal Tax Liability: Rs %6")
                     .arg(grossIncome)
                     .arg(taxSlab)
                     .arg(taxableIncome)
                     .arg(totalTax)
                     .arg(cess)
                     .arg(totalLiability);
    }

    // Display the result
    QMessageBox::information(this, "Tax Calculation Result", result);
}
