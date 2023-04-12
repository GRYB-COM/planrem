rem ----------------------------------------------------------------------
rem Kontrola poprawnoœci bazy
rem U.I. INFO-SYSTEM, 2002
rem ----------------------------------------------------------------------
rem Wykonanie kopii bazy , Odtworzenie z kopii
rem Parametr - nazwa bazy (bez rozszerzenia !!!)
rem Przed ca³¹ akcj¹ tworzona jest kopia bazy o nazwie $olddb$.ib
rem Podczas dzia³ania inni uzytkownicy nie mog¹ korzystaæ z bazy !
rem ----------------------------------------------------------------------
del  $olddb$.ib
gfix -sh -force 60 -user sysdba -password masterkey %1.GDB
copy %1.GDB    $olddb$.ib 
echo on
gfix -v  -f     -i -user sysdba -password masterkey %1.GDB
gfix -commit all   -user sysdba -password masterkey %1.GDB
gfix -mend -i  -ig -f  -user sysdba -password masterkey %1.GDB

gbak -B -i -v    -ig   -user sysdba -pas      masterkey %1.GDB %1.GBK
gbak -FIX_FSS_METADATA WIN1250 -REP   -v   -user sysdba -pas      masterkey %1.GBK %1.GDB

endlocal