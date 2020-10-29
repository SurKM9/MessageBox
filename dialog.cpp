#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    // using static api
    QMessageBox::information(this, "Information Box", "This is an informative message");
    QMessageBox::critical(this, "Critical Box", "This is a critical message");
    QMessageBox::question(this, "Question Box", "This is a question");
    QMessageBox::warning(this, "Warning Box", "This is a warning message");

    // using message box instances
    QMessageBox msgBox;
    msgBox.setText("Custom message");
    msgBox.exec();

    QMessageBox msgBox2;
    msgBox2.setText("Highly customised message box");
    msgBox2.setInformativeText("Including standard buttons");
    msgBox2.setStandardButtons(QMessageBox::Save |
                               QMessageBox::Discard |
                               QMessageBox::Cancel);
    msgBox2.setDefaultButton(QMessageBox::Save);
    msgBox2.exec();
}
