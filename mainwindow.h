#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    bool CheckMagicNumber();

protected:
    QSqlDatabase db;

    bool InitDatabase(QString path);

    bool GetSeries(QStringList &series);

    bool CheckQueryResult(const QSqlQuery& q);

private slots:
    // series check box的槽
    void stateChanged(int state);

};

#endif // MAINWINDOW_H
