        .386p
CODE32          SEGMENT DWORD PUBLIC USE32 'CODE'

        EXTRN   GpiSetDrawControl:PROC
        PUBLIC  _GpiSetDrawControl
_GpiSetDrawControl PROC NEAR
    push   fs
    mov    eax, 0150bh
    mov    fs, eax
    push   dword ptr [esp+16]
    push   dword ptr [esp+16]
    push   dword ptr [esp+16]
    call   GpiSetDrawControl
    add    esp, 12
    pop    fs
    ret
_GpiSetDrawControl ENDP

CODE32          ENDS

                END
