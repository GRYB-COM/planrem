object _AccessDM: T_AccessDM
  OldCreateOrder = False
  Height = 293
  Width = 661
  object m_Conn: TADOConnection
    ConnectionString = 'FILE NAME=P:\PLANREM\IMPORT\FROMMDB\import.udl;'
    KeepConnection = False
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 24
    Top = 16
  end
  object m_JWADO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from [Dane JW i przedsi'#281'biorstw]')
    Left = 104
    Top = 16
  end
  object m_OddDAO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT DISTINCT [Nazwy warsztat'#243'w kom'#243'rek].Oddzia'#322
      'FROM [Nazwy warsztat'#243'w kom'#243'rek]')
    Left = 184
    Top = 16
  end
  object m_GrupySPrzADO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT DISTINCT [Grupy i rodzaje sprz'#281'tu].[Grupa sprz'#281'tu]'
      'FROM [Grupy i rodzaje sprz'#281'tu]')
    Left = 40
    Top = 80
  end
  object m_RodzajeSprzętuADO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT DISTINCT [Grupy i rodzaje sprz'#281'tu].[Grupa sprz'#281'tu], '
      ' [Grupy i rodzaje sprz'#281'tu].[Rodzaj sprz'#281'tu]'
      'FROM [Grupy i rodzaje sprz'#281'tu]')
    Left = 152
    Top = 80
  end
  object m_WydzDAO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT '
      'distinct wydzia'#322', '
      #39'G'#322#243'wny wydzia'#322' produkcyjny'#39' as [Nazwa pe'#322'na]'
      ' FROM  [Nazwy warsztat'#243'w kom'#243'rek] where wydzia'#322' = '#39'W1'#39
      'union'
      'select distinct wydzia'#322', [Nazwa pe'#322'na]'
      ' FROM  [Nazwy warsztat'#243'w kom'#243'rek] where Wydzia'#322' = Warsztat')
    Left = 256
    Top = 16
  end
  object m_KomorkiADO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      
        'select distinct oddzia'#322', wydzia'#322', [Nazwa pe'#322'na], Warsztat, Stano' +
        'wisko, [Kierownik w-tu]'
      ' FROM  [Nazwy warsztat'#243'w kom'#243'rek] ')
    Left = 344
    Top = 16
  end
  object m_SprzetADO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT   distinct '
      'AR.[Nazwa sprz'#281'tu], '
      'AR.[Warsztat wiod'#261'cy],'
      'JIM.[INDEKS JIM],'
      '0 as [Grupa sprz'#281'tu],'
      '0 as [Rodzaj sprz'#281'tu]'
      'FROM [Asortyment sprz'#281'tu remontowanego w 3 OWT] AR'
      'LEFT OUTER JOIN JIM ON JIM.[Nazwa sprz'#281'tu] = AR.[Nazwa sprz'#281'tu]')
    Left = 264
    Top = 80
  end
  object m_KodyUslugADO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM'
      '[Kody us'#322'ug]')
    Left = 40
    Top = 144
  end
  object m_PlanADO: TADOQuery
    AutoCalcFields = False
    Connection = m_Conn
    CursorType = ctStatic
    AfterOpen = m_PlanADOAfterOpen
    AfterClose = m_PlanADOAfterClose
    Parameters = <>
    SQL.Strings = (
      'SELECT r.*, 0 as ROK    FROM'
      '[pLAN REMONT'#211'W r] as r')
    Left = 152
    Top = 144
  end
  object m_MagazynADO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'ID_WYDZ'
        DataType = ftInteger
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = 0
      end>
    SQL.Strings = (
      
        'SELECT ew.*, mid(Warsztat,1,1) as Wydzia'#322', :ID_WYDZ as ID_WYDZIA' +
        'LU_DEF'
      'FROM [Ewidencja sprz'#281'tu i zada'#324' wykonywanych w 3 OWT] ew'
      'where mid(ew.[nr kuta],len(ew.[nr kuta])-7,1) in ('#39'S'#39','#39'D'#39',0)')
    Left = 360
    Top = 80
  end
  object m_ZleceniaADO: TADOQuery
    CacheSize = 1000
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'ID_WYDZ'
        Attributes = [paNullable]
        DataType = ftInteger
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = 0
      end>
    SQL.Strings = (
      'SELECT'
      ' ew.*,'
      ' '#39'W'#39'+ mid(ew.Warsztat,1,1) as Wydzia'#322', '
      'mid(ew.[nr kuta], len(ew.[nr kuta])-7,1) as Pozycja,'
      
        '(select min(ew1.Warsztat)  FROM [Ewidencja sprz'#281'tu i zada'#324' wykon' +
        'ywanych w 3 OWT] ew1 where ew1.[nr kuta] = (Mid(ew.[nr kuta],1,l' +
        'en(ew.[nr kuta])-8) + '#39'0/'#39'  + Mid(ew.[nr kuta], len(ew.[nr kuta]' +
        ')-5,6)))  as [Warsztat wiod'#261'cy],'
      
        '(select min(ew1.Warsztat)  FROM [Ewidencja sprz'#281'tu i zada'#324' wykon' +
        'ywanych w 3 OWT] ew1 where ew1.[nr kuta] = (Mid(ew.[nr kuta],1,l' +
        'en(ew.[nr kuta])-8) + '#39'S/'#39'  + Mid(ew.[nr kuta], len(ew.[nr kuta]' +
        ')-5,6)))  as [Serwis],'
      ':ID_WYDZ as ID_WYDZIALU_DEF'
      ''
      'FROM [Ewidencja sprz'#281'tu i zada'#324' wykonywanych w 3 OWT] ew')
    Left = 448
    Top = 80
  end
  object m_ZlecRbhADO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'ID_WYDZ'
        Size = -1
        Value = Null
      end>
    SQL.Strings = (
      'SELECT r.*, e.Warsztat,'
      ':ID_WYDZ as ID_WYDZIALU_DEF'
      ' FROM'
      
        '[Rozliczenie rbh] r left outer join [Ewidencja sprz'#281'tu i zada'#324' w' +
        'ykonywanych w 3 OWT] e'
      'on e.[Nr Kuta]=r.[Nr Kut]')
    Left = 552
    Top = 80
  end
  object m_RodzRemADO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      ' distinct ew.[Rodzaj remontu]'
      'FROM [Ewidencja sprz'#281'tu i zada'#324' wykonywanych w 3 OWT] ew')
    Left = 440
    Top = 16
  end
  object m_StopnieADO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT DISTINCT [STOPIE'#323'] FROM [Kadry plan urlop'#243'w]')
    Left = 248
    Top = 144
  end
  object m_StanowiskaADO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT DISTINCT [stanowisko] FROM [Kadry plan urlop'#243'w]')
    Left = 344
    Top = 144
  end
  object m_OsobyADO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      
        'SELECT [Kadry plan urlop'#243'w].[Symbol kom'#243'rki], [Kadry plan urlop'#243 +
        'w].stanowisko, [Kadry plan urlop'#243'w].stopie'#324', '
      
        '[Kadry plan urlop'#243'w].imi'#281', [Kadry plan urlop'#243'w].nazwisko, [kpr]+' +
        '[cpr] AS Etat,[kpr],[cpr],[knpr],[cnpr],[k/c]'
      'FROM [Kadry plan urlop'#243'w]'
      'WHERE ((([Kadry plan urlop'#243'w].stopie'#324')<>'#39'vacat'#39'))'
      'ORDER BY [Kadry plan urlop'#243'w].[Symbol kom'#243'rki]')
    Left = 432
    Top = 144
  end
end
