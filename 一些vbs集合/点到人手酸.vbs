on error resume next
msgbox "�ܺã���㿪���ң�ȷ���Լ�����",vbInformation+vbSystemModel,"���ڵ�"
c=0
p=0
do
    s=Eval(inputbox ("����������������֣�"&vbCrLF&"������50��1000֮�䣩","���ڵ�","1000"))
    if s>=50 and s<=1000 then
        for i=0 to s-1
            select case round(rnd*4)
            case 0
                if msgbox("����Ҫ��ȷ��"&s-i&"�£�"&vbCrLF&"�Ҿ���ʧ�ˣ�",vbMsgBoxRight+vbInformation+vbSystemModel+vbOKCancel+vbDefaultButton2,"���ڵ�")=vbCancel then
                    p=1
                end if
            case 1
                if msgbox("����Ҫ��ȷ��"&s-i&"�£�"&vbCrLF&"�Ҿ���ʧ�ˣ�",vbMsgBoxRight+vbInformation+vbSystemModel+vbOKCancel+vbDefaultButton1,"���ڵ�")=vbCancel then
                    p=1
                end if
            case 2
                if msgbox("������Ҫ��ȷ��"&s-i&"��"&vbCrLF&"���Ҿ���ʧ��",vbMsgBoxRight+vbInformation+vbMsgBoxRtlReading+vbSystemModel+vbOKCancel+vbDefaultButton1,"���ڵ�")=vbCancel then
                p=1
                end if
            case 3
                if msgbox("������Ҫ��ȷ��"&s-i&"��"&vbCrLF&"���Ҿ���ʧ��",vbMsgBoxRight+vbInformation+vbMsgBoxRtlReading+vbSystemModel+vbOKCancel+vbDefaultButton2,"���ڵ�")=vbCancel then
                p=2
                end if
            end select
            if p=1 then
                p=0
                msgbox "�����Ȼ�����ң������������κ�����"&vbCrLF&"!���Ҵ������˷������ͷ����",vbMsgBoxRtlReading+vbMsgBoxRight+vbExclamation+vbSystemModel+vbOKCancel+vbDefaultButton2,"���ڵ�"
                c=c+1
                i=i-1
            end if
            if p=2 then
                p=0
                msgbox "���Ȼ�����ң������������κ����ã�"&vbCrLF&"���Ҵ������˷������ͷ����!",vbExclamation+vbSystemModel+vbOKCancel+vbDefaultButton2,"���ڵ�"
                c=c+1
                i=i-1
            end if
            if c=int(s/5) then
                c=0
                msgbox "�㰴��ȡ������̫�࣬��ͷ������",vbCritical+vbSystemModel,"���ڵ�"
                i=-1
            end if
        next
        if  msgbox("��Ҫ������",vbQuestion+vbSystemModel+vbYesNo+vbDefaultButton1,"���ڵ�")=vbNo then
            exit do
        end if
        msgbox "�õģ���������һ��",vbInformation+vbSystemModel,"���ڵ�"
    else
        msgbox "����ˣ���ͷ����",vbCritical+vbSystemModel,"���ڵ�"
    end if
loop