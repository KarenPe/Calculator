cmake_minimum_required(VERSION 3.5)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

project(Calculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)

get_property(QT_CORE_INCLUDE_DIRS TARGET Qt5::Core PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
get_property(QT_GUI_INCLUDE_DIRS TARGET Qt5::Gui PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
get_property(QT_WIDGETS_INCLUDE_DIRS TARGET Qt5::Widgets PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
list(GET QT_CORE_INCLUDE_DIRS 0 QT_CORE_MAIN_INCLUDE_DIR)
get_filename_component(QT_MAIN_DIR ${QT_CORE_MAIN_INCLUDE_DIR}/.. ABSOLUTE)
set(QT_INCLUDE_DIRS ${QT_CORE_INCLUDE_DIRS} ${QT_GUI_INCLUDE_DIRS} ${QT_WIDGETS_INCLUDE_DIRS})
set(INCLUDES "")
foreach(INCLUDE_DIR ${QT_INCLUDE_DIRS})
    list(APPEND INCLUDES "-I${INCLUDE_DIR}")
endforeach()

add_executable(Calculator
        WIN32 main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        form.h
        form.cpp
        form.ui
        difform.h
        difform.cpp
        difform.ui
)

find_package(Doxygen)
if (DOXYGEN_FOUND)
  set(doxyfile_cfg ${CMAKE_CURRENT_BINARY_DIR}/doxyfile.cfg)

  add_custom_target(get_doc ALL
                                        COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile_cfg}
                                        COMMENT "Generating API documentation with Doxygen"
                                        VERBATIM)
endif()

set(dir_src_doc ${CMAKE_CURRENT_BINARY_DIR}/doc/rtf/)
install(
        DIRECTORY
                "${dir_src_doc}"
        DESTINATION
                doc
)
install(FILES $<TARGET_FILE:Qt5::Widgets> DESTINATION bin)


install(FILES $<TARGET_FILE:Qt5::Gui> DESTINATION bin)


install(FILES $<TARGET_FILE:Qt5::Core> DESTINATION bin)


install(
        TARGETS
                Calculator
        DESTINATION
                bin
)
install(DIRECTORY ${QT_MAIN_DIR}/plugins/platforms/
            DESTINATION bin/Plugins/platforms)

install(DIRECTORY ${QT_MAIN_DIR}/plugins/imageformats/
                DESTINATION bin/Plugins/imageformats)



target_link_libraries(Calculator PRIVATE Qt5::Widgets PRIVATE Qt5::Gui)
