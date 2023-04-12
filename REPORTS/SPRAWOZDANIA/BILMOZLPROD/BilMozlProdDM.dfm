object _BilMozlProdDM: T_BilMozlProdDM
  OldCreateOrder = False
  Height = 82
  Width = 834
  object m_Client: TClientDataSet
    Aggregates = <>
    AggregatesActive = True
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
        Name = 'L_CYWIL'
        DataType = ftCurrency
      end
      item
        Name = 'L_KADRA'
        DataType = ftCurrency
      end
      item
        Name = 'L_PROD_CYWIL'
        DataType = ftCurrency
      end
      item
        Name = 'L_PROD_KADRA'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_NOM_CYWIL'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_NOM_KADRA'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_PROD_CYWIL'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_PROD_KADRA'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_NPROD_CYWIL'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_NPROD_KADRA'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_EF_CYWIL'
        DataType = ftCurrency
      end
      item
        Name = 'RBH_EF_KADRA'
        DataType = ftCurrency
      end>
    IndexDefs = <>
    Params = <>
    StoreDefs = True
    OnCalcFields = m_ClientCalcFields
    Left = 16
    Top = 16
    object m_ClientID_WYDZIALU: TIntegerField
      FieldName = 'ID_WYDZIALU'
    end
    object m_ClientKOD_WYDZIALU: TStringField
      FieldName = 'KOD_WYDZIALU'
      Size = 10
    end
    object m_ClientNAZ_WYDZIALU: TStringField
      FieldName = 'NAZ_WYDZIALU'
      Size = 80
    end
    object m_ClientID_WARSZTATU: TIntegerField
      FieldName = 'ID_WARSZTATU'
    end
    object m_ClientKOD_WARSZTATU: TStringField
      FieldName = 'KOD_WARSZTATU'
    end
    object m_ClientNAZ_WARSZTATU: TStringField
      FieldName = 'NAZ_WARSZTATU'
      Size = 250
    end
    object m_ClientL_PROD_CYWIL: TCurrencyField
      FieldName = 'L_PROD_CYWIL'
    end
    object m_ClientL_PROD_KADRA: TCurrencyField
      FieldName = 'L_PROD_KADRA'
    end
    object m_ClientRBH_NOM_CYWIL: TCurrencyField
      FieldName = 'RBH_NOM_CYWIL'
    end
    object m_ClientRBH_NOM_KADRA: TCurrencyField
      FieldName = 'RBH_NOM_KADRA'
    end
    object m_ClientRBH_PROD_CYWIL: TCurrencyField
      FieldName = 'RBH_PROD_CYWIL'
    end
    object m_ClientRBH_PROD_KADRA: TCurrencyField
      FieldName = 'RBH_PROD_KADRA'
    end
    object m_ClientRBH_NPROD_CYWIL: TCurrencyField
      FieldName = 'RBH_NPROD_CYWIL'
    end
    object m_ClientRBH_NPROD_KADRA: TCurrencyField
      FieldName = 'RBH_NPROD_KADRA'
    end
    object m_ClientRBH_EF_CYWIL: TCurrencyField
      FieldName = 'RBH_EF_CYWIL'
    end
    object m_ClientRBH_EF_KADRA: TCurrencyField
      FieldName = 'RBH_EF_KADRA'
    end
    object m_ClientRBH_NOM_RAZEM: TCurrencyField
      FieldKind = fkCalculated
      FieldName = 'RBH_NOM_RAZEM'
      Calculated = True
    end
    object m_ClientRBH_NPROD_RAZEM: TCurrencyField
      FieldKind = fkCalculated
      FieldName = 'RBH_NPROD_RAZEM'
      Calculated = True
    end
    object m_ClientRBH_PROD_RAZEM: TCurrencyField
      FieldKind = fkCalculated
      FieldName = 'RBH_PROD_RAZEM'
      Calculated = True
    end
    object m_ClientL_CYWIL: TCurrencyField
      FieldName = 'L_CYWIL'
    end
    object m_ClientL_KADRA: TCurrencyField
      FieldName = 'L_KADRA'
    end
    object m_ClientL_CYWIL_SUM: TAggregateField
      DefaultExpression = 'SUM(L_CYWIL)'
      FieldName = 'L_CYWIL_SUM'
      Active = True
      Expression = 'SUM(L_CYWIL)'
    end
    object m_ClientL_KADRA_SUM: TAggregateField
      DefaultExpression = 'SUM(L_KADRA)'
      FieldName = 'L_KADRA_SUM'
      Active = True
      Expression = 'SUM(L_KADRA)'
    end
    object m_ClientRBH_NPROD_KADRA_SUM: TAggregateField
      DefaultExpression = 'SUM(RBH_NPROD_KADRA)'
      FieldName = 'RBH_NPROD_KADRA_SUM'
      Active = True
      Expression = 'SUM(RBH_NPROD_KADRA)'
    end
    object m_ClientRBH_NPROD_CYWIL_SUM: TAggregateField
      DefaultExpression = 'SUM(RBH_NPROD_CYWIL)'
      FieldName = 'RBH_NPROD_CYWIL_SUM'
      Active = True
      Expression = 'SUM(RBH_NPROD_CYWIL)'
    end
  end
  object m_WorkADO: TADOQuery
    Connection = m_Conn
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'DELETE *'
      'FROM [Bilans mo'#380'liwo'#347'ci produkcyjnych]')
    Left = 216
    Top = 8
  end
  object m_MozlRemADO: TADOTable
    Connection = m_Conn
    CursorType = ctStatic
    TableName = 'Bilans mo'#380'liwo'#347'ci produkcyjnych'
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
  object m_MozlRemParADO: TADOTable
    Connection = m_Conn
    CursorType = ctStatic
    TableName = 'Bilans mo'#380'liwo'#347'ci produkcyjnych - parametry'
    Left = 424
    Top = 8
  end
end
