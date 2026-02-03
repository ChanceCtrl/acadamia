openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program build/Lab1.elf verify reset exit"
