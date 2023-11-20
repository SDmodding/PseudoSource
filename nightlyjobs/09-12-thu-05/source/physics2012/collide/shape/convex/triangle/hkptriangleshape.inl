// File Line: 139
// RVA: 0xC30B80
__int64 __fastcall hkpTriangleShape::getNumCollisionSpheres(hkpTriangleShape *this)
{
  return 3 * ((unsigned int)(unsigned __int8)this->m_isExtruded + 1);
}

