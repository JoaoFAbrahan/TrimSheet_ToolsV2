#include "StyleController.h"

namespace Controller {
StyleController::StyleController()
{
    LoadThemesFromQSS();
}

void StyleController::DarkThemeStatus(bool status)
{
    this->_isDarkTheme = status;
}

void StyleController::ApplyStyle(QWidget *objRef, EStyleObjects objTypeRef)
{
    const QVector<QString>& theme = _isDarkTheme ? _darkThemes : _lightThemes;

    if (objTypeRef >= 0 && objTypeRef < theme.size())
        objRef->setStyleSheet(theme[objTypeRef]);
}

void StyleController::LoadThemesFromQSS()
{
    // Prepare the themelists
    _darkThemes.clear();
    _lightThemes.clear();

    // Create the QFile
    const QVector<QString> files = {
        _styles.WindowBackground,
        _styles.MainMenuPanel,
        _styles.ContainerPanels,
        _styles.MenuDockButton,
        _styles.MenuButtons,
        _styles.Buttons,
        _styles.ComboBox,
        _styles.CheckBox,
        _styles.TextBox,
        _styles.TitleLabel,
        _styles.NormalLabel,
        _styles.DataGridView
    };

    for(const QString& filePath : files)
    {
        QFile file(filePath);

        // Validantion
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qWarning() << "Could not open QSS file:" << filePath;
            continue;
        }

        QTextStream in(&file);
        QString qssContent = in.readAll();
        file.close();

        // Get the Dark and Light themes
        QStringList parts = qssContent.split("=== Theme ===", Qt::SkipEmptyParts);
        if (parts.size() >= 2) {
            _darkThemes.append(parts[0].trimmed());
            _lightThemes.append(parts[1].trimmed());
        } else
            qWarning() << "Invalid QSS format in file:" << filePath;
    }
}
}
