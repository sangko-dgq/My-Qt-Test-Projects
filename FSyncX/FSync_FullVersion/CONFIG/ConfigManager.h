
#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H


#include "../UI_Modules/QHeaders.h"
#include "../mainwindow.h"
#include "../ui_mainwindow.h"

#include <QSettings>

class ConfigManager : public QObject
{
    Q_OBJECT

public:
    explicit ConfigManager(QObject *parent = nullptr);
    void LINK_MW(Ui::MainWindow *mw);
    

private:
    
    


public:
    
    // void CONFIG_INIT();
    void CONFIG_UPDATE();
    QString GET_CONFIG_VALUE(const QString &key);
    void SET_CONFIG_VALUE(const QString &key, const QVariant &value);

    
};




#endif