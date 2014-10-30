#############################################
##### Declaring
#############################################

set(libname  "fedosov-alexander-colorspaceconverter-library")
set(testname "fedosov-alexander-colorspaceconverter-test")

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
