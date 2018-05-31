#include <numeric>
#include <algorithm>

#include <QMessageBox>
#include <QGridLayout>
#include <QIcon>

#include "widget.hpp"


#define TO_QSTRING QString::fromLocal8Bit


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    init_ui();
}

Widget::~Widget()
{

}

void Widget::set_values()
{
    int h = spn_effort_h->value();
    int a = spn_effort_a->value();
    int b = spn_effort_b->value();
    int c = spn_effort_c->value();
    int d = spn_effort_d->value();
    int s = spn_effort_s->value();

    if ((h % 2 == 0) && (a % 2 == 0) && (b % 2 == 0) && (c % 2 == 0) && (d % 2 == 0) && (s % 2 == 0))
    {
        std::map<std::string, std::vector<int>> values;
        values = get_pairs(h, a, b, c, d, s);

        int haspower_h = values["h"][0];
        int haspower_a = values["a"][0];
        int haspower_b = values["b"][0];
        int haspower_c = values["c"][0];
        int haspower_d = values["d"][0];
        int haspower_s = values["s"][0];

        int nopower_h = values["h"][1];
        int nopower_a = values["a"][1];
        int nopower_b = values["b"][1];
        int nopower_c = values["c"][1];
        int nopower_d = values["d"][1];
        int nopower_s = values["s"][1];

        int berry_h = values["h"][2];
        int berry_a = values["a"][2];
        int berry_b = values["b"][2];
        int berry_c = values["c"][2];
        int berry_d = values["d"][2];
        int berry_s = values["s"][2];

        lbl_haspower_h->setText(TO_QSTRING(std::to_string(haspower_h).data()));
        lbl_haspower_a->setText(TO_QSTRING(std::to_string(haspower_a).data()));
        lbl_haspower_b->setText(TO_QSTRING(std::to_string(haspower_b).data()));
        lbl_haspower_c->setText(TO_QSTRING(std::to_string(haspower_c).data()));
        lbl_haspower_d->setText(TO_QSTRING(std::to_string(haspower_d).data()));
        lbl_haspower_s->setText(TO_QSTRING(std::to_string(haspower_s).data()));

        lbl_nopower_h->setText(TO_QSTRING(std::to_string(nopower_h).data()));
        lbl_nopower_a->setText(TO_QSTRING(std::to_string(nopower_a).data()));
        lbl_nopower_b->setText(TO_QSTRING(std::to_string(nopower_b).data()));
        lbl_nopower_c->setText(TO_QSTRING(std::to_string(nopower_c).data()));
        lbl_nopower_d->setText(TO_QSTRING(std::to_string(nopower_d).data()));
        lbl_nopower_s->setText(TO_QSTRING(std::to_string(nopower_s).data()));

        lbl_berry_h->setText(TO_QSTRING(std::to_string(berry_h).data()));
        lbl_berry_a->setText(TO_QSTRING(std::to_string(berry_a).data()));
        lbl_berry_b->setText(TO_QSTRING(std::to_string(berry_b).data()));
        lbl_berry_c->setText(TO_QSTRING(std::to_string(berry_c).data()));
        lbl_berry_d->setText(TO_QSTRING(std::to_string(berry_d).data()));
        lbl_berry_s->setText(TO_QSTRING(std::to_string(berry_s).data()));

        int remain = 510 - h - a - b - c - d - s;

        lbl_effort_r->setText(TO_QSTRING(std::to_string(remain).data()));
    }
}

void Widget::reset_count()
{
    int reply = QMessageBox::question(this, TO_QSTRING("確認"), TO_QSTRING("本当にリセットしますか？"));
    if (reply == QMessageBox::Yes)
    {
        spn_effort_h->setValue(0);
        spn_effort_a->setValue(0);
        spn_effort_b->setValue(0);
        spn_effort_c->setValue(0);
        spn_effort_d->setValue(0);
        spn_effort_s->setValue(0);

        set_values();
    }
}

void Widget::init_ui()
{
    lbl_h = new QLabel(TO_QSTRING("耐久：　"));
    lbl_a = new QLabel(TO_QSTRING("攻撃：　"));
    lbl_b = new QLabel(TO_QSTRING("防御：　"));
    lbl_c = new QLabel(TO_QSTRING("特攻：　"));
    lbl_d = new QLabel(TO_QSTRING("特防：　"));
    lbl_s = new QLabel(TO_QSTRING("素早：　"));
    lbl_r = new QLabel(TO_QSTRING("残り：　"));

    lbl_effort = new QLabel(TO_QSTRING("  努力値  "));
    spn_effort_h = new QSpinBox();
    spn_effort_a = new QSpinBox();
    spn_effort_b = new QSpinBox();
    spn_effort_c = new QSpinBox();
    spn_effort_d = new QSpinBox();
    spn_effort_s = new QSpinBox();
    lbl_effort_r = new QLabel(TO_QSTRING("510"));

    spn_effort_h->setMaximum(252);
    spn_effort_a->setMaximum(252);
    spn_effort_b->setMaximum(252);
    spn_effort_c->setMaximum(252);
    spn_effort_d->setMaximum(252);
    spn_effort_s->setMaximum(252);

    lbl_haspower = new QLabel(TO_QSTRING(" パワー有 "));
    lbl_haspower_h = new QLabel(TO_QSTRING("0"));
    lbl_haspower_a = new QLabel(TO_QSTRING("0"));
    lbl_haspower_b = new QLabel(TO_QSTRING("0"));
    lbl_haspower_c = new QLabel(TO_QSTRING("0"));
    lbl_haspower_d = new QLabel(TO_QSTRING("0"));
    lbl_haspower_s = new QLabel(TO_QSTRING("0"));

    lbl_haspower_h->setAlignment(Qt::AlignCenter);
    lbl_haspower_a->setAlignment(Qt::AlignCenter);
    lbl_haspower_b->setAlignment(Qt::AlignCenter);
    lbl_haspower_c->setAlignment(Qt::AlignCenter);
    lbl_haspower_d->setAlignment(Qt::AlignCenter);
    lbl_haspower_s->setAlignment(Qt::AlignCenter);

    lbl_nopower = new QLabel(TO_QSTRING(" パワー無 "));
    lbl_nopower_h = new QLabel(TO_QSTRING("0"));
    lbl_nopower_a = new QLabel(TO_QSTRING("0"));
    lbl_nopower_b = new QLabel(TO_QSTRING("0"));
    lbl_nopower_c = new QLabel(TO_QSTRING("0"));
    lbl_nopower_d = new QLabel(TO_QSTRING("0"));
    lbl_nopower_s = new QLabel(TO_QSTRING("0"));

    lbl_nopower_h->setAlignment(Qt::AlignCenter);
    lbl_nopower_a->setAlignment(Qt::AlignCenter);
    lbl_nopower_b->setAlignment(Qt::AlignCenter);
    lbl_nopower_c->setAlignment(Qt::AlignCenter);
    lbl_nopower_d->setAlignment(Qt::AlignCenter);
    lbl_nopower_s->setAlignment(Qt::AlignCenter);

    lbl_berry = new QLabel(TO_QSTRING(" なつき実 "));
    lbl_berry_h = new QLabel(TO_QSTRING("0"));
    lbl_berry_a = new QLabel(TO_QSTRING("0"));
    lbl_berry_b = new QLabel(TO_QSTRING("0"));
    lbl_berry_c = new QLabel(TO_QSTRING("0"));
    lbl_berry_d = new QLabel(TO_QSTRING("0"));
    lbl_berry_s = new QLabel(TO_QSTRING("0"));

    lbl_berry_h->setAlignment(Qt::AlignCenter);
    lbl_berry_a->setAlignment(Qt::AlignCenter);
    lbl_berry_b->setAlignment(Qt::AlignCenter);
    lbl_berry_c->setAlignment(Qt::AlignCenter);
    lbl_berry_d->setAlignment(Qt::AlignCenter);
    lbl_berry_s->setAlignment(Qt::AlignCenter);

    btn_reset = new QPushButton(TO_QSTRING("リセット"));

    QGridLayout *main_layout = new QGridLayout();

    main_layout->addWidget(lbl_h, 1, 0, 1, 1);
    main_layout->addWidget(lbl_a, 2, 0, 1, 1);
    main_layout->addWidget(lbl_b, 3, 0, 1, 1);
    main_layout->addWidget(lbl_c, 4, 0, 1, 1);
    main_layout->addWidget(lbl_d, 5, 0, 1, 1);
    main_layout->addWidget(lbl_s, 6, 0, 1, 1);
    main_layout->addWidget(lbl_r, 7, 0, 1, 1);

    main_layout->addWidget(lbl_effort, 0, 1, 1, 1);
    main_layout->addWidget(spn_effort_h, 1, 1, 1, 1);
    main_layout->addWidget(spn_effort_a, 2, 1, 1, 1);
    main_layout->addWidget(spn_effort_b, 3, 1, 1, 1);
    main_layout->addWidget(spn_effort_c, 4, 1, 1, 1);
    main_layout->addWidget(spn_effort_d, 5, 1, 1, 1);
    main_layout->addWidget(spn_effort_s, 6, 1, 1, 1);
    main_layout->addWidget(lbl_effort_r, 7, 1, 1, 1);

    main_layout->addWidget(lbl_haspower, 0, 2, 1, 1);
    main_layout->addWidget(lbl_haspower_h, 1, 2, 1, 1);
    main_layout->addWidget(lbl_haspower_a, 2, 2, 1, 1);
    main_layout->addWidget(lbl_haspower_b, 3, 2, 1, 1);
    main_layout->addWidget(lbl_haspower_c, 4, 2, 1, 1);
    main_layout->addWidget(lbl_haspower_d, 5, 2, 1, 1);
    main_layout->addWidget(lbl_haspower_s, 6, 2, 1, 1);

    main_layout->addWidget(lbl_nopower, 0, 3, 1, 1);
    main_layout->addWidget(lbl_nopower_h, 1, 3, 1, 1);
    main_layout->addWidget(lbl_nopower_a, 2, 3, 1, 1);
    main_layout->addWidget(lbl_nopower_b, 3, 3, 1, 1);
    main_layout->addWidget(lbl_nopower_c, 4, 3, 1, 1);
    main_layout->addWidget(lbl_nopower_d, 5, 3, 1, 1);
    main_layout->addWidget(lbl_nopower_s, 6, 3, 1, 1);

    main_layout->addWidget(lbl_berry, 0, 4, 1, 1);
    main_layout->addWidget(lbl_berry_h, 1, 4, 1, 1);
    main_layout->addWidget(lbl_berry_a, 2, 4, 1, 1);
    main_layout->addWidget(lbl_berry_b, 3, 4, 1, 1);
    main_layout->addWidget(lbl_berry_c, 4, 4, 1, 1);
    main_layout->addWidget(lbl_berry_d, 5, 4, 1, 1);
    main_layout->addWidget(lbl_berry_s, 6, 4, 1, 1);

    main_layout->addWidget(btn_reset, 7, 3, 1, 2);

    setLayout(main_layout);

    setWindowTitle(TO_QSTRING("努力値計算"));
    setWindowIcon(QIcon(TO_QSTRING("qrc:/CalcEffort.ico")));

    connect(spn_effort_h, SIGNAL(valueChanged(int)), this, SLOT(set_values()));
    connect(spn_effort_a, SIGNAL(valueChanged(int)), this, SLOT(set_values()));
    connect(spn_effort_b, SIGNAL(valueChanged(int)), this, SLOT(set_values()));
    connect(spn_effort_c, SIGNAL(valueChanged(int)), this, SLOT(set_values()));
    connect(spn_effort_d, SIGNAL(valueChanged(int)), this, SLOT(set_values()));
    connect(spn_effort_s, SIGNAL(valueChanged(int)), this, SLOT(set_values()));
    connect(btn_reset, SIGNAL(clicked()), this, SLOT(reset_count()));

}

std::vector<int> Widget::get_pair(int v, int limit)
{
    if (v == 0)
    {
        std::vector<int> pair = {0, 0, 0};
        return pair;
    }
    else
    {
        int max_i;
        int max_j;
        int max_k;

        if (limit >= 252)
        {
            max_i = 252 / 18;
            max_j = 252 / 2;
            max_k = 251 / 10;
        }
        else
        {
            max_i = limit / 18;
            max_j = limit / 2;
            max_k = limit / 10;
        }
        if (v + 2 == limit)
        {
            std::vector<int> pair = {max_i + 1, 0, 0};
            return pair;
        }
        else
        {
            std::vector<std::vector<int>> pairs;
            for (int i = 0; i <= max_i; ++i)
            {
                for (int j = 0; j <= max_j; ++j)
                {
                    for (int k = 0; k <= max_k; ++k)
                    {
                        if (i * 18 + 2 * j - 10 * k == v)
                        {
                            std::vector<int> pair = {i, j, k};
                            pairs.push_back(pair);
                        }
                    }
                }
            }

            std::vector<int> pairs_sum;
            for (const auto& pair : pairs)
            {
                int pair_sum = std::accumulate(pair.begin(), pair.end(), 0);
                pairs_sum.push_back(pair_sum);
            }

            int argmin;
            argmin = std::distance(pairs_sum.begin(), std::min_element(pairs_sum.begin(), pairs_sum.end()));
            return pairs[argmin];
        }
    }
}

std::map<std::string, std::vector<int>> Widget::get_pairs(int h, int a, int b, int c, int d, int s)
{
    std::map<std::string, int> inputs;
    inputs["h"] = h;
    inputs["a"] = a;
    inputs["b"] = b;
    inputs["c"] = c;
    inputs["d"] = d;
    inputs["s"] = s;

    std::map<std::string, std::vector<int>> outputs;
    int limit = 510;
    for (const auto& input : inputs)
    {
        std::vector<int> pair;
        pair = get_pair(input.second, limit);
        outputs[input.first] = pair;
        limit -= input.second;
    }
    return outputs;
}
