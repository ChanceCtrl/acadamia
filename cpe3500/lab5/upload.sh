openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program build/Lab2.elf verify reset exit"
