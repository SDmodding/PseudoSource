// File Line: 45
// RVA: 0x2FA000
void __fastcall UIEventTask::Begin(UIEventTask *this, ActionContext *context)
{
  ITrack *m_Track; // rax
  Expression::IMemberMapVtbl *vfptr; // rcx
  ITrack *v4; // rax
  unsigned __int64 v5; // rcx
  const char *v6; // rcx
  UFG::UIScreenManager *v7; // rbx
  unsigned int v8; // eax

  m_Track = this->m_Track;
  vfptr = m_Track[1].vfptr;
  v4 = m_Track + 1;
  v5 = (unsigned __int64)vfptr & 0xFFFFFFFFFFFFFFFEui64;
  if ( v5 )
    v6 = (char *)v4 + v5;
  else
    v6 = BinString::sEmptyString;
  v7 = UFG::UIScreenManager::s_instance;
  v8 = UFG::qStringHashUpper32(v6, -1);
  UFG::UIScreenManagerBase::queueMessage(v7, v8, 0xFFFFFFFF);
}

// File Line: 57
// RVA: 0x2FA050
void __fastcall UIScreenTask::Begin(UIScreenTask *this, ActionContext *pContext)
{
  __int64 vfptr_low; // rdi
  const char *v3; // rsi
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::SimObjectCVBase *CurrentVehicle; // rax
  UFG::SimObject *v8; // rbx
  __int16 v9; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::UIScreenTextureManager *v11; // rax
  UFG::allocator::free_link *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rbx
  UFG::allocator::free_link *v15; // rax
  UFG::qString *v16; // rdi
  UFG::allocator::free_link *v17; // rax
  UFG::allocator::free_link *v18; // rdi
  UFG::allocator::free_link *v19; // rsi
  __int64 v20; // rsi
  __int64 v21; // rdi
  __int64 v22; // rsi
  __int64 v23; // rdi

  vfptr_low = SLODWORD(this->m_Track[1].vfptr);
  v3 = gUIScreenListNames[vfptr_low];
  if ( (_DWORD)vfptr_low == 8 )
  {
    m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
        m_pComponent = (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent;
      else
        m_pComponent = (UFG::CharacterOccupantComponent *)(m_Flags < 0
                                                        || (m_Flags & 0x2000) != 0
                                                        || (m_Flags & 0x1000) != 0
                                                         ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             m_pPointer,
                                                             UFG::CharacterOccupantComponent::_TypeUID)
                                                         : UFG::SimObject::GetComponentOfType(
                                                             m_pPointer,
                                                             UFG::CharacterOccupantComponent::_TypeUID));
      if ( m_pComponent )
      {
        CurrentVehicle = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
        v8 = CurrentVehicle;
        if ( CurrentVehicle )
        {
          v9 = CurrentVehicle->m_Flags;
          if ( (v9 & 0x4000) != 0 || v9 < 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(CurrentVehicle);
          }
          else if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
          {
            ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            CurrentVehicle,
                                                            UFG::AiDriverComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                            CurrentVehicle,
                                                            UFG::AiDriverComponent::_TypeUID);
          }
          if ( !ComponentOfTypeHK || !UFG::UIHKScreenWorldMap::SetWorldMapFromVehicle(v8) )
            return;
          UFG::UI::PauseGame(0i64);
        }
      }
    }
  }
  v11 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v11, v3, 0i64);
  if ( (_DWORD)vfptr_low == 7 )
  {
    v12 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x58ui64, "UIScreenInvoke", 0i64, 1u);
    if ( v12 )
    {
      UFG::UIScreenInvokeValueArgs::UIScreenInvokeValueArgs((UFG::UIScreenInvokeValueArgs *)v12);
      v14 = v13;
    }
    else
    {
      v14 = 0i64;
    }
    if ( v14 )
    {
      v15 = UFG::qMalloc(0x80ui64, "qString[]", 0i64);
      if ( v15 )
      {
        LODWORD(v15->mNext) = 3;
        v16 = (UFG::qString *)&v15[1];
        `eh vector constructor iterator(&v15[1], 0x28ui64, 3, (void (__fastcall *)(void *))UFG::qString::qString);
      }
      else
      {
        v16 = 0i64;
      }
      *(_QWORD *)(v14 + 80) = v16;
      UFG::qString::Set(v16, "Location 1");
      UFG::qString::Set((UFG::qString *)(*(_QWORD *)(v14 + 80) + 40i64), "Location 2");
      UFG::qString::Set((UFG::qString *)(*(_QWORD *)(v14 + 80) + 80i64), "Location 3");
      UFG::qString::Set((UFG::qString *)(v14 + 24), "ScriptableList_AddItem");
      *(_DWORD *)(v14 + 72) = 3;
      v17 = UFG::qMalloc(0x98ui64, "TSHUD GFxValue[]", 0i64);
      if ( v17 )
      {
        LODWORD(v17->mNext) = 3;
        v18 = v17 + 1;
        `eh vector constructor iterator(
          &v17[1],
          0x30ui64,
          3,
          (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      }
      else
      {
        v18 = 0i64;
      }
      *(_QWORD *)(v14 + 64) = v18;
      v19 = *(UFG::allocator::free_link **)(*(_QWORD *)(v14 + 80) + 24i64);
      if ( ((__int64)v18[3].mNext & 0x40) != 0 )
      {
        ((void (__fastcall *)(UFG::allocator::free_link *, UFG::allocator::free_link *, UFG::allocator::free_link *))v18[2].mNext->mNext[2].mNext)(
          v18[2].mNext,
          v18,
          v18[4].mNext);
        v18[2].mNext = 0i64;
      }
      LODWORD(v18[3].mNext) = 6;
      v18[4].mNext = v19;
      v20 = *(_QWORD *)(*(_QWORD *)(v14 + 80) + 64i64);
      v21 = *(_QWORD *)(v14 + 64);
      if ( (*(_DWORD *)(v21 + 72) & 0x40) != 0 )
      {
        (*(void (__fastcall **)(_QWORD, __int64, _QWORD))(**(_QWORD **)(v21 + 64) + 16i64))(
          *(_QWORD *)(v21 + 64),
          v21 + 48,
          *(_QWORD *)(v21 + 80));
        *(_QWORD *)(v21 + 64) = 0i64;
      }
      *(_DWORD *)(v21 + 72) = 6;
      *(_QWORD *)(v21 + 80) = v20;
      v22 = *(_QWORD *)(*(_QWORD *)(v14 + 80) + 104i64);
      v23 = *(_QWORD *)(v14 + 64);
      if ( (*(_DWORD *)(v23 + 120) & 0x40) != 0 )
      {
        (*(void (__fastcall **)(_QWORD, __int64, _QWORD))(**(_QWORD **)(v23 + 112) + 16i64))(
          *(_QWORD *)(v23 + 112),
          v23 + 96,
          *(_QWORD *)(v23 + 128));
        *(_QWORD *)(v23 + 112) = 0i64;
      }
      *(_DWORD *)(v23 + 120) = 6;
      *(_QWORD *)(v23 + 128) = v22;
      UFG::UIHKScreenScriptableList::QueueInvoke((UFG::UIScreenInvoke *)v14);
    }
  }
}

// File Line: 110
// RVA: 0x30B690
_BOOL8 __fastcall UIScreenTask::Update(UIScreenTask *this, float timeDelta)
{
  UFG::UIScreen *Screen; // rax

  Screen = UFG::UIScreenManagerBase::getScreen(
             UFG::UIScreenManager::s_instance,
             gUIScreenListNames[SLODWORD(this->m_Track[1].vfptr)]);
  return !Screen || LOBYTE(Screen[1].vfptr) == 0;
}

// File Line: 124
// RVA: 0x3014A0
void __fastcall UIScreenTask::End(UIScreenTask *this)
{
  UIScreenTrack *m_Track; // rax

  m_Track = (UIScreenTrack *)this->m_Track;
  if ( !m_Track->mDontRemoveOnEnd )
  {
    if ( m_Track->mIsOverlay )
      UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, gUIScreenListNames[m_Track->mScreen]);
    else
      UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
    UFG::TSMinigame::gbMinigameRunning = 0;
  }
}

// File Line: 151
// RVA: 0x2EE930
double __fastcall HUDSocialActionChargeTask::Begin(HUDSocialActionChargeTask *this, ActionContext *context)
{
  ITrack *m_Track; // rax
  float CombatCharge; // xmm0_4
  UFG::GameStatTracker *v5; // rax
  double result; // xmm0_8

  m_Track = this->m_Track;
  if ( BYTE4(m_Track[1].vfptr) )
  {
    UFG::UIHKCombatMeterWidget::SetCombatCharge(UFG::UIHKScreenHud::CombatMeter, *(float *)&m_Track[1].vfptr);
  }
  else
  {
    CombatCharge = UFG::UIHKCombatMeterWidget::GetCombatCharge(UFG::UIHKScreenHud::CombatMeter);
    UFG::UIHKCombatMeterWidget::SetCombatCharge(
      UFG::UIHKScreenHud::CombatMeter,
      CombatCharge + *(float *)&this->m_Track[1].vfptr);
    v5 = UFG::GameStatTracker::Instance();
    *(float *)&result = UFG::GameStatTracker::GetStat(v5, Face);
  }
  return result;
}

// File Line: 207
// RVA: 0x2EE910
void __fastcall HUDSocialActionActivateTask::Begin(HUDSocialActionActivateTask *this, ActionContext *context)
{
  if ( UFG::UIHKScreenHud::CombatMeter->mCombatAction )
    UFG::UIHKCombatMeterWidget::PingCombatAction(UFG::UIHKScreenHud::CombatMeter);
}

// File Line: 218
// RVA: 0x2EE990
void __fastcall HUDSocialActionEnableTask::Begin(HUDSocialActionEnableTask *this, ActionContext *context)
{
  if ( LOBYTE(this->m_Track[1].vfptr) )
    UFG::UIHKCombatMeterWidget::SetCombatCharge(UFG::UIHKScreenHud::CombatMeter, 0.0);
  if ( !LOBYTE(this->m_Track[1].vfptr) )
    UFG::UIHKCombatMeterWidget::SetCombatCharge(UFG::UIHKScreenHud::CombatMeter, 0.0);
}

