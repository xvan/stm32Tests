cmake_minimum_required(VERSION 3.10)

project(blinker)
message(STATUS "Current Source Dir: ${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_BUILD_TYPE Debug) 
set(LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/src/linker.ld")
#set(LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/src/ASF/sam/utils/linker_scripts/sam4e/sam4e16/gcc/flash.ld")
message(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")
include(toolchain-arm-none-eabi)
#include(sam4e)

#add_definitions(-D__SAM4E16E__ -Dscanf=iscanf -DBOARD=SAM4E_XPLAINED_PRO -DARM_MATH_CM4=true -Dprintf=iprintf -D__SAM4E16E__ -DDEBUG)

#include_directories(
#src
#src/ASF/common/boards
#src/ASF/common/services/clock
#src/ASF/common/services/delay
#src/ASF/common/services/ioport
#src/ASF/common/services/serial
#src/ASF/common/services/serial/sam_uart
#src/ASF/common/services/twi
#src/ASF/common/services/gpio
#src/ASF/common/services/spi
#src/ASF/common/utils
#src/ASF/common/utils/stdio/stdio_serial
#src/ASF/sam/applications/sam_low_power/sam4e16e_sam4e_xplained_pro
#src/ASF/sam/boards
#src/ASF/sam/boards/sam4e_xplained_pro
#src/ASF/sam/components/ethernet_phy/ksz8081mnx
#src/ASF/sam/drivers/efc
#src/ASF/sam/drivers/gmac
#src/ASF/sam/drivers/gpbr
#src/ASF/sam/drivers/matrix
#src/ASF/sam/drivers/pio
#src/ASF/sam/drivers/pmc
#src/ASF/sam/drivers/pwm
#src/ASF/sam/drivers/pdc
#src/ASF/sam/drivers/rstc
#src/ASF/sam/drivers/rtt
#src/ASF/sam/drivers/supc
#src/ASF/sam/drivers/tc
#src/ASF/sam/drivers/twi
#src/ASF/sam/drivers/uart
#src/ASF/sam/drivers/usart
#src/ASF/sam/drivers/wdt
#src/ASF/sam/drivers/spi
#src/ASF/sam/services/flash_efc
#src/ASF/sam/utils
#src/ASF/sam/utils/cmsis/sam4e/include
#src/ASF/sam/utils/cmsis/sam4e/source/templates
#src/ASF/sam/utils/fpu
#src/ASF/sam/utils/header_files
#src/ASF/sam/utils/preprocessor
#src/ASF/thirdparty/CMSIS/Include
#src/ASF/thirdparty/CMSIS/Lib/GCC
#src/config
#src/local
#)

FILE(GLOB_RECURSE BLINK_SRC "src/*.c")
set(TARGET ${PROJECT_NAME}.elf)
add_executable( ${TARGET} ${BLINK_SRC} )
