object _KwMozlWarSprzDM: T_KwMozlWarSprzDM
  OldCreateOrder = False
  Height = 82
  Width = 515
  object m_Client: TClientDataSet
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'ID_WYDZIALU'
        DataType = ftInteger
      end
      item
        Name = 'KOD_WYDZIALU'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'NAZ_WYDZIALU'
        DataType = ftString
        Size = 80
      end
      item
        Name = 'ID_KOMORKI'
        DataType = ftInteger
      end
      item
        Name = 'KOD_WARSZTATU'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'NAZ_WARSZTATU'
        DataType = ftString
        Size = 250
      end
      item
        Name = 'ID_REMONTU'
        DataType = ftInteger
      end
      item
        Name = 'NAZ_REMONTU'
        DataType = ftString
        Size = 80
      end
      item
        Name = 'ID_HARMONOGRAMU'
        DataType = ftInteger
      end
      item
        Name = 'NAZ_SPRZ'
        DataType = ftString
        Size = 200
      end
      item
        Name = 'ZADANIE'
        DataType = ftString
        Size = 255
      end
      item
        Name = 'INDEKS_MAT'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'KOD_REM'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'NORMA_RBH'
        DataType = ftCurrency
      end
      item
        Name = 'ILOSC'
        DataType = ftCurrency
      end
      item
        Name = 'ILOSC_KW_I'
        DataType = ftCurrency
      end
      item
        Name = 'ILOSC_KW_II'
        DataType = ftCurrency
      end
      item
        Name = 'ILOSC_KW_III'
        DataType = ftCurrency
      end
      item
        Name = 'ILOSC_KW_IV'
        DataType = ftCurrency
      end
      item
        Name = 'PLAN_RBH'
        DataType = ftCurrency
      end
      item
        Name = 'PLAN_RBH_KW_I'
        DataType = ftCurrency
      end
      item
        Name = 'PLAN_RBH_KW_II'
        DataType = ftCurrency
      end
      item
        Name = 'PLAN_RBH_KW_III'
        DataType = ftCurrency
      end
      item
        Name = 'PLAN_RBH_KW_IV'
        DataType = ftCurrency
      end
      item
        Name = 'NR_SPRZ'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'TYP_SPRZ'
        DataType = ftString
        Size = 600
      end>
    IndexDefs = <>
    IndexFieldNames = 'KOD_WYDZIALU;KOD_WARSZTATU;ID_REMONTU;ID_HARMONOGRAMU;TYP_SPRZ'
    Params = <>
    StoreDefs = True
    Left = 24
    Top = 8
  end
  object m_WorkADO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'DELETE *'
      'FROM [Roczny plan remont'#243'w]')
    Left = 216
    Top = 8
  end
  object m_KwMozlWarADO: TADOTable
    Connection = m_Conn
    CursorType = ctStatic
    TableName = 'Roczny plan remont'#243'w'
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
