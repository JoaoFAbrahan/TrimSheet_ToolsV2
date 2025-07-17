cmake_minimum_required(VERSION 3.16)

project(TrimSheet_ToolsV2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

# Lista todos os arquivos .cpp, .h e .ui das pastas Views, Models, Controllers
file(GLOB_RECURSE VIEW_FORMS          "${CMAKE_SOURCE_DIR}/Views/*.cpp" "${CMAKE_SOURCE_DIR}/Views/*.h" "${CMAKE_SOURCE_DIR}/Views/*.ui")
file(GLOB_RECURSE VIEW_COMPONENTS     "${CMAKE_SOURCE_DIR}/Views/Components/*.cpp" "${CMAKE_SOURCE_DIR}/Views/Components/*.h" "${CMAKE_SOURCE_DIR}/Views/Components/*.ui")
file(GLOB_RECURSE MODEL_SOURCES       "${CMAKE_SOURCE_DIR}/Models/*.cpp" "${CMAKE_SOURCE_DIR}/Models/*.h")
file(GLOB_RECURSE CONTROLLER_SOURCES  "${CMAKE_SOURCE_DIR}/Controllers/*.cpp" "${CMAKE_SOURCE_DIR}/Controllers/*.h")

# View Module
set(VIEW_SOURCES
    ${VIEW_FORMS}
    ${VIEW_COMPONENTS}
)

# Arquivos de tradução
set(TS_FILES Resources/Translations/TrimSheet_ToolsV2_en_US.ts)

# Arquivo resource
set(RESOURCE_FILES
    Resources/resources.qrc
    ${TS_FILES}
)

# Lista de fontes
set(PROJECT_SOURCES
    # Entry Point
    main.cpp

    # MVC Modules
    ${VIEW_SOURCES}
    ${MODEL_SOURCES}
    ${CONTROLLER_SOURCES}

    # Resource
    ${RESOURCE_FILES}
)

# Criação do executável
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TrimSheet_ToolsV2
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Views/ToogleStyle.h
        Views/switch.h Views/switch.cpp

    )

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(TrimSheet_ToolsV2 SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(TrimSheet_ToolsV2
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

# Link com bibliotecas Qt
target_link_libraries(TrimSheet_ToolsV2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Configurações específicas para bundle (macOS, iOS, etc.)
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

# Instalação
include(GNUInstallDirs)
install(TARGETS TrimSheet_ToolsV2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finaliza (Qt 6)
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TrimSheet_ToolsV2)
endif()
