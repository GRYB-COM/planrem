object DataModule1: TDataModule1
  OldCreateOrder = False
  Height = 150
  Width = 215
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      ' Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\BAZA\__TEST\BBB' +
      '.xls;Extended Properties="Excel 8.0;HDR=Yes;IMEX=1";'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 32
    Top = 16
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorLocation = clUseServer
    EnableBCD = False
    TableDirect = True
    TableName = 'Ewidencja$'
    Left = 136
    Top = 24
  end
  object ADOQuery1: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorLocation = clUseServer
    CursorType = ctStatic
    LockType = ltReadOnly
    EnableBCD = False
    Parameters = <>
    Prepared = True
    SQL.Strings = (
      'SELECT * FROM [Ewidencja$]')
    Left = 88
    Top = 80
  end
end
