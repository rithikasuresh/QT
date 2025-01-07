#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int num1, num2, result;

void MainWindow::on_add_clicked()
{
    num1 = ui->text_num1->text().toInt();
    num2 = ui->text_num2->text().toInt();

    result = num1 + num2;
    ui->text_result->setText(QString::number(result));
}


void MainWindow::on_subtract_clicked()
{
    num1 = ui->text_num1->text().toInt();
    num2 = ui->text_num2->text().toInt();

    result = num1 - num2;
    ui->text_result->setText(QString::number(result));
}


void MainWindow::on_divide_clicked()
{
    num1 = ui->text_num1->text().toInt();
    num2 = ui->text_num2->text().toInt();

    if (num2 == 0) {
        QMessageBox::warning(this, "Error", "Division by zero.");
        return;
    }

    result = num1 / num2;
    ui->text_result->setText(QString::number(result));
}


void MainWindow::on_multiply_clicked()
{
    num1 = ui->text_num1->text().toInt();
    num2 = ui->text_num2->text().toInt();

    result = num1 * num2;
    ui->text_result->setText(QString::number(result));
}


