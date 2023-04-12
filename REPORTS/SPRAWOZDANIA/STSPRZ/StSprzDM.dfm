object _StSprzDM: T_StSprzDM
  OldCreateOrder = False
  Height = 82
  Width = 515
  object m_Client: TClientDataSet
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'LP'
        DataType = ftInteger
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
        Name = 'TYP_SPRZ'
        DataType = ftString
        Size = 200
      end
      item
        Name = 'SPRZ_PLAN'
        DataType = ftCurrency
      end
      item
        Name = 'SPRZ_PRZYJ'
        DataType = ftCurrency
      end
      item
        Name = 'RODZ_NAPR'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'SPRZ_REM_KW_I'
        DataType = ftCurrency
      end
      item
        Name = 'SPRZ_REM_KW_II'
        DataType = ftCurrency
      end
      item
        Name = 'SPRZ_REM_KW_III'
        DataType = ftCurrency
      end
      item
        Name = 'SPRZ_REM_KW_IV'
        DataType = ftCurrency
      end
      item
        Name = 'SPRZ_REM'
        DataType = ftCurrency
      end
      item
        Name = 'SPRZ_WREM_PLAN'
        DataType = ftCurrency
      end
      item
        Name = 'SPRZ_WREM_PLAN_PROC'
        DataType = ftCurrency
      end
      item
        Name = 'SPRZ_WREM_ZAL'
        DataType = ftCurrency
      end
      item
        Name = 'SPRZ_WREM_ZAL_PROC'
        DataType = ftCurrency
      end
      item
        Name = 'REMONT'
        DataType = ftString
        Size = 20
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
      'FROM [Stan sprz'#281'tu]')
    Left = 216
    Top = 8
  end
  object m_StSprzADO: TADOTable
    Connection = m_Conn
    CursorType = ctStatic
    TableName = 'Stan sprz'#281'tu'
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
