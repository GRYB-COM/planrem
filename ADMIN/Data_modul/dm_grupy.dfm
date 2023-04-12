object DMGrupyUpr: TDMGrupyUpr
  OldCreateOrder = False
  Left = 312
  Top = 188
  Height = 340
  Width = 680
  object dspGrupyUpr: TDataSetProvider
    Constraints = True
    UpdateMode = upWhereKeyOnly
    OnUpdateError = dspGrupyUprUpdateError
    BeforeUpdateRecord = dspGrupyUprBeforeUpdateRecord
    OnGetTableName = dspGrupyUprGetTableName
    Left = 24
    Top = 32
  end
  object cdsGrupy: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'dspGrupyUpr'
    AfterOpen = cdsGrupyAfterOpen
    Left = 88
    Top = 24
  end
  object cdsGrupyFun: TClientDataSet
    Aggregates = <>
    Params = <>
    Left = 144
    Top = 52
  end
end
