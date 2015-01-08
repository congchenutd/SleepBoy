#ifndef SLEEPITEMEDITORFACTORY_H
#define SLEEPITEMEDITORFACTORY_H

#include <QItemEditorFactory>

class SleepItemEditorFactory : public QItemEditorFactory
{
public:
    QWidget* createEditor(int userType, QWidget* parent) const;
};

#endif // SLEEPITEMEDITORFACTORY_H
