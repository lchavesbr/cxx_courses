# Adapted fromm  https://github.com/ttroy50/cmake-examples/

option(ENABLE_CLANG_FORMAT "Enable code format analysis with clang-format" ON)

if(ENABLE_CLANG_FORMAT)

  find_program(CLANG_FORMAT "clang-format")
  if(NOT CLANG_FORMAT)
    message(SEND_ERROR "clang-format not found on your \$\{PATH\}")
  endif()


# Split the regex into multiple parts
set(EXCLUDE_BUILD "\\( -path ./build -o -path ./tests -o -path ./external \\) -prune -o")
set(REGEX "-regextype posix-extended -regex")
set(CPP_EXT "'.*\\.(cpp|cxx|cc|hpp|hxx|h)'")
set(TRIM_OUT "-print |  tr '\\n' ';'")

# Get all project files
execute_process(
  COMMAND bash -c "find . ${EXCLUDE_BUILD} ${REGEX} ${CPP_EXT} ${TRIM_OUT}"
  OUTPUT_VARIABLE ALL_SOURCES
  OUTPUT_STRIP_TRAILING_WHITESPACE
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

add_custom_target(${PROJECT_NAME}_format ALL
                  COMMENT "Checking clang-format changes"
                  #WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                  COMMAND ${CLANG_FORMAT} -Werror
                          --dry-run --ferror-limit=1 -style=file ${ALL_SOURCES})
message(STATUS "Clang-format will be applied to the following files: ${ALL_SOURCES}")
endif()