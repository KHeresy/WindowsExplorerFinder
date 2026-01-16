#pragma once

#include <QDialog>
#include "ui_SettingsDialog.h"

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

    static void applyAutoStart(bool enable);
    static QKeySequence getHotkey();
    
    void accept() override;

private:
    Ui::SettingsDialog *ui;
};
