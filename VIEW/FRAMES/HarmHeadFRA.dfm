object _HarmHeadFRA: T_HarmHeadFRA
  Left = 0
  Top = 0
  Width = 556
  Height = 21
  TabOrder = 0
  DesignSize = (
    556
    21)
  object m_Combo: TDBLookupComboBox
    Left = 0
    Top = 0
    Width = 81
    Height = 21
    KeyField = 'ID'
    ListField = 'MIES_ROK;OPIS'
    ListSource = m_DataSource
    TabOrder = 0
  end
  object m_Edit: TDBEdit
    Left = 89
    Top = 0
    Width = 467
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    Color = clInfoBk
    Ctl3D = False
    DataField = 'OPIS'
    DataSource = m_DataSource
    ParentCtl3D = False
    ReadOnly = True
    TabOrder = 1
    ExplicitWidth = 464
  end
  object m_Client: TClientDataSet
    Active = True
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'ID'
        DataType = ftInteger
      end
      item
        Name = 'MIESIAC'
        DataType = ftInteger
      end
      item
        Name = 'ROK'
        DataType = ftInteger
      end
      item
        Name = 'MIES_ROK'
        DataType = ftString
        Size = 10
      end
      item
        Name = 'OPIS'
        DataType = ftString
        Size = 50
      end>
    IndexDefs = <>
    Params = <>
    StoreDefs = True
    Left = 528
    Data = {
      770000009619E0BD010000001800000005000000000003000000770002494404
      00010000000000074D494553494143040001000000000003524F4B0400010000
      000000084D4945535F524F4B0100490000000100055749445448020002000A00
      044F50495301004900000001000557494454480200020032000000}
  end
  object m_DataSource: TDataSource
    DataSet = m_Client
    Left = 499
  end
end
