// File Line: 170
// RVA: 0x94EAA0
bool __fastcall Scaleform::Render::VertexFormat::operator==(Scaleform::Render::VertexFormat *this, Scaleform::Render::VertexFormat *o)
{
  Scaleform::Render::VertexElement *v2; // rax
  Scaleform::Render::VertexElement *i; // r8
  unsigned int v4; // edx
  unsigned int v5; // er9

  v2 = this->pElements;
  for ( i = o->pElements; ; ++i )
  {
    if ( !(((v2->Attribute & 0xF0) - 112) & 0xFFFFFFEF) )
      ++v2;
    if ( !(((i->Attribute & 0xF0) - 112) & 0xFFFFFFEF) )
      ++i;
    v4 = v2->Attribute;
    if ( !v4 )
      break;
    v5 = i->Attribute;
    if ( !v5 )
      break;
    if ( v2->Offset != i->Offset || v4 != v5 )
      return 0;
    ++v2;
  }
  return v2->Offset == i->Offset && v4 == i->Attribute;
}

