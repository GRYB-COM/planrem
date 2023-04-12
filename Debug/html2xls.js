var xlWorkbookNormal = -4143;  
  var scriptPathAndName = WScript.ScriptFullName; 
  var index = scriptPathAndName.lastIndexOf ('\\'); 
  var path = scriptPathAndName.substring (0, index) + "\\"; 
  var htmlPathAndName = WScript.Arguments (0); 
  var excel = null; 
  try 
  { 
 	excel = WScript.CreateObject ("Excel.Application"); 
 	excel.DisplayAlerts = false; 
  	var workbooks = excel.Workbooks; 
 	var workbook = workbooks.Open (htmlPathAndName, null, true); 
 	workbook.SaveAs (htmlPathAndName + ".xls", xlWorkbookNormal); 
 	workbook.Close (); 
  } 
  catch(e) 
  { 
  } 
  if (excel != null) 
  { 
 	excel.Quit(); 
  } 
   
