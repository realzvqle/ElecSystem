set_project("elec")

set_xmakever("2.6.0")

set_languages("c99")

target("elec")
    set_kind("binary")  
    add_files("src/*.c")
    add_files("src/**/*.c") 
    add_includedirs("src") 