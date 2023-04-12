//---------------------------------------------------------------------------
 #pragma hdrstop
 #include "KodyUslugDICT.h"
 #include "MANAGER\stream_db.h"
 //---------------------------------------------------------------------------
 #pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace dict;
//---------------------------------------------------------------------------
KodyUslugDICT::KodyUslugDICT(void)
{
 m_Stream = new mng::StreamDB();
 m_Stream->setQuery("select * from pr_kody_uslug order by pozycja");
}
//---------------------------------------------------------------------------
KodyUslugDICT::~KodyUslugDICT(void)
{
 m_Stream->close();
delete m_Stream;
}
//---------------------------------------------------------------------------
KodyUslugDICT& KodyUslugDICT::instance(void)
{
 static KodyUslugDICT m_Dict;
 m_Dict.open();
 return m_Dict;
}
//---------------------------------------------------------------------------
void KodyUslugDICT::open(void)
{
 if(!m_Stream->isOpen())
 {
  m_Stream->open();
 }
}
//---------------------------------------------------------------------------
void KodyUslugDICT::close(void)
{
  m_Stream->close();
}
//---------------------------------------------------------------------------
String KodyUslugDICT::getNazwa(const int _Id, const bool _IdP)const
{
 String _Res;
 AnsiString _FN( _IdP ? "ID_USLUGI" : "POZYCJA");
 if(m_Stream->locate(_FN,_Id) )
 {
  _Res = m_Stream->fieldByName("P_N")->AsString;
 }
 return _Res;
}
//---------------------------------------------------------------------------
TField* KodyUslugDICT::fieldByName(const int _Id, const AnsiString& _FieldName, const bool _IdP)
{

  AnsiString _FN( _IdP ? "ID_USLUGI" : "POZYCJA");
if(!m_Stream->locate(_FN,_Id)) throw Exception(String("Brak identyfikatora sprzêtu: ") + String(_Id) );
 return m_Stream->fieldByName(_FieldName);
}
//---------------------------------------------------------------------------
void    KodyUslugDICT::first(void)
{
 m_Stream->first();
}
//---------------------------------------------------------------------------
void    KodyUslugDICT::next(void)
{
 m_Stream->next();
}

//---------------------------------------------------------------------------
bool    KodyUslugDICT::isEof(void)
{
 return m_Stream->isEof();
}
;
//---------------------------------------------------------------------------
String  KodyUslugDICT::getKod(void)
{
 return m_Stream->fieldByName("P_N")->AsString;
}

//---------------------------------------------------------------------------
String KodyUslugDICT::getName(void)
{
 return m_Stream->fieldByName("NAZ_REMONTU")->AsString;
}

//---------------------------------------------------------------------------
int KodyUslugDICT::getID(void)
{
 return m_Stream->fieldByName("ID_USLUGI")->AsInteger;
}
//---------------------------------------------------------------------------
TDataSet* KodyUslugDICT::getDataSet(void)
{
 return m_Stream->getClient();
}
//---------------------------------------------------------------------------
int KodyUslugDICT::getID2(void)
{
 return m_Stream->fieldByName("POZYCJA")->AsInteger;
}

