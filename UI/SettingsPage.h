#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include "ui_SettingsPage.h"
#include "MySettings.h"

class SettingsPage : public QWidget
{
    Q_OBJECT

public:
    SettingsPage(QWidget* parent = 0);
    void load();

public slots:
    void onSave();
    void onSetStoragePath();

private:
    Ui::SettingsPage ui;
    MySettings _settings;
};

#endif // SETTINGSPAGE_H
