#include "pluginbases/WidgetBase.h"
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>

class PopUp : public WidgetBase
{
public:
    PopUp () {
        layout = new QHBoxLayout(this);
        lineEdit = new QLineEdit(this);
        btn = new QPushButton(this);

        lineEdit->setPlaceholderText("Enter data ...");
        btn->setText("Display to console");

        QObject::connect(btn, &QPushButton::clicked, this, [this](){
            qDebug() << "data of lineEdit:"  << lineEdit->text();
        });

        layout->addWidget(lineEdit);
        layout->addWidget(btn);
        this->setLayout(layout);
//        this->setMinimumSize(200, 300);
    }

private:
    QHBoxLayout *layout;
    QLineEdit *lineEdit;
    QPushButton *btn;
};


IMPORT_PLUGIN(PopUp)
