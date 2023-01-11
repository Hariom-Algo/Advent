# CMakeList.txt : CMake project for hsingh_advent, include source and define
# project specific logic here.
#
# Or use the header-only version
add_executable (kata "kata.cpp" "kata.h" "kata.cpp" "kata.h")

target_link_libraries(kata PRIVATE fmt::fmt tl::ranges ctre::ctre)


# TODO: Add tests and install targets if needed.
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET kata PROPERTY CXX_STANDARD 23)
endif()