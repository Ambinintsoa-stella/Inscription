#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Liste.hpp"
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>
#include <QRect>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,compteur(0)
{
    ui->setupUi(this);
    fontTitre();
    setupButton();
    setupContextMenu();
    ui->textEdit_affichage->setReadOnly(true);
    ui->textEdit_affichage->insertPlainText("p1\np2\np3");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupButton()
{
    QList<QPushButton *> allButtons = this->findChildren<QPushButton *>();
    for (QPushButton *buttonsfor: allButtons)
        if (buttonsfor->objectName().startsWith("Button_"))
        {
            buttonsfor->setContextMenuPolicy(Qt::CustomContextMenu);
            connect(buttonsfor, &QPushButton::clicked, this, &MainWindow::onLeftClick);
            connect(buttonsfor, &QPushButton::customContextMenuRequested, this, [=](const QPoint &pos)
            {
                QPoint globalPos = buttonsfor->mapToGlobal(pos);
                contextMenu->exec(globalPos);
            });
        }
}

void MainWindow::setupContextMenu()
{
    contextMenu = new QMenu(this);
    QAction *action1 = contextMenu->addAction("Modifier");
    QAction *action2 = contextMenu->addAction("Supprimer");
    contextMenu->addSeparator();
    QAction *action3 = contextMenu->addAction("Propriétés");

    connect(action1, &QAction::triggered, this, &MainWindow::onRightClickAction1);
    connect(action2, &QAction::triggered, this, &MainWindow::onRightClickAction2);
    connect(action3, &QAction::triggered, this, &MainWindow::onRightClickAction3);
}
void MainWindow::newButton()
{
    k++;
    myButton = new QPushButton(QString("p%1").arg(k), this);
    j++;
    if (j>3)
    {
        j=1;
        compteur++;
    }
    myButton->setGeometry(compteur*120+180,313+j*39,88,26);
    myButton->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(myButton, &QPushButton::clicked, this, &MainWindow::onLeftClick);
    connect(myButton, &QPushButton::customContextMenuRequested, this, [this](const QPoint &pos)
    {
        QPoint globalPos = myButton->mapToGlobal(pos);
        contextMenu->exec(globalPos);
    });
    myButton->show();
    ui->textEdit_affichage->append(QString("p%1").arg(k));
}
void MainWindow::on_Bouton_ajouter_clicked()
{
    Personne p4;
    p4.setName("Pers4");
    p4.setId("004");
    Liste i;
    i.inscrire(p4);
    newButton();
}

void MainWindow::onLeftClick()
{

}

void MainWindow::onRightClickAction1()
{
    //Personne::setName() || setId();
    //QMessageBox::information(this,"Modification","Name: QString(%1).arg")
}

void MainWindow::onRightClickAction2()
{
    //Liste::desabonner(p);
}

void MainWindow::onRightClickAction3()
{
    //Personne::getName() && getId();
}

void MainWindow::fontTitre()
{
    QFont font2= ui->label_title2->font();
    font2.setBold(true);
    ui->label_title2->setFont(font2);
    QFont font1= ui->label_title1->font();
    font1.setBold(true);
    ui->label_title1->setFont(font1);
}

void MainWindow::setupScrollArea()
{

}

