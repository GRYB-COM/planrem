object _MozlRemDM: T_MozlRemDM
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
        Name = 'L_PROD'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_NOM'
        DataType = ftCurrency
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
        Name = 'RBH_EF'
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
      'FROM [Mo'#380'liwo'#347'ci remontowe]')
    Left = 216
    Top = 8
  end
  object m_MozlRemADO: TADOTable
    Connection = m_Conn
    CursorType = ctStatic
    TableName = 'Mo'#380'liwo'#347'ci remontowe'
    Left = 320
    Top = 8
  end
  object m_Conn: TADOConnection
    ConnectionString = 'FILE NAME=P:\PLANREM\EXE\MDB\sprawozdania.udl;'
    KeepConnection = False
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 128
    Top = 8
  end
  object m_MozlRemParsADO: TADOTable
    Connection = m_Conn
    CursorType = ctStatic
    TableName = 'Mo'#380'liwo'#347'ci remontowe - parametry'
    Left = 424
    Top = 8
  end
end
