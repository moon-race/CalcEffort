#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QLineEdit>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void set_values();
    void reset_count();

private:
    void init_ui();
    std::vector<int> get_pair(int, int);
    std::map<std::string, std::vector<int>> get_pairs(int, int, int, int, int, int);

    QLabel *lbl_h;
    QLabel *lbl_a;
    QLabel *lbl_b;
    QLabel *lbl_c;
    QLabel *lbl_d;
    QLabel *lbl_s;
    QLabel *lbl_r;

    QLabel *lbl_effort;
    QSpinBox *spn_effort_h;
    QSpinBox *spn_effort_a;
    QSpinBox *spn_effort_b;
    QSpinBox *spn_effort_c;
    QSpinBox *spn_effort_d;
    QSpinBox *spn_effort_s;
    QLabel *lbl_effort_r;

    QLabel *lbl_haspower;
    QLabel *lbl_haspower_h;
    QLabel *lbl_haspower_a;
    QLabel *lbl_haspower_b;
    QLabel *lbl_haspower_c;
    QLabel *lbl_haspower_d;
    QLabel *lbl_haspower_s;
    QLabel *lbl_haspower_r;

    QLabel *lbl_nopower;
    QLabel *lbl_nopower_h;
    QLabel *lbl_nopower_a;
    QLabel *lbl_nopower_b;
    QLabel *lbl_nopower_c;
    QLabel *lbl_nopower_d;
    QLabel *lbl_nopower_s;
    QLabel *lbl_nopower_r;

    QLabel *lbl_berry;
    QLabel *lbl_berry_h;
    QLabel *lbl_berry_a;
    QLabel *lbl_berry_b;
    QLabel *lbl_berry_c;
    QLabel *lbl_berry_d;
    QLabel *lbl_berry_s;
    QLabel *lbl_berry_r;

    QPushButton *btn_reset;

};

#endif // WIDGET_HPP
