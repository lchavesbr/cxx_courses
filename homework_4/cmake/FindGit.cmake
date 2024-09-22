# Adapted from https://cliutils.gitlab.io/modern-cmake/chapters/projects/submodule.html

find_program (GIT_FOUND "git")
if(GIT_FOUND)
    execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse --show-toplevel
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}                
                    OUTPUT_VARIABLE GIT_ROOT_FOLDER)
endif()

include(CMakePrintHelpers)
cmake_print_variables(GIT_EXECUTABLE GIT_FOUND GIT_ROOT_FOLDER)


if(GIT_FOUND AND EXISTS "${GIT_ROOT_FOLDER}/.git") #Git folder is Uni-Bonn
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/googletest/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()