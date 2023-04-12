//---------------------------------------------------------------------------

#pragma hdrstop

#include "rv_lines.h"
#include <isvaria\tokens.h>
#include <isvaria\varia.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)



/**********
*  Funkcje sk³adowe klasy: Lines
**********/


Lines::Lines() : m_lines()
{
}
//------------------------------------------------------------------------------

Lines::Lines(const AnsiString& str,int max_len,char filler) : m_lines()
{
   split(str,max_len,filler);
}
//------------------------------------------------------------------------------

Lines::ConstIterator Lines::begin() const
{
   return m_lines.begin();
}
//------------------------------------------------------------------------------

Lines::Iterator Lines::begin()
{
   return m_lines.begin();
}
//------------------------------------------------------------------------------

Lines::ConstIterator Lines::end() const
{
   return m_lines.end();
}
//------------------------------------------------------------------------------

Lines::Iterator Lines::end()
{
   return m_lines.end();
}
//------------------------------------------------------------------------------

bool Lines::empty() const
{
   return m_lines.empty();
}
//------------------------------------------------------------------------------

int Lines::size() const
{
   return m_lines.size();
}
//------------------------------------------------------------------------------

void Lines::append(const AnsiString& str,bool at_front)
{
   if(at_front)
   {
      m_lines.insert(m_lines.begin(),str);
   }
   else
   {
      m_lines.push_back(str);
   }
}
//------------------------------------------------------------------------------

void Lines::attach(const Lines& lines)
{
   m_lines.insert(m_lines.end(),lines.begin(),lines.end());
}
//------------------------------------------------------------------------------

void Lines::clear()
{
   m_lines.clear();
}
//------------------------------------------------------------------------------

void Lines::split(const AnsiString& str,int max_len,char filler)
{
   m_lines.clear();

   if(max_len <= 0)
   {
      return;
   }

   // rozbicie nazwy na wyrazy; jako separator u¿ywana jest spacja
   Tokens tk(str.Trim(),' ');

   AnsiString ln;

   do
   {
      AnsiString tmp(tk.Token().Trim());

      // puste ³añcuchy s¹ pomijane
      if(!tmp.IsEmpty())
      {

         if(ln.Length() + tmp.Length() < max_len)
         {
            ln += tmp + filler;
         }
         else
         {
            m_lines.push_back(PadRight(ln,max_len,filler));

            if(tmp.Length() < max_len)
            {
               ln = tmp + filler;
            }
            else
            {
               int ibeg=1, irest=tmp.Length();

               while(irest > max_len)
               {
                  m_lines.push_back( tmp.SubString(ibeg,max_len) );

                  irest -= max_len;
                  ibeg  += max_len;
               }

               ln = tmp.SubString(ibeg,tmp.Length()-ibeg) + filler;
            }
         }
      }

   } while(tk.Next());


   if(!ln.IsEmpty())
   {
      m_lines.push_back(PadRight(ln,max_len,filler));
   }
}
//------------------------------------------------------------------------------

AnsiString Lines::asText(const AnsiString& carriage,bool trim) const
{
   AnsiString text;

   ConstIterator it(m_lines.begin());

   if(it != m_lines.end())
   {
      AnsiString line(trim ? it->Trim() : *it);

      text += line;

      for(++it;it != m_lines.end();++it)
      {
         AnsiString line(trim ? it->Trim() : *it);

         text += carriage + line;
      }
   }

   return text;
}
//------------------------------------------------------------------------------

AnsiString Lines::operator[](int index) const
{
   return m_lines[index];
}
//------------------------------------------------------------------------------

AnsiString& Lines::operator[](int index)
{
   return m_lines[index];
}
//------------------------------------------------------------------------------

