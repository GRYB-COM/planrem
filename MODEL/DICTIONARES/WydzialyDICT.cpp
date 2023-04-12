//---------------------------------------------------------------------------
 #pragma hdrstop
 #include "WydzialyDICT.h"
 #include "MANAGER\stream_db.h"
 //---------------------------------------------------------------------------
 #pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace dict;
//---------------------------------------------------------------------------
WydzialyDICT::WydzialyDICT(void)
{
 m_Stream = new mng::StreamDB();
 m_Stream->setQuery("select * FROM  PR_WYDZIALY");
}
//---------------------------------------------------------------------------
WydzialyDICT::~WydzialyDICT(void)
{
 m_Stream->close();
 delete m_Stream;
}
//---------------------------------------------------------------------------
WydzialyDICT& WydzialyDICT::instance(void)
{
 static WydzialyDICT m_Dict;
 m_Dict.open();
 return m_Dict;
}
//---------------------------------------------------------------------------
void WydzialyDICT::open(void)
{
  if(!m_Stream->isOpen())
  {
	m_Stream->open();
  }
}
//---------------------------------------------------------------------------
void WydzialyDICT::close(void)
{
  m_Stream->close();
}
//---------------------------------------------------------------------------
TField* WydzialyDICT::fieldByName(const int _IdWydzialu, const AnsiString& _FieldName)
{
 if(!m_Stream->locate("ID_WYDZIALU",_IdWydzialu)) throw Exception(String("Brak identyfikatora wydzia³u: ") + String(_IdWydzialu) );
 return m_Stream->fieldByName(_FieldName);
}
//---------------------------------------------------------------------------
String WydzialyDICT::getKod(const int _IdWydzialu)
{
 if(!m_Stream->locate("ID_WYDZIALU",_IdWydzialu)) throw Exception(String("Brak identyfikatora wydzia³u: ") + String(_IdWydzialu) );
 return m_Stream->fieldByName("KOD")->AsString;
}
//---------------------------------------------------------------------------
String WydzialyDICT::getName(const int _IdWydzialu)
{
 if(!m_Stream->locate("ID_WYDZIALU",_IdWydzialu)) throw Exception(String("Brak identyfikatora wydzia³u: ") + String(_IdWydzialu) );
 return m_Stream->fieldByName("NAZWA")->AsString;
}
//---------------------------------------------------------------------------
bool WydzialyDICT::isWydzialOk(const String& _Kod) const
{
 bool _Res(false);

 _Res =m_Stream->locate("KOD",_Kod);
 return _Res;
}
//---------------------------------------------------------------------------
void    WydzialyDICT::first(void)
{
 m_Stream->first();
}
//---------------------------------------------------------------------------
void    WydzialyDICT::next(void)
{
 m_Stream->next();
}

//---------------------------------------------------------------------------
bool    WydzialyDICT::isEof(void)
{
 return m_Stream->isEof();
}
;
//---------------------------------------------------------------------------
String  WydzialyDICT::getKod(void)
{
 return m_Stream->fieldByName("KOD")->AsString;
}

//---------------------------------------------------------------------------
String WydzialyDICT::getName(void)
{
 return m_Stream->fieldByName("NAZWA")->AsString;
}

//---------------------------------------------------------------------------
int WydzialyDICT::getID(void)
{
 return m_Stream->fieldByName("ID_WYDZIALU")->AsInteger;
}


