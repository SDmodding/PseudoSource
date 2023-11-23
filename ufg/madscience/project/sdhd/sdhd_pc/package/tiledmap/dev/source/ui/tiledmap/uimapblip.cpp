// File Line: 71
// RVA: 0xBD670
void __fastcall UFG::UIMapBlip::~UIMapBlip(UFG::UIMapBlip *this)
{
  UFG::UIMapBlipGraphic *mNativeIcon; // rsi
  void **v3; // rbx
  __int64 v4; // rdi
  char *mWorldMapCaption; // rcx

  mNativeIcon = this->mNativeIcon;
  if ( mNativeIcon )
  {
    v3 = (void **)&mNativeIcon->mPolys[1];
    v4 = 4i64;
    mNativeIcon->vfptr = (UFG::UIMapBlipGraphicVtbl *)&UFG::UIMapBlipGraphic::`vftable;
    do
    {
      if ( *v3 )
      {
        operator delete[](*v3);
        *v3 = 0i64;
      }
      ++v3;
      --v4;
    }
    while ( v4 );
    operator delete[](mNativeIcon);
  }
  mWorldMapCaption = (char *)this->mWorldMapCaption;
  if ( mWorldMapCaption )
  {
    operator delete[](mWorldMapCaption);
    this->mWorldMapCaption = 0i64;
  }
}

// File Line: 96
// RVA: 0xBE9E0
void __fastcall UFG::UIMapBlip::Clone(UFG::UIMapBlip *this, UFG::UIMapBlip *clone)
{
  float v2; // xmm0_4
  float y; // xmm0_4
  float z; // xmm1_4

  if ( clone )
  {
    UFG::UIMapBlip::SetType(this, clone->mType, v2);
    y = clone->pos.y;
    z = clone->pos.z;
    this->pos.x = clone->pos.x;
    this->pos.y = y;
    this->pos.z = z;
    this->mVisible = clone->mVisible;
    UFG::UIMapBlip::SetWorldMapCaption(this, clone->mWorldMapCaption);
  }
}

// File Line: 108
// RVA: 0xCDCC0
void __fastcall UFG::UIMapBlip::UpdateNative(
        UFG::UIMapBlip *this,
        UFG::qVector3 *playerPos,
        UFG::UITiledMapMath *mapGeo,
        UFG::UITiledMapMath *mapIconGeo,
        UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeClipped,
        UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeNotClipped,
        UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeDoubleClipped)
{
  float Alpha; // xmm0_4
  UFG::UIMapBlipGraphic *mNativeIcon; // rcx
  bool v12; // zf
  float v13; // xmm2_4
  float v14; // xmm4_4
  float v15; // xmm6_4
  float v16; // xmm7_4
  bool boundIcon; // al
  float v18; // xmm11_4
  float y; // xmm8_4
  float x; // xmm9_4
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm10_4
  float v24; // xmm0_4
  float v25; // xmm6_4
  float v26; // xmm10_4
  float v27; // xmm9_4
  float v28; // xmm0_4
  UFG::ScreenPoint2f screenPoint; // [rsp+30h] [rbp-78h] BYREF
  UFG::MinimapPoint2f mapPoint; // [rsp+B0h] [rbp+8h] BYREF

  if ( this->mType )
  {
    Alpha = UFG::UIMapBlip::GetAlpha(this, playerPos, mapGeo);
    mNativeIcon = this->mNativeIcon;
    if ( mNativeIcon )
      UFG::UIMapBlipGraphic::SetAlpha(mNativeIcon, IconPoly, Alpha);
    if ( Alpha >= 0.001 && this->mNativeIcon )
    {
      v12 = !mapGeo->IsWorldMap;
      v13 = 1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX);
      v14 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v13 * UFG::UITiledMapMath::WorldGeo.TextureWidth) ^ _xmm[0]) * this->pos.y;
      v15 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::UITiledMapMath::WorldGeo.TextureWidth * UFG::UITiledMapMath::WorldGeo.MinX) ^ _xmm[0])
                  * v13)
          + (float)((float)(v13 * UFG::UITiledMapMath::WorldGeo.TextureWidth) * this->pos.x);
      mapPoint.x = v15;
      v16 = (float)((float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
                  / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY))
          + v14;
      mapPoint.y = v16;
      if ( (!v12 || mapIconGeo->IsWorldMap) && this->pos.y > 1690.0 && this->pos.z > 20.0 )
      {
        v15 = v15 + UFG::UITiledMapTweakables::WorldMap_ElectionBlipOffsetX;
        v16 = v16 + UFG::UITiledMapTweakables::WorldMap_ElectionBlipOffsetY;
        mapPoint.x = v15;
        mapPoint.y = v16;
      }
      boundIcon = this->mBoundIcon;
      v18 = 0.0;
      screenPoint = 0i64;
      UFG::UIMapBlip::MapToScreen(mapGeo, mapIconGeo, &mapPoint, &screenPoint, boundIcon, &this->mTouchesEdge);
      if ( mapGeo->IsWorldMap || !this->mType->HideOnBorder || !this->mTouchesEdge )
      {
        y = screenPoint.y;
        x = screenPoint.x;
        ((void (__fastcall *)(UFG::UIMapBlipGraphic *))this->mNativeIcon->vfptr->UpdateLocation)(this->mNativeIcon);
        this->mNativeIcon->vfptr->UpdateAnimation(this->mNativeIcon);
        if ( this->mHasRadius )
        {
          if ( this->mBoundIcon )
          {
            v21 = v15 - (float)mapIconGeo->m_colOffset;
            v22 = v16 - (float)mapIconGeo->m_rowOffset;
            v23 = fsqrt((float)(v21 * v21) + (float)(v22 * v22));
            v24 = atan2f(v22, v21);
            if ( mapIconGeo->useWideTiles )
              v18 = FLOAT_0_5;
            v25 = v24 + mapIconGeo->rot;
            v26 = v23 * (float)((float)(UFG::UITiledMapTweakables::MinimapScaleTweak + mapIconGeo->scale) + v18);
            v27 = cosf(v25);
            v28 = sinf(v25);
            x = (float)(v27 * v26) + mapIconGeo->screenPosition.x;
            y = (float)(v28 * v26) + mapIconGeo->screenPosition.y;
          }
          UFG::UIMapBlipGraphic::SetPos(this->mNativeIcon, RangePoly, x, y);
          UFG::UIMapBlipGraphic::SetPos(this->mNativeIcon, InteriorRangePoly, x, y);
        }
        UFG::UIMapBlipGraphic::QueueIconToRender(
          this->mNativeIcon,
          polyListNativeClipped,
          polyListNativeNotClipped,
          polyListNativeDoubleClipped);
      }
    }
  }
}

// File Line: 176
// RVA: 0xCC020
void __fastcall UFG::UIMapBlip::Update(
        UFG::UIMapBlip *this,
        UFG::UIScreen *screen,
        UFG::qVector3 *playerPos,
        UFG::UITiledMapMath *mapGeo)
{
  float v5; // xmm0_4
  UFG::UIMapBlip::eAltitudeState v6; // ecx
  bool v7; // zf
  bool v8; // al
  UFG::UIMapBlip::eAltitudeState mAltitudeState; // eax
  UFG::UIMapBlipGraphic *mNativeIcon; // rcx
  UFG::UIMapBlipGraphic *v11; // rcx
  UFG::UIMapBlipGraphic *v12; // rcx
  UFG::UIMapBlipGraphic *v13; // rcx

  if ( this->mNativeIcon )
  {
    if ( this->mHasAltitude && this->mType->HasAltitude )
    {
      v5 = this->pos.z - playerPos->z;
      this->mAltitudeDiff = v5;
      v6 = ALTITUDE_SAME;
      if ( v5 <= 3.5 )
      {
        if ( v5 < -3.5 )
          v6 = ALTITUDE_LOWER;
      }
      else
      {
        v6 = ALTITUDE_HIGHER;
      }
      v7 = this->mAltitudeState == v6;
      this->mAltitudeState = v6;
      this->mAltitudeStateChanged |= !v7;
      v8 = (float)((float)((float)(this->pos.y - playerPos->y) * (float)(this->pos.y - playerPos->y))
                 + (float)((float)(this->pos.x - playerPos->x) * (float)(this->pos.x - playerPos->x))) < this->mAltitudeIconRangeSq;
      if ( this->mInAltitudeRange != v8 )
      {
        this->mInAltitudeRange = v8;
        if ( v8 )
          this->mAltitudeStateChanged = 1;
        else
          UFG::UIMapBlip::SetNormalAltitude(this);
      }
      if ( this->mInAltitudeRange && this->mAltitudeStateChanged )
      {
        mAltitudeState = this->mAltitudeState;
        this->mAltitudeStateChanged = 0;
        switch ( mAltitudeState )
        {
          case ALTITUDE_HIGHER:
            UFG::UIMapBlip::SetHigherAltitude(this);
            break;
          case ALTITUDE_LOWER:
            UFG::UIMapBlip::SetLowerAltitude(this);
            break;
          case ALTITUDE_SAME:
            UFG::UIMapBlip::SetNormalAltitude(this);
            break;
        }
      }
    }
    if ( this->mChanged )
    {
      v7 = !this->mHasObjectiveHighlight;
      this->mChanged = 0;
      if ( !v7 )
      {
        mNativeIcon = this->mNativeIcon;
        if ( mNativeIcon )
          ((void (__fastcall *)(UFG::UIMapBlipGraphic *, UFG::UIScreen *, UFG::qVector3 *, UFG::UITiledMapMath *))mNativeIcon->vfptr->SetBlink)(
            mNativeIcon,
            screen,
            playerPos,
            mapGeo);
      }
      if ( this->mShouldBlink )
      {
        v11 = this->mNativeIcon;
        if ( v11 )
        {
          ((void (__fastcall *)(UFG::UIMapBlipGraphic *, UFG::UIScreen *, UFG::qVector3 *, UFG::UITiledMapMath *))v11->vfptr->SetBlink)(
            v11,
            screen,
            playerPos,
            mapGeo);
          *(_DWORD *)&this->mShouldBlink = 0;
          this->mShouldStopHighlight = 0;
          return;
        }
      }
      else if ( this->mShouldPulse )
      {
        v12 = this->mNativeIcon;
        if ( v12 )
        {
          ((void (__fastcall *)(UFG::UIMapBlipGraphic *, UFG::UIScreen *, UFG::qVector3 *, UFG::UITiledMapMath *))v12->vfptr->SetPulse)(
            v12,
            screen,
            playerPos,
            mapGeo);
          *(_DWORD *)&this->mShouldBlink = 0;
          this->mShouldStopHighlight = 0;
          return;
        }
      }
      else if ( !this->mShouldHighlight && this->mShouldStopBlink )
      {
        v13 = this->mNativeIcon;
        if ( v13 )
          ((void (__fastcall *)(UFG::UIMapBlipGraphic *, UFG::UIScreen *, UFG::qVector3 *, UFG::UITiledMapMath *))v13->vfptr->StopBlink)(
            v13,
            screen,
            playerPos,
            mapGeo);
      }
      *(_DWORD *)&this->mShouldBlink = 0;
      this->mShouldStopHighlight = 0;
    }
  }
}

// File Line: 280
// RVA: 0xCAE30
void __fastcall UFG::UIMapBlip::SetNormalAltitude(UFG::UIMapBlip *this)
{
  UFG::UIMapBlipGraphic *mNativeIcon; // rcx

  mNativeIcon = this->mNativeIcon;
  if ( mNativeIcon )
  {
    if ( mNativeIcon->vfptr->HasAltitudeIcon(mNativeIcon) )
      UFG::UIMapBlipGraphic::RemovePoly(this->mNativeIcon, AltitudePoly);
  }
}

// File Line: 287
// RVA: 0xCA880
void __fastcall UFG::UIMapBlip::SetHigherAltitude(UFG::UIMapBlip *this)
{
  UFG::UIMapBlipGraphic *mNativeIcon; // rcx
  UFG::qColour v3; // xmm6
  float v4; // xmm7_4
  UFG::UIMapBlipGraphic *v5; // rbx
  UFG::UIRenderQuad *v6; // rax
  UFG::UIRenderQuad *v7; // rcx
  char *v8; // [rsp+60h] [rbp+8h]
  char *v9; // [rsp+60h] [rbp+8h]
  char *v10; // [rsp+60h] [rbp+8h]

  mNativeIcon = this->mNativeIcon;
  if ( mNativeIcon && mNativeIcon->vfptr->HasAltitudeIcon(mNativeIcon) )
  {
    v3 = UFG::qColour::White;
    v4 = (float)dword_142034218;
    v5 = this->mNativeIcon;
    if ( !v5->mPolys[4] )
    {
      v8 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v8 + 13) = 1092616192;
      *((_QWORD *)v8 + 1) = 0i64;
      *((_DWORD *)v8 + 8) = 1065353216;
      v8[72] = 0;
      v5->mPolys[4] = (UFG::UIRenderQuad *)v8;
    }
    v6 = v5->mPolys[4];
    v6->Color = v3;
    v6->Size = v4;
    *(_QWORD *)&v6->X = 0i64;
    *(_QWORD *)&v6->OffsetX = 0i64;
    v6->Visible = 1;
    if ( !v5->mPolys[4] )
    {
      v9 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v9 + 13) = 1092616192;
      *((_QWORD *)v9 + 1) = 0i64;
      *((_DWORD *)v9 + 8) = 1065353216;
      v9[72] = 0;
      v5->mPolys[4] = (UFG::UIRenderQuad *)v9;
    }
    v5->mPolys[4]->Color.a = 1.0;
    if ( !v5->mPolys[4] )
    {
      v10 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v10 + 13) = 1092616192;
      *((_QWORD *)v10 + 1) = 0i64;
      *((_DWORD *)v10 + 8) = 1065353216;
      v10[72] = 0;
      v5->mPolys[4] = (UFG::UIRenderQuad *)v10;
    }
    v7 = v5->mPolys[4];
    v7->TextureID = uid_Icon_Minimap_TextureSheet;
    v7->UVs[0] = 0.875;
    v7->UVs[1] = 0.25;
    v7->UVs[2] = 0.125;
    v7->UVs[3] = 0.125;
    UFG::UIMapBlipGraphic::SetPolyOffset(this->mNativeIcon, AltitudePoly, 0, -10);
  }
}

// File Line: 296
// RVA: 0xCACA0
void __fastcall UFG::UIMapBlip::SetLowerAltitude(UFG::UIMapBlip *this)
{
  UFG::UIMapBlipGraphic *mNativeIcon; // rcx
  UFG::qColour v3; // xmm6
  float v4; // xmm7_4
  UFG::UIMapBlipGraphic *v5; // rbx
  UFG::UIRenderQuad *v6; // rax
  UFG::UIRenderQuad *v7; // rcx
  char *v8; // [rsp+60h] [rbp+8h]
  char *v9; // [rsp+60h] [rbp+8h]
  char *v10; // [rsp+60h] [rbp+8h]

  mNativeIcon = this->mNativeIcon;
  if ( mNativeIcon && mNativeIcon->vfptr->HasAltitudeIcon(mNativeIcon) )
  {
    v3 = UFG::qColour::White;
    v4 = (float)dword_142034218;
    v5 = this->mNativeIcon;
    if ( !v5->mPolys[4] )
    {
      v8 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v8 + 13) = 1092616192;
      *((_QWORD *)v8 + 1) = 0i64;
      *((_DWORD *)v8 + 8) = 1065353216;
      v8[72] = 0;
      v5->mPolys[4] = (UFG::UIRenderQuad *)v8;
    }
    v6 = v5->mPolys[4];
    v6->Color = v3;
    v6->Size = v4;
    *(_QWORD *)&v6->X = 0i64;
    *(_QWORD *)&v6->OffsetX = 0i64;
    v6->Visible = 1;
    if ( !v5->mPolys[4] )
    {
      v9 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v9 + 13) = 1092616192;
      *((_QWORD *)v9 + 1) = 0i64;
      *((_DWORD *)v9 + 8) = 1065353216;
      v9[72] = 0;
      v5->mPolys[4] = (UFG::UIRenderQuad *)v9;
    }
    v5->mPolys[4]->Color.a = 1.0;
    if ( !v5->mPolys[4] )
    {
      v10 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
      *((_DWORD *)v10 + 13) = 1092616192;
      *((_QWORD *)v10 + 1) = 0i64;
      *((_DWORD *)v10 + 8) = 1065353216;
      v10[72] = 0;
      v5->mPolys[4] = (UFG::UIRenderQuad *)v10;
    }
    v7 = v5->mPolys[4];
    v7->TextureID = uid_Icon_Minimap_TextureSheet;
    v7->UVs[0] = 0.875;
    v7->UVs[1] = 0.375;
    v7->UVs[2] = 0.125;
    v7->UVs[3] = -0.125;
    UFG::UIMapBlipGraphic::SetPolyOffset(this->mNativeIcon, AltitudePoly, 0, 10);
  }
}

// File Line: 372
// RVA: 0xCB7F0
void __fastcall UFG::UIMapBlip::SetType(UFG::UIMapBlip *this, UFG::UIHKMinimapBlipType *type)
{
  float v2; // xmm0_4
  UFG::UIMapBlipGraphic *mNativeIcon; // rcx
  UFG::UIMapBlipGraphic *NativeIconInstance; // rax

  if ( type != this->mType )
  {
    this->mType = type;
    if ( type )
    {
      if ( (_S5_2 & 1) == 0 )
      {
        _S5_2 |= 1u;
        UFG::qSymbolUC::create_from_string(&invisible_icon, "invisible_icon");
        atexit(UFG::UIMapBlip::SetType_::_8_::_dynamic_atexit_destructor_for__invisible_icon__);
      }
      if ( this->mType->TypeNameSymbol.mUID == invisible_icon.mUID )
        this->mBoundIcon = 0;
      mNativeIcon = this->mNativeIcon;
      if ( mNativeIcon )
        UFG::UIMapBlipGraphic::`scalar deleting destructor(mNativeIcon, 1);
      NativeIconInstance = UFG::UIMapBlipGraphicFactory::GetNativeIconInstance(
                             &UFG::UIMapBlipGraphicFactory::Singleton,
                             &this->mType->Icon);
      this->mNativeIcon = NativeIconInstance;
      if ( NativeIconInstance )
        NativeIconInstance->vfptr->AltitudeIconRange(NativeIconInstance);
      else
        v2 = 0.0;
      this->mAltitudeIconRangeSq = v2 * v2;
      this->mIconTypeChanged = 1;
    }
  }
}

// File Line: 414
// RVA: 0xCB8F0
void __fastcall UFG::UIMapBlip::SetWorldMapCaption(UFG::UIMapBlip *this, const char *caption)
{
  char *mWorldMapCaption; // rcx
  int v5; // eax
  char *v6; // rbx

  mWorldMapCaption = (char *)this->mWorldMapCaption;
  if ( mWorldMapCaption )
  {
    operator delete[](mWorldMapCaption);
    this->mWorldMapCaption = 0i64;
  }
  if ( caption )
  {
    v5 = UFG::qStringLength(caption);
    v6 = UFG::qMalloc(v5 + 1, "UIMapBlip", 0i64);
    UFG::qStringCopy(v6, 0x7FFFFFFF, caption, -1);
    this->mWorldMapCaption = v6;
  }
}

// File Line: 458
// RVA: 0xC5E10
bool __fastcall UFG::UIMapBlip::IsVisible(UFG::UIMapBlip *this)
{
  UFG::UIHKMinimapBlipType *mType; // rax
  bool result; // al

  result = 0;
  if ( this->mVisible )
  {
    mType = this->mType;
    if ( mType )
    {
      if ( mType->IsVisible )
        return 1;
    }
  }
  return result;
}

// File Line: 464
// RVA: 0xCB8B0
void __fastcall UFG::UIMapBlip::SetVisible(UFG::UIMapBlip *this, bool visible)
{
  bool v2; // zf

  v2 = this->mVisible == visible;
  this->mVisible = visible;
  this->mChanged |= !v2;
}

// File Line: 485
// RVA: 0xCB3B0
void __fastcall UFG::UIMapBlip::SetPosition(UFG::UIMapBlip *this, UFG::qVector3 *worldPos)
{
  __m128 y_low; // xmm2
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4

  y_low = (__m128)LODWORD(this->pos.y);
  x = worldPos->x;
  y = worldPos->y;
  z = worldPos->z;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - y) * (float)(y_low.m128_f32[0] - y))
                            + (float)((float)(this->pos.x - x) * (float)(this->pos.x - x)))
                    + (float)((float)(this->pos.z - z) * (float)(this->pos.z - z));
  if ( _mm_sqrt_ps(y_low).m128_f32[0] > UFG::gSymbolPosDiff )
  {
    this->pos.x = x;
    this->pos.y = y;
    this->pos.z = z;
    this->mChanged = 1;
  }
}

// File Line: 505
// RVA: 0xC0CB0
float __fastcall UFG::UIMapBlip::GetAlpha(UFG::UIMapBlip *this)
{
  UFG::UIMapBlipGraphic *mNativeIcon; // rax
  UFG::UIRenderQuad *v3; // rax

  mNativeIcon = this->mNativeIcon;
  if ( !mNativeIcon )
    return 0.0;
  v3 = mNativeIcon->mPolys[0];
  if ( v3 )
    return v3->Color.a;
  else
    return *(float *)&FLOAT_1_0;
}

// File Line: 512
// RVA: 0xCAC30
void __fastcall UFG::UIMapBlip::SetIsSelectedObjective(UFG::UIMapBlip *this, bool value)
{
  bool v2; // zf

  v2 = this->mIsSelectedObjective == value;
  this->mIsSelectedObjective = value;
  this->mChanged |= !v2;
}

// File Line: 519
// RVA: 0xCB420
void __fastcall UFG::UIMapBlip::SetRange(UFG::UIMapBlip *this, bool visible, float radius)
{
  UFG::UIMapBlip::SetRange(this, visible, radius, &this->mType->RadiusColor, 1.0);
}

// File Line: 525
// RVA: 0xCB450
void __fastcall UFG::UIMapBlip::SetRange(
        UFG::UIMapBlip *this,
        bool visible,
        float radius,
        UFG::qColour *color,
        float alphaFactor)
{
  float v6; // xmm6_4
  UFG::UIMapBlipGraphic *mNativeIcon; // rbx
  float r; // xmm8_4
  float g; // xmm9_4
  float b; // xmm10_4
  float a; // xmm0_4
  float v12; // xmm7_4
  UFG::UIRenderQuad *v13; // rax
  UFG::UIRenderQuad *v14; // rcx
  char *v15; // [rsp+B0h] [rbp+8h]
  char *v16; // [rsp+B0h] [rbp+8h]
  char *v17; // [rsp+B0h] [rbp+8h]

  v6 = (float)(radius
             / (float)((float)((float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX)
                             / UFG::UITiledMapMath::WorldGeo.TextureWidth)
                     * 88.0))
     * UFG::UITiledMapMath::MapRangeScaleAdjustment;
  this->mChanged |= this->mHasRadius != visible;
  this->mHasRadius = visible;
  this->mChanged |= v6 != this->radiusScale;
  this->radiusScale = v6;
  mNativeIcon = this->mNativeIcon;
  if ( mNativeIcon )
  {
    if ( visible )
    {
      r = color->r;
      g = color->g;
      b = color->b;
      a = color->a;
      v12 = alphaFactor * a;
      if ( !((int)(float)(color->r * 255.0) | (((int)(float)(g * 255.0) | (((int)(float)(b * 255.0) | ((int)(float)(a * 255.0) << 8)) << 8)) << 8)) )
      {
        r = mNativeIcon->mIconPoly.Color.r;
        g = mNativeIcon->mIconPoly.Color.g;
        b = mNativeIcon->mIconPoly.Color.b;
        v12 = alphaFactor * 0.15000001;
      }
      if ( !mNativeIcon->mPolys[2] )
      {
        v15 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
        *((_DWORD *)v15 + 13) = 1092616192;
        *((_QWORD *)v15 + 1) = 0i64;
        *((_DWORD *)v15 + 8) = 1065353216;
        v15[72] = 0;
        mNativeIcon->mPolys[2] = (UFG::UIRenderQuad *)v15;
      }
      v13 = mNativeIcon->mPolys[2];
      v13->Color.r = r;
      v13->Color.g = g;
      v13->Color.b = b;
      v13->Color.a = alphaFactor;
      v13->Size = 150.0;
      *(_QWORD *)&v13->X = 0i64;
      *(_QWORD *)&v13->OffsetX = 0i64;
      v13->Visible = 1;
      if ( !mNativeIcon->mPolys[2] )
      {
        v16 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
        *((_DWORD *)v16 + 13) = 1092616192;
        *((_QWORD *)v16 + 1) = 0i64;
        *((_DWORD *)v16 + 8) = 1065353216;
        v16[72] = 0;
        mNativeIcon->mPolys[2] = (UFG::UIRenderQuad *)v16;
      }
      mNativeIcon->mPolys[2]->Color.a = 1.0;
      if ( !mNativeIcon->mPolys[2] )
      {
        v17 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
        *((_DWORD *)v17 + 13) = 1092616192;
        *((_QWORD *)v17 + 1) = 0i64;
        *((_DWORD *)v17 + 8) = 1065353216;
        v17[72] = 0;
        mNativeIcon->mPolys[2] = (UFG::UIRenderQuad *)v17;
      }
      v14 = mNativeIcon->mPolys[2];
      v14->TextureID = uid_CopRadiusIndicator;
      *(_QWORD *)v14->UVs = 0i64;
      v14->UVs[2] = 1.0;
      v14->UVs[3] = 1.0;
      UFG::UIMapBlipGraphic::SetAlpha(this->mNativeIcon, RangePoly, v12);
      UFG::UIMapBlipGraphic::SetScale(this->mNativeIcon, RangePoly, v6);
    }
    else
    {
      UFG::UIMapBlipGraphic::RemovePoly(this->mNativeIcon, RangePoly);
    }
  }
}

// File Line: 580
// RVA: 0xCAA00
void __fastcall UFG::UIMapBlip::SetInteriorRange(UFG::UIMapBlip *this, bool visible, float radius, UFG::qColour *color)
{
  float v5; // xmm6_4
  UFG::UIMapBlipGraphic *mNativeIcon; // rbx
  float r; // xmm7_4
  float g; // xmm8_4
  float b; // xmm9_4
  float a; // xmm11_4
  UFG::UIRenderQuad *v11; // rax
  UFG::UIRenderQuad *v12; // rcx
  char *v13; // [rsp+B0h] [rbp+8h]
  char *v14; // [rsp+B0h] [rbp+8h]
  char *v15; // [rsp+B0h] [rbp+8h]

  v5 = (float)(radius
             / (float)((float)((float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX)
                             / UFG::UITiledMapMath::WorldGeo.TextureWidth)
                     * 88.0))
     * UFG::UITiledMapMath::MapRangeScaleAdjustment;
  this->mChanged |= this->mHasInteriorRadius != visible;
  this->mHasInteriorRadius = visible;
  mNativeIcon = this->mNativeIcon;
  if ( mNativeIcon )
  {
    if ( visible )
    {
      r = color->r;
      g = color->g;
      b = color->b;
      a = color->a;
      if ( !mNativeIcon->mPolys[3] )
      {
        v13 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
        *((_DWORD *)v13 + 13) = 1092616192;
        *((_QWORD *)v13 + 1) = 0i64;
        *((_DWORD *)v13 + 8) = 1065353216;
        v13[72] = 0;
        mNativeIcon->mPolys[3] = (UFG::UIRenderQuad *)v13;
      }
      v11 = mNativeIcon->mPolys[3];
      v11->Color.r = r;
      v11->Color.g = g;
      v11->Color.b = b;
      LODWORD(v11->Color.a) = (_DWORD)FLOAT_1_0;
      v11->Size = 128.0;
      *(_QWORD *)&v11->X = 0i64;
      *(_QWORD *)&v11->OffsetX = 0i64;
      v11->Visible = 1;
      if ( !mNativeIcon->mPolys[3] )
      {
        v14 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
        *((_DWORD *)v14 + 13) = 1092616192;
        *((_QWORD *)v14 + 1) = 0i64;
        *((_DWORD *)v14 + 8) = 1065353216;
        v14[72] = 0;
        mNativeIcon->mPolys[3] = (UFG::UIRenderQuad *)v14;
      }
      mNativeIcon->mPolys[3]->Color.a = 1.0;
      if ( !mNativeIcon->mPolys[3] )
      {
        v15 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
        *((_DWORD *)v15 + 13) = 1092616192;
        *((_QWORD *)v15 + 1) = 0i64;
        *((_DWORD *)v15 + 8) = 1065353216;
        v15[72] = 0;
        mNativeIcon->mPolys[3] = (UFG::UIRenderQuad *)v15;
      }
      v12 = mNativeIcon->mPolys[3];
      v12->TextureID = uid_CopRadiusIndicator;
      *(_QWORD *)v12->UVs = 0i64;
      v12->UVs[2] = 1.0;
      v12->UVs[3] = 1.0;
      UFG::UIMapBlipGraphic::SetAlpha(this->mNativeIcon, InteriorRangePoly, a);
      UFG::UIMapBlipGraphic::SetScale(this->mNativeIcon, InteriorRangePoly, v5);
    }
    else
    {
      UFG::UIMapBlipGraphic::RemovePoly(this->mNativeIcon, InteriorRangePoly);
    }
  }
}

// File Line: 613
// RVA: 0xCA650
void __fastcall UFG::UIMapBlip::SetBlinkMaxTimes(UFG::UIMapBlip *this, unsigned int nMaxTimes)
{
  UFG::UIMapBlipGraphic *mNativeIcon; // rax

  mNativeIcon = this->mNativeIcon;
  if ( mNativeIcon )
    mNativeIcon->mBlinkTimesMax = nMaxTimes;
}

// File Line: 620
// RVA: 0xBE550
void __fastcall UFG::UIMapBlip::Blink(UFG::UIMapBlip *this)
{
  bool v1; // zf

  v1 = !this->mShouldBlink;
  this->mShouldBlink = 1;
  this->mChanged |= v1;
}

// File Line: 627
// RVA: 0xC67B0
void __fastcall UFG::UIMapBlip::Pulse(UFG::UIMapBlip *this)
{
  bool v1; // zf

  v1 = !this->mShouldPulse;
  this->mShouldPulse = 1;
  this->mChanged |= v1;
}

// File Line: 641
// RVA: 0xCB970
void __fastcall UFG::UIMapBlip::StopBlink(UFG::UIMapBlip *this)
{
  bool v1; // zf

  v1 = !this->mShouldStopBlink;
  this->mShouldStopBlink = 1;
  this->mChanged |= v1;
}

// File Line: 663
// RVA: 0xC6130
void __fastcall UFG::UIMapBlip::MapToScreen(
        UFG::UITiledMapMath *mapGeo,
        UFG::UITiledMapMath *mapIconGeo,
        UFG::MinimapPoint2f *mapPoint,
        UFG::ScreenPoint2f *screenPoint,
        bool boundIcon,
        bool *touchesEdge)
{
  bool *v6; // rsi
  float MaskRadius; // xmm6_4
  float v10; // xmm6_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm6_4

  v6 = touchesEdge;
  MaskRadius = mapGeo->MaskRadius;
  *touchesEdge = 0;
  v10 = MaskRadius * MaskRadius;
  v11 = mapPoint->y - (float)mapIconGeo->m_rowOffset;
  *(float *)&touchesEdge = mapPoint->x - (float)mapIconGeo->m_colOffset;
  *((float *)&touchesEdge + 1) = v11;
  UFG::ScreenPoint2f::InitFromIconPos(screenPoint, (UFG::MinimapTilePoint2f *)&touchesEdge, mapIconGeo);
  if ( boundIcon && UFG::UITiledMapTweakables::MinimapDebugIconBoundaryTweak )
  {
    v12 = screenPoint->x - mapGeo->CircleMaskX;
    v13 = mapGeo->CircleMaskY - screenPoint->y;
    if ( (float)((float)(v13 * v13) + (float)(v12 * v12)) > v10 )
    {
      *v6 = 1;
      v14 = atan2f(v13, v12);
      screenPoint->x = (float)(cosf(v14) * mapGeo->MaskRadius) + mapGeo->CircleMaskX;
      screenPoint->y = mapGeo->CircleMaskY - (float)(sinf(v14) * mapGeo->MaskRadius);
    }
  }
}

// File Line: 696
// RVA: 0xC0F00
UFG::qColour *__fastcall UFG::UIMapBlip::GetColor(UFG::UIMapBlip *this)
{
  UFG::UIMapBlipGraphic *mNativeIcon; // rax

  mNativeIcon = this->mNativeIcon;
  if ( mNativeIcon )
    return &mNativeIcon->mIconPoly.Color;
  else
    return &UFG::qColour::White;
}

// File Line: 703
// RVA: 0xC0BB0
float __fastcall UFG::UIMapBlip::GetAlpha(UFG::UIMapBlip *this, UFG::qVector3 *playerPos, UFG::UITiledMapMath *mapGeo)
{
  bool IsWorldMap; // r10
  UFG::UIHKMinimapBlipType *mType; // rax
  float v5; // xmm2_4
  bool IsDistanceFilteredOnWorldMap; // r9
  float FilterDistance; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float WorldMapZoomFilter; // xmm4_4

  IsWorldMap = mapGeo->IsWorldMap;
  mType = this->mType;
  v5 = *(float *)&FLOAT_1_0;
  if ( IsWorldMap )
    IsDistanceFilteredOnWorldMap = mType->IsDistanceFilteredOnWorldMap;
  else
    IsDistanceFilteredOnWorldMap = mType->IsDistanceFiltered || this->mUseCustomFilterDistance;
  FilterDistance = mType->FilterDistance;
  if ( this->mUseCustomFilterDistance )
    FilterDistance = this->mCustomFilterDistance;
  if ( IsDistanceFilteredOnWorldMap && !this->mIsSelectedObjective && FilterDistance > 0.0 )
  {
    v8 = FilterDistance * FilterDistance;
    v9 = (float)((float)(this->pos.y - playerPos->y) * (float)(this->pos.y - playerPos->y))
       + (float)((float)(this->pos.x - playerPos->x) * (float)(this->pos.x - playerPos->x));
    if ( v9 > v8 )
      goto LABEL_17;
    if ( v9 <= (float)(v8 * 0.80000001) )
      goto LABEL_18;
    v5 = (float)(v8 - v9) / (float)(v8 * 0.2);
    if ( v5 <= 0.0 )
    {
LABEL_17:
      v5 = 0.0;
      goto LABEL_18;
    }
    if ( v5 >= 1.0 )
      v5 = *(float *)&FLOAT_1_0;
  }
LABEL_18:
  if ( IsWorldMap )
  {
    WorldMapZoomFilter = mType->WorldMapZoomFilter;
    if ( mType->IsWorldMapZoomFiltered && !this->mIsSelectedObjective && WorldMapZoomFilter > 0.0 )
    {
      v5 = v5 * (float)((float)(mapGeo->scale - WorldMapZoomFilter) / (float)(WorldMapZoomFilter * 0.1));
      if ( v5 <= 0.0 )
      {
        return 0.0;
      }
      else if ( v5 >= 1.0 )
      {
        return *(float *)&FLOAT_1_0;
      }
    }
  }
  return v5;
}

// File Line: 851
// RVA: 0xC4470
UFG::Objective *__fastcall UFG::UIMapBlip::GetObjective(UFG::UIMapBlip *this)
{
  UFG::Objective *result; // rax
  Render::SimpleDrawableComponent *ObjectiveFromBlip; // rax

  result = this->mObjective;
  if ( !result )
  {
    if ( UFG::UIHKPlayerObjectiveManager::mInstance
      && (ObjectiveFromBlip = (Render::SimpleDrawableComponent *)UFG::UIHKPlayerObjectiveManager::FindObjectiveFromBlip(
                                                                   UFG::UIHKPlayerObjectiveManager::mInstance,
                                                                   this)) != 0i64 )
    {
      result = (UFG::Objective *)UFG::UIHKPlayerObjective::GetObjective(ObjectiveFromBlip);
      this->mObjective = result;
    }
    else
    {
      return 0i64;
    }
  }
  return result;
}

