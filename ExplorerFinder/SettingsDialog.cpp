#include "SettingsDialog.h"
#include <QSettings>
#include <QCoreApplication>
#include <QDir>
#include <QKeySequence>

#ifdef Q_OS_WIN
#include <windows.h>
#endif

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SettingsDialog())
{
    ui->setupUi(this);

    QSettings settings("ExplorerFinder", "ExplorerFinder");
    
    // Load Hotkey
    QString hotkeyStr = settings.value("GlobalHotkey", "Ctrl+F3").toString();
    ui->keySequenceEdit->setKeySequence(QKeySequence::fromString(hotkeyStr));

    // Load AutoStart
    bool autoStart = settings.value("AutoStart", false).toBool();
    ui->chkAutoStart->setChecked(autoStart);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::accept()
{
    QSettings settings("ExplorerFinder", "ExplorerFinder");
    
    QString newHotkey = ui->keySequenceEdit->keySequence().toString();
    bool newAutoStart = ui->chkAutoStart->isChecked();

    settings.setValue("GlobalHotkey", newHotkey);
    settings.setValue("AutoStart", newAutoStart);

    applyAutoStart(newAutoStart);

    QDialog::accept();
}

void SettingsDialog::applyAutoStart(bool enable)
{
#ifdef Q_OS_WIN
    QSettings bootSettings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
    QString appPath = QDir::toNativeSeparators(QCoreApplication::applicationFilePath());
    if (enable) {
        bootSettings.setValue("ExplorerFinder", """ + appPath + """);
    } else {
        bootSettings.remove("ExplorerFinder");
    }
#endif
}

QKeySequence SettingsDialog::getHotkey()
{
    QSettings settings("ExplorerFinder", "ExplorerFinder");
    return QKeySequence::fromString(settings.value("GlobalHotkey", "Ctrl+F3").toString());
}
