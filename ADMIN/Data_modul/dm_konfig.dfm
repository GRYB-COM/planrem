object DMEditConfig: TDMEditConfig
  OldCreateOrder = False
  Height = 408
  Width = 546
  object cdsConfiguration: TClientDataSet
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'TITLE'
        DataType = ftString
        Size = 80
      end
      item
        Name = 'OWNER'
        DataType = ftString
        Size = 100
      end
      item
        Name = 'VERSION'
        DataType = ftString
        Size = 20
      end>
    IndexDefs = <>
    Params = <>
    StoreDefs = True
    Left = 84
    Top = 8
  end
  object cdsGlbLinks: TClientDataSet
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'ID'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'NAME'
        DataType = ftString
        Size = 60
      end
      item
        Name = 'KIND'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'PROTOCOL'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'ALIAS'
        DataType = ftString
        Size = 100
      end
      item
        Name = 'USER'
        DataType = ftString
        Size = 40
      end
      item
        Name = 'PASSWORD'
        DataType = ftString
        Size = 40
      end
      item
        Name = 'CHARSET'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'DIALECT'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'VENDORLIB'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'OWNER'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'ISREFER'
        DataType = ftBoolean
      end>
    IndexDefs = <>
    Params = <>
    StoreDefs = True
    Left = 80
    Top = 104
  end
  object cdsApplications: TClientDataSet
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'SYSID'
        DataType = ftInteger
      end
      item
        Name = 'NAME'
        DataType = ftString
        Size = 80
      end
      item
        Name = 'KEY'
        DataType = ftString
        Size = 25
      end>
    IndexDefs = <>
    Params = <>
    StoreDefs = True
    Left = 64
    Top = 220
  end
  object cdsLinks: TClientDataSet
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'IDAPP'
        DataType = ftInteger
      end
      item
        Name = 'ID'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'NAME'
        DataType = ftString
        Size = 60
      end
      item
        Name = 'KIND'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'PROTOCOL'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'ALIAS'
        DataType = ftString
        Size = 100
      end
      item
        Name = 'USER'
        DataType = ftString
        Size = 40
      end
      item
        Name = 'PASSWORD'
        DataType = ftString
        Size = 40
      end
      item
        Name = 'CHARSET'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'DIALECT'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'VENDORLIB'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'OWNER'
        DataType = ftString
        Size = 50
      end
      item
        Name = 'ISREFER'
        DataType = ftBoolean
      end>
    IndexDefs = <>
    Params = <>
    StoreDefs = True
    Left = 128
    Top = 160
  end
  object cdsParamLink: TClientDataSet
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'IDAPP'
        DataType = ftInteger
      end
      item
        Name = 'IDLINK'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'KEY'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'VALUE'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'NAME'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'FORCE'
        DataType = ftBoolean
      end
      item
        Name = 'LIBTYPE'
        DataType = ftString
        Size = 20
      end>
    IndexDefs = <>
    Params = <>
    StoreDefs = True
    Left = 268
    Top = 160
  end
  object cdsParam: TClientDataSet
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'IDAPP'
        DataType = ftInteger
      end
      item
        Name = 'KEY'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'VALUE'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'NAME'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'FORCE'
        DataType = ftBoolean
      end
      item
        Name = 'LIBTYPE'
        DataType = ftString
        Size = 20
      end>
    IndexDefs = <>
    Params = <>
    StoreDefs = True
    Left = 256
    Top = 268
  end
  object cdsParamGlbLink: TClientDataSet
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'IDLINK'
        DataType = ftString
        Size = 20
      end
      item
        Name = 'KEY'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'VALUE'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'NAME'
        DataType = ftString
        Size = 30
      end
      item
        Name = 'FORCE'
        DataType = ftBoolean
      end
      item
        Name = 'LIBTYPE'
        DataType = ftString
        Size = 20
      end>
    IndexDefs = <>
    Params = <>
    StoreDefs = True
    Left = 224
    Top = 108
  end
  object dsLinks: TDataSource
    AutoEdit = False
    DataSet = cdsLinks
    OnDataChange = dsLinksDataChange
    Left = 196
    Top = 160
  end
  object dsLaczaGlb: TDataSource
    DataSet = cdsGlbLinks
    OnDataChange = dsLaczaGlbDataChange
    Left = 152
    Top = 96
  end
  object dsApplication: TDataSource
    DataSet = cdsApplications
    OnDataChange = dsApplicationDataChange
    Left = 144
    Top = 236
  end
end
