cmake_minimum_required (VERSION 3.17)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()



#Setup vcpkg script with CMake bfore project() call
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "") 

project ("animation-engine")

find_package(FFMPEG REQUIRED) # Only works with vcpkg

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake) # For calling Findraylib.cmake
set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} MODULE QUIET) # Will call FetchContent if raylib not found


# Include sub-projects.
add_subdirectory ("src")
