.586
.model flat, stdcall
option casemap:none
includelib msvcrt.lib
printf proto c: ptr sbyte, : vararg
scanf proto c: ptr sbyte, : vararg
.data
@00000000 byte 37 ,100 ,0
@00000001 byte 37 ,100 ,10 ,0
@00000002 byte 37 ,100 ,10 ,0
@00000003 byte 37 ,100 ,10 ,0
.code
start:
call _main
ret

_main:
push ebp
mov ebp, esp
sub esp, 4
mov eax, 0
push eax
lea eax, [ebp + -4]
pop ecx
mov [eax], ecx
mov eax, [eax]
sub esp, 4
mov eax, 1
push eax
lea eax, [ebp + -8]
pop ecx
mov [eax], ecx
mov eax, [eax]
sub esp, 4
mov eax, 1
push eax
lea eax, [ebp + -12]
pop ecx
mov [eax], ecx
mov eax, [eax]
sub esp, 4
sub esp, 4
lea eax, [ebp + -20]
push eax
lea eax, @00000000
push eax
call scanf
add esp, 8
mov eax, [ebp + -4]
push eax
lea eax, @00000001
push eax
call printf
add esp, 8
mov eax, [ebp + -8]
push eax
lea eax, @00000002
push eax
call printf
add esp, 8
label0:
mov eax, [ebp + -20]
push eax
mov eax, [ebp + -12]
pop ecx
cmp eax, ecx
setb al
movsx eax, al
cmp eax, 0
je label1
mov eax, [ebp + -8]
push eax
lea eax, [ebp + -16]
pop ecx
mov [eax], ecx
mov eax, [eax]
mov eax, [ebp + -8]
push eax
mov eax, [ebp + -4]
pop ecx
add eax, ecx
push eax
lea eax, [ebp + -8]
pop ecx
mov [eax], ecx
mov eax, [eax]
mov eax, [ebp + -8]
push eax
lea eax, @00000003
push eax
call printf
add esp, 8
mov eax, [ebp + -16]
push eax
lea eax, [ebp + -4]
pop ecx
mov [eax], ecx
mov eax, [eax]
mov eax, 1
push eax
mov eax, [ebp + -12]
pop ecx
add eax, ecx
push eax
lea eax, [ebp + -12]
pop ecx
mov [eax], ecx
mov eax, [eax]
jmp label0
label1:
add esp, 20
pop ebp
ret

end start
