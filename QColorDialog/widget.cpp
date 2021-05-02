#include "widget.h"
#include "ui_widget.h"
#include <QColorDialog>
#include <QFontDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
     ui->label->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}




void Widget::on_pushButton_TEXTCOLOR_clicked()
{
    QPalette palette = ui->label->palette();
       QColor color = palette.color(QPalette::WindowText);
       QColor chosenColor = QColorDialog::getColor(color, this, "Choose Text Color");
       if(chosenColor.isValid())
       {
           palette.setColor(QPalette::WindowText, chosenColor);
           ui->label->setPalette(palette);
           qDebug() << " Choosen a valid color";
       }
       else
       {
           qDebug() << " choosen an invalid color";
       }

   }

void Widget::on_pushButton_BACKGROUNDCOLOR_clicked()
{
    QPalette palette = ui->label->palette();
        QColor color = palette.color(QPalette::Window);
        QColor chosenColor = QColorDialog::getColor(color, this, "Choose Background Color");
        if(chosenColor.isValid())
        {
            palette.setColor(QPalette::Window, chosenColor);
            ui->label->setPalette(palette);
            qDebug() << "Choosen a valid color";
        }
        else
        {
            qDebug() << "choosen an invalid color";
        }
}


void Widget::on_pushButton_FONT_clicked()
{
    bool ok;
       QFont chosenFont = QFontDialog::getFont(&ok, ui->label->font(), this, "Choose Font");
       if(ok)
       {
           ui->label->setFont(chosenFont);
           qDebug() << "Choosen a valid Font";
       }
       else
       {
           qDebug() << "Choosen an invalid Font";
       }
}
