# CMakeList.txt : CMake project for hsingh_advent, include source and define
# project specific logic here.
find_package(PythonInterp)
find_package(Python)


# Skip compiler check by enabling no languages.
project(day7 NONE)

# Tell CMake to run python from the directory where this CMakeLists file exists.
execute_process(COMMAND python day7.py
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

