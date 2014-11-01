#############################################
##### Declaring
#############################################

set(libname  "fedosov-alexander-lengthconverter-library")
set(testname "fedosov-alexander-lengthconverter-test")

message("")
message("############################################")
message("##### Testing ${libname}")
message("############################################")
message("")

#############################################
##### Building
#############################################

# Declare directory with public headers
add_dir_inc("./")

# Declare static library
add_lib_static(${libname} "Includes" "src")

# Declare module with unit tests
add_local_dependency(${libname})
add_app(${testname} "Test")
target_link_libraries(${testname})
