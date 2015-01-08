#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include "ui_SettingsPage.h"

class SettingsPage : public QWidget
{
    Q_OBJECT

public:
    SettingsPage(QWidget* parent = 0);

private:
    Ui::SettingsPage ui;
};

#endif // SETTINGSPAGE_H
