// File Line: 71
// RVA: 0xE68780
void __fastcall hkXmlParser::StartElement::StartElement(hkXmlParser::StartElement *this, const char *n)
{
  hkStringPtr *p_name; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->type = CYLINDER;
  p_name = &this->name;
  p_name[-3].m_stringAndFlag = (const char *)&hkXmlParser::StartElement::`vftable;
  hkStringPtr::hkStringPtr(p_name, n);
  this->attributes.m_data = 0i64;
  this->attributes.m_size = 0;
  this->attributes.m_capacityAndFlags = 0x80000000;
}

// File Line: 83
// RVA: 0xE68740
void __fastcall hkXmlParser::EndElement::EndElement(hkXmlParser::EndElement *this, const char *n)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->type = TRIANGLE;
  this->vfptr = (hkBaseObjectVtbl *)&hkXmlParser::EndElement::`vftable;
  hkStringPtr::hkStringPtr(&this->name, n);
}

// File Line: 92
// RVA: 0xE68700
void __fastcall hkXmlParser::Characters::Characters(hkXmlParser::Characters *this, const char *s, int len)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->type = BOX;
  this->vfptr = (hkBaseObjectVtbl *)&hkXmlParser::Characters::`vftable;
  hkStringPtr::hkStringPtr(&this->text, s, len);
}

