;start.asm
.extern _main

entry start

start: call _main
infLoop: jmp infLoop
