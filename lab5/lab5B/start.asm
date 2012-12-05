section .text
	
global _start
global read
global write
global open
global close
global strlen
extern main
_start:

	mov	eax, esp
	add	eax, 4
	push	eax
	push	dword [esp]	
	
	
	call	main
        mov     ebx,eax
	mov	eax,1
	int 0x80

read:
	mov edx, [esp+12]
	mov ecx, [esp+8]
	mov ebx, [esp+4]
	mov eax, 3
	int 0x80
	ret

write:
	mov edx, [esp+12]
	mov ecx, [esp+8]
	mov ebx, [esp+4]
	mov eax, 4
	int 0x80
	ret

open:
	mov edx, [esp+12]
	mov ecx, [esp+8]
	mov ebx, [esp+4]
	mov eax, 5
	int 0x80
	ret

close:
	mov ebx, [esp+4]
	mov eax, 6
	int 0x80
	ret

strlen:
	push	ebp
	mov	ebp, esp
	mov	dword eax, 0 ; i
	mov	dword edx, 1 
.Loop:
	test	dl, dl				;the curr char
	je	.FinishLoop
	mov	edx, DWORD [ebp+8] 		; edx = ourString
	add	edx, ebx  			; edx = &ourString[i]
	mov	dl, [edx]			; edx = ourString[i]
	inc	eax
	jmp	.Loop
.FinishLoop:
	mov esp, ebp
	pop ebp
	ret



