// File Line: 71
// RVA: 0xBD670
void __fastcall UFG::UIMapBlip::~UIMapBlip(UFG::UIMapBlip *this)
{
  UFG::UIMapBlipGraphic *v1; // rsi
  UFG::UIMapBlip *v2; // rbp
  void **v3; // rbx
  signed __int64 v4; // rdi
  char *v5; // rcx

  v1 = this->mNativeIcon;
  v2 = this;
  if ( v1 )
  {
    v3 = (void **)&v1->mPolys[1];
    v4 = 4i64;
    v1->vfptr = (UFG::UIMapBlipGraphicVtbl *)&UFG::UIMapBlipGraphic::`vftable';
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
    operator delete[](v1);
  }
  v5 = (char *)v2->mWorldMapCaption;
  if ( v5 )
  {
    operator delete[](v5);
    v2->mWorldMapCaption = 0i64;
  }
}

// File Line: 96
// RVA: 0xBE9E0
void __usercall UFG::UIMapBlip::Clone(UFG::UIMapBlip *this@<rcx>, UFG::UIMapBlip *clone@<rdx>, float a3@<xmm0>)
{
  UFG::UIMapBlip *v3; // rbx
  UFG::UIMapBlip *v4; // rdi
  float v5; // xmm0_4
  float v6; // xmm1_4

  if ( clone )
  {
    v3 = clone;
    v4 = this;
    UFG::UIMapBlip::SetType(this, clone->mType, a3);
    v5 = v3->pos.y;
    v6 = v3->pos.z;
    v4->pos.x = v3->pos.x;
    v4->pos.y = v5;
    v4->pos.z = v6;
    v4->mVisible = v3->mVisible;
    UFG::UIMapBlip::SetWorldMapCaption(v4, v3->mWorldMapCaption);
  }
}

// File Line: 108
// RVA: 0xCDCC0
void __fastcall UFG::UIMapBlip::UpdateNative(UFG::UIMapBlip *this, UFG::qVector3 *playerPos, UFG::UITiledMapMath *mapGeo, UFG::UITiledMapMath *mapIconGeo, UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeClipped, UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeNotClipped, UFG::qArray<UFG::UIRenderQuad,0> *polyListNativeDoubleClipped)
{
  UFG::UITiledMapMath *v7; // rdi
  UFG::UITiledMapMath *v8; // rsi
  UFG::UIMapBlip *v9; // rbx
  float v10; // xmm0_4
  UFG::UIMapBlipGraphic *v11; // rcx
  bool v12; // zf
  float v13; // xmm2_4
  float v14; // xmm4_4
  float v15; // xmm6_4
  float v16; // xmm7_4
  bool boundIcon; // al
  float v18; // xmm11_4
  float v19; // xmm8_4
  float v20; // xmm9_4
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm10_4
  float v24; // xmm0_4
  float v25; // xmm6_4
  float v26; // xmm10_4
  float v27; // xmm9_4
  float v28; // xmm0_4
  UFG::ScreenPoint2f screenPoint; // [rsp+30h] [rbp-78h]
  UFG::MinimapPoint2f mapPoint; // [rsp+B0h] [rbp+8h]

  v7 = mapIconGeo;
  v8 = mapGeo;
  v9 = this;
  if ( this->mType )
  {
    v10 = UFG::UIMapBlip::GetAlpha(this, playerPos, mapGeo);
    v11 = v9->mNativeIcon;
    if ( v11 )
      UFG::UIMapBlipGraphic::SetAlpha(v11, 0, v10);
    if ( v10 >= 0.001 && v9->mNativeIcon )
    {
      v12 = v8->IsWorldMap == 0;
      v13 = 1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX);
      v14 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v13 * UFG::UITiledMapMath::WorldGeo.TextureWidth) ^ _xmm[0]) * v9->pos.y;
      v15 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::UITiledMapMath::WorldGeo.TextureWidth * UFG::UITiledMapMath::WorldGeo.MinX) ^ _xmm[0])
                  * v13)
          + (float)((float)(v13 * UFG::UITiledMapMath::WorldGeo.TextureWidth) * v9->pos.x);
      mapPoint.x = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                          UFG::UITiledMapMath::WorldGeo.TextureWidth
                                        * UFG::UITiledMapMath::WorldGeo.MinX) ^ _xmm[0])
                         * v13)
                 + (float)((float)(v13 * UFG::UITiledMapMath::WorldGeo.TextureWidth) * v9->pos.x);
      v16 = (float)((float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
                  / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY))
          + v14;
      mapPoint.y = (float)((float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
                         / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY))
                 + v14;
      if ( (!v12 || v7->IsWorldMap) && v9->pos.y > 1690.0 && v9->pos.z > 20.0 )
      {
        v15 = v15 + UFG::UITiledMapTweakables::WorldMap_ElectionBlipOffsetX;
        v16 = v16 + UFG::UITiledMapTweakables::WorldMap_ElectionBlipOffsetY;
        mapPoint.x = v15;
        mapPoint.y = v16;
      }
      boundIcon = v9->mBoundIcon;
      v18 = 0.0;
      screenPoint = 0i64;
      UFG::UIMapBlip::MapToScreen(v8, v7, &mapPoint, &screenPoint, boundIcon, &v9->mTouchesEdge);
      if ( v8->IsWorldMap || !v9->mType->HideOnBorder || !v9->mTouchesEdge )
      {
        v19 = screenPoint.y;
        v20 = screenPoint.x;
        ((void (*)(void))v9->mNativeIcon->vfptr->UpdateLocation)();
        ((void (*)(void))v9->mNativeIcon->vfptr->UpdateAnimation)();
        if ( v9->mHasRadius )
        {
          if ( v9->mBoundIcon )
          {
            v21 = v15 - (float)v7->m_colOffset;
            v22 = v16 - (float)v7->m_rowOffset;
            v23 = fsqrt((float)(v21 * v21) + (float)(v22 * v22));
            v24 = atan2f(v22, v21);
            if ( v7->useWideTiles )
              v18 = FLOAT_0_5;
            v25 = v24 + v7->rot;
            v26 = v23 * (float)((float)(UFG::UITiledMapTweakables::MinimapScaleTweak + v7->scale) + v18);
            v27 = cosf(v25);
            v28 = sinf(v25);
            v20 = (float)(v27 * v26) + v7->screenPosition.x;
            v19 = (float)(v28 * v26) + v7->screenPosition.y;
          }
          UFG::UIMapBlipGraphic::SetPos(v9->mNativeIcon, RangePoly, v20, v19);
          UFG::UIMapBlipGraphic::SetPos(v9->mNativeIcon, InteriorRangePoly, v20, v19);
        }
        UFG::UIMapBlipGraphic::QueueIconToRender(
          v9->mNativeIcon,
          polyListNativeClipped,
          polyListNativeNotClipped,
          polyListNativeDoubleClipped);
      }
    }
  }
}

// File Line: 176
// RVA: 0xCC020
void __fastcall UFG::UIMapBlip::Update(UFG::UIMapBlip *this, UFG::UIScreen *screen, UFG::qVector3 *playerPos, UFG::UITiledMapMath *mapGeo)
{
  UFG::UIMapBlip *v4; // rbx
  float v5; // xmm0_4
  signed int v6; // ecx
  bool v7; // zf
  bool v8; // al
  UFG::UIMapBlip::eAltitudeState v9; // eax
  UFG::UIMapBlipGraphic *v10; // rcx
  UFG::UIMapBlipGraphic *v11; // rcx
  UFG::UIMapBlipGraphic *v12; // rcx
  UFG::UIMapBlipGraphic *v13; // rcx

  v4 = this;
  if ( this->mNativeIcon )
  {
    if ( this->mHasAltitude && this->mType->HasAltitude )
    {
      v5 = this->pos.z - playerPos->z;
      this->mAltitudeDiff = v5;
      v6 = 0;
      if ( v5 <= 3.5 )
      {
        if ( v5 < -3.5 )
          v6 = 2;
      }
      else
      {
        v6 = 1;
      }
      v7 = v4->mAltitudeState == v6;
      v4->mAltitudeState = v6;
      v4->mAltitudeStateChanged |= !v7;
      v8 = (float)((float)((float)(v4->pos.y - playerPos->y) * (float)(v4->pos.y - playerPos->y))
                 + (float)((float)(v4->pos.x - playerPos->x) * (float)(v4->pos.x - playerPos->x))) < v4->mAltitudeIconRangeSq;
      if ( v4->mInAltitudeRange != v8 )
      {
        v4->mInAltitudeRange = v8;
        if ( v8 )
          v4->mAltitudeStateChanged = 1;
        else
          UFG::UIMapBlip::SetNormalAltitude(v4);
      }
      if ( v4->mInAltitudeRange && v4->mAltitudeStateChanged )
      {
        v9 = v4->mAltitudeState;
        v4->mAltitudeStateChanged = 0;
        switch ( v9 )
        {
          case 1:
            UFG::UIMapBlip::SetHigherAltitude(v4);
            break;
          case 2:
            UFG::UIMapBlip::SetLowerAltitude(v4);
            break;
          case 0:
            UFG::UIMapBlip::SetNormalAltitude(v4);
            break;
        }
      }
    }
    if ( v4->mChanged )
    {
      v7 = v4->mHasObjectiveHighlight == 0;
      v4->mChanged = 0;
      if ( !v7 )
      {
        v10 = v4->mNativeIcon;
        if ( v10 )
          ((void (__fastcall *)(UFG::UIMapBlipGraphic *, UFG::UIScreen *, UFG::qVector3 *, UFG::UITiledMapMath *))v10->vfptr->SetBlink)(
            v10,
            screen,
            playerPos,
            mapGeo);
      }
      if ( v4->mShouldBlink )
      {
        v11 = v4->mNativeIcon;
        if ( v11 )
        {
          ((void (__fastcall *)(UFG::UIMapBlipGraphic *, UFG::UIScreen *, UFG::qVector3 *, UFG::UITiledMapMath *))v11->vfptr->SetBlink)(
            v11,
            screen,
            playerPos,
            mapGeo);
          *(_DWORD *)&v4->mShouldBlink = 0;
          v4->mShouldStopHighlight = 0;
          return;
        }
      }
      else if ( v4->mShouldPulse )
      {
        v12 = v4->mNativeIcon;
        if ( v12 )
        {
          ((void (__fastcall *)(UFG::UIMapBlipGraphic *, UFG::UIScreen *, UFG::qVector3 *, UFG::UITiledMapMath *))v12->vfptr->SetPulse)(
            v12,
            screen,
            playerPos,
            mapGeo);
          *(_DWORD *)&v4->mShouldBlink = 0;
          v4->mShouldStopHighlight = 0;
          return;
        }
      }
      else if ( !v4->mShouldHighlight && v4->mShouldStopBlink )
      {
        v13 = v4->mNativeIcon;
        if ( v13 )
          ((void (__fastcall *)(UFG::UIMapBlipGraphic *, UFG::UIScreen *, UFG::qVector3 *, UFG::UITiledMapMath *))v13->vfptr->StopBlink)(
            v13,
            screen,
            playerPos,
            mapGeo);
      }
      *(_DWORD *)&v4->mShouldBlink = 0;
      v4->mShouldStopHighlight = 0;
    }
  }
}

// File Line: 280
// RVA: 0xCAE30
void __fastcall UFG::UIMapBlip::SetNormalAltitude(UFG::UIMapBlip *this)
{
  UFG::UIMapBlip *v1; // rbx
  UFG::UIMapBlipGraphic *v2; // rcx

  v1 = this;
  v2 = this->mNativeIcon;
  if ( v2 )
  {
    if ( ((unsigned __int8 (*)(void))v2->vfptr->HasAltitudeIcon)() )
      UFG::UIMapBlipGraphic::RemovePoly(v1->mNativeIcon, AltitudePoly);
  }
}

// File Line: 287
// RVA: 0xCA880
void __fastcall UFG::UIMapBlip::SetHigherAltitude(UFG::UIMapBlip *this)
{
  UFG::UIMapBlip *v1; // rdi
  UFG::UIMapBlipGraphic *v2; // rcx
  UFG::qColour v3; // xmm6
  float v4; // xmm7_4
  UFG::UIMapBlipGraphic *v5; // rbx
  UFG::UIRenderQuad *v6; // rax
  UFG::UIRenderQuad *v7; // rcx
  char *v8; // [rsp+60h] [rbp+8h]
  char *v9; // [rsp+60h] [rbp+8h]
  char *v10; // [rsp+60h] [rbp+8h]

  v1 = this;
  v2 = this->mNativeIcon;
  if ( v2 && ((unsigned __int8 (__cdecl *)(UFG::UIMapBlipGraphic *))v2->vfptr->HasAltitudeIcon)(v2) )
  {
    v3 = UFG::qColour::White;
    v4 = (float)dword_142034218;
    v5 = v1->mNativeIcon;
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
    UFG::UIMapBlipGraphic::SetPolyOffset(v1->mNativeIcon, AltitudePoly, 0, -10);
  }
}

// File Line: 296
// RVA: 0xCACA0
void __fastcall UFG::UIMapBlip::SetLowerAltitude(UFG::UIMapBlip *this)
{
  UFG::UIMapBlip *v1; // rdi
  UFG::UIMapBlipGraphic *v2; // rcx
  UFG::qColour v3; // xmm6
  float v4; // xmm7_4
  UFG::UIMapBlipGraphic *v5; // rbx
  UFG::UIRenderQuad *v6; // rax
  UFG::UIRenderQuad *v7; // rcx
  char *v8; // [rsp+60h] [rbp+8h]
  char *v9; // [rsp+60h] [rbp+8h]
  char *v10; // [rsp+60h] [rbp+8h]

  v1 = this;
  v2 = this->mNativeIcon;
  if ( v2 && ((unsigned __int8 (__cdecl *)(UFG::UIMapBlipGraphic *))v2->vfptr->HasAltitudeIcon)(v2) )
  {
    v3 = UFG::qColour::White;
    v4 = (float)dword_142034218;
    v5 = v1->mNativeIcon;
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
    UFG::UIMapBlipGraphic::SetPolyOffset(v1->mNativeIcon, AltitudePoly, 0, 10);
  }
}

// File Line: 372
// RVA: 0xCB7F0
void __usercall UFG::UIMapBlip::SetType(UFG::UIMapBlip *this@<rcx>, UFG::UIHKMinimapBlipType *type@<rdx>, float a3@<xmm0>)
{
  UFG::UIMapBlip *v3; // rbx
  UFG::UIMapBlipGraphic *v4; // rcx
  UFG::UIMapBlipGraphic *v5; // rax

  v3 = this;
  if ( type != this->mType )
  {
    this->mType = type;
    if ( type )
    {
      if ( !(_S5_2 & 1) )
      {
        _S5_2 |= 1u;
        UFG::qSymbolUC::create_from_string(&invisible_icon, "invisible_icon");
        atexit(UFG::UIMapBlip::SetType_::_8_::_dynamic_atexit_destructor_for__invisible_icon__);
      }
      if ( v3->mType->TypeNameSymbol.mUID == invisible_icon.mUID )
        v3->mBoundIcon = 0;
      v4 = v3->mNativeIcon;
      if ( v4 )
        UFG::UIMapBlipGraphic::`scalar deleting destructor'(v4, 1);
      v5 = UFG::UIMapBlipGraphicFactory::GetNativeIconInstance(
             &UFG::UIMapBlipGraphicFactory::Singleton,
             &v3->mType->Icon);
      v3->mNativeIcon = v5;
      if ( v5 )
        v5->vfptr->AltitudeIconRange(v5);
      else
        a3 = 0.0;
      v3->mAltitudeIconRangeSq = a3 * a3;
      v3->mIconTypeChanged = 1;
    }
  }
}

// File Line: 414
// RVA: 0xCB8F0
void __fastcall UFG::UIMapBlip::SetWorldMapCaption(UFG::UIMapBlip *this, const char *caption)
{
  UFG::UIMapBlip *v2; // rdi
  char *v3; // rcx
  const char *v4; // rsi
  int v5; // eax
  char *v6; // rbx

  v2 = this;
  v3 = (char *)this->mWorldMapCaption;
  v4 = caption;
  if ( v3 )
  {
    operator delete[](v3);
    v2->mWorldMapCaption = 0i64;
  }
  if ( v4 )
  {
    v5 = UFG::qStringLength(v4);
    v6 = UFG::qMalloc(v5 + 1, "UIMapBlip", 0i64);
    UFG::qStringCopy(v6, 0x7FFFFFFF, v4, -1);
    v2->mWorldMapCaption = v6;
  }
}

// File Line: 458
// RVA: 0xC5E10
bool __fastcall UFG::UIMapBlip::IsVisible(UFG::UIMapBlip *this)
{
  UFG::UIHKMinimapBlipType *v1; // rax
  bool result; // al

  result = 0;
  if ( this->mVisible )
  {
    v1 = this->mType;
    if ( v1 )
    {
      if ( v1->IsVisible )
        result = 1;
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
  __m128 v2; // xmm2
  float v3; // xmm3_4
  float v4; // xmm4_4
  float v5; // xmm5_4

  v2 = (__m128)LODWORD(this->pos.y);
  v3 = worldPos->x;
  v4 = worldPos->y;
  v5 = worldPos->z;
  v2.m128_f32[0] = (float)((float)((float)(v2.m128_f32[0] - v4) * (float)(v2.m128_f32[0] - v4))
                         + (float)((float)(this->pos.x - v3) * (float)(this->pos.x - v3)))
                 + (float)((float)(this->pos.z - v5) * (float)(this->pos.z - v5));
  if ( COERCE_FLOAT(_mm_sqrt_ps(v2)) > UFG::gSymbolPosDiff )
  {
    this->pos.x = v3;
    this->pos.y = v4;
    this->pos.z = v5;
    this->mChanged = 1;
  }
}

// File Line: 505
// RVA: 0xC0CB0
float __fastcall UFG::UIMapBlip::GetAlpha(UFG::UIMapBlip *this)
{
  UFG::UIMapBlipGraphic *v1; // rax
  float result; // xmm0_4
  UFG::UIRenderQuad *v3; // rax

  v1 = this->mNativeIcon;
  if ( !v1 )
    return 0.0;
  v3 = v1->mPolys[0];
  if ( v3 )
    result = v3->Color.a;
  else
    result = *(float *)&FLOAT_1_0;
  return result;
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
void __fastcall UFG::UIMapBlip::SetRange(UFG::UIMapBlip *this, bool visible, float radius, UFG::qColour *color, float alphaFactor)
{
  UFG::UIMapBlip *v5; // rdi
  float v6; // xmm6_4
  char v7; // al
  UFG::UIMapBlipGraphic *v8; // rbx
  float v9; // xmm8_4
  float v10; // xmm9_4
  float v11; // xmm10_4
  float v12; // xmm0_4
  float v13; // xmm7_4
  __int128 v14; // xmm0
  UFG::UIRenderQuad *v15; // rax
  UFG::UIRenderQuad *v16; // rcx
  char *v17; // [rsp+B0h] [rbp+8h]
  char *v18; // [rsp+B0h] [rbp+8h]
  char *v19; // [rsp+B0h] [rbp+8h]

  v5 = this;
  v6 = (float)(radius
             / (float)((float)((float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX)
                             / UFG::UITiledMapMath::WorldGeo.TextureWidth)
                     * 88.0))
     * UFG::UITiledMapMath::MapRangeScaleAdjustment;
  this->mChanged |= this->mHasRadius != visible;
  this->mHasRadius = visible;
  v7 = 1;
  if ( v6 == this->radiusScale )
    v7 = 0;
  this->mChanged |= v7;
  this->radiusScale = v6;
  v8 = this->mNativeIcon;
  if ( v8 )
  {
    if ( visible )
    {
      v9 = color->r;
      v10 = color->g;
      v11 = color->b;
      v12 = color->a;
      v13 = alphaFactor * v12;
      if ( !((signed int)(float)(color->r * 255.0) | (((signed int)(float)(color->g * 255.0) | (((signed int)(float)(color->b * 255.0) | ((signed int)(float)(v12 * 255.0) << 8)) << 8)) << 8)) )
      {
        v9 = v8->mIconPoly.Color.r;
        v10 = v8->mIconPoly.Color.g;
        v11 = v8->mIconPoly.Color.b;
        v14 = LODWORD(v8->mIconPoly.Color.a);
        v13 = alphaFactor * 0.15000001;
      }
      if ( !v8->mPolys[2] )
      {
        v17 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
        *((_DWORD *)v17 + 13) = 1092616192;
        *((_QWORD *)v17 + 1) = 0i64;
        *((_DWORD *)v17 + 8) = 1065353216;
        v17[72] = 0;
        v8->mPolys[2] = (UFG::UIRenderQuad *)v17;
      }
      v15 = v8->mPolys[2];
      v15->Color.r = v9;
      v15->Color.g = v10;
      v15->Color.b = v11;
      v15->Color.a = alphaFactor;
      v15->Size = 150.0;
      *(_QWORD *)&v15->X = 0i64;
      *(_QWORD *)&v15->OffsetX = 0i64;
      v15->Visible = 1;
      if ( !v8->mPolys[2] )
      {
        v18 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
        *((_DWORD *)v18 + 13) = 1092616192;
        *((_QWORD *)v18 + 1) = 0i64;
        *((_DWORD *)v18 + 8) = 1065353216;
        v18[72] = 0;
        v8->mPolys[2] = (UFG::UIRenderQuad *)v18;
      }
      v8->mPolys[2]->Color.a = 1.0;
      if ( !v8->mPolys[2] )
      {
        v19 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
        *((_DWORD *)v19 + 13) = 1092616192;
        *((_QWORD *)v19 + 1) = 0i64;
        *((_DWORD *)v19 + 8) = 1065353216;
        v19[72] = 0;
        v8->mPolys[2] = (UFG::UIRenderQuad *)v19;
      }
      v16 = v8->mPolys[2];
      v16->TextureID = uid_CopRadiusIndicator;
      *(_QWORD *)v16->UVs = 0i64;
      v16->UVs[2] = 1.0;
      v16->UVs[3] = 1.0;
      UFG::UIMapBlipGraphic::SetAlpha(v5->mNativeIcon, RangePoly, v13);
      UFG::UIMapBlipGraphic::SetScale(v5->mNativeIcon, RangePoly, v6);
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
  UFG::UIMapBlip *v4; // rdi
  float v5; // xmm6_4
  UFG::UIMapBlipGraphic *v6; // rbx
  float v7; // xmm7_4
  float v8; // xmm8_4
  float v9; // xmm9_4
  float v10; // xmm11_4
  UFG::UIRenderQuad *v11; // rax
  UFG::UIRenderQuad *v12; // rcx
  char *v13; // [rsp+B0h] [rbp+8h]
  char *v14; // [rsp+B0h] [rbp+8h]
  char *v15; // [rsp+B0h] [rbp+8h]

  v4 = this;
  v5 = (float)(radius
             / (float)((float)((float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX)
                             / UFG::UITiledMapMath::WorldGeo.TextureWidth)
                     * 88.0))
     * UFG::UITiledMapMath::MapRangeScaleAdjustment;
  this->mChanged |= this->mHasInteriorRadius != visible;
  this->mHasInteriorRadius = visible;
  v6 = this->mNativeIcon;
  if ( v6 )
  {
    if ( visible )
    {
      v7 = color->r;
      v8 = color->g;
      v9 = color->b;
      v10 = color->a;
      if ( !v6->mPolys[3] )
      {
        v13 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
        *((_DWORD *)v13 + 13) = 1092616192;
        *((_QWORD *)v13 + 1) = 0i64;
        *((_DWORD *)v13 + 8) = 1065353216;
        v13[72] = 0;
        v6->mPolys[3] = (UFG::UIRenderQuad *)v13;
      }
      v11 = v6->mPolys[3];
      v11->Color.r = v7;
      v11->Color.g = v8;
      v11->Color.b = v9;
      LODWORD(v11->Color.a) = (_DWORD)FLOAT_1_0;
      v11->Size = 128.0;
      *(_QWORD *)&v11->X = 0i64;
      *(_QWORD *)&v11->OffsetX = 0i64;
      v11->Visible = 1;
      if ( !v6->mPolys[3] )
      {
        v14 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
        *((_DWORD *)v14 + 13) = 1092616192;
        *((_QWORD *)v14 + 1) = 0i64;
        *((_DWORD *)v14 + 8) = 1065353216;
        v14[72] = 0;
        v6->mPolys[3] = (UFG::UIRenderQuad *)v14;
      }
      v6->mPolys[3]->Color.a = 1.0;
      if ( !v6->mPolys[3] )
      {
        v15 = UFG::qMalloc(0x50ui64, "UIMapBlipGraphic::Quad", 0i64);
        *((_DWORD *)v15 + 13) = 1092616192;
        *((_QWORD *)v15 + 1) = 0i64;
        *((_DWORD *)v15 + 8) = 1065353216;
        v15[72] = 0;
        v6->mPolys[3] = (UFG::UIRenderQuad *)v15;
      }
      v12 = v6->mPolys[3];
      v12->TextureID = uid_CopRadiusIndicator;
      *(_QWORD *)v12->UVs = 0i64;
      v12->UVs[2] = 1.0;
      v12->UVs[3] = 1.0;
      UFG::UIMapBlipGraphic::SetAlpha(v4->mNativeIcon, InteriorRangePoly, v10);
      UFG::UIMapBlipGraphic::SetScale(v4->mNativeIcon, InteriorRangePoly, v5);
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
  UFG::UIMapBlipGraphic *v2; // rax

  v2 = this->mNativeIcon;
  if ( v2 )
    v2->mBlinkTimesMax = nMaxTimes;
}

// File Line: 620
// RVA: 0xBE550
void __fastcall UFG::UIMapBlip::Blink(UFG::UIMapBlip *this)
{
  bool v1; // zf

  v1 = this->mShouldBlink == 0;
  this->mShouldBlink = 1;
  this->mChanged |= v1;
}

// File Line: 627
// RVA: 0xC67B0
void __fastcall UFG::UIMapBlip::Pulse(UFG::UIMapBlip *this)
{
  bool v1; // zf

  v1 = this->mShouldPulse == 0;
  this->mShouldPulse = 1;
  this->mChanged |= v1;
}

// File Line: 641
// RVA: 0xCB970
void __fastcall UFG::UIMapBlip::StopBlink(UFG::UIMapBlip *this)
{
  bool v1; // zf

  v1 = this->mShouldStopBlink == 0;
  this->mShouldStopBlink = 1;
  this->mChanged |= v1;
}

// File Line: 663
// RVA: 0xC6130
void __fastcall UFG::UIMapBlip::MapToScreen(UFG::UITiledMapMath *mapGeo, UFG::UITiledMapMath *mapIconGeo, UFG::MinimapPoint2f *mapPoint, UFG::ScreenPoint2f *screenPoint, bool boundIcon, bool *touchesEdge)
{
  bool *v6; // rsi
  float v7; // xmm6_4
  UFG::UITiledMapMath *v8; // rbx
  UFG::ScreenPoint2f *v9; // rdi
  float v10; // xmm6_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm6_4

  v6 = touchesEdge;
  v7 = mapGeo->MaskRadius;
  v8 = mapGeo;
  v9 = screenPoint;
  *touchesEdge = 0;
  v10 = v7 * v7;
  v11 = mapPoint->y - (float)mapIconGeo->m_rowOffset;
  *(float *)&touchesEdge = mapPoint->x - (float)mapIconGeo->m_colOffset;
  *((float *)&touchesEdge + 1) = v11;
  UFG::ScreenPoint2f::InitFromIconPos(screenPoint, (UFG::MinimapTilePoint2f *)&touchesEdge, mapIconGeo);
  if ( boundIcon && UFG::UITiledMapTweakables::MinimapDebugIconBoundaryTweak )
  {
    v12 = v9->x - v8->CircleMaskX;
    v13 = v8->CircleMaskY - v9->y;
    if ( (float)((float)(v13 * v13) + (float)(v12 * v12)) > v10 )
    {
      *v6 = 1;
      v14 = atan2f(v13, v12);
      v9->x = (float)(cosf(v14) * v8->MaskRadius) + v8->CircleMaskX;
      v9->y = v8->CircleMaskY - (float)(sinf(v14) * v8->MaskRadius);
    }
  }
}

// File Line: 696
// RVA: 0xC0F00
UFG::qColour *__fastcall UFG::UIMapBlip::GetColor(UFG::UIMapBlip *this)
{
  UFG::UIMapBlipGraphic *v1; // rax
  UFG::qColour *result; // rax

  v1 = this->mNativeIcon;
  if ( v1 )
    result = &v1->mIconPoly.Color;
  else
    result = &UFG::qColour::White;
  return result;
}

// File Line: 703
// RVA: 0xC0BB0
float __fastcall UFG::UIMapBlip::GetAlpha(UFG::UIMapBlip *this, UFG::qVector3 *playerPos, UFG::UITiledMapMath *mapGeo)
{
  bool v3; // r10
  UFG::UIHKMinimapBlipType *v4; // rax
  float v5; // xmm2_4
  bool v6; // r9
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm4_4

  v3 = mapGeo->IsWorldMap;
  v4 = this->mType;
  v5 = *(float *)&FLOAT_1_0;
  if ( v3 )
    v6 = v4->IsDistanceFilteredOnWorldMap;
  else
    v6 = v4->IsDistanceFiltered || this->mUseCustomFilterDistance;
  v7 = v4->FilterDistance;
  if ( this->mUseCustomFilterDistance )
    v7 = this->mCustomFilterDistance;
  if ( v6 && !this->mIsSelectedObjective && v7 > 0.0 )
  {
    v8 = v7 * v7;
    v9 = (float)((float)(this->pos.y - playerPos->y) * (float)(this->pos.y - playerPos->y))
       + (float)((float)(this->pos.x - playerPos->x) * (float)(this->pos.x - playerPos->x));
    if ( v9 > v8 )
      goto LABEL_29;
    if ( v9 <= (float)(v8 * 0.80000001) )
      goto LABEL_18;
    v5 = (float)(v8 - v9) / (float)(v8 * 0.2);
    if ( v5 <= 0.0 )
    {
LABEL_29:
      v5 = 0.0;
      goto LABEL_18;
    }
    if ( v5 >= 1.0 )
      v5 = *(float *)&FLOAT_1_0;
  }
LABEL_18:
  if ( v3 )
  {
    v10 = v4->WorldMapZoomFilter;
    if ( v4->IsWorldMapZoomFiltered )
    {
      if ( !this->mIsSelectedObjective && v10 > 0.0 )
      {
        v5 = v5 * (float)((float)(mapGeo->scale - v10) / (float)(v10 * 0.1));
        if ( v5 <= 0.0 )
        {
          v5 = 0.0;
        }
        else if ( v5 >= 1.0 )
        {
          return *(float *)&FLOAT_1_0;
        }
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
  UFG::UIMapBlip *v2; // rbx
  Render::SimpleDrawableComponent *v3; // rax

  result = this->mObjective;
  v2 = this;
  if ( !result )
  {
    if ( UFG::UIHKPlayerObjectiveManager::mInstance
      && (v3 = (Render::SimpleDrawableComponent *)UFG::UIHKPlayerObjectiveManager::FindObjectiveFromBlip(
                                                    UFG::UIHKPlayerObjectiveManager::mInstance,
                                                    this)) != 0i64 )
    {
      result = (UFG::Objective *)UFG::UIHKPlayerObjective::GetObjective(v3);
      v2->mObjective = result;
    }
    else
    {
      result = 0i64;
    }
  }
  return result;
}

