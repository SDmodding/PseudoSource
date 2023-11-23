// File Line: 170
// RVA: 0x94EAA0
bool __fastcall Scaleform::Render::VertexFormat::operator==(
        Scaleform::Render::VertexFormat *this,
        Scaleform::Render::VertexFormat *o)
{
  Scaleform::Render::VertexElement *pElements; // rax
  Scaleform::Render::VertexElement *i; // r8
  unsigned int Attribute; // edx
  unsigned int v5; // r9d

  pElements = this->pElements;
  for ( i = o->pElements; ; ++i )
  {
    if ( (((pElements->Attribute & 0xF0) - 112) & 0xFFFFFFEF) == 0 )
      ++pElements;
    if ( (((i->Attribute & 0xF0) - 112) & 0xFFFFFFEF) == 0 )
      ++i;
    Attribute = pElements->Attribute;
    if ( !Attribute )
      break;
    v5 = i->Attribute;
    if ( !v5 )
      break;
    if ( pElements->Offset != i->Offset || Attribute != v5 )
      return 0;
    ++pElements;
  }
  return pElements->Offset == i->Offset && Attribute == i->Attribute;
}

