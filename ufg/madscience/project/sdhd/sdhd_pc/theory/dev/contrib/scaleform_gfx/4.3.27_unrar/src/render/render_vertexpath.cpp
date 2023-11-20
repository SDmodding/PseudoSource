// File Line: 21
// RVA: 0x9600D0
void __fastcall Scaleform::Render::VertexPath::Clear(Scaleform::Render::VertexPath *this)
{
  this->Vertices.MaxPages = 0i64;
  this->Vertices.NumPages = 0i64;
  this->Vertices.Size = 0i64;
  this->Vertices.Pages = 0i64;
  this->Paths.MaxPages = 0i64;
  this->Paths.NumPages = 0i64;
  this->Paths.Size = 0i64;
  this->Paths.Pages = 0i64;
  this->LastVertex = 0;
}

// File Line: 28
// RVA: 0x955010
void __fastcall Scaleform::Render::VertexPath::AddVertex(Scaleform::Render::VertexPath *this, float x, float y)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *v3; // rbx
  unsigned __int64 v4; // rdi

  v3 = &this->Vertices;
  v4 = this->Vertices.Size >> 4;
  if ( v4 >= this->Vertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(&this->Vertices, v4);
  v3->Pages[v4][v3->Size & 0xF] = (Scaleform::Render::VertexBasic)__PAIR__(LODWORD(y), LODWORD(x));
  ++v3->Size;
}

// File Line: 34
// RVA: 0x961750
void __fastcall Scaleform::Render::VertexPath::ClosePath(Scaleform::Render::VertexPath *this)
{
  __int64 v1; // rbx
  Scaleform::Render::VertexBasic **v2; // r10
  unsigned __int64 v3; // rsi
  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *v4; // rdi
  Scaleform::Render::VertexBasic **v5; // r14
  unsigned __int64 v6; // rsi
  __int64 v7; // rbx
  Scaleform::Render::VertexBasic *v8; // r14

  v1 = this->LastVertex;
  if ( this->Vertices.Size - v1 > 2 )
  {
    v2 = this->Vertices.Pages;
    v3 = this->Vertices.Size;
    v4 = &this->Vertices;
    v5 = this->Vertices.Pages;
    if ( v2[(v3 - 1) >> 4][((_BYTE)v3 - 1) & 0xF].x != v5[(unsigned __int64)(unsigned int)v1 >> 4][v1 & 0xF].x
      || v2[(v3 - 1) >> 4][((_BYTE)v3 - 1) & 0xF].y != v5[(unsigned __int64)(unsigned int)v1 >> 4][v1 & 0xF].y )
    {
      v6 = v3 >> 4;
      v7 = v1 & 0xF;
      v8 = v5[(unsigned __int64)this->LastVertex >> 4];
      if ( v6 >= this->Vertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(v4, v6);
      v4->Pages[v6][v4->Size & 0xF] = v8[v7];
      ++v4->Size;
    }
  }
}

// File Line: 44
// RVA: 0x979380
void __fastcall Scaleform::Render::VertexPath::FinalizePath(Scaleform::Render::VertexPath *this, unsigned int __formal, unsigned int a3, bool a4)
{
  Scaleform::Render::VertexPath *v4; // rbx
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // rsi
  Scaleform::Render::PathBasic v7; // [rsp+30h] [rbp+8h]

  v4 = this;
  v5 = this->LastVertex;
  if ( v4->Vertices.Size - v5 >= 3 )
  {
    v6 = v4->Paths.Size >> 2;
    v7.Start = v5;
    v7.Count = LODWORD(v4->Vertices.Size) - v5;
    if ( v6 >= v4->Paths.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(&v4->Paths, v6);
    v4->Paths.Pages[v6][v4->Paths.Size & 3] = v7;
    ++v4->Paths.Size;
    v4->LastVertex = v4->Vertices.Size;
  }
  else if ( v5 < v4->Vertices.Size )
  {
    v4->Vertices.Size = v5;
  }
}

