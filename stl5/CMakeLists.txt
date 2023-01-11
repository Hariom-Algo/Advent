# CMakeList.txt : CMake project for hsingh_advent, include source and define
# project specific logic here.
#
# Or use the header-only version
add_executable (stl5 "stl5.cpp" "stl5.h" "stl5.cpp" "stl5.h")

target_link_libraries(stl5 PRIVATE fmt::fmt tl::ranges ctre::ctre)


# TODO: Add tests and install targets if needed.
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET stl5 PROPERTY CXX_STANDARD 23)
endif()