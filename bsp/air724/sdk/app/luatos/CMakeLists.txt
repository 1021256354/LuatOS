
file(GLOB SC_FILE *.c)
if(CONFIG_APPIMG_LOAD_FLASH)
add_appimg(${target} ${flash_ldscript} ${SC_FILE})
else(CONFIG_APPIMG_LOAD_FLASH)
add_appimg(${target} ${file_ldscript} ${SC_FILE})
endif()