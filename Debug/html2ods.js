  
  var scriptPathAndName = WScript.ScriptFullName; 
  var index = scriptPathAndName.lastIndexOf ('\\'); 
  var path = scriptPathAndName.substring (0, index) + "\\"; 
  var htmlPathAndName = WScript.Arguments (0); 
  var url = encodeURI ("file://localhost/" + htmlPathAndName.split ("\\").join ("/")); 
  try 
  { 
 	var serviceManager = WScript.CreateObject ("com.sun.star.ServiceManager");  
 	var desktop = serviceManager.createInstance ("com.sun.star.frame.Desktop");  
 	var dispatcher = serviceManager.createInstance ("com.sun.star.frame.DispatchHelper");  
 	var document = desktop.loadComponentFromURL ("private:factory/scalc", "_blank", 0, new Array ());  
 	var sheets = document.getSheets ();  
 	var sheet = sheets.getByIndex (0);  
 	sheet.link (url, "link", "", "", 1);  
 	sheet.setLinkMode (0);   
 	document.storeAsURL (url + ".ods", new Array ());   
 	desktop.terminate ();  
  } 
  catch(e) 
  { 
  } 
   
