#ifndef PERSONTAGWIDGET_H
#define PERSONTAGWIDGET_H

#include <KDialog>
#include <QListWidget>

class PersonTagWidget : public KDialog
{
    Q_OBJECT
public:
    explicit PersonTagWidget(QWidget *parent = 0);

private:
    void setupGui();
    void setPersons();

private:
    QListWidget* m_personWidget;
};

#endif // PERSONTAGWIDGET_H
