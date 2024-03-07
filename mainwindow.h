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

private:
    enum CalcOperator{
       Op_add,
       Op_sub,
       Op_mul,
       Op_div,
    };

    struct CalcInfo {
        CalcOperator op_type;
        int op_one;
        int op_two;
    };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_zero_clicked();

    void on_btn_one_clicked();

    void on_btn_two_clicked();

    void on_btn_three_clicked();

    void on_btn_four_clicked();

    void on_btn_five_clicked();

    void on_btn_six_clicked();

    void on_btn_seven_clicked();

    void on_btn_eight_clicked();

    void on_btn_nine_clicked();

    void on_btn_clear_clicked();

    void on_btn_div_clicked();

    void on_btn_add_clicked();

    void on_btn_sub_clicked();

    void on_btn_mul_clicked();

    void on_btn_equal_clicked();

private:
    Ui::MainWindow *ui;

private:
    QString buffer;
    QString out_text;
    struct CalcInfo operation;

    int get_result();
    void reset_buffs();
};
#endif // MAINWINDOW_H
