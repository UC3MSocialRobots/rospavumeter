### 1 - Required CMake Version
cmake_minimum_required(VERSION 2.8.3)
### 2- Package Name
project(rospavumeter)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra") # add extra warnings
### 3 - Find other CMake/Catkin packages needed for build
find_package(catkin REQUIRED COMPONENTS roscpp roslib
                                        std_msgs
                                        #~ utils
                                        )

find_package(PulseAudio REQUIRED)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake/Modules")
find_package(Glib REQUIRED)
find_package(Glibmm REQUIRED)

### 4 - Message/Service/Action Generators (add_message_files(), add_service_files(), add_action_files())
# nothing to do

### 5 - Invoke message/service/action generation (generate_messages())
## Generate added messages and services with any dependencies listed here

### 6 - Specify package build info export (catkin_package())
catkin_package(
  INCLUDE_DIRS src
  CATKIN_DEPENDS roscpp roslib std_msgs
)

### 7 - Libraries/Executables to build (add_library()/add_executable()/target_link_libraries())
include_directories(
  include
  src
  ${catkin_INCLUDE_DIRS}
  ${SIGC++_INCLUDE_DIR}
  ${Glib_INCLUDE_DIRS}
  ${Glibmm_INCLUDE_DIRS}
  ${PULSEAUDIO_INCLUDE_DIR}
)
ADD_DEFINITIONS(-std=c++11)

ADD_SUBDIRECTORY(src)

### 8 - Tests to build (catkin_add_gtest())
#~ ADD_SUBDIRECTORY(test)
### 9 - Install rules (install())
install(DIRECTORY include/${PROJECT_NAME}/
   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
   FILES_MATCHING PATTERN "*.h"
   PATTERN ".svn" EXCLUDE
)
