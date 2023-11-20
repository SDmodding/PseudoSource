// File Line: 45
// RVA: 0x2FA000
void __fastcall UIEventTask::Begin(UIEventTask *this, ActionContext *context)
{
  ITrack *v2; // rax
  Expression::IMemberMapVtbl *v3; // rcx
  signed __int64 v4; // rax
  unsigned __int64 v5; // rcx
  const char *v6; // rcx
  UFG::UIScreenManager *v7; // rbx
  unsigned int v8; // eax

  v2 = this->m_Track;
  v3 = v2[1].vfptr;
  v4 = (signed __int64)&v2[1];
  v5 = (unsigned __int64)v3 & 0xFFFFFFFFFFFFFFFEui64;
  if ( v5 )
    v6 = (const char *)(v4 + v5);
  else
    v6 = BinString::sEmptyString;
  v7 = UFG::UIScreenManager::s_instance;
  v8 = UFG::qStringHashUpper32(v6, 0xFFFFFFFF);
  UFG::UIScreenManagerBase::queueMessage((UFG::UIScreenManagerBase *)&v7->vfptr, v8, 0xFFFFFFFF);
}

// File Line: 57
// RVA: 0x2FA050
void __fastcall UIScreenTask::Begin(UIScreenTask *this, ActionContext *pContext)
{
  __int64 v2; // rdi
  const char *v3; // rsi
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::CharacterOccupantComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rax
  UFG::SimObject *v8; // rbx
  unsigned __int16 v9; // dx
  UFG::AiDriverComponent *v10; // rax
  UFG::UIScreenTextureManager *v11; // rax
  UFG::allocator::free_link *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rbx
  UFG::allocator::free_link *v15; // rax
  UFG::qString *v16; // rdi
  UFG::allocator::free_link *v17; // rax
  signed __int64 v18; // rdi
  __int64 v19; // rsi
  __int64 v20; // rsi
  __int64 v21; // rdi
  __int64 v22; // rsi
  __int64 v23; // rdi

  v2 = SLODWORD(this->m_Track[1].vfptr);
  v3 = gUIScreenListNames[v2];
  if ( (_DWORD)v2 == 8 )
  {
    v4 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( v4 )
    {
      v5 = v4->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = (UFG::CharacterOccupantComponent *)v4->m_Components.p[44].m_pComponent;
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
          v6 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v4,
                                                    UFG::CharacterOccupantComponent::_TypeUID);
        else
          v6 = (UFG::CharacterOccupantComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v4,
                                                                      UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
      }
      else
      {
        v6 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v4,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
      }
      if ( v6 )
      {
        v7 = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v6);
        v8 = (UFG::SimObject *)&v7->vfptr;
        if ( v7 )
        {
          v9 = v7->m_Flags;
          if ( (v9 >> 14) & 1 )
          {
            v10 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7);
          }
          else if ( (v9 & 0x8000u) == 0 )
          {
            if ( (v9 >> 13) & 1 )
            {
              v10 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v7->vfptr,
                                                UFG::AiDriverComponent::_TypeUID);
            }
            else if ( (v9 >> 12) & 1 )
            {
              v10 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v7->vfptr,
                                                UFG::AiDriverComponent::_TypeUID);
            }
            else
            {
              v10 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v7->vfptr,
                                                UFG::AiDriverComponent::_TypeUID);
            }
          }
          else
          {
            v10 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7);
          }
          if ( !v10 || !UFG::UIHKScreenWorldMap::SetWorldMapFromVehicle(v8) )
            return;
          UFG::UI::PauseGame(0i64);
        }
      }
    }
  }
  v11 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v11, v3, 0i64);
  if ( (_DWORD)v2 == 7 )
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
        `eh vector constructor iterator'(&v15[1], 0x28ui64, 3, (void (__fastcall *)(void *))UFG::qString::qString);
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
        v18 = (signed __int64)&v17[1];
        `eh vector constructor iterator'(
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
      v19 = *(_QWORD *)(*(_QWORD *)(v14 + 80) + 24i64);
      if ( (*(_DWORD *)(v18 + 24) >> 6) & 1 )
      {
        (*(void (__fastcall **)(_QWORD, signed __int64, _QWORD))(**(_QWORD **)(v18 + 16) + 16i64))(
          *(_QWORD *)(v18 + 16),
          v18,
          *(_QWORD *)(v18 + 32));
        *(_QWORD *)(v18 + 16) = 0i64;
      }
      *(_DWORD *)(v18 + 24) = 6;
      *(_QWORD *)(v18 + 32) = v19;
      v20 = *(_QWORD *)(*(_QWORD *)(v14 + 80) + 64i64);
      v21 = *(_QWORD *)(v14 + 64);
      if ( (*(_DWORD *)(v21 + 72) >> 6) & 1 )
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
      if ( (*(_DWORD *)(v23 + 120) >> 6) & 1 )
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
  UFG::UIScreen *v2; // rax
  _BOOL8 result; // rax

  v2 = UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         gUIScreenListNames[SLODWORD(this->m_Track[1].vfptr)]);
  if ( v2 )
    result = LOBYTE(v2[1].vfptr) == 0;
  else
    result = 1i64;
  return result;
}

// File Line: 124
// RVA: 0x3014A0
void __fastcall UIScreenTask::End(UIScreenTask *this)
{
  UIScreenTrack *v1; // rax

  v1 = (UIScreenTrack *)this->m_Track;
  if ( !v1->mDontRemoveOnEnd )
  {
    if ( v1->mIsOverlay )
      UFG::UIScreenManagerBase::queuePopOverlay(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        gUIScreenListNames[v1->mScreen]);
    else
      UFG::UIScreenManagerBase::queuePopScreen(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        0xFFFFFFFF);
    UFG::TSMinigame::gbMinigameRunning = 0;
  }
}

// File Line: 151
// RVA: 0x2EE930
void __fastcall HUDSocialActionChargeTask::Begin(HUDSocialActionChargeTask *this, ActionContext *context)
{
  ITrack *v2; // rax
  HUDSocialActionChargeTask *v3; // rbx
  float v4; // xmm0_4
  UFG::GameStatTracker *v5; // rax

  v2 = this->m_Track;
  v3 = this;
  if ( BYTE4(v2[1].vfptr) )
  {
    UFG::UIHKCombatMeterWidget::SetCombatCharge(UFG::UIHKScreenHud::CombatMeter, *(float *)&v2[1].vfptr);
  }
  else
  {
    v4 = UFG::UIHKCombatMeterWidget::GetCombatCharge(UFG::UIHKScreenHud::CombatMeter);
    UFG::UIHKCombatMeterWidget::SetCombatCharge(UFG::UIHKScreenHud::CombatMeter, v4 + *(float *)&v3->m_Track[1].vfptr);
    v5 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::GetStat(v5, Face);
  }
}

// File Line: 207
// RVA: 0x2EE910
void __fastcall HUDSocialActionActivateTask::Begin(HUDSocialActionActivateTask *this, ActionContext *context)
{
  JUMPOUT(UFG::UIHKScreenHud::CombatMeter->mCombatAction, 0, UFG::UIHKCombatMeterWidget::PingCombatAction);
}

// File Line: 218
// RVA: 0x2EE990
void __fastcall HUDSocialActionEnableTask::Begin(HUDSocialActionEnableTask *this, ActionContext *context)
{
  HUDSocialActionEnableTask *v2; // rbx

  v2 = this;
  if ( LOBYTE(this->m_Track[1].vfptr) )
    UFG::UIHKCombatMeterWidget::SetCombatCharge(UFG::UIHKScreenHud::CombatMeter, 0.0);
  if ( !LOBYTE(v2->m_Track[1].vfptr) )
    UFG::UIHKCombatMeterWidget::SetCombatCharge(UFG::UIHKScreenHud::CombatMeter, 0.0);
}

