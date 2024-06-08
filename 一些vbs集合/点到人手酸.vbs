on error resume next
msgbox "很好，你点开了我（确定以继续）",vbInformation+vbSystemModel,"点亿点"
c=0
p=0
do
    s=Eval(inputbox ("请输入你的幸运数字！"&vbCrLF&"（介于50到1000之间）","点亿点","1000"))
    if s>=50 and s<=1000 then
        for i=0 to s-1
            select case round(rnd*4)
            case 0
                if msgbox("还需要点确定"&s-i&"下！"&vbCrLF&"我就消失了！",vbMsgBoxRight+vbInformation+vbSystemModel+vbOKCancel+vbDefaultButton2,"点亿点")=vbCancel then
                    p=1
                end if
            case 1
                if msgbox("还需要点确定"&s-i&"下！"&vbCrLF&"我就消失了！",vbMsgBoxRight+vbInformation+vbSystemModel+vbOKCancel+vbDefaultButton1,"点亿点")=vbCancel then
                    p=1
                end if
            case 2
                if msgbox("！还需要点确定"&s-i&"下"&vbCrLF&"！我就消失了",vbMsgBoxRight+vbInformation+vbMsgBoxRtlReading+vbSystemModel+vbOKCancel+vbDefaultButton1,"点亿点")=vbCancel then
                p=1
                end if
            case 3
                if msgbox("！还需要点确定"&s-i&"下"&vbCrLF&"！我就消失了",vbMsgBoxRight+vbInformation+vbMsgBoxRtlReading+vbSystemModel+vbOKCancel+vbDefaultButton2,"点亿点")=vbCancel then
                p=2
                end if
            end select
            if p=1 then
                p=0
                msgbox "！你居然忽视我，这样不会有任何作用"&vbCrLF&"!而且次数多了反而会从头来过",vbMsgBoxRtlReading+vbMsgBoxRight+vbExclamation+vbSystemModel+vbOKCancel+vbDefaultButton2,"点亿点"
                c=c+1
                i=i-1
            end if
            if p=2 then
                p=0
                msgbox "你居然忽视我，这样不会有任何作用！"&vbCrLF&"而且次数多了反而会从头来过!",vbExclamation+vbSystemModel+vbOKCancel+vbDefaultButton2,"点亿点"
                c=c+1
                i=i-1
            end if
            if c=int(s/5) then
                c=0
                msgbox "你按的取消次数太多，重头再来！",vbCritical+vbSystemModel,"点亿点"
                i=-1
            end if
        next
        if  msgbox("你要继续吗？",vbQuestion+vbSystemModel+vbYesNo+vbDefaultButton1,"点亿点")=vbNo then
            exit do
        end if
        msgbox "好的，我们再来一遍",vbInformation+vbSystemModel,"点亿点"
    else
        msgbox "输错了！重头再来",vbCritical+vbSystemModel,"点亿点"
    end if
loop