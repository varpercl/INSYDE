# CMake generated Testfile for 
# Source directory: C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/calib3d
# Build directory: C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/modules/calib3d
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(opencv_test_calib3d "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/bin/Debug/opencv_test_calib3dd.exe" "--gtest_output=xml:opencv_test_calib3d.xml")
  set_tests_properties(opencv_test_calib3d PROPERTIES  LABELS "Main;opencv_calib3d;Accuracy" WORKING_DIRECTORY "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/test-reports/accuracy")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(opencv_test_calib3d "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/bin/Release/opencv_test_calib3d.exe" "--gtest_output=xml:opencv_test_calib3d.xml")
  set_tests_properties(opencv_test_calib3d PROPERTIES  LABELS "Main;opencv_calib3d;Accuracy" WORKING_DIRECTORY "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/test-reports/accuracy")
else()
  add_test(opencv_test_calib3d NOT_AVAILABLE)
endif()
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(opencv_perf_calib3d "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/bin/Debug/opencv_perf_calib3dd.exe" "--gtest_output=xml:opencv_perf_calib3d.xml")
  set_tests_properties(opencv_perf_calib3d PROPERTIES  LABELS "Main;opencv_calib3d;Performance" WORKING_DIRECTORY "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/test-reports/performance")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(opencv_perf_calib3d "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/bin/Release/opencv_perf_calib3d.exe" "--gtest_output=xml:opencv_perf_calib3d.xml")
  set_tests_properties(opencv_perf_calib3d PROPERTIES  LABELS "Main;opencv_calib3d;Performance" WORKING_DIRECTORY "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/test-reports/performance")
else()
  add_test(opencv_perf_calib3d NOT_AVAILABLE)
endif()
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(opencv_sanity_calib3d "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/bin/Debug/opencv_perf_calib3dd.exe" "--gtest_output=xml:opencv_perf_calib3d.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
  set_tests_properties(opencv_sanity_calib3d PROPERTIES  LABELS "Main;opencv_calib3d;Sanity" WORKING_DIRECTORY "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/test-reports/sanity")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(opencv_sanity_calib3d "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/bin/Release/opencv_perf_calib3d.exe" "--gtest_output=xml:opencv_perf_calib3d.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
  set_tests_properties(opencv_sanity_calib3d PROPERTIES  LABELS "Main;opencv_calib3d;Sanity" WORKING_DIRECTORY "C:/Users/Edixon Vargas/Documents/GitHub/INSYDE_Repo/INSYDE/external/opencv/sources/test-reports/sanity")
else()
  add_test(opencv_sanity_calib3d NOT_AVAILABLE)
endif()
