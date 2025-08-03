#ifndef PCH_H
#define PCH_H

// ========== Qt Core ==========
#include <QObject>
#include <QtGlobal>
#include <QCoreApplication>
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QSettings>
#include <QVariant>
#include <QTextStream>
#include <QDataStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QByteArray>
#include <QThread>
#include <QMutex>
#include <QScopedPointer>
#include <QSharedPointer>
#include <QPointer>
#include <QSignalMapper>

// ========== Qt GUI ==========
#include <QGuiApplication>
#include <QFont>
#include <QColor>
#include <QPixmap>
#include <QIcon>
#include <QImage>
#include <QPalette>
#include <QPainter>
#include <QPaintEvent>
#include <QStyleOption>

// ========== Qt Widgets ==========
#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QToolButton>
#include <QGroupBox>
#include <QTabWidget>
#include <QScrollBar>
#include <QScrollArea>
#include <QProgressBar>
#include <QSlider>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QListView>
#include <QTableView>
#include <QTreeView>
#include <QHeaderView>
#include <QBoxLayout>
#include <QGridLayout>
#include <QStackedWidget>
#include <QSplitter>
#include <QFrame>
#include <QSizePolicy>
#include <QFormLayout>
#include <QGraphicsView>
#include <QGraphicsScene>

// ========== Qt Events & Misc ==========
#include <QMouseEvent>
#include <QKeyEvent>
#include <QResizeEvent>
#include <QCloseEvent>
#include <QDrag>
#include <QDropEvent>
#include <QMimeData>
#include <QClipboard>
#include <QShortcut>
#include <QKeySequence>

// ========== STL ==========
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include <functional>

// ========== Atalhos Qt Containers ==========
#include <QString>
#include <QStringList>
#include <QVector>
#include <QList>
#include <QMap>
#include <QSet>

// ========== Macros úteis ==========
#ifndef UNUSED
#define UNUSED(x) (void)x
#endif

#endif // PCH_H
