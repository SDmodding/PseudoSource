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
  UFG::qMatrix44 *p_mViewportScaleMatrix; // rcx

  this->mAlpha = 0.0;
  this->m_prevGeo.rot = -1000.0;
  this->m_prevGeo.playerRot = -1000.0;
  this->m_prevGeo.screenPosition.x = -15000.0;
  this->m_prevGeo.screenPosition.y = -15000.0;
  this->mViewportScale = UFG::gUIViewportScale;
  p_mViewportScaleMatrix = &this->mViewportScaleMatrix;
  p_mViewportScaleMatrix[1].v0.y = UFG::gUIViewportScaleH;
  p_mViewportScaleMatrix[1].v0.z = UFG::gUIViewportScaleV;
  UFG::UIGetViewportScaleMatrix(p_mViewportScaleMatrix, screen);
  if ( !this->mIsWorldMap )
    UFG::UITiledMapWidget::Flash_GetWidgetScreenPosition(this, screen);
}

// File Line: 125
// RVA: 0xCC8C0
void __fastcall UFG::UITiledMapWidget::Update(
        UFG::UITiledMapWidget *this,
        UFG::UIScreen *screen,
        float elapsed,
        UFG::UIMapBlipManager *blipMan,
        UFG::UIMapInteriorManager *interiorMan,
        UFG::UITiledMapTextureManager *textureMan,
        UFG::UITiledMapTextureManager *wideTextureMan,
        UFG::UITiledMapGPS *gps)
{
  UFG::qMatrix44 *p_mViewportScaleMatrix; // rcx
  UFG::UIScreenRenderable *mRenderable; // rax
  Scaleform::GFx::Movie *pObject; // rcx
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r14
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rsi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  _DWORD *p_x; // r12
  bool v19; // zf
  float mScale; // eax
  float y; // xmm1_4
  float x; // xmm0_4
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::Camera *p_mCamera; // rax
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float i; // xmm6_4
  float v32; // eax
  float v33; // xmm3_4
  float v34; // xmm5_4
  float v35; // xmm9_4
  UFG::UIAmbientMapBlipManager *Instance; // rax
  bool forceUpdate; // [rsp+50h] [rbp-89h]
  UFG::qVector3 v1; // [rsp+60h] [rbp-79h] BYREF
  UFG::qVector3 v39; // [rsp+70h] [rbp-69h] BYREF
  UFG::qVector3 v2; // [rsp+80h] [rbp-59h] BYREF
  UFG::MinimapPoint2f pos; // [rsp+120h] [rbp+47h]

  if ( UFG::gUIViewportScale != this->mViewportScale
    || UFG::gUIViewportScaleH != this->mViewportScaleH
    || UFG::gUIViewportScaleV != this->mViewportScaleV )
  {
    this->mViewportScale = UFG::gUIViewportScale;
    p_mViewportScaleMatrix = &this->mViewportScaleMatrix;
    p_mViewportScaleMatrix[1].v0.y = UFG::gUIViewportScaleH;
    p_mViewportScaleMatrix[1].v0.z = UFG::gUIViewportScaleV;
    UFG::UIGetViewportScaleMatrix(p_mViewportScaleMatrix, screen);
  }
  mRenderable = screen->mRenderable;
  if ( mRenderable )
  {
    if ( mRenderable->m_shouldRender )
    {
      pObject = mRenderable->m_movie.pObject;
      if ( pObject )
      {
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Movie *))pObject->Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[10].__vecDelDtor)(pObject) )
        {
          LocalPlayer = UFG::GetLocalPlayer();
          if ( LocalPlayer )
          {
            m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
            if ( m_pTransformNodeComponent )
            {
              m_Flags = LocalPlayer->m_Flags;
              if ( (m_Flags & 0x4000) != 0 )
              {
                m_pComponent = LocalPlayer->m_Components.p[44].m_pComponent;
              }
              else
              {
                if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
                  ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                        LocalPlayer,
                                        UFG::CharacterOccupantComponent::_TypeUID);
                else
                  ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                        LocalPlayer,
                                        UFG::CharacterOccupantComponent::_TypeUID);
                m_pComponent = ComponentOfTypeHK;
              }
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
              p_x = (_DWORD *)&m_pTransformNodeComponent->mWorldTransform.v3.x;
              UFG::UIMapInteriorManager::Update(
                interiorMan,
                screen,
                (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
                this,
                textureMan);
              v19 = gps->mInteriorActive == interiorMan->mActive;
              gps->mInteriorActive = interiorMan->mActive;
              gps->mChanged |= !v19;
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
              UFG::UITiledMapZoomCalc::Update(
                &this->ZoomCalc,
                elapsed,
                &m_pTransformNodeComponent->mWorldVelocity,
                m_pComponent == 0i64,
                interiorMan);
              mScale = this->ZoomCalc.mScale;
              this->forceUpdate = 0;
              v2.x = 0.0;
              *(_QWORD *)&v2.y = 1065353216i64;
              this->m_mapGeo.scale = mScale;
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
              y = m_pTransformNodeComponent->mWorldTransform.v0.y;
              x = m_pTransformNodeComponent->mWorldTransform.v0.x;
              v39.z = 0.0;
              v39.x = x;
              v39.y = y;
              mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
              if ( mCurrentCamera )
                p_mCamera = &mCurrentCamera->mCamera;
              else
                p_mCamera = 0i64;
              v25 = p_mCamera->mTransformation.v2.y;
              v26 = p_mCamera->mTransformation.v2.x;
              v1.z = 0.0;
              LODWORD(v1.x) = LODWORD(v26) ^ _xmm[0];
              LODWORD(v1.y) = LODWORD(v25) ^ _xmm[0];
              v27 = UFG::qAngleBetween(&v1, &v2);
              v28 = v1.x;
              this->m_mapGeo.rot = v27;
              if ( v28 > 0.0 )
                LODWORD(this->m_mapGeo.rot) = LODWORD(v27) ^ _xmm[0];
              v29 = UFG::qAngleBetween(&v39, &v1);
              v30 = FLOAT_N1_0;
              if ( (float)((float)(v39.y * v1.x) - (float)(v1.y * v39.x)) < 0.0 )
                v30 = *(float *)&FLOAT_1_0;
              for ( i = (float)((float)(v29 * 180.0) * 0.31830987) * v30; i < -180.0; i = i + 360.0 )
                ;
              for ( ; i > 180.0; i = i + -360.0 )
                ;
              if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)p_x - this->m_prevGeo.centerPosition.x) & _xmm) > UFG::UITiledMapTweakables::PlayerPosDiff
                || COERCE_FLOAT(COERCE_UNSIGNED_INT(m_pTransformNodeComponent->mWorldTransform.v3.y - this->m_prevGeo.centerPosition.y) & _xmm) > UFG::UITiledMapTweakables::PlayerPosDiff
                || COERCE_FLOAT(COERCE_UNSIGNED_INT(this->m_mapGeo.rot - this->m_prevGeo.rot) & _xmm) > UFG::UITiledMapTweakables::CameraHeadingDiff
                || COERCE_FLOAT(COERCE_UNSIGNED_INT(i - this->m_prevGeo.playerRot) & _xmm) > UFG::UITiledMapTweakables::PlayerHeadingDiff
                || COERCE_FLOAT(COERCE_UNSIGNED_INT(this->m_mapGeo.scale - this->m_prevGeo.scale) & _xmm) > UFG::UITiledMapTweakables::MapScaleDiff
                || UFG::UITiledMapTweakables::MinimapForceUpdateEveryFrame )
              {
                v32 = this->m_mapGeo.screenPosition.x;
                this->forceUpdate = 1;
                this->m_prevGeo.screenPosition.x = v32;
                this->m_prevGeo.screenPosition.y = this->m_mapGeo.screenPosition.y;
                this->m_prevGeo.centerPosition.x = this->m_mapGeo.centerPosition.x;
                this->m_prevGeo.centerPosition.y = this->m_mapGeo.centerPosition.y;
                this->m_prevGeo.rot = this->m_mapGeo.rot;
                this->m_prevGeo.playerRot = this->m_mapGeo.playerRot;
                this->m_prevGeo.scale = this->m_mapGeo.scale;
                *(_DWORD *)&this->m_prevGeo.useWideTiles = *(_DWORD *)&this->m_mapGeo.useWideTiles;
                this->m_prevGeo.CircleMaskX = this->m_mapGeo.CircleMaskX;
                this->m_prevGeo.CircleMaskY = this->m_mapGeo.CircleMaskY;
                this->m_prevGeo.MaskRadius = this->m_mapGeo.MaskRadius;
                this->m_prevGeo.m_rowOffset = this->m_mapGeo.m_rowOffset;
                this->m_prevGeo.m_colOffset = this->m_mapGeo.m_colOffset;
                *(_DWORD *)&this->m_prevGeo.IsWorldMap = *(_DWORD *)&this->m_mapGeo.IsWorldMap;
              }
              v33 = *(float *)p_x;
              v34 = m_pTransformNodeComponent->mWorldTransform.v3.y;
              this->m_mapGeo.centerPosition = (UFG::WorldPoint2f)__PAIR64__(LODWORD(v34), *p_x);
              v35 = 1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX);
              pos.x = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                             UFG::UITiledMapMath::WorldGeo.TextureWidth
                                           * UFG::UITiledMapMath::WorldGeo.MinX) ^ _xmm[0])
                            * v35)
                    + (float)((float)(v35 * UFG::UITiledMapMath::WorldGeo.TextureWidth) * v33);
              pos.y = (float)((float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
                            / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY))
                    + (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v35 * UFG::UITiledMapMath::WorldGeo.TextureWidth) ^ _xmm[0])
                            * v34);
              UFG::UITiledMapWidget::setMapPosition(this, pos, i, textureMan, wideTextureMan, 0);
              Instance = UFG::UIAmbientMapBlipManager::getInstance();
              UFG::UIAmbientMapBlipManager::Update(Instance, elapsed, blipMan, 0);
              forceUpdate = this->forceUpdate;
              this->PolyListNativeClipped.size = 0;
              this->PolyListNativeNotClipped.size = 0;
              this->PolyListNativeDoubleClipped.size = 0;
              UFG::UIMapBlipManager::Update(
                blipMan,
                screen,
                elapsed,
                (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
                &this->m_mapGeo,
                &this->m_mapIconGeo,
                &this->PolyListNativeClipped,
                &this->PolyListNativeNotClipped,
                &this->PolyListNativeDoubleClipped,
                interiorMan->mActive,
                forceUpdate);
              UFG::UITiledMapGPS::Update(gps, elapsed, screen, &this->m_mapIconGeo);
            }
          }
        }
      }
    }
  }
}

// File Line: 237
// RVA: 0xCEA10
void __fastcall UFG::UITiledMapWidget::UpdateWorldMap(
        UFG::UITiledMapWidget *this,
        UFG::UIScreen *screen,
        UFG::UITiledMapMath *mapGeo)
{
  UFG::qMatrix44 *p_mViewportScaleMatrix; // rcx

  if ( UFG::gUIViewportScale != this->mViewportScale
    || UFG::gUIViewportScaleH != this->mViewportScaleH
    || UFG::gUIViewportScaleV != this->mViewportScaleV )
  {
    this->mViewportScale = UFG::gUIViewportScale;
    p_mViewportScaleMatrix = &this->mViewportScaleMatrix;
    p_mViewportScaleMatrix[1].v0.y = UFG::gUIViewportScaleH;
    p_mViewportScaleMatrix[1].v0.z = UFG::gUIViewportScaleV;
    UFG::UIGetViewportScaleMatrix(p_mViewportScaleMatrix, screen);
  }
  this->m_mapGeo.screenPosition.x = mapGeo->screenPosition.x;
  this->m_mapGeo.screenPosition.y = mapGeo->screenPosition.y;
  this->m_mapGeo.centerPosition.x = mapGeo->centerPosition.x;
  this->m_mapGeo.centerPosition.y = mapGeo->centerPosition.y;
  this->m_mapGeo.rot = mapGeo->rot;
  this->m_mapGeo.playerRot = mapGeo->playerRot;
  this->m_mapGeo.scale = mapGeo->scale;
  *(_DWORD *)&this->m_mapGeo.useWideTiles = *(_DWORD *)&mapGeo->useWideTiles;
  this->m_mapGeo.CircleMaskX = mapGeo->CircleMaskX;
  this->m_mapGeo.CircleMaskY = mapGeo->CircleMaskY;
  this->m_mapGeo.MaskRadius = mapGeo->MaskRadius;
  this->m_mapGeo.m_rowOffset = mapGeo->m_rowOffset;
  this->m_mapGeo.m_colOffset = mapGeo->m_colOffset;
  *(_DWORD *)&this->m_mapGeo.IsWorldMap = *(_DWORD *)&mapGeo->IsWorldMap;
}

// File Line: 259
// RVA: 0xC7330
void __fastcall UFG::UITiledMapWidget::Render(
        UFG::UITiledMapWidget *this,
        Render::View *view,
        UFG::UIMapBlipManager *blipMan,
        UFG::UIMapInteriorManager *interiorMan,
        UFG::UITiledMapGPS *GPS,
        UFG::UIMapLinesWidget *MapLines,
        UFG::UITiledMapRaceSplines *RacePath)
{
  float mAlpha; // xmm1_4
  unsigned int m_NumSplinePoints; // r8d
  UFG::qColour v12; // [rsp+30h] [rbp-18h] BYREF

  UFG::UITiledMapWidget::RenderNorth(this, view);
  UFG::UITiledMapWidget::RenderBlipRanges(this, view);
  if ( UFG::UITiledMapWidget::gMinimapRaceRouteVisible )
  {
    mAlpha = this->mAlpha;
    m_NumSplinePoints = RacePath->m_NumSplinePoints;
    v12 = UFG::UITiledMapWidget::RaceRouteColor;
    v12.a = mAlpha;
    UFG::UITiledMapWidget::RenderSpline(this, &RacePath->m_SplinePoints, m_NumSplinePoints, &v12, view);
  }
  else if ( !GPS->mActive
         || GPS->mInteriorActive
         || GPS->mOnlyShowInVehicles && !UFG::UI::IsPlayerInVehicle()
         || UFG::UI::IsPlayerInWater()
         || !GPS->mVisible )
  {
    if ( UI_BLIP_GPS_DESTINATION && UFG::qBaseTreeRB::Get(&blipMan->mIconList.mIconData.mTree, UI_BLIP_GPS_DESTINATION) )
      UFG::UIMapBlipManager::RemoveIcon(blipMan, UI_BLIP_GPS_DESTINATION);
  }
  else
  {
    UFG::UITiledMapWidget::RenderGPSSpline(this, view, GPS, blipMan);
  }
  UFG::UITiledMapWidget::RenderBlips(this, view);
}

// File Line: 459
// RVA: 0xBFAD0
void __fastcall UFG::DrawClippedPolys(
        Render::View *view,
        UFG::ClipRect *rects,
        int rect_count,
        UFG::qColour *Color,
        unsigned int TextureUID,
        unsigned int AlphaStateUID,
        unsigned int RasterStateUID,
        UFG::qMatrix44 *TransformMatrix)
{
  __int64 v11; // rsi
  Illusion::Material *SimpleMaterial; // r15
  float *p_y0; // rbx
  Render::vDynamic *mVertices; // rax
  float y; // xmm2_4
  float v16; // xmm6_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm6_4
  Render::vDynamic *v20; // rax
  float v21; // xmm2_4
  float v22; // xmm6_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm6_4
  Render::vDynamic *v26; // rax
  float v27; // xmm2_4
  float v28; // xmm6_4
  Render::vDynamic *v29; // rax
  float v30; // xmm2_4
  float v31; // xmm6_4
  Render::Poly poly; // [rsp+30h] [rbp-48h] BYREF

  v11 = rect_count;
  SimpleMaterial = Render::View::CreateSimpleMaterial(TextureUID, RasterStateUID, AlphaStateUID, 0);
  if ( (int)v11 > 0 )
  {
    p_y0 = &rects->y0;
    do
    {
      Render::Poly::Poly(&poly, *(p_y0 - 4), *p_y0, *(p_y0 - 2) - *(p_y0 - 4), p_y0[2] - *p_y0, 0.0);
      Render::Poly::SetColour(&poly, Color);
      Render::Poly::SetUVs(&poly, *(p_y0 - 3), p_y0[1], *(p_y0 - 1) - *(p_y0 - 3), p_y0[3] - p_y0[1]);
      if ( TransformMatrix )
      {
        mVertices = poly.mVertices;
        y = poly.mVertices->mPosition.y;
        v16 = y * TransformMatrix->v1.z;
        v17 = y * TransformMatrix->v1.x;
        v18 = (float)((float)((float)(y * TransformMatrix->v1.y)
                            + (float)(poly.mVertices->mPosition.x * TransformMatrix->v0.y))
                    + (float)(poly.mVertices->mPosition.z * TransformMatrix->v2.y))
            + TransformMatrix->v3.y;
        v19 = (float)((float)(v16 + (float)(poly.mVertices->mPosition.x * TransformMatrix->v0.z))
                    + (float)(poly.mVertices->mPosition.z * TransformMatrix->v2.z))
            + TransformMatrix->v3.z;
        poly.mVertices->mPosition.x = (float)((float)((float)(poly.mVertices->mPosition.x * TransformMatrix->v0.x) + v17)
                                            + (float)(poly.mVertices->mPosition.z * TransformMatrix->v2.x))
                                    + TransformMatrix->v3.x;
        mVertices->mPosition.y = v18;
        mVertices->mPosition.z = v19;
        v20 = poly.mVertices;
        v21 = poly.mVertices[1].mPosition.y;
        v22 = v21 * TransformMatrix->v1.z;
        v23 = v21 * TransformMatrix->v1.x;
        v24 = (float)((float)((float)(v21 * TransformMatrix->v1.y)
                            + (float)(poly.mVertices[1].mPosition.x * TransformMatrix->v0.y))
                    + (float)(poly.mVertices[1].mPosition.z * TransformMatrix->v2.y))
            + TransformMatrix->v3.y;
        v25 = (float)((float)(v22 + (float)(poly.mVertices[1].mPosition.x * TransformMatrix->v0.z))
                    + (float)(poly.mVertices[1].mPosition.z * TransformMatrix->v2.z))
            + TransformMatrix->v3.z;
        poly.mVertices[1].mPosition.x = (float)((float)((float)(poly.mVertices[1].mPosition.x * TransformMatrix->v0.x)
                                                      + v23)
                                              + (float)(poly.mVertices[1].mPosition.z * TransformMatrix->v2.x))
                                      + TransformMatrix->v3.x;
        v20[1].mPosition.y = v24;
        v20[1].mPosition.z = v25;
        v26 = poly.mVertices;
        v27 = (float)((float)((float)(poly.mVertices[2].mPosition.y * TransformMatrix->v1.y)
                            + (float)(poly.mVertices[2].mPosition.x * TransformMatrix->v0.y))
                    + (float)(poly.mVertices[2].mPosition.z * TransformMatrix->v2.y))
            + TransformMatrix->v3.y;
        v28 = (float)((float)((float)(poly.mVertices[2].mPosition.y * TransformMatrix->v1.z)
                            + (float)(poly.mVertices[2].mPosition.x * TransformMatrix->v0.z))
                    + (float)(poly.mVertices[2].mPosition.z * TransformMatrix->v2.z))
            + TransformMatrix->v3.z;
        poly.mVertices[2].mPosition.x = (float)((float)((float)(poly.mVertices[2].mPosition.x * TransformMatrix->v0.x)
                                                      + (float)(poly.mVertices[2].mPosition.y * TransformMatrix->v1.x))
                                              + (float)(poly.mVertices[2].mPosition.z * TransformMatrix->v2.x))
                                      + TransformMatrix->v3.x;
        v26[2].mPosition.y = v27;
        v26[2].mPosition.z = v28;
        v29 = poly.mVertices;
        v30 = (float)((float)((float)(poly.mVertices[3].mPosition.y * TransformMatrix->v1.y)
                            + (float)(poly.mVertices[3].mPosition.x * TransformMatrix->v0.y))
                    + (float)(poly.mVertices[3].mPosition.z * TransformMatrix->v2.y))
            + TransformMatrix->v3.y;
        v31 = (float)((float)((float)(poly.mVertices[3].mPosition.y * TransformMatrix->v1.z)
                            + (float)(poly.mVertices[3].mPosition.x * TransformMatrix->v0.z))
                    + (float)(poly.mVertices[3].mPosition.z * TransformMatrix->v2.z))
            + TransformMatrix->v3.z;
        poly.mVertices[3].mPosition.x = (float)((float)((float)(poly.mVertices[3].mPosition.x * TransformMatrix->v0.x)
                                                      + (float)(poly.mVertices[3].mPosition.y * TransformMatrix->v1.x))
                                              + (float)(poly.mVertices[3].mPosition.z * TransformMatrix->v2.x))
                                      + TransformMatrix->v3.x;
        v29[3].mPosition.y = v30;
        v29[3].mPosition.z = v31;
      }
      poly.mVertices->mPosition.x = poly.mVertices->mPosition.x
                                  / (float)(int)UFG::UIScreenManager::s_instance->m_flashWidth;
      poly.mVertices->mPosition.y = poly.mVertices->mPosition.y
                                  / (float)(int)UFG::UIScreenManager::s_instance->m_flashHeight;
      poly.mVertices[1].mPosition.x = poly.mVertices[1].mPosition.x
                                    / (float)(int)UFG::UIScreenManager::s_instance->m_flashWidth;
      poly.mVertices[1].mPosition.y = poly.mVertices[1].mPosition.y
                                    / (float)(int)UFG::UIScreenManager::s_instance->m_flashHeight;
      poly.mVertices[2].mPosition.x = poly.mVertices[2].mPosition.x
                                    / (float)(int)UFG::UIScreenManager::s_instance->m_flashWidth;
      poly.mVertices[2].mPosition.y = poly.mVertices[2].mPosition.y
                                    / (float)(int)UFG::UIScreenManager::s_instance->m_flashHeight;
      poly.mVertices[3].mPosition.x = poly.mVertices[3].mPosition.x
                                    / (float)(int)UFG::UIScreenManager::s_instance->m_flashWidth;
      poly.mVertices[3].mPosition.y = poly.mVertices[3].mPosition.y
                                    / (float)(int)UFG::UIScreenManager::s_instance->m_flashHeight;
      Render::View::Draw(view, &poly, SimpleMaterial, 0i64);
      p_y0 += 10;
      --v11;
    }
    while ( v11 );
  }
}

// File Line: 500
// RVA: 0xBF7E0
void __fastcall UFG::UITiledMapWidget::DrawClipRects(
        UFG::UITiledMapWidget *this,
        Render::View *view,
        UFG::qColour *Color,
        unsigned int AlphaStateUID,
        unsigned int RasterStateUID,
        UFG::qMatrix44 *TransformMatrix)
{
  __int64 v10; // rdi
  float v11; // xmm2_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  UFG::qBaseTreeRB *i; // rdx
  __int64 v15; // r8
  float MaxX; // xmm0_4
  float TextureWidth; // xmm5_4
  UFG::qBaseNodeRB *v18; // rcx
  __m128i v19; // xmm1
  unsigned int v20; // eax
  float v21; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  __m128i v25; // xmm0
  int mParent_high; // eax
  int v27; // xmm5_4
  float v28; // xmm2_4
  int v29; // xmm2_4
  int *v30; // rbx
  __int128 v31; // xmm1
  int v32[8]; // [rsp+40h] [rbp-C68h] BYREF
  __int64 v33[32]; // [rsp+60h] [rbp-C48h]
  UFG::ClipRect rects; // [rsp+160h] [rbp-B48h] BYREF

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
      MaxX = UFG::UITiledMapMath::WorldGeo.MaxX;
      TextureWidth = UFG::UITiledMapMath::WorldGeo.TextureWidth;
      v18 = i[1].mNULL.mChild[1];
      v19 = _mm_cvtsi32_si128(this->m_mapGeo.m_rowOffset);
      v32[10 * v10 + 1] = 0;
      v20 = WORD2(v18[3].mParent);
      v32[10 * v10 + 5] = 0;
      v32[10 * v10 + 3] = 1065353216;
      v21 = MaxX - UFG::UITiledMapMath::WorldGeo.MinX;
      v22 = *(float *)&i[1].mRoot.mChild[1];
      v32[10 * v10 + 7] = 1065353216;
      v33[5 * v10] = (__int64)i;
      v10 = (unsigned int)(v10 + 1);
      v23 = (float)(1.0 / v21) * TextureWidth;
      v24 = (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(TextureWidth * UFG::UITiledMapMath::WorldGeo.MinX) ^ _xmm[0])
                          * (float)(1.0 / v21))
                  + (float)(v22 * v23))
          - (float)this->m_mapGeo.m_colOffset;
      v25 = _mm_cvtsi32_si128(v20);
      mParent_high = HIWORD(v18[3].mParent);
      *(float *)&v27 = v24 - v12;
      v28 = (float)((float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
                  / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY))
          + (float)(COERCE_FLOAT(LODWORD(v23) ^ _xmm[0]) * *((float *)&i[1].mRoot.mChild[1] + 1));
      v32[2 * v15] = v27;
      *(float *)&v29 = (float)(v28 - _mm_cvtepi32_ps(v19).m128_f32[0]) - v13;
      *(float *)&v32[2 * v15 + 2] = _mm_cvtepi32_ps(v25).m128_f32[0] + *(float *)&v27;
      v32[2 * v15 + 4] = v29;
      *(float *)&v32[2 * v15 + 6] = (float)mParent_high + *(float *)&v29;
    }
  }
  if ( (_DWORD)v10 )
  {
    v30 = v32;
    do
    {
      v31 = *((_OWORD *)v30 + 1);
      *(_OWORD *)&rects.x0 = *(_OWORD *)v30;
      *(_OWORD *)&rects.y0 = v31;
      rects.tile = (UFG::UIMinimapTile *)*((_QWORD *)v30 + 4);
      UFG::DrawClippedPolys(
        view,
        &rects,
        1,
        Color,
        rects.tile->mMapTileHandle.mNameUID,
        AlphaStateUID,
        RasterStateUID,
        TransformMatrix);
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
  UFG::qMatrix44 v4; // [rsp+70h] [rbp-168h] BYREF
  UFG::qMatrix44 v5; // [rsp+B0h] [rbp-128h] BYREF
  UFG::qMatrix44 dest; // [rsp+F0h] [rbp-E8h] BYREF
  UFG::qMatrix44 result; // [rsp+130h] [rbp-A8h] BYREF

  if ( (_S7_2 & 1) == 0 )
  {
    _S7_2 |= 1u;
    NorthIconTextureUID = UFG::qStringHashUpper32("Icon_North", 0xFFFFFFFF);
  }
  UFG::qRotationMatrixZ(&dest, this->m_mapGeo.rot);
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
  UFG::qMatrix44::operator*(&v5, &result, &this->mViewportScaleMatrix);
  UFG::DrawColoredRect_Xform(
    view,
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
void __fastcall UFG::UITiledMapWidget::RenderMinimap(
        UFG::UITiledMapWidget *this,
        Render::View *view,
        UFG::UIMapInteriorManager *interiorMan)
{
  bool v6; // r15
  float b; // xmm0_4
  float a; // xmm1_4
  unsigned int v9; // esi
  bool useWideTiles; // al
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  __m128 v14; // xmm5
  __m128 v15; // xmm6
  __m128 v16; // xmm4
  __m128 v17; // xmm11
  float TextureWidth; // xmm7_4
  unsigned int TextureUID; // r15d
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm8_4
  float v24; // xmm3_4
  bool v25; // al
  float v26; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  __m128 v29; // xmm5
  __m128 v30; // xmm6
  __m128 v31; // xmm4
  __m128 v32; // xmm11
  __m128 v33; // xmm5
  __m128 v34; // xmm6
  __m128 v35; // xmm4
  __m128 v36; // xmm11
  __m128 v37; // xmm5
  __m128 v38; // xmm6
  __m128 v39; // xmm4
  __m128 v40; // xmm11
  UFG::qColour v41; // [rsp+58h] [rbp-80h] BYREF
  UFG::qMatrix44 Color; // [rsp+68h] [rbp-70h] BYREF
  UFG::qMatrix44 v43; // [rsp+A8h] [rbp-30h] BYREF
  UFG::qMatrix44 v44; // [rsp+E8h] [rbp+10h] BYREF
  __int64 v45; // [rsp+128h] [rbp+50h]
  UFG::qMatrix44 v46; // [rsp+138h] [rbp+60h] BYREF
  UFG::qMatrix44 v47; // [rsp+178h] [rbp+A0h] BYREF
  UFG::qMatrix44 v48; // [rsp+1B8h] [rbp+E0h] BYREF
  UFG::qMatrix44 dest; // [rsp+1F8h] [rbp+120h] BYREF
  UFG::qMatrix44 result; // [rsp+238h] [rbp+160h] BYREF

  v45 = -2i64;
  if ( (_S8_0 & 1) == 0 )
  {
    _S8_0 |= 1u;
    BackgroundTextureUID = UFG::qStringHashUpper32("FX_Circle_Fill", 0xFFFFFFFF);
  }
  v6 = !interiorMan->mActive;
  v41 = UFG::qColour::White;
  v41.a = this->mAlpha;
  Render::View::Clear(view, &UFG::qColour::Black, 4u, 1.0, 0);
  if ( v6 )
  {
    Color.v0.z = UFG::qColour::Black.r;
    Color.v0.w = UFG::qColour::Black.g;
    b = UFG::qColour::Black.b;
    a = UFG::qColour::Black.a;
  }
  else
  {
    Color.v0.z = UFG::qColour::White.r;
    Color.v0.w = UFG::qColour::White.g;
    b = UFG::qColour::White.b;
    a = UFG::qColour::White.a;
  }
  Color.v1.y = a;
  Color.v1.x = b;
  Color.v1.y = UFG::UITiledMapWidget::gMinimapBackgroundAlpha * this->mAlpha;
  v9 = 1660426324;
  UFG::DrawColoredRect_Xform(
    view,
    (float)(int)(float)(UFG::UITiledMapWidget::gMinimapCenter.x
                      - (float)((float)UFG::UITiledMapWidget::gMinimapBackgroundSize * 0.5)),
    (float)(int)(float)(UFG::UITiledMapWidget::gMinimapCenter.y
                      - (float)((float)UFG::UITiledMapWidget::gMinimapBackgroundSize * 0.5)),
    (float)UFG::UITiledMapWidget::gMinimapBackgroundSize,
    (float)UFG::UITiledMapWidget::gMinimapBackgroundSize,
    (UFG::qColour *)&Color.v0.z,
    BackgroundTextureUID,
    0i64,
    0xA3833FDE,
    0x62F81854u,
    &this->mViewportScaleMatrix);
  Render::View::SetSimpleMaterialShader(UFG::gUIshader_Punch_Simple_UID);
  UFG::DrawColoredRect_Xform(
    view,
    (float)(int)(float)(UFG::UITiledMapWidget::gMinimapCenter.x
                      - (float)((float)UFG::UITiledMapWidget::gMinimapBackgroundSize * 0.5)),
    (float)(int)(float)(UFG::UITiledMapWidget::gMinimapCenter.y
                      - (float)((float)UFG::UITiledMapWidget::gMinimapBackgroundSize * 0.5)),
    (float)UFG::UITiledMapWidget::gMinimapBackgroundSize,
    (float)UFG::UITiledMapWidget::gMinimapBackgroundSize,
    &UFG::qColour::White,
    BackgroundTextureUID,
    0i64,
    0x91A2DD53,
    UFG::gUIrasterState_Set_Mask1_UID,
    &this->mViewportScaleMatrix);
  Render::View::SetSimpleMaterialShader(UFG::gUIshader_Simple_UID);
  UFG::qRotationMatrixZ(&dest, this->m_mapGeo.rot);
  UFG::qTranslationMatrix(&v44, &UFG::UITiledMapWidget::gMinimapCenter);
  if ( v6 )
  {
    useWideTiles = this->m_mapGeo.useWideTiles;
    v11 = FLOAT_0_5;
    if ( useWideTiles )
      v12 = FLOAT_0_5;
    else
      v12 = 0.0;
    v13 = UFG::UITiledMapTweakables::MinimapScaleTweak + this->m_mapGeo.scale;
    if ( !useWideTiles )
      v11 = 0.0;
    v41.b = v13 + v11;
    v41.a = v13 + v12;
    Color.v0.x = 1.0;
    UFG::qScaleMatrix(&v43, (UFG::qVector3 *)&v41.b);
    v14 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v43.v0, (__m128)v43.v0, 0), (__m128)dest.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v43.v0, (__m128)v43.v0, 85), (__m128)dest.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v43.v0, (__m128)v43.v0, 170), (__m128)dest.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v43.v0, (__m128)v43.v0, 255), (__m128)dest.v3));
    v15 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v43.v1, (__m128)v43.v1, 0), (__m128)dest.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v43.v1, (__m128)v43.v1, 85), (__m128)dest.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v43.v1, (__m128)v43.v1, 170), (__m128)dest.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v43.v1, (__m128)v43.v1, 255), (__m128)dest.v3));
    v16 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v43.v2, (__m128)v43.v2, 0), (__m128)dest.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v43.v2, (__m128)v43.v2, 85), (__m128)dest.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v43.v2, (__m128)v43.v2, 170), (__m128)dest.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v43.v2, (__m128)v43.v2, 255), (__m128)dest.v3));
    v17 = _mm_add_ps(
            _mm_mul_ps((__m128)dest.v3, _mm_shuffle_ps((__m128)v43.v3, (__m128)v43.v3, 255)),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v43.v3, (__m128)v43.v3, 0), (__m128)dest.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v43.v3, (__m128)v43.v3, 85), (__m128)dest.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v43.v3, (__m128)v43.v3, 170), (__m128)dest.v2)));
    Color.v0 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), (__m128)v44.v0), (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), (__m128)v44.v1)),
                                  _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), (__m128)v44.v2)),
                                _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), (__m128)v44.v3));
    Color.v1 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), (__m128)v44.v0), (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), (__m128)v44.v1)),
                                  _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), (__m128)v44.v2)),
                                _mm_mul_ps(_mm_shuffle_ps(v15, v15, 255), (__m128)v44.v3));
    Color.v2 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), (__m128)v44.v0), (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), (__m128)v44.v1)),
                                  _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), (__m128)v44.v2)),
                                _mm_mul_ps(_mm_shuffle_ps(v16, v16, 255), (__m128)v44.v3));
    Color.v3 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), (__m128)v44.v0), (__m128)0i64),
                                    _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), (__m128)v44.v1)),
                                  _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), (__m128)v44.v2)),
                                _mm_mul_ps(_mm_shuffle_ps(v17, v17, 255), (__m128)v44.v3));
    Color = *UFG::qMatrix44::operator*(&Color, &result, &this->mViewportScaleMatrix);
    if ( UFG::UITiledMapTweakables::MinimapRenderMask )
      v9 = UFG::gUIrasterState_Test_Mask_UID;
    UFG::UITiledMapWidget::DrawClipRects(this, view, &v41, 0xA3833FDE, v9, &Color);
  }
  else
  {
    TextureWidth = UFG::UITiledMapMath::WorldGeo.TextureWidth;
    TextureUID = UFG::qStringHashUpper32((const char *)interiorMan->mTextureName.mData + 6, 0xFFFFFFFF);
    v20 = TextureWidth * 0.0078125;
    v21 = UFG::UITiledMapTweakables::InteriorMapScaleTweak + v20;
    v22 = v20 * 64.0;
    v23 = 1.0 / (float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX);
    v24 = (float)((float)((float)(UFG::UITiledMapMath::WorldGeo.TextureHeight * UFG::UITiledMapMath::WorldGeo.MaxY)
                        / (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY))
                + (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v23 * UFG::UITiledMapMath::WorldGeo.TextureWidth) ^ _xmm[0])
                        * this->m_mapGeo.centerPosition.y))
        - (float)this->m_mapGeo.m_rowOffset;
    v41.b = (float)(v22
                  - (float)((float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                                           UFG::UITiledMapMath::WorldGeo.MinX
                                                         * UFG::UITiledMapMath::WorldGeo.TextureWidth) ^ _xmm[0])
                                          * v23)
                                  + (float)((float)(v23 * UFG::UITiledMapMath::WorldGeo.TextureWidth)
                                          * this->m_mapGeo.centerPosition.x))
                          - (float)this->m_mapGeo.m_colOffset))
          + UFG::UITiledMapTweakables::InteriorMapXOffsetTweak;
    v41.a = (float)(v22 - v24) + UFG::UITiledMapTweakables::InteriorMapYOffsetTweak;
    Color.v0.x = 0.0;
    UFG::qTranslationMatrix(&v43, (UFG::qVector3 *)&v41.b);
    v41.b = v21;
    v41.a = v21;
    Color.v0.x = 1.0;
    UFG::qScaleMatrix(&Color, (UFG::qVector3 *)&v41.b);
    v25 = this->m_mapGeo.useWideTiles;
    v26 = FLOAT_0_5;
    if ( v25 )
      v27 = FLOAT_0_5;
    else
      v27 = 0.0;
    v28 = UFG::UITiledMapTweakables::MinimapScaleTweak + this->m_mapGeo.scale;
    if ( !v25 )
      v26 = 0.0;
    v41.b = v28 + v26;
    v41.a = v28 + v27;
    Color.v0.x = 1.0;
    UFG::qScaleMatrix(&v46, (UFG::qVector3 *)&v41.b);
    UFG::qRotationMatrixZ(&v47, UFG::UITiledMapTweakables::InteriorMapRotationTweak + this->m_mapGeo.rot);
    v29 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v0, (__m128)Color.v0, 0), (__m128)v43.v0),
                  (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v0, (__m128)Color.v0, 85), (__m128)v43.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v0, (__m128)Color.v0, 170), (__m128)v43.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v0, (__m128)Color.v0, 255), (__m128)v43.v3));
    v30 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v1, (__m128)Color.v1, 0), (__m128)v43.v0),
                  (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v1, (__m128)Color.v1, 85), (__m128)v43.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v1, (__m128)Color.v1, 170), (__m128)v43.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v1, (__m128)Color.v1, 255), (__m128)v43.v3));
    v31 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v2, (__m128)Color.v2, 0), (__m128)v43.v0),
                  (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v2, (__m128)Color.v2, 85), (__m128)v43.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v2, (__m128)Color.v2, 170), (__m128)v43.v2)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v2, (__m128)Color.v2, 255), (__m128)v43.v3));
    v32 = _mm_add_ps(
            _mm_mul_ps((__m128)v43.v3, _mm_shuffle_ps((__m128)Color.v3, (__m128)Color.v3, 255)),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v3, (__m128)Color.v3, 0), (__m128)v43.v0),
                  (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v3, (__m128)Color.v3, 85), (__m128)v43.v1)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)Color.v3, (__m128)Color.v3, 170), (__m128)v43.v2)));
    v33 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v29, v29, 255), (__m128)v46.v3),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), (__m128)v46.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), (__m128)v46.v1)),
              _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), (__m128)v46.v2)));
    v34 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), (__m128)v46.v3),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), (__m128)v46.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), (__m128)v46.v1)),
              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), (__m128)v46.v2)));
    v35 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v31, v31, 255), (__m128)v46.v3),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), (__m128)v46.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), (__m128)v46.v1)),
              _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), (__m128)v46.v2)));
    v36 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v32, v32, 255), (__m128)v46.v3),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), (__m128)v46.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), (__m128)v46.v1)),
              _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), (__m128)v46.v2)));
    v37 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v33, v33, 255), (__m128)v47.v3),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), (__m128)v47.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), (__m128)v47.v1)),
              _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), (__m128)v47.v2)));
    v38 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v34, v34, 255), (__m128)v47.v3),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), (__m128)v47.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), (__m128)v47.v1)),
              _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), (__m128)v47.v2)));
    v39 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v35, v35, 255), (__m128)v47.v3),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), (__m128)v47.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v35, v35, 85), (__m128)v47.v1)),
              _mm_mul_ps(_mm_shuffle_ps(v35, v35, 170), (__m128)v47.v2)));
    v40 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v36, v36, 255), (__m128)v47.v3),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v36, v36, 0), (__m128)v47.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v36, v36, 85), (__m128)v47.v1)),
              _mm_mul_ps(_mm_shuffle_ps(v36, v36, 170), (__m128)v47.v2)));
    v48.v0 = (UFG::qVector4)_mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), (__m128)v44.v0), (__m128)0i64),
                                  _mm_mul_ps(_mm_shuffle_ps(v37, v37, 85), (__m128)v44.v1)),
                                _mm_mul_ps(_mm_shuffle_ps(v37, v37, 170), (__m128)v44.v2)),
                              _mm_mul_ps(_mm_shuffle_ps(v37, v37, 255), (__m128)v44.v3));
    v48.v1 = (UFG::qVector4)_mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), (__m128)v44.v0), (__m128)0i64),
                                  _mm_mul_ps(_mm_shuffle_ps(v38, v38, 85), (__m128)v44.v1)),
                                _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), (__m128)v44.v2)),
                              _mm_mul_ps(_mm_shuffle_ps(v38, v38, 255), (__m128)v44.v3));
    v48.v2 = (UFG::qVector4)_mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v39, v39, 0), (__m128)v44.v0), (__m128)0i64),
                                  _mm_mul_ps(_mm_shuffle_ps(v39, v39, 85), (__m128)v44.v1)),
                                _mm_mul_ps(_mm_shuffle_ps(v39, v39, 170), (__m128)v44.v2)),
                              _mm_mul_ps(_mm_shuffle_ps(v39, v39, 255), (__m128)v44.v3));
    v48.v3 = (UFG::qVector4)_mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), (__m128)v44.v0), (__m128)0i64),
                                  _mm_mul_ps(_mm_shuffle_ps(v40, v40, 85), (__m128)v44.v1)),
                                _mm_mul_ps(_mm_shuffle_ps(v40, v40, 170), (__m128)v44.v2)),
                              _mm_mul_ps(_mm_shuffle_ps(v40, v40, 255), (__m128)v44.v3));
    UFG::qMatrix44::operator*(&v48, &result, &this->mViewportScaleMatrix);
    if ( UFG::UITiledMapTweakables::MinimapRenderMask )
      UFG::DrawColoredRect_Xform(
        view,
        -64.0,
        -64.0,
        128.0,
        128.0,
        &v41,
        TextureUID,
        0i64,
        0xA3833FDE,
        UFG::gUIrasterState_Test_Mask_UID,
        &result);
    else
      UFG::DrawColoredRect_Xform(
        view,
        -64.0,
        -64.0,
        128.0,
        128.0,
        &v41,
        TextureUID,
        0i64,
        0xA3833FDE,
        0x62F81854u,
        &result);
  }
}

// File Line: 768
// RVA: 0xCF100
void __fastcall UFG::UITiledMapWidget::setMapPosition(
        UFG::UITiledMapWidget *this,
        UFG::MinimapPoint2f pos,
        float arrowRotation,
        UFG::UITiledMapTextureManager *textureMan,
        UFG::UITiledMapTextureManager *wideTextureMan,
        bool streamBasedOnPlayerPos)
{
  bool v6; // zf
  unsigned int v9; // xmm1_4
  unsigned int v10; // xmm0_4
  float v11; // xmm7_4
  float v12; // xmm8_4
  float y; // eax
  float v14; // xmm1_4
  UFG::UITiledMapTextureManager *v15; // rsi
  UFG::MinimapPoint2f *p_posa; // rdx
  UFG::MinimapPoint2f *v17; // rdx
  UFG::UITiledMapTextureManager *v18; // rcx
  UFG::MinimapPoint2f posa; // [rsp+20h] [rbp-58h] BYREF
  UFG::MinimapPoint2f v20; // [rsp+80h] [rbp+8h] BYREF
  UFG::MinimapPoint2f v21; // [rsp+88h] [rbp+10h]

  v6 = !streamBasedOnPlayerPos;
  *(float *)&v9 = pos.y + UFG::UITiledMapTweakables::MinimapYOffsetTweak;
  *(float *)&v10 = pos.x + UFG::UITiledMapTweakables::MinimapXOffsetTweak;
  this->m_mapGeo.playerRot = arrowRotation;
  v21 = (UFG::MinimapPoint2f)__PAIR64__(v9, v10);
  v20 = (UFG::MinimapPoint2f)__PAIR64__(v9, v10);
  this->m_mapIconGeo.screenPosition.x = this->m_mapGeo.screenPosition.x;
  v11 = *(float *)&v10 + -128.0;
  v12 = *(float *)&v9 + -128.0;
  this->m_mapIconGeo.screenPosition.y = this->m_mapGeo.screenPosition.y;
  this->m_mapIconGeo.centerPosition.x = this->m_mapGeo.centerPosition.x;
  y = this->m_mapGeo.centerPosition.y;
  v20.x = *(float *)&v10 + -128.0;
  v20.y = *(float *)&v9 + -128.0;
  this->m_mapIconGeo.centerPosition.y = y;
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
      p_posa = &v20;
LABEL_16:
      UFG::UITiledMapTextureManager::SetPlayerPosition(textureMan, p_posa);
      goto LABEL_17;
    }
    if ( v14 > UFG::UITiledMapTweakables::WideTileTrigger )
    {
      if ( v14 > (float)(UFG::UITiledMapTweakables::WideTileTrigger + UFG::UITiledMapTweakables::TileStreamingLead)
        || !textureMan )
      {
        goto LABEL_17;
      }
      p_posa = &posa;
      posa.x = v11 * 0.66666669;
      posa.y = v12 * 0.66666669;
      goto LABEL_16;
    }
    this->m_mapGeo.useWideTiles = 1;
    if ( textureMan )
      UFG::UITiledMapTextureManager::ReleaseAllTextures(textureMan);
  }
LABEL_17:
  if ( this->m_mapGeo.useWideTiles )
  {
    if ( v15 )
    {
      v17 = &posa;
      v18 = v15;
      posa.x = v11 * 0.66666669;
      posa.y = v12 * 0.66666669;
LABEL_22:
      UFG::UITiledMapTextureManager::SetPlayerPosition(v18, v17);
    }
  }
  else if ( textureMan )
  {
    v17 = &v20;
    v18 = textureMan;
    goto LABEL_22;
  }
LABEL_23:
  UFG::UITiledMapMath::UpdatePosition(&this->m_mapGeo, v20, 128);
  UFG::UITiledMapMath::UpdatePosition(&this->m_mapIconGeo, v21, 128);
}tePosition(&this->m_mapGeo, v20, 128);
  UFG::UITiledMapMath::UpdatePosition(&this->m_mapIconGeo, v21, 128);

// File Line: 889
// RVA: 0xC8D40
void __fastcall UFG::UITiledMapWidget::RenderMinimapPrimitive(
        UFG::UITiledMapWidget *this,
        Render::View *view,
        Illusion::Primitive::Type PrimitiveType,
        UFG::qColour *Color)
{
  float TextureHeight; // xmm10_4
  float TextureWidth; // xmm9_4
  float MaxY; // xmm11_4
  float MinY; // xmm12_4
  float MaxX; // xmm14_4
  float MinX; // xmm15_4
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
  bool useWideTiles; // al
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  signed int m_flashHeight; // ecx
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
  unsigned int v43; // r9d
  __int64 v44; // rax
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
  Illusion::Material *SimpleMaterial; // r14
  unsigned int v87; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v89; // rax
  Illusion::Primitive *v90; // rbx
  __m128 v91; // [rsp+40h] [rbp-98h] BYREF
  float offset; // [rsp+50h] [rbp-88h] BYREF
  float offset_4; // [rsp+54h] [rbp-84h]
  __m128 offset_8; // [rsp+58h] [rbp-80h] BYREF
  __m128 v95; // [rsp+68h] [rbp-70h]
  __m128 v96; // [rsp+78h] [rbp-60h]
  __int64 v97; // [rsp+88h] [rbp-50h]
  UFG::qMatrix44 v98; // [rsp+98h] [rbp-40h] BYREF
  UFG::qMatrix44 v99; // [rsp+D8h] [rbp+0h] BYREF
  UFG::qMatrix44 v100; // [rsp+118h] [rbp+40h] BYREF
  UFG::qMatrix44 v101; // [rsp+158h] [rbp+80h] BYREF
  UFG::qMatrix44 b; // [rsp+198h] [rbp+C0h] BYREF
  UFG::qMatrix44 result; // [rsp+1D8h] [rbp+100h] BYREF
  float v104; // [rsp+2E8h] [rbp+210h]
  float vars0; // [rsp+300h] [rbp+228h]
  char *retaddr; // [rsp+308h] [rbp+230h]
  int num_vertices; // [rsp+310h] [rbp+238h]
  int num_verticesa; // [rsp+310h] [rbp+238h]
  int num_verticesb; // [rsp+310h] [rbp+238h]
  void *indices; // [rsp+318h] [rbp+240h]
  int num_indices; // [rsp+320h] [rbp+248h]

  v97 = -2i64;
  offset = UFG::UITiledMapWidget::gMinimapCenter.x;
  offset_4 = UFG::UITiledMapWidget::gMinimapCenter.y;
  offset_8.m128_i32[0] = LODWORD(UFG::UITiledMapWidget::gMinimapCenter.z);
  TextureHeight = UFG::UITiledMapMath::WorldGeo.TextureHeight;
  TextureWidth = UFG::UITiledMapMath::WorldGeo.TextureWidth;
  MaxY = UFG::UITiledMapMath::WorldGeo.MaxY;
  MinY = UFG::UITiledMapMath::WorldGeo.MinY;
  MaxX = UFG::UITiledMapMath::WorldGeo.MaxX;
  MinX = UFG::UITiledMapMath::WorldGeo.MinX;
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
    LODWORD(v19) = _mm_sqrt_ps(v18).m128_u32[0];
    v20 = atan2f(v17, v16.m128_f32[0]);
    if ( this->m_mapGeo.useWideTiles )
      v14 = FLOAT_0_5;
    v21 = v19 * (float)((float)(UFG::UITiledMapTweakables::MinimapScaleTweak + this->m_mapGeo.scale) + v14);
    v22 = v20 + this->m_mapGeo.rot;
    v23 = cosf(v22) * v21;
    v24 = (float)(sinf(v22) * v21) + this->m_mapGeo.screenPosition.y;
    offset = v23 + this->m_mapGeo.screenPosition.x;
    offset_4 = v24;
    offset_8.m128_i32[0] = 0;
    MinY = UFG::UITiledMapMath::WorldGeo.MinY;
  }
  v25 = 1.0 / (float)(MaxX - MinX);
  v26 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v25 * TextureWidth) ^ _xmm[0]) * this->m_mapGeo.centerPosition.y)
      + (float)((float)(TextureHeight * MaxY) / (float)(MaxY - MinY));
  v91.m128_i32[0] = COERCE_UNSIGNED_INT(
                      (float)((float)(v25 * TextureWidth) * this->m_mapGeo.centerPosition.x)
                    + (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(TextureWidth * MinX) ^ _xmm[0]) * v25)) ^ _xmm[0];
  *(unsigned __int64 *)((char *)v91.m128_u64 + 4) = (unsigned int)(LODWORD(v26) ^ _xmm[0]);
  UFG::qTranslationMatrix(&v98, (UFG::qVector3 *)&v91);
  useWideTiles = this->m_mapGeo.useWideTiles;
  v28 = FLOAT_0_5;
  if ( useWideTiles )
    v29 = FLOAT_0_5;
  else
    v29 = 0.0;
  v30 = UFG::UITiledMapTweakables::MinimapScaleTweak + this->m_mapGeo.scale;
  v31 = v29 + v30;
  if ( !useWideTiles )
    v28 = 0.0;
  v91.m128_f32[0] = v28 + v30;
  *(unsigned __int64 *)((char *)v91.m128_u64 + 4) = LODWORD(v31) | 0x3F80000000000000i64;
  UFG::qScaleMatrix(&v100, (UFG::qVector3 *)&v91);
  UFG::qRotationMatrixZ(&v101, this->m_mapGeo.rot);
  UFG::qTranslationMatrix(&v99, (UFG::qVector3 *)&offset);
  m_flashHeight = UFG::UIScreenManager::s_instance->m_flashHeight;
  v91.m128_f32[0] = 1.0 / (float)(int)UFG::UIScreenManager::s_instance->m_flashWidth;
  v91.m128_f32[1] = 1.0 / (float)m_flashHeight;
  v91.m128_i32[2] = 1065353216;
  UFG::qScaleMatrix(&b, (UFG::qVector3 *)&v91);
  v96 = _mm_mul_ps(_mm_shuffle_ps((__m128)v98.v0, (__m128)v98.v0, 0), (__m128)v100.v0);
  v33 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)v98.v0, (__m128)v98.v0, 255), (__m128)v100.v3),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(v96, _xmm),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v98.v0, (__m128)v98.v0, 85), (__m128)v100.v1)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v98.v0, (__m128)v98.v0, 170), (__m128)v100.v2)));
  v34 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)v98.v1, (__m128)v98.v1, 255), (__m128)v100.v3),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v98.v1, (__m128)v98.v1, 0), (__m128)v100.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v98.v1, (__m128)v98.v1, 85), (__m128)v100.v1)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v98.v1, (__m128)v98.v1, 170), (__m128)v100.v2)));
  v35 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)v98.v2, (__m128)v98.v2, 255), (__m128)v100.v3),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v98.v2, (__m128)v98.v2, 0), (__m128)v100.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v98.v2, (__m128)v98.v2, 85), (__m128)v100.v1)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v98.v2, (__m128)v98.v2, 170), (__m128)v100.v2)));
  v91 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps((__m128)v98.v3, (__m128)v98.v3, 170), (__m128)v100.v2),
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v98.v3, (__m128)v98.v3, 0), (__m128)v100.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v98.v3, (__m128)v98.v3, 85), (__m128)v100.v1))),
          _mm_mul_ps(_mm_shuffle_ps((__m128)v98.v3, (__m128)v98.v3, 255), (__m128)v100.v3));
  v96 = _mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), (__m128)v101.v0);
  v36 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v33, v33, 255), (__m128)v101.v3),
          _mm_add_ps(
            _mm_add_ps(_mm_add_ps(v96, _xmm), _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), (__m128)v101.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), (__m128)v101.v2)));
  v37 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v34, v34, 255), (__m128)v101.v3),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), (__m128)v101.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), (__m128)v101.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), (__m128)v101.v2)));
  v38 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v91, v91, 0), (__m128)v101.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v91, v91, 85), (__m128)v101.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v91, v91, 170), (__m128)v101.v2)),
          _mm_mul_ps(_mm_shuffle_ps(v91, v91, 255), (__m128)v101.v3));
  v39 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v35, v35, 170), (__m128)v101.v2),
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), (__m128)v101.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v35, v35, 85), (__m128)v101.v1))),
          _mm_mul_ps(_mm_shuffle_ps(v35, v35, 255), (__m128)v101.v3));
  v91 = _mm_mul_ps(_mm_shuffle_ps(v36, v36, 0), (__m128)v99.v0);
  v96 = _mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), (__m128)v99.v0);
  v91 = _mm_add_ps(_mm_add_ps(v91, _xmm), _mm_mul_ps(_mm_shuffle_ps(v36, v36, 85), (__m128)v99.v1));
  v40 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_add_ps(v96, (__m128)0i64), _mm_mul_ps(_mm_shuffle_ps(v38, v38, 85), (__m128)v99.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), (__m128)v99.v2)),
          _mm_mul_ps((__m128)v99.v3, _mm_shuffle_ps(v38, v38, 255)));
  v96.m128_u64[0] = *(unsigned __int128 *)&_mm_add_ps(
                                             _mm_add_ps(
                                               _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), (__m128)v99.v0),
                                                   (__m128)0i64),
                                                 _mm_mul_ps(_mm_shuffle_ps(v37, v37, 85), (__m128)v99.v1)),
                                               _mm_mul_ps(_mm_shuffle_ps(v37, v37, 170), (__m128)v99.v2)),
                                             _mm_mul_ps((__m128)v99.v3, _mm_shuffle_ps(v37, v37, 255))) >> 64;
  offset_8 = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v39, v39, 0), (__m128)v99.v0), (__m128)0i64),
                   _mm_mul_ps(_mm_shuffle_ps(v39, v39, 85), (__m128)v99.v1)),
                 _mm_mul_ps(_mm_shuffle_ps(v39, v39, 170), (__m128)v99.v2)),
               _mm_mul_ps((__m128)v99.v3, _mm_shuffle_ps(v39, v39, 255)));
  v95 = v40;
  v41 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)&offset_8.m128_u16[4], &result, &this->mViewportScaleMatrix);
  UFG::qMatrix44::operator*(v41, (UFG::qMatrix44 *)&offset_8.m128_u16[4], &b);
  v42 = (int)(float)(Color->r * 255.0) | (((int)(float)(Color->g * 255.0) | (((int)(float)(Color->b * 255.0) | ((int)(float)(Color->a * 255.0) << 8)) << 8)) << 8);
  v43 = 0;
  v44 = 0i64;
  v45 = v95.m128_f32[2];
  v46 = v95.m128_f32[1];
  v47 = v95.m128_f32[0];
  v48 = offset_8.m128_f32[2];
  v49 = offset_8.m128_f32[1];
  v50 = offset_8.m128_f32[0];
  v51 = v96.m128_f32[0];
  v52 = v95.m128_f32[3];
  v53 = v95.m128_f32[2];
  v54 = v95.m128_f32[0];
  v55 = num_vertices;
  if ( num_vertices >= 4 )
  {
    *(float *)&num_verticesa = offset_8.m128_f32[0] * 0.0;
    v104 = offset_8.m128_f32[1] * 0.0;
    vars0 = offset_8.m128_f32[2] * 0.0;
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
      v62 = (float)((float)((float)(v52 * v61) + (float)(offset_8.m128_f32[3] * v60)) + v104) + v46;
      v63 = (float)((float)((float)(v51 * v61) + (float)(v54 * v60)) + vars0) + v45;
      *(v56 - 14) = (float)((float)((float)(v53 * v61) + (float)(offset_8.m128_f32[2] * v60)) + *(float *)&num_verticesa)
                  + v47;
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
      v67 = (float)((float)((float)(v52 * v66) + (float)(offset_8.m128_f32[3] * v65)) + v104) + v46;
      v68 = (float)((float)((float)(v51 * v66) + (float)(v54 * v65)) + vars0) + v45;
      *(v56 - 2) = (float)((float)((float)(v53 * v66) + (float)(offset_8.m128_f32[2] * v65)) + *(float *)&num_verticesa)
                 + v47;
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
      v72 = (float)((float)((float)(v52 * v71) + (float)(offset_8.m128_f32[3] * v70)) + v104) + v46;
      v73 = (float)((float)((float)(v51 * v71) + (float)(v54 * v70)) + vars0) + v45;
      v56[10] = (float)((float)((float)(v53 * v71) + (float)(offset_8.m128_f32[2] * v70)) + *(float *)&num_verticesa)
              + v47;
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
      v77 = (float)((float)((float)(v52 * v76) + (float)(offset_8.m128_f32[3] * v75)) + v104) + v46;
      v78 = (float)((float)((float)(v51 * v76) + (float)(v54 * v75)) + vars0) + v45;
      v56[22] = (float)((float)((float)(v53 * v76) + (float)(offset_8.m128_f32[2] * v75)) + *(float *)&num_verticesa)
              + v47;
      v56[23] = v77;
      v56[24] = v78;
      *((_DWORD *)v56 + 33) = v42;
      v56 += 48;
      --v58;
    }
    while ( v58 );
    v48 = offset_8.m128_f32[2];
    v49 = offset_8.m128_f32[1];
    v50 = offset_8.m128_f32[0];
  }
  if ( v43 < v55 )
  {
    *(float *)&num_verticesb = v50 * 0.0;
    v104 = v49 * 0.0;
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
      v84 = (float)((float)((float)(v52 * v83) + (float)(offset_8.m128_f32[3] * v82)) + v104) + v46;
      v85 = (float)((float)((float)(v51 * v83) + (float)(v54 * v82)) + vars0) + v45;
      *(v79 - 1) = (float)((float)((float)(v53 * v83) + (float)(offset_8.m128_f32[2] * v82)) + *(float *)&num_verticesb)
                 + v47;
      *v79 = v84;
      v79[1] = v85;
      *((_DWORD *)v79 + 10) = v42;
      v79 += 12;
      --v80;
    }
    while ( v80 );
  }
  SimpleMaterial = Render::View::CreateSimpleMaterial(0xB11369EB, UFG::gUIrasterState_Test_Mask_UID, 0xA3833FDE, 0);
  if ( (_S9 & 1) == 0 )
  {
    _S9 |= 1u;
    UFG::qResourceHandle::qResourceHandle(&vertex_decl_handle_1);
    atexit(UFG::UITiledMapWidget::RenderMinimapPrimitive_::_7_::_dynamic_atexit_destructor_for__vertex_decl_handle__);
  }
  if ( !vertex_decl_handle_1.mData )
  {
    v87 = UFG::qStringHash32("VertexDecl.Dynamic", 0xFFFFFFFF);
    Inventory = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
    {
      v89 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v89, 0x3E5FDA3Eu);
      `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&vertex_decl_handle_1, 0x3E5FDA3Eu, v87, Inventory);
  }
  v90 = Illusion::Primitive::Create("MiniMap");
  Illusion::Primitive::SetBuffers(
    v90,
    PrimitiveType,
    retaddr,
    v55,
    (Illusion::VertexDecl *)vertex_decl_handle_1.mData,
    indices,
    num_indices,
    1);
  Render::View::Draw(view, v90, SimpleMaterial, 0i64);
}2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&vertex_decl_handle_1, 0x3E5FDA3Eu, v87, Inventory);
  }
  v90 = Illusion::Primitive::Create("MiniMap");
  Illusion::Primitive::SetBuffers(
    v

// File Line: 1017
// RVA: 0xC7CA0
void __fastcall UFG::UITiledMapWidget::RenderGPSSpline(
        UFG::UITiledMapWidget *this,
        Render::View *view,
        UFG::UITiledMapGPS *GPS,
        UFG::UIMapBlipManager *blipMan)
{
  unsigned int mNumSplinePoints; // ebx
  float mAlpha; // xmm1_4
  unsigned int v9; // r8d
  UFG::qArray<UFG::qVector3,0> *p_mSplinePoints; // rbp
  unsigned int v11; // r9d
  UFG::qBaseTreeRB *v12; // rax
  UFG::qVector3 *p; // rcx
  float x; // xmm3_4
  float yPos; // xmm4_4
  float z; // xmm5_4
  UFG::UIMapBlip *Icon; // rax
  __m128 v18; // xmm2
  UFG::qColour v19; // [rsp+30h] [rbp-18h] BYREF

  mNumSplinePoints = GPS->mNumSplinePoints;
  if ( mNumSplinePoints >= 2 )
  {
    mAlpha = this->mAlpha;
    v9 = 50;
    p_mSplinePoints = &GPS->mSplinePoints;
    if ( mNumSplinePoints < 0x32 )
      v9 = mNumSplinePoints;
    v19 = UFG::UITiledMapWidget::GPSLineColor;
    v19.a = mAlpha;
    UFG::UITiledMapWidget::RenderSpline(this, &GPS->mSplinePoints, v9, &v19, view);
    if ( UFG::UITiledMapTweakables::GPS_ShowDestinationBlip )
    {
      v11 = UI_BLIP_GPS_DESTINATION;
      if ( UI_BLIP_GPS_DESTINATION )
      {
        v12 = UFG::qBaseTreeRB::Get(&blipMan->mIconList.mIconData.mTree, UI_BLIP_GPS_DESTINATION);
        v11 = UI_BLIP_GPS_DESTINATION;
      }
      else
      {
        v12 = 0i64;
      }
      p = p_mSplinePoints->p;
      x = p[mNumSplinePoints - 1].x;
      yPos = p[mNumSplinePoints - 1].y;
      z = p[mNumSplinePoints - 1].z;
      if ( v12 )
      {
        v18 = (__m128)*((unsigned int *)&v12->mCount + 1);
        v18.m128_f32[0] = (float)((float)((float)(v18.m128_f32[0] - yPos) * (float)(v18.m128_f32[0] - yPos))
                                + (float)((float)(*(float *)&v12->mCount - x) * (float)(*(float *)&v12->mCount - x)))
                        + (float)((float)(*(float *)&v12[1].mRoot.mParent - z)
                                * (float)(*(float *)&v12[1].mRoot.mParent - z));
        if ( _mm_sqrt_ps(v18).m128_f32[0] > UFG::gSymbolPosDiff )
        {
          *(float *)&v12->mCount = x;
          *((float *)&v12->mCount + 1) = yPos;
          *(float *)&v12[1].mRoot.mParent = z;
          BYTE5(v12->mNULL.mChild[0]) = 1;
        }
      }
      else
      {
        Icon = UFG::UIMapBlipManager::CreateIcon(blipMan, v11, "friendly", x, yPos);
        if ( this->mIsWorldMap )
          Icon->mBoundIcon = 0;
      }
    }
  }
}

// File Line: 1094
// RVA: 0xC9E20
void __fastcall UFG::UITiledMapWidget::RenderSpline(
        UFG::UITiledMapWidget *this,
        UFG::qArray<UFG::qVector3,0> *SplinePoints,
        unsigned int NumSplinePoints,
        UFG::qColour *Colour,
        Render::View *view)
{
  float v9; // xmm1_4
  float v10; // xmm11_4
  char *v11; // r10
  int v12; // r9d
  UFG::qVector3 *p; // rax
  float v14; // xmm8_4
  float v15; // xmm7_4
  float v16; // xmm1_4
  float v17; // xmm6_4
  float v18; // xmm8_4
  float v19; // xmm7_4
  __int64 v20; // r14
  float v21; // xmm1_4
  float v22; // xmm0_4
  UFG::qVector3 *v23; // rax
  float v24; // xmm1_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm2_4
  __int64 v28; // rcx
  __int64 v29; // r8
  char *v30; // rdx
  __int64 v31; // r11
  UFG::qVector3 *v32; // rax
  __m128 y_low; // xmm8
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
  float x; // xmm1_4
  float y; // xmm0_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  UFG::qVector3 *v51; // rax
  __int64 v52; // rdx
  float v53; // xmm8_4
  float v54; // xmm7_4
  float v55; // xmm0_4
  __int64 v56; // rcx
  UFG::qVector3 *v57; // rax
  float v58; // xmm2_4
  float v59; // xmm1_4
  Illusion::Primitive::Type v60; // r8d
  __int64 v61; // rax

  if ( NumSplinePoints >= 2 )
  {
    if ( this->m_mapGeo.useWideTiles )
      v9 = FLOAT_0_5;
    else
      v9 = 0.0;
    v10 = 3.0 / (float)((float)(UFG::UITiledMapTweakables::MinimapScaleTweak + this->m_mapGeo.scale) + v9);
    v11 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 96 * NumSplinePoints, 0x10u);
    v12 = (int)(float)(Colour->r * 255.0) | (((int)(float)(Colour->g * 255.0) | (((int)(float)(Colour->b * 255.0) | ((int)(float)(Colour->a * 255.0) << 8)) << 8)) << 8);
    p = SplinePoints->p;
    v14 = p[1].y - p->y;
    LODWORD(v15) = COERCE_UNSIGNED_INT(p[1].x - p->x) ^ _xmm[0];
    v16 = (float)(v15 * v15) + (float)(v14 * v14);
    if ( v16 == 0.0 )
      v17 = 0.0;
    else
      v17 = 1.0 / fsqrt(v16);
    v18 = v14 * v17;
    v19 = v15 * v17;
    v20 = NumSplinePoints - 1;
    v21 = (float)(v18 * v10) + p->x;
    v22 = (float)(v19 * v10) + p->y;
    *((_DWORD *)v11 + 2) = 0;
    *(float *)v11 = v21;
    *((float *)v11 + 1) = v22;
    *((_DWORD *)v11 + 11) = v12;
    v23 = SplinePoints->p;
    v24 = v23->y - (float)(v19 * v10);
    v25 = v19;
    v26 = v17 * 0.0;
    *((float *)v11 + 12) = v23->x - (float)(v18 * v10);
    *((float *)v11 + 13) = v24;
    *((_DWORD *)v11 + 14) = 0;
    *((_DWORD *)v11 + 23) = v12;
    v27 = v18;
    if ( (unsigned int)v20 > 1 )
    {
      v28 = 1i64;
      v29 = 2i64;
      v30 = v11 + 152;
      v31 = NumSplinePoints - 2;
      do
      {
        v32 = SplinePoints->p;
        y_low = (__m128)LODWORD(v32[v29].y);
        y_low.m128_f32[0] = y_low.m128_f32[0] - v32[v28].y;
        LODWORD(v34) = COERCE_UNSIGNED_INT(v32[v29].x - v32[v28].x) ^ _xmm[0];
        v35 = y_low;
        v35.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v34 * v34);
        if ( v35.m128_f32[0] == 0.0 )
          v36 = 0.0;
        else
          v36 = 1.0 / _mm_sqrt_ps(v35).m128_f32[0];
        v18 = y_low.m128_f32[0] * v36;
        v19 = v34 * v36;
        v37 = v36 * 0.0;
        v38 = v27 + v18;
        v39 = v25 + v19;
        v40 = (float)((float)(v39 * v39) + (float)(v38 * v38)) + (float)((float)(v26 + v37) * (float)(v26 + v37));
        if ( v40 == 0.0 )
          v41 = 0.0;
        else
          v41 = 1.0 / fsqrt(v40);
        v30 += 96;
        ++v29;
        ++v28;
        v26 = v37;
        v42 = (float)(v38 * v41) * v10;
        v43 = (float)(v39 * v41) * v10;
        v44 = v42 + v32[v28 - 1].x;
        v45 = v43 + v32[v28 - 1].y;
        *((_DWORD *)v30 - 36) = 0;
        *((float *)v30 - 38) = v44;
        *((float *)v30 - 37) = v45;
        *((_DWORD *)v30 - 27) = v12;
        v46 = SplinePoints->p;
        x = v46[v28 - 1].x;
        y = v46[v28 - 1].y;
        *((_DWORD *)v30 - 24) = 0;
        v49 = x - v42;
        v50 = y - v43;
        v27 = v18;
        v25 = v19;
        *((float *)v30 - 26) = v49;
        *((float *)v30 - 25) = v50;
        *((_DWORD *)v30 - 15) = v12;
        --v31;
      }
      while ( v31 );
    }
    v51 = SplinePoints->p;
    v52 = (unsigned int)(2 * v20);
    v53 = v18 * v10;
    v54 = v19 * v10;
    v55 = v54 + v51[v20].y;
    v56 = 6 * v52;
    *(float *)&v11[8 * v56] = v53 + v51[v20].x;
    *(float *)&v11[8 * v56 + 4] = v55;
    *(_DWORD *)&v11[8 * v56 + 8] = 0;
    *(_DWORD *)&v11[8 * v56 + 44] = v12;
    v57 = SplinePoints->p;
    v58 = v57[v20].x;
    v59 = v57[v20].y;
    v60 = TRIANGLESTRIP;
    v61 = 6i64 * (unsigned int)(v52 + 1);
    *(float *)&v11[8 * v61] = v58 - v53;
    *(float *)&v11[8 * v61 + 4] = v59 - v54;
    *(_DWORD *)&v11[8 * v61 + 44] = v12;
    *(_DWORD *)&v11[8 * v61 + 8] = 0;
    if ( UFG::UIHKTweakables::WorldMap_UsePointList )
      v60 = POINTLIST;
    UFG::UITiledMapWidget::RenderMinimapPrimitive(this, view, v60, Colour);
  }
}

// File Line: 1160
// RVA: 0xC7E00
void __fastcall UFG::UITiledMapWidget::RenderMapLines(
        UFG::UITiledMapWidget *this,
        Render::View *view,
        UFG::UIMapLinesWidget *MapLines)
{
  UFG::UIHKMapLine *p; // rdi
  unsigned int size; // ebx
  Render::vDynamic *Vertices; // rsi
  char *Indices; // rbp
  unsigned int v9; // r11d
  float *p_y; // r8
  char *v11; // r10
  char *p_z; // r9
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

  p = MapLines->mActiveLines.p;
  size = MapLines->mActiveLines.size;
  if ( p && size )
  {
    Vertices = (Render::vDynamic *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 192 * size, 0x10u);
    memset(Vertices, 0, 192i64 * size);
    Indices = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 12 * size, 0x10u);
    memset(Indices, 0, 12i64 * size);
    v9 = 0;
    p_y = &p->start.y;
    v11 = Indices + 4;
    p_z = (char *)&Vertices[1].mPosition.z;
    do
    {
      v13 = p_y[1];
      v14 = *(p_y - 1);
      v15 = p_y[2];
      v16 = *p_y;
      v17 = v15 - *p_y;
      LODWORD(v18) = COERCE_UNSIGNED_INT(v13 - v14) ^ _xmm[0];
      v19 = (float)(v18 * v18) + (float)(v17 * v17);
      if ( v19 == 0.0 )
        v20 = 0.0;
      else
        v20 = 1.0 / fsqrt(v19);
      *((_DWORD *)p_z - 12) = 0;
      v21 = 4 * v9;
      v22 = (float)(v18 * v20) * 3.0;
      ++v9;
      v11 += 12;
      p_y += 4;
      p_z += 192;
      v23 = (float)(v17 * v20) * 3.0;
      *((float *)p_z - 61) = v22 + v16;
      *((float *)p_z - 62) = v14 + v23;
      *((float *)p_z - 49) = v16 - v22;
      *((_DWORD *)p_z - 48) = 0;
      *((float *)p_z - 50) = v14 - v23;
      *((float *)p_z - 38) = v13 + v23;
      *((float *)p_z - 37) = v15 + v22;
      *((_DWORD *)p_z - 36) = 0;
      *((_DWORD *)p_z - 24) = 0;
      *((float *)p_z - 26) = v13 - v23;
      *((float *)p_z - 25) = v15 - v22;
      *((_WORD *)v11 - 8) = v21;
      *((_WORD *)v11 - 6) = v21 + 2;
      *((_WORD *)v11 - 5) = v21 + 2;
      *((_WORD *)v11 - 7) = v21 + 1;
      *((_WORD *)v11 - 4) = v21 + 1;
      *((_WORD *)v11 - 3) = v21 + 3;
    }
    while ( v9 < size );
    UFG::UITiledMapWidget::RenderMinimapPrimitive(
      this,
      view,
      3u,
      &UFG::qColour::Green,
      Vertices,
      4 * size,
      (unsigned __int16 *)Indices,
      6 * size);
  }
}

// File Line: 1202
// RVA: 0xC7440
void __fastcall UFG::UITiledMapWidget::RenderBlipRanges(UFG::UITiledMapWidget *this, Render::View *view)
{
  UFG::UIRenderQuad *p; // rbx
  float v5; // xmm1_4
  float v6; // xmm6_4
  UFG::qMatrix44 *Matrix; // rcx
  UFG::qMatrix44 *v8; // rax
  UFG::qVector4 v9; // xmm0
  UFG::qVector4 v10; // xmm1
  float v11; // xmm1_4
  int v12; // ebx
  UFG::UIRenderQuad *v13; // rbx
  float v14; // xmm1_4
  UFG::qMatrix44 TransformMatrix; // [rsp+60h] [rbp-C8h] BYREF
  __int64 v16; // [rsp+A0h] [rbp-88h]
  UFG::qMatrix44 result; // [rsp+A8h] [rbp-80h] BYREF

  v16 = -2i64;
  if ( (_S10 & 1) == 0 )
  {
    _S10 |= 1u;
    BackgroundTextureUID_0 = UFG::qStringHashUpper32("FX_Feathered_Circle_2", 0xFFFFFFFF);
  }
  p = this->PolyListNativeDoubleClipped.p;
  if ( &p[this->PolyListNativeDoubleClipped.size] != p )
  {
    do
    {
      Render::View::Clear(view, &UFG::qColour::Black, 4u, 1.0, 0);
      Render::View::SetSimpleMaterialShader(UFG::gUIshader_Punch_Simple_UID);
      UFG::DrawColoredRect_Xform(
        view,
        (float)(int)(float)(UFG::UITiledMapWidget::gMinimapCenter.x
                          - (float)((float)(UFG::UITiledMapWidget::gMinimapStencilSizePad
                                          + UFG::UITiledMapWidget::gMinimapBackgroundSize)
                                  * 0.5)),
        (float)(int)(float)(UFG::UITiledMapWidget::gMinimapCenter.y
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
        &this->mViewportScaleMatrix);
      Render::View::SetSimpleMaterialShader(UFG::gUIshader_Simple_UID);
      if ( this->m_mapGeo.useWideTiles )
        v5 = FLOAT_0_5;
      else
        v5 = 0.0;
      v6 = (float)(p->Size * p->Scale)
         * (float)((float)(UFG::UITiledMapTweakables::MinimapScaleTweak + this->m_mapGeo.scale) + v5);
      Matrix = p->Matrix;
      if ( Matrix )
      {
        v8 = UFG::qMatrix44::operator*(Matrix, &result, &this->mViewportScaleMatrix);
        TransformMatrix.v0 = v8->v0;
        TransformMatrix.v1 = v8->v1;
        v9 = v8->v2;
        v10 = v8->v3;
      }
      else
      {
        TransformMatrix.v0 = this->mViewportScaleMatrix.v0;
        TransformMatrix.v1 = this->mViewportScaleMatrix.v1;
        v9 = this->mViewportScaleMatrix.v2;
        v10 = this->mViewportScaleMatrix.v3;
      }
      TransformMatrix.v3 = v10;
      TransformMatrix.v2 = v9;
      Render::View::SetSimpleMaterialShader(UFG::gUIshader_Punch_Simple_UID);
      UFG::DrawColoredRect_Xform(
        view,
        p->X - (float)(v6 * 0.5),
        p->Y - (float)(v6 * 0.5),
        v6,
        v6,
        &UFG::qColour::White,
        p->TextureID,
        p->UVs,
        0x91A2DD53,
        UFG::gUIrasterState_Set_Mask0_UID,
        &TransformMatrix);
      Render::View::SetSimpleMaterialShader(UFG::gUIshader_Simple_UID);
      if ( this->m_mapGeo.useWideTiles )
        v11 = FLOAT_0_5;
      else
        v11 = 0.0;
      UFG::DrawUIRenderQuad(
        view,
        p + 1,
        &this->mViewportScaleMatrix,
        UFG::gUIrasterState_Test_Mask_UID,
        this->mAlpha,
        (float)(UFG::UITiledMapTweakables::MinimapScaleTweak + this->m_mapGeo.scale) + v11);
      p += 2;
    }
    while ( &this->PolyListNativeDoubleClipped.p[this->PolyListNativeDoubleClipped.size] != p );
  }
  Render::View::Clear(view, &UFG::qColour::Black, 4u, 1.0, 0);
  v12 = UFG::UITiledMapWidget::gMinimapBackgroundSize + UFG::UITiledMapWidget::gMinimapStencilSizePad;
  Render::View::SetSimpleMaterialShader(UFG::gUIshader_Punch_Simple_UID);
  UFG::DrawColoredRect_Xform(
    view,
    (float)(int)(float)(UFG::UITiledMapWidget::gMinimapCenter.x - (float)((float)v12 * 0.5)),
    (float)(int)(float)(UFG::UITiledMapWidget::gMinimapCenter.y - (float)((float)v12 * 0.5)),
    (float)v12,
    (float)v12,
    &UFG::qColour::White,
    BackgroundTextureUID_0,
    0i64,
    0x91A2DD53,
    UFG::gUIrasterState_Set_Mask1_UID,
    &this->mViewportScaleMatrix);
  Render::View::SetSimpleMaterialShader(UFG::gUIshader_Simple_UID);
  v13 = this->PolyListNativeClipped.p;
  if ( &v13[this->PolyListNativeClipped.size] != v13 )
  {
    do
    {
      if ( this->m_mapGeo.useWideTiles )
        v14 = FLOAT_0_5;
      else
        v14 = 0.0;
      UFG::DrawUIRenderQuad(
        view,
        v13++,
        &this->mViewportScaleMatrix,
        UFG::gUIrasterState_Test_Mask_UID,
        this->mAlpha,
        (float)(UFG::UITiledMapTweakables::MinimapScaleTweak + this->m_mapGeo.scale) + v14);
    }
    while ( &this->PolyListNativeClipped.p[this->PolyListNativeClipped.size] != v13 );
  }
}

// File Line: 1282
// RVA: 0xC7890
void __fastcall UFG::UITiledMapWidget::RenderBlips(UFG::UITiledMapWidget *this, Render::View *view)
{
  UFG::UIRenderQuad *p; // rbx
  float X; // xmm0_4
  float Y; // xmm1_4
  __m128 v7; // xmm5
  __m128 v8; // xmm6
  __m128 v9; // xmm4
  __m128 v10; // xmm12
  UFG::qMatrix44 *Matrix; // rsi
  UFG::qVector3 scale; // [rsp+30h] [rbp-D0h] BYREF
  UFG::qVector3 offset; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qMatrix44 m; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qMatrix44 v15; // [rsp+90h] [rbp-70h] BYREF
  UFG::qMatrix44 d; // [rsp+D0h] [rbp-30h] BYREF
  UFG::qMatrix44 dest; // [rsp+110h] [rbp+10h] BYREF

  scale.x = UFG::UITiledMapTweakables::BlipScale;
  scale.y = UFG::UITiledMapTweakables::BlipScale;
  scale.z = 1.0;
  UFG::qScaleMatrix(&dest, &scale);
  p = this->PolyListNativeNotClipped.p;
  if ( &p[this->PolyListNativeNotClipped.size] != p )
  {
    do
    {
      X = p->X;
      Y = p->Y;
      offset.z = 0.0;
      offset.x = X;
      offset.y = Y;
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
      Matrix = p->Matrix;
      if ( Matrix )
        UFG::qMatrix44::operator*=(&v15, p->Matrix);
      p->Matrix = &v15;
      UFG::DrawUIRenderQuad(view, p, &this->mViewportScaleMatrix, 0x62F81854u, this->mAlpha, 1.0);
      p->Matrix = Matrix;
      ++p;
    }
    while ( &this->PolyListNativeNotClipped.p[this->PolyListNativeNotClipped.size] != p );
  }
}

// File Line: 1329
// RVA: 0xC8D00
void __fastcall UFG::UITiledMapWidget::RenderMinimapBackdrop(
        UFG::UITiledMapWidget *this,
        Render::View *view,
        UFG::UIMapInteriorManager *interiorMan,
        UFG::UITiledMapTextureManager *textureMan,
        UFG::UIMapLinesWidget *MapLines)
{
  UFG::UITiledMapWidget::RenderMinimap(this, view, interiorMan);
  if ( MapLines->mVisible )
    UFG::UITiledMapWidget::RenderMapLines(this, view, MapLines);
}

// File Line: 1342
// RVA: 0xC0820
void __fastcall UFG::UITiledMapWidget::Flash_GetWidgetScreenPosition(
        UFG::UITiledMapWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    pval.pObjectInterface = 0i64;
    pval.Type = VT_Undefined;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "circle_mask._width");
    this->m_mapGeo.MaskRadius = pval.mValue.NValue * 0.5 * 1.5;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "circle_mask._x");
    this->m_mapGeo.CircleMaskX = pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "circle_mask._y");
    this->m_mapGeo.CircleMaskY = pval.mValue.NValue;
    if ( (pval.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        pval.mValue);
  }
}

// File Line: 1361
// RVA: 0xCA800
void __fastcall UFG::UITiledMapWidget::SetGPSLineColor(UFG::qColour *color)
{
  float g; // xmm3_4
  float b; // xmm2_4
  float a; // xmm1_4

  UFG::UITiledMapWidget::GPSLineColor.r = color->r;
  g = color->g;
  UFG::UITiledMapWidget::GPSLineColor.g = g;
  b = color->b;
  UFG::UITiledMapWidget::GPSLineColor.b = b;
  a = color->a;
  UFG::UITiledMapWidget::GPSLineColor.a = a;
  if ( UFG::UITiledMapWidget::GPSLineColor.r == UFG::qColour::White.r
    && g == UFG::qColour::White.g
    && b == UFG::qColour::White.b
    && a == UFG::qColour::White.a )
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

