// File Line: 61
// RVA: 0x954D40
void __fastcall Scaleform::Render::GlyphFitter::AddVertex(Scaleform::Render::GlyphFitter *this, float x, float y)
{
  Scaleform::Render::GlyphFitter::LineTo(this, x, y);
}

// File Line: 63
// RVA: 0x987F30
float __fastcall Scaleform::Render::GlyphFitter::GetLastY(Scaleform::Render::GlyphFitter *this)
{
  return this->LastYf;
}

// File Line: 70
// RVA: 0x9B8530
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::Render::GlyphFitter::StretchTo(Scaleform::Render::VertexPath *this, Scaleform::Render::Matrix2x4<float> *result, float __formal, float a4)
{
  *(_QWORD *)&result->M[0][0] = 1065353216i64;
  *(_QWORD *)&result->M[1][1] = 1065353216i64;
  *(_QWORD *)&result->M[0][2] = 0i64;
  result->M[1][0] = 0.0;
  result->M[1][3] = 0.0;
  return result;
}

