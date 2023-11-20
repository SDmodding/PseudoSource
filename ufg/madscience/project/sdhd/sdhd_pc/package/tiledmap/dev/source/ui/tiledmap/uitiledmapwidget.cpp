// File Line: 89
// RVA: 0xBD160
void __fastcall UFG::UITiledMapWidget::UITiledMapWidget(UFG::UITiledMapWidget *this)
{
  this->m_mapGeo.screenPosition = 0i64;
  this->m_mapGeo.centerPosition = 0i64;
  *(_QWORD *)&this->m_mapGeo.rot = 0i64;
  this->m_mapGeo.scale = 1.0;
  *(_WORD *)&this->m_mapGeo.useWideTiles = 256;
  *(_QWORD *)&this->m_mapGeo.CircleMaskX = 0i64;
  this->m_mapGeo.MaskRadius = 100.0;
  this->m_mapGeo.IsWorldMap = 0;
  *(_WORD *)&this->mIsWorldMap = 256;
  this->m_prevGeo.screenPosition = 0i64;
  this->m_prevGeo.centerPosition = 0i64;
  *(_QWORD *)&this->m_prevGeo.rot = 0i64;
  this->m_prevGeo.scale = 1.0;
  *(_WORD *)&this->m_prevGeo.useWideTiles = 256;
  *(_QWORD *)&this->m_prevGeo.CircleMaskX = 0i64;
  this->m_prevGeo.MaskRadius = 100.0;
  this->m_prevGeo.IsWorldMap = 0;
  this->m_mapIconGeo.screenPosition = 0i64;
  this->m_mapIconGeo.centerPosition = 0i64;
  *(_QWORD *)&this->m_mapIconGeo.rot = 0i64;
  this->m_mapIconGeo.scale = 1.0;
  *(_WORD *)&this->m_mapIconGeo.useWideTiles = 256;
  *(_QWORD *)&this->m_mapIconGeo.CircleMaskX = 0i64;
  this->m_mapIconGeo.MaskRadius = 100.0;
  this->m_mapIconGeo.IsWorldMap = 0;
  this->ZoomCalc.mScale = 1.0;
  this->ZoomCalc.mInteriorActiveLastFrame = 0;
  this->ZoomCalc.mZoomHistoryIndex = 0;
  if ( UFG::UITiledMapZoomCalc::gScaleIsLocked )
    this->ZoomCalc.mScale = UFG::UITiledMapZoomCalc::gLockedScale;
  *(_QWORD *)this->ZoomCalc.mZoomHistory = 0i64;
  *(_QWORD *)&this->ZoomCalc.mZoomHistory[2] = 0i64;
  *(_QWORD *)&this->ZoomCalc.mZoomHistory[4] = 0i64;
  *(_QWORD *)&this->ZoomCalc.mZoomHistory[6] = 0i64;
  *(_QWORD *)&this->ZoomCalc.mZoomHistory[8] = 0i64;
  *(_QWORD *)&this->ZoomCalc.mZoomHistory[10] = 0i64;
  this->forceUpdate = 0;
  *(_QWORD *)&this->mAlpha = 0i64;
  this->PolyListNativeClipped.p = 0i64;
  this->PolyListNativeClipped.capacity = 0;
  this->PolyListNativeDoubleClipped.p = 0i64;
  *(_QWORD *)&this->PolyListNativeDoubleClipped.size = 0i64;
  this->PolyListNativeNotClipped.p = 0i64;
  *(_QWORD *)&this->PolyListNativeNotClipped.size = 0i64;
  this->mViewportScale = 1.0;
  this->mViewportScaleH = 1.0;
  this->mViewportScaleV = 1.0;
}

// File Line: 97
// RVA: 0xC5940
void __fastcall UFG::UITiledMapWidget::Init(UFG::UITiledMapWidget *this, UFG::UIScreen *screen)
{
  UFG::UITiledMapWidget *v2; // rbx
  UFG::qMatrix44 *v3; // rcx
  UFG::UIScreen *v4; // rdi

  this->mAlpha = 0.0;
  this->m_prevGeo.rot = -1000.0;
  this->m_prevGeo.playerRot = -1000.0;
  this->m_prevGeo.screenPosition.x = -15000.0;
  this->m_prevGeo.screenPosition.y = -15000.0;
  v2 = this;
  this->mViewportScale = UFG::gUIViewportScale;
  v3 = &this->mViewportScaleMatrix;
  v4 = screen;
  v3[1].v0.y = UFG::gUIViewportScaleH;
  v3[1].v0.z = UFG::gUIViewportScaleV;
  UFG::UIGetViewportScaleMatrix(v3, screen);
  if ( !v2->mIsWorldMap )
    UFG::UITiledMapWidget::Flash_GetWidgetScreenPosition(v2, v4);
}

// File Line: 125
// RVA: 0xCC8C0
void __fastcall UFG::UITiledMapWidget::Update(UFG::UITiledMapWidget *this, UFG::UIScreen *screen, float elapsed, UFG::UIMapBlipManager *blipMan, UFG::UIMapInteriorManager *interiorMan, UFG::UITiledMapTextureManager *textureMan, UFG::UITiledMapTextureManager *wideTextureMan, UFG::UITiledMapGPS *gps)
{
  UFG::UIScreen *v8; // r15
  UFG::UITiledMapWidget *v9; // rdi
  float v10; // xmm0_4
  UFG::qMatrix44 *v11; // rcx
  UFG::UIScreenRenderable *v12; // rax
  Scaleform::GFx::Movie *v13; // rcx
  UFG::SimObjectCharacter *v14; // rax
  UFG::TransformNodeComponent *v15; // r14
  unsigned __int16 v16; // dx
  UFG::SimComponent *v17; // rsi
  UFG::SimComponent *v18; // rax
  _DWORD *v19; // r12
  bool v20; // zf
  float v21; // eax
  float v22; // xmm1_4
  float v23; // xmm0_4
  UFG::BaseCameraComponent *v24; // rax
  signed __int64 v25; // rax
  int v26; // xmm1_4
  int v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm3_4
  float i; // xmm6_4
  float v33; // eax
  float v34; // xmm3_4
  float v35; // xmm5_4
  float v36; // xmm9_4
  UFG::UIAmbientMapBlipManager *v37; // rax
  bool forceUpdate; // ST50_1
  UFG::qVector3 v1; // [rsp+60h] [rbp-79h]
  UFG::qVector3 v40; // [rsp+70h] [rbp-69h]
  UFG::qVector3 v2; // [rsp+80h] [rbp-59h]
  UFG::MinimapPoint2f pos; // [rsp+120h] [rbp+47h]
  UFG::UIMapBlipManager *iconMan; // [rsp+138h] [rbp+5Fh]

  iconMan = blipMan;
  v8 = screen;
  v9 = this;
  if ( UFG::gUIViewportScale != this->mViewportScale
    || UFG::gUIViewportScaleH != this->mViewportScaleH
    || UFG::gUIViewportScaleV != this->mViewportScaleV )
  {
    this->mViewportScale = UFG::gUIViewportScale;
    v10 = UFG::gUIViewportScaleH;
    v11 = &this->mViewportScaleMatrix;
    v11[1].v0.y = UFG::gUIViewportScaleH;
    v11[1].v0.z = UFG::gUIViewportScaleV;
    UFG::UIGetViewportScaleMatrix(v11, screen, v10);
  }
  v12 = v8->mRenderable;
  if ( v12 )
  {
    if ( v12->m_shouldRender )
    {
      v13 = v12->m_movie.pObject;
      if ( v13 )
      {
        if ( ((unsigned __int8 (*)(void))v13->vfptr[10].__vecDelDtor)() )
        {
          v14 = UFG::GetLocalPlayer();
          if ( v14 )
          {
            v15 = v14->m_pTransformNodeComponent;
            if ( v15 )
            {
              v16 = v14->m_Flags;
              if ( (v14->m_Flags >> 14) & 1 )
              {
                v17 = v14->m_Components.p[44].m_pComponent;
              }
              else
              {
                if ( (v16 & 0x8000u) == 0 )
                {
                  if ( (v16 >> 13) & 1 )
                  {
                    v18 = UFG::SimObjectGame::GetComponentOfTypeHK(
                            (UFG::SimObjectGame *)&v14->vfptr,
                            UFG::CharacterOccupantComponent::_TypeUID);
                  }
                  else if ( (v16 >> 12) & 1 )
                  {
                    v18 = UFG::SimObjectGame::GetComponentOfTypeHK(
                            (UFG::SimObjectGame *)&v14->vfptr,
                            UFG::CharacterOccupantComponent::_TypeUID);
                  }
                  else
                  {
                    v18 = UFG::SimObject::GetComponentOfType(
                            (UFG::SimObject *)&v14->vfptr,
                            UFG::CharacterOccupantComponent::_TypeUID);
                  }
                }
                else
                {
                  v18 = UFG::SimObjectGame::GetComponentOfTypeHK(
                          (UFG::SimObjectGame *)&v14->vfptr,
                          UFG::CharacterOccupantComponent::_TypeUID);
                }
                v17 = v18;
              }
              UFG::TransformNodeComponent::UpdateWorldTransform(v15);
              v19 = (_DWORD *)&v15->mWorldTransform.v3.x;
              UFG::UIMapInteriorManager::Update(
                interiorMan,
                v8,
                (UFG::qVector3 *)&v15->mWorldTransform.v3,
                v9,
                textureMan);
              v20 = gps->mInteriorActive == interiorMan->mActive;
              gps->mInteriorActive = interiorMan->mActive;
              gps->mChanged |= !v20;
              UFG::TransformNodeComponent::UpdateWorldTransform(v15);
              UFG::UITiledMapZoomCalc::Update(&v9->ZoomCalc, elapsed, &v15->mWorldVelocity, v17 == 0i64, interiorMan);
              v21 = v9->ZoomCalc.mScale;
              v9->forceUpdate = 0;
              v2.x = 0.0;
              *(_QWORD *)&v2.y = 1065353216i64;
              v9->m_mapGeo.scale = v21;
              UFG::TransformNodeComponent::UpdateWorldTransform(v15);
              v22 = v15->mWorldTransform.v0.y;
              v23 = v15->mWorldTransform.v0.x;
              v40.z = 0.0;
              v40.x = v23;
              v40.y = v22;
              v24 = UFG::Director::Get()->mCurrentCamera;
              if ( v24 )
                v25 = (signed __int64)&v24->mCamera;
              else
                v25 = 0i64;
              v26 = *(_DWORD *)(v25 + 164);
              v27 = *(_DWORD *)(v25 + 160);
              v1.z = 0.0;
              LODWORD(v1.x) = v27 ^ _xmm[0];
              LODWORD(v1.y) = v26 ^ _xmm[0];
              v28 = UFG::qAngleBetween(&v1, &v2);
              v29 = v1.x;
              v9->m_mapGeo.rot = v28;
              if ( v29 > 0.0 )
                LODWORD(v9->m_mapGeo.rot) = LODWORD(v28) ^ _xmm[0];
              v30 = UFG::qAngleBetween(&v40, &v1);
              v31 = FLOAT_N1_0;
              if ( (float)((float)(v40.y * v1.x) - (float)(v1.y * v40.x)) < 0.0 )
                v31 = *(float *)&FLOAT_1_0;
              for ( i = (float)((float)(v30 * 180.0) * 0.31830987) * v31; i < -180.0; i = i + 360.0 )
                ;
              for ( ; i > 180.0; i = i + -360.0 )
                ;
              if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)v19 - v9->m_prevGeo.centerPosition.x) & _xmm) > UFG::UITiledMapTweakables::PlayerPosDiff
                || COERCE_FLOAT(COERCE_UNSIGNED_INT(v15->mWorldTransform.v3.y - v9->m_prevGeo.centerPosition.y) & _xmm) > UFG::UITiledMapTweakables::PlayerPosDiff
                || COERCE_FLOAT(COERCE_UNSIGNED_INT(v9->m_mapGeo.rot - v9->m_prevGeo.rot) & _xmm) > UFG::UITiledMapTweakables::CameraHeadingDiff
                || COERCE_FLOAT(COERCE_UNSIGNED_INT(i - v9->m_prevGeo.playerRot) & _xmm) > UFG::UITiledMapTweakables::PlayerHeadingDiff
                || COERCE_FLOAT(COERCE_UNSIGNED_INT(v9->m_mapGeo.scale - v9->m_prevGeo.scale) & _xmm) > UFG::UITiledMapTweakables::MapScaleDiff
                || UFG::UITiledMapTweakables::MinimapForceUpdateEveryFrame )
              {
                v33 = v9->m_mapGeo.screenPosition.x;
                v9->forceUpdate = 1;
                v9->m_prevGeo.screenPosition.x = v33;
                v9->m_prevGeo.screenPosition.y = v9->m_mapGeo.screenPosition.y;
                v9->m_prevGeo.centerPosition.x = v9->m_mapGeo.centerPosition.x;
                v9->m_prevGeo.centerPosition.y = v9->m_mapGeo.centerPosition.y;
                v9->m_prevGeo.rot = v9->m_mapGeo.rot;
                v9->m_prevGeo.playerRot = v9->m_mapGeo.playerRot;
                v9->m_prevGeo.scale = v9->m_mapGeo.scale;
                *(_DWORD *)&v9->m_prevGeo.useWideTiles = *(_DWORD *)&v9->m_mapGeo.useWideTiles;
                v9->m_prevGeo.CircleMaskX = v9->m_mapGeo.CircleMaskX;
                v9->m_prevGeo.CircleMaskY = v9->m_mapGeo.CircleMaskY;
                v9->m_prevGeo.MaskRadius = v9->m_mapGeo.MaskRadius;
                v9->m_prevGeo.m_rowOffset = v9->m_mapGeo.m_rowOffset;
                v9->m_prevGeo.m_colOffset = v9->m_mapGeo.m_colOffset;
                *(_DWORD *)&v9->m_prevGeo.IsWorldMap = *(_DWORD *)&v9->m_mapGeo.IsWorldMap;
              }
              v34 = *(float *)v19;
              v35 = v15->mWorldTransform.v3.y;
              v9->m_mapGeo.centerPosition = (UFG::WorldPoint2f)__PAIR__(LODWORD(v35), *v19);
              v36 = 1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX);
              pos.x = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                             UFG::UITiledMapMath::WorldGeo.TextureWidth
                                           * UFG::UITiledMapMath::WorldGeo.MinX) ^ _xmm[0])
                            * v36)
                    + (float)((float)(v36 * UFG::UITiledMapMath::WorldGeo.TextureWidth) * v34);
              pos.y = (float)((float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
                            / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY))
                    + (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v36 * UFG::UITiledMapMath::WorldGeo.TextureWidth) ^ _xmm[0])
                            * v35);
              UFG::UITiledMapWidget::setMapPosition(v9, pos, i, textureMan, wideTextureMan, 0);
              v37 = UFG::UIAmbientMapBlipManager::getInstance();
              UFG::UIAmbientMapBlipManager::Update(v37, elapsed, iconMan, 0);
              forceUpdate = v9->forceUpdate;
              v9->PolyListNativeClipped.size = 0;
              v9->PolyListNativeNotClipped.size = 0;
              v9->PolyListNativeDoubleClipped.size = 0;
              UFG::UIMapBlipManager::Update(
                iconMan,
                v8,
                elapsed,
                (UFG::qVector3 *)&v15->mWorldTransform.v3,
                &v9->m_mapGeo,
                &v9->m_mapIconGeo,
                &v9->PolyListNativeClipped,
                &v9->PolyListNativeNotClipped,
                &v9->PolyListNativeDoubleClipped,
                interiorMan->mActive,
                forceUpdate);
              UFG::UITiledMapGPS::Update(gps, elapsed, v8, &v9->m_mapIconGeo);
            }
          }
        }
      }
    }
  }
}

// File Line: 237
// RVA: 0xCEA10
void __fastcall UFG::UITiledMapWidget::UpdateWorldMap(UFG::UITiledMapWidget *this, UFG::UIScreen *screen, UFG::UITiledMapMath *mapGeo)
{
  UFG::UITiledMapMath *v3; // rdi
  UFG::UITiledMapWidget *v4; // rbx
  float v5; // xmm0_4
  UFG::qMatrix44 *v6; // rcx

  v3 = mapGeo;
  v4 = this;
  if ( UFG::gUIViewportScale != this->mViewportScale
    || UFG::gUIViewportScaleH != this->mViewportScaleH
    || UFG::gUIViewportScaleV != this->mViewportScaleV )
  {
    this->mViewportScale = UFG::gUIViewportScale;
    v5 = UFG::gUIViewportScaleH;
    v6 = &this->mViewportScaleMatrix;
    v6[1].v0.y = UFG::gUIViewportScaleH;
    v6[1].v0.z = UFG::gUIViewportScaleV;
    UFG::UIGetViewportScaleMatrix(v6, screen, v5);
  }
  v4->m_mapGeo.screenPosition.x = v3->screenPosition.x;
  v4->m_mapGeo.screenPosition.y = v3->screenPosition.y;
  v4->m_mapGeo.centerPosition.x = v3->centerPosition.x;
  v4->m_mapGeo.centerPosition.y = v3->centerPosition.y;
  v4->m_mapGeo.rot = v3->rot;
  v4->m_mapGeo.playerRot = v3->playerRot;
  v4->m_mapGeo.scale = v3->scale;
  *(_DWORD *)&v4->m_mapGeo.useWideTiles = *(_DWORD *)&v3->useWideTiles;
  v4->m_mapGeo.CircleMaskX = v3->CircleMaskX;
  v4->m_mapGeo.CircleMaskY = v3->CircleMaskY;
  v4->m_mapGeo.MaskRadius = v3->MaskRadius;
  v4->m_mapGeo.m_rowOffset = v3->m_rowOffset;
  v4->m_mapGeo.m_colOffset = v3->m_colOffset;
  *(_DWORD *)&v4->m_mapGeo.IsWorldMap = *(_DWORD *)&v3->IsWorldMap;
}

// File Line: 259
// RVA: 0xC7330
void __fastcall UFG::UITiledMapWidget::Render(UFG::UITiledMapWidget *this, Render::View *view, UFG::UIMapBlipManager *blipMan, UFG::UIMapInteriorManager *interiorMan, UFG::UITiledMapGPS *GPS, UFG::UIMapLinesWidget *MapLines, UFG::UITiledMapRaceSplines *RacePath)
{
  UFG::UIMapBlipManager *v7; // rbp
  Render::View *v8; // rsi
  UFG::UITiledMapWidget *v9; // rdi
  float v10; // xmm1_4
  unsigned int v11; // er8
  UFG::qColour v12; // [rsp+30h] [rbp-18h]

  v7 = blipMan;
  v8 = view;
  v9 = this;
  UFG::UITiledMapWidget::RenderNorth(this, view);
  UFG::UITiledMapWidget::RenderBlipRanges(v9, v8);
  if ( UFG::UITiledMapWidget::gMinimapRaceRouteVisible )
  {
    v10 = v9->mAlpha;
    v11 = RacePath->m_NumSplinePoints;
    v12 = UFG::UITiledMapWidget::RaceRouteColor;
    v12.a = v10;
    _mm_store_si128((__m128i *)&v12, (__m128i)v12);
    UFG::UITiledMapWidget::RenderSpline(v9, &RacePath->m_SplinePoints, v11, &v12, v8);
  }
  else if ( !GPS->mActive
         || GPS->mInteriorActive
         || GPS->mOnlyShowInVehicles && !UFG::UI::IsPlayerInVehicle()
         || UFG::UI::IsPlayerInWater()
         || !GPS->mVisible )
  {
    if ( UI_BLIP_GPS_DESTINATION && UFG::qBaseTreeRB::Get(&v7->mIconList.mIconData.mTree, UI_BLIP_GPS_DESTINATION) )
      UFG::UIMapBlipManager::RemoveIcon(v7, UI_BLIP_GPS_DESTINATION);
  }
  else
  {
    UFG::UITiledMapWidget::RenderGPSSpline(v9, v8, GPS, v7);
  }
  UFG::UITiledMapWidget::RenderBlips(v9, v8);
}

// File Line: 459
// RVA: 0xBFAD0
void __fastcall UFG::DrawClippedPolys(Render::View *view, UFG::ClipRect *rects, int rect_count, UFG::qColour *Color, unsigned int TextureUID, const unsigned int AlphaStateUID, unsigned int RasterStateUID, UFG::qMatrix44 *TransformMatrix)
{
  UFG::ClipRect *v8; // rdi
  Render::View *v9; // r14
  UFG::qColour *v10; // rbp
  __int64 v11; // rsi
  Illusion::Material *v12; // r15
  float *v13; // rbx
  Render::vDynamic *v14; // rax
  float v15; // xmm6_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm6_4
  Render::vDynamic *v19; // rax
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  Render::vDynamic *v24; // rax
  float v25; // xmm2_4
  float v26; // xmm6_4
  Render::vDynamic *v27; // rax
  float v28; // xmm2_4
  float v29; // xmm6_4
  Render::Poly poly; // [rsp+30h] [rbp-48h]

  v8 = rects;
  v9 = view;
  v10 = Color;
  v11 = rect_count;
  v12 = Render::View::CreateSimpleMaterial(TextureUID, RasterStateUID, AlphaStateUID, 0);
  if ( (signed int)v11 > 0 )
  {
    v13 = &v8->y0;
    do
    {
      Render::Poly::Poly(&poly, *(v13 - 4), *v13, *(v13 - 2) - *(v13 - 4), v13[2] - *v13, 0.0);
      Render::Poly::SetColour(&poly, v10);
      Render::Poly::SetUVs(&poly, *(v13 - 3), v13[1], *(v13 - 1) - *(v13 - 3), v13[3] - v13[1]);
      if ( TransformMatrix )
      {
        v14 = poly.mVertices;
        v15 = poly.mVertices->mPosition.y;
        v16 = v15;
        v17 = (float)((float)((float)(poly.mVertices->mPosition.y * TransformMatrix->v1.y)
                            + (float)(poly.mVertices->mPosition.x * TransformMatrix->v0.y))
                    + (float)(poly.mVertices->mPosition.z * TransformMatrix->v2.y))
            + TransformMatrix->v3.y;
        v18 = (float)((float)((float)(v15 * TransformMatrix->v1.z)
                            + (float)(poly.mVertices->mPosition.x * TransformMatrix->v0.z))
                    + (float)(poly.mVertices->mPosition.z * TransformMatrix->v2.z))
            + TransformMatrix->v3.z;
        poly.mVertices->mPosition.x = (float)((float)((float)(poly.mVertices->mPosition.x * TransformMatrix->v0.x)
                                                    + (float)(v16 * TransformMatrix->v1.x))
                                            + (float)(poly.mVertices->mPosition.z * TransformMatrix->v2.x))
                                    + TransformMatrix->v3.x;
        v14->mPosition.y = v17;
        v14->mPosition.z = v18;
        v19 = poly.mVertices;
        v20 = poly.mVertices[1].mPosition.y;
        v21 = v20;
        v22 = (float)((float)((float)(poly.mVertices[1].mPosition.y * TransformMatrix->v1.y)
                            + (float)(poly.mVertices[1].mPosition.x * TransformMatrix->v0.y))
                    + (float)(poly.mVertices[1].mPosition.z * TransformMatrix->v2.y))
            + TransformMatrix->v3.y;
        v23 = (float)((float)((float)(v20 * TransformMatrix->v1.z)
                            + (float)(poly.mVertices[1].mPosition.x * TransformMatrix->v0.z))
                    + (float)(poly.mVertices[1].mPosition.z * TransformMatrix->v2.z))
            + TransformMatrix->v3.z;
        poly.mVertices[1].mPosition.x = (float)((float)((float)(poly.mVertices[1].mPosition.x * TransformMatrix->v0.x)
                                                      + (float)(v21 * TransformMatrix->v1.x))
                                              + (float)(poly.mVertices[1].mPosition.z * TransformMatrix->v2.x))
                                      + TransformMatrix->v3.x;
        v19[1].mPosition.y = v22;
        v19[1].mPosition.z = v23;
        v24 = poly.mVertices;
        v25 = (float)((float)((float)(poly.mVertices[2].mPosition.y * TransformMatrix->v1.y)
                            + (float)(poly.mVertices[2].mPosition.x * TransformMatrix->v0.y))
                    + (float)(poly.mVertices[2].mPosition.z * TransformMatrix->v2.y))
            + TransformMatrix->v3.y;
        v26 = (float)((float)((float)(poly.mVertices[2].mPosition.y * TransformMatrix->v1.z)
                            + (float)(poly.mVertices[2].mPosition.x * TransformMatrix->v0.z))
                    + (float)(poly.mVertices[2].mPosition.z * TransformMatrix->v2.z))
            + TransformMatrix->v3.z;
        poly.mVertices[2].mPosition.x = (float)((float)((float)(poly.mVertices[2].mPosition.x * TransformMatrix->v0.x)
                                                      + (float)(poly.mVertices[2].mPosition.y * TransformMatrix->v1.x))
                                              + (float)(poly.mVertices[2].mPosition.z * TransformMatrix->v2.x))
                                      + TransformMatrix->v3.x;
        v24[2].mPosition.y = v25;
        v24[2].mPosition.z = v26;
        v27 = poly.mVertices;
        v28 = (float)((float)((float)(poly.mVertices[3].mPosition.y * TransformMatrix->v1.y)
                            + (float)(poly.mVertices[3].mPosition.x * TransformMatrix->v0.y))
                    + (float)(poly.mVertices[3].mPosition.z * TransformMatrix->v2.y))
            + TransformMatrix->v3.y;
        v29 = (float)((float)((float)(poly.mVertices[3].mPosition.y * TransformMatrix->v1.z)
                            + (float)(poly.mVertices[3].mPosition.x * TransformMatrix->v0.z))
                    + (float)(poly.mVertices[3].mPosition.z * TransformMatrix->v2.z))
            + TransformMatrix->v3.z;
        poly.mVertices[3].mPosition.x = (float)((float)((float)(poly.mVertices[3].mPosition.x * TransformMatrix->v0.x)
                                                      + (float)(poly.mVertices[3].mPosition.y * TransformMatrix->v1.x))
                                              + (float)(poly.mVertices[3].mPosition.z * TransformMatrix->v2.x))
                                      + TransformMatrix->v3.x;
        v27[3].mPosition.y = v28;
        v27[3].mPosition.z = v29;
      }
      poly.mVertices->mPosition.x = poly.mVertices->mPosition.x
                                  / (float)(signed int)UFG::UIScreenManager::s_instance->m_flashWidth;
      poly.mVertices->mPosition.y = poly.mVertices->mPosition.y
                                  / (float)(signed int)UFG::UIScreenManager::s_instance->m_flashHeight;
      poly.mVertices[1].mPosition.x = poly.mVertices[1].mPosition.x
                                    / (float)(signed int)UFG::UIScreenManager::s_instance->m_flashWidth;
      poly.mVertices[1].mPosition.y = poly.mVertices[1].mPosition.y
                                    / (float)(signed int)UFG::UIScreenManager::s_instance->m_flashHeight;
      poly.mVertices[2].mPosition.x = poly.mVertices[2].mPosition.x
                                    / (float)(signed int)UFG::UIScreenManager::s_instance->m_flashWidth;
      poly.mVertices[2].mPosition.y = poly.mVertices[2].mPosition.y
                                    / (float)(signed int)UFG::UIScreenManager::s_instance->m_flashHeight;
      poly.mVertices[3].mPosition.x = poly.mVertices[3].mPosition.x
                                    / (float)(signed int)UFG::UIScreenManager::s_instance->m_flashWidth;
      poly.mVertices[3].mPosition.y = poly.mVertices[3].mPosition.y
                                    / (float)(signed int)UFG::UIScreenManager::s_instance->m_flashHeight;
      Render::View::Draw(v9, &poly, v12, 0i64);
      v13 += 10;
      --v11;
    }
    while ( v11 );
  }
}

// File Line: 500
// RVA: 0xBF7E0
void __fastcall UFG::UITiledMapWidget::DrawClipRects(UFG::UITiledMapWidget *this, Render::View *view, UFG::qColour *Color, const unsigned int AlphaStateUID, unsigned int RasterStateUID, UFG::qMatrix44 *TransformMatrix)
{
  UFG::UITiledMapWidget *v6; // rbx
  unsigned int v7; // er14
  UFG::qColour *v8; // r15
  Render::View *v9; // r12
  __int64 v10; // rdi
  float v11; // xmm2_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  UFG::qBaseTreeRB *i; // rdx
  signed __int64 v15; // r8
  float v16; // xmm0_4
  float v17; // xmm5_4
  UFG::qBaseNodeRB *v18; // rcx
  __m128i v19; // xmm1
  unsigned int v20; // eax
  float v21; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  __m128i v25; // xmm0
  signed int v26; // eax
  float v27; // xmm5_4
  float v28; // xmm2_4
  float v29; // xmm2_4
  int *v30; // rbx
  __int128 v31; // xmm1
  int v32; // [rsp+40h] [rbp-C68h]
  int v33; // [rsp+44h] [rbp-C64h]
  int v34; // [rsp+48h] [rbp-C60h]
  int v35; // [rsp+4Ch] [rbp-C5Ch]
  int v36; // [rsp+50h] [rbp-C58h]
  int v37; // [rsp+54h] [rbp-C54h]
  int v38; // [rsp+58h] [rbp-C50h]
  int v39; // [rsp+5Ch] [rbp-C4Ch]
  __int64 v40[32]; // [rsp+60h] [rbp-C48h]
  UFG::ClipRect rects; // [rsp+160h] [rbp-B48h]

  v6 = this;
  v7 = AlphaStateUID;
  v8 = Color;
  v9 = view;
  v10 = 0i64;
  v11 = 1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX);
  v12 = (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::UITiledMapMath::WorldGeo.TextureWidth * UFG::UITiledMapMath::WorldGeo.MinX) ^ _xmm[0])
                      * v11)
              + (float)((float)(v11 * UFG::UITiledMapMath::WorldGeo.TextureWidth) * this->m_mapGeo.centerPosition.x))
      - (float)this->m_mapGeo.m_colOffset;
  v13 = (float)((float)((float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
                      / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY))
              + (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v11 * UFG::UITiledMapMath::WorldGeo.TextureWidth) ^ _xmm[0])
                      * this->m_mapGeo.centerPosition.y))
      - (float)this->m_mapGeo.m_rowOffset;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_14249BD10);
        i;
        i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_14249BD10, &i->mRoot) )
  {
    if ( (unsigned int)v10 >= 7 )
      break;
    v15 = 5 * v10;
    if ( i[1].mRoot.mUID )
    {
      v16 = UFG::UITiledMapMath::WorldGeo.MaxX;
      v17 = UFG::UITiledMapMath::WorldGeo.TextureWidth;
      v18 = i[1].mNULL.mChild[1];
      v19 = _mm_cvtsi32_si128(v6->m_mapGeo.m_rowOffset);
      *(&v33 + 10 * v10) = 0;
      v20 = WORD2(v18[3].mParent);
      *(&v37 + 10 * v10) = 0;
      *(&v35 + 10 * v10) = 1065353216;
      v21 = v16 - UFG::UITiledMapMath::WorldGeo.MinX;
      v22 = *(float *)&i[1].mRoot.mChild[1];
      *(&v39 + 10 * v10) = 1065353216;
      v40[5 * v10] = (__int64)i;
      v10 = (unsigned int)(v10 + 1);
      v23 = (float)(1.0 / v21) * v17;
      v24 = (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v17 * UFG::UITiledMapMath::WorldGeo.MinX) ^ _xmm[0])
                          * (float)(1.0 / v21))
                  + (float)(v22 * v23))
          - (float)v6->m_mapGeo.m_colOffset;
      v25 = _mm_cvtsi32_si128(v20);
      v26 = HIWORD(v18[3].mParent);
      v27 = v24 - v12;
      v28 = (float)((float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
                  / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY))
          + (float)(COERCE_FLOAT(LODWORD(v23) ^ _xmm[0]) * *((float *)&i[1].mRoot.mChild[1] + 1));
      *((float *)&v32 + 2 * v15) = v27;
      v29 = (float)(v28 - COERCE_FLOAT(_mm_cvtepi32_ps(v19))) - v13;
      *((float *)&v34 + 2 * v15) = COERCE_FLOAT(_mm_cvtepi32_ps(v25)) + v27;
      *((float *)&v36 + 2 * v15) = v29;
      *((float *)&v38 + 2 * v15) = (float)v26 + v29;
    }
  }
  if ( (_DWORD)v10 )
  {
    v30 = &v32;
    do
    {
      v31 = *((_OWORD *)v30 + 1);
      *(_OWORD *)&rects.x0 = *(_OWORD *)v30;
      *(_OWORD *)&rects.y0 = v31;
      rects.tile = (UFG::UIMinimapTile *)*((_QWORD *)v30 + 4);
      UFG::DrawClippedPolys(v9, &rects, 1, v8, rects.tile->mMapTileHandle.mNameUID, v7, RasterStateUID, TransformMatrix);
      v30 += 10;
      --v10;
    }
    while ( v10 );
  }
}

// File Line: 603
// RVA: 0xC9BA0
void __fastcall UFG::UITiledMapWidget::RenderNorth(UFG::UITiledMapWidget *this, Render::View *view)
{
  Render::View *v2; // rdi
  UFG::UITiledMapWidget *v3; // rbx
  UFG::qMatrix44 v4; // [rsp+70h] [rbp-168h]
  UFG::qMatrix44 v5; // [rsp+B0h] [rbp-128h]
  UFG::qMatrix44 dest; // [rsp+F0h] [rbp-E8h]
  UFG::qMatrix44 result; // [rsp+130h] [rbp-A8h]

  v2 = view;
  v3 = this;
  if ( !(_S7_2 & 1) )
  {
    _S7_2 |= 1u;
    NorthIconTextureUID = UFG::qStringHashUpper32("Icon_North", 0xFFFFFFFF);
  }
  UFG::qRotationMatrixZ(&dest, v3->m_mapGeo.rot);
  UFG::qTranslationMatrix(&v4, &UFG::UITiledMapWidget::gMinimapCenter);
  v5.v0 = (UFG::qVector4)_mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 0), (__m128)v4.v0),
                                 (__m128)0i64),
                               _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 85), (__m128)v4.v1)),
                             _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 170), (__m128)v4.v2)),
                           _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 255), (__m128)v4.v3));
  v5.v1 = (UFG::qVector4)_mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 0), (__m128)v4.v0),
                                 (__m128)0i64),
                               _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 85), (__m128)v4.v1)),
                             _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 170), (__m128)v4.v2)),
                           _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 255), (__m128)v4.v3));
  v5.v2 = (UFG::qVector4)_mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 0), (__m128)v4.v0),
                                 (__m128)0i64),
                               _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 85), (__m128)v4.v1)),
                             _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 170), (__m128)v4.v2)),
                           _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 255), (__m128)v4.v3));
  v5.v3 = (UFG::qVector4)_mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 0), (__m128)v4.v0),
                                 (__m128)0i64),
                               _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 85), (__m128)v4.v1)),
                             _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 170), (__m128)v4.v2)),
                           _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 255), (__m128)v4.v3));
  UFG::qMatrix44::operator*(&v5, &result, &v3->mViewportScaleMatrix);
  UFG::DrawColoredRect_Xform(
    v2,
    -11.0,
    (float)(-14 - UFG::UITiledMapWidget::gMinimapBackgroundSize / 2),
    22.0,
    22.0,
    &UFG::qColour::White,
    NorthIconTextureUID,
    0i64,
    0xA3833FDE,
    0x62F81854u,
    &result);
}

// File Line: 631
// RVA: 0xC8100
void __fastcall UFG::UITiledMapWidget::RenderMinimap(UFG::UITiledMapWidget *this, Render::View *view, UFG::UIMapInteriorManager *interiorMan)
{
  UFG::UIMapInteriorManager *v3; // r13
  Render::View *v4; // rdi
  UFG::UITiledMapWidget *v5; // rbx
  bool v6; // r15
  float v7; // xmm0_4
  float v8; // xmm1_4
  unsigned int v9; // esi
  bool v10; // al
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  __m128 v14; // xmm5
  __m128 v15; // xmm6
  __m128 v16; // xmm4
  __m128 v17; // xmm11
  UFG::qMatrix44 *v18; // rax
  float v19; // xmm7_4
  unsigned int TextureUID; // er15
  float v21; // xmm7_4
  float v22; // xmm6_4
  float v23; // xmm7_4
  float v24; // xmm8_4
  float v25; // xmm3_4
  bool v26; // al
  float v27; // xmm3_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  __m128 v30; // xmm5
  __m128 v31; // xmm6
  __m128 v32; // xmm4
  __m128 v33; // xmm11
  __m128 v34; // xmm5
  __m128 v35; // xmm6
  __m128 v36; // xmm4
  __m128 v37; // xmm11
  __m128 v38; // xmm5
  __m128 v39; // xmm6
  __m128 v40; // xmm4
  __m128 v41; // xmm11
  UFG::qColour v42; // [rsp+58h] [rbp-80h]
  UFG::qMatrix44 Color; // [rsp+68h] [rbp-70h]
  UFG::qMatrix44 v44; // [rsp+A8h] [rbp-30h]
  UFG::qMatrix44 v45; // [rsp+E8h] [rbp+10h]
  __int64 v46; // [rsp+128h] [rbp+50h]
  UFG::qMatrix44 v47; // [rsp+138h] [rbp+60h]
  UFG::qMatrix44 v48; // [rsp+178h] [rbp+A0h]
  UFG::qMatrix44 v49; // [rsp+1B8h] [rbp+E0h]
  UFG::qMatrix44 dest; // [rsp+1F8h] [rbp+120h]
  UFG::qMatrix44 result; // [rsp+238h] [rbp+160h]

  v46 = -2i64;
  v3 = interiorMan;
  v4 = view;
  v5 = this;
  if ( !(_S8_0 & 1) )
  {
    _S8_0 |= 1u;
    BackgroundTextureUID = UFG::qStringHashUpper32("FX_Circle_Fill", 0xFFFFFFFF);
  }
  v6 = v3->mActive == 0;
  v42 = UFG::qColour::White;
  v42.a = v5->mAlpha;
  Render::View::Clear(v4, &UFG::qColour::Black, 4u, 1.0, 0);
  if ( v6 )
  {
    Color.v0.z = UFG::qColour::Black.r;
    Color.v0.w = UFG::qColour::Black.g;
    v7 = UFG::qColour::Black.b;
    v8 = UFG::qColour::Black.a;
  }
  else
  {
    Color.v0.z = UFG::qColour::White.r;
    Color.v0.w = UFG::qColour::White.g;
    v7 = UFG::qColour::White.b;
    v8 = UFG::qColour::White.a;
  }
  Color.v1.y = v8;
  Color.v1.x = v7;
  Color.v1.y = UFG::UITiledMapWidget::gMinimapBackgroundAlpha * v5->mAlpha;
  v9 = 1660426324;
  UFG::DrawColoredRect_Xform(
    v4,
    (float)(signed int)(float)(UFG::UITiledMapWidget::gMinimapCenter.x
                             - (float)((float)UFG::UITiledMapWidget::gMinimapBackgroundSize * 0.5)),
    (float)(signed int)(float)(UFG::UITiledMapWidget::gMinimapCenter.y
                             - (float)((float)UFG::UITiledMapWidget::gMinimapBackgroundSize * 0.5)),
    (float)UFG::UITiledMapWidget::gMinimapBackgroundSize,
    (float)UFG::UITiledMapWidget::gMinimapBackgroundSize,
    (UFG::qColour *)&Color.v0.z,
    BackgroundTextureUID,
    0i64,
    0xA3833FDE,
    0x62F81854u,
    &v5->mViewportScaleMatrix);
  Render::View::SetSimpleMaterialShader(UFG::gUIshader_Punch_Simple_UID);
  UFG::DrawColoredRect_Xform(
    v4,
    (float)(signed int)(float)(UFG::UITiledMapWidget::gMinimapCenter.x
                             - (float)((float)UFG::UITiledMapWidget::gMinimapBackgroundSize * 0.5)),
    (float)(signed int)(float)(UFG::UITiledMapWidget::gMinimapCenter.y
                             - (float)((float)UFG::UITiledMapWidget::gMinimapBackgroundSize * 0.5)),
    (float)UFG::UITiledMapWidget::gMinimapBackgroundSize,
    (float)UFG::UITiledMapWidget::gMinimapBackgroundSize,
    &UFG::qColour::White,
    BackgroundTextureUID,
    0i64,
    0x91A2DD53,
    UFG::gUIrasterState_Set_Mask1_UID,
    &v5->mViewportScaleMatrix);
  Render::View::SetSimpleMaterialShader(UFG::gUIshader_Simple_UID);
  UFG::qRotationMatrixZ(&dest, v5->m_mapGeo.rot);
  UFG::qTranslationMatrix(&v45, &UFG::UITiledMapWidget::gMinimapCenter);
  if ( v6 )
  {
    v10 = v5->m_mapGeo.useWideTiles;
    v11 = FLOAT_0_5;
    if ( v10 )
      v12 = FLOAT_0_5;
    else
      v12 = 0.0;
    v13 = UFG::UITiledMapTweakables::MinimapScaleTweak + v5->m_mapGeo.scale;
    if ( !v10 )
      v11 = 0.0;
    v42.b = v13 + v11;
    v42.a = v13 + v12;
    Color.v0.x = 1.0;
    UFG::qScaleMatrix(&v44, (UFG::qVector3 *)&v42.b);
    v14 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v44.v0, (__m128)v44.v0, 0), (__m128)dest.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v44.v0, (__m128)v44.v0, 85), (__m128)dest.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v44.v0, (__m128)v44.v0, 170), (__m128)dest.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v44.v0, (__m128)v44.v0, 255), (__m128)dest.v3));
    v15 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v44.v1, (__m128)v44.v1, 0), (__m128)dest.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v44.v1, (__m128)v44.v1, 85), (__m128)dest.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v44.v1, (__m128)v44.v1, 170), (__m128)dest.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v44.v1, (__m128)v44.v1, 255), (__m128)dest.v3));
    v16 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v44.v2, (__m128)v44.v2, 0), (__m128)dest.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v44.v2, (__m128)v44.v2, 85), (__m128)dest.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v44.v2, (__m128)v44.v2, 170), (__m128)dest.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v44.v2, (__m128)v44.v2, 255), (__m128)dest.v3));
    v17 = _mm_add_ps(
            _mm_mul_ps((__m128)dest.v3, _mm_shuffle_ps((__m128)v44.v3, (__m128)v44.v3, 255)),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v44.v3, (__m128)v44.v3, 0), (__m128)dest.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v44.v3, (__m128)v44.v3, 85), (__m128)dest.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v44.v3, (__m128)v44.v3, 170), (__m128)dest.v2)));
    Color.v0 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), (__m128)v45.v0), (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), (__m128)v45.v1)),
                                  _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), (__m128)v45.v2)),
                                _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), (__m128)v45.v3));
    Color.v1 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), (__m128)v45.v0), (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), (__m128)v45.v1)),
                                  _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), (__m128)v45.v2)),
                                _mm_mul_ps(_mm_shuffle_ps(v15, v15, 255), (__m128)v45.v3));
    Color.v2 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), (__m128)v45.v0), (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), (__m128)v45.v1)),
                                  _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), (__m128)v45.v2)),
                                _mm_mul_ps(_mm_shuffle_ps(v16, v16, 255), (__m128)v45.v3));
    Color.v3 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), (__m128)v45.v0), (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), (__m128)v45.v1)),
                                  _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), (__m128)v45.v2)),
                                _mm_mul_ps(_mm_shuffle_ps(v17, v17, 255), (__m128)v45.v3));
    v18 = UFG::qMatrix44::operator*(&Color, &result, &v5->mViewportScaleMatrix);
    Color.v0 = v18->v0;
    Color.v1 = v18->v1;
    Color.v2 = v18->v2;
    Color.v3 = v18->v3;
    if ( UFG::UITiledMapTweakables::MinimapRenderMask )
      v9 = UFG::gUIrasterState_Test_Mask_UID;
    UFG::UITiledMapWidget::DrawClipRects(v5, v4, &v42, 0xA3833FDE, v9, &Color);
  }
  else
  {
    v19 = UFG::UITiledMapMath::WorldGeo.TextureWidth;
    TextureUID = UFG::qStringHashUpper32((const char *)v3->mTextureName.mData + 6, 0xFFFFFFFF);
    v21 = v19 * 0.0078125;
    v22 = UFG::UITiledMapTweakables::InteriorMapScaleTweak + v21;
    v23 = v21 * 64.0;
    v24 = 1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX);
    v25 = (float)((float)((float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
                        / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY))
                + (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 * UFG::UITiledMapMath::WorldGeo.TextureWidth) ^ _xmm[0])
                        * v5->m_mapGeo.centerPosition.y))
        - (float)v5->m_mapGeo.m_rowOffset;
    v42.b = (float)(v23
                  - (float)((float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                                           UFG::UITiledMapMath::WorldGeo.MinX
                                                         * UFG::UITiledMapMath::WorldGeo.TextureWidth) ^ _xmm[0])
                                          * v24)
                                  + (float)((float)(v24 * UFG::UITiledMapMath::WorldGeo.TextureWidth)
                                          * v5->m_mapGeo.centerPosition.x))
                          - (float)v5->m_mapGeo.m_colOffset))
          + UFG::UITiledMapTweakables::InteriorMapXOffsetTweak;
    v42.a = (float)(v23 - v25) + UFG::UITiledMapTweakables::InteriorMapYOffsetTweak;
    Color.v0.x = 0.0;
    UFG::qTranslationMatrix(&v44, (UFG::qVector3 *)&v42.b);
    v42.b = v22;
    v42.a = v22;
    Color.v0.x = 1.0;
    UFG::qScaleMatrix(&Color, (UFG::qVector3 *)&v42.b);
    v26 = v5->m_mapGeo.useWideTiles;
    v27 = FLOAT_0_5;
    if ( v26 )
      v28 = FLOAT_0_5;
    else
      v28 = 0.0;
    v29 = UFG::UITiledMapTweakables::MinimapScaleTweak + v5->m_mapGeo.scale;
    if ( !v26 )
      v27 = 0.0;
    v42.b = v29 + v27;
    v42.a = v29 + v28;
    Color.v0.x = 1.0;
    UFG::qScaleMatrix(&v47, (UFG::qVector3 *)&v42.b);
    UFG::qRotationMatrixZ(&v48, UFG::UITiledMapTweakables::InteriorMapRotationTweak + v5->m_mapGeo.rot);
    v30 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v0, (__m128)Color.v0, 0), (__m128)v44.v0),
                  (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v0, (__m128)Color.v0, 85), (__m128)v44.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v0, (__m128)Color.v0, 170), (__m128)v44.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v0, (__m128)Color.v0, 255), (__m128)v44.v3));
    v31 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v1, (__m128)Color.v1, 0), (__m128)v44.v0),
                  (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v1, (__m128)Color.v1, 85), (__m128)v44.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v1, (__m128)Color.v1, 170), (__m128)v44.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v1, (__m128)Color.v1, 255), (__m128)v44.v3));
    v32 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v2, (__m128)Color.v2, 0), (__m128)v44.v0),
                  (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v2, (__m128)Color.v2, 85), (__m128)v44.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v2, (__m128)Color.v2, 170), (__m128)v44.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v2, (__m128)Color.v2, 255), (__m128)v44.v3));
    v33 = _mm_add_ps(
            _mm_mul_ps((__m128)v44.v3, _mm_shuffle_ps((__m128)Color.v3, (__m128)Color.v3, 255)),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v3, (__m128)Color.v3, 0), (__m128)v44.v0),
                  (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v3, (__m128)Color.v3, 85), (__m128)v44.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v3, (__m128)Color.v3, 170), (__m128)v44.v2)));
    v34 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), (__m128)v47.v3),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), (__m128)v47.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), (__m128)v47.v1)),
              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), (__m128)v47.v2)));
    v35 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v31, v31, 255), (__m128)v47.v3),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), (__m128)v47.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), (__m128)v47.v1)),
              _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), (__m128)v47.v2)));
    v36 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v32, v32, 255), (__m128)v47.v3),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), (__m128)v47.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), (__m128)v47.v1)),
              _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), (__m128)v47.v2)));
    v37 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v33, v33, 255), (__m128)v47.v3),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), (__m128)v47.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), (__m128)v47.v1)),
              _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), (__m128)v47.v2)));
    v38 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v34, v34, 255), (__m128)v48.v3),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), (__m128)v48.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), (__m128)v48.v1)),
              _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), (__m128)v48.v2)));
    v39 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v35, v35, 255), (__m128)v48.v3),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), (__m128)v48.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v35, v35, 85), (__m128)v48.v1)),
              _mm_mul_ps(_mm_shuffle_ps(v35, v35, 170), (__m128)v48.v2)));
    v40 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v36, v36, 255), (__m128)v48.v3),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v36, v36, 0), (__m128)v48.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v36, v36, 85), (__m128)v48.v1)),
              _mm_mul_ps(_mm_shuffle_ps(v36, v36, 170), (__m128)v48.v2)));
    v41 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v37, v37, 255), (__m128)v48.v3),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), (__m128)v48.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v37, v37, 85), (__m128)v48.v1)),
              _mm_mul_ps(_mm_shuffle_ps(v37, v37, 170), (__m128)v48.v2)));
    v49.v0 = (UFG::qVector4)_mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), (__m128)v45.v0), (__m128)0i64),
                                  _mm_mul_ps(_mm_shuffle_ps(v38, v38, 85), (__m128)v45.v1)),
                                _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), (__m128)v45.v2)),
                              _mm_mul_ps(_mm_shuffle_ps(v38, v38, 255), (__m128)v45.v3));
    v49.v1 = (UFG::qVector4)_mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v39, v39, 0), (__m128)v45.v0), (__m128)0i64),
                                  _mm_mul_ps(_mm_shuffle_ps(v39, v39, 85), (__m128)v45.v1)),
                                _mm_mul_ps(_mm_shuffle_ps(v39, v39, 170), (__m128)v45.v2)),
                              _mm_mul_ps(_mm_shuffle_ps(v39, v39, 255), (__m128)v45.v3));
    v49.v2 = (UFG::qVector4)_mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), (__m128)v45.v0), (__m128)0i64),
                                  _mm_mul_ps(_mm_shuffle_ps(v40, v40, 85), (__m128)v45.v1)),
                                _mm_mul_ps(_mm_shuffle_ps(v40, v40, 170), (__m128)v45.v2)),
                              _mm_mul_ps(_mm_shuffle_ps(v40, v40, 255), (__m128)v45.v3));
    v49.v3 = (UFG::qVector4)_mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), (__m128)v45.v0), (__m128)0i64),
                                  _mm_mul_ps(_mm_shuffle_ps(v41, v41, 85), (__m128)v45.v1)),
                                _mm_mul_ps(_mm_shuffle_ps(v41, v41, 170), (__m128)v45.v2)),
                              _mm_mul_ps(_mm_shuffle_ps(v41, v41, 255), (__m128)v45.v3));
    UFG::qMatrix44::operator*(&v49, &result, &v5->mViewportScaleMatrix);
    if ( UFG::UITiledMapTweakables::MinimapRenderMask )
      UFG::DrawColoredRect_Xform(
        v4,
        -64.0,
        -64.0,
        128.0,
        128.0,
        &v42,
        TextureUID,
        0i64,
        0xA3833FDE,
        UFG::gUIrasterState_Test_Mask_UID,
        &result);
    else
      UFG::DrawColoredRect_Xform(
        v4,
        -64.0,
        -64.0,
        128.0,
        128.0,
        &v42,
        TextureUID,
        0i64,
        0xA3833FDE,
        0x62F81854u,
        &result);
  }
}

// File Line: 768
// RVA: 0xCF100
void __fastcall UFG::UITiledMapWidget::setMapPosition(UFG::UITiledMapWidget *this, UFG::MinimapPoint2f pos, float arrowRotation, UFG::UITiledMapTextureManager *textureMan, UFG::UITiledMapTextureManager *wideTextureMan, bool streamBasedOnPlayerPos)
{
  bool v6; // zf
  UFG::UITiledMapTextureManager *v7; // rbx
  UFG::UITiledMapWidget *v8; // rdi
  unsigned int v9; // xmm1_4
  unsigned int v10; // xmm0_4
  float v11; // xmm7_4
  float v12; // xmm8_4
  float v13; // eax
  float v14; // xmm1_4
  UFG::UITiledMapTextureManager *v15; // rsi
  UFG::MinimapPoint2f *v16; // rdx
  UFG::MinimapPoint2f *v17; // rdx
  UFG::UITiledMapTextureManager *v18; // rcx
  UFG::MinimapPoint2f posa; // [rsp+20h] [rbp-58h]
  UFG::MinimapPoint2f v20; // [rsp+80h] [rbp+8h]
  UFG::MinimapPoint2f v21; // [rsp+88h] [rbp+10h]

  v6 = streamBasedOnPlayerPos == 0;
  v7 = textureMan;
  v8 = this;
  *(float *)&v9 = pos.y + UFG::UITiledMapTweakables::MinimapYOffsetTweak;
  *(float *)&v10 = pos.x + UFG::UITiledMapTweakables::MinimapXOffsetTweak;
  this->m_mapGeo.playerRot = arrowRotation;
  v21 = (UFG::MinimapPoint2f)__PAIR__(v9, v10);
  v20 = (UFG::MinimapPoint2f)__PAIR__(v9, v10);
  this->m_mapIconGeo.screenPosition.x = this->m_mapGeo.screenPosition.x;
  v11 = *(float *)&v10 + -128.0;
  v12 = *(float *)&v9 + -128.0;
  this->m_mapIconGeo.screenPosition.y = this->m_mapGeo.screenPosition.y;
  this->m_mapIconGeo.centerPosition.x = this->m_mapGeo.centerPosition.x;
  v13 = this->m_mapGeo.centerPosition.y;
  v20.x = *(float *)&v10 + -128.0;
  v20.y = *(float *)&v9 + -128.0;
  this->m_mapIconGeo.centerPosition.y = v13;
  this->m_mapIconGeo.rot = this->m_mapGeo.rot;
  this->m_mapIconGeo.playerRot = this->m_mapGeo.playerRot;
  this->m_mapIconGeo.scale = this->m_mapGeo.scale;
  *(_DWORD *)&this->m_mapIconGeo.useWideTiles = *(_DWORD *)&this->m_mapGeo.useWideTiles;
  this->m_mapIconGeo.CircleMaskX = this->m_mapGeo.CircleMaskX;
  this->m_mapIconGeo.CircleMaskY = this->m_mapGeo.CircleMaskY;
  this->m_mapIconGeo.MaskRadius = this->m_mapGeo.MaskRadius;
  this->m_mapIconGeo.m_rowOffset = this->m_mapGeo.m_rowOffset;
  this->m_mapIconGeo.m_colOffset = this->m_mapGeo.m_colOffset;
  *(_DWORD *)&this->m_mapIconGeo.IsWorldMap = *(_DWORD *)&this->m_mapGeo.IsWorldMap;
  this->m_mapIconGeo.useWideTiles = 0;
  v14 = UFG::UITiledMapTweakables::MinimapScaleTweak + this->m_mapGeo.scale;
  if ( v6 )
    goto LABEL_23;
  v15 = wideTextureMan;
  if ( UFG::gEnableMinimapTileSwitch )
  {
    if ( this->m_mapGeo.useWideTiles )
    {
      if ( v14 >= UFG::UITiledMapTweakables::NormalTileTrigger )
      {
        this->m_mapGeo.useWideTiles = 0;
        if ( v15 )
          UFG::UITiledMapTextureManager::ReleaseAllTextures(v15);
        goto LABEL_17;
      }
      if ( v14 < (float)(UFG::UITiledMapTweakables::NormalTileTrigger - UFG::UITiledMapTweakables::TileStreamingLead)
        || !textureMan )
      {
        goto LABEL_17;
      }
      v16 = &v20;
LABEL_16:
      UFG::UITiledMapTextureManager::SetPlayerPosition(textureMan, v16);
      goto LABEL_17;
    }
    if ( v14 > UFG::UITiledMapTweakables::WideTileTrigger )
    {
      if ( v14 > (float)(UFG::UITiledMapTweakables::WideTileTrigger + UFG::UITiledMapTweakables::TileStreamingLead)
        || !textureMan )
      {
        goto LABEL_17;
      }
      v16 = &posa;
      posa.x = v11 * 0.66666669;
      posa.y = v12 * 0.66666669;
      goto LABEL_16;
    }
    this->m_mapGeo.useWideTiles = 1;
    if ( textureMan )
      UFG::UITiledMapTextureManager::ReleaseAllTextures(textureMan);
  }
LABEL_17:
  if ( v8->m_mapGeo.useWideTiles )
  {
    if ( v15 )
    {
      v17 = &posa;
      v18 = v15;
      posa.x = v11 * 0.66666669;
      posa.y = v12 * 0.66666669;
LABEL_22:
      UFG::UITiledMapTextureManager::SetPlayerPosition(v18, v17);
      goto LABEL_23;
    }
  }
  else if ( v7 )
  {
    v17 = &v20;
    v18 = v7;
    goto LABEL_22;
  }
LABEL_23:
  UFG::UITiledMapMath::UpdatePosition(&v8->m_mapGeo, v20, 128);
  UFG::UITiledMapMath::UpdatePosition(&v8->m_mapIconGeo, v21, 128);
}pdatePosition(&v8->m_mapGeo, v20, 128);
  UFG::UITiledMapMath::U

// File Line: 889
// RVA: 0xC8D40
void __fastcall UFG::UITiledMapWidget::RenderMinimapPrimitive(UFG::UITiledMapWidget *this, Render::View *view, unsigned int PrimitiveType, UFG::qColour *Color)
{
  UFG::qColour *v4; // rdi
  signed int v5; // er15
  Render::View *v6; // r12
  UFG::UITiledMapWidget *v7; // rbx
  float v8; // xmm10_4
  float v9; // xmm9_4
  float v10; // xmm11_4
  float v11; // xmm12_4
  float v12; // xmm14_4
  float v13; // xmm15_4
  float v14; // xmm6_4
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  float v17; // xmm4_4
  __m128 v18; // xmm3
  float v19; // xmm12_4
  float v20; // xmm0_4
  float v21; // xmm12_4
  float v22; // xmm13_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  bool v27; // al
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  signed int v32; // ecx
  __m128 v33; // xmm9
  __m128 v34; // xmm10
  __m128 v35; // xmm14
  __m128 v36; // xmm9
  __m128 v37; // xmm10
  __m128 v38; // xmm15
  __m128 v39; // xmm11
  __m128 v40; // xmm12
  UFG::qMatrix44 *v41; // rax
  int v42; // edx
  unsigned int v43; // er9
  signed __int64 v44; // rax
  float v45; // xmm9_4
  float v46; // xmm10_4
  float v47; // xmm11_4
  float v48; // xmm2_4
  float v49; // xmm3_4
  float v50; // xmm1_4
  float v51; // xmm12_4
  float v52; // xmm13_4
  float v53; // xmm14_4
  float v54; // xmm15_4
  unsigned int v55; // edi
  float *v56; // rcx
  unsigned int v57; // eax
  __int64 v58; // r8
  float v59; // xmm4_4
  float v60; // xmm6_4
  float v61; // xmm5_4
  float v62; // xmm2_4
  float v63; // xmm1_4
  float v64; // xmm4_4
  float v65; // xmm6_4
  float v66; // xmm5_4
  float v67; // xmm2_4
  float v68; // xmm1_4
  float v69; // xmm4_4
  float v70; // xmm6_4
  float v71; // xmm5_4
  float v72; // xmm2_4
  float v73; // xmm1_4
  float v74; // xmm2_4
  float v75; // xmm6_4
  float v76; // xmm5_4
  float v77; // xmm2_4
  float v78; // xmm1_4
  float *v79; // rcx
  __int64 v80; // r8
  float v81; // xmm2_4
  float v82; // xmm6_4
  float v83; // xmm5_4
  float v84; // xmm2_4
  float v85; // xmm1_4
  Illusion::Material *v86; // r14
  unsigned int v87; // ebx
  UFG::qResourceInventory *v88; // rax
  UFG::qResourceWarehouse *v89; // rax
  Illusion::Primitive *v90; // rbx
  __m128 v91; // [rsp+40h] [rbp-98h]
  UFG::qVector3 offset; // [rsp+50h] [rbp-88h]
  float v93; // [rsp+5Ch] [rbp-7Ch]
  UFG::qMatrix44 v94; // [rsp+60h] [rbp-78h]
  __m128 v95; // [rsp+A8h] [rbp-30h]
  __m128 v96; // [rsp+B8h] [rbp-20h]
  __m128 v97; // [rsp+C8h] [rbp-10h]
  UFG::qMatrix44 v98; // [rsp+D8h] [rbp+0h]
  UFG::qMatrix44 v99; // [rsp+118h] [rbp+40h]
  UFG::qMatrix44 v100; // [rsp+158h] [rbp+80h]
  UFG::qMatrix44 b; // [rsp+198h] [rbp+C0h]
  UFG::qMatrix44 result; // [rsp+1D8h] [rbp+100h]
  float v103; // [rsp+2E8h] [rbp+210h]
  float vars0; // [rsp+300h] [rbp+228h]
  char *retaddr; // [rsp+308h] [rbp+230h]
  int num_vertices; // [rsp+310h] [rbp+238h]
  int num_verticesa; // [rsp+310h] [rbp+238h]
  int num_verticesb; // [rsp+310h] [rbp+238h]
  void *indices; // [rsp+318h] [rbp+240h]
  int num_indices; // [rsp+320h] [rbp+248h]

  *(_QWORD *)&v94.v2.z = -2i64;
  v4 = Color;
  v5 = PrimitiveType;
  v6 = view;
  v7 = this;
  offset = UFG::UITiledMapWidget::gMinimapCenter;
  v8 = UFG::UITiledMapMath::WorldGeo.TextureHeight;
  v9 = UFG::UITiledMapMath::WorldGeo.TextureWidth;
  v10 = UFG::UITiledMapMath::WorldGeo.MaxY;
  v11 = UFG::UITiledMapMath::WorldGeo.MinY;
  v12 = UFG::UITiledMapMath::WorldGeo.MaxX;
  v13 = UFG::UITiledMapMath::WorldGeo.MinX;
  v14 = 0.0;
  if ( this->mIsWorldMap )
  {
    v15 = (__m128)(unsigned int)FLOAT_1_0;
    v15.m128_f32[0] = 1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX);
    v16 = v15;
    v16.m128_f32[0] = (float)((float)((float)(v15.m128_f32[0] * UFG::UITiledMapMath::WorldGeo.TextureWidth) * 0.0)
                            + (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                                     UFG::UITiledMapMath::WorldGeo.TextureWidth
                                                   * UFG::UITiledMapMath::WorldGeo.MinX) ^ _xmm[0])
                                    * v15.m128_f32[0]))
                    - (float)this->m_mapGeo.m_colOffset;
    v17 = (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v15.m128_f32[0] * UFG::UITiledMapMath::WorldGeo.TextureWidth) ^ _xmm[0])
                        * 0.0)
                + (float)((float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
                        / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY)))
        - (float)this->m_mapGeo.m_rowOffset;
    v18 = v16;
    v18.m128_f32[0] = (float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v17 * v17);
    LODWORD(v19) = (unsigned __int128)_mm_sqrt_ps(v18);
    v20 = atan2f(v17, v16.m128_f32[0]);
    if ( v7->m_mapGeo.useWideTiles )
      v14 = FLOAT_0_5;
    v21 = v19 * (float)((float)(UFG::UITiledMapTweakables::MinimapScaleTweak + v7->m_mapGeo.scale) + v14);
    v22 = v20 + v7->m_mapGeo.rot;
    v23 = cosf(v22) * v21;
    v24 = (float)(sinf(v22) * v21) + v7->m_mapGeo.screenPosition.y;
    offset.x = v23 + v7->m_mapGeo.screenPosition.x;
    offset.y = v24;
    offset.z = 0.0;
    v11 = UFG::UITiledMapMath::WorldGeo.MinY;
  }
  v25 = 1.0 / (float)(v12 - v13);
  v26 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v25 * v9) ^ _xmm[0]) * v7->m_mapGeo.centerPosition.y)
      + (float)((float)(v8 * v10) / (float)(v10 - v11));
  v91.m128_i32[0] = COERCE_UNSIGNED_INT(
                      (float)((float)(v25 * v9) * v7->m_mapGeo.centerPosition.x)
                    + (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v9 * v13) ^ _xmm[0]) * v25)) ^ _xmm[0];
  *(unsigned __int64 *)((char *)v91.m128_u64 + 4) = (unsigned int)(LODWORD(v26) ^ _xmm[0]);
  UFG::qTranslationMatrix((UFG::qMatrix44 *)((char *)&v94 + 56), (UFG::qVector3 *)&v91);
  v27 = v7->m_mapGeo.useWideTiles;
  v28 = FLOAT_0_5;
  if ( v27 )
    v29 = FLOAT_0_5;
  else
    v29 = 0.0;
  v30 = UFG::UITiledMapTweakables::MinimapScaleTweak + v7->m_mapGeo.scale;
  v31 = v29 + v30;
  if ( !v27 )
    v28 = 0.0;
  v91.m128_f32[0] = v28 + v30;
  *(unsigned __int64 *)((char *)v91.m128_u64 + 4) = __PAIR__(1065353216, LODWORD(v31));
  UFG::qScaleMatrix(&v99, (UFG::qVector3 *)&v91);
  UFG::qRotationMatrixZ(&v100, v7->m_mapGeo.rot);
  UFG::qTranslationMatrix(&v98, &offset);
  v32 = UFG::UIScreenManager::s_instance->m_flashHeight;
  v91.m128_f32[0] = 1.0 / (float)(signed int)UFG::UIScreenManager::s_instance->m_flashWidth;
  v91.m128_f32[1] = 1.0 / (float)v32;
  v91.m128_i32[2] = 1065353216;
  UFG::qScaleMatrix(&b, (UFG::qVector3 *)&v91);
  *(__m128 *)&v94.v1.z = _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v94.v3.z, *(__m128 *)&v94.v3.z, 0), (__m128)v99.v0);
  v33 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v94.v3.z, *(__m128 *)&v94.v3.z, 255), (__m128)v99.v3),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(*(__m128 *)&v94.v1.z, _xmm),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v94.v3.z, *(__m128 *)&v94.v3.z, 85), (__m128)v99.v1)),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v94.v3.z, *(__m128 *)&v94.v3.z, 170), (__m128)v99.v2)));
  v34 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v95, v95, 255), (__m128)v99.v3),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v95, v95, 0), (__m128)v99.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v95, v95, 85), (__m128)v99.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v95, v95, 170), (__m128)v99.v2)));
  v35 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v96, v96, 255), (__m128)v99.v3),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v96, v96, 0), (__m128)v99.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v96, v96, 85), (__m128)v99.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v96, v96, 170), (__m128)v99.v2)));
  v91 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v97, v97, 170), (__m128)v99.v2),
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v97, v97, 0), (__m128)v99.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v97, v97, 85), (__m128)v99.v1))),
          _mm_mul_ps(_mm_shuffle_ps(v97, v97, 255), (__m128)v99.v3));
  *(__m128 *)&v94.v1.z = _mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), (__m128)v100.v0);
  v36 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v33, v33, 255), (__m128)v100.v3),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(*(__m128 *)&v94.v1.z, _xmm),
              _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), (__m128)v100.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), (__m128)v100.v2)));
  v37 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v34, v34, 255), (__m128)v100.v3),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), (__m128)v100.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), (__m128)v100.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), (__m128)v100.v2)));
  v38 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v91, v91, 0), (__m128)v100.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v91, v91, 85), (__m128)v100.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v91, v91, 170), (__m128)v100.v2)),
          _mm_mul_ps(_mm_shuffle_ps(v91, v91, 255), (__m128)v100.v3));
  v39 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v35, v35, 170), (__m128)v100.v2),
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), (__m128)v100.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v35, v35, 85), (__m128)v100.v1))),
          _mm_mul_ps(_mm_shuffle_ps(v35, v35, 255), (__m128)v100.v3));
  v91 = _mm_mul_ps(_mm_shuffle_ps(v36, v36, 0), (__m128)v98.v0);
  *(__m128 *)&v94.v1.z = _mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), (__m128)v98.v0);
  v91 = _mm_add_ps(_mm_add_ps(v91, _xmm), _mm_mul_ps(_mm_shuffle_ps(v36, v36, 85), (__m128)v98.v1));
  v40 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(*(__m128 *)&v94.v1.z, (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v38, v38, 85), (__m128)v98.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), (__m128)v98.v2)),
          _mm_mul_ps((__m128)v98.v3, _mm_shuffle_ps(v38, v38, 255)));
  v94.v1 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), (__m128)v98.v0), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v37, v37, 85), (__m128)v98.v1)),
                              _mm_mul_ps(_mm_shuffle_ps(v37, v37, 170), (__m128)v98.v2)),
                            _mm_mul_ps((__m128)v98.v3, _mm_shuffle_ps(v37, v37, 255)));
  *(__m128 *)&offset.z = _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v39, v39, 0), (__m128)v98.v0), (__m128)0i64),
                               _mm_mul_ps(_mm_shuffle_ps(v39, v39, 85), (__m128)v98.v1)),
                             _mm_mul_ps(_mm_shuffle_ps(v39, v39, 170), (__m128)v98.v2)),
                           _mm_mul_ps((__m128)v98.v3, _mm_shuffle_ps(v39, v39, 255)));
  *(__m128 *)&v94.v0.z = v40;
  v41 = UFG::qMatrix44::operator*(&v94, &result, &v7->mViewportScaleMatrix);
  UFG::qMatrix44::operator*(v41, &v94, &b);
  v42 = (signed int)(float)(v4->r * 255.0) | (((signed int)(float)(v4->g * 255.0) | (((signed int)(float)(v4->b * 255.0) | ((signed int)(float)(v4->a * 255.0) << 8)) << 8)) << 8);
  v43 = 0;
  v44 = 0i64;
  v45 = v94.v1.x;
  v46 = v94.v0.w;
  v47 = v94.v0.z;
  v48 = v94.v0.x;
  v49 = v93;
  v50 = offset.z;
  v51 = v94.v1.z;
  v52 = v94.v1.y;
  v53 = v94.v1.x;
  v54 = v94.v0.z;
  v55 = num_vertices;
  if ( num_vertices >= 4 )
  {
    *(float *)&num_verticesa = offset.z * 0.0;
    v103 = v93 * 0.0;
    vars0 = v94.v0.x * 0.0;
    v56 = (float *)(retaddr + 56);
    v57 = ((v55 - 4) >> 2) + 1;
    v58 = v57;
    v43 = 4 * v57;
    v44 = 4i64 * v57;
    do
    {
      v59 = (float)(1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX))
          * UFG::UITiledMapMath::WorldGeo.TextureWidth;
      v60 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::UITiledMapMath::WorldGeo.TextureWidth * UFG::UITiledMapMath::WorldGeo.MinX) ^ _xmm[0])
                  * (float)(1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX)))
          + (float)(*(v56 - 14) * v59);
      v61 = (float)((float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
                  / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY))
          + (float)(COERCE_FLOAT(LODWORD(v59) ^ _xmm[0]) * *(v56 - 13));
      v62 = (float)((float)((float)(v52 * v61) + (float)(v94.v0.y * v60)) + v103) + v46;
      v63 = (float)((float)((float)(v51 * v61) + (float)(v54 * v60)) + vars0) + v45;
      *(v56 - 14) = (float)((float)((float)(v53 * v61) + (float)(v94.v0.x * v60)) + *(float *)&num_verticesa) + v47;
      *(v56 - 13) = v62;
      *(v56 - 12) = v63;
      *((_DWORD *)v56 - 3) = v42;
      v64 = (float)(1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX))
          * UFG::UITiledMapMath::WorldGeo.TextureWidth;
      v65 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::UITiledMapMath::WorldGeo.TextureWidth * UFG::UITiledMapMath::WorldGeo.MinX) ^ _xmm[0])
                  * (float)(1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX)))
          + (float)(*(v56 - 2) * v64);
      v66 = (float)((float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
                  / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY))
          + (float)(COERCE_FLOAT(LODWORD(v64) ^ _xmm[0]) * *(v56 - 1));
      v67 = (float)((float)((float)(v52 * v66) + (float)(v94.v0.y * v65)) + v103) + v46;
      v68 = (float)((float)((float)(v51 * v66) + (float)(v54 * v65)) + vars0) + v45;
      *(v56 - 2) = (float)((float)((float)(v53 * v66) + (float)(v94.v0.x * v65)) + *(float *)&num_verticesa) + v47;
      *(v56 - 1) = v67;
      *v56 = v68;
      *((_DWORD *)v56 + 9) = v42;
      v69 = (float)(1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX))
          * UFG::UITiledMapMath::WorldGeo.TextureWidth;
      v70 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::UITiledMapMath::WorldGeo.TextureWidth * UFG::UITiledMapMath::WorldGeo.MinX) ^ _xmm[0])
                  * (float)(1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX)))
          + (float)(v56[10] * v69);
      v71 = (float)((float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
                  / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY))
          + (float)(COERCE_FLOAT(LODWORD(v69) ^ _xmm[0]) * v56[11]);
      v72 = (float)((float)((float)(v52 * v71) + (float)(v94.v0.y * v70)) + v103) + v46;
      v73 = (float)((float)((float)(v51 * v71) + (float)(v54 * v70)) + vars0) + v45;
      v56[10] = (float)((float)((float)(v53 * v71) + (float)(v94.v0.x * v70)) + *(float *)&num_verticesa) + v47;
      v56[11] = v72;
      v56[12] = v73;
      *((_DWORD *)v56 + 21) = v42;
      v74 = 1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX);
      v75 = (float)(v56[22] * (float)(v74 * UFG::UITiledMapMath::WorldGeo.TextureWidth))
          + (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::UITiledMapMath::WorldGeo.TextureWidth * UFG::UITiledMapMath::WorldGeo.MinX) ^ _xmm[0])
                  * v74);
      v76 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v74 * UFG::UITiledMapMath::WorldGeo.TextureWidth) ^ _xmm[0])
                  * v56[23])
          + (float)((float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
                  / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY));
      v77 = (float)((float)((float)(v52 * v76) + (float)(v94.v0.y * v75)) + v103) + v46;
      v78 = (float)((float)((float)(v51 * v76) + (float)(v54 * v75)) + vars0) + v45;
      v56[22] = (float)((float)((float)(v53 * v76) + (float)(v94.v0.x * v75)) + *(float *)&num_verticesa) + v47;
      v56[23] = v77;
      v56[24] = v78;
      *((_DWORD *)v56 + 33) = v42;
      v56 += 48;
      --v58;
    }
    while ( v58 );
    v48 = v94.v0.x;
    v49 = v93;
    v50 = offset.z;
  }
  if ( v43 < v55 )
  {
    *(float *)&num_verticesb = v50 * 0.0;
    v103 = v49 * 0.0;
    vars0 = v48 * 0.0;
    v79 = (float *)&retaddr[48 * v44 + 4];
    v80 = v55 - v43;
    do
    {
      v81 = 1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX);
      v82 = (float)(*(v79 - 1) * (float)(v81 * UFG::UITiledMapMath::WorldGeo.TextureWidth))
          + (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::UITiledMapMath::WorldGeo.TextureWidth * UFG::UITiledMapMath::WorldGeo.MinX) ^ _xmm[0])
                  * v81);
      v83 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v81 * UFG::UITiledMapMath::WorldGeo.TextureWidth) ^ _xmm[0]) * *v79)
          + (float)((float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
                  / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY));
      v84 = (float)((float)((float)(v52 * v83) + (float)(v94.v0.y * v82)) + v103) + v46;
      v85 = (float)((float)((float)(v51 * v83) + (float)(v54 * v82)) + vars0) + v45;
      *(v79 - 1) = (float)((float)((float)(v53 * v83) + (float)(v94.v0.x * v82)) + *(float *)&num_verticesb) + v47;
      *v79 = v84;
      v79[1] = v85;
      *((_DWORD *)v79 + 10) = v42;
      v79 += 12;
      --v80;
    }
    while ( v80 );
  }
  v86 = Render::View::CreateSimpleMaterial(0xB11369EB, UFG::gUIrasterState_Test_Mask_UID, 0xA3833FDE, 0);
  if ( !(_S9 & 1) )
  {
    _S9 |= 1u;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&vertex_decl_handle_1.mPrev);
    atexit(UFG::UITiledMapWidget::RenderMinimapPrimitive_::_7_::_dynamic_atexit_destructor_for__vertex_decl_handle__);
  }
  if ( !vertex_decl_handle_1.mData )
  {
    v87 = UFG::qStringHash32("VertexDecl.Dynamic", 0xFFFFFFFF);
    v88 = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
    {
      v89 = UFG::qResourceWarehouse::Instance();
      v88 = UFG::qResourceWarehouse::GetInventory(v89, 0x3E5FDA3Eu);
      `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = v88;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&vertex_decl_handle_1.mPrev, 0x3E5FDA3Eu, v87, v88);
  }
  v90 = Illusion::Primitive::Create("MiniMap");
  Illusion::Primitive::SetBuffers(
    v90,
    (Illusion::Primitive::Type)v5,
    retaddr,
    v55,
    (Illusion::VertexDecl *)vertex_decl_handle_1.mData,
    indices,
    num_indices,
    1);
  Render::View::Draw(v6, v90, v86, 0i64);
}

// File Line: 1017
// RVA: 0xC7CA0
void __fastcall UFG::UITiledMapWidget::RenderGPSSpline(UFG::UITiledMapWidget *this, Render::View *view, UFG::UITiledMapGPS *GPS, UFG::UIMapBlipManager *blipMan)
{
  unsigned int v4; // ebx
  UFG::UIMapBlipManager *v5; // rsi
  UFG::UITiledMapGPS *v6; // rax
  UFG::UITiledMapWidget *v7; // rdi
  float v8; // xmm1_4
  unsigned int v9; // er8
  signed __int64 v10; // rbp
  float v11; // xmm0_4
  unsigned int v12; // er9
  UFG::qBaseTreeRB *v13; // rax
  __int64 v14; // rcx
  float v15; // xmm3_4
  float yPos; // xmm4_4
  float v17; // xmm5_4
  UFG::UIMapBlip *v18; // rax
  __m128 v19; // xmm2
  UFG::qColour v20; // [rsp+30h] [rbp-18h]

  v4 = GPS->mNumSplinePoints;
  v5 = blipMan;
  v6 = GPS;
  v7 = this;
  if ( v4 >= 2 )
  {
    v8 = this->mAlpha;
    v9 = 50;
    v10 = (signed __int64)&v6->mSplinePoints;
    if ( v4 < 0x32 )
      v9 = v4;
    v20 = UFG::UITiledMapWidget::GPSLineColor;
    v20.a = v8;
    v11 = UFG::UITiledMapWidget::GPSLineColor.r;
    _mm_store_si128((__m128i *)&v20, (__m128i)v20);
    UFG::UITiledMapWidget::RenderSpline(this, &v6->mSplinePoints, v9, &v20, view);
    if ( UFG::UITiledMapTweakables::GPS_ShowDestinationBlip )
    {
      v12 = UI_BLIP_GPS_DESTINATION;
      if ( UI_BLIP_GPS_DESTINATION )
      {
        v13 = UFG::qBaseTreeRB::Get(&v5->mIconList.mIconData.mTree, UI_BLIP_GPS_DESTINATION);
        v12 = UI_BLIP_GPS_DESTINATION;
      }
      else
      {
        v13 = 0i64;
      }
      v14 = *(_QWORD *)(v10 + 8);
      v15 = *(float *)(v14 + 12i64 * (v4 - 1));
      yPos = *(float *)(v14 + 12i64 * (v4 - 1) + 4);
      v17 = *(float *)(v14 + 12i64 * (v4 - 1) + 8);
      if ( v13 )
      {
        v19 = (__m128)*((unsigned int *)&v13->mCount + 1);
        v19.m128_f32[0] = (float)((float)((float)(v19.m128_f32[0] - yPos) * (float)(v19.m128_f32[0] - yPos))
                                + (float)((float)(*(float *)&v13->mCount - v15) * (float)(*(float *)&v13->mCount - v15)))
                        + (float)((float)(*(float *)&v13[1].mRoot.mParent - v17)
                                * (float)(*(float *)&v13[1].mRoot.mParent - v17));
        if ( COERCE_FLOAT(_mm_sqrt_ps(v19)) > UFG::gSymbolPosDiff )
        {
          *(float *)&v13->mCount = v15;
          *((float *)&v13->mCount + 1) = yPos;
          *(float *)&v13[1].mRoot.mParent = v17;
          BYTE5(v13->mNULL.mChild[0]) = 1;
        }
      }
      else
      {
        v18 = UFG::UIMapBlipManager::CreateIcon(v5, v12, "friendly", v15, v11, yPos);
        if ( v7->mIsWorldMap )
          v18->mBoundIcon = 0;
      }
    }
  }
}

// File Line: 1094
// RVA: 0xC9E20
void __fastcall UFG::UITiledMapWidget::RenderSpline(UFG::UITiledMapWidget *this, UFG::qArray<UFG::qVector3,0> *SplinePoints, const unsigned int NumSplinePoints, UFG::qColour *Colour, Render::View *view)
{
  UFG::qColour *v5; // rbp
  unsigned int v6; // edi
  UFG::qArray<UFG::qVector3,0> *v7; // rbx
  UFG::UITiledMapWidget *v8; // rsi
  float v9; // xmm1_4
  float v10; // xmm11_4
  char *v11; // r10
  int v12; // er9
  float *v13; // rax
  float v14; // xmm8_4
  float v15; // xmm7_4
  float v16; // xmm1_4
  float v17; // xmm6_4
  float v18; // xmm8_4
  float v19; // xmm7_4
  __int64 v20; // r14
  float v21; // xmm1_4
  float v22; // xmm0_4
  float *v23; // rax
  float v24; // xmm1_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm2_4
  signed __int64 v28; // rcx
  signed __int64 v29; // r8
  signed __int64 v30; // rdx
  __int64 v31; // r11
  UFG::qVector3 *v32; // rax
  __m128 v33; // xmm8
  float v34; // xmm7_4
  __m128 v35; // xmm1
  float v36; // xmm6_4
  float v37; // xmm6_4
  float v38; // xmm2_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  UFG::qVector3 *v46; // rax
  float v47; // xmm1_4
  float v48; // xmm0_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  UFG::qVector3 *v51; // rax
  __int64 v52; // rdx
  float v53; // xmm8_4
  float v54; // xmm7_4
  float v55; // xmm0_4
  signed __int64 v56; // rcx
  UFG::qVector3 *v57; // rax
  float v58; // xmm2_4
  float v59; // xmm1_4
  unsigned int v60; // er8
  signed __int64 v61; // rax

  if ( NumSplinePoints >= 2 )
  {
    v5 = Colour;
    v6 = NumSplinePoints;
    v7 = SplinePoints;
    v8 = this;
    if ( this->m_mapGeo.useWideTiles )
      v9 = FLOAT_0_5;
    else
      v9 = 0.0;
    v10 = 3.0 / (float)((float)(UFG::UITiledMapTweakables::MinimapScaleTweak + this->m_mapGeo.scale) + v9);
    v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 96 * NumSplinePoints, 0x10u);
    v12 = (signed int)(float)(v5->r * 255.0) | (((signed int)(float)(v5->g * 255.0) | (((signed int)(float)(v5->b * 255.0) | ((signed int)(float)(v5->a * 255.0) << 8)) << 8)) << 8);
    v13 = &v7->p->x;
    v14 = v13[4] - v13[1];
    LODWORD(v15) = COERCE_UNSIGNED_INT(v13[3] - *v13) ^ _xmm[0];
    v16 = (float)(v15 * v15) + (float)(v14 * v14);
    if ( v16 == 0.0 )
      v17 = 0.0;
    else
      v17 = 1.0 / fsqrt(v16);
    v18 = v14 * v17;
    v19 = v15 * v17;
    v20 = v6 - 1;
    v21 = (float)(v18 * v10) + *v13;
    v22 = (float)(v19 * v10) + v13[1];
    *((_DWORD *)v11 + 2) = 0;
    *(float *)v11 = v21;
    *((float *)v11 + 1) = v22;
    *((_DWORD *)v11 + 11) = v12;
    v23 = &v7->p->x;
    v24 = v23[1] - (float)(v19 * v10);
    v25 = v19;
    v26 = v17 * 0.0;
    *((float *)v11 + 12) = *v23 - (float)(v18 * v10);
    *((float *)v11 + 13) = v24;
    *((_DWORD *)v11 + 14) = 0;
    *((_DWORD *)v11 + 23) = v12;
    v27 = v18;
    if ( (unsigned int)v20 > 1 )
    {
      v28 = 1i64;
      v29 = 2i64;
      v30 = (signed __int64)(v11 + 152);
      v31 = v6 - 2;
      do
      {
        v32 = v7->p;
        v33 = (__m128)LODWORD(v32[v29].y);
        v33.m128_f32[0] = v33.m128_f32[0] - v32[v28].y;
        LODWORD(v34) = COERCE_UNSIGNED_INT(v32[v29].x - v32[v28].x) ^ _xmm[0];
        v35 = v33;
        v35.m128_f32[0] = (float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(v34 * v34);
        if ( v35.m128_f32[0] == 0.0 )
          v36 = 0.0;
        else
          v36 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v35));
        v18 = v33.m128_f32[0] * v36;
        v19 = v34 * v36;
        v37 = v36 * 0.0;
        v38 = v27 + v18;
        v39 = v25 + v19;
        v40 = (float)((float)(v39 * v39) + (float)(v38 * v38)) + (float)((float)(v26 + v37) * (float)(v26 + v37));
        if ( v40 == 0.0 )
          v41 = 0.0;
        else
          v41 = 1.0 / fsqrt(v40);
        v30 += 96i64;
        ++v29;
        ++v28;
        v26 = v37;
        v42 = (float)(v38 * v41) * v10;
        v43 = (float)(v39 * v41) * v10;
        v44 = v42 + v32[v28 - 1].x;
        v45 = v43 + *((float *)&v32[v28] - 2);
        *(_DWORD *)(v30 - 144) = 0;
        *(float *)(v30 - 152) = v44;
        *(float *)(v30 - 148) = v45;
        *(_DWORD *)(v30 - 108) = v12;
        v46 = v7->p;
        v47 = v46[v28 - 1].x;
        v48 = *((float *)&v46[v28] - 2);
        *(_DWORD *)(v30 - 96) = 0;
        v49 = v47 - v42;
        v50 = v48 - v43;
        v27 = v18;
        v25 = v19;
        *(float *)(v30 - 104) = v49;
        *(float *)(v30 - 100) = v50;
        *(_DWORD *)(v30 - 60) = v12;
        --v31;
      }
      while ( v31 );
    }
    v51 = v7->p;
    v52 = (unsigned int)(2 * v20);
    v53 = v18 * v10;
    v54 = v19 * v10;
    v55 = v54 + v51[v20].y;
    v56 = 6 * v52;
    *(float *)&v11[8 * v56] = v53 + v51[v20].x;
    *(float *)&v11[8 * v56 + 4] = v55;
    *(_DWORD *)&v11[8 * v56 + 8] = 0;
    *(_DWORD *)&v11[8 * v56 + 44] = v12;
    v57 = v7->p;
    v58 = v57[v20].x;
    v59 = v57[v20].y;
    v60 = 4;
    v61 = 6i64 * (unsigned int)(v52 + 1);
    *(float *)&v11[8 * v61] = v58 - v53;
    *(float *)&v11[8 * v61 + 4] = v59 - v54;
    *(_DWORD *)&v11[8 * v61 + 44] = v12;
    *(_DWORD *)&v11[8 * v61 + 8] = 0;
    if ( UFG::UIHKTweakables::WorldMap_UsePointList )
      v60 = 0;
    UFG::UITiledMapWidget::RenderMinimapPrimitive(v8, view, v60, v5);
  }
}

// File Line: 1160
// RVA: 0xC7E00
void __fastcall UFG::UITiledMapWidget::RenderMapLines(UFG::UITiledMapWidget *this, Render::View *view, UFG::UIMapLinesWidget *MapLines)
{
  UFG::UIHKMapLine *v3; // rdi
  unsigned int v4; // ebx
  Render::View *v5; // r12
  UFG::UITiledMapWidget *v6; // r13
  Render::vDynamic *Vertices; // rsi
  char *Indices; // rbp
  unsigned int v9; // er11
  float *v10; // r8
  signed __int64 v11; // r10
  signed __int64 v12; // r9
  float v13; // xmm8_4
  float v14; // xmm6_4
  float v15; // xmm9_4
  float v16; // xmm7_4
  float v17; // xmm5_4
  float v18; // xmm4_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  __int16 v21; // dx
  float v22; // xmm4_4
  float v23; // xmm5_4

  v3 = MapLines->mActiveLines.p;
  v4 = MapLines->mActiveLines.size;
  v5 = view;
  v6 = this;
  if ( v3 && v4 )
  {
    Vertices = (Render::vDynamic *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 192 * v4, 0x10u);
    memset(Vertices, 0, 192i64 * v4);
    Indices = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 12 * v4, 0x10u);
    memset(Indices, 0, 12i64 * v4);
    v9 = 0;
    if ( v4 )
    {
      v10 = &v3->start.y;
      v11 = (signed __int64)(Indices + 4);
      v12 = (signed __int64)&Vertices[1].mPosition.z;
      do
      {
        v13 = v10[1];
        v14 = *(v10 - 1);
        v15 = v10[2];
        v16 = *v10;
        v17 = v10[2] - *v10;
        LODWORD(v18) = COERCE_UNSIGNED_INT(v10[1] - v14) ^ _xmm[0];
        v19 = (float)(v18 * v18) + (float)(v17 * v17);
        if ( v19 == 0.0 )
          v20 = 0.0;
        else
          v20 = 1.0 / fsqrt(v19);
        *(_DWORD *)(v12 - 48) = 0;
        v21 = 4 * v9;
        v22 = (float)(v18 * v20) * 3.0;
        ++v9;
        v11 += 12i64;
        v10 += 4;
        v12 += 192i64;
        v23 = (float)(v17 * v20) * 3.0;
        *(float *)(v12 - 244) = v22 + v16;
        *(float *)(v12 - 248) = v14 + v23;
        *(float *)(v12 - 196) = v16 - v22;
        *(_DWORD *)(v12 - 192) = 0;
        *(float *)(v12 - 200) = v14 - v23;
        *(float *)(v12 - 152) = v13 + v23;
        *(float *)(v12 - 148) = v15 + v22;
        *(_DWORD *)(v12 - 144) = 0;
        *(_DWORD *)(v12 - 96) = 0;
        *(float *)(v12 - 104) = v13 - v23;
        *(float *)(v12 - 100) = v15 - v22;
        *(_WORD *)(v11 - 16) = v21;
        *(_WORD *)(v11 - 12) = v21 + 2;
        *(_WORD *)(v11 - 10) = v21 + 2;
        *(_WORD *)(v11 - 14) = v21 + 1;
        *(_WORD *)(v11 - 8) = v21 + 1;
        *(_WORD *)(v11 - 6) = v21 + 3;
      }
      while ( v9 < v4 );
    }
    UFG::UITiledMapWidget::RenderMinimapPrimitive(
      v6,
      v5,
      3u,
      &UFG::qColour::Green,
      Vertices,
      4 * v4,
      (unsigned __int16 *)Indices,
      6 * v4);
  }
}

// File Line: 1202
// RVA: 0xC7440
void __fastcall UFG::UITiledMapWidget::RenderBlipRanges(UFG::UITiledMapWidget *this, Render::View *view)
{
  Render::View *v2; // rbp
  UFG::UITiledMapWidget *v3; // rdi
  UFG::UIRenderQuad *v4; // rbx
  float v5; // xmm1_4
  float v6; // xmm6_4
  UFG::qMatrix44 *v7; // rcx
  UFG::qMatrix44 *v8; // rax
  UFG::qVector4 v9; // xmm0
  UFG::qVector4 v10; // xmm1
  float v11; // xmm1_4
  int v12; // ebx
  UFG::UIRenderQuad *v13; // rbx
  float v14; // xmm1_4
  UFG::qMatrix44 TransformMatrix; // [rsp+60h] [rbp-C8h]
  __int64 v16; // [rsp+A0h] [rbp-88h]
  UFG::qMatrix44 result; // [rsp+A8h] [rbp-80h]

  v16 = -2i64;
  v2 = view;
  v3 = this;
  if ( !(_S10 & 1) )
  {
    _S10 |= 1u;
    BackgroundTextureUID_0 = UFG::qStringHashUpper32("FX_Feathered_Circle_2", 0xFFFFFFFF);
  }
  v4 = v3->PolyListNativeDoubleClipped.p;
  if ( &v4[v3->PolyListNativeDoubleClipped.size] != v4 )
  {
    do
    {
      Render::View::Clear(v2, &UFG::qColour::Black, 4u, 1.0, 0);
      Render::View::SetSimpleMaterialShader(UFG::gUIshader_Punch_Simple_UID);
      UFG::DrawColoredRect_Xform(
        v2,
        (float)(signed int)(float)(UFG::UITiledMapWidget::gMinimapCenter.x
                                 - (float)((float)(UFG::UITiledMapWidget::gMinimapStencilSizePad
                                                 + UFG::UITiledMapWidget::gMinimapBackgroundSize)
                                         * 0.5)),
        (float)(signed int)(float)(UFG::UITiledMapWidget::gMinimapCenter.y
                                 - (float)((float)(UFG::UITiledMapWidget::gMinimapStencilSizePad
                                                 + UFG::UITiledMapWidget::gMinimapBackgroundSize)
                                         * 0.5)),
        (float)(UFG::UITiledMapWidget::gMinimapStencilSizePad + UFG::UITiledMapWidget::gMinimapBackgroundSize),
        (float)(UFG::UITiledMapWidget::gMinimapStencilSizePad + UFG::UITiledMapWidget::gMinimapBackgroundSize),
        &UFG::qColour::White,
        BackgroundTextureUID_0,
        0i64,
        0x91A2DD53,
        UFG::gUIrasterState_Set_Mask1_UID,
        &v3->mViewportScaleMatrix);
      Render::View::SetSimpleMaterialShader(UFG::gUIshader_Simple_UID);
      if ( v3->m_mapGeo.useWideTiles )
        v5 = FLOAT_0_5;
      else
        v5 = 0.0;
      v6 = (float)(v4->Size * v4->Scale)
         * (float)((float)(UFG::UITiledMapTweakables::MinimapScaleTweak + v3->m_mapGeo.scale) + v5);
      v7 = v4->Matrix;
      if ( v7 )
      {
        v8 = UFG::qMatrix44::operator*(v7, &result, &v3->mViewportScaleMatrix);
        TransformMatrix.v0 = v8->v0;
        TransformMatrix.v1 = v8->v1;
        v9 = v8->v2;
        v10 = v8->v3;
      }
      else
      {
        TransformMatrix.v0 = v3->mViewportScaleMatrix.v0;
        TransformMatrix.v1 = v3->mViewportScaleMatrix.v1;
        v9 = v3->mViewportScaleMatrix.v2;
        v10 = v3->mViewportScaleMatrix.v3;
      }
      TransformMatrix.v3 = v10;
      TransformMatrix.v2 = v9;
      Render::View::SetSimpleMaterialShader(UFG::gUIshader_Punch_Simple_UID);
      UFG::DrawColoredRect_Xform(
        v2,
        v4->X - (float)(v6 * 0.5),
        v4->Y - (float)(v6 * 0.5),
        v6,
        v6,
        &UFG::qColour::White,
        v4->TextureID,
        v4->UVs,
        0x91A2DD53,
        UFG::gUIrasterState_Set_Mask0_UID,
        &TransformMatrix);
      Render::View::SetSimpleMaterialShader(UFG::gUIshader_Simple_UID);
      if ( v3->m_mapGeo.useWideTiles )
        v11 = FLOAT_0_5;
      else
        v11 = 0.0;
      UFG::DrawUIRenderQuad(
        v2,
        v4 + 1,
        &v3->mViewportScaleMatrix,
        UFG::gUIrasterState_Test_Mask_UID,
        v3->mAlpha,
        (float)(UFG::UITiledMapTweakables::MinimapScaleTweak + v3->m_mapGeo.scale) + v11);
      v4 += 2;
    }
    while ( &v3->PolyListNativeDoubleClipped.p[v3->PolyListNativeDoubleClipped.size] != v4 );
  }
  Render::View::Clear(v2, &UFG::qColour::Black, 4u, 1.0, 0);
  v12 = UFG::UITiledMapWidget::gMinimapBackgroundSize + UFG::UITiledMapWidget::gMinimapStencilSizePad;
  Render::View::SetSimpleMaterialShader(UFG::gUIshader_Punch_Simple_UID);
  UFG::DrawColoredRect_Xform(
    v2,
    (float)(signed int)(float)(UFG::UITiledMapWidget::gMinimapCenter.x - (float)((float)v12 * 0.5)),
    (float)(signed int)(float)(UFG::UITiledMapWidget::gMinimapCenter.y - (float)((float)v12 * 0.5)),
    (float)v12,
    (float)v12,
    &UFG::qColour::White,
    BackgroundTextureUID_0,
    0i64,
    0x91A2DD53,
    UFG::gUIrasterState_Set_Mask1_UID,
    &v3->mViewportScaleMatrix);
  Render::View::SetSimpleMaterialShader(UFG::gUIshader_Simple_UID);
  v13 = v3->PolyListNativeClipped.p;
  if ( &v13[v3->PolyListNativeClipped.size] != v13 )
  {
    do
    {
      if ( v3->m_mapGeo.useWideTiles )
        v14 = FLOAT_0_5;
      else
        v14 = 0.0;
      UFG::DrawUIRenderQuad(
        v2,
        v13,
        &v3->mViewportScaleMatrix,
        UFG::gUIrasterState_Test_Mask_UID,
        v3->mAlpha,
        (float)(UFG::UITiledMapTweakables::MinimapScaleTweak + v3->m_mapGeo.scale) + v14);
      ++v13;
    }
    while ( &v3->PolyListNativeClipped.p[v3->PolyListNativeClipped.size] != v13 );
  }
}

// File Line: 1282
// RVA: 0xC7890
void __fastcall UFG::UITiledMapWidget::RenderBlips(UFG::UITiledMapWidget *this, Render::View *view)
{
  Render::View *v2; // r15
  UFG::UITiledMapWidget *v3; // rdi
  UFG::UIRenderQuad *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm1_4
  __m128 v7; // xmm5
  __m128 v8; // xmm6
  __m128 v9; // xmm4
  __m128 v10; // xmm12
  UFG::qMatrix44 *v11; // rsi
  UFG::qVector3 scale; // [rsp+30h] [rbp-D0h]
  UFG::qVector3 offset; // [rsp+40h] [rbp-C0h]
  UFG::qMatrix44 m; // [rsp+50h] [rbp-B0h]
  UFG::qMatrix44 v15; // [rsp+90h] [rbp-70h]
  UFG::qMatrix44 d; // [rsp+D0h] [rbp-30h]
  UFG::qMatrix44 dest; // [rsp+110h] [rbp+10h]

  v2 = view;
  v3 = this;
  scale.x = UFG::UITiledMapTweakables::BlipScale;
  scale.y = UFG::UITiledMapTweakables::BlipScale;
  scale.z = 1.0;
  UFG::qScaleMatrix(&dest, &scale);
  v4 = v3->PolyListNativeNotClipped.p;
  if ( &v4[v3->PolyListNativeNotClipped.size] != v4 )
  {
    do
    {
      v5 = v4->X;
      v6 = v4->Y;
      offset.z = 0.0;
      offset.x = v5;
      offset.y = v6;
      UFG::qTranslationMatrix(&m, &offset);
      UFG::qInverseAffine(&d, &m);
      v7 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)d.v0, (__m128)d.v0, 0), (__m128)dest.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps((__m128)d.v0, (__m128)d.v0, 85), (__m128)dest.v1)),
               _mm_mul_ps(_mm_shuffle_ps((__m128)d.v0, (__m128)d.v0, 170), (__m128)dest.v2)),
             _mm_mul_ps(_mm_shuffle_ps((__m128)d.v0, (__m128)d.v0, 255), (__m128)dest.v3));
      v8 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)d.v1, (__m128)d.v1, 0), (__m128)dest.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps((__m128)d.v1, (__m128)d.v1, 85), (__m128)dest.v1)),
               _mm_mul_ps(_mm_shuffle_ps((__m128)d.v1, (__m128)d.v1, 170), (__m128)dest.v2)),
             _mm_mul_ps(_mm_shuffle_ps((__m128)d.v1, (__m128)d.v1, 255), (__m128)dest.v3));
      v9 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)d.v2, (__m128)d.v2, 0), (__m128)dest.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps((__m128)d.v2, (__m128)d.v2, 85), (__m128)dest.v1)),
               _mm_mul_ps(_mm_shuffle_ps((__m128)d.v2, (__m128)d.v2, 170), (__m128)dest.v2)),
             _mm_mul_ps(_mm_shuffle_ps((__m128)d.v2, (__m128)d.v2, 255), (__m128)dest.v3));
      v10 = _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps((__m128)d.v3, (__m128)d.v3, 255), (__m128)dest.v3),
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)d.v3, (__m128)d.v3, 0), (__m128)dest.v0), (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps((__m128)d.v3, (__m128)d.v3, 85), (__m128)dest.v1)),
                _mm_mul_ps(_mm_shuffle_ps((__m128)d.v3, (__m128)d.v3, 170), (__m128)dest.v2)));
      v15.v0 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), (__m128)m.v0), (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), (__m128)m.v1)),
                                  _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), (__m128)m.v2)),
                                _mm_mul_ps(_mm_shuffle_ps(v7, v7, 255), (__m128)m.v3));
      v15.v1 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), (__m128)m.v0), (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), (__m128)m.v1)),
                                  _mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), (__m128)m.v2)),
                                _mm_mul_ps(_mm_shuffle_ps(v8, v8, 255), (__m128)m.v3));
      v15.v2 = (UFG::qVector4)_mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v9, v9, 255), (__m128)m.v3),
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), (__m128)m.v0), (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), (__m128)m.v1)),
                                  _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), (__m128)m.v2)));
      v15.v3 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), (__m128)m.v1),
                                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), (__m128)m.v0), (__m128)0i64)),
                                  _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), (__m128)m.v2)),
                                _mm_mul_ps(_mm_shuffle_ps(v10, v10, 255), (__m128)m.v3));
      v11 = v4->Matrix;
      if ( v11 )
        UFG::qMatrix44::operator*=(&v15, v4->Matrix);
      v4->Matrix = &v15;
      UFG::DrawUIRenderQuad(v2, v4, &v3->mViewportScaleMatrix, 0x62F81854u, v3->mAlpha, 1.0);
      v4->Matrix = v11;
      ++v4;
    }
    while ( &v3->PolyListNativeNotClipped.p[v3->PolyListNativeNotClipped.size] != v4 );
  }
}

// File Line: 1329
// RVA: 0xC8D00
void __fastcall UFG::UITiledMapWidget::RenderMinimapBackdrop(UFG::UITiledMapWidget *this, Render::View *view, UFG::UIMapInteriorManager *interiorMan, UFG::UITiledMapTextureManager *textureMan, UFG::UIMapLinesWidget *MapLines)
{
  Render::View *v5; // rbx
  UFG::UITiledMapWidget *v6; // rdi

  v5 = view;
  v6 = this;
  UFG::UITiledMapWidget::RenderMinimap(this, view, interiorMan);
  if ( MapLines->mVisible )
    UFG::UITiledMapWidget::RenderMapLines(v6, v5, MapLines);
}

// File Line: 1342
// RVA: 0xC0820
void __fastcall UFG::UITiledMapWidget::Flash_GetWidgetScreenPosition(UFG::UITiledMapWidget *this, UFG::UIScreen *screen)
{
  UFG::UITiledMapWidget *v2; // rdi
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h]

  v2 = this;
  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    pval.pObjectInterface = 0i64;
    pval.Type = 0;
    Scaleform::GFx::Movie::GetVariable(v3, &pval, "circle_mask._width");
    v2->m_mapGeo.MaskRadius = pval.mValue.NValue * 0.5 * 1.5;
    Scaleform::GFx::Movie::GetVariable(v3, &pval, "circle_mask._x");
    v2->m_mapGeo.CircleMaskX = pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(v3, &pval, "circle_mask._y");
    v2->m_mapGeo.CircleMaskY = pval.mValue.NValue;
    if ( ((unsigned int)pval.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
  }
}

// File Line: 1361
// RVA: 0xCA800
void __fastcall UFG::UITiledMapWidget::SetGPSLineColor(UFG::qColour *color)
{
  float v1; // xmm3_4
  float v2; // xmm2_4
  float v3; // xmm1_4

  UFG::UITiledMapWidget::GPSLineColor.r = color->r;
  v1 = color->g;
  UFG::UITiledMapWidget::GPSLineColor.g = color->g;
  v2 = color->b;
  UFG::UITiledMapWidget::GPSLineColor.b = color->b;
  v3 = color->a;
  UFG::UITiledMapWidget::GPSLineColor.a = color->a;
  if ( UFG::UITiledMapWidget::GPSLineColor.r == UFG::qColour::White.r
    && v1 == UFG::qColour::White.g
    && v2 == UFG::qColour::White.b
    && v3 == UFG::qColour::White.a )
  {
    UFG::UITiledMapWidget::GPSLineColor = UFG::UITiledMapWidget::DefaultGPSLineColor;
  }
}

// File Line: 1373
// RVA: 0xC4B10
float __fastcall UFG::UITiledMapWidget::GetZoom(UFG::UITiledMapWidget *this)
{
  return UFG::UITiledMapTweakables::MinimapScaleTweak + this->m_mapGeo.scale;
}

