#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

void MainWindow::on_btn_zero_clicked()
{
    this->buffer.append("0");
    this->out_text.append("0");
    ui->text_output->setText(out_text);
}


void MainWindow::on_btn_one_clicked()
{
    this->buffer.append("1");
    this->out_text.append("1");
    ui->text_output->setText(out_text);
}


void MainWindow::on_btn_two_clicked()
{
    this->buffer.append("2");
    this->out_text.append("2");
    ui->text_output->setText(out_text);
}


void MainWindow::on_btn_three_clicked()
{
    this->buffer.append("3");
    this->out_text.append("3");
    ui->text_output->setText(out_text);
}


void MainWindow::on_btn_four_clicked()
{
    this->buffer.append("4");
    this->out_text.append("4");
    ui->text_output->setText(out_text);
}


void MainWindow::on_btn_five_clicked()
{
    this->buffer.append("5");
    this->out_text.append("5");
    ui->text_output->setText(out_text);
}


void MainWindow::on_btn_six_clicked()
{
    this->buffer.append("6");
    this->out_text.append("6");
    ui->text_output->setText(out_text);
}


void MainWindow::on_btn_seven_clicked()
{
    this->buffer.append("7");
    this->out_text.append("7");
    ui->text_output->setText(out_text);
}


void MainWindow::on_btn_eight_clicked()
{
    this->buffer.append("8");
    this->out_text.append("8");
    ui->text_output->setText(out_text);
}


void MainWindow::on_btn_nine_clicked()
{
    this->buffer.append("9");
    this->out_text.append("9");
    ui->text_output->setText(out_text);
}


void MainWindow::on_btn_clear_clicked()
{
    ui->text_output->clear();
    reset_buffs();
}


void MainWindow::on_btn_div_clicked()
{
    if (buffer.isEmpty()) {
        this->operation.op_one = 0;
    } else {
        this->operation.op_one = buffer.toInt();
    }

    this->operation.op_type = Op_div;

    this->out_text.append(" / ");
    ui->text_output->setText(out_text);
    this->buffer.clear();
}


void MainWindow::on_btn_add_clicked()
{
    if (buffer.isEmpty()) {
        this->operation.op_one = 0;
    } else {
        this->operation.op_one = buffer.toInt();
    }

    this->operation.op_type = Op_add;

    this->out_text.append(" + ");
    ui->text_output->setText(out_text);
    this->buffer.clear();
}


void MainWindow::on_btn_sub_clicked()
{
    if (buffer.isEmpty()) {
        this->operation.op_one = 0;
    } else {
        this->operation.op_one = buffer.toInt();
    }

    this->operation.op_type = Op_sub;

    this->out_text.append(" - ");
    ui->text_output->setText(out_text);
    this->buffer.clear();
}


void MainWindow::on_btn_mul_clicked()
{
    if (buffer.isEmpty()) {
        this->operation.op_one = 0;
    } else {
        this->operation.op_one = buffer.toInt();
    }

    this->operation.op_type = Op_mul;
    this->buffer.clear();

    this->out_text.append(" X ");
    ui->text_output->setText(out_text);
    this->buffer.clear();
}


void MainWindow::on_btn_equal_clicked()
{
    if (buffer.isEmpty()) {
        this->operation.op_two = 0;
    } else {
        this->operation.op_two = buffer.toInt();
    }

    ui->text_output->setText(QString::number(get_result()));
    reset_buffs();
}

int MainWindow::get_result() {
    switch(this->operation.op_type) {
    case Op_add:
        return this->operation.op_one + this->operation.op_two;
    case Op_sub:
        return this->operation.op_one - this->operation.op_two;
    case Op_mul:
        return this->operation.op_one * this->operation.op_two;
    case Op_div:
        return (operation.op_one == 0 || operation.op_two == 0) ?
                   0 : (this->operation.op_one / this->operation.op_two);
    }

    return 0;
}

void MainWindow::reset_buffs()
{
    this->out_text.clear();
    this->buffer.clear();
}
