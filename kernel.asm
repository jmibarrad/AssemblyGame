;kernel.asm contains assembly functions that you can use in your kernel

	.global _putInMemory
	.global _makeInterrupt21
	.global _readChar
	.global _clrScreen
	.global _moveCursor
	.global _getCurrentRow
	.global _getCurrentColumn
	.global _scrollUp
	.global _mod
	.global _setVideoMode
	.global _putPixel
	.global _printCharVGA
	.global _showCursor

_showCursor:
	mov ax, #0x01
	int #0x33
	ret

_printCharVGA:
	push bp
	mov bp, sp
	mov ah, #0xE
	mov al, [bp+4]
	mov bh, #0
	mov bl, [bp+6]
	int #0x10
	pop bp
	ret

_setVideoMode:
	mov ah, #0x00
	mov al, #0x13
	int #0x10
	ret

_putPixel:
	push bp
	mov bp, sp
	mov ah, #0x0C
	mov al, [bp+8]
	mov cx, [bp+6]
	mov dx, [bp+4]
	int #0x10
	pop bp
	ret
;void putInMemory (int segment, int address, char character)
_putInMemory:
	push bp
	mov bp,sp
	push ds
	mov ax,[bp+4]
	mov si,[bp+6]
	mov cl,[bp+8]
	mov ds,ax
	mov [si],cl
	pop ds
	pop bp
	ret
;_mod(dividend, divisor)
_mod:
	push bp
	mov bp, sp
	xor dx, dx
	mov ax, [bp+4]
	mov bx, [bp+6]
	div bx
	mov ax, dx
	pop bp
	ret

_readChar:
	mov ah, #0
	int #0x16
	ret

_clrScreen:
	mov ah,#6    
        mov al,#0
        mov bh,#7
        mov cx,#0
        mov dl,#79
        mov dh,#24
        int  #0x10
	call _setCursor
	ret

_setCursor:
	mov ah, #2		;Set cursor position
	mov bh, #0		;Page Number
	mov dh, #3		;Row
	mov dl, #0		;Column
	int #0x10
	mov ah, #0xB		;Set background/border Color
	mov bh, #0		
	mov bl, #0xC0   	;Set color
	int #0x10
	ret

_moveCursor:
	push bp
	mov bp,sp
	mov bh, #0		;Page Number
	mov dh,[bp+6]   	;Row
	mov dl,[bp+4]   	;Column
	mov ah,#0x2
	int #0x10
	pop bp
	ret

_getCurrentRow:
	mov ah,#0x3
	mov bh,#0  ;  page
	int #0x10
	xor ax,ax
	mov al,dh
	ret

_getCurrentColumn:
	mov ah,#0x3
	mov bh,#0  ;  page
	int #0x10
	xor ax,ax
	mov al,dl
	ret

;void makeInterrupt21()
;this sets up the interrupt 0x21 vector
;when an interrupt 0x21 is called in the future, 
;_interrupt21ServiceRoutine will run
_makeInterrupt21:
	mov dx,#_interrupt21ServiceRoutine	;get the address of the service routine
	push ds
	mov ax, #0	;interrupts are in lowest memory
	mov ds,ax
	mov si,#0x84	;interrupt 0x21 vector (21 * 4 = 84)
	mov ax,cs	;have interrupt go to the current segment
	mov [si+2],ax
	mov [si],dx	;set up our vector
	pop ds
	ret

_interrupt21ServiceRoutine:

	jmp _end

_end:
	iret

_scrollUp:
	push bp
	mov bp, sp
	mov ah, #0x6
	mov al, [bp+4]		;# of lines to scroll
	mov bh, #0x7
	xor cx, cx
	mov dh, #24
	mov dl, #79
	int #0x10
	pop bp
	ret
