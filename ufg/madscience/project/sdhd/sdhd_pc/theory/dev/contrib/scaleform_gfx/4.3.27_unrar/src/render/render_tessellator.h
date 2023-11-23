// File Line: 260
// RVA: 0x987ED0
float __fastcall Scaleform::Render::Tessellator::GetLastX(Scaleform::Render::Tessellator *this)
{
  return this->SrcVertices.Pages[(this->SrcVertices.Size - 1) >> 4][(LODWORD(this->SrcVertices.Size) - 1) & 0xF].x;
}

// File Line: 261
// RVA: 0x988020
float __fastcall Scaleform::Render::Tessellator::GetLastY(Scaleform::Render::Tessellator *this)
{
  return this->SrcVertices.Pages[(this->SrcVertices.Size - 1) >> 4][(LODWORD(this->SrcVertices.Size) - 1) & 0xF].y;
}

// File Line: 276
// RVA: 0x9895A0
__int64 __fastcall Scaleform::Render::Tessellator::GetMeshCount(Scaleform::Render::Tessellator *this)
{
  return LODWORD(this->Meshes.Size);
}

// File Line: 277
// RVA: 0x9896D0
__int64 __fastcall Scaleform::Render::Tessellator::GetMeshVertexCount(
        Scaleform::Render::Tessellator *this,
        unsigned int meshIdx)
{
  return this->Meshes.Pages[(unsigned __int64)meshIdx >> 4][meshIdx & 0xF].VertexCount;
}

// File Line: 278
// RVA: 0x989620
__int64 __fastcall Scaleform::Render::Tessellator::GetMeshTriangleCount(
        Scaleform::Render::Tessellator *this,
        unsigned int meshIdx)
{
  return LODWORD(this->MeshTriangles.Arrays[meshIdx].Size);
}

// File Line: 285
// RVA: 0x98ED80
__int64 __fastcall Scaleform::Render::Tessellator::GetVertexCount(Scaleform::Render::Tessellator *this)
{
  return LODWORD(this->MeshVertices.Size);
}

// File Line: 534
// RVA: 0x954FB0
void __fastcall Scaleform::Render::Tessellator::AddVertex(Scaleform::Render::Tessellator *this, float x, float y)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::SrcVertexType,4,16> *p_SrcVertices; // rbx
  unsigned __int64 v4; // rdi

  p_SrcVertices = &this->SrcVertices;
  v4 = this->SrcVertices.Size >> 4;
  if ( v4 >= this->SrcVertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->SrcVertices,
      v4);
  p_SrcVertices->Pages[v4][p_SrcVertices->Size & 0xF] = (Scaleform::Render::Tessellator::SrcVertexType)__PAIR64__(LODWORD(y), LODWORD(x));
  ++p_SrcVertices->Size;
}

