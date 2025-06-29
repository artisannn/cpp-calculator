#pragma once

#include "calculator.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

QString inline RemoveTrailingZeroes(const QString &text) {
    for (qsizetype i = 0; i < text.size(); ++i) {
        if (text[i] != '0') {
            return text.mid(i);
        }
    }
    return "";
}

QString inline NormalizeNumber(const QString &text) {
    if (text.isEmpty()) {
        return "0";
    }
    if (text.startsWith('.')) {
        // Рекурсивный вызов.
        return NormalizeNumber("0" + text);
    }
    if (text.startsWith('-')) {
        // Рекурсивный вызов.
        return "-" + NormalizeNumber(text.mid(1));
    }
    if (text.startsWith('0') && !text.startsWith("0.")) {
        return NormalizeNumber(RemoveTrailingZeroes(text));
    }
    return text;
}

enum class Operation{
    NO_OPERATION,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    POWER
};

QString inline OpToString(Operation op) {
    switch(op) {
    case Operation::NO_OPERATION: return "";
    case Operation::ADDITION: return "+";
    case Operation::DIVISION: return "÷";
    case Operation::MULTIPLICATION: return "×";
    case Operation::SUBTRACTION: return "−";
    case Operation::POWER: return "^";
    }
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:

    void on_tb_seven_clicked();

    void on_tb_one_clicked();

    void on_tb_two_clicked();

    void on_tb_three_clicked();

    void on_tb_four_clicked();

    void on_tb_five_clicked();

    void on_tb_six_clicked();

    void on_tb_eight_clicked();

    void on_tb_nine_clicked();

    void on_tb_comma_clicked();

    void on_tb_negate_clicked();

    void on_tb_backspace_clicked();

    void on_tb_zero_clicked();

    void on_tb_divide_clicked();

    void on_tb_multiplicate_clicked();

    void on_tb_substract_clicked();

    void on_tb_add_clicked();

    void on_tb_power_clicked();

    void on_tb_equal_clicked();

    void on_tb_reset_clicked();

    void on_tb_mc_clicked();

    void on_tb_ms_clicked();

    void on_tn_mr_clicked();

private:
    void SetText(const QString& text);
    void AddText(const QString& suffix);
    void SetOperation(Operation op);

private:
    Ui::MainWindow* ui;
    Calculator calculator_;
    QString input_number_{"0"};
    Number active_number_{0};
    Operation current_operation_{Operation::NO_OPERATION};
    Number saved_number_{0};
    bool is_saved_{true};
};
