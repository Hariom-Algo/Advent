# CMakeList.txt : CMake project for hsingh_advent, include source and define
# project specific logic here.
#
# Or use the header-only version
add_executable (day3 "day3.cpp" "day3.h")

target_link_libraries(day3 PRIVATE fmt::fmt tl::ranges ctre::ctre)


# TODO: Add tests and install targets if needed.
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET day3 PROPERTY CXX_STANDARD 20)
endif()