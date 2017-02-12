# Install script for directory: C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/stitching

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x86/vc15/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/lib/Debug/opencv_stitching320d.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x86/vc15/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/lib/Release/opencv_stitching320.lib")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "libs" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x86/vc15/bin" TYPE SHARED_LIBRARY OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/bin/Debug/opencv_stitching320d.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x86/vc15/bin" TYPE SHARED_LIBRARY OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/bin/Release/opencv_stitching320.dll")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/stitching/include/opencv2/stitching.hpp")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/stitching" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/stitching/include/opencv2/stitching/warpers.hpp")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/stitching/detail" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/stitching/include/opencv2/stitching/detail/autocalib.hpp")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/stitching/detail" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/stitching/include/opencv2/stitching/detail/blenders.hpp")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/stitching/detail" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/stitching/include/opencv2/stitching/detail/camera.hpp")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/stitching/detail" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/stitching/include/opencv2/stitching/detail/exposure_compensate.hpp")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/stitching/detail" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/stitching/include/opencv2/stitching/detail/matchers.hpp")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/stitching/detail" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/stitching/include/opencv2/stitching/detail/motion_estimators.hpp")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/stitching/detail" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/stitching/include/opencv2/stitching/detail/seam_finders.hpp")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/stitching/detail" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/stitching/include/opencv2/stitching/detail/timelapsers.hpp")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/stitching/detail" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/stitching/include/opencv2/stitching/detail/util.hpp")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/stitching/detail" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/stitching/include/opencv2/stitching/detail/util_inl.hpp")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/stitching/detail" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/stitching/include/opencv2/stitching/detail/warpers.hpp")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/stitching/detail" TYPE FILE OPTIONAL FILES "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/stitching/include/opencv2/stitching/detail/warpers_inl.hpp")
endif()

