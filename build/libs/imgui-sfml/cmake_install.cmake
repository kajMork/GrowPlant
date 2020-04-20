# Install script for directory: /Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/imgui-sfml

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/imgui-sfml/libImGui-SFML.dylib")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImGui-SFML.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImGui-SFML.dylib")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/SFML/lib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImGui-SFML.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" -x "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImGui-SFML.dylib")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/imgui-sfml/imgui-SFML.h"
    "/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/imgui-sfml/imgui-SFML_export.h"
    "/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/imgui-sfml/imconfig-SFML.h"
    "/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/imgui/imconfig.h"
    "/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/imgui/imgui.h"
    "/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/imgui/imgui_internal.h"
    "/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/imgui/imstb_rectpack.h"
    "/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/imgui/imstb_textedit.h"
    "/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/imgui/imstb_truetype.h"
    "/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/libs/imgui/misc/cpp/imgui_stdlib.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML/ImGui-SFMLConfig.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML/ImGui-SFMLConfig.cmake"
         "/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/imgui-sfml/CMakeFiles/Export/lib/cmake/ImGui-SFML/ImGui-SFMLConfig.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML/ImGui-SFMLConfig-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML/ImGui-SFMLConfig.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML" TYPE FILE FILES "/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/imgui-sfml/CMakeFiles/Export/lib/cmake/ImGui-SFML/ImGui-SFMLConfig.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML" TYPE FILE FILES "/Users/madsrossen/Documents/VS_code/projects/greenhouse_simulator/build/libs/imgui-sfml/CMakeFiles/Export/lib/cmake/ImGui-SFML/ImGui-SFMLConfig-debug.cmake")
  endif()
endif()

