add_executable(02_forward_declaration
        main.cc
        src/arme.cc
        src/joueur.cc)
target_include_directories(02_forward_declaration PRIVATE include)
