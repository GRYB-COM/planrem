object _PlanKwartZadDM: T_PlanKwartZadDM
  OldCreateOrder = False
  Height = 82
  Width = 515
  object m_Client: TClientDataSet
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'KOD_USLUGI'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'NAZ_USLUGI'
        DataType = ftString
        Size = 200
      end
      item
        Name = 'NR_HARM'
        DataType = ftInteger
      end
      item
        Name = 'NAZ_SPRZETU'
        DataType = ftString
        Size = 255
      end
      item
        Name = 'JIM'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'ILOSC'
        DataType = ftCurrency
      end
      item
        Name = 'KOD_REMONTU'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'JW_MIASTO'
        DataType = ftString
        Size = 140
      end
      item
        Name = 'NAZ_REMONTU'
        DataType = ftString
        Size = 80
      end
      item
        Name = 'RBH_NORMA'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_I'
        DataType = ftCurrency
      end
      item
        Name = 'ILOSC_I'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_II'
        DataType = ftCurrency
      end
      item
        Name = 'ILOSC_II'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_III'
        DataType = ftCurrency
      end
      item
        Name = 'ILOSC_III'
        DataType = ftCurrency
      end>
    IndexDefs = <>
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
      'FROM [Kwartalny plan zada'#324']')
    Left = 216
    Top = 8
  end
  object m_PlanKwartZadADO: TADOTable
    Connection = m_Conn
    CursorType = ctStatic
    TableName = 'Kwartalny plan zada'#324
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
