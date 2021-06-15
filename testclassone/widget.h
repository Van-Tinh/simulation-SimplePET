#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:

private slots:

    void on_Apply_clicked();

    void on_Ok_clicked();

    void on_Applyroot_clicked();

    void on_appl_clicked();

    void on_Cancel_clicked();
    void display();


private:
    Ui::Widget *ui;

};
#endif // WIDGET_H
