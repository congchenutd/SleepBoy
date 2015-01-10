#include "SettingsPage.h"
#include <QFileDialog>

SettingsPage::SettingsPage(QWidget* parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    connect(ui.btSave,          SIGNAL(clicked()), this, SLOT(onSave()));
    connect(ui.btStoragePath,   SIGNAL(clicked()), this, SLOT(onSetStoragePath()));
}

void SettingsPage::load()
{
    ui.leUrl            ->setText   (_settings.getUrl());
    ui.sbFPS            ->setValue  (_settings.getFPS());
    ui.sbWidth          ->setValue  (_settings.getMinWidth());
    ui.sbHeight         ->setValue  (_settings.getMinHeight());
    ui.sbNumber         ->setValue  (_settings.getMinNumber());
    ui.sbStorageInterval->setValue  (_settings.getStorageInterval());
    ui.leStoragePath    ->setText   (_settings.getStoragePath());
    ui.sbMaxDays        ->setValue  (_settings.getMaxDays());
    ui.sbMaxStorage     ->setValue  (_settings.getMaxStorage());
}

void SettingsPage::onSave()
{
    _settings.setUrl            (ui.leUrl->text());
    _settings.setFPS            (ui.sbFPS->value());
    _settings.setMinWidth       (ui.sbWidth ->value());
    _settings.setMinHeight      (ui.sbHeight->value());
    _settings.setMinNumber      (ui.sbNumber->value());
    _settings.setStorageInterval(ui.sbStorageInterval->value());
    _settings.setStoragePath    (ui.leStoragePath->text());
    _settings.setMaxStorage     (ui.sbMaxDays->value());
    _settings.setMaxDays        (ui.sbMaxDays->value());
}

void SettingsPage::onSetStoragePath()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    ".",  QFileDialog::ShowDirsOnly);
    if(!dir.isEmpty())
        ui.leStoragePath->setText(dir);
}
