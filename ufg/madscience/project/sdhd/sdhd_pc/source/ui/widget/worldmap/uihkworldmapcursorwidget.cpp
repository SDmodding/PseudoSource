// File Line: 36
// RVA: 0x618E90
void __fastcall UFG::UIHKWorldMapCursorWidget::Update(
        UFG::UIHKWorldMapCursorWidget *this,
        UFG::UIScreen *screen,
        UFG::BasePhysicsSystem *iconManager,
        UFG::UITiledMapMath *geo)
{
  if ( screen && screen->mRenderable->m_movie.pObject )
  {
    UFG::UIHKCursorWidget::Update(this, screen);
    if ( this->mIsMoving )
      UFG::UIHKWorldMapCursorWidget::Close(this);
    else
      UFG::UIHKWorldMapCursorWidget::SnapToObjective(this, iconManager, geo);
  }
}

// File Line: 70
// RVA: 0x1570CA0
__int64 UFG::_dynamic_initializer_for__symRaceStartFlag__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("race_start_flag", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symRaceStartFlag, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symRaceStartFlag__);
}

// File Line: 71
// RVA: 0x1570C60
__int64 UFG::_dynamic_initializer_for__symRaceEndFlag__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("race_end_flag", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symRaceEndFlag, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symRaceEndFlag__);
}

// File Line: 75
// RVA: 0x6117A0
void __fastcall UFG::UIHKWorldMapCursorWidget::SnapToObjective(
        UFG::UIHKWorldMapCursorWidget *this,
        UFG::BasePhysicsSystem *iconManager,
        UFG::UITiledMapMath *geo)
{
  UFG::UIHKPlayerObjectiveManager *v3; // r14
  UFG::UIMapBlip *v7; // rdi
  UFG::UIHKPlayerObjective *NearestObjective; // rax
  UFG::UIHKPlayerObjective *v9; // r14
  UFG::qBaseTreeRB *CollisionModel; // rax
  bool v11; // r15
  UFG::UIMapBlip *NearestVisibleIcon; // rax
  UFG::UIMapBlip *v13; // rsi
  float v14; // xmm6_4
  const char *invokable; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  const char *mData; // rsi
  float v19; // xmm1_4
  UFG::Objective *mObjective; // rsi
  char v21; // r14
  AK::IAkPluginParam *Type; // rax
  UFG::UIScreen *Screen; // rax
  int v24; // ecx
  UFG::ScreenPoint2f v25; // [rsp+30h] [rbp-50h] BYREF
  UFG::qVector3 pos; // [rsp+38h] [rbp-48h] BYREF
  UFG::qVector3 point; // [rsp+48h] [rbp-38h] BYREF
  UFG::qVector3 playerPos; // [rsp+58h] [rbp-28h] BYREF
  UFG::WorldPoint2f v29; // [rsp+C8h] [rbp+48h] BYREF

  v3 = UFG::UIHKPlayerObjectiveManager::mInstance;
  if ( !UFG::UIHKPlayerObjectiveManager::mInstance )
    return;
  this->mSelectedBlipColor = UFG::qColour::White;
  UFG::WorldPoint2f::WorldPoint2f(&v29, &this->mPos, geo);
  pos.z = 0.0;
  *(_QWORD *)&playerPos.x = 0i64;
  playerPos.z = 0.0;
  pos.x = v29.x;
  pos.y = v29.y;
  v7 = 0i64;
  NearestObjective = UFG::UIHKPlayerObjectiveManager::FindNearestObjective(v3, &pos);
  v9 = NearestObjective;
  if ( NearestObjective )
  {
    if ( !iconManager
      || !NearestObjective->minimapBlips.size
      || (CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(iconManager, *NearestObjective->minimapBlips.p),
          (v7 = (UFG::UIMapBlip *)CollisionModel) == 0i64)
      || !UFG::UIMapBlip::IsVisible((UFG::UIMapBlip *)CollisionModel)
      || UFG::UIMapBlip::GetAlpha(v7, &playerPos, geo) <= 0.0 )
    {
      v7 = 0i64;
    }
  }
  v11 = v7 != 0i64;
  NearestVisibleIcon = UFG::UIMapBlipManager::FindNearestVisibleIcon((UFG::UIMapBlipManager *)iconManager, &pos, geo);
  v13 = NearestVisibleIcon;
  if ( v7
    && NearestVisibleIcon
    && (float)((float)((float)(NearestVisibleIcon->pos.y - pos.y) * (float)(NearestVisibleIcon->pos.y - pos.y))
             + (float)((float)(NearestVisibleIcon->pos.x - pos.x) * (float)(NearestVisibleIcon->pos.x - pos.x))) < (float)((float)((float)(v7->pos.y - pos.y) * (float)(v7->pos.y - pos.y)) + (float)((float)(v7->pos.x - pos.x) * (float)(v7->pos.x - pos.x))) )
  {
    if ( !UFG::UIMapBlip::GetObjective(NearestVisibleIcon) )
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
    goto LABEL_40;
  this->mSelectedBlipColor = *UFG::UIMapBlip::GetColor(v7);
  v14 = 20.0 / geo->scale;
  invokable = SSInvokedMethod::get_invokable(v7);
  y = v7->pos.y;
  z = v7->pos.z;
  mData = invokable;
  point.x = v7->pos.x;
  point.y = y;
  point.z = z;
  UFG::WorldPoint2f::WorldPoint2f(&v29, &point);
  UFG::ScreenPoint2f::ScreenPoint2f(&v25, &v29, geo);
  if ( (float)((float)((float)(pos.y - point.y) * (float)(pos.y - point.y))
             + (float)((float)(pos.x - point.x) * (float)(pos.x - point.x))) >= (float)(v14 * v14) )
    goto LABEL_40;
  if ( v25.x >= this->mMinLimit.x
    && v25.x <= this->mMaxLimit.x
    && (v19 = v25.y, v25.y >= this->mMinLimit.y)
    && v25.y <= this->mMaxLimit.y )
  {
    this->mPos.x = v25.x;
    this->mPos.y = v19;
    UFG::UIHKCursorWidget::BoundPos(this);
    if ( v11 )
    {
      if ( !mData || !*mData )
      {
        mObjective = v9->mObjective;
        if ( mObjective )
          mData = mObjective->mCaption.mData;
        else
          mData = v9->alternateCaption.mData;
      }
      UFG::UIHKWorldMapCursorWidget::Open(this, v9->gameSliceType, v9->gameSliceName.mData, mData);
    }
    else
    {
      v21 = 0;
      Type = UFG::UIMapBlip::GetType((CAkSrcPhysModel *)v7);
      if ( Type )
      {
        if ( !mData || !*mData )
          mData = (const char *)Type[4].vfptr;
        if ( LODWORD(Type->vfptr) == UFG::symRaceStartFlag.mUID || LODWORD(Type->vfptr) == UFG::symRaceEndFlag.mUID )
          v21 = 1;
      }
      UFG::UIHKWorldMapCursorWidget::Open(this, TYPE_OCCLUSION, &customCaption, mData);
      if ( v21 )
      {
        Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "WorldMap");
        if ( Screen )
        {
          v24 = *(_DWORD *)&Screen[1].m_screenName[40];
          *(_DWORD *)&Screen[1].m_screenName[36] = 0;
          *(_DWORD *)&Screen[1].m_screenName[44] = v24;
        }
      }
    }
  }
  else
  {
LABEL_40:
    UFG::UIHKWorldMapCursorWidget::Close(this);
  }
}

// File Line: 203
// RVA: 0x6044C0
char __fastcall UFG::UIHKWorldMapCursorWidget::SelectObjective(
        UFG::UIHKWorldMapCursorWidget *this,
        UFG::UITiledMapMath *geo)
{
  int v2; // ebx
  UFG::UIHKPlayerObjectiveManager *v5; // rsi
  float x; // xmm7_4
  float y; // xmm6_4
  UFG::UIHKPlayerObjective *NearestObjective; // rax
  UFG::UIHKPlayerObjective *v10; // rdi
  float v11; // xmm2_4
  float v12; // xmm1_4
  UFG::HudComponent *m_pPointer; // rcx
  char WorldPosition; // al
  unsigned int size; // ecx
  UFG::qVector3 v16; // [rsp+20h] [rbp-58h] BYREF
  UFG::qVector3 pos; // [rsp+30h] [rbp-48h] BYREF
  UFG::WorldPoint2f v18; // [rsp+80h] [rbp+8h] BYREF

  v2 = 0;
  this->mSelectedObjective = 0i64;
  v5 = UFG::UIHKPlayerObjectiveManager::mInstance;
  if ( !UFG::UIHKPlayerObjectiveManager::mInstance )
    return 0;
  UFG::WorldPoint2f::WorldPoint2f(&v18, &this->mPos, geo);
  x = v18.x;
  y = v18.y;
  pos.z = 0.0;
  pos.x = v18.x;
  pos.y = v18.y;
  NearestObjective = UFG::UIHKPlayerObjectiveManager::FindNearestObjective(v5, &pos);
  v10 = NearestObjective;
  if ( !NearestObjective )
    return 0;
  v18 = 0i64;
  if ( NearestObjective->useFixedPos )
  {
    v11 = NearestObjective->fixedPos.y;
    v12 = NearestObjective->fixedPos.x;
    v16.x = v12;
    v16.y = v11;
  }
  else
  {
    m_pPointer = (UFG::HudComponent *)NearestObjective->gpsTarget.m_pPointer;
    if ( m_pPointer )
      WorldPosition = UFG::HudComponent::GetWorldPosition(m_pPointer, &v16);
    else
      WorldPosition = UFG::UIHKPlayerObjectiveManager::GetObjectivePos(
                        v5,
                        NearestObjective,
                        &v16,
                        (UFG::HudComponent **)&v18);
    if ( !WorldPosition )
      return 0;
    v11 = v16.y;
    v12 = v16.x;
  }
  v16.z = 0.0;
  if ( (float)((float)((float)(y - v11) * (float)(y - v11)) + (float)((float)(x - v12) * (float)(x - v12))) >= (float)((float)(20.0 / geo->scale) * (float)(20.0 / geo->scale)) )
    return 0;
  size = v5->m_objectives.size;
  if ( size )
  {
    while ( v5->m_objectives.p[v2] != v10 )
    {
      if ( ++v2 >= size )
      {
        this->mSelectedObjective = v10;
        return 1;
      }
    }
    v5->m_currentObjective = v2;
  }
  this->mSelectedObjective = v10;
  return 1;
}

// File Line: 233
// RVA: 0x5F36D0
void __fastcall UFG::UIHKWorldMapCursorWidget::Open(
        UFG::UIHKWorldMapCursorWidget *this,
        UFG::GameSlice::Type gameSliceType,
        const char *gameSliceName,
        const char *infoCaption)
{
  UFG::UIScreen *Screen; // rax
  UFG::UIScreen *v9; // rbx
  float y; // xmm0_4
  float x; // xmm1_4
  bool v12; // di
  UFG::allocator::free_link *v13; // rax
  UFG::UIScreenInvoke *v14; // rsi
  UFG::allocator::free_link *v15; // rax

  Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "WorldMap");
  v9 = Screen;
  if ( this->mIsOpen )
  {
    if ( Screen )
    {
      y = this->mPos.y;
      x = this->mPos.x;
      v12 = this->mPos.x != *(float *)&Screen[1].m_screenNameHash || y != *((float *)&Screen[1].m_screenNameHash + 1);
      Screen[1].m_screenName[60] |= v12;
      *(float *)&Screen[1].m_screenNameHash = x;
      *((float *)&Screen[1].m_screenNameHash + 1) = y;
    }
  }
  else
  {
    this->mIsOpen = 1;
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x6D325410u, 0i64, 0, 0i64);
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
      UFG::qString::qString(&v14->command, &customCaption);
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
          this->mPos.x,
          this->mPos.y,
          &customCaption,
          infoCaption);
        *(_DWORD *)&v9[1].m_screenName[44] = 0;
        if ( gameSliceType == 8 )
        {
          *(_DWORD *)&v9[1].m_screenName[36] = 0;
          UFG::UITiledMapRaceSplines::SetLayerName(
            (UFG::UITiledMapRaceSplines *)&v9[22].m_screenName[16],
            gameSliceName);
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
  UFG::UIScreen *Screen; // rax
  int v5; // edx
  int v6; // edx

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
      UFG::qString::qString(&v2->command, &customCaption);
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
      Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "WorldMap");
      if ( Screen )
      {
        v5 = *(_DWORD *)&Screen[1].m_screenName[56];
        if ( v5 )
        {
          v6 = v5 - 1;
          if ( !v6 || v6 == 2 )
          {
            *(_DWORD *)&Screen[1].m_screenName[56] = 2;
            Screen[1].m_screenName[62] = 1;
          }
        }
        *(_DWORD *)&Screen[1].m_screenName[44] = 0;
        *(_DWORD *)&Screen[1].m_screenName[36] = 2;
      }
    }
  }
}

