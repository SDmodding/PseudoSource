// File Line: 36
// RVA: 0x618E90
void __fastcall UFG::UIHKWorldMapCursorWidget::Update(UFG::UIHKWorldMapCursorWidget *this, UFG::UIScreen *screen, UFG::UIMapBlipManager *iconManager, UFG::UITiledMapMath *geo)
{
  UFG::UITiledMapMath *v4; // rdi
  UFG::UIMapBlipManager *v5; // rsi
  UFG::UIHKWorldMapCursorWidget *v6; // rbx
  char v7; // [rsp+28h] [rbp-40h]
  __int64 v8; // [rsp+38h] [rbp-30h]
  unsigned int v9; // [rsp+40h] [rbp-28h]
  __int64 v10; // [rsp+48h] [rbp-20h]

  if ( screen )
  {
    v4 = geo;
    v5 = iconManager;
    v6 = this;
    if ( screen->mRenderable->m_movie.pObject )
    {
      UFG::UIHKCursorWidget::Update((UFG::UIHKCursorWidget *)&this->mPos, screen);
      v8 = 0i64;
      v9 = 0;
      if ( v6->mIsMoving )
        UFG::UIHKWorldMapCursorWidget::Close(v6);
      else
        UFG::UIHKWorldMapCursorWidget::SnapToObjective(v6, v5, v4);
      if ( (v9 >> 6) & 1 )
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v8 + 16i64))(v8, &v7, v10);
    }
  }
}

// File Line: 70
// RVA: 0x1570CA0
__int64 UFG::_dynamic_initializer_for__symRaceStartFlag__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("race_start_flag", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symRaceStartFlag, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symRaceStartFlag__);
}

// File Line: 71
// RVA: 0x1570C60
__int64 UFG::_dynamic_initializer_for__symRaceEndFlag__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("race_end_flag", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symRaceEndFlag, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symRaceEndFlag__);
}

// File Line: 75
// RVA: 0x6117A0
void __fastcall UFG::UIHKWorldMapCursorWidget::SnapToObjective(UFG::UIHKWorldMapCursorWidget *this, UFG::UIMapBlipManager *iconManager, UFG::UITiledMapMath *geo)
{
  UFG::UIHKPlayerObjectiveManager *v3; // r14
  UFG::UITiledMapMath *v4; // r12
  UFG::BasePhysicsSystem *v5; // rsi
  UFG::UIHKWorldMapCursorWidget *v6; // rbx
  UFG::UIMapBlip *v7; // rdi
  UFG::UIHKPlayerObjective *v8; // rax
  UFG::UIHKPlayerObjective *v9; // r14
  UFG::qBaseTreeRB *v10; // rax
  bool v11; // r15
  UFG::UIMapBlip *v12; // rax
  UFG::UIMapBlip *v13; // rsi
  UFG::qColour *v14; // rax
  float v15; // xmm6_4
  const char *v16; // rax
  float v17; // xmm1_4
  float v18; // xmm2_4
  const char *v19; // rsi
  float v20; // xmm1_4
  UFG::Objective *v21; // rsi
  char *titleCaption; // ST20_8
  char v23; // r14
  AK::IAkPluginParam *v24; // rax
  UFG::UIScreen *v25; // rax
  int v26; // ecx
  UFG::ScreenPoint2f v27; // [rsp+30h] [rbp-50h]
  UFG::qVector3 pos; // [rsp+38h] [rbp-48h]
  UFG::qVector3 point; // [rsp+48h] [rbp-38h]
  UFG::qVector3 playerPos; // [rsp+58h] [rbp-28h]
  UFG::WorldPoint2f v31; // [rsp+C8h] [rbp+48h]

  v3 = UFG::UIHKPlayerObjectiveManager::mInstance;
  v4 = geo;
  v5 = (UFG::BasePhysicsSystem *)iconManager;
  v6 = this;
  if ( !UFG::UIHKPlayerObjectiveManager::mInstance )
    return;
  this->mSelectedBlipColor.r = UFG::qColour::White.r;
  this->mSelectedBlipColor.g = UFG::qColour::White.g;
  this->mSelectedBlipColor.b = UFG::qColour::White.b;
  this->mSelectedBlipColor.a = UFG::qColour::White.a;
  UFG::WorldPoint2f::WorldPoint2f(&v31, &this->mPos, geo);
  pos.z = 0.0;
  *(_QWORD *)&playerPos.x = 0i64;
  playerPos.z = 0.0;
  *(UFG::WorldPoint2f *)&pos.x = v31;
  v7 = 0i64;
  v8 = UFG::UIHKPlayerObjectiveManager::FindNearestObjective(v3, &pos);
  v9 = v8;
  if ( v8 )
  {
    if ( !v5
      || v8->minimapBlips.size <= 0
      || (v10 = UFG::BasePhysicsSystem::GetCollisionModel(v5, *v8->minimapBlips.p), (v7 = (UFG::UIMapBlip *)v10) == 0i64)
      || !UFG::UIMapBlip::IsVisible((UFG::UIMapBlip *)v10)
      || UFG::UIMapBlip::GetAlpha(v7, &playerPos, v4) <= 0.0 )
    {
      v7 = 0i64;
    }
  }
  v11 = v7 != 0i64;
  v12 = UFG::UIMapBlipManager::FindNearestVisibleIcon((UFG::UIMapBlipManager *)v5, &pos, v4);
  v13 = v12;
  if ( v7
    && v12
    && (float)((float)((float)(v12->pos.y - pos.y) * (float)(v12->pos.y - pos.y))
             + (float)((float)(v12->pos.x - pos.x) * (float)(v12->pos.x - pos.x))) < (float)((float)((float)(v7->pos.y - pos.y) * (float)(v7->pos.y - pos.y))
                                                                                           + (float)((float)(v7->pos.x - pos.x) * (float)(v7->pos.x - pos.x))) )
  {
    if ( !UFG::UIMapBlip::GetObjective(v12) )
    {
      v11 = 0;
      goto LABEL_15;
    }
    v7 = v13;
  }
  if ( !v11 )
LABEL_15:
    v7 = v13;
  if ( !v7 )
    goto LABEL_43;
  v14 = UFG::UIMapBlip::GetColor(v7);
  v6->mSelectedBlipColor.r = v14->r;
  v6->mSelectedBlipColor.g = v14->g;
  v6->mSelectedBlipColor.b = v14->b;
  v6->mSelectedBlipColor.a = v14->a;
  v15 = 20.0 / v4->scale;
  v16 = SSInvokedMethod::get_invokable(v7);
  v17 = v7->pos.y;
  v18 = v7->pos.z;
  v19 = v16;
  point.x = v7->pos.x;
  point.y = v17;
  point.z = v18;
  UFG::WorldPoint2f::WorldPoint2f(&v31, &point);
  UFG::ScreenPoint2f::ScreenPoint2f(&v27, &v31, v4);
  if ( (float)((float)((float)(pos.y - point.y) * (float)(pos.y - point.y))
             + (float)((float)(pos.x - point.x) * (float)(pos.x - point.x))) >= (float)(v15 * v15) )
    goto LABEL_43;
  if ( v27.x >= v6->mMinLimit.x
    && v27.x <= v6->mMaxLimit.x
    && (v20 = v27.y, v27.y >= v6->mMinLimit.y)
    && v27.y <= v6->mMaxLimit.y )
  {
    v6->mPos.x = v27.x;
    v6->mPos.y = v20;
    UFG::UIHKCursorWidget::BoundPos((UFG::UIHKCursorWidget *)&v6->mPos);
    if ( v11 )
    {
      if ( !v19 || !*v19 )
      {
        v21 = v9->mObjective;
        if ( v21 )
          v19 = v21->mCaption.mData;
        else
          v19 = v9->alternateCaption.mData;
      }
      titleCaption = v9->titleCaption.mData;
      UFG::UIHKWorldMapCursorWidget::Open(v6, v9->gameSliceType, v9->gameSliceName.mData, v19);
    }
    else
    {
      v23 = 0;
      v24 = UFG::UIMapBlip::GetType((CAkSrcPhysModel *)v7);
      if ( v24 )
      {
        if ( !v19 || !*v19 )
          v19 = (const char *)v24[4].vfptr;
        if ( LODWORD(v24->vfptr) == UFG::symRaceStartFlag.mUID || LODWORD(v24->vfptr) == UFG::symRaceEndFlag.mUID )
          v23 = 1;
      }
      UFG::UIHKWorldMapCursorWidget::Open(v6, TYPE_OCCLUSION, &customWorldMapCaption, v19);
      if ( v23 )
      {
        v25 = UFG::UIScreenManagerBase::getScreen(
                (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                "WorldMap");
        if ( v25 )
        {
          v26 = *(_DWORD *)&v25[1].m_screenName[40];
          *(_DWORD *)&v25[1].m_screenName[36] = 0;
          *(_DWORD *)&v25[1].m_screenName[44] = v26;
        }
      }
    }
  }
  else
  {
LABEL_43:
    UFG::UIHKWorldMapCursorWidget::Close(v6);
  }
}

// File Line: 203
// RVA: 0x6044C0
char __fastcall UFG::UIHKWorldMapCursorWidget::SelectObjective(UFG::UIHKWorldMapCursorWidget *this, UFG::UITiledMapMath *geo)
{
  int v2; // ebx
  UFG::UITiledMapMath *v3; // r14
  UFG::UIHKWorldMapCursorWidget *v4; // rbp
  UFG::UIHKPlayerObjectiveManager *v5; // rsi
  float v7; // xmm7_4
  float v8; // xmm6_4
  UFG::UIHKPlayerObjective *v9; // rax
  UFG::UIHKPlayerObjective *v10; // rdi
  float v11; // xmm2_4
  float v12; // xmm1_4
  UFG::HudComponent *v13; // rcx
  char v14; // al
  unsigned int v15; // ecx
  UFG::qVector3 v16; // [rsp+20h] [rbp-58h]
  UFG::qVector3 pos; // [rsp+30h] [rbp-48h]
  UFG::WorldPoint2f v18; // [rsp+80h] [rbp+8h]

  v2 = 0;
  v3 = geo;
  v4 = this;
  this->mSelectedObjective = 0i64;
  v5 = UFG::UIHKPlayerObjectiveManager::mInstance;
  if ( !UFG::UIHKPlayerObjectiveManager::mInstance )
    return 0;
  UFG::WorldPoint2f::WorldPoint2f(&v18, &this->mPos, geo);
  v7 = v18.x;
  v8 = v18.y;
  pos.z = 0.0;
  *(UFG::WorldPoint2f *)&pos.x = v18;
  v9 = UFG::UIHKPlayerObjectiveManager::FindNearestObjective(v5, &pos);
  v10 = v9;
  if ( !v9 )
    return 0;
  v18 = 0i64;
  if ( v9->useFixedPos )
  {
    v11 = v9->fixedPos.y;
    v12 = v9->fixedPos.x;
    v16.x = v9->fixedPos.x;
    v16.y = v11;
  }
  else
  {
    v13 = (UFG::HudComponent *)v9->gpsTarget.m_pPointer;
    if ( v13 )
      v14 = UFG::HudComponent::GetWorldPosition(v13, &v16);
    else
      v14 = UFG::UIHKPlayerObjectiveManager::GetObjectivePos(v5, v9, &v16, (UFG::HudComponent **)&v18);
    if ( !v14 )
      return 0;
    v11 = v16.y;
    v12 = v16.x;
  }
  v16.z = 0.0;
  if ( (float)((float)((float)(v8 - v11) * (float)(v8 - v11)) + (float)((float)(v7 - v12) * (float)(v7 - v12))) >= (float)((float)(20.0 / v3->scale) * (float)(20.0 / v3->scale)) )
    return 0;
  v15 = v5->m_objectives.size;
  if ( v15 )
  {
    while ( v5->m_objectives.p[v2] != v10 )
    {
      if ( ++v2 >= v15 )
      {
        v4->mSelectedObjective = v10;
        return 1;
      }
    }
    v5->m_currentObjective = v2;
  }
  v4->mSelectedObjective = v10;
  return 1;
}

// File Line: 233
// RVA: 0x5F36D0
void __fastcall UFG::UIHKWorldMapCursorWidget::Open(UFG::UIHKWorldMapCursorWidget *this, UFG::GameSlice::Type gameSliceType, const char *gameSliceName, const char *infoCaption)
{
  const char *v4; // r15
  const char *v5; // r14
  UFG::GameSlice::Type v6; // er12
  UFG::UIHKWorldMapCursorWidget *v7; // rbp
  UFG::UIScreen *v8; // rax
  UFG::UIScreen *v9; // rbx
  float v10; // xmm0_4
  float v11; // xmm1_4
  bool v12; // di
  UFG::allocator::free_link *v13; // rax
  UFG::UIScreenInvoke *v14; // rsi
  UFG::allocator::free_link *v15; // rax

  v4 = infoCaption;
  v5 = gameSliceName;
  v6 = gameSliceType;
  v7 = this;
  v8 = UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "WorldMap");
  v9 = v8;
  if ( v7->mIsOpen )
  {
    if ( v8 )
    {
      v10 = v7->mPos.y;
      v11 = v7->mPos.x;
      v12 = v7->mPos.x != *(float *)&v8[1].m_screenNameHash || v10 != *((float *)&v8[1].m_screenNameHash + 1);
      v8[1].m_screenName[60] |= v12;
      *(float *)&v8[1].m_screenNameHash = v11;
      *((float *)&v8[1].m_screenNameHash + 1) = v10;
    }
  }
  else
  {
    v7->mIsOpen = 1;
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0x6D325410u,
        0i64,
        0,
        0i64);
    v13 = UFG::qMemoryPool::Allocate(
            &gScaleformMemoryPool,
            0x40ui64,
            "UIHKWorldMapCursorWidget UIScreenInvoke",
            0i64,
            1u);
    v14 = (UFG::UIScreenInvoke *)v13;
    if ( v13 )
    {
      v15 = v13 + 1;
      v15->mNext = v15;
      v15[1].mNext = v15;
      v14->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable;
      UFG::qString::qString(&v14->command, &customWorldMapCaption);
    }
    else
    {
      v14 = 0i64;
    }
    if ( v14 )
    {
      UFG::qString::Set(&v14->command, "Cursor_Open");
      if ( v14->command.mLength )
        UFG::UIScreenInvokeQueue::Add(&UFG::UIHKScreenWorldMap::mScreenInvokeQueue, v14);
      if ( v9 )
      {
        UFG::UIHKScreenWorldMap::ShowInfoPopup(
          (UFG::UIHKScreenWorldMap *)v9,
          v7->mPos.x,
          v7->mPos.y,
          &customWorldMapCaption,
          v4);
        *(_DWORD *)&v9[1].m_screenName[44] = 0;
        if ( v6 == 8 )
        {
          *(_DWORD *)&v9[1].m_screenName[36] = 0;
          UFG::UITiledMapRaceSplines::SetLayerName((UFG::UITiledMapRaceSplines *)&v9[22].m_screenName[16], v5);
        }
        else
        {
          *(_DWORD *)&v9[1].m_screenName[36] = 2;
        }
      }
    }
  }
}

// File Line: 271
// RVA: 0x5D5B20
void __fastcall UFG::UIHKWorldMapCursorWidget::Close(UFG::UIHKWorldMapCursorWidget *this)
{
  UFG::allocator::free_link *v1; // rax
  UFG::UIScreenInvoke *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  UFG::UIScreen *v4; // rax
  int v5; // edx
  int v6; // edx
  int v7; // edx

  if ( this->mIsOpen )
  {
    this->mIsOpen = 0;
    v1 = UFG::qMemoryPool::Allocate(
           &gScaleformMemoryPool,
           0x40ui64,
           "UIHKWorldMapCursorWidget UIScreenInvoke",
           0i64,
           1u);
    v2 = (UFG::UIScreenInvoke *)v1;
    if ( v1 )
    {
      v3 = v1 + 1;
      v3->mNext = v3;
      v3[1].mNext = v3;
      v2->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable;
      UFG::qString::qString(&v2->command, &customWorldMapCaption);
    }
    else
    {
      v2 = 0i64;
    }
    if ( v2 )
    {
      UFG::qString::Set(&v2->command, "Cursor_Close");
      if ( v2->command.mLength )
        UFG::UIScreenInvokeQueue::Add(&UFG::UIHKScreenWorldMap::mScreenInvokeQueue, v2);
      v4 = UFG::UIScreenManagerBase::getScreen(
             (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
             "WorldMap");
      if ( v4 )
      {
        v5 = *(_DWORD *)&v4[1].m_screenName[56];
        if ( v5 )
        {
          v6 = v5 - 1;
          if ( !v6 || (v7 = v6 - 1) != 0 && v7 == 1 )
          {
            *(_DWORD *)&v4[1].m_screenName[56] = 2;
            v4[1].m_screenName[62] = 1;
          }
        }
        *(_DWORD *)&v4[1].m_screenName[44] = 0;
        *(_DWORD *)&v4[1].m_screenName[36] = 2;
      }
    }
  }
}

