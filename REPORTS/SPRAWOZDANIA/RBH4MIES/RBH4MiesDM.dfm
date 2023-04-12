object _RBH4MiesDM: T_RBH4MiesDM
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
        Name = 'ID_WARSZTATU'
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
        Name = 'STY'
        DataType = ftCurrency
      end
      item
        Name = 'LUT'
        DataType = ftCurrency
      end
      item
        Name = 'MAR'
        DataType = ftCurrency
      end
      item
        Name = 'KWI'
        DataType = ftCurrency
      end
      item
        Name = 'MAJ'
        DataType = ftCurrency
      end
      item
        Name = 'CZE'
        DataType = ftCurrency
      end
      item
        Name = 'LIP'
        DataType = ftCurrency
      end
      item
        Name = 'SIE'
        DataType = ftCurrency
      end
      item
        Name = 'WRZE'
        DataType = ftCurrency
      end
      item
        Name = 'PAZ'
        DataType = ftCurrency
      end
      item
        Name = 'LIS'
        DataType = ftCurrency
      end
      item
        Name = 'GRU'
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
      'FROM [RBH w miesi'#261'cach]')
    Left = 216
    Top = 8
  end
  object m_RBH4MiesADO: TADOTable
    Connection = m_Conn
    CursorType = ctStatic
    TableName = 'RBH w miesi'#261'cach'
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
