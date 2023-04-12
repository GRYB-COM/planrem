object _KwMozlWarDM: T_KwMozlWarDM
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
        Name = 'RBH_NOM_I'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_NOM_II'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_NOM_III'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_NOM_IV'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_NOM_R'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_NPROD_I'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_NPROD_II'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_NPROD_III'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_NPROD_IV'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_NPROD_R'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_PROD_I'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_PROD_II'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_PROD_III'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_PROD_IV'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_PROD_R'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_PRODW_I'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_PRODW_II'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_PRODW_III'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_PRODW_IV'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_PRODW_R'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_EF_I'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_EF_II'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_EF_III'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_EF_IV'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_EF_R'
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
      'FROM [Kwartalny bilans mo'#380'liwo'#347'ci warsztat'#243'w]')
    Left = 216
    Top = 8
  end
  object m_KwMozlWarADO: TADOTable
    Connection = m_Conn
    CursorType = ctStatic
    TableName = 'Kwartalny bilans mo'#380'liwo'#347'ci warsztat'#243'w'
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
