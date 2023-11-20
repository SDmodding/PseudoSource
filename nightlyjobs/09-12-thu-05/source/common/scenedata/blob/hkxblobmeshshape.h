// File Line: 52
// RVA: 0xE31B80
const char *__fastcall hkxBlobMeshShape::getName(hkxBlobMeshShape *this)
{
  return (const char *)((_QWORD)this->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 55
// RVA: 0xE31B90
void __fastcall hkxBlobMeshShape::setName(hkxBlobMeshShape *this, const char *n)
{
  hkStringPtr::operator=(&this->m_name, n);
}

// File Line: 58
// RVA: 0xE31B70
hkClass *__fastcall hkxBlobMeshShape::getClassType(hkxBlobMeshShape *this)
{
  return &hkxBlobMeshShapeClass;
}

