add_executable(vumeter.exe
               vumeter.cpp vumeter.h)

target_link_libraries(vumeter.exe
				  	  ${catkin_LIBRARIES} 
                      #~ string_utils
				  	  ${Glib_LIBRARIES} ${Glibmm_LIBRARIES}
				  	  ${PULSEAUDIO_LIBRARY} ${PULSEAUDIO_MAINLOOP_LIBRARY})
