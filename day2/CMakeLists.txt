# CMakeList.txt : CMake project for hsingh_advent, include source and define
# project specific logic here.
#
# Or use the header-only version
find_package(fmt CONFIG REQUIRED)
add_executable (day2 "day2.cpp" "day2.h")

# this is heuristically generated, and may not be correct
find_package(tl-ranges CONFIG REQUIRED)
find_package(ctre CONFIG REQUIRED)

target_link_libraries(day2 PRIVATE fmt::fmt tl::ranges ctre::ctre)


# TODO: Add tests and install targets if needed.
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET day2 PROPERTY CXX_STANDARD 20)
endif()