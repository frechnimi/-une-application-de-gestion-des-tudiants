cmake_minimum_required(VERSION 3.16)

project(gestionE VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools Sql)

set(TS_FILES gestionE_en_150.ts)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ajouterEtudient.h
        ajouteretudient.cpp
        ajouteretudient.ui
        ajouternote.h
        ajouternote.cpp
        ajouternote.ui
        modifiernote.h
        modifiernote.cpp
        modifiernote.ui
        # modifieretudient.h
        # modifieretudient.cpp
        # modifieretudient.ui
        filtrer.h
        filtrer.cpp
        filtrer.ui
        supprimer.h
        supprimer.cpp
        supprimer.ui
        trier.h
        trier.cpp
        trier.ui
        databaseheader.h
        modifiernote12.h
        modifiernote12.cpp
        modifiernote12.ui
        modifierprenom.h
        modifierprenom.cpp
        modifierprenom.ui
        modifiercne.h
        modifiercne.cpp
        modifiercne.ui
        modifiermassar.h
        modifiermassar.cpp
        modifiermassar.ui
        modifierdate.h
        modifierdate.cpp
        modifierdate.ui
        modifieretudient2.ui
        modifieretudient2.h
        modifieretudient2.cpp
        listev.ui
        listev.h
        listev.cpp
        listnv.h
        listnv.cpp
        listnv.ui

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(gestionE
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ajouteretudient.h ajouteretudient.cpp ajouteretudient.ui
        ajouternote.h ajouternote.cpp ajouternote.ui
        modifiernote.h modifiernote.cpp modifiernote.ui
        modifieretudient.h modifieretudient.cpp modifieretudient.ui
        filtrer.h filtrer.cpp filtrer.ui
        consulter.h consulter.cpp consulter.ui
        supprimer.h supprimer.cpp supprimer.ui
        trier.h trier.cpp trier.ui
        databaseheader.h
        modifiernote12.h modifiernote12.cpp modifiernote12.ui
        modifierprenom.h modifierprenom.cpp modifierprenom.ui
        modifiercne.h modifiercne.cpp modifiercne.ui
        modifiermassar.h modifiermassar.cpp modifiermassar.ui
        modifierdate.h modifierdate.cpp modifierdate.ui
        modifieretudient2.h modifieretudient2.cpp modifieretudient2.ui
        listev.h listev.cpp listev.ui
        listnv.h listnv.cpp listnv.ui
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET gestionE APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(gestionE SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(gestionE
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(gestionE PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.gestionE)
endif()
set_target_properties(gestionE PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS gestionE
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(gestionE)
endif()





