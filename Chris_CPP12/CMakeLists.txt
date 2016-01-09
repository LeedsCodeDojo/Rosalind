cmake_minimum_required(VERSION 3.0)

project ("Rosalind")

include_directories (${CMAKE_SOURCE_DIR})
include_directories (${CMAKE_SOURCE_DIR}/shared/tclap/include)
include_directories (${CMAKE_SOURCE_DIR}/shared/utils)

SET(PROBLEM_SOURCES 
    DNA.cpp
    DNA.h
    RNA.cpp
    RNA.h
    REVC.cpp
    REVC.h
    GC.cpp
    GC.h
    FIB.cpp
    FIB.h
    PROT.cpp
    PROT.h
    HAMM.cpp
    HAMM.h
)

SET(LIB_SOURCES 
    main.cpp
    shared/utils/stringutils.cpp
    shared/utils/stringutils.h
    fasta.cpp
    fasta.h
    codon.cpp
    codon.h
    Common.h
)

SET (GLOB DATA_FILES data/*.txt 
)

add_executable(Rosalind 
    ${PROBLEM_SOURCES}
    ${LIB_SOURCES}
    ${DATA_FILES}
    ) 

 SOURCE_GROUP ("Problems" FILES ${PROBLEM_SOURCES})
 SOURCE_GROUP ("Lib" FILES ${LIB_SOURCES})
 SOURCE_GROUP ("Data" FILES ${DATA_FILES})

