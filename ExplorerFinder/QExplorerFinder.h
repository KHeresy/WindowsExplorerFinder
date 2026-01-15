#pragma once

#include <QtWidgets/QWidget>
#include "ui_QExplorerFinder.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QExplorerFinderClass; };
QT_END_NAMESPACE

class QExplorerFinder : public QWidget
{
    Q_OBJECT

public:
    QExplorerFinder(QWidget *parent = nullptr);
    ~QExplorerFinder();

    void setTargetPath(const QString& path);

private slots:
    void on_btnSearch_clicked();
    void on_btnSelectAll_clicked();
    void on_lineEditSearch_returnPressed();
    void on_listResults_itemClicked(QListWidgetItem *item);

private:
    Ui::QExplorerFinderClass *ui;
    QString m_targetPath;
    
    void selectFiles(const QStringList& files);
};

