# CMakeList.txt : CMake project for hsingh_advent, include source and define
# project specific logic here.
#
# Or use the header-only version
add_executable (day6 "day6.cpp" "day6.h")

target_link_libraries(day6 PRIVATE fmt::fmt tl::ranges ctre::ctre)


# TODO: Add tests and install targets if needed.
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET day6 PROPERTY CXX_STANDARD 20)
endif()