aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SERVER_SRC )


add_executable(server
    ${SERVER_SRC}
)

target_link_directories(server PUBLIC ${CMAKE_SOURCE_DIR}/mysql)
target_link_libraries(server mysqlcppconn8)