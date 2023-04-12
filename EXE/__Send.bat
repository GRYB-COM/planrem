copy RejRem.exe RejRem.e__ /y
zip RejRem.z__ RejRem.e__
rar a RejRem.r__ RejRem.z__
copy RejRem.r__ T:\ /y
wscript mail.vbs
del RejRem.e__
del RejRem.z__
del RejRem.r__