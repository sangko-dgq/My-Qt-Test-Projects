
#include "ThemeManager.h"


ThemeManager::ThemeManager(QObject *parent)
    : QObject{parent}
{

}

Ui::MainWindow *ui_ThemeManager  = nullptr;
void ThemeManager::LINK_MW(Ui::MainWindow *mw)
{
    ui_ThemeManager = mw;
}


/*读取配 置，根据读取的配置加载对应主题*/
void ThemeManager::setAPPTheme_FROM_CONFIG()
{
    QString theme_value = configManager->GET_CONFIG_VALUE("THEME");
    commonHelper->setStyle("://" + theme_value + ".qss");

}

/*设置主题，并写入到配置表里面*/
void ThemeManager::setAPPTheme(QString theme)
{
    //设置主题 
    commonHelper->setStyle("://" + theme + ".qss");
    //写入配置表
    configManager->SET_CONFIG_VALUE("THEME", theme);
}

/*下拉列表选择主题*/
