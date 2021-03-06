LANGUAGE LANG_JAPANESE, SUBLANG_DEFAULT

SYSMENU MENU LOADONCALL MOVEABLE DISCARDABLE
{
 MENUITEM "元のサイズに戻す(&R)", 61728
 MENUITEM "移動(&M)", 61456
 MENUITEM "サイズ変更(&S)", 61440
 MENUITEM "アイコン化(&N)", 61472
 MENUITEM "最大表\示(&X)", 61488
 MENUITEM SEPARATOR
 MENUITEM "閉じる(&C)\tAlt-F4", 61536
 MENUITEM SEPARATOR
 MENUITEM "アプリケーションの切り替え(&W)...\tCtrl-Esc", 61744
}

SYSMENUWARP MENU LOADONCALL MOVEABLE DISCARDABLE
{
 MENUITEM "ﾌTCYﾉﾟｷ(&R)\tAlt-F5", 61728
 MENUITEM "ﾚ(&M)\tAlt-F7", 61456
 MENUITEM "TCYﾏX(&S)\tAlt-F8", 61440
 MENUITEM "ACR(&N)\tAlt-F9", 61472
 MENUITEM "ﾅ�\\(&X)\tAlt-F10", 61488
 MENUITEM SEPARATOR
 MENUITEM "ﾂ�(&C)\tAlt-F4", 61536
 MENUITEM SEPARATOR
 MENUITEM "AvP[Vﾌﾘ�ﾖ(&W)...\tCtrl-Esc", 61744
}

EDITMENU MENU LOADONCALL MOVEABLE DISCARDABLE
{
        POPUP "" 
        BEGIN
                MENUITEM "元に戻す(&U)", EM_UNDO
                MENUITEM SEPARATOR
                MENUITEM "切り取り(&T)", WM_CUT
                MENUITEM "コピー(&C)", WM_COPY
                MENUITEM "貼\り付け(&P)", WM_PASTE
                MENUITEM "削除(&D)", WM_CLEAR
                MENUITEM SEPARATOR
                MENUITEM "選択(&A)", EM_SETSEL
        END
}

MSGBOX DIALOG 100, 80, 216, 168
STYLE DS_SYSMODAL | DS_MODALFRAME | WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU
BEGIN
        ICON "", 1088, 8, 20, 16, 16, WS_CHILD | WS_VISIBLE
        LTEXT "", 100, 32, 4, 176, 48, WS_CHILD | WS_VISIBLE | WS_GROUP
        PUSHBUTTON "OK", 1, 16, 56, 40, 14, WS_CHILD | WS_VISIBLE | WS_TABSTOP
        PUSHBUTTON "ｷｬﾝｾﾙ", 2, 64, 56, 40, 14, WS_CHILD | WS_VISIBLE | WS_TABSTOP
        PUSHBUTTON "中止(&A)", 3, 112, 56, 40, 14, WS_CHILD | WS_VISIBLE | WS_TABSTOP
        PUSHBUTTON "再試行(&R)", 4, 160, 56, 40, 14, WS_CHILD | WS_VISIBLE | WS_TABSTOP
        PUSHBUTTON "無視(&I)", 5, 208, 56, 40, 14, WS_CHILD | WS_VISIBLE | WS_TABSTOP
        PUSHBUTTON "はい(&Y)", 6, 256, 56, 40, 14, WS_CHILD | WS_VISIBLE | WS_TABSTOP
        PUSHBUTTON "いいえ(&N)", 7, 304, 56, 40, 14, WS_CHILD | WS_VISIBLE | WS_TABSTOP
END
