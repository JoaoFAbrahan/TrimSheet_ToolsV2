#ifndef SSTYLECOMPONENTS_H
#define SSTYLECOMPONENTS_H

#include <QString>

namespace Model {
struct SStyleComponents {
    QString WindowBackground = ":/Styles/Style_WindowBackground.qss";
    QString MainMenuPanel = ":/Styles/Style_MainMenuPanel.qss";
    QString ContainerPanel = ":/Styles/Style_ContainerPanels.qss";
    QString MenuDockButton = ":/Styles/Style_MenuDockButton.qss";
    QString MenuButton = ":/Styles/Style_MainMenu_Button.qss";
    QString NormalButton = ":/Styles/Style_NormalMenu_Button.qss";
    QString ComboBox = ":/Styles/Style_ComboBox.qss";
    QString CheckBox = ":/Styles/Style_CheckBox.qss";
    QString TextBox = ":/Styles/Style_TextBox.qss";
    QString TitleLabel = ":/Styles/Style_TitleLabel.qss";
    QString NormalLabel = ":/Styles/Style_NormalLabel.qss";
    QString DataGridView = ":/Styles/Style_DataGridView.qss";
};
}
#endif // SSTYLECOMPONENTS_H
