        .386p
CODE32          SEGMENT DWORD PUBLIC USE32 'CODE'

        EXTRN   SplStdClose:PROC
        PUBLIC  _SplStdClose
_SplStdClose PROC NEAR
    push   fs
    mov    eax, 0150bh
    mov    fs, eax
    push   dword ptr [esp+8]
    call   SplStdClose
    add    esp, 4
    pop    fs
    ret
_SplStdClose ENDP

CODE32          ENDS

                END
