﻿# CMakeList.txt : CMake project for hsingh_advent, include source and define
# project specific logic here.
#



add_executable (day1 "day1.cpp" "day1.h")



target_link_libraries(day1 PRIVATE fmt::fmt tl::ranges ctre::ctre)


# TODO: Add tests and install targets if needed.
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET day1 PROPERTY CXX_STANDARD 20)
endif()