// File Line: 127
// RVA: 0x987DF0
float __fastcall Scaleform::Render::Hairliner::GetLastX(Scaleform::Render::Hairliner *this)
{
  return this->SrcVertices.Pages[(this->SrcVertices.Size - 1) >> 4][(LODWORD(this->SrcVertices.Size) - 1) & 0xF].x;
}

// File Line: 128
// RVA: 0x987F40
float __fastcall Scaleform::Render::Hairliner::GetLastY(Scaleform::Render::Hairliner *this)
{
  return this->SrcVertices.Pages[(this->SrcVertices.Size - 1) >> 4][(LODWORD(this->SrcVertices.Size) - 1) & 0xF].y;
}

// File Line: 141
// RVA: 0x989580
_BOOL8 __fastcall Scaleform::Render::Hairliner::GetMeshCount(Scaleform::Render::Hairliner *this)
{
  return this->Triangles.Size != 0;
}

// File Line: 142
// RVA: 0x98ED70
__int64 __fastcall Scaleform::Render::Hairliner::GetMeshVertexCount(UFG::GroupComponent *this)
{
  return this->mGroupLeader.mFollowers.size;
}

// File Line: 241
// RVA: 0x954D50
void __fastcall Scaleform::Render::Hairliner::AddVertex(Scaleform::Render::Hairliner *this, float x, float y)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::SrcVertexType,4,16> *p_SrcVertices; // rbx
  unsigned __int64 v4; // rdi

  p_SrcVertices = &this->SrcVertices;
  v4 = this->SrcVertices.Size >> 4;
  if ( v4 >= this->SrcVertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->SrcVertices,
      v4);
  p_SrcVertices->Pages[v4][p_SrcVertices->Size & 0xF] = (Scaleform::Render::Hairliner::SrcVertexType)__PAIR64__(LODWORD(y), LODWORD(x));
  ++p_SrcVertices->Size;
}

