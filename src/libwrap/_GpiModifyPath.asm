        .386p
CODE32          SEGMENT DWORD PUBLIC USE32 'CODE'

        EXTRN   GpiModifyPath:PROC
        PUBLIC  _GpiModifyPath
_GpiModifyPath PROC NEAR
    push   fs
    mov    eax, 0150bh
    mov    fs, eax
    push   dword ptr [esp+16]
    push   dword ptr [esp+16]
    push   dword ptr [esp+16]
    call   GpiModifyPath
    add    esp, 12
    pop    fs
    ret
_GpiModifyPath ENDP

CODE32          ENDS

                END
