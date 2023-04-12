object DMOperator: TDMOperator
  OldCreateOrder = False
  Height = 199
  Width = 360
  object dspOperat: TDataSetProvider
    Options = [poAutoRefresh, poPropogateChanges]
    UpdateMode = upWhereKeyOnly
    OnUpdateError = dspOperatUpdateError
    BeforeUpdateRecord = dspOperatBeforeUpdateRecord
    OnGetTableName = dspOperatGetTableName
    Left = 36
    Top = 24
  end
  object cdsOperat: TClientDataSet
    Tag = -100
    Aggregates = <>
    AggregatesActive = True
    IndexFieldNames = 'NAZWA'
    Params = <>
    ProviderName = 'dspOperat'
    AfterOpen = cdsOperatAfterOpen
    AfterInsert = cdsOperatAfterInsert
    Left = 104
    Top = 24
  end
  object cdsUpraw: TClientDataSet
    Aggregates = <>
    Params = <>
    Left = 180
    Top = 24
  end
  object cdsGrupy: TClientDataSet
    Aggregates = <>
    Params = <>
    Left = 252
    Top = 24
  end
end
