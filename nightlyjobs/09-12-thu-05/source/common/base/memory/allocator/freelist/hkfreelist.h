// File Line: 176
// RVA: 0xC706B0
hkBool *__fastcall hkFreeList::_compareElements(hkBool *result, hkFreeList::Element *a, hkFreeList::Element *b)
{
  result->m_bool = a < b;
  return result;
}

