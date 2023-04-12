//---------------------------------------------------------------------------
#pragma hdrstop
#include "EksportCfg.h"
#pragma package(smart_init)
#include "..\_INCLUDE\XML\xml_serializer.h"
#include "..\_INCLUDE\XML\xml_header.h"
#include "..\_INCLUDE\XML\xml_sequence.h"

//---------------------------------------------------------------------------
using namespace msg;
//---------------------------------------------------------------------------
AnsiString EksportCfg::getPath(void) const
{
 return m_Path;
}
//---------------------------------------------------------------------------
void EksportCfg::setPath(const AnsiString & _Path)
{
 m_Path = _Path;
}
//---------------------------------------------------------------------------
AnsiString EksportCfg::getFileName(void)const
{
 return m_FileName;
}
//---------------------------------------------------------------------------
void EksportCfg::setFileName(const AnsiString & _FileName)
{
 m_FileName = _FileName;
}
//---------------------------------------------------------------------------
AnsiString EksportCfg::getXML(void)const
{
 xmlLib::XMLSequence _Seq("Export");
 _Seq.AddElement(xmlLib::XMLSerializer::buildElement(AnsiString("Path"),m_Path));
 _Seq.AddElement(xmlLib::XMLSerializer::buildElement(AnsiString("FileName"),m_FileName));
  AnsiString _XMLStr;
  xmlLib::XMLElement::CarriageReturnCharMan cr(xmlLib::XMLElement::crcNone);
 _XMLStr  = xmlLib::XMLHeader("win-1250").GetHeader();
 _XMLStr += _Seq.ToXML();

 return _XMLStr;
}
//---------------------------------------------------------------------------
namespace xml{
 class EksportCfgXML: public xmlLib::XMLSerializer{
 public:
 virtual xmlLib::XMLElement* toXML() const{return NULL;};
 virtual EksportCfgXML*      clone(void) const{return new EksportCfgXML(Owner);};
 virtual void                loadXML(xmlLib::XMLElement* xml);
 EksportCfgXML(EksportCfg& _Owner) :xmlLib::XMLSerializer("Export"),Owner(_Owner) {}
 EksportCfg& Owner;
 };
}
//---------------------------------------------------------------------------
void EksportCfg::setXML(const AnsiString & _XML)
{
 xml::EksportCfgXML _Srlz(*this);
 _Srlz.loadFromString(_XML,true);
}
//---------------------------------------------------------------------------
void xml::EksportCfgXML::loadXML(xmlLib::XMLElement* xml)
{
 checkName(xml);
  xmlLib::XMLSequence* seq=convertToSequence(xml);
  Owner.setPath(contentToString(seq,"Path",""));
  Owner.setFileName(contentToString(seq,"FileName",""));

}
//---------------------------------------------------------------------------
bool EksportCfg::isDefined(void)
{
 return ! m_Path.IsEmpty();
}
//---------------------------------------------------------------------------

