cmake_minimum_required(VERSION 3.0.2)
project(st9051)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

add_message_files(FILES cmd_vel_tutorial.msg)
generate_messages(DEPENDENCIES std_msgs)

catkin_package(
 INCLUDE_DIRS include
 LIBRARIES ${PROJECT_NAME}
 CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# add_library(${PROJECT_NAME}
#   include/${PROJECT_NAME}/running.h
#   src/running.cpp
# )



# add_executable(pub_cmd_vel src/cmd_vel_pub.cpp src/running.cpp)
# add_dependencies(pub_cmd_vel ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
# target_link_libraries(pub_cmd_vel ${catkin_LIBRARIES})

add_executable(pub_cmd_vel src/cmd_vel_pub.cpp)
add_library(runningt src/running.cpp)
add_dependencies(pub_cmd_vel ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(pub_cmd_vel ${catkin_LIBRARIES} runningt)

add_executable(sub_cmd_vel src/cmd_vel_sub.cpp)
add_dependencies(sub_cmd_vel ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(sub_cmd_vel ${catkin_LIBRARIES})
