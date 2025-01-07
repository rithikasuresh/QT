#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr); // Explicit constructor
    ~MainWindow();

private slots:
    void calculateTax(); // Slot for handling tax calculation logic

private:
    Ui::MainWindow *ui;

    // Helper methods for tax calculation
    int incomeTaxSlab(int taxableIncome);
    int taxCalculator(int taxableIncome, int taxSlab);
};

#endif // MAINWINDOW_H
