#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QWidget>
#include <QMenu>
#include "Liste.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLeftClick();
    void onRightClickAction1();
    void onRightClickAction2();
    void onRightClickAction3();
    void on_Bouton_ajouter_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton *myButton;
    QMenu *contextMenu;
    QVBoxLayout *layout;
    QWidget *containerWidget;
    QScrollArea *scrollArea;
    int j=0;
    int k=3;
    int compteur;
    void fontTitre();
    void setupButton();
    void setupContextMenu();
    void newButton();
    void setupScrollArea();
};
#endif // MAINWINDOW_H
