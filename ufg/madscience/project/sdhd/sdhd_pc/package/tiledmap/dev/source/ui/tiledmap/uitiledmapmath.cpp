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
void __fastcall UFG::WorldPoint2f::WorldPoint2f(
        UFG::WorldPoint2f *this,
        UFG::ScreenPoint2f *point,
        UFG::UITiledMapMath *geo)
{
  float v5; // xmm2_4
  UFG::MinimapTilePoint2f v6; // [rsp+30h] [rbp+8h] BYREF

  *this = 0i64;
  UFG::MinimapTilePoint2f::MinimapTilePoint2f(&v6, point, geo);
  v5 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                              (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX)
                            / UFG::UITiledMapMath::WorldGeo.TextureWidth) ^ _xmm[0])
             * (float)((float)geo->m_rowOffset + v6.y))
     + UFG::UITiledMapMath::WorldGeo.MaxY;
  this->x = (float)((float)((float)geo->m_colOffset + v6.x)
                  * (float)((float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX)
                          / UFG::UITiledMapMath::WorldGeo.TextureWidth))
          + UFG::UITiledMapMath::WorldGeo.MinX;
  this->y = v5;
}

// File Line: 134
// RVA: 0xBB770
void __fastcall UFG::MinimapTilePoint2f::MinimapTilePoint2f(
        UFG::MinimapTilePoint2f *this,
        UFG::MinimapPoint2f *point,
        UFG::UITiledMapMath *geo)
{
  *this = 0i64;
  this->x = point->x - (float)geo->m_colOffset;
  this->y = point->y - (float)geo->m_rowOffset;
}

// File Line: 141
// RVA: 0xBB7B0
void __fastcall UFG::MinimapTilePoint2f::MinimapTilePoint2f(
        UFG::MinimapTilePoint2f *this,
        UFG::ScreenPoint2f *point,
        UFG::UITiledMapMath *geo)
{
  __m128 y_low; // xmm0
  float v6; // xmm1_4
  __m128 v7; // xmm3
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm0_4
  float v11; // xmm7_4
  float v12; // xmm6_4
  float v13; // xmm0_4

  *this = 0i64;
  y_low = (__m128)LODWORD(point->y);
  v6 = point->x - geo->screenPosition.x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - geo->screenPosition.y;
  v7 = y_low;
  v7.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v6 * v6);
  LODWORD(v8) = _mm_sqrt_ps(v7).m128_u32[0];
  v9 = atan2f(y_low.m128_f32[0], v6) - geo->rot;
  if ( geo->useWideTiles )
    v10 = FLOAT_0_5;
  else
    v10 = 0.0;
  v11 = v8 / (float)((float)(UFG::UITiledMapTweakables::MinimapScaleTweak + geo->scale) + v10);
  v12 = cosf(v9);
  v13 = sinf(v9);
  this->x = v12 * v11;
  this->y = v13 * v11;
}

// File Line: 166
// RVA: 0xBB880
void __fastcall UFG::ScreenPoint2f::ScreenPoint2f(
        UFG::ScreenPoint2f *this,
        UFG::WorldPoint2f *point,
        UFG::UITiledMapMath *geo)
{
  float m_rowOffset; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm4_4
  UFG::MinimapTilePoint2f iconPos; // [rsp+30h] [rbp+8h] BYREF

  *this = 0i64;
  m_rowOffset = (float)geo->m_rowOffset;
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
            - m_rowOffset;
  UFG::ScreenPoint2f::InitFromIconPos(this, &iconPos, geo);
}

// File Line: 174
// RVA: 0xC5A90
void __fastcall UFG::ScreenPoint2f::InitFromMapPos(
        UFG::ScreenPoint2f *this,
        UFG::MinimapTilePoint2f *mapPos,
        UFG::UITiledMapMath *geo)
{
  float y; // xmm0_4
  __m128 x_low; // xmm1
  __m128 v5; // xmm3
  float v8; // xmm7_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm8_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  float v14; // xmm0_4

  y = mapPos->y;
  x_low = (__m128)LODWORD(mapPos->x);
  v5 = x_low;
  v5.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y);
  LODWORD(v8) = _mm_sqrt_ps(v5).m128_u32[0];
  v9 = atan2f(y, x_low.m128_f32[0]);
  if ( geo->useWideTiles )
    v10 = FLOAT_0_5;
  else
    v10 = 0.0;
  v11 = v9 + geo->rot;
  v12 = v8 * (float)((float)(UFG::UITiledMapTweakables::MinimapScaleTweak + geo->scale) + v10);
  v13 = cosf(v11) * v12;
  v14 = sinf(v11) * v12;
  LODWORD(this->x) = COERCE_UNSIGNED_INT(v13 - geo->CircleMaskX) ^ _xmm[0];
  LODWORD(this->y) = COERCE_UNSIGNED_INT(v14 - geo->CircleMaskY) ^ _xmm[0];
}

// File Line: 186
// RVA: 0xC59D0
void __fastcall UFG::ScreenPoint2f::InitFromIconPos(
        UFG::ScreenPoint2f *this,
        UFG::MinimapTilePoint2f *iconPos,
        UFG::UITiledMapMath *geo)
{
  float y; // xmm0_4
  __m128 x_low; // xmm1
  __m128 v5; // xmm3
  float v8; // xmm7_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm8_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  float v14; // xmm0_4

  y = iconPos->y;
  x_low = (__m128)LODWORD(iconPos->x);
  v5 = x_low;
  v5.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y);
  LODWORD(v8) = _mm_sqrt_ps(v5).m128_u32[0];
  v9 = atan2f(y, x_low.m128_f32[0]);
  if ( geo->useWideTiles )
    v10 = FLOAT_0_5;
  else
    v10 = 0.0;
  v11 = v9 + geo->rot;
  v12 = v8 * (float)((float)(UFG::UITiledMapTweakables::MinimapScaleTweak + geo->scale) + v10);
  v13 = cosf(v11);
  v14 = sinf(v11) * v12;
  this->x = (float)(v13 * v12) + geo->screenPosition.x;
  this->y = v14 + geo->screenPosition.y;
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
void __fastcall UFG::UITiledMapMath::UpdatePosition(
        UFG::UITiledMapMath *this,
        UFG::MinimapPoint2f pos,
        int mapTileSize)
{
  float x; // xmm4_4
  float y; // xmm3_4
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  int v7; // edx
  int v8; // edx
  float v9; // xmm3_4
  UFG::MinimapTilePoint2f mapPos; // [rsp+38h] [rbp+10h] BYREF

  mapPos = (UFG::MinimapTilePoint2f)pos;
  x = pos.x;
  y = pos.y;
  if ( this->useWideTiles )
  {
    x = pos.x * 0.66666669;
    y = pos.y * 0.66666669;
  }
  if ( this->useTiledMap )
  {
    v5 = (__m128)(unsigned int)FLOAT_1_0;
    v5.m128_f32[0] = 1.0 / (float)mapTileSize;
    v6 = v5;
    v6.m128_f32[0] = v5.m128_f32[0] * y;
    v7 = (int)(float)(v5.m128_f32[0] * y);
    if ( v7 != 0x80000000 && (float)v7 != v6.m128_f32[0] )
      v6.m128_f32[0] = (float)(v7 - (_mm_movemask_ps(_mm_unpacklo_ps(v6, v6)) & 1));
    v5.m128_f32[0] = v5.m128_f32[0] * x;
    v8 = (int)v5.m128_f32[0];
    this->m_rowOffset = mapTileSize * (int)v6.m128_f32[0];
    if ( (int)v5.m128_f32[0] != 0x80000000 && (float)v8 != v5.m128_f32[0] )
      v5.m128_f32[0] = (float)(v8 - (_mm_movemask_ps(_mm_unpacklo_ps(v5, v5)) & 1));
    this->m_colOffset = mapTileSize * (int)v5.m128_f32[0];
  }
  else
  {
    *(_QWORD *)&this->m_rowOffset = 0i64;
  }
  v9 = y - (float)this->m_rowOffset;
  mapPos.x = x - (float)this->m_colOffset;
  mapPos.y = v9;
  UFG::ScreenPoint2f::InitFromMapPos(&this->screenPosition, &mapPos, this);
}

// File Line: 246
// RVA: 0xC0B70
float __fastcall UFG::UITiledMapMath::GetAdjustedScale(UFG::UITiledMapMath *this)
{
  if ( this->useWideTiles )
    return (float)(UFG::UITiledMapTweakables::MinimapScaleTweak + this->scale) + 0.5;
  else
    return (float)(UFG::UITiledMapTweakables::MinimapScaleTweak + this->scale) + 0.0;
}

