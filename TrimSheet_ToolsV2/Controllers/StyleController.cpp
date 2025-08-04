#include "StyleController.h"
#include "pch.h"

namespace Controller {
bool Controller::StyleController::_isDarkTheme = false;
QVector<QString> Controller::StyleController::_darkThemes;
QVector<QString> Controller::StyleController::_lightThemes;

StyleController& StyleController::Instance()
{
    static StyleController instance;
    return instance;
}

StyleController::StyleController()
{
    LoadThemesFromQSS();
}

void StyleController::DarkThemeStatus(bool status)
{
    this->_isDarkTheme = status;
}

bool StyleController::GetThemeStatus()
{
    return this->_isDarkTheme;
}

void StyleController::ApplyStyle(QWidget *objRef, EStyleObjects objTypeRef)
{
    const QVector<QString>& theme = _isDarkTheme ? _darkThemes : _lightThemes;

    if (objTypeRef >= 0 && objTypeRef < theme.size())
        objRef->setStyleSheet(theme[objTypeRef]);
}

void StyleController::ApplyMessageBoxStyle(QMessageBox *msgBoxRef)
{
    if(_isDarkTheme)
    {
        //Apply Dark Style
        msgBoxRef->setStyleSheet(R"(
        QDialog  {
            background-color: #0f1011;
        }

        QLabel {
            /* Font Button */
            color: #f5f5f5;
            font-family: 'MollenNarrow_Regular';
            font-size: 8pt;
            text-align: left;
        }

        /* Buttons */
        QPushButton {
            /* Shape Button */
            background-color: #645ac8;

            /* Font Button */
            color: #f5f5f5;
            font-family: 'MollenNarrow_Bold';
            font-size: 10pt;
            font-weight: bold;
            text-align: center;

            /* Icon Button */
            qproperty-iconSize: 30px 30px;
        }

        QPushButton:hover {
            background-color: #69b5ff;
        }

        QPushButton:pressed {
            background-color: #5441F6;
        }

        QPushButton:disabled {
            color: #333333;
            background-color: #f8f8f8;
        }
        )");
    }
    else
    {
        //Apply Light Style
        msgBoxRef->setStyleSheet(R"(
        QDialog  {
            background-color: #e8eaec;
        }

        QLabel {
            /* Font Button */
            color: #0a142a;
            font-family: 'MollenNarrow_Regular';
            font-size: 8pt;
            text-align: left;
        }

        /* Buttons */
        QPushButton {
            /* Shape Button */
            background-color: #645ac8;

            /* Font Button */
            color: #f5f5f5;
            font-family: 'MollenNarrow_Bold';
            font-size: 10pt;
            font-weight: bold;
            text-align: center;

            /* Icon Button */
            qproperty-iconSize: 30px 30px;
        }

        QPushButton:hover {
            background-color: #69b5ff;
        }

        QPushButton:pressed {
            background-color: #5441F6;
        }

        QPushButton:disabled {
            color: #333333;
            background-color: #f8f8f8;
        }
        )");
    }
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
        _styles.ContainerPanel,
        _styles.MenuDockButton,
        _styles.MenuButton,
        _styles.NormalButton,
        _styles.ComboBox,
        _styles.CheckBox,
        _styles.TextBox,
        _styles.TitleLabel,
        _styles.NormalLabel,
        _styles.DataGridView,
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
