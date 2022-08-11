cmake_minimum_required(VERSION 3.22)
project(controlsmm VERSION 1.0)

set(LIBRARY_NAME controls)

list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake)
set(GENERATED_FILES_DIR ${PROJECT_BINARY_DIR}/generated)
set(GENERATED_DATA_DIR ${GENERATED_FILES_DIR}/data)

set(GRESOURCE_FILE ${GENERATED_DATA_DIR}/${LIBRARY_NAME}.gresource.xml)

find_package(GTKMM)

configure_file(gresource.xml.in ${GRESOURCE_FILE})

macro(compile_control_resources OUTPUT)
    find_program(GLIB_RESOURCE_COMPILER NAMES glib-compile-resources REQUIRED)

    set(GRESOURCE_FILE ${GENERATED_DATA_DIR}/${LIBRARY_NAME}.gresource.xml)
    set(WORK_DIR ${CMAKE_CURRENT_SOURCE_DIR})

    if(${ARGC} GREATER 1)
        foreach(arg IN ITEMS ${ARGN})
            string(CONCAT RESOURCE ${WORK_DIR}/ui/ ${arg})
            list(APPEND RESOURCES ${RESOURCE})
        endforeach()
    endif()

    add_custom_command(
        OUTPUT ${OUTPUT}
        WORKING_DIRECTORY ${WORK_DIR}
        COMMAND ${GLIB_RESOURCE_COMPILER} --target=${OUTPUT} --generate-source ${GRESOURCE_FILE}
        DEPENDS ${GRESOURCE_FILE} ${RESOURCES}
        COMMENT "Generating ${OUTPUT}..."
        )
endmacro()

compile_control_resources(
    ${GENERATED_DATA_DIR}/resources_control.c
    wifisignalicon.ui
    )

add_library(${LIBRARY_NAME} SHARED
    wifisignalicon.cpp
    ${GENERATED_DATA_DIR}/resources_control.c
    )

link_directories(
    ${GTKMM_LIBRARY_DIRS}
    )

include_directories(
    ${GTKMM_INCLUDE_DIRS}
    )
