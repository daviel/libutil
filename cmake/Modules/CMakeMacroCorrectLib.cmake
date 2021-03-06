
MACRO(CORRECT_LIB library name)
	IF( CMAKE_CROSSCOMPILING AND APPLE)
		WHILE(IS_DIRECTORY ${${library}})
			STRING(REPLACE ";" " " TMP "${${library}}")
			SEPARATE_ARGUMENTS(TMP)

			SET(new_library "NOTFOUND")
			FOREACH(path ${TMP})
				IF(IS_DIRECTORY "${path}" )
					IF(EXISTS ${path}/${name})
						SET(new_library ${path}/${name})
					ENDIF()
					IF(EXISTS ${path}/${name}.tbd)
						SET(new_library ${path}/${name}.tbd)
					ENDIF()
				ENDIF()
			ENDFOREACH()
			
			IF(new_library)
				MESSAGE(STATUS "Found ${name}: ${new_library}")
				SET(${library} ${new_library})
			ENDIF()
		ENDWHILE()
	ELSE()
		MESSAGE(STATUS "Found ${name}: ${${library}}")
	ENDIF()
ENDMACRO(CORRECT_LIB)
