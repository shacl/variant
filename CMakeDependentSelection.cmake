include(Backports/IncludeGuard)
include_guard(GLOBAL)

function(CMAKE_DEPENDENT_SELECTION variable docstring)
  cmake_parse_arguments(${variable}_selection
    "" "DEFAULT;CONDITION" OPTIONS ${ARGN})

  if(NOT DEFINED ${variable}_selection_OPTIONS)
    message(FATAL_ERROR
      "CMAKE_DEPENDENT_SELECTION invoked without 'OPTIONS' keyword")
  endif()

  if(NOT DEFINED ${variable}_selection_CONDITION)
    message(FATAL_ERROR
      "CMAKE_DEPENDENT_SELECTION invoked without 'CONDITION' keyword")
  endif()

  if(NOT DEFINED ${variable}_selection_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR
      "CMAKE_DEPENDENT_SELECTION invoked without fallback value")
  else()
    list(GET ${variable}_selection_UNPARSED_ARGUMENTS "0"
      ${variable}_selection_fallback)
    list(REMOVE_AT ${variable}_selection_UNPARSED_ARGUMENTS "0")
    if(${variable}_selection_UNPARSED_ARGUMENTS)
      message("CMAKE_DEPENDENT_SELECTION called with unparsed arguments")
      message(FATAL_ERROR "unparsed arguments: ${${variable}_selection_UNPARSED_ARGUMENTS}")
    endif()
  endif()

  set(${variable}_selection_AVAILABLE TRUE)
  foreach(condition ${${variable}_selection_CONDITION})
    string(REGEX REPLACE " +" ";" condition "${condition}")
    if(${condition})
    else()
      set(${variable}_selection_AVAILABLE FALSE)
    endif()
  endforeach()

  if(${variable}_selection_AVAILABLE)
    if(DEFINED ${variable}_selection_DEFAULT)
      selection(${variable} "${docstring}"
        DEFAULT "${${variable}_selection_DEFAULT}"
        OPTIONS "${${variable}_selection_OPTIONS}")
    else()
      selection(${variable} "${docstring}"
        OPTIONS "${${variable}_selection_OPTIONS}")
    endif()
    set(${variable} "${${variable}}" CACHE STRING "${docstring}" FORCE)
  else()
    if(DEFINED ${variable})
      set(${variable} "${${variable}}" CACHE INTERNAL "${docstring}")
    endif()
    set(${variable} "${${variable}_selection_fallback}" PARENT_SCOPE)
  endif()
endfunction()
