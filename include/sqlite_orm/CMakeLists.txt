add_library(sqlite_orm INTERFACE)

# Set up include directories
target_include_directories(sqlite_orm INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/sqlite_orm>
        $<INSTALL_INTERFACE:include/sqlite_orm>
        )