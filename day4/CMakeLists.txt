# CMakeList.txt : CMake project for hsingh_advent, include source and define
# project specific logic here.
#
# Or use the header-only version
add_executable (day4 "day4.cpp" "day4.h")

target_link_libraries(day4 PRIVATE tl::ranges ctre::ctre)


# TODO: Add tests and install targets if needed.
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET day4 PROPERTY CXX_STANDARD 20)
endif()