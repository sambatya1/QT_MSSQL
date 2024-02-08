#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->passLineEdit->setEchoMode(QLineEdit::Password);
    mes = new QMessageBox();
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL Server}; SERVER="+
                       ui->serverLineEdit->text()+"; DATABASE="+
                       ui->databaseLineEdit->text()+";");
    db.setUserName(ui->loginLineEdit->text());
    db.setPassword(ui->passLineEdit->text());
    if(db.open()){
        mes->setText("Все окей!");
    }
    else{
       // qDebug()<<"ERROR: "<<QSqlError(db.lastError()).text();
        mes->setText("ERROR: "+QSqlError(db.lastError()).text());
    }
     mes->show();
}
