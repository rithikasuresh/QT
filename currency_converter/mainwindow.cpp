#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Dollar");
    ui->comboBox->addItem("Euro");
    ui->comboBox->addItem("Pound");

    // connect(ui->pushButton, SIGNAL(clicked()),
    //         this, SLOT(on_pushButton_clicked()));

    connect(ui->pushButton_2, SIGNAL(clicked()),
            this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    enum Currency {Dollar, Euro, Pound, Invalid};
    float rates[] = {0.012, 0.011, 0.0094};

    QString localCurrency = ui->lineEdit->text();
    float localCurrency_int = localCurrency.toInt();
    QString selectedCurrency = ui->comboBox->currentText();

    Currency currencyType = Invalid;

    if (selectedCurrency == "Dollar")
        currencyType = Dollar;
    else if (selectedCurrency == "Euro")
        currencyType = Euro;
    else if (selectedCurrency == "Pound")
        currencyType = Pound;

    float result = 0;
    QString result_string;

    switch (currencyType) {
    case Dollar:
        result = localCurrency_int * rates[Dollar];
        result_string = QString::number(result);
        QMessageBox::information(this, "Currency convertor", "Your currency is equal to: $"+result_string);
        break;
    case Euro:
        result = localCurrency_int * rates[Euro];
        result_string = QString::number(result);
        QMessageBox::information(this, "Currency convertor", "Your currency is equal to: "+result_string+ " Euros");
        break;
    case Pound:
        result = localCurrency_int * rates[Pound];
        result_string = QString::number(result);
        QMessageBox::information(this, "Currency convertor", "Your currency is equal to: "+result_string+" Pounds");
        break;
    default:
        QMessageBox::information(this, "Currency convertor", "Invalid choice");
        break;
    }
}

