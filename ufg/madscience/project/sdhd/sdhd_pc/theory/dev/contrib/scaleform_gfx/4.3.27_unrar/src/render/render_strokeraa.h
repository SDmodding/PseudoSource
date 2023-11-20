// File Line: 86
// RVA: 0x987EA0
float __fastcall Scaleform::Render::StrokerAA::GetLastX(Scaleform::Render::StrokerAA *this)
{
  return this->Path.Path.Pages[(this->Path.Path.Size - 1) >> 4][(LODWORD(this->Path.Path.Size) - 1) & 0xF].x;
}

// File Line: 87
// RVA: 0x987FF0
float __fastcall Scaleform::Render::StrokerAA::GetLastY(Scaleform::Render::StrokerAA *this)
{
  return this->Path.Path.Pages[(this->Path.Path.Size - 1) >> 4][(LODWORD(this->Path.Path.Size) - 1) & 0xF].y;
}

// File Line: 98
// RVA: 0x989590
_BOOL8 __fastcall Scaleform::Render::StrokerAA::GetMeshCount(Scaleform::Render::StrokerAA *this)
{
  return this->Triangles.Size != 0;
}

// File Line: 100
// RVA: 0x989610
__int64 __fastcall Scaleform::Render::StrokerAA::GetMeshTriangleCount(Scaleform::Render::StrokerAA *this, unsigned int __formal)
{
  return LODWORD(this->Triangles.Size);
}

// File Line: 210
// RVA: 0x9CB440
__int64 __fastcall Scaleform::Render::StrokerAA::addVertex(Scaleform::Render::StrokerAA *this, float x, float y, unsigned int style, unsigned int alpha)
{
  unsigned __int64 v5; // rdi
  Scaleform::Render::StrokerAA *v6; // rsi
  signed __int64 v7; // rdx
  Scaleform::Render::StrokerAA::VertexType *v8; // rax
  int v10; // [rsp+28h] [rbp-30h]

  v5 = this->Vertices.Size >> 4;
  v6 = this;
  LOWORD(v10) = style;
  HIWORD(v10) = alpha;
  if ( v5 >= this->Vertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(&this->Vertices, v5);
  v7 = v6->Vertices.Size & 0xF;
  v8 = v6->Vertices.Pages[v5];
  v8[v7].x = x;
  v8[v7].y = y;
  *(_DWORD *)&v8[v7].style = v10;
  ++v6->Vertices.Size;
  return (unsigned int)(LODWORD(v6->Vertices.Size) - 1);
}

// File Line: 216
// RVA: 0x9CAEC0
void __fastcall Scaleform::Render::StrokerAA::addTriangle(Scaleform::Render::StrokerAA *this, unsigned int v1, unsigned int v2, unsigned int v3)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::TriangleType,4,16> *v4; // rbx
  unsigned int v5; // er14
  unsigned int v6; // ebp
  unsigned int v7; // esi
  unsigned __int64 v8; // rdi
  signed __int64 v9; // rcx
  Scaleform::Render::StrokerAA::TriangleType *v10; // rax

  v4 = &this->Triangles;
  v5 = v3;
  v6 = v2;
  v7 = v1;
  v8 = this->Triangles.Size >> 4;
  if ( v8 >= this->Triangles.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeVertex,4,16>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::VertexType,4,16> *)&this->Triangles,
      this->Triangles.Size >> 4);
  v9 = v4->Size & 0xF;
  v10 = v4->Pages[v8];
  v10[v9].v1 = v7;
  v10[v9].v2 = v6;
  v10[v9].v3 = v5;
  ++v4->Size;
}

// File Line: 313
// RVA: 0x954F80
void __fastcall Scaleform::Render::StrokerAA::AddVertex(Scaleform::Render::StrokerAA *this, float x, float y)
{
  Scaleform::Render::StrokeVertex v; // [rsp+20h] [rbp-18h]

  v.x = x;
  v.y = y;
  v.dist = 0.0;
  Scaleform::Render::StrokePath::AddVertex(&this->Path, &v);
}

