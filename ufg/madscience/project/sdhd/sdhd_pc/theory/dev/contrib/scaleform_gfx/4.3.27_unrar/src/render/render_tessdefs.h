// File Line: 84
// RVA: 0x94D0D0
void __fastcall Scaleform::Render::TessBase::~TessBase(Scaleform::Render::TessBase *this)
{
  this->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable';
}

// File Line: 116
// RVA: 0x987F00
float __fastcall Scaleform::Render::VertexPath::GetLastX(Scaleform::Render::VertexPath *this)
{
  return this->Vertices.Pages[(this->Vertices.Size - 1) >> 4][(LODWORD(this->Vertices.Size) - 1) & 0xF].x;
}

// File Line: 117
// RVA: 0x988050
float __fastcall Scaleform::Render::VertexPath::GetLastY(Scaleform::Render::VertexPath *this)
{
  return this->Vertices.Pages[(this->Vertices.Size - 1) >> 4][(LODWORD(this->Vertices.Size) - 1) & 0xF].y;
}

// File Line: 159
// RVA: 0x8A8710
void __fastcall Scaleform::Render::TransformerBase::~TransformerBase(Scaleform::Render::TransformerBase *this)
{
  this->vfptr = (Scaleform::Render::TransformerBaseVtbl *)&Scaleform::Render::TransformerBase::`vftable';
}

