//---------------------------------------------------------------------------

#ifndef KUTEditorH
#define KUTEditorH
namespace msg { class MagID; }
namespace editors{
 class KUTEditor{
  public:
			//INTERFEJS
			  static void create(const msg::MagID& _MagID);
			  static void updateDost(const msg::MagID& _MagID);

 };
 }//end namespace editors
//---------------------------------------------------------------------------
#endif
