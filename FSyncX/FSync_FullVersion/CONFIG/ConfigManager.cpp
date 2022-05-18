
#include "ConfigManager.h"


ConfigManager::ConfigManager(QObject *parent)
    : QObject{parent}
{

}

Ui::MainWindow *ui  = nullptr;
void ConfigManager::LINK_MW(Ui::MainWindow *mw)
{
    ui = mw;
}




// void ConfigManager::CONFIG_INIT()
// {
//     QSettings FSyncXConfig("FSyncXConfig.ini", QSettings::IniFormat); 
//     FSyncXConfig.setValue("VERSION", "Beta1.0");
//     FSyncXConfig.setValue("THEME","MacOS");

//     CONFIG_UPDATE();
// }

void ConfigManager::CONFIG_UPDATE()
{
    QSettings FSyncXConfig("FSyncXConfig.ini", QSettings::IniFormat); 
    FSyncXConfig.sync();//SAVE FSyncXConfig
}

//操作配置表
void ConfigManager::SET_CONFIG_VALUE(const QString &key,const QVariant &value)
{
    QSettings FSyncXConfig("FSyncXConfig.ini", QSettings::IniFormat); 
    FSyncXConfig.setValue(key, value);
    CONFIG_UPDATE();
}

//读取配置表
QString ConfigManager::GET_CONFIG_VALUE(const QString &key)
{
    QSettings FSyncXConfig("FSyncXConfig.ini", QSettings::IniFormat); 
    return FSyncXConfig.value(key).toString();
}