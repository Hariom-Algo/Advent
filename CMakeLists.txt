# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("hsingh_advent")
include(C:/VCPKG/vcpkg/scripts/buildsystems/vcpkg.cmake)
include_directories( ${Boost_INCLUDE_DIRS} )
# this is heuristically generated, and may not be correct
find_package(fmt CONFIG REQUIRED)
find_package(tl-ranges CONFIG REQUIRED)
find_package(ctre CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options regex )

find_package(fmt CONFIG REQUIRED)
# Include sub-projects.
add_subdirectory ("day1")
add_subdirectory ("day2")
add_subdirectory ("day3")
add_subdirectory ("day4")
add_subdirectory ("day5")
add_subdirectory ("day6")
add_subdirectory ("day7")
add_subdirectory ("day8")
add_subdirectory ("day9")