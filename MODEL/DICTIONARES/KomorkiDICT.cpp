//---------------------------------------------------------------------------
 #pragma hdrstop
 #include "KomorkiDICT.h"
 #include "MANAGER\stream_db.h"
 //---------------------------------------------------------------------------
 #pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace dict;
//---------------------------------------------------------------------------
KomorkiDICT::KomorkiDICT(void)
{
 m_Stream = new mng::StreamDB();
 m_Stream->setQuery("select k.*, w.KOD as KOD_WYDZ, w.NAZWA as NAZ_WYDZ FROM PR_KOMORKI K INNER JOIN PR_WYDZIALY W ON W.ID_WYDZIALU = K.ID_WYDZIALU ");
}
//---------------------------------------------------------------------------
KomorkiDICT::~KomorkiDICT(void)
{
 m_Stream->close();
 delete m_Stream;
}
//---------------------------------------------------------------------------
KomorkiDICT& KomorkiDICT::instance(void)
{
 static KomorkiDICT m_Dict;
 m_Dict.open();
 return m_Dict;
}
//---------------------------------------------------------------------------
void KomorkiDICT::open(void)
{
 if(!m_Stream->isOpen())
 {
  m_Stream->open();
 }
}
//---------------------------------------------------------------------------
void KomorkiDICT::close(void)
{
  m_Stream->close();
}
//---------------------------------------------------------------------------
String KomorkiDICT::getKodWydzialu(const int _Id, const bool _IdWydz)const
{
 String _Res;
 AnsiString _Field(_IdWydz ? "ID_WYDZIALU" : "ID_KOMORKI");
 if(m_Stream->locate(_Field,_Id) )
 {
  _Res = m_Stream->fieldByName("KOD_WYDZ")->AsString;
 }
 return _Res;
}
//---------------------------------------------------------------------------
int KomorkiDICT::getIdWydzialu(const int _IdKomorki)const
{
 int _Res(-1);
 if(m_Stream->locate("ID_KOMORKI",_IdKomorki) )
 {
  _Res = m_Stream->fieldByName("ID_WYDZIALU")->AsInteger;
 }
 return _Res;
}
//---------------------------------------------------------------------------
TField* KomorkiDICT::fieldByName(const int _IdKomorki, const AnsiString& _FieldName)
{
 if(!m_Stream->locate("ID_KOMORKI",_IdKomorki)) throw Exception(String("Brak identyfikatora komorki: ") + String(_IdKomorki) );
 return m_Stream->fieldByName(_FieldName);
}
//---------------------------------------------------------------------------
int KomorkiDICT::getIdKomorki(const String& _Kod)const
{
 int _Res(-1);
 if(!_Kod.IsEmpty() &&  m_Stream->locate("KOD",_Kod) )
 {
  _Res = m_Stream->fieldByName("ID_KOMORKI")->AsInteger;
 }
 return _Res;
}
//---------------------------------------------------------------------------
void    KomorkiDICT::first(void)
{
 m_Stream->first();
}
//---------------------------------------------------------------------------
void    KomorkiDICT::next(void)
{
 m_Stream->next();
}

//---------------------------------------------------------------------------
bool    KomorkiDICT::isEof(void)
{
 return m_Stream->isEof();
}
;
//---------------------------------------------------------------------------
String  KomorkiDICT::getKod(void)
{
 return m_Stream->fieldByName("KOD")->AsString;
}
//---------------------------------------------------------------------------
String  KomorkiDICT::getKod(const int _IdKomorki)
{
 String _Res;
 if(!m_Stream->locate("ID_KOMORKI",_IdKomorki)) throw Exception(String("Brak identyfikatora komorki: ") + String(_IdKomorki) );
 else
 {
  _Res = m_Stream->fieldByName("KOD")->AsString;
 }
 return _Res;
}

//---------------------------------------------------------------------------
String  KomorkiDICT::getMasterKod(void)
{
 return m_Stream->fieldByName("KOD_WYDZ")->AsString;
}

//---------------------------------------------------------------------------
String KomorkiDICT::getName(void)
{
 return m_Stream->fieldByName("NAZWA")->AsString;
}
//---------------------------------------------------------------------------
String  KomorkiDICT::getName(const int _IdKomorki)
{
 String _Res;
 if(!m_Stream->locate("ID_KOMORKI",_IdKomorki)) throw Exception(String("Brak identyfikatora komorki: ") + String(_IdKomorki) );
 else
 {
  _Res = m_Stream->fieldByName("NAZWA")->AsString;
 }
 return _Res;
}
//---------------------------------------------------------------------------
int KomorkiDICT::getID(void)
{
 return m_Stream->fieldByName("ID_KOMORKI")->AsInteger;
}
//---------------------------------------------------------------------------
int KomorkiDICT::getMasterID(void)
{
 return m_Stream->fieldByName("ID_WYDZIALU")->AsInteger;
}


