option(ENABLE_CPPCHECK "Enable static analysis with cppcheck" ON)
option(ENABLE_CLANG_TIDY "Enable static analysis with clang-tidy" OFF )

if(ENABLE_CPPCHECK)
  find_program(CPPCHECK cppcheck)
  if(CPPCHECK)
  # Ignore Directories: exclude certain folders from the check to avoid irrelevant warnings or speed up the analysis. Use the -i flag for this.  
    #set(CPPCHECK_EXCLUDE_FOLDER "-i ${PROJECT_SOURCE_DIR}/tests -i ${PROJECT_SOURCE_DIR}/external")
    #message(STATUS "CPPCHECK ignore folders parameters: ${CPPCHECK_EXCLUDE_FOLDER}")
    set(CMAKE_CXX_CPPCHECK
        ${CPPCHECK}
        #${CPPCHECK_EXCLUDE_FOLDER}
        --enable=all
        --suppress=unusedFunction
        --suppress=missingIncludeSystem
        --suppress=checkersReport
        --inconclusive)
        message(STATUS "CPPCHECK CMD: ${CMAKE_CXX_CPPCHECK}")
  else()
    message(SEND_ERROR "cppcheck requested but executable not found")
  endif()
endif()

if(ENABLE_CLANG_TIDY)
  find_program(CLANGTIDY clang-tidy)
  if(CLANGTIDY)
    set(CMAKE_CXX_CLANG_TIDY ${CLANGTIDY})
  else()
    message(SEND_ERROR "clang-tidy requested but executable not found")
  endif()
endif()
