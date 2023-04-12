object _RBH4OneMiesDM: T_RBH4OneMiesDM
  OldCreateOrder = False
  Height = 82
  Width = 515
  object m_WorkADO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'DELETE FROM [RBH w  jednym miesi'#261'cu]')
    Left = 216
    Top = 8
  end
  object m_RBH4OneMiesADO: TADOTable
    Connection = m_Conn
    CursorType = ctStatic
    TableName = 'RBH w  jednym miesi'#261'cu'
    Left = 320
    Top = 8
  end
  object m_Conn: TADOConnection
    KeepConnection = False
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 128
    Top = 8
  end
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
        Size = 20
      end
      item
        Name = 'NAZ_WYDZIALU'
        DataType = ftString
        Size = 100
      end
      item
        Name = 'ID_WARSZTATU'
        DataType = ftInteger
      end
      item
        Name = 'KOD_WARSZTATU'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'NAZ_WARSZTATU'
        DataType = ftString
        Size = 120
      end
      item
        Name = 'ETAT_PR'
        DataType = ftCurrency
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
        Name = 'RBH_NPROD'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_PROD'
        DataType = ftCurrency
      end>
    IndexDefs = <>
    Params = <>
    StoreDefs = True
    Left = 32
    Top = 8
    object m_ClientID_KOMORKI: TIntegerField
      FieldName = 'ID_WARSZTATU'
    end
    object m_ClientKOD_WARSZTATU: TStringField
      FieldName = 'KOD_WARSZTATU'
      Size = 50
    end
    object m_ClientNAZWA: TStringField
      FieldName = 'NAZ_WARSZTATU'
      Size = 120
    end
    object m_ClientETAT_PR: TCurrencyField
      FieldName = 'ETAT_PR'
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
    object m_ClientID_WYDZIALU: TIntegerField
      FieldName = 'ID_WYDZIALU'
    end
    object m_ClientKOD_WYDZIALU: TStringField
      FieldName = 'KOD_WYDZIALU'
    end
    object m_ClientNAZ_WYDZIALU: TStringField
      FieldName = 'NAZ_WYDZIALU'
      Size = 100
    end
  end
end
