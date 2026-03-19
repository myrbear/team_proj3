#ifndef MODESELECTSCREEN_H
#define MODESELECTSCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QHeaderView>

class modeselectscreen : public QWidget
{
    Q_OBJECT
public:
    explicit modeselectscreen(QWidget *parent = nullptr);
private:
    QPushButton *play1Button;
    QPushButton *play2Button;
signals:
    void startMenu(int players);
};

#endif // MODESELECTSCREEN_H
