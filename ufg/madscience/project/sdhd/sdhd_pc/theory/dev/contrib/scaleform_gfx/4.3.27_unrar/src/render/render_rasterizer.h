// File Line: 87
// RVA: 0x954DB0
// attributes: thunk
void __fastcall Scaleform::Render::Rasterizer::AddVertex(Scaleform::Render::Rasterizer *this, float x, float y)
{
  Scaleform::Render::Rasterizer::LineTo(this, x, y);
}

// File Line: 88
// RVA: 0x987E20
float __fastcall Scaleform::Render::Rasterizer::GetLastX(Scaleform::Render::Rasterizer *this)
{
  return this->LastXf;
}

// File Line: 89
// RVA: 0x987F70
float __fastcall Scaleform::Render::Rasterizer::GetLastY(Scaleform::Render::Rasterizer *this)
{
  return this->LastYf;
}

