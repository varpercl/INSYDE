# Install script for directory: C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/objdetect

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x86/vc15/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/lib/Debug/opencv_objdetect320d.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x86/vc15/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/lib/Release/opencv_objdetect320.lib")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "libs" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x86/vc15/bin" TYPE SHARED_LIBRARY OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/bin/Debug/opencv_objdetect320d.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x86/vc15/bin" TYPE SHARED_LIBRARY OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/bin/Release/opencv_objdetect320.dll")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/objdetect/include/opencv2/objdetect.hpp")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/objdetect" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/objdetect/include/opencv2/objdetect/detection_based_tracker.hpp")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/objdetect" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/objdetect/include/opencv2/objdetect/objdetect.hpp")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/objdetect" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/objdetect/include/opencv2/objdetect/objdetect_c.h")
endif()

