add_executable(vumeter.exe
               vumeter.cpp vumeter.h)

target_link_libraries(vumeter.exe
              ${catkin_LIBRARIES}
              ${Glib_LIBRARIES} ${Glibmm_LIBRARIES} ${SIGC++_LIBRARY}
              ${PULSEAUDIO_LIBRARY} ${PULSEAUDIO_MAINLOOP_LIBRARY})
