//---------------------------------------------------------------------------
 #pragma hdrstop
 #include "RemontyDICT.h"
 #include "MANAGER\stream_db.h"
 //---------------------------------------------------------------------------
 #pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace dict;
//---------------------------------------------------------------------------
RemontyDICT::RemontyDICT(void)
{
 m_Stream = new mng::StreamDB();
 m_Stream->setQuery("select * from pr_remonty");
}
//---------------------------------------------------------------------------
RemontyDICT::~RemontyDICT(void)
{
 m_Stream->close();
delete m_Stream;
}
//---------------------------------------------------------------------------
RemontyDICT& RemontyDICT::instance(void)
{
 static RemontyDICT m_Dict;
 m_Dict.open();
 return m_Dict;
}
//---------------------------------------------------------------------------
void RemontyDICT::open(void)
{
 if(!m_Stream->isOpen())
 {
  m_Stream->open();
 }
}
//---------------------------------------------------------------------------
void RemontyDICT::close(void)
{
  m_Stream->close();
}
//---------------------------------------------------------------------------
String RemontyDICT::getNazwa(const int _Id)const
{
 String _Res;
 if(m_Stream->locate("ID_REMONTU",_Id) )
 {
  _Res = m_Stream->fieldByName("NAZWA")->AsString;
 }
 return _Res;
}
//---------------------------------------------------------------------------
String RemontyDICT::getKod(const int _Id)const
{
 String _Res;
 if(m_Stream->locate("ID_REMONTU",_Id) )
 {
  _Res = m_Stream->fieldByName("KOD_REM")->AsString;
 }
 return _Res;
}
//---------------------------------------------------------------------------
String RemontyDICT::getNazwa(const String& _Kod)const
{
 String _Res;
 if(m_Stream->locate("KOD_REM",_Kod) )
 {
  _Res = m_Stream->fieldByName("NAZWA")->AsString;
 }
 return _Res;
}
//---------------------------------------------------------------------------
TField* RemontyDICT::fieldByName(const int _Id, const AnsiString& _FieldName, const bool _IdP)
{
  AnsiString _FN( "ID_REMONTU");
if(!m_Stream->locate(_FN,_Id)) throw Exception(String("Brak identyfikatora sprzêtu: ") + String(_Id) );
 return m_Stream->fieldByName(_FieldName);
}
//---------------------------------------------------------------------------
