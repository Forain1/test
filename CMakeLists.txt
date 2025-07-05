cmake_minimum_required(VERSION 3.19)
project(learn LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)

qt_standard_project_setup()
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# 翻译源文件
set(TS_FILES learn_zh_CN.ts)
qt6_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

qt_add_executable(learn
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    form.h form.cpp form.ui
    src.qrc
)

# 把生成的 .qm 加进资源文件（你可以手动，也可以把 src.qrc 改为自动添加 ${QM_FILES}）
# 如果你不加进 .qrc，你可以 runtime 加载 .qm（更灵活）

target_link_libraries(learn
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS learn
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET learn
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
