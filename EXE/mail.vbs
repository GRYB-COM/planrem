        Dim oApp
        Set oApp = GetObject(, "Outlook.Application")
        If Err.Number <> 0 Then Set oApp = CreateObject("Outlook.Application")
        Err.Clear
        Set oEmail = oApp.CreateItem(olMailItem)
        With oEmail
            .To = "adamos360@wp.pl"
            .Subject = "Nowy RejRem"
            .Body = "Czeœæ" + vbNewLine +  vbNewLine + "Pozdrowienia" + vbNewLine +  "S³awek "
            .Attachments.Add "T:\RejRem.r__", olByValue	
            .Display 'Show the email message and allow for editing before sending
        End With