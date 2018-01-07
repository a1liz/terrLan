.586
.model flat, stdcall
option casemap :none

__UNICODE__ equ 1
include \masm32\include\windows.inc
include \masm32\macros\macros.asm
include \masm32\include\msvcrt.inc
include \masm32\include\gdi32.inc
include \masm32\include\user32.inc
include \masm32\include\kernel32.inc
include \masm32\include\masm32.inc

includelib \masm32\lib\gdi32.lib
includelib \masm32\lib\msvcrt.lib
includelib \masm32\lib\user32.lib
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\masm32.lib

.data
	$Int_Fmt_Input db '%d', 0
	$Int_Fmt_Output db '%d', 13, 10, 0
	$Char_Fmt_Input db '%c', 0
	$Char_Fmt_Output db '%c', 13, 10, 0
	$a$ SDWORD ?
	$b$ SDWORD ?
	$i$ SDWORD ?
	$c$ SDWORD ?
	$tmp0$ DWORD ?
	$tmp1$ DWORD ?
	$tmp2$ DWORD ?
	$tmp3$ DWORD ?
	$tmp4$ DWORD ?
	$tmp5$ DWORD ?



.code
start:
@0:
	MOV eax, 10
	MOV $a$, eax

	MOV eax, 8
	MOV $b$, eax

	MOV eax, 0
	MOV $i$, eax

@2:
	MOV eax, $i$
	MOV ecx, 10
	CMP eax, ecx
	JL @4
	JMP @3

@4:
	INVOKE crt_printf, ADDR $Int_Fmt_Output, $i$
	MOV eax, $i$
	MOV ecx, 3
	CMP eax, ecx
	JL @8
	JMP @9

@9:
	MOV eax, $i$
	MOV ecx, 5
	CMP eax, ecx
	JG @8
	JMP @7

@8:
	MOV eax, $i$
	MOV ecx, 7
	CMP eax, ecx
	JL @6
	JMP @7

@6:
@10:
	INVOKE crt_printf, ADDR $Int_Fmt_Output, 15
@7:
	MOV eax, $i$
	MOV $tmp4$, eax
	INC eax
	MOV $i$, eax

	JMP @2
@3:

	INVOKE crt_scanf, ADDR $Int_Fmt_Input, ADDR $c$
	;invoke ExitProcess, 0
end start
