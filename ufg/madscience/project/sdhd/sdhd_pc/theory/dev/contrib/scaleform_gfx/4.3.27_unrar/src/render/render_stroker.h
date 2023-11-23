// File Line: 174
// RVA: 0x987E70
float __fastcall Scaleform::Render::Stroker::GetLastX(Scaleform::Render::Stroker *this)
{
  return this->Path.Path.Pages[(this->Path.Path.Size - 1) >> 4][(LODWORD(this->Path.Path.Size) - 1) & 0xF].x;
}

// File Line: 175
// RVA: 0x987FC0
float __fastcall Scaleform::Render::Stroker::GetLastY(Scaleform::Render::Stroker *this)
{
  return this->Path.Path.Pages[(this->Path.Path.Size - 1) >> 4][(LODWORD(this->Path.Path.Size) - 1) & 0xF].y;
}

// File Line: 247
// RVA: 0x954F50
void __fastcall Scaleform::Render::Stroker::AddVertex(Scaleform::Render::Stroker *this, float x, float y)
{
  Scaleform::Render::StrokeVertex v; // [rsp+20h] [rbp-18h] BYREF

  v.x = x;
  v.y = y;
  v.dist = 0.0;
  Scaleform::Render::StrokePath::AddVertex(&this->Path, &v);
}

// File Line: 264
// RVA: 0x987E30
float __fastcall Scaleform::Render::StrokeScaler::GetLastX(Scaleform::Render::StrokeScaler *this)
{
  return this->LastX;
}

// File Line: 265
// RVA: 0x987F80
float __fastcall Scaleform::Render::StrokeScaler::GetLastY(Scaleform::Render::StrokeScaler *this)
{
  return this->LastY;
}

// File Line: 267
// RVA: 0x954E80
void __fastcall Scaleform::Render::StrokeScaler::AddVertex(Scaleform::Render::StrokeScaler *this, float x, float y)
{
  this->LastX = x;
  this->LastY = y;
  ((void (__fastcall *)(Scaleform::Render::Stroker *))this->Str->vfptr->AddVertex)(this->Str);
}

// File Line: 346
// RVA: 0x987E40
float __fastcall Scaleform::Render::StrokeSorter::GetLastX(Scaleform::Render::StrokeSorter *this)
{
  return this->SrcVertices.Pages[(this->SrcVertices.Size - 1) >> 4][(LODWORD(this->SrcVertices.Size) - 1) & 0xF].x;
}

// File Line: 347
// RVA: 0x987F90
float __fastcall Scaleform::Render::StrokeSorter::GetLastY(Scaleform::Render::StrokeSorter *this)
{
  return this->SrcVertices.Pages[(this->SrcVertices.Size - 1) >> 4][(LODWORD(this->SrcVertices.Size) - 1) & 0xF].y;
}

// File Line: 398
// RVA: 0x9D62E0
bool __fastcall Scaleform::Render::StrokeSorter::cmpPaths(
        Scaleform::Render::StrokeSorter::SortedPathType *a,
        Scaleform::Render::StrokeSorter::SortedPathType *b)
{
  if ( a->x == b->x )
    return a->y < b->y;
  else
    return b->x > a->x;
}

