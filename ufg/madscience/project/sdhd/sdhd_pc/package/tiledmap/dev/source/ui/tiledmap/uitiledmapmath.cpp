// File Line: 27
// RVA: 0x1459580
__int64 dynamic_initializer_for__UFG::UITiledMapMath::WorldGeo__()
{
  UFG::UITiledMapMath::WorldGeo = UFG::UITiledMapMath::InitWorldGeo;
  return *(_QWORD *)&UFG::UITiledMapMath::InitWorldGeo.TextureWidth;
}

// File Line: 30
// RVA: 0x1459550
void dynamic_initializer_for__UFG::UITiledMapMath::MapRangeScaleAdjustment__()
{
  UFG::UITiledMapMath::MapRangeScaleAdjustment = (float)(UFG::UITiledMapMath::InitWorldGeo.TextureWidth - 200.0)
                                               * 0.00052056223;
}

// File Line: 60
// RVA: 0xBB6E0
void __fastcall UFG::MinimapPoint2f::MinimapPoint2f(UFG::MinimapPoint2f *this, UFG::WorldPoint2f *point)
{
  float v2; // xmm2_4
  float v3; // xmm5_4
  float v4; // xmm4_4

  *this = 0i64;
  v2 = 1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX);
  v3 = v2 * UFG::UITiledMapMath::WorldGeo.TextureWidth;
  v4 = (float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
     / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY);
  this->x = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::UITiledMapMath::WorldGeo.TextureWidth * UFG::UITiledMapMath::WorldGeo.MinX) ^ _xmm[0])
                  * v2)
          + (float)((float)(v2 * UFG::UITiledMapMath::WorldGeo.TextureWidth) * point->x);
  this->y = (float)(COERCE_FLOAT(LODWORD(v3) ^ _xmm[0]) * point->y) + v4;
}

// File Line: 102
// RVA: 0xBD360
void __fastcall UFG::WorldPoint2f::WorldPoint2f(UFG::WorldPoint2f *this, UFG::qVector3 *point)
{
  *this = 0i64;
  this->x = point->x;
  this->y = point->y;
}

// File Line: 109
// RVA: 0xBD2D0
void __fastcall UFG::WorldPoint2f::WorldPoint2f(UFG::WorldPoint2f *this, UFG::ScreenPoint2f *point, UFG::UITiledMapMath *geo)
{
  UFG::WorldPoint2f *v3; // rdi
  UFG::UITiledMapMath *v4; // rbx
  float v5; // xmm2_4
  UFG::MinimapTilePoint2f v6; // [rsp+30h] [rbp+8h]

  v3 = this;
  v4 = geo;
  *this = 0i64;
  UFG::MinimapTilePoint2f::MinimapTilePoint2f(&v6, point, geo);
  v5 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                              (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX)
                            / UFG::UITiledMapMath::WorldGeo.TextureWidth) ^ _xmm[0])
             * (float)((float)v4->m_rowOffset + v6.y))
     + UFG::UITiledMapMath::WorldGeo.MaxY;
  v3->x = (float)((float)((float)v4->m_colOffset + v6.x)
                * (float)((float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX)
                        / UFG::UITiledMapMath::WorldGeo.TextureWidth))
        + UFG::UITiledMapMath::WorldGeo.MinX;
  v3->y = v5;
}

// File Line: 134
// RVA: 0xBB770
void __fastcall UFG::MinimapTilePoint2f::MinimapTilePoint2f(UFG::MinimapTilePoint2f *this, UFG::MinimapPoint2f *point, UFG::UITiledMapMath *geo)
{
  *this = 0i64;
  this->x = point->x - (float)geo->m_colOffset;
  this->y = point->y - (float)geo->m_rowOffset;
}

// File Line: 141
// RVA: 0xBB7B0
void __fastcall UFG::MinimapTilePoint2f::MinimapTilePoint2f(UFG::MinimapTilePoint2f *this, UFG::ScreenPoint2f *point, UFG::UITiledMapMath *geo)
{
  UFG::UITiledMapMath *v3; // rdi
  UFG::MinimapTilePoint2f *v4; // rbx
  __m128 v5; // xmm0
  float v6; // xmm1_4
  __m128 v7; // xmm3
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm0_4
  float v11; // xmm7_4
  float v12; // xmm6_4
  float v13; // xmm0_4

  *this = 0i64;
  v3 = geo;
  v4 = this;
  v5 = (__m128)LODWORD(point->y);
  v6 = point->x - geo->screenPosition.x;
  v5.m128_f32[0] = v5.m128_f32[0] - geo->screenPosition.y;
  v7 = v5;
  v7.m128_f32[0] = (float)(v5.m128_f32[0] * v5.m128_f32[0]) + (float)(v6 * v6);
  LODWORD(v8) = (unsigned __int128)_mm_sqrt_ps(v7);
  v9 = atan2f(v5.m128_f32[0], v6) - geo->rot;
  if ( v3->useWideTiles )
    v10 = FLOAT_0_5;
  else
    v10 = 0.0;
  v11 = v8 / (float)((float)(UFG::UITiledMapTweakables::MinimapScaleTweak + v3->scale) + v10);
  v12 = cosf(v9);
  v13 = sinf(v9);
  v4->x = v12 * v11;
  v4->y = v13 * v11;
}

// File Line: 166
// RVA: 0xBB880
void __fastcall UFG::ScreenPoint2f::ScreenPoint2f(UFG::ScreenPoint2f *this, UFG::WorldPoint2f *point, UFG::UITiledMapMath *geo)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm4_4
  UFG::MinimapTilePoint2f iconPos; // [rsp+30h] [rbp+8h]

  *this = 0i64;
  v3 = (float)geo->m_rowOffset;
  v4 = 1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX);
  v5 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v4 * UFG::UITiledMapMath::WorldGeo.TextureWidth) ^ _xmm[0]) * point->y;
  iconPos.x = (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                             UFG::UITiledMapMath::WorldGeo.TextureWidth
                                           * UFG::UITiledMapMath::WorldGeo.MinX) ^ _xmm[0])
                            * v4)
                    + (float)((float)(v4 * UFG::UITiledMapMath::WorldGeo.TextureWidth) * point->x))
            - (float)geo->m_colOffset;
  iconPos.y = (float)((float)((float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
                            / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY))
                    + v5)
            - v3;
  UFG::ScreenPoint2f::InitFromIconPos(this, &iconPos, geo);
}

// File Line: 174
// RVA: 0xC5A90
void __fastcall UFG::ScreenPoint2f::InitFromMapPos(UFG::ScreenPoint2f *this, UFG::MinimapTilePoint2f *mapPos, UFG::UITiledMapMath *geo)
{
  float v3; // xmm0_4
  __m128 v4; // xmm1
  __m128 v5; // xmm3
  UFG::UITiledMapMath *v6; // rbx
  UFG::ScreenPoint2f *v7; // rdi
  float v8; // xmm7_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm8_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  float v14; // xmm0_4

  v3 = mapPos->y;
  v4 = (__m128)LODWORD(mapPos->x);
  v5 = v4;
  v6 = geo;
  v7 = this;
  v5.m128_f32[0] = (float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(v3 * v3);
  LODWORD(v8) = (unsigned __int128)_mm_sqrt_ps(v5);
  v9 = atan2f(v3, v4.m128_f32[0]);
  if ( v6->useWideTiles )
    v10 = FLOAT_0_5;
  else
    v10 = 0.0;
  v11 = v9 + v6->rot;
  v12 = v8 * (float)((float)(UFG::UITiledMapTweakables::MinimapScaleTweak + v6->scale) + v10);
  v13 = cosf(v11) * v12;
  v14 = sinf(v11) * v12;
  LODWORD(v7->x) = COERCE_UNSIGNED_INT(v13 - v6->CircleMaskX) ^ _xmm[0];
  LODWORD(v7->y) = COERCE_UNSIGNED_INT(v14 - v6->CircleMaskY) ^ _xmm[0];
}

// File Line: 186
// RVA: 0xC59D0
void __fastcall UFG::ScreenPoint2f::InitFromIconPos(UFG::ScreenPoint2f *this, UFG::MinimapTilePoint2f *iconPos, UFG::UITiledMapMath *geo)
{
  float v3; // xmm0_4
  __m128 v4; // xmm1
  __m128 v5; // xmm3
  UFG::UITiledMapMath *v6; // rbx
  UFG::ScreenPoint2f *v7; // rdi
  float v8; // xmm7_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm8_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  float v14; // xmm0_4

  v3 = iconPos->y;
  v4 = (__m128)LODWORD(iconPos->x);
  v5 = v4;
  v6 = geo;
  v7 = this;
  v5.m128_f32[0] = (float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(v3 * v3);
  LODWORD(v8) = (unsigned __int128)_mm_sqrt_ps(v5);
  v9 = atan2f(v3, v4.m128_f32[0]);
  if ( v6->useWideTiles )
    v10 = FLOAT_0_5;
  else
    v10 = 0.0;
  v11 = v9 + v6->rot;
  v12 = v8 * (float)((float)(UFG::UITiledMapTweakables::MinimapScaleTweak + v6->scale) + v10);
  v13 = cosf(v11);
  v14 = sinf(v11) * v12;
  v7->x = (float)(v13 * v12) + v6->screenPosition.x;
  v7->y = v14 + v6->screenPosition.y;
}

// File Line: 207
// RVA: 0xBCF80
void __fastcall UFG::UITiledMapMath::UITiledMapMath(UFG::UITiledMapMath *this)
{
  this->screenPosition = 0i64;
  this->centerPosition = 0i64;
  *(_QWORD *)&this->rot = 0i64;
  *(_QWORD *)&this->CircleMaskX = 0i64;
  this->IsWorldMap = 0;
  this->scale = 1.0;
  *(_WORD *)&this->useWideTiles = 256;
  this->MaskRadius = 100.0;
}

// File Line: 218
// RVA: 0xCE200
void __fastcall UFG::UITiledMapMath::UpdatePosition(UFG::UITiledMapMath *this, UFG::MinimapPoint2f pos, int mapTileSize)
{
  float v3; // xmm4_4
  float v4; // xmm3_4
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  signed int v7; // edx
  signed int v8; // edx
  float v9; // xmm3_4
  UFG::MinimapTilePoint2f mapPos; // [rsp+38h] [rbp+10h]

  mapPos = (UFG::MinimapTilePoint2f)pos;
  v3 = pos.x;
  v4 = pos.y;
  if ( this->useWideTiles )
  {
    v3 = pos.x * 0.66666669;
    v4 = pos.y * 0.66666669;
  }
  if ( this->useTiledMap )
  {
    v5 = (__m128)(unsigned int)FLOAT_1_0;
    v5.m128_f32[0] = 1.0 / (float)mapTileSize;
    v6 = v5;
    v6.m128_f32[0] = v5.m128_f32[0] * v4;
    v7 = (signed int)(float)(v5.m128_f32[0] * v4);
    if ( v7 != 0x80000000 && (float)v7 != v6.m128_f32[0] )
      v6.m128_f32[0] = (float)(v7 - (_mm_movemask_ps(_mm_unpacklo_ps(v6, v6)) & 1));
    v5.m128_f32[0] = v5.m128_f32[0] * v3;
    v8 = (signed int)v5.m128_f32[0];
    this->m_rowOffset = mapTileSize * (signed int)v6.m128_f32[0];
    if ( (signed int)v5.m128_f32[0] != 0x80000000 && (float)v8 != v5.m128_f32[0] )
      v5.m128_f32[0] = (float)(v8 - (_mm_movemask_ps(_mm_unpacklo_ps(v5, v5)) & 1));
    this->m_colOffset = mapTileSize * (signed int)v5.m128_f32[0];
  }
  else
  {
    *(_QWORD *)&this->m_rowOffset = 0i64;
  }
  v9 = v4 - (float)this->m_rowOffset;
  mapPos.x = v3 - (float)this->m_colOffset;
  mapPos.y = v9;
  UFG::ScreenPoint2f::InitFromMapPos(&this->screenPosition, &mapPos, this);
}

// File Line: 246
// RVA: 0xC0B70
float __fastcall UFG::UITiledMapMath::GetAdjustedScale(UFG::UITiledMapMath *this)
{
  float result; // xmm0_4

  if ( this->useWideTiles )
    result = (float)(UFG::UITiledMapTweakables::MinimapScaleTweak + this->scale) + 0.5;
  else
    result = (float)(UFG::UITiledMapTweakables::MinimapScaleTweak + this->scale) + 0.0;
  return result;
}

