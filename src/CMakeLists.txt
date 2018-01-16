SET(SOURCE_FILES main.cpp journal.cpp journal.h record.cpp record.h DataBase.cpp DataBase.h client.cpp client.h)
SET(CMAKE_CXX_FLAGS "-lncurses")
ADD_EXECUTABLE(pdiary ${SOURCE_FILES})
