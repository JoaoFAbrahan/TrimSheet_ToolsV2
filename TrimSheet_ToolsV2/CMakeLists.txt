cmake_minimum_required(VERSION 3.16)

project(TrimSheet_ToolsV2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools Core)

# === Fontes MVC ===
file(GLOB_RECURSE VIEW_FORMS          "${CMAKE_SOURCE_DIR}/Views/*.cpp" "${CMAKE_SOURCE_DIR}/Views/*.h" "${CMAKE_SOURCE_DIR}/Views/*.ui")
file(GLOB_RECURSE MODEL_SOURCES       "${CMAKE_SOURCE_DIR}/Models/*.cpp" "${CMAKE_SOURCE_DIR}/Models/*.h")
file(GLOB_RECURSE CONTROLLER_SOURCES  "${CMAKE_SOURCE_DIR}/Controllers/*.cpp" "${CMAKE_SOURCE_DIR}/Controllers/*.h")

set(VIEW_SOURCES ${VIEW_FORMS})

# === Arquivos de tradução ===
set(TS_FILES Resources/Translations/TrimSheet_ToolsV2_en_US.ts)

# === Geração das traduções (.qm) ===
qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

# === Arquivos do projeto ===
set(PROJECT_SOURCES
    main.cpp
    ${VIEW_SOURCES}
    ${MODEL_SOURCES}
    ${CONTROLLER_SOURCES}
)

# === Recursos (resources.qrc) ===
qt_add_resources(GENERATED_RESOURCE_FILES
    Resources/resources.qrc
)

# === Executável (Qt6 ou Qt5) ===
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    find_package(Qt6 REQUIRED COMPONENTS Widgets)

    qt_add_executable(TrimSheet_ToolsV2
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${GENERATED_RESOURCE_FILES}
        Models/SStyleComponents.h
        Controllers/Components/EStyleObjects.h
        Controllers/StyleController.h Controllers/StyleController.cpp
        Resources/Styles/Style_MainMenuPanel.qss
        Resources/Styles/Style_MenuDockButton.qss
    )
    qt_finalize_executable(TrimSheet_ToolsV2)
else()
    if(ANDROID)
        add_library(TrimSheet_ToolsV2 SHARED
            ${PROJECT_SOURCES}
            ${GENERATED_RESOURCE_FILES}
        )
    else()
        add_executable(TrimSheet_ToolsV2
            ${PROJECT_SOURCES}
            ${GENERATED_RESOURCE_FILES}
        )
    endif()
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

# === Link com bibliotecas Qt ===
target_link_libraries(TrimSheet_ToolsV2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(TrimSheet_ToolsV2 PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(TrimSheet_ToolsV2 PRIVATE Qt6::Widgets)

# === Includes ===
file(GLOB_RECURSE VIEW_HEADER_PATHS "${CMAKE_SOURCE_DIR}/Views/*.h")
file(GLOB_RECURSE CONTROLLER_HEADER_PATHS "${CMAKE_SOURCE_DIR}/Controllers/*.h")

set(INCLUDE_DIRS "")
foreach(HEADER ${VIEW_HEADER_PATHS} ${CONTROLLER_HEADER_PATHS})
    get_filename_component(DIR ${HEADER} DIRECTORY)
    list(APPEND INCLUDE_DIRS ${DIR})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)

target_include_directories(TrimSheet_ToolsV2 PRIVATE
    ${CMAKE_SOURCE_DIR}/Models
    ${INCLUDE_DIRS}
)

# === Bundle config (macOS/iOS/Win32) ===
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.TrimSheet_ToolsV2)
endif()

set_target_properties(TrimSheet_ToolsV2 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# === Instalação ===
include(GNUInstallDirs)
install(TARGETS TrimSheet_ToolsV2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
