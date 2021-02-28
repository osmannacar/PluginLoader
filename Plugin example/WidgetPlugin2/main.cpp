#include "pluginbases/WidgetBase.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

class Confirm : public WidgetBase
{
public:
    Confirm() {
        layout = new QVBoxLayout(this);
        label = new QLabel(this);
        btn = new QPushButton(this);
        btn->setText("Confirm");

        label->setText("Do you want to confirm?");

        QObject::connect(btn, &QPushButton::clicked, this, [this](){
            qDebug() << "Confirmed by user" ;
            this->close();
        });

        layout->addWidget(label);
        layout->addWidget(btn);
        this->setLayout(layout);
    }

private:
    QVBoxLayout *layout;
    QLabel *label;
    QPushButton *btn;
};


IMPORT_PLUGIN(Confirm)
