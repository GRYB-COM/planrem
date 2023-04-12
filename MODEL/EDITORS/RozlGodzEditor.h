//---------------------------------------------------------------------------

#ifndef RozlGodzEditorH
#define RozlGodzEditorH
namespace editors{
 class RozlGodzEditor{
	public:
		 //KLASY WEWNÊTRZNE
		   class Pars{
		   public:
			int IdKomorki;
            int Rok;
			Pars(void);
		   };
		 //INTERFEJS
		   static RozlGodzEditor& instance(void);
		   void   run(const Pars& _Pars);
		 //DESTRUKTOR
		   ~RozlGodzEditor(void);
	private:
		//KONSTRUKTOR
		  RozlGodzEditor(void);
		//ZABRONIONE
		  RozlGodzEditor(RozlGodzEditor&);
		  RozlGodzEditor& operator=(RozlGodzEditor&);

 };
}
//---------------------------------------------------------------------------
#endif
