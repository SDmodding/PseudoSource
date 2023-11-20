// File Line: 87
// RVA: 0x93CE30
void __fastcall Scaleform::Render::GlyphTextureMapper::GlyphTextureMapper(Scaleform::Render::GlyphTextureMapper *this)
{
  Scaleform::Render::GlyphTextureMapper *v1; // rdx
  Scaleform::Render::ImagePlane *v2; // rcx
  Scaleform::Render::ImageData *v3; // [rsp+28h] [rbp+10h]

  v1 = this;
  this->Valid = 0;
  this->Method = 0;
  this->pTexMan = 0i64;
  this->pCache = 0i64;
  this->TextureId = 0;
  v3 = &this->Data;
  *(_QWORD *)&v3->Format = 0i64;
  *(_DWORD *)&v3->Flags = 0x10000;
  v2 = &this->Data.Plane0;
  v3->pPlanes = v2;
  v3->pPalette.pObject = 0i64;
  *(_QWORD *)&v2->Width = 0i64;
  v2->Pitch = 0i64;
  v2->DataSize = 0i64;
  v2->pData = 0i64;
  v1->pRawImg.pObject = 0i64;
  v1->pTexImg.pObject = 0i64;
  v1->pFill.pObject = 0i64;
  v1->Mapped = 0;
  v1->NumGlyphsToUpdate = 0;
}

// File Line: 131
// RVA: 0x93CB50
void __fastcall Scaleform::Render::GlyphScanlineFilter::GlyphScanlineFilter(Scaleform::Render::GlyphScanlineFilter *this, float prim, float second, float tert)
{
  signed int v4; // er8
  char *v5; // rdx
  float v6; // xmm4_4
  float v7; // xmm6_4
  float v8; // xmm8_4
  float v9; // xmm7_4
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  signed int v12; // ecx
  __m128 v13; // xmm3
  signed int v14; // ecx
  signed int v15; // ecx

  v4 = 0;
  v5 = this->Secondary;
  v6 = 1.0 / (float)((float)((float)(second * 2.0) + prim) + (float)(tert * 2.0));
  v7 = prim * v6;
  v8 = second * v6;
  v9 = tert * v6;
  do
  {
    v10 = 0i64;
    v10.m128_f32[0] = (float)v4;
    v11 = v10;
    v11.m128_f32[0] = (float)v4 * v7;
    v12 = (signed int)v11.m128_f32[0];
    if ( (signed int)v11.m128_f32[0] != 0x80000000 && (float)v12 != v11.m128_f32[0] )
      v11.m128_f32[0] = (float)(v12 - (_mm_movemask_ps(_mm_unpacklo_ps(v11, v11)) & 1));
    v13 = v10;
    v13.m128_f32[0] = v10.m128_f32[0] * v8;
    v14 = (signed int)(float)(v10.m128_f32[0] * v8);
    *(v5 - 256) = (signed int)v11.m128_f32[0];
    if ( v14 != 0x80000000 && (float)v14 != v13.m128_f32[0] )
      v13.m128_f32[0] = (float)(v14 - (_mm_movemask_ps(_mm_unpacklo_ps(v13, v13)) & 1));
    v10.m128_f32[0] = v10.m128_f32[0] * v9;
    v15 = (signed int)v10.m128_f32[0];
    *v5 = (signed int)v13.m128_f32[0];
    if ( (signed int)v10.m128_f32[0] != 0x80000000 && (float)v15 != v10.m128_f32[0] )
      v10.m128_f32[0] = (float)(v15 - (_mm_movemask_ps(_mm_unpacklo_ps(v10, v10)) & 1));
    ++v4;
    (++v5)[255] = (signed int)v10.m128_f32[0];
  }
  while ( (unsigned int)v4 < 0x100 );
}

// File Line: 231
// RVA: 0x971BC0
void __fastcall Scaleform::Render::GlyphCache::EvictNotifier::Evict(Scaleform::Render::GlyphCache::EvictNotifier *this, Scaleform::Render::TextMeshProvider *p)
{
  Scaleform::Render::TextMeshProvider::Clear(p);
}

// File Line: 232
// RVA: 0x959FA0
void __fastcall Scaleform::Render::GlyphCache::EvictNotifier::ApplyInUseList(Scaleform::Render::GlyphCache::EvictNotifier *this)
{
  Scaleform::Render::GlyphCache::ApplyInUseList(this->pCache);
}

// File Line: 233
// RVA: 0x9BF3D0
bool __fastcall Scaleform::Render::GlyphCache::EvictNotifier::UpdatePinList(Scaleform::Render::GlyphCache::EvictNotifier *this)
{
  return Scaleform::Render::GlyphCache::UpdatePinList(this->pCache);
}

