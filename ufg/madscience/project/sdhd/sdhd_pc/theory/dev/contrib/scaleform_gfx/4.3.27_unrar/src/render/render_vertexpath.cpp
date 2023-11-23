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
  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *p_Vertices; // rbx
  unsigned __int64 v4; // rdi

  p_Vertices = &this->Vertices;
  v4 = this->Vertices.Size >> 4;
  if ( v4 >= this->Vertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(&this->Vertices, v4);
  p_Vertices->Pages[v4][p_Vertices->Size & 0xF] = (Scaleform::Render::VertexBasic)__PAIR64__(LODWORD(y), LODWORD(x));
  ++p_Vertices->Size;
}

// File Line: 34
// RVA: 0x961750
void __fastcall Scaleform::Render::VertexPath::ClosePath(Scaleform::Render::VertexPath *this)
{
  __int64 LastVertex; // rbx
  Scaleform::Render::VertexBasic **Pages; // r10
  unsigned __int64 Size; // rsi
  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *p_Vertices; // rdi
  unsigned __int64 v5; // rsi
  __int64 v6; // rbx
  Scaleform::Render::VertexBasic *v7; // r14

  LastVertex = this->LastVertex;
  if ( this->Vertices.Size - LastVertex > 2 )
  {
    Pages = this->Vertices.Pages;
    Size = this->Vertices.Size;
    p_Vertices = &this->Vertices;
    if ( Pages[(Size - 1) >> 4][((_BYTE)Size - 1) & 0xF].x != Pages[(unsigned __int64)(unsigned int)LastVertex >> 4][LastVertex & 0xF].x
      || Pages[(Size - 1) >> 4][((_BYTE)Size - 1) & 0xF].y != Pages[(unsigned __int64)(unsigned int)LastVertex >> 4][LastVertex & 0xF].y )
    {
      v5 = Size >> 4;
      v6 = LastVertex & 0xF;
      v7 = Pages[(unsigned __int64)this->LastVertex >> 4];
      if ( v5 >= this->Vertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(p_Vertices, v5);
      p_Vertices->Pages[v5][p_Vertices->Size & 0xF] = v7[v6];
      ++p_Vertices->Size;
    }
  }
}

// File Line: 44
// RVA: 0x979380
void __fastcall Scaleform::Render::VertexPath::FinalizePath(
        Scaleform::Render::VertexPath *this,
        unsigned int __formal,
        unsigned int a3,
        bool a4)
{
  unsigned __int64 LastVertex; // rcx
  unsigned __int64 v6; // rsi
  Scaleform::Render::PathBasic v7; // [rsp+30h] [rbp+8h]

  LastVertex = this->LastVertex;
  if ( this->Vertices.Size - LastVertex >= 3 )
  {
    v6 = this->Paths.Size >> 2;
    v7.Start = LastVertex;
    v7.Count = LODWORD(this->Vertices.Size) - LastVertex;
    if ( v6 >= this->Paths.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(&this->Paths, v6);
    this->Paths.Pages[v6][this->Paths.Size & 3] = v7;
    ++this->Paths.Size;
    this->LastVertex = this->Vertices.Size;
  }
  else if ( LastVertex < this->Vertices.Size )
  {
    this->Vertices.Size = LastVertex;
  }
}

