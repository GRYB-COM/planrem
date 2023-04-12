object _PotrzRemDM: T_PotrzRemDM
  OldCreateOrder = False
  Height = 82
  Width = 515
  object m_Client: TClientDataSet
    Aggregates = <>
    FieldDefs = <
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
        Name = 'JW'
        DataType = ftString
        Size = 300
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
        Name = 'ILOSC'
        DataType = ftCurrency
      end
      item
        Name = 'NORMA_RBH'
        DataType = ftCurrency
      end
      item
        Name = 'ILOSC_RBH'
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
      'FROM [Potrzeby JW]')
    Left = 216
    Top = 8
  end
  object m_PotrzRemADO: TADOTable
    Connection = m_Conn
    CursorType = ctStatic
    TableName = 'Potrzeby JW'
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
