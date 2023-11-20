// File Line: 217
// RVA: 0xDC7870
hkpShapeContainer *__fastcall hkpStaticCompoundShape::getContainer(hkpStaticCompoundShape *this)
{
  hkpShapeContainer *result; // rax

  if ( this )
    result = (hkpShapeContainer *)&this->vfptr;
  else
    result = 0i64;
  return result;
}

