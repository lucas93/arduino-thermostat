FUNCTION(print input)
     message(STATUS "${input}: ${${input}}")
ENDFUNCTION()



MACRO(GetListOfSubDirectories result curdir)
  FILE(GLOB_RECURSE  children LIST_DIRECTORIES ON RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${curdir}/${child})
    ENDIF()
  ENDFOREACH()
  LIST(APPEND dirlist ${curdir})
  SET(${result} ${dirlist})
ENDMACRO()


# TODO
MACRO(GetListOfAllFilesInSubDirectories result base_directory filename)
  SET(filelist "")

  GetListOfSubDirectories(dirlist ${base_directory})
  FOREACH(dir ${dirlist})
    FILE(GLOB file   ${dir}/${filename})
      LIST(APPEND filelist ${file})
  ENDFOREACH()
  SET(${result} ${filelist})
ENDMACRO()


FUNCTION(print_foreach input)
    FOREACH(element ${${input}})
        message(STATUS "${input}: ${element}")
    ENDFOREACH()
ENDFUNCTION()



