object _RBH4OSDM: T_RBH4OSDM
  OldCreateOrder = False
  Height = 82
  Width = 515
  object m_Client: TClientDataSet
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'ID_KOMORKI'
        DataType = ftInteger
      end
      item
        Name = 'KOD_WARSZTATU'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'NAZWA'
        DataType = ftString
        Size = 120
      end
      item
        Name = 'ID_OSOBY'
        DataType = ftInteger
      end
      item
        Name = 'STOPIEN'
        DataType = ftString
        Size = 80
      end
      item
        Name = 'IMIE'
        DataType = ftString
        Size = 80
      end
      item
        Name = 'NAZWISKO'
        DataType = ftString
        Size = 120
      end
      item
        Name = 'ETAT_PR'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'RBH_NOM'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_URLOP'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_PRZERWA'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_CHOROBA'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_SLUZBA'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_SZKOLENIE'
        DataType = ftCurrency
      end
      item
        Name = 'STANOWISKO'
        DataType = ftString
        Size = 60
      end
      item
        Name = 'KIEROWNIK'
        DataType = ftInteger
      end
      item
        Name = 'RBH_NPROD'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_PROD'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_EFF'
        DataType = ftCurrency
      end>
    IndexDefs = <>
    IndexFieldNames = 'KIEROWNIK'
    Params = <>
    StoreDefs = True
    Left = 24
    Top = 8
    object m_ClientID_KOMORKI: TIntegerField
      FieldName = 'ID_KOMORKI'
    end
    object m_ClientKOD_WARSZTATU: TStringField
      FieldName = 'KOD_WARSZTATU'
      Size = 50
    end
    object m_ClientNAZWA: TStringField
      FieldName = 'NAZWA'
      Size = 120
    end
    object m_ClientID_OSOBY: TIntegerField
      FieldName = 'ID_OSOBY'
    end
    object m_ClientSTOPIEN: TStringField
      FieldName = 'STOPIEN'
      Size = 80
    end
    object m_ClientIMIE: TStringField
      FieldName = 'IMIE'
      Size = 80
    end
    object m_ClientNAZWISKO: TStringField
      FieldName = 'NAZWISKO'
      Size = 120
    end
    object m_ClientRBH_NOM: TCurrencyField
      FieldName = 'RBH_NOM'
    end
    object m_ClientRBH_URLOP: TCurrencyField
      FieldName = 'RBH_URLOP'
    end
    object m_ClientRBH_PRZERWA: TCurrencyField
      FieldName = 'RBH_PRZERWA'
    end
    object m_ClientRBH_CHOROBA: TCurrencyField
      FieldName = 'RBH_CHOROBA'
    end
    object m_ClientRBH_SLUZBA: TCurrencyField
      FieldName = 'RBH_SLUZBA'
    end
    object m_ClientRBH_SZKOLENIE: TCurrencyField
      FieldName = 'RBH_SZKOLENIE'
    end
    object m_ClientRBH_NPROD: TCurrencyField
      FieldName = 'RBH_NPROD'
    end
    object m_ClientRBH_PROD: TCurrencyField
      FieldName = 'RBH_PROD'
    end
    object m_ClientRBH_EFF: TCurrencyField
      FieldName = 'RBH_EFF'
    end
    object m_ClientSTANOWISKO: TStringField
      FieldName = 'STANOWISKO'
      Size = 60
    end
    object m_ClientKIEROWNIK: TIntegerField
      FieldName = 'KIEROWNIK'
    end
    object m_ClientETAT_PR: TStringField
      FieldName = 'ETAT_PR'
    end
  end
  object m_WorkADO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'DELETE *'
      'FROM [Rozliczenie godzin pracownik'#243'w]')
    Left = 216
    Top = 8
  end
  object m_RBH4OSADO: TADOTable
    Connection = m_Conn
    CursorType = ctStatic
    TableName = 'Rozliczenie godzin pracownik'#243'w'
    Left = 320
    Top = 8
  end
  object m_Conn: TADOConnection
    ConnectionString = 'FILE NAME=P:\PLANREM\EXE\MDB\sprawozdania.udl;'
    KeepConnection = False
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'P:\PLANREM\EXE\MDB\sprawozdania.udl'
    Left = 128
    Top = 8
  end
end
