
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} CLIENT_SRC)


add_executable(client
    ${CLIENT_SRC}
)

target_link_directories(client PUBLIC ${CMAKE_SOURCE_DIR}/mysql)
target_link_libraries(client mysqlcppconn8)
