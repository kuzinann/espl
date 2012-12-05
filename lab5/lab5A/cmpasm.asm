section .text
	global cmpstr

cmpstr:
	push	ebp
	mov	ebp, esp
	mov	dword ebx, 0 ; i
	mov	dword edx, 1

.Loop:
	test	dl, dl
	je	FinishLoop
	mov	ecx, DWORD [ebp+12] 		; ecx = shiran
	add	ecx, ebx  			; ecx = &shiran[i]
	mov	cl, [ecx]			; ecx = shiran[i]
	mov	edx, DWORD [ebp+8] 		; edx = anna
	add	edx, ebx  			; edx = &anna[i]
	mov	dl, [edx]			; edx = anna[i]
	inc	ebx
	cmp	cl, dl
	je	.Loop
FinishLoop:


	cmp	cl, dl	
	je	.L5
	jg	.L6
	mov	eax, 1
	mov esp, ebp
	pop ebp
	ret
.L6:
	mov	eax, 2
	mov esp, ebp
	pop ebp
	ret
.L5:
	mov	eax, 0
	mov esp, ebp
	pop ebp
	ret
	
	
