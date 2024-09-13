# CMake generated Testfile for 
# Source directory: /home/dt/zachet
# Build directory: /home/dt/zachet/_build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(check "/home/dt/zachet/_build/check")
set_tests_properties(check PROPERTIES  _BACKTRACE_TRIPLES "/home/dt/zachet/CMakeLists.txt;46;add_test;/home/dt/zachet/CMakeLists.txt;0;")
subdirs("third-party/gtest")
