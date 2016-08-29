	.586
	.model flat, stdcall
	option casemap :none

	include \masm32\include\windows.inc
	include \masm32\include\user32.inc
	include \masm32\include\kernel32.inc
	include \masm32\include\masm32.inc

	includelib \masm32\lib\user32.lib
	includelib \masm32\lib\kernel32.lib
	includelib \masm32\lib\masm32.lib


	.data
		_a DWORD 0
		_b DWORD 0
		_i DWORD 0
		_t DWORD 0
		_n DWORD 0
		t0 DWORD 0
		t1 DWORD 0
		buffer BYTE 128 dup(0)
		LF BYTE 13, 10, 0


	.code
_start:
	MOV eax, 0
	MOV _a, eax
	MOV eax, 1
	MOV _b, eax
	MOV eax, 1
	MOV _i, eax
	invoke StdIn, ADDR buffer, 127
	invoke StripLF, ADDR buffer
	invoke atodw, ADDR buffer
	MOV _n, eax
	invoke dwtoa, _a, ADDR buffer
	invoke StdOut, ADDR buffer
	invoke StdOut, ADDR LF
	invoke dwtoa, _b, ADDR buffer
	invoke StdOut, ADDR buffer
	invoke StdOut, ADDR LF
@0:
	MOV eax, _i
	CMP eax, _n
	jl @1
	jmp @2
@1:
	MOV eax, _b
	MOV _t, eax
	MOV eax, _a
	ADD eax, _b
	MOV t0, eax
	MOV eax, t0
	MOV _b, eax
	invoke dwtoa, _b, ADDR buffer
	invoke StdOut, ADDR buffer
	invoke StdOut, ADDR LF
	MOV eax, _t
	MOV _a, eax
	MOV eax, _i
	ADD eax, 1
	MOV t1, eax
	MOV eax, t1
	MOV _i, eax
	jmp @0
@2:
	invoke ExitProcess, 0
end _start
