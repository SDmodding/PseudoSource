// File Line: 71
// RVA: 0xE68780
void __fastcall hkXmlParser::StartElement::StartElement(hkXmlParser::StartElement *this, const char *n)
{
  hkXmlParser::StartElement *v2; // rbx
  hkStringPtr *v3; // rcx

  v2 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->type = 1;
  v3 = &this->name;
  v3[-3].m_stringAndFlag = (const char *)&hkXmlParser::StartElement::`vftable;
  hkStringPtr::hkStringPtr(v3, n);
  v2->attributes.m_data = 0i64;
  v2->attributes.m_size = 0;
  v2->attributes.m_capacityAndFlags = 2147483648;
}

// File Line: 83
// RVA: 0xE68740
void __fastcall hkXmlParser::EndElement::EndElement(hkXmlParser::EndElement *this, const char *n)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->type = 2;
  this->vfptr = (hkBaseObjectVtbl *)&hkXmlParser::EndElement::`vftable;
  hkStringPtr::hkStringPtr(&this->name, n);
}

// File Line: 92
// RVA: 0xE68700
void __fastcall hkXmlParser::Characters::Characters(hkXmlParser::Characters *this, const char *s, int len)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->type = 3;
  this->vfptr = (hkBaseObjectVtbl *)&hkXmlParser::Characters::`vftable;
  hkStringPtr::hkStringPtr(&this->text, s, len);
}

