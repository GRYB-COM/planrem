//---------------------------------------------------------------------------
 #pragma hdrstop
 #include "SprzetDICT.h"
 #include "MANAGER\stream_db.h"
 //---------------------------------------------------------------------------
 #pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace dict;
//---------------------------------------------------------------------------
SprzetDICT::SprzetDICT(void)
{
 m_Stream = new mng::StreamDB();
 m_Stream->setQuery("select * from pr_sprzet");
}
//---------------------------------------------------------------------------
SprzetDICT::~SprzetDICT(void)
{
 m_Stream->close();
 delete m_Stream;
}
//---------------------------------------------------------------------------
SprzetDICT& SprzetDICT::instance(void)
{
 static SprzetDICT m_Dict;
 m_Dict.open();
 return m_Dict;
}
//---------------------------------------------------------------------------
void SprzetDICT::open(void)
{
 if(!m_Stream->isOpen())
 {
  m_Stream->open();
 }
}
//---------------------------------------------------------------------------
void SprzetDICT::close(void)
{
  m_Stream->close();
}
//---------------------------------------------------------------------------
String SprzetDICT::getNazwa(const int _Id)const
{
 String _Res;
 if(m_Stream->locate("ID_SPRZETU",_Id) )
 {
  _Res = m_Stream->fieldByName("NAZWA")->AsString;
 }
 return _Res;
}
//---------------------------------------------------------------------------
String SprzetDICT::getJIM(const int _Id)const
{
 String _Res;
 if(m_Stream->locate("ID_SPRZETU",_Id) )
 {
  _Res = m_Stream->fieldByName("INDEKS_MAT")->AsString;
 }
 return _Res;
}
//---------------------------------------------------------------------------
TField* SprzetDICT::fieldByName(const int _Id, const AnsiString& _FieldName)
{
 if(!m_Stream->locate("ID_SPRZETU",_Id)) throw Exception(String("Brak identyfikatora sprzêtu: ") + String(_Id) );
 return m_Stream->fieldByName(_FieldName);
}
//---------------------------------------------------------------------------
